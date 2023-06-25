//
// Created by jan on 13.5.2023.
//

#ifndef JFMT_CFORMATTED_H
#define JFMT_CFORMATTED_H
#include <jmem/lin_jalloc.h>
#include <string.h>
#include <stdarg.h>


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
 * Counts the number of bytes needed to store the formatted string, not including the terminating null byte. Wrapper
 * around vcprintf.
 * @param support_allocator linear allocator to use for temporary buffers needed by the function
 * @param fmt format string
 * @param ... variable arguments for the format string
 * @return the number of bytes needed to store the format string
 */
JFMT_NDATTRIBUTES(format(printf, 2, 3)) size_t cprintf(linear_jallocator* support_allocator, const char* fmt, ...);

/**
 * Counts the number of bytes needed to store the formatted string, not including the terminating null byte. Called by
 * cprintf.
 * @param support_allocator linear allocator to use for temporary buffers needed by the function
 * @param fmt format string
 * @param args variable argument list for the format string
 * @return the number of bytes needed to store the format string
 */size_t vcprintf(linear_jallocator* support_allocator, const char* fmt, va_list args);


#undef JFMT_NODISCARD_ATTRIB
#undef JFMT_ATTRIBUTES
#undef JFMT_NDATTRIBUTES
#endif //JFMT_CFORMATTED_H
