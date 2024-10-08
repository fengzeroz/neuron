/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: opentelemetry/proto/common/v1/common.proto */

#ifndef PROTOBUF_C_opentelemetry_2fproto_2fcommon_2fv1_2fcommon_2eproto__INCLUDED
#define PROTOBUF_C_opentelemetry_2fproto_2fcommon_2fv1_2fcommon_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1003000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1004000 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct Opentelemetry__Proto__Common__V1__AnyValue Opentelemetry__Proto__Common__V1__AnyValue;
typedef struct Opentelemetry__Proto__Common__V1__ArrayValue Opentelemetry__Proto__Common__V1__ArrayValue;
typedef struct Opentelemetry__Proto__Common__V1__KeyValueList Opentelemetry__Proto__Common__V1__KeyValueList;
typedef struct Opentelemetry__Proto__Common__V1__KeyValue Opentelemetry__Proto__Common__V1__KeyValue;
typedef struct Opentelemetry__Proto__Common__V1__InstrumentationScope Opentelemetry__Proto__Common__V1__InstrumentationScope;


/* --- enums --- */


/* --- messages --- */

typedef enum {
  OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE__NOT_SET = 0,
  OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE_STRING_VALUE = 1,
  OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE_BOOL_VALUE = 2,
  OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE_INT_VALUE = 3,
  OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE_DOUBLE_VALUE = 4,
  OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE_ARRAY_VALUE = 5,
  OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE_KVLIST_VALUE = 6,
  OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE_BYTES_VALUE = 7
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE__CASE)
} Opentelemetry__Proto__Common__V1__AnyValue__ValueCase;

/*
 * AnyValue is used to represent any type of attribute value. AnyValue may contain a
 * primitive value such as a string or integer or it may contain an arbitrary nested
 * object containing arrays, key-value lists and primitives.
 */
struct  Opentelemetry__Proto__Common__V1__AnyValue
{
  ProtobufCMessage base;
  Opentelemetry__Proto__Common__V1__AnyValue__ValueCase value_case;
  union {
    char *string_value;
    protobuf_c_boolean bool_value;
    int64_t int_value;
    double double_value;
    Opentelemetry__Proto__Common__V1__ArrayValue *array_value;
    Opentelemetry__Proto__Common__V1__KeyValueList *kvlist_value;
    ProtobufCBinaryData bytes_value;
  };
};
#define OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__common__v1__any_value__descriptor) \
    , OPENTELEMETRY__PROTO__COMMON__V1__ANY_VALUE__VALUE__NOT_SET, {0} }


/*
 * ArrayValue is a list of AnyValue messages. We need ArrayValue as a message
 * since oneof in AnyValue does not allow repeated fields.
 */
struct  Opentelemetry__Proto__Common__V1__ArrayValue
{
  ProtobufCMessage base;
  /*
   * Array of values. The array may be empty (contain 0 elements).
   */
  size_t n_values;
  Opentelemetry__Proto__Common__V1__AnyValue **values;
};
#define OPENTELEMETRY__PROTO__COMMON__V1__ARRAY_VALUE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__common__v1__array_value__descriptor) \
    , 0,NULL }


/*
 * KeyValueList is a list of KeyValue messages. We need KeyValueList as a message
 * since `oneof` in AnyValue does not allow repeated fields. Everywhere else where we need
 * a list of KeyValue messages (e.g. in Span) we use `repeated KeyValue` directly to
 * avoid unnecessary extra wrapping (which slows down the protocol). The 2 approaches
 * are semantically equivalent.
 */
struct  Opentelemetry__Proto__Common__V1__KeyValueList
{
  ProtobufCMessage base;
  /*
   * A collection of key/value pairs of key-value pairs. The list may be empty (may
   * contain 0 elements).
   * The keys MUST be unique (it is not allowed to have more than one
   * value with the same key).
   */
  size_t n_values;
  Opentelemetry__Proto__Common__V1__KeyValue **values;
};
#define OPENTELEMETRY__PROTO__COMMON__V1__KEY_VALUE_LIST__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__common__v1__key_value_list__descriptor) \
    , 0,NULL }


/*
 * KeyValue is a key-value pair that is used to store Span attributes, Link
 * attributes, etc.
 */
struct  Opentelemetry__Proto__Common__V1__KeyValue
{
  ProtobufCMessage base;
  char *key;
  Opentelemetry__Proto__Common__V1__AnyValue *value;
};
#define OPENTELEMETRY__PROTO__COMMON__V1__KEY_VALUE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__common__v1__key_value__descriptor) \
    , (char *)protobuf_c_empty_string, NULL }


/*
 * InstrumentationScope is a message representing the instrumentation scope information
 * such as the fully qualified name and version. 
 */
struct  Opentelemetry__Proto__Common__V1__InstrumentationScope
{
  ProtobufCMessage base;
  /*
   * An empty instrumentation scope name means the name is unknown.
   */
  char *name;
  char *version;
  /*
   * Additional attributes that describe the scope. [Optional].
   * Attribute keys MUST be unique (it is not allowed to have more than one
   * attribute with the same key).
   */
  size_t n_attributes;
  Opentelemetry__Proto__Common__V1__KeyValue **attributes;
  uint32_t dropped_attributes_count;
};
#define OPENTELEMETRY__PROTO__COMMON__V1__INSTRUMENTATION_SCOPE__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&opentelemetry__proto__common__v1__instrumentation_scope__descriptor) \
    , (char *)protobuf_c_empty_string, (char *)protobuf_c_empty_string, 0,NULL, 0 }


