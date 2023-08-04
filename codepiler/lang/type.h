#ifndef CODEPILER_TYPE_H
#define CODEPILER_TYPE_H

typedef enum {
    DATA_TYPE_VOID = 0,
    DATA_TYPE_PRIMITIVE = 1,
    DATA_TYPE_STRUCT = 2,
    DATA_TYPE_ENUM = 3,
} DataType;

typedef enum {
    PRIMITIVE_TYPE_I64,
    PRIMITIVE_TYPE_F64
} PrimitiveType;

typedef struct {
    char *str_name;
    DataType data_type;

    union {
        PrimitiveType primitive;
        int struct_id;
        int enum_id;
    };
    int ptr_depth;
} Type;

static Type type_void() {
    return (Type) {0};
}

static Type type_int64() {
    Type type;
    type.data_type = DATA_TYPE_PRIMITIVE;
    type.primitive = PRIMITIVE_TYPE_I64;
    return type;
}

static Type type_f64() {
    Type type;
    type.data_type = DATA_TYPE_PRIMITIVE;
    type.primitive = PRIMITIVE_TYPE_F64;
    return type;
}

#endif //CODEPILER_TYPE_H
