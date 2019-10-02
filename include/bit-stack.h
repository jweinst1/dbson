#ifndef DBSON_BIT_STACK_H
#define DBSON_BIT_STACK_H

#include "compiler-info.h"

#ifndef DBSON_BIT_STACK_SIZE
#define DBSON_BIT_STACK_SIZE 128
#endif

#define DBSON_BIT_STACK_BITS (CHAR_BIT * DBSON_BIT_STACK_SIZE)

typedef struct {
    unsigned char bits[DBSON_BIT_STACK_SIZE];
    size_t top;
} dbson_BitStack;

#endif // DBSON_BIT_STACK_H
