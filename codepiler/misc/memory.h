#ifndef CODEPILER_MEMORY_H
#define CODEPILER_MEMORY_H

#include <stdint.h>
#include <stdlib.h>

static void *code_alloc(size_t size) {
    return malloc(size);
}

static void *code_realloc(void *memory, size_t new_size) {
    return realloc(memory, new_size);
}

static void code_free(void *memory) {
    free(memory);
}

#endif //CODEPILER_MEMORY_H
