#ifndef CODEPILER_X86_ENCODER_H
#define CODEPILER_X86_ENCODER_H

#include "x86_info.h"
#include "../../misc/byte_writer.h"

void x86_encode_mov_reg_i64(ByteWriter *writer, X86Reg reg, long long value);

void x86_encode_add_reg_to_reg(ByteWriter *writer, X86Reg left, X86Reg right);

void x86_encode_sub_reg_to_reg(ByteWriter *writer, X86Reg left, X86Reg right);

void x86_encode_mul_reg_to_reg(ByteWriter *writer, X86Reg left, X86Reg right);

void x86_encode_div_reg_to_reg(ByteWriter *writer, X86Reg divider);

void x86_encode_ret(ByteWriter *writer);

#endif //CODEPILER_X86_ENCODER_H
