#include "func.h"
#include <stdio.h>

IR func_add_instruction(Func *func, _IR ir) {
    _IR *new_ir = flat_array_add(&func->instructions, sizeof(_IR));
    *new_ir = ir;
    return func->instructions.size - 1;
}

void func_print(Func func) {
    for (int i = 0; i < func.instructions_count; ++i) {
        _IR ir = func.instructions[i];
        switch (ir.instr) {

            case INSTR_CONST_I64:
                printf("const i64 %d", ir.int_const);
                break;

            case INSTR_RETURN:
                printf("return %d", ir.return_instr.expr);
                break;

        }
    }
}