/* Opentelemetry__Proto__Common__V1__AnyValue methods */
void   opentelemetry__proto__common__v1__any_value__init
                     (Opentelemetry__Proto__Common__V1__AnyValue         *message);
size_t opentelemetry__proto__common__v1__any_value__get_packed_size
                     (const Opentelemetry__Proto__Common__V1__AnyValue   *message);
size_t opentelemetry__proto__common__v1__any_value__pack
                     (const Opentelemetry__Proto__Common__V1__AnyValue   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__common__v1__any_value__pack_to_buffer
                     (const Opentelemetry__Proto__Common__V1__AnyValue   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Common__V1__AnyValue *
       opentelemetry__proto__common__v1__any_value__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__common__v1__any_value__free_unpacked
                     (Opentelemetry__Proto__Common__V1__AnyValue *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Common__V1__ArrayValue methods */
void   opentelemetry__proto__common__v1__array_value__init
                     (Opentelemetry__Proto__Common__V1__ArrayValue         *message);
size_t opentelemetry__proto__common__v1__array_value__get_packed_size
                     (const Opentelemetry__Proto__Common__V1__ArrayValue   *message);
size_t opentelemetry__proto__common__v1__array_value__pack
                     (const Opentelemetry__Proto__Common__V1__ArrayValue   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__common__v1__array_value__pack_to_buffer
                     (const Opentelemetry__Proto__Common__V1__ArrayValue   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Common__V1__ArrayValue *
       opentelemetry__proto__common__v1__array_value__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__common__v1__array_value__free_unpacked
                     (Opentelemetry__Proto__Common__V1__ArrayValue *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Common__V1__KeyValueList methods */
void   opentelemetry__proto__common__v1__key_value_list__init
                     (Opentelemetry__Proto__Common__V1__KeyValueList         *message);
size_t opentelemetry__proto__common__v1__key_value_list__get_packed_size
                     (const Opentelemetry__Proto__Common__V1__KeyValueList   *message);
size_t opentelemetry__proto__common__v1__key_value_list__pack
                     (const Opentelemetry__Proto__Common__V1__KeyValueList   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__common__v1__key_value_list__pack_to_buffer
                     (const Opentelemetry__Proto__Common__V1__KeyValueList   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Common__V1__KeyValueList *
       opentelemetry__proto__common__v1__key_value_list__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__common__v1__key_value_list__free_unpacked
                     (Opentelemetry__Proto__Common__V1__KeyValueList *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Common__V1__KeyValue methods */
void   opentelemetry__proto__common__v1__key_value__init
                     (Opentelemetry__Proto__Common__V1__KeyValue         *message);
size_t opentelemetry__proto__common__v1__key_value__get_packed_size
                     (const Opentelemetry__Proto__Common__V1__KeyValue   *message);
size_t opentelemetry__proto__common__v1__key_value__pack
                     (const Opentelemetry__Proto__Common__V1__KeyValue   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__common__v1__key_value__pack_to_buffer
                     (const Opentelemetry__Proto__Common__V1__KeyValue   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Common__V1__KeyValue *
       opentelemetry__proto__common__v1__key_value__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__common__v1__key_value__free_unpacked
                     (Opentelemetry__Proto__Common__V1__KeyValue *message,
                      ProtobufCAllocator *allocator);
/* Opentelemetry__Proto__Common__V1__InstrumentationScope methods */
void   opentelemetry__proto__common__v1__instrumentation_scope__init
                     (Opentelemetry__Proto__Common__V1__InstrumentationScope         *message);
size_t opentelemetry__proto__common__v1__instrumentation_scope__get_packed_size
                     (const Opentelemetry__Proto__Common__V1__InstrumentationScope   *message);
size_t opentelemetry__proto__common__v1__instrumentation_scope__pack
                     (const Opentelemetry__Proto__Common__V1__InstrumentationScope   *message,
                      uint8_t             *out);
size_t opentelemetry__proto__common__v1__instrumentation_scope__pack_to_buffer
                     (const Opentelemetry__Proto__Common__V1__InstrumentationScope   *message,
                      ProtobufCBuffer     *buffer);
Opentelemetry__Proto__Common__V1__InstrumentationScope *
       opentelemetry__proto__common__v1__instrumentation_scope__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   opentelemetry__proto__common__v1__instrumentation_scope__free_unpacked
                     (Opentelemetry__Proto__Common__V1__InstrumentationScope *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*Opentelemetry__Proto__Common__V1__AnyValue_Closure)
                 (const Opentelemetry__Proto__Common__V1__AnyValue *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Common__V1__ArrayValue_Closure)
                 (const Opentelemetry__Proto__Common__V1__ArrayValue *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Common__V1__KeyValueList_Closure)
                 (const Opentelemetry__Proto__Common__V1__KeyValueList *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Common__V1__KeyValue_Closure)
                 (const Opentelemetry__Proto__Common__V1__KeyValue *message,
                  void *closure_data);
typedef void (*Opentelemetry__Proto__Common__V1__InstrumentationScope_Closure)
                 (const Opentelemetry__Proto__Common__V1__InstrumentationScope *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCMessageDescriptor opentelemetry__proto__common__v1__any_value__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__common__v1__array_value__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__common__v1__key_value_list__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__common__v1__key_value__descriptor;
extern const ProtobufCMessageDescriptor opentelemetry__proto__common__v1__instrumentation_scope__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_opentelemetry_2fproto_2fcommon_2fv1_2fcommon_2eproto__INCLUDED */
