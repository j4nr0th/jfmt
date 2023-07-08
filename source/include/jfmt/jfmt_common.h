//
// Created by jan on 8.7.2023.
//

#ifndef JFMT_JFMT_COMMON_H
#define JFMT_JFMT_COMMON_H
#include <stdint.h>

typedef struct jfmt_allocation_callbacks_struct jfmt_allocation_callbacks;
struct jfmt_allocation_callbacks_struct
{
    void* (*alloc)(void* param, uint64_t size);
    void (*free)(void* param, void* ptr);
    void* (*realloc)(void* param, void* ptr, uint64_t new_size);
    void* param;
};

#endif //JFMT_JFMT_COMMON_H
