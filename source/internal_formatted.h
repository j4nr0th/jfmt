//
// Created by jan on 10.6.2023.
//

#ifndef JFMT_INTERNAL_FORMATTED_H
#define JFMT_INTERNAL_FORMATTED_H
#include <stdint.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

/**
 * Gets the least significant digit in base 10 in the unsigned integer and divides it by 10
 * @param p_value pointer to the integer value
 * @return character which represents the LSD
 */
char unsigned_get_lsd_dec_and_shift(uintmax_t* p_value);

/**
 * Gets the least significant digit in base 8 in the unsigned integer and divides it by 8
 * @param p_value pointer to the integer value
 * @return character which represents the LSD
 */
char unsigned_get_lsd_oct_and_shift(uintmax_t* p_value);

/**
 * Gets the least significant digit in base 16 in the unsigned integer and divides it by 16. Lower case.
 * @param p_value pointer to the integer value
 * @return character which represents the LSD
 */
char unsigned_get_lsd_hex_and_shift(uintmax_t* p_value);

/**
 * Gets the least significant digit in base 16 in the unsigned integer and divides it by 16. Upper case.
 * @param p_value pointer to the integer value
 * @return character which represents the LSD
 */
char unsigned_get_lsd_HEX_and_shift(uintmax_t* p_value);

/**
 * Gets the integer part of the double as a digit and shifts it by removing that and multiplying by 10.
 * @param p_value pointer to the integer value
 * @return character which represents the whole part
 */
char double_get_dig_and_shift(double* p_value);


/**
 * Gets the integer part of the double as a digit and shifts it by removing that and multiplying by 16.
 * This does not produce rounding errors. Lower case.
 * @param p_value pointer to the integer value
 * @return character which represents the whole part
 */
char double_get_hex_and_shift(double* p_value);

/**
 * Gets the integer part of the double as a digit and shifts it by removing that and multiplying by 16.
 * This does not produce rounding errors. Upper case.
 * @param p_value pointer to the integer value
 * @return character which represents the whole part
 */
char double_get_HEX_and_shift(double* p_value);

#endif //JFMT_INTERNAL_FORMATTED_H
