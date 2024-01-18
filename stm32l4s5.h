#ifndef _STM32L4S5_H_
#define _STM32L4S5_H_

#ifdef __cplusplus
    extern "C" {
#endif

// Included header files
// #include "blahblah"
#include "stm32l4s5_exti.h"
#include "stm32l4s5_gpio.h"

/* Microcontroller Base Addresses */
#define FLASH_BASE                  ((uint32_t)0xblahU)
#define SRAM_BASE                   ((uint32_t)0xblahU)

/*!< AHB1 Peripherals */
#define RCC_REGISTER                ((uint32_t)0x40021000U)
#define EXTI_REGISTER               ((uint32_t)0x40010400U)
#define GPIOA_REGISTER              ((uint32_t)0x48000000U)
#define GPIOB_REGISTER              ((uint32_t)0x48000400U)
#define GPIOC_REGISTER              ((uint32_t)0x48000800U)
#define GPIOD_REGISTER              ((uint32_t)0x48000C00U)
#define GPIOE_REGISTER              ((uint32_t)0x48001000U)
#define GPIOF_REGISTER              ((uint32_t)0x48001400U)
#define GPIOG_REGISTER              ((uint32_t)0x48001800U)
#define GPIOH_REGISTER              ((uint32_t)0x48001C00U)
#define GPIOI_REGISTER              ((uint32_t)0x48002000U)

/*!< Register Memory Maps */
#define RCC                         ((RCC_TypeDef *)RCC_REGISTER)
#define EXTI                         ((EXTI_TypeDef *)EXTI_REGISTER)
#define GPIOA                       ((GPIO_TypeDef *)GPIOA_REGISTER)
#define GPIOB                       ((GPIO_TypeDef *)GPIOB_REGISTER)
#define GPIOC                       ((GPIO_TypeDef *)GPIOC_REGISTER)
#define GPIOD                       ((GPIO_TypeDef *)GPIOD_REGISTER)
#define GPIOE                       ((GPIO_TypeDef *)GPIOE_REGISTER)
#define GPIOF                       ((GPIO_TypeDef *)GPIOF_REGISTER)
#define GPIOG                       ((GPIO_TypeDef *)GPIOG_REGISTER)
#define GPIOH                       ((GPIO_TypeDef *)GPIOH_REGISTER)
#define GPIOI                       ((GPIO_TypeDef *)GPIOI_REGISTER)

/* RCC TypeDef */
typedef struct
{
    volatile uint32_t CR;
    volatile uint32_t ICSCR;
    volatile uint32_t CFGR;
    volatile uint32_t PLLCFGR;
    volatile uint32_t PLLSAI1CFGR;
    volatile uint32_t PLLSAI2CFGR;
    volatile uint32_t CIER;
    volatile uint32_t CIFR;
    volatile uint32_t CICR;
    volatile uint32_t AHB1RSTR;
    volatile uint32_t AHB2RSTR;
    volatile uint32_t AHB3RSTR;
    volatile uint32_t APB1RSTR1;
    volatile uint32_t APB1RSTR2;
    volatile uint32_t APB2RSTR;
    volatile uint32_t AHB1ENR;
    volatile uint32_t AHB2ENR;
    volatile uint32_t AHB3ENR;
    volatile uint32_t APB1ENR1;
    volatile uint32_t APB1ENR2;
    volatile uint32_t APB2ENR;
    volatile uint32_t AHB1SMENR;
    volatile uint32_t AHB2SMENR;
    volatile uint32_t AHB3SMENR;
    volatile uint32_t APB1SMENR1;
    volatile uint32_t APB1SMENR2;
    volatile uint32_t APB2SMENR;
    volatile uint32_t CCIPR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t CRRCR;
    volatile uint32_t CCIPR2;
    volatile uint32_t DLYCFGR;    
} RCC_TypeDef;

/* EXTI TypeDef */
typedef struct 
{
    volatile EXTI_x_TypeDef IMR1;
    volatile EXTI_x_TypeDef EMR1;
    volatile EXTI_x_TypeDef RTSR1;
    volatile EXTI_x_TypeDef FTSR1;
    volatile EXTI_x_TypeDef SWIER1;
    volatile EXTI_x_TypeDef PR1;
    volatile EXTI_x_TypeDef IMR2;
    volatile EXTI_x_TypeDef EMR2;
    volatile EXTI_x_TypeDef RTSR2;
    volatile EXTI_x_TypeDef FTSR2;
    volatile EXTI_x_TypeDef SWIER2;
    volatile EXTI_x_TypeDef PR2;
} EXTI_TypeDef;

/* GPIO TypeDef */
typedef struct 
{
    volatile GPIOx_2_TypeDef MODER;       		/*!< GPIO Port Mode Register,                   Address offset: 0x00 */
    volatile GPIOx_16_TypeDef OTYPER;			/*!< GPIO Port Output Type Register,            Address offset: 0x04 */ 
	volatile GPIOx_2_TypeDef OSPEEDR;			/*!< GPIO Port Output Speed Register,           Address offset: 0x08 */ 
	volatile GPIOx_2_TypeDef PUPDR;				/*!< GPIO Port Pull-Up/Pull-Down Register,      Address offset: 0x0C */
    volatile GPIOx_16_TypeDef IDR;					/*!< GPIO Port Input Data Register,             Address offset: 0x10 */
    volatile GPIOx_16_TypeDef ODR;					/*!< GPIO Port Output Data Register,            Address offset: 0x14 */
    volatile uint32_t BSRR;							/*!< GPIO Port Bit Set/Reset Register,          Address offset: 0x18 */
    volatile GPIOx_17_TypeDef LCKR;							/*!< GPIO Port Configuration Lock Register,     Address offset: 0x1C */
    volatile GPIOx_2_TypeDef AFRL;							/*!< GPIO Alternate Function Low Register,      Address offset: 0x20 */
	volatile GPIOx_2_TypeDef AFRH;							/*!< GPIO Alternate Function High Register,     Address offset: 0x24 */
    volatile GPIOx_16_TypeDef BRR;                          /*!< GPIO */
} GPIO_TypeDef;


#endif