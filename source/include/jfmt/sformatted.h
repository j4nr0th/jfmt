//
// Created by jan on 13.5.2023.
//

#ifndef JFMT_SFORMATTED_H
#define JFMT_SFORMATTED_H
#include <string.h>
#include <stdarg.h>
#include <jmem/lin_jalloc.h>


#if __STDC_VERSION__ >= 201112L
#define JFMT_NODISCARD_ATTRIB [[nodiscard]]
#else
#ifdef __GNUC__
#define JFMT_NODISCARD_ATTRIB __attribute__((warn_unused_result))
#else
#define JFMT_NODISCARD_ATTRIB
#endif
#endif
#ifdef __GNUC__
#define JFMT_ATTRIBUTES(...) __VA_OPT__(__attribute__((__VA_ARGS__)))
#define JFMT_NDATTRIBUTES(...) __attribute__((warn_unused_result __VA_OPT__(,)__VA_ARGS__))
#endif

/**
 * Prints the formatted string into a buffer which is allocated as needed from the provided linear allocator. Wrapper
 * around lin_vsprintf.
 * @param allocator linear allocator to use for temporary buffers and output
 * @param p_size pointer to store the size of the resulting string
 * @param fmt format string
 * @param ... variable arguments for the format string
 * @return pointer to the output string or null on failure
 */
JFMT_NDATTRIBUTES(format(printf, 3, 4)) char* lin_sprintf(linear_jallocator* allocator, size_t* p_size, const char* fmt, ...);

/**
 * Appends a string previously allocated by lin_sprintf or lin_asprintf. Wrapper around lin_vaprintf.
 * @param allocator linear allocator to use for temporary buffers and output
 * @param previous pointer to pointer previously returned by lin_sprintf or lin_asprintf
 * @param p_size pointer to read and store the size of the resulting string
 * @param fmt format string
 * @param ... variable arguments for the format string
 * @return pointer to the output string or null on failure
 */
JFMT_NDATTRIBUTES(format(printf, 4, 5)) char* lin_aprintf(linear_jallocator* allocator, char* previous, size_t* p_size, const char* fmt, ...);

/**
 * Prints the formatted string into a buffer which is allocated as needed from the provided linear allocator. Called by
 * lin_sprintf.
 * @param allocator linear allocator to use for temporary buffers and output
 * @param p_size pointer to store the size of the resulting string
 * @param fmt format string
 * @param args variable argument list
 * @return pointer to the output string or null on failure
 */
char* lin_vsprintf(linear_jallocator* allocator, size_t* p_size, const char* fmt, va_list args);

/**
 * Appends a string previously allocated by lin_sprintf or lin_asprintf. Called by lin_aprintf.
 * @param allocator linear allocator to use for temporary buffers and output
 * @param previous pointer to pointer previously returned by lin_sprintf or lin_asprintf
 * @param p_size pointer to read and store the size of the resulting string
 * @param fmt format string
 * @param ... variable arguments for the format string
 * @return pointer to the output string or null on failure
 */
char* lin_vaprintf(linear_jallocator* allocator, char* previous, size_t* p_size, const char* fmt, va_list args);

/**
 * Uses linear allocator to call lin_vsprintf and write the output to stderr directly.
 * @param allocator allocator to use for intermediate buffers and calls to formatting functions.
 * @param fmt
 * @param ...
 */
JFMT_ATTRIBUTES(format(printf, 2, 3))void lin_eprintf(linear_jallocator* allocator, const char* fmt, ...);

#undef JFMT_NODISCARD_ATTRIB
#undef JFMT_ATTRIBUTES
#undef JFMT_NDATTRIBUTES
#endif //JFMT_SFORMATTED_H
