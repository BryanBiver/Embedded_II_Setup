#ifndef _TIMERS_H_
#define _TIMERS_H_

#include "main.h"

void TIM6_Initialize();
void TIM6_Start( uint32_t reload_value, bool auto_reload );
void TIM6_Stop();

void TIM3_Initialize();
void TIM3_Start( uint32_t reload_value, bool auto_reload );
void TIM3_Stop();

#endif  // _TIMERS_H_
