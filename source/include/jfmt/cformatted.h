//
// Created by jan on 13.5.2023.
//

#ifndef JFMT_CFORMATTED_H
#define JFMT_CFORMATTED_H
#include <string.h>
#include <stdarg.h>
#include "jfmt_common.h"

#ifdef __GNUC__
#define GCC_ONLY(x) x
#endif

/**
 * Counts the number of bytes needed to store the formatted string, not including the terminating null byte. Wrapper
 * around vcprintf.
 * @param allocation_callbacks linear allocator to use for temporary buffers needed by the function
 * @param fmt format string
 * @param ... variable arguments for the format string
 * @return the number of bytes needed to store the format string
 */
GCC_ONLY(__attribute__((format(printf, 2, 3))))
size_t cprintf(jfmt_allocation_callbacks* allocation_callbacks, const char* fmt, ...);

/**
 * Counts the number of bytes needed to store the formatted string, not including the terminating null byte. Called by
 * cprintf.
 * @param allocation_callbacks linear allocator to use for temporary buffers needed by the function
 * @param fmt format string
 * @param args variable argument list for the format string
 * @return the number of bytes needed to store the format string
 */
size_t vcprintf(jfmt_allocation_callbacks* allocation_callbacks, const char* fmt, va_list args);

#undef GCC_ONLY

#endif //JFMT_CFORMATTED_H
