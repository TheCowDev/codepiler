#include "x86_encoder.h"

void x86_encode_mov_reg_i64(ByteWriter *writer, X86Reg reg, long long value) {
    byte_writer_uint8(writer, 0x48); // REX prefix
    byte_writer_uint8(writer, 0xB8 | ((int) reg & 0x7)); //src register
    byte_writer_int64(writer, value);
}

void x86_encode_add_reg_to_reg(ByteWriter *writer, X86Reg left, X86Reg right) {
    byte_writer_uint8(writer, 0x01);
    unsigned char modrm = 0;
    modrm |= 3 << 6; // set operation to 11 (register-to-register)
    modrm |= (unsigned char) right << 3; // set destination register
    modrm |= (unsigned char) left; // set source register
    byte_writer_uint8(writer, modrm);
}

void x86_encode_sub_reg_to_reg(ByteWriter *writer, X86Reg left, X86Reg right) {
    byte_writer_uint8(writer, 0x29);
    unsigned char modrm = 0;
    modrm |= 3 << 6; // set operation to 11 (register-to-register)
    modrm |= (unsigned char) right << 3; // set destination register
    modrm |= (unsigned char) left; // set source register
    byte_writer_uint8(writer, modrm);
}

void x86_encode_mul_reg_to_reg(ByteWriter *writer, X86Reg left, X86Reg right) {
    byte_writer_uint8(writer, 0x0F);
    byte_writer_uint8(writer, 0xAF);
    unsigned char modrm = 0;
    modrm |= 3 << 6; // set operation to 11 (register-to-register)
    modrm |= (unsigned char) left << 3; // set destination register
    modrm |= (unsigned char) right; // set source register
    byte_writer_uint8(writer, modrm);
}

void x86_encode_div_reg_to_reg(ByteWriter *writer, X86Reg divider) {
    // idiv only works on rax and rdx
    byte_writer_uint8(writer, 0xF7);
    unsigned char modrm = 0;
    modrm |= 3 << 6; // set operation to 11 (register-to-register)
    modrm |= 7 << 3; // set operation to 11 (register-to-register)
    modrm |= (unsigned char) divider;
    byte_writer_uint8(writer, modrm);
}

void x86_encode_ret(ByteWriter *writer) {
    byte_writer_uint8(writer, 0xC3);
}