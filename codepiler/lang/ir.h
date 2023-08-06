#ifndef CODEPILER_IR_H
#define CODEPILER_IR_H

#include "type.h"
#include "block.h"
#include "code_info.h"

typedef enum {
    INSTR_CONST_I64 = 1,
    INSTR_CONST_F64 = 2,
    INSTR_CONST_STR = 3,

    INSTR_OP_ADD = 7,
    INSTR_OP_SUB = 8,
    INSTR_OP_MUL = 9,
    INSTR_OP_DIV = 10,
    INSTR_OP_IDIV = 11,

    INSTR_OP_EQ = 12,
    INSTR_OP_DIFF = 13,
    INSTR_OP_LARGER = 14,
    INSTR_OP_LARGER_EQ = 15,
    INSTR_OP_SMALLER = 16,
    INSTR_OP_SMALLER_EQ = 17,

    INSTR_NOT = 18,

    INSTR_LOAD_ATTR = 19,
    INSTR_SET_ATTR = 20,

    INSTR_GET_LOCAL = 21,
    INSTR_SET_LOCAL = 22,

    INSTR_IF = 23,
    INSTR_WHILE = 24,

    INSTR_CALL = 25,

    INSTR_RETURN = 26,
    INSTR_RETURN_VOID = 27,

} Instr;

typedef int IR;

static const IR INVALID_IR = -1;

typedef struct {
    Instr instr;

    union {

        long long int_const;
        double float_const;

        struct {
            IR left_operand;
            IR right_operand;
        } op;

        IR not;

        struct {
            IR condition;
            Block true_block;
            Block *else_if_blocks;
            Block *else_block;
            Block *continue_block;
        } cond_if;

        struct {
            Block *loop_block;
            Block *continue_block;
        } cond_while;

        struct {
            int var_index;
        } local_get;

        struct {
            int var_index;
            IR value_to_set;
        } local_set;

        struct {
            IR expression;
        } return_instr;

    };

    Type return_type;
    CodeInfo code_info;
} _IR;

#endif //CODEPILER_IR_H