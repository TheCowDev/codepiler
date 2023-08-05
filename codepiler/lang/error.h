#ifndef CODEPILER_ERROR_H
#define CODEPILER_ERROR_H

#include <stdbool.h>
#include "code_info.h"

typedef struct {
    const char *message;
    CodeInfo info;
    int file;
} Error;

typedef struct {
    bool present;
    Error error;
} OptError;

static OptError error_opt_from_char(const char *message, CodeInfo info) {
    OptError error;
    error.present = true;
    error.error.message = message;
    error.error.info = info;
    return error;
}

#endif //CODEPILER_ERROR_H
