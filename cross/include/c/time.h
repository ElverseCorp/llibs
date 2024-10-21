#ifndef ELLIPSE_2_TIME_H_
#define ELLIPSE_2_TIME_H_

/**************************************************************************//**
 * @file     time.h
 * @brief    Ellipse time for C language.
 * @version  V0.0.1
 * @date     20. Oct 2024
 * @author   Matvey Rybalkin
******************************************************************************/

#include "types.h"
#include "str.h"

/**
 * @brief Basic time structure (HH:MM:SS)
 */
typedef struct {
    u16_t hours          :5;  ///< Hours (0-23)
    u16_t minutes        :6;  ///< Minutes (0-59)
    u16_t seconds        :6;  ///< Seconds (0-59)
} time_t;

/**
 * @brief High precision time structure (HH:MM:SS:MS:US:NS)
 */
typedef struct {
    u16_t hours          :5;  ///< Hours (0-23)
    u16_t minutes        :6;  ///< Minutes (0-59)
    u16_t seconds        :6;  ///< Seconds (0-59)

    u16_t milliseconds   :10; ///< Milliseconds (0-999)
    u16_t microseconds   :10; ///< Microseconds (0-999)
    u16_t nanoseconds    :10; ///< Nanoseconds (0-999)
} time_hprec_t;

/////////////////////////////////////////////
/////////// Function declaration //////////// 
///////////////////////////////////////////// 

/**
 * @brief Get current time.
 * @return Current time as time_t structure.
 */
time_t time(void);

/**
 * @brief Get current system ticks for high-precision timing.
 * @return Number of ticks since the program started.
 */
umax_t ticks(void);

/**
 * @brief Compare two time_t structures and return the difference in seconds.
 * 
 * This function compares two time_t structures and returns the difference 
 * between them in seconds. If time1 is later than time2, the result will be positive. 
 * If time1 is earlier than time2, the result will be negative.
 * 
 * @param time1 First time.
 * @param time2 Second time.
 * @return Difference in seconds as a signed ssize_t value.
 */
ssize_t time_compare(time_t time1, time_t time2);

/**
 * @brief Compare two time_hprec_t structures and return the difference in nanoseconds.
 * 
 * This function compares two time_hprec_t structures and returns the difference 
 * between them in nanoseconds. If time1 is later than time2, the result will be positive. 
 * If time1 is earlier than time2, the result will be negative.
 * 
 * @param time1 First high-precision time.
 * @param time2 Second high-precision time.
 * @return Difference in nanoseconds as a signed ssize_t value.
 */
ssize_t time_hprec_compare(time_hprec_t time1, time_hprec_t time2);

/**
 * @brief Convert time_t structure to `xstr_t` string.
 * @param time Time to convert.
 * @param encode String encode.
 * @return `xstr_t` string structure.
 */
xstr_t time_to_xstr(time_t time, xstr_encode_t encode);

/**
 * @brief Convert time_t structure to string (ASCII or UTF-8).
 * @param time Time to convert.
 * @param encode String encode. 
 * @return Pointer to static string representing the time in HH:MM:SS format.
 */
void* time_to_string(time_t time);

/**
 * @brief Convert time_t structure to string.
 * @param string `xstr_t` string to convert.
 * @return `xstr_t` string structure representing the time in HH:MM:SS format..
 */
time_t time_from_xstr(xstr_t string);

/**
 * @brief Delay execution for a given number of seconds.
 * @param seconds Number of seconds to delay.
 */
void time_delay_s(len_t seconds);

/**
 * @brief Delay execution for a given number of milliseconds.
 * @param milliseconds Number of milliseconds to delay.
 */
void time_delay_ms(len_t milliseconds);

/**
 * @brief Delay execution for a given number of microseconds.
 * @param microseconds Number of microseconds to delay.
 */
void time_delay_us(len_t microseconds);

/**
 * @brief Delay execution for a given number of nanoseconds.
 * @param nanoseconds Number of nanoseconds to delay.
 */
void time_delay_ns(len_t nanoseconds);

#endif // ELLIPSE_2_TIME_H_
