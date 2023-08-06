#ifndef CODEPILER_PASS_H
#define CODEPILER_PASS_H

#include "../compiler.h"

typedef void (*ModulePass)(Compiler *, Module *);

typedef void (*FunctionPass)(Compiler *, Module *, Func *);

typedef void (*IrPass)(Compiler *, Module *, Func *, _IR *ir);

#endif //CODEPILER_PASS_H
