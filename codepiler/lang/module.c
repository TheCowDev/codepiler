#include "module.h"
#include <stdio.h>
#include "parse.h"

void module_parse(Module *module) {

    Parser parser = {0};
    parser.code = module->raw_code;
    OptError error = {0};
    *module = parse_module(&parser, &error);

    if (error.present) {
        printf("Compiling error :");
        printf(error.error.message);
    }
}

void module_print(Module module) {
    func_print(module.functions);
}