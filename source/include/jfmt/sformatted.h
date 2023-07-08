//
// Created by jan on 13.5.2023.
//

#ifndef JFMT_SFORMATTED_H
#define JFMT_SFORMATTED_H
#include <string.h>
#include <stdarg.h>
#include "jfmt_common.h"

#ifdef __GNUC__
#define GCC_ONLY(x) x
#endif


/**
 * Prints the formatted string into a buffer which is allocated as needed from the provided linear allocator. Wrapper
 * around lin_vsprintf.
 * @param allocation_callbacks linear allocator to use for temporary buffers and output
 * @param p_size pointer to store the size of the resulting string
 * @param fmt format string
 * @param ... variable arguments for the format string
 * @return pointer to the output string or null on failure
 */
GCC_ONLY(__attribute__((warn_unused_result, format(printf, 3, 4))))
char* lin_sprintf(jfmt_allocation_callbacks* allocation_callbacks, size_t* p_size, const char* fmt, ...);

/**
 * Appends a string previously allocated by lin_sprintf or lin_asprintf. Wrapper around lin_vaprintf.
 * @param allocation_callbacks linear allocator to use for temporary buffers and output
 * @param previous pointer to pointer previously returned by lin_sprintf or lin_asprintf
 * @param p_size pointer to read and store the size of the resulting string
 * @param fmt format string
 * @param ... variable arguments for the format string
 * @return pointer to the output string or null on failure
 */
GCC_ONLY(__attribute__((warn_unused_result, format(printf, 4, 5))))
char* lin_aprintf(jfmt_allocation_callbacks* allocation_callbacks, char* previous, size_t* p_size, const char* fmt, ...);

/**
 * Prints the formatted string into a buffer which is allocated as needed from the provided linear allocator. Called by
 * lin_sprintf.
 * @param allocation_callbacks linear allocator to use for temporary buffers and output
 * @param p_size pointer to store the size of the resulting string
 * @param fmt format string
 * @param args variable argument list
 * @return pointer to the output string or null on failure
 */
GCC_ONLY(__attribute__((warn_unused_result)))
char* lin_vsprintf(jfmt_allocation_callbacks* allocation_callbacks, size_t* p_size, const char* fmt, va_list args);

/**
 * Appends a string previously allocated by lin_sprintf or lin_asprintf. Called by lin_aprintf.
 * @param allocation_callbacks linear allocator to use for temporary buffers and output
 * @param previous pointer to pointer previously returned by lin_sprintf or lin_asprintf
 * @param p_size pointer to read and store the size of the resulting string
 * @param fmt format string
 * @param ... variable arguments for the format string
 * @return pointer to the output string or null on failure
 */
GCC_ONLY(__attribute__((warn_unused_result)))
char* lin_vaprintf(jfmt_allocation_callbacks* allocation_callbacks, char* previous, size_t* p_size, const char* fmt, va_list args);

/**
 * Uses linear allocator to call lin_vsprintf and write the output to stderr directly.
 * @param allocation_callbacks allocator to use for intermediate buffers and calls to formatting functions.
 * @param fmt
 * @param ...
 */
GCC_ONLY(__attribute__((format(printf, 2, 3))))
void lin_eprintf(jfmt_allocation_callbacks* allocation_callbacks, const char* fmt, ...);

#undef GCC_ONLY
#endif //JFMT_SFORMATTED_H
