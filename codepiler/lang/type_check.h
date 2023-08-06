#ifndef CODEPILER_TYPE_CHECK_H
#define CODEPILER_TYPE_CHECK_H

static void type_check_pass(Compiler *compiler, Module *module, Func *func, _IR *ir) {

    switch (ir->instr) {
        
        case INSTR_OP_ADD:
        case INSTR_OP_SUB:
        case INSTR_OP_MUL:
        case INSTR_OP_DIV:
        case INSTR_OP_IDIV:
        case INSTR_OP_LARGER:
        case INSTR_OP_LARGER_EQ:
        case INSTR_OP_SMALLER:
        case INSTR_OP_SMALLER_EQ: {
            _IR *left = func_get_instruction(func, ir->op.left_operand);
            _IR *right = func_get_instruction(func, ir->op.right_operand);
            if (!type_eq(left->return_type, right->return_type)) {
                func_add_error(func, "Incompatible type to operate", ir->code_info);
            }
        }
            break;

    }

}

#endif //CODEPILER_TYPE_CHECK_H
