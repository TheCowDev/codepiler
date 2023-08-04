#ifndef CODEPILER_COMPILER_H
#define CODEPILER_COMPILER_H

#include <stdbool.h>
#include "lang/module.h"

typedef struct {
    Module module;
} Compiler;

bool compiler_add_file(Compiler *compiler, const char *file);

void compiler_compile(Compiler *compiler);

#endif //CODEPILER_COMPILER_H
