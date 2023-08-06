#ifndef CODEPILER_FUNC_H
#define CODEPILER_FUNC_H

#include "type.h"
#include "block.h"
#include "error.h"
#include "ir.h"
#include "../misc/flat_array.h"
#include "../misc/byte_writer.h"

typedef struct {
    const char *name;
    Type return_type;
    Type *args;
    FlatArray errors;

    FlatArray instructions;
    FlatArray blocks;

    ByteWriter machine_code;
    char *executable_code;
} Func;

IR func_add_instruction(Func *func, _IR ir);

_IR *func_get_instruction(Func *func, int index);

void func_add_error(Func *func, const char *error, CodeInfo info);

void func_print(Func *func);

#endif //CODEPILER_FUNC_H
