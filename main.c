// Main program //

#include <stdio.h>
 
#include "main.h"
#include "sysclock.h"
#include "timers.h"


// External Button on Pin C3
// used as second button to double flash EXTERNAL LED
void EXTI3_IRQ_handler(void)
{
	// ensure single flash and double flash are set to 1
	doubleFlash = 1;
	singleFlash = 0;
	// reset leds to flash at same time
	GPIOA->ODR.pins.pin5 = 0;
	GPIOB->ODR.pins.pin5 = 0;
	// clear the interrupt
	EXTI->PR.pins.pin3 = 1;
}

// External Button on Pin B4
// used as first button to single flash EXTERNAL LED
void EXTI4_IRQ_handler(void)
{
	singleFlash = 1;
	doubleFlash = 0;
	//reset leds to flash at same time
	GPIOA->ODR.pins.pin5 = 0;
	GPIOB->ODR.pins.pin5 = 0;
	// clear the interrupt
	EXTI->PR.pins.pin4 = 1;
}

// Internal Button Interrupt Handler Pin C13
// Used to turn off external LED
void EXTI15_10_IRQ_handler(void)
{
	// set single and double flash to 0 to turn off EXTERNAL LED
	singleFlash = 0;
	doubleFlash = 0;
	//reset leds
	GPIOA->ODR.pins.pin5 = 0;
	GPIOB->ODR.pins.pin5 = 0;
	// clear the interrupt
	EXTI->PR.pins.pin13 = 1;
}

// Working
void TIM3_DAC(void) {

	halftimeToggle = 1;
	// Clear TIM3
	TIM3->SR.UIF = 0;

}

// Working
void TIM6_DAC(void) {

	fulltimeToggle = 1;
	// Clear TIM6
	TIM6->SR.UIF = 0;

}

int main(void) 
{
	
	/* Enable GPIO Port A */ 
	RCC->AHB1ENR.GPIOAEN = 1; 
	/* Enable GPIO Port B */ 
	RCC->AHB1ENR.GPIOBEN = 1; 
	/* Enable GPIO Port C */ 
	RCC->AHB1ENR.GPIOCEN = 1; 
	/* Enable SYSCFG */
	RCC->APB2ENR.SYSCFGEN = 1;

	// Configure the SysTick to operate at 1 mS
	SysTickConfigure();

	// Turn OFF INTERNAL_LED
	GPIOA->ODR.pins.pin5 = 0;

	// Initialize TIM6
	TIM6_Initialize();
	TIM6_Start( 2999 , TRUE );
	
	// Initialize TIM3
	TIM3_Initialize();
	TIM3_Start( 1499 , TRUE );

	/* INTERNAL LED Setup (Pin A5) */
	GPIOA->MODER.pins.pin5 = 1;
	GPIOA->OTYPER.pins.pin5 = 0;
	GPIOA->PUPDR.pins.pin5 = 0;
	GPIOA->OSPEEDR.pins.pin5 = 0;

	/* EXTERNAL LED Setup (Pin B5) */
	GPIOB->MODER.pins.pin5 = 1;
	GPIOB->OTYPER.pins.pin5 = 0;
	GPIOB->PUPDR.pins.pin5 = 0;
	GPIOB->OSPEEDR.pins.pin5 = 0;

	/* EXTERNAL Button Setup (Pin C3) */
	// GPIO Port Mode register 
	GPIOC->MODER.pins.pin3 = 0;
	// GPIO port output type register
	GPIOC->OTYPER.pins.pin3 = 0;
	// GPIO port output speed
	GPIOC->OSPEEDR.pins.pin3 = 0;
	// GPIO port pull-up/pull-down
	GPIOC->PUPDR.pins.pin3 = 2;

	/* EXTERNAL Button Setup (Pin B4) */
	// GPIO Port Mode register 
	GPIOB->MODER.pins.pin4 = 0;
	// GPIO port output type register
	GPIOB->OTYPER.pins.pin4 = 0;
	// GPIO port output speed
	GPIOB->OSPEEDR.pins.pin4 = 0;
	// GPIO port pull-up/pull-down
	GPIOB->PUPDR.pins.pin4 = 2;

	/* INTERNAL Button Setup (Pin C13) */
	// GPIO Port Mode register 
	GPIOC->MODER.pins.pin13 = 0;
	// GPIO port output type register
	GPIOC->OTYPER.pins.pin13 = 0;
	// GPIO port output speed
	GPIOC->OSPEEDR.pins.pin13 = 0;
	// GPIO port pull-up/pull-down
	GPIOC->PUPDR.pins.pin13 = 2;
	
	/* 3_IRQ Interrupt Setup */
	// Enable external interrupt (Pin C3)
	SYSCFG->EXTICR1.pins.pin3 = 2;
	// Unmask external interrupt (Pin C3)
	EXTI->IMR.pins.pin3 = 1;
	// Disable rising trigger (Pin C3)
	EXTI->RTSR.pins.pin3 = 0;
	// Enable falling trigger (Pin C3)
	EXTI->FTSR.pins.pin3 = 1;
	// Interrupt enable (Pin C3)
	NVIC->ISER0.interrupts.interrupt9 = 1;

	/* 4_IRQ Interrupt Setup */
	// Enable external interrupt (Pin B4)
	SYSCFG->EXTICR2.pins.pin0 = 1;
	// Unmask external interrupt (Pin B4)
	EXTI->IMR.pins.pin4 = 1;
	// Disable rising trigger (Pin B4)
	EXTI->RTSR.pins.pin4 = 0;
	// Enable falling trigger (Pin B4)
	EXTI->FTSR.pins.pin4 = 1;
	// Interrupt enable (Pin B4)
	NVIC->ISER0.interrupts.interrupt10 = 1;

	/* 15_10_IRQ Interrupt Setup */
	// Enable external interrupt (Pin C13)
	SYSCFG->EXTICR4.pins.pin1 = 2;
	// Unmask external interrupt (Pin C13)
	EXTI->IMR.pins.pin13 = 1;
	// Disable rising trigger (Pin C13)
	EXTI->RTSR.pins.pin13 = 0;
	// Enable falling trigger (Pin C13)
	EXTI->FTSR.pins.pin13 = 1;
	// Interrupt enable (Pin C13)
	NVIC->ISER1.interrupts.interrupt8 = 1;

	

	while (1)
	{

		// EXTERNAL halftime TOGGLE LOGIC
		if ( halftimeToggle == 1)
		{
			if ( doubleFlash == 1 )
			{
				if ( GPIOB->IDR.pins.pin5 == 0 )
				{
					GPIOB->ODR.pins.pin5 = 1;
				}	
				else
				{
					GPIOB->ODR.pins.pin5 = 0;
				}
			}
			halftimeToggle = 0;
		}

		// EXTERNAL fulltime TOGGLE LOGIC
		if ( fulltimeToggle == 1 )
		{
			if ( singleFlash == 1 )
			{
				if ( GPIOA->IDR.pins.pin5 == 0 )
				{
					GPIOA->ODR.pins.pin5 = 1;
					GPIOB->ODR.pins.pin5 = 1;
				}	
				else
				{
					GPIOA->ODR.pins.pin5 = 0;
					GPIOB->ODR.pins.pin5 = 0;
				}
			}
			else
			{
				if ( GPIOA->IDR.pins.pin5 == 0 )
				{
					GPIOA->ODR.pins.pin5 = 1;
				}	
				else
				{
					GPIOA->ODR.pins.pin5 = 0;
				}
			}
			fulltimeToggle = 0;
		}
	}
}
