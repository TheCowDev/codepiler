#include "func.h"
#include <stdio.h>

IR func_add_instruction(Func *func, _IR ir) {
    _IR *new_ir = flat_array_add(&func->instructions, sizeof(_IR));
    *new_ir = ir;
    new_ir->index = func->instructions.size - 1;
    return new_ir->index;
}

_IR *func_get_instruction(Func *func, int index) {
    return flat_array_get(&func->instructions, index, sizeof(_IR));
}

void func_add_error(Func *func, const char *error, CodeInfo info) {
    Error *new_error = flat_array_add(&func->errors, sizeof(Error));
    new_error->message = error;
    new_error->info = info;
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

            case INSTR_OP_ADD:
                printf("add %d %d", ir->op.left_operand, ir->op.right_operand);
                break;

            case INSTR_OP_SUB:
                printf("sub %d %d", ir->op.left_operand, ir->op.right_operand);
                break;

            case INSTR_OP_MUL:
                printf("mul %d %d", ir->op.left_operand, ir->op.right_operand);
                break;

            case INSTR_OP_DIV:
                printf("div %d %d", ir->op.left_operand, ir->op.right_operand);
                break;

            case INSTR_RETURN:
                printf("return %d", ir->return_instr.expression);
                break;

        }

        printf("\n");

    }
}

