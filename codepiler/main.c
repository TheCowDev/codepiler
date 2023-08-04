#include "compiler.h"
#include <stdio.h>

int main() {
    Compiler compiler = {0};
    if (!compiler_add_file(&compiler, "test.code")) {
        printf("Cannot find file");
    }
    compiler_compile(&compiler);
    return 0;
}