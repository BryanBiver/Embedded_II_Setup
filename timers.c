#include <stdint.h>

#include "stm32f446.h"                  
#include "timers.h"

void TIM6_Initialize()
{
	RCC->APB1ENR.TIM6EN = 1;		// Enable Clock for Timer 6
//	void NVIC_EnableIRQ( TIM6_DAC ); 
	NVIC->ISER1.interrupts.interrupt22 = 1;
    TIM6->ARR = 0;
	TIM6->PSC = 15999;					// Set Prescaler
	TIM6->DIER.UIE = 1;				// Enable the Update Interrupt
}

void TIM6_Start( uint32_t reload_value, bool auto_reload )
{
	TIM6->ARR = reload_value;			// Set Reload Value
    if ( auto_reload == TRUE )
    {
        TIM6->CR1.OPM = 0;
    }
    else
    {
        TIM6->CR1.OPM = 1;
    }
	TIM6->CR1.CEN = 1;				// Enable Counting
}

void TIM6_Stop()
{
	TIM6->CR1.CEN = 0;				// Disable Counting
}


void TIM3_Initialize()
{
	RCC->APB1ENR.TIM3EN = 1;		// Enable Clock for Timer 6
//	void NVIC_EnableIRQ( TIM6_DAC ); 
	NVIC->ISER0.interrupts.interrupt29 = 1;
    TIM3->ARR = 0;
	TIM3->PSC = 15999;					// Set Prescaler
	TIM3->DIER.UIE = 1;				// Enable the Update Interrupt
}

void TIM3_Start( uint32_t reload_value, bool auto_reload )
{
	TIM3->ARR = reload_value;			// Set Reload Value
    if ( auto_reload == TRUE )
    {
        TIM3->CR1.OPM = 0;
    }
    else
    {
        TIM3->CR1.OPM = 1;
    }
	TIM3->CR1.CEN = 1;				// Enable Counting
}

void TIM3_Stop()
{
	TIM3->CR1.CEN = 0;				// Disable Counting
}

