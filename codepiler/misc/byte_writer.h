#ifndef CODEPILER_BYTE_WRITER_H
#define CODEPILER_BYTE_WRITER_H


#include <stdint.h>

typedef struct {
    char *data;
    int current_index;
    int capacity;
} ByteWriter;

void byte_writer_free(ByteWriter *writer);

int byte_writer_uint8(ByteWriter *writer, uint8_t value);

int byte_writer_int8(ByteWriter *writer, int8_t value);

int byte_writer_int32(ByteWriter *writer, int32_t value);

void byte_writer_int32_at(ByteWriter *writer, int32_t value, size_t offset);

int byte_writer_int64(ByteWriter *writer, int64_t value);

int byte_writer_f32(ByteWriter *writer, float value);

int byte_writer_f64(ByteWriter *writer, double value);

int byte_writer_size(ByteWriter *writer);

#endif //CODEPILER_BYTE_WRITER_H
