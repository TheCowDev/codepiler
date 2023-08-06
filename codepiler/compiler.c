#include "compiler.h"
#include <stdio.h>
#include "misc/memory.h"
#include "lang/pass.h"
#include "lang/type_set.h"
#include "lang/type_check.h"
#include "codegen/codegen.h"

static const char *read_all_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = (char *) code_alloc(file_size + 1);
    if (buffer == NULL) {
        printf("Failed to allocate memory for file content.\n");
        fclose(file);
        return NULL;
    }
    fread(buffer, sizeof(char), file_size, file);
    buffer[file_size] = '\0';

    fclose(file);
    return buffer;
}


void compiler_run_module_pass(Compiler *compiler, ModulePass pass) {
    pass(compiler, &compiler->module);
}

void compiler_run_function_pass(Compiler *compiler, FunctionPass pass) {
    Module *module = &compiler->module;
    for (int i = 0; i < 1; ++i) {
        pass(compiler, module, module->functions);
    }
}

void compiler_run_ir_pass(Compiler *compiler, IrPass pass) {
    Module *module = &compiler->module;
    for (int i = 0; i < 1; ++i) {
        Func *func = module->functions;
        for (int j = 0; j < func->instructions.size; ++j) {
            _IR *ir = func_get_instruction(func, j);
            pass(compiler, module, func, ir);
        }
    }
}

bool compiler_add_file(Compiler *compiler, const char *filename) {
    const char *code = read_all_file(filename);
    if (code != NULL) {
        compiler->module.raw_code = code;
        return true;
    } else {
        printf("Can't read the file");
    }

    return false;
}

void compiler_compile(Compiler *compiler) {
    module_parse(&compiler->module);
    module_print(compiler->module);

    //parse set
    compiler_run_ir_pass(compiler, type_set_pass);

    //parse check
    compiler_run_ir_pass(compiler, type_check_pass);


    //codegen
    compiler_run_ir_pass(compiler, codegen_get_pass());
    compiler_run_function_pass(compiler, codegen_get_jit_gen_pass());
}