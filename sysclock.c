#include <stdio.h>

#include "stm32f446.h"
#include "sysclock.h"

uint32_t clock_tick;								// Variable to hold the system tick


void SysTick_handler( void )
{
	clock_tick++;
}


void Delay( uint32_t delay )
{
	uint32_t	start_tick = clock_tick;			// Start Time
	
	while (( clock_tick - start_tick ) < delay );	// Blocking loop waiting for delay to expire
}


void SysTickConfigure( void )
{
	SYSTICK->STK_LOAD.RELOAD = 16000;
	SYSTICK->STK_VAL.CURRENT = 15999;
	SYSTICK->STK_CTRL.CLKSOURCE = 1;           // Use Processor Clock (AHB)
	SYSTICK->STK_CTRL.TICKINT = 1;             // Trigger Interrupt when counter hits 0
	SYSTICK->STK_CTRL.ENABLE = 1;               // Enable the System Tick Timer
}


void SysClockConfigure( void )
{
    RCC->APB2ENR.SYSCFGEN = 1;                // Enable the System Clock

	// Configure RCC Clock Control Register
    RCC->CR.HSION = 1;                              // Enable the Clock Source
    while (( RCC->CR.HSIRDY ) == 0 );                // Wait for Clock Source to become Ready
	
	// Configure RCC Clock Configuration Register
    RCC->CFGR.PPRE1 = 0;
    RCC->CFGR.PPRE2 = 0;
    RCC->CFGR.HPRE = 0;
    
	// Make sure the Clock is Running
    RCC->CFGR.SW = 1;                           // Configure the Clock Source
    while ( RCC->CFGR.SWS != 1 );               // Wait for the Clock Source
}

