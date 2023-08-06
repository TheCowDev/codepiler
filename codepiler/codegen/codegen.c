#include "codegen.h"
#include <windows.h>
#include "x86/x86_gen_pass.h"

IrPass codegen_get_pass() {
    return x86_gen_pass;
}

void func_exec_memory_pass(Compiler *compiler, Module *module, Func *func) {
    const int code_size = byte_writer_size(&func->machine_code);
    func->executable_code = VirtualAlloc(NULL, code_size,
                                         MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);
    memcpy(func->executable_code, func->machine_code.data, code_size);
}

FunctionPass codegen_get_jit_gen_pass() {
    return func_exec_memory_pass;
}
