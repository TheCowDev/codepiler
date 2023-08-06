#ifndef CODEPILER_CODEGEN_H
#define CODEPILER_CODEGEN_H

#include "../lang/pass.h"

IrPass codegen_get_pass();

FunctionPass codegen_get_jit_gen_pass();

#endif //CODEPILER_CODEGEN_H
