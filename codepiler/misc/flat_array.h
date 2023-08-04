#ifndef CODEPILER_FLAT_ARRAY_H
#define CODEPILER_FLAT_ARRAY_H

#include "memory.h"

typedef struct {
    char *data;
    size_t size;
    size_t capacity;
} FlatArray;

static void flat_array_free(FlatArray *array) {
    code_free(array->data);
}

static void *flat_array_add(FlatArray *array, int element_size) {
    if (array->size >= array->capacity) {
        array->capacity = (array->capacity + 1) * 2;
        array->data = (char *) code_realloc(array->data, array->capacity * element_size);
    }

    ++array->size;
    return &array->data[(array->size - 1) * element_size];
}

static void *flat_array_get(FlatArray *array, int index, const int element_size) {
    return &array->data[element_size * index];
}

#endif //OESERVER_FLAT_ARRAY_H
