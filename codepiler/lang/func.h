#ifndef CODEPILER_FUNC_H
#define CODEPILER_FUNC_H

#include "type.h"
#include "block.h"
#include "ir.h"
#include "../misc/flat_array.h"

typedef struct {
    const char *name;
    Type return_type;
    Type *args;
    FlatArray instructions;
    FlatArray blocks;
} Func;

IR func_add_instruction(Func *func, _IR ir);

void func_print(Func *func);

#endif //CODEPILER_FUNC_H
