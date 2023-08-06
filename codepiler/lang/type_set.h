#ifndef CODEPILER_TYPE_SET_H
#define CODEPILER_TYPE_SET_H

static void type_set_pass(Compiler *compiler, Module *module, Func *func, _IR *ir) {

    switch (ir->instr) {

        case INSTR_CONST_I64:
            ir->return_type = type_int64();
            break;

        case INSTR_CONST_F64:
            ir->return_type = type_f64();
            break;

        case INSTR_OP_ADD:
        case INSTR_OP_SUB:
        case INSTR_OP_MUL:
        case INSTR_OP_DIV:
        case INSTR_OP_IDIV:
        case INSTR_OP_LARGER:
        case INSTR_OP_LARGER_EQ:
        case INSTR_OP_SMALLER:
        case INSTR_OP_SMALLER_EQ:
            ir->return_type = func_get_instruction(func, ir->op.left_operand)->return_type;
            break;

        default:
            ir->return_type = type_void();
            break;
    }

}

#endif //CODEPILER_TYPE_SET_H
