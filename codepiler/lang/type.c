#include "type.h"

Type type_void() {
    Type type;
    type.data_type = DATA_TYPE_PRIMITIVE;
    type.primitive = PRIMITIVE_TYPE_I64;
    type.ptr_depth = 0;
    return type;
}

Type type_int64() {
    Type type;
    type.data_type = DATA_TYPE_PRIMITIVE;
    type.primitive = PRIMITIVE_TYPE_I64;
    type.ptr_depth = 0;
    return type;
}

Type type_f64() {
    Type type;
    type.data_type = DATA_TYPE_PRIMITIVE;
    type.primitive = PRIMITIVE_TYPE_F64;
    type.ptr_depth = 0;
    return type;
}

bool type_is_int64(Type type) {
    return type.data_type == DATA_TYPE_PRIMITIVE && type.primitive == PRIMITIVE_TYPE_I64 && type.ptr_depth == 0;
}

bool type_is_f64(Type type) {
    return type.data_type == DATA_TYPE_PRIMITIVE && type.primitive == PRIMITIVE_TYPE_F64 && type.ptr_depth == 0;
}

bool type_eq(Type a, Type b) {
    if (a.data_type == b.data_type && a.ptr_depth == b.ptr_depth) {
        switch (a.data_type) {

            case DATA_TYPE_VOID:
                return true;

            case DATA_TYPE_PRIMITIVE:
                return a.primitive == b.primitive;

            case DATA_TYPE_STRUCT:
                return a.struct_id == b.struct_id;

            case DATA_TYPE_ENUM:
                return a.enum_id == b.enum_id;
        }
    }

    return false;
}