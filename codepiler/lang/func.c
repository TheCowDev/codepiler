#include "func.h"
#include <stdio.h>

IR func_add_instruction(Func *func, _IR ir) {
    _IR *new_ir = flat_array_add(&func->instructions, sizeof(_IR));
    *new_ir = ir;
    return func->instructions.size - 1;
}

void func_print(Func *func) {
    printf("Func %s\n", func->name);
    for (int i = 0; i < func->instructions.size; ++i) {
        _IR *ir = flat_array_get(&func->instructions, i, sizeof(_IR));
        printf("%%%d ", i);
        switch (ir->instr) {

            case INSTR_CONST_I64:
                printf("const i64 %d", ir->int_const);
                break;

            case INSTR_RETURN:
                printf("return %d", ir->return_instr.expression);
                break;
        }

        printf("\n");

    }
}

