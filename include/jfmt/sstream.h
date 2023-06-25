//
// Created by jan on 10.6.2023.
//

#ifndef JFMT_SSTREAM_H
#define JFMT_SSTREAM_H
#include "sformatted.h"
#include <jmem/jalloc.h>


#if __STDC_VERSION__ >= 201112L
#define NODISCARD_ATTRIB [[nodiscard]]
#else
#ifdef __GNUC__
#define JFMT_NODISCARD_ATTRIB __attribute__((warn_unused_result))
#else
#define NODISCARD_ATTRIB
#endif
#endif

#ifdef __GNUC__
#define JFMT_ATTRIBUTES(...) __VA_OPT__(__attribute__((__VA_ARGS__)))
#define JFMT_NDATTRIBUTES(...) JMEM_NODISCARD_ATTRIB __VA_OPT__(__attribute__((__VA_ARGS__)))
#endif

/**
 * @brief Stores the state associated with the string stream. Intended as a string which is incrementally build using
 * formatted input.
 */
typedef struct string_stream_struct string_stream;

/**
 * Creates a string stream and associates it with a given allocator that it will use.
 * @param allocator allocator to use for the string stream's buffer
 * @param p_stream pointer which receives the string stream
 * @return 0 on success, (size_t)-1 on failure
 */
size_t string_stream_create(jallocator* allocator, string_stream** p_stream);

/**
 * Adds more to the end of the current string stream contents
 * @param stream stream to which to add to
 * @param fmt format string
 * @param ... variable arguments form the string stream
 * @return number of characters written to the stream, (size_t)-1 on failure
 */
size_t string_stream_add(string_stream* stream, const char* fmt, ...)JFMT_ATTRIBUTES(format(printf, 2, 3));

/**
 * Retrieves the current contents of the string stream. The buffer belongs to the string stream so it should not be
 * freed may be invalidated by subsequent function calls with the same string stream
 * @param stream stream for which to retrieve the contents from
 * @return stream's content buffer
 */
char* string_stream_contents(string_stream* stream);

/**
 * Adds a string to the string stream the way calling string_stream_add(stream, "%s", str) would, but more efficiently.
 * @param stream stream to which the string is added to
 * @param str string to add to the stream
 * @return number of characters added on success, (-1) on failure
 */
size_t string_stream_add_str(string_stream* stream, const char* str);

/**
 * Finds the current length of the string stream's buffer
 * @param stream string stream to examine
 * @return size of the string stream's buffer
 */
size_t string_stream_len(string_stream* stream);

/**
 * Clears the string streams and empties its buffer
 * @param stream stream to reset
 */
void string_stream_reset(string_stream* stream);

/**
 * Destroys the string stream and releases all of its memory
 * @param stream stream to destroy
 */
void string_stream_destroy(string_stream* stream);

#undef JFMT_NODISCARD_ATTRIB
#undef JFMT_ATTRIBUTES
#undef JFMT_NDATTRIBUTES

#endif //JFMT_SSTREAM_H
