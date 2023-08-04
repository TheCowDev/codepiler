#include "compiler.h"
#include <stdio.h>
#include "misc/memory.h"

static const char *read_all_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file: %s\n", filename);
        return NULL;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);

    char *buffer = (char *) code_alloc(file_size + 1);
    if (buffer == NULL) {
        printf("Failed to allocate memory for file content.\n");
        fclose(file);
        return NULL;
    }
    fread(buffer, sizeof(char), file_size, file);
    buffer[file_size] = '\0';

    fclose(file);
    return buffer;
}

bool compiler_add_file(Compiler *compiler, const char *filename) {
    const char *code = read_all_file(filename);
    if (code != NULL) {
        compiler->module.raw_code = code;
        return true;
    } else {
        printf("Can't read the file");
    }

    return false;
}

void compiler_compile(Compiler *compiler) {
    module_parse(&compiler->module);
}