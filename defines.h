#include <cstdio>
#ifndef NULL
#error "defines.h requires NULL defined in stdio.h"
#endif

#define S_NULL NULL

// types definition
typedef enum {
  S_TYPE_INT,
  S_TYPE_LONG,
  S_TYPE_FLOAT,
  S_TYPE_DOUBLE,
  S_TYPE_CHAR,
  S_TYPE_BOOLEAN
} S_TYPE;

// var definition
typedef struct {
  S_TYPE type;
  union {
    int intVal;
    long longVal;
    float floatVal;
    double doubleVal;
    char charVal;
    bool booleanVal;
  } value;
} S_VAR;
