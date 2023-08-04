#ifndef CODEPILER_PARSE_H
#define CODEPILER_PARSE_H

#include "func.h"
#include "module.h"
#include "error.h"
#include "code_info.h"

typedef struct {
    const char *initial_code;
    const char *code;
    CodeInfo info;
    int tab_level;
} Parser;

Module parse_module(Parser *parser, OptError *error);


#endif //CODEPILER_PARSE_H
