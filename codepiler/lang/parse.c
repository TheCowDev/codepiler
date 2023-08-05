#include "parse.h"
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "../misc/memory.h"

typedef struct {
    bool present;
    long long value;
} OptInt;

typedef struct {
    bool present;
    double value;
} OptFloat;

static void lex_skip_whitespaces(Parser *parser) {
    while (*parser->code == ' ') {
        ++parser->code;
    }
}

static bool lex_specific(Parser *parser, const char *specific) {
    lex_skip_whitespaces(parser);

    const char *initial = parser->code;
    const size_t specific_size = strlen(specific);
    for (int i = 0; i < specific_size; ++i) {
        if (*parser->code != specific[i]) {
            parser->code = initial;
            return false;
        } else {
            ++parser->code;
        }
    }

    return true;
}

static const char *lex_id(Parser *parser) {
    lex_skip_whitespaces(parser);

    const char *begin = parser->code;
    while (isalpha(*parser->code) ||
           *parser->code == '_' ||
           (parser->code != begin && isdigit(*parser->code))) {
        ++parser->code;
    }

    if (parser->code != begin) {
        int id_size = parser->code - begin;
        char *lexed_id = code_alloc(id_size + 1);
        memcpy(lexed_id, begin, id_size);
        lexed_id[id_size] = 0;
        return lexed_id;
    }

    return NULL;
}

static OptInt lex_int(Parser *parser) {
    OptInt opt;
    lex_skip_whitespaces(parser);

    const char *begin = parser->code;
    while (isdigit(*parser->code)) {
        ++parser->code;
    }

    if (parser->code != begin) {
        int id_size = parser->code - begin;
        char lexed_int[id_size + 1];
        memcpy(lexed_int, begin, id_size);
        lexed_int[id_size] = 0;
        opt.present = true;
        opt.value = atoll((const char *) &lexed_int);
        return opt;
    }

    opt.present = false;
    parser->code = begin;
    return opt;
}

static OptFloat lex_float(Parser *parser) {
    OptFloat opt;
    lex_skip_whitespaces(parser);

    const char *begin = parser->code;
    bool found_dot = false;
    while (isdigit(*parser->code) || (!found_dot && *parser->code == '.')) {
        if (*parser->code == '.') {
            found_dot = true;
        }

        ++parser->code;
    }

    if (parser->code != begin && found_dot) {
        int id_size = parser->code - begin;
        char lexed_float[id_size + 1];
        memcpy(lexed_float, begin, id_size);
        lexed_float[id_size] = 0;
        opt.present = true;
        opt.value = atof((const char *) &lexed_float);
        return opt;
    }

    parser->code = begin;
    opt.present = false;
    return opt;
}

static char *lex_str(Parser *parser) {
    return NULL;
}

static bool peek_to_next_level_of_tab(Parser *parser, int *tab_level) {
    if (*parser->code == '\n') {
        int index = 1; // 1 to skip the jump line
        while (true) {
            if (*(parser->code + index) == '\t') {
                ++(*tab_level);
                ++index;
            } else if (strncmp(parser->code + index, "    ", 4) == 0) {
                ++(*tab_level);
                index += 4;
            } else {
                break;
            }
        }
        return true;
    }
    return false;
}

static void go_to_next_level_of_tab(Parser *parser) {
    if (*parser->code == '\n') {
        int index = 1; // 1 to skip the jump line
        while (true) {
            if (*(parser->code + index) == '\t') {
                ++index;
            } else if (strncmp(parser->code + index, "    ", 4) == 0) {
                index += 4;
            } else {
                break;
            }
        }
        parser->code += index;
    }
}

static IR parse_expression(Parser *parser, Func *func, OptError *error) {
    _IR expression = {0};
    OptFloat opt_float = lex_float(parser);
    if (opt_float.present) {

    } else {
        OptInt opt_int = lex_int(parser);
        if (opt_int.present) {
            expression.instr = INSTR_CONST_I64;
            expression.return_type = type_int64();
            expression.int_const = opt_int.value;
        } else {
            printf("Expression not recognized");
        }
    }

    func_add_instruction(func, expression);
}

static void parse_function_body(Parser *parser, Func *func, OptError *error) {
    if (lex_specific(parser, "return")) {
        _IR return_ir;
        return_ir.instr = INSTR_RETURN;
        return_ir.return_instr.expression = parse_expression(parser, func, error);
        func_add_instruction(func, return_ir);
    }
}

static Func *parse_func(Parser *parser, OptError *error) {
    if (lex_specific(parser, "fn")) {
        const char *func_name = lex_id(parser);
        if (func_name != NULL) {
            if (lex_specific(parser, "(") && lex_specific(parser, ")") && lex_specific(parser, ":")) {
                int func_body_level = 0;
                peek_to_next_level_of_tab(parser, &func_body_level);
                if (func_body_level > 0) {
                    go_to_next_level_of_tab(parser);
                    Func *func = code_calloc(sizeof(Func));
                    func->name = func_name;
                    parse_function_body(parser, func, error);
                    return func;
                } else {
                    *error = error_opt_from_char("Function content expected after ':'", parser->info);
                }
            }
        } else {
            *error = error_opt_from_char("Function name expected after 'fn'", parser->info);
        }
    }

    return NULL;
}

Module parse_module(Parser *parser, OptError *error) {
    Module module;
    Func *func = parse_func(parser, error);
    module.functions = func;
    return module;
}