#include "x86_gen_pass.h"
#include "x86_encoder.h"

void x86_gen_pass(Compiler *compiler, Module *module, Func *func, _IR *ir) {
    ByteWriter *writer = &func->machine_code;
    switch (ir->instr) {

        case INSTR_CONST_I64:
            x86_encode_mov_reg_i64(writer, ir->index, ir->int_const);
            break;

        case INSTR_OP_ADD:
            x86_encode_add_reg_to_reg(writer, ir->op.left_operand, ir->op.right_operand);
            break;

        case INSTR_OP_SUB:
            x86_encode_sub_reg_to_reg(writer, ir->op.left_operand, ir->op.right_operand);
            break;

        case INSTR_OP_MUL:
            x86_encode_mul_reg_to_reg(writer, ir->op.left_operand, ir->op.right_operand);
            break;

        case INSTR_RETURN:
            x86_encode_ret(writer);
            break;
    }
}