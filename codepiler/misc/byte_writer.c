#include "byte_writer.h"
#include "memory.h"

static void expand(ByteWriter *writer, size_t new_size) {
    if (writer->current_index + new_size >= writer->capacity) {
        writer->capacity = writer->current_index + new_size + 1 * 2;
        writer->data = code_realloc(writer->data, writer->capacity);
    }
}

void byte_writer_free(ByteWriter *writer) {
    code_free(writer->data);
}

int byte_writer_uint8(ByteWriter *writer, uint8_t value) {
    size_t result = writer->current_index;
    expand(writer, sizeof(value));
    uint8_t *value_ptr = (uint8_t *) &writer->data[writer->current_index];
    *value_ptr = value;
    writer->current_index += sizeof(value);
    return result;
}

int byte_writer_int8(ByteWriter *writer, int8_t value) {
    size_t result = writer->current_index;
    expand(writer, sizeof(value));
    int8_t *value_ptr = (uint8_t *) &writer->data[writer->current_index];
    *value_ptr = value;
    writer->current_index += sizeof(value);
    return result;
}

int byte_writer_int32(ByteWriter *writer, int32_t value) {
    size_t result = writer->current_index;
    expand(writer, sizeof(value));
    int32_t *value_ptr = (int32_t *) &writer->data[writer->current_index];
    *value_ptr = value;
    writer->current_index += sizeof(value);
    return result;
}

void byte_writer_int32_at(ByteWriter *writer, int32_t value, size_t offset) {
    int32_t *value_ptr = (int32_t *) &writer->data[offset];
    *value_ptr = value;
}

int byte_writer_int64(ByteWriter *writer, int64_t value) {
    size_t result = writer->current_index;
    expand(writer, sizeof(value));
    int64_t *value_ptr = (uint64_t *) &writer->data[writer->current_index];
    *value_ptr = value;
    writer->current_index += sizeof(value);
    return result;
}

int byte_writer_f32(ByteWriter *writer, float value) {
    size_t result = writer->current_index;
    expand(writer, sizeof(value));
    float *value_ptr = (float *) &writer->data[writer->current_index];
    *value_ptr = value;
    writer->current_index += sizeof(value);
    return result;
}

int byte_writer_f64(ByteWriter *writer, double value) {
    size_t result = writer->current_index;
    expand(writer, sizeof(value));
    double *value_ptr = (double *) &writer->data[writer->current_index];
    *value_ptr = value;
    writer->current_index += sizeof(value);
    return result;
}

int byte_writer_size(ByteWriter *writer) {
    return writer->current_index;
}