#include "compiler.h"
#include <stdio.h>

typedef int (*JitFunc)();

int main() {
    Compiler compiler = {0};
    if (!compiler_add_file(&compiler, "test.code")) {
        printf("Cannot find file");
    }

    compiler_compile(&compiler);
    JitFunc func_to_call = (JitFunc) compiler.module.functions->executable_code;
    return func_to_call();
}