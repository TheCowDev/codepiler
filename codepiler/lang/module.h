#ifndef CODEPILER_MODULE_H
#define CODEPILER_MODULE_H

#include "func.h"

typedef struct {
    const char *name;
    const char *raw_code;
    Func *functions;
} Module;

void module_parse(Module *module);

void module_print(Module module);

#endif //CODEPILER_MODULE_H
