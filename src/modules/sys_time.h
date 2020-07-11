/**
 * @file		sys_time.h
 * @author		Andrew Loebs
 * @brief		Header file of the sys time module
 * 
 * Exposes a millisecond time to the system (driven by systick) and provides
 * functions for comparing times (with wrap-around) and blocking delays.
 * 	
 */

#ifndef __SYS_TIME_H
#define __SYS_TIME_H

#include <stdint.h>
#include <stdbool.h>

/// @brief Resets the system time and enables sys tick interrupt
void sys_time_init(void);

/// @brief Increments the system time counter -- should only be called by interrupt!
void _sys_time_increment(void);

/// @brief Returns system time counter (which tracks milliseconds)
uint32_t sys_time_get_ms(void);

/// @brief Checks whether a given time duration has elapsed since a given start time
bool sys_time_is_elapsed(uint32_t start, uint32_t duration_ms);

/// @brief Blocking delay for a given duration
void sys_time_delay(uint32_t duration_ms);

#endif // __SYS_TIME_H