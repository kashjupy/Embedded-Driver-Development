/*
 * stm32f407xx.h
 *
 *  Created on: Feb 17, 2024
 *      Author: karth
 */

#ifndef INC_STM32F407XXXX_H_
#define INC_STM32F407XXXX_H_

#include<stdint.h>

#define __vo__ volatile


/*base address of Flash and SRAM memories*/
#define FLASH_BASEADDR     0x08000000U  /*This is the base address of the Flash memory*/
#define SRAM1_BASEADDR     0x20000000U  /*This is the base address of the SRAM1*/
#define SRAM2_BASEADDR     0x2001C000U  /*wE HAVE 112 kb OF THE SRAM1 (112 *1024) =1C000*/
#define ROM_BASEADDR       0x1FFF0000U  /*This is the base address of the ROM*/
#define SRAM               SRAM1_BASEADDR /*This is the baseadddress of the system memory */



/*
 * AHB AND APBx Bus Peripheral base adddress
 */

#define PERIPH_BASE            0x40000000U
#define APB1PERIPH_BASEADDR    PERIPH_BASE
#define APB2PERIPH_BASEADDR    0x40010000U
#define AHB1PERIPH_BASEADDR    0x40020000U
#define AHB2PERIPH_BASEADDR    0x50000000U



/*
 * Base address of peripherals which are hanging on AHB1 BUS
 * : Complete all the other peripherals.
 */

#define GPIOA_BASEADDR   (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR   (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR   (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR   (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR   (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR   (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR   (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR   (AHB1PERIPH_BASEADDR + 0x1C00)
#define GPIOI_BASEADDR   (AHB1PERIPH_BASEADDR + 0x2000)

#define RCC_BASEADDR (AHB1PERIPH_BASEADDR + 0x3800)

/*
 * BASE ADDRESS OF PERIPHERALS WHICH ARE HANGING  ON APB1 BUS
 * : COMPLETE FOR ALL PERIPHERALS
 */

#define I2C1_BASEADDR (APB1PERIPH_BASEADDR +0x5400)
#define I2C2_BASEADDR (APB1PERIPH_BASEADDR +0x5800)
#define I2C3_BASEADDR (APB1PERIPH_BASEADDR +0x5C00)
#define SPI2_BASEADDR (APB1PERIPH_BASEADDR +0x3800)
#define SPI3_BASEADDR (APB1PERIPH_BASEADDR +0x3C00)
#define USART2_BASEADDR (APB1PERIPH_BASEADDR +0x4400)
#define USART3_BASEADDR (APB1PERIPH_BASEADDR +0x4800)
#define UART4_BASEADDR (APB1PERIPH_BASEADDR +0x4C00)
#define UART5_BASEADDR (APB1PERIPH_BASEADDR +0x5000)

/*
 * bASE ADDRESSOF TH EPERIPHERALS WHICH ARE HANGING ON APB2 bus
 *:Compete all the peripherals which is hanging on APB2 bus
 */

#define EXTI_BASEADDR (APB2PERIPH_BASEADDR +0x3C00)
#define SPI1_BASEADDR (APB2PERIPH_BASEADDR +0x3000)
#define USART1_BASEADDR (APB2PERIPH_BASEADDR +0x1000)
#define USART6_BASEADDR (APB2PERIPH_BASEADDR +0x1400)
#define SYSCFG_BASEADDR (APB2PERIPH_BASEADDR +0x3800)



/*
 * Peripheral register definition structures
 * Note: Registers of a peripheral are specific to MCU
 */

typedef struct
{
	__vo__ uint32_t MODE;      /*GPIO port mode register*/
	__vo__ uint32_t OTYPER;    /*GPIO port output type register*/
	__vo__ uint32_t OSPEEDR;   /*GPIO port output speed register*/
	__vo__ uint32_t PUPDR;     /*GPIO port pull-up/pull-down register*/
	__vo__ uint32_t IDR;       /*GPIO port input data register*/
	__vo__ uint32_t ODR;      /*GPIO port output data register*/
	__vo__ uint32_t BSRR;     /*GPIO port bit set/reset register*/
	__vo__ uint32_t LCKR;     /*GPIO port configuration lock register*/
	__vo__ uint32_t AFR[2]; /*   GPIO alternate function low register .This AFR[2] is beacsue in reference manual we have two AFR register low and High.*/

}GPIO_RegDef_t;

typedef struct
{
	__vo__ uint32_t CR;      /* Address offset:   0x00  */
	__vo__ uint32_t PLLCFGR; /* Address offset:   0x04   */
	__vo__ uint32_t CFGR;    /* Address offset:   0x08   */
	__vo__ uint32_t CIR;    /*  Address offset:    0x0C  */
	__vo__ uint32_t AHB1RSTR; /* Address offset:  0x10    */
	__vo__ uint32_t AHB2RSTR; /* Address offset:    0x14  */
	__vo__ uint32_t AHB3RSTR; /* Address offset:   0x18   */
     uint32_t  Reserved; /*Address offset:    0x1C   */
     __vo__ uint32_t APB1RSTR;  /* Address offset:  0x20    */
     __vo__ uint32_t APB2RSTR;  /* Address offset:  0x24    */
	 uint32_t Reserved1[2]; /* Address offset: 0x28 and 0x2C    */
	 __vo__ uint32_t AHB1ENR;  /* Address offset:  0x30  */
	 __vo__ uint32_t AHB2ENR;  /*Address offset:  0x34   */
	 __vo__ uint32_t AHB3ENR;  /* Address offset:  0x38   */
	 uint32_t Reserved2; /* Address offset:  0x3C   */
	 __vo__ uint32_t APB1ENR;    /* Address offset: 0x40    */
	 __vo__ uint32_t APB2ENR;     /*   Address offset:  0x44 */
	 uint32_t Reserved3[2];      /*   Address offset:  0x48 0x4C*/
	 __vo__ uint32_t AHB1LPENR;     /*Address offset:  0x50    */
	 __vo__ uint32_t AHB2LPENR;   /*  Address offset: 0x54  */
	 __vo__ uint32_t AHB3LPENR;    /*  Address offset:  0x58  */
	 __vo__ uint32_t Reserved4;       /* Address offset: 0x5C    */
	 __vo__ uint32_t APB1LPENR;     /* Address offset:  0x60   */
	 __vo__ uint32_t APB2LPENR;   /*  Address offset: 0x64  */
	 uint32_t Reserved5[2];    /*    Address offset:0x68 0x6C  */
	 __vo__ uint32_t BDCR;         /*   Address offset: 0x70*/
	 __vo__ uint32_t CSR;      /*    Address offset: 0x74 */
	 uint32_t Reserved6[2];  /*  Address offset:   0x78 0x7C */
	 __vo__ uint32_t SSCGR;     /*   Address offset: 0x80    */
	 __vo__ uint32_t PLLI2SCFGR;  /* Address offset:    0x84 */
}RCC_RegDef_t;

/*
 * Peripheral definition (Peripheral base addresses typecasted to xxx_Regdef_t)
 */
#define GPIOA  ((GPIO_RegDef_t *)GPIOA_BASEADDR)
#define GPIOB  ((GPIO_RegDef_t *)GPIOB_BASEADDR)
#define GPIOC ((GPIO_RegDef_t *)GPIOC_BASEADDR)
#define GPIOD  ((GPIO_RegDef_t *)GPIOD_BASEADDR)
#define GPIOE  ((GPIO_RegDef_t *)GPIOE_BASEADDR)
#define GPIOF  ((GPIO_RegDef_t *)GPIOF_BASEADDR)
#define GPIOG ((GPIO_RegDef_t *)GPIOG_BASEADDR)
#define GPIOH  ((GPIO_RegDef_t *)GPIOH_BASEADDR)
#define GPIOI  ((GPIO_RegDef_t *)GPIOI_BASEADDR)
/*
 * Defining the RCC macro with its offise and it is Presentnt int he AHB1 BUS in the architecturte
 */
#define RCC  ((RCC_RegDef_t*)RCC_BASEADDR )

/*
 * clock enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |=(1<<0))
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |=(1<<1))
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |=(1<<2))
#define GPIOD_PCLK_EN()     (RCC->AHB1ENR |=(1<<3))
#define GPIOE_PCLK_EN()     (RCC->AHB1ENR |=(1<<4))
#define GPIOF_PCLK_EN()     (RCC->AHB1ENR |=(1<<5))
#define GPIOG_PCLK_EN()     (RCC->AHB1ENR |=(1<<6))
#define GPIOH_PCLK_EN()     (RCC->AHB1ENR |=(1<<7))
#define GPIOI_PCLK_EN()     (RCC->AHB1ENR |=(1<<8))

/*
 *Clock Enable Macros for I2Cx peripherals
 */
#define I2C1_PCLK_EN()     ((RCC->APB1ENR |= (1<<21))
#define I2C2_PCLK_EN()     ((RCC->APB1ENR |= (1<<22))
#define I2C3_PCLK_EN()     ((RCC->APB1ENR |= (1<<23))


/*
 * cLOCK eNABLE MACROS FOR THE SPI
 */
#define SPI1_PCLK_EN()     ((RCC->APB2ENR |= (1<<12))
#define SPI2_PCLK_EN()     ((RCC->APB1ENR |= (1<<14))
#define SPI3_PCLK_EN()     ((RCC->APB1ENR |= (1<<15))


/*
 * Clock  Enable macros for USARTx peripherals
 */
#define USART1_PCLK_EN()  ((RCC->APB2ENR |= (1<<4))
#define USART2_PCLK_EN()  ((RCC->APB1ENR |= (1<<17))
#define USART3_PCLK_EN()  ((RCC->APB1ENR |= (1<<18))
#define USART4_PCLK_EN()  ((RCC->APB1ENR |= (1<<19))
#define USART5_PCLK_EN()  ((RCC->APB1ENR |= (1<<20))
#define USART6_PCLK_EN()  ((RCC->APB2ENR |= (1<<5))

/*
 * Clock enable for SYSCFG peripherals
 */
#define SYSCFG_PCLK_EN()  ((RCC->APB2ENR |= (1<<14))



/*Disable or reset pins config which as enabled above)
 */

/*
 * clock Disablee Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()     (RCC->AHB1ENR &=~(1<<0))
#define GPIOB_PCLK_DI()     (RCC->AHB1ENR &=~(1<<1))
#define GPIOC_PCLK_DI()     (RCC->AHB1ENR &=~(1<<2))
#define GPIOD_PCLK_DI()     (RCC->AHB1ENR &=~(1<<3))
#define GPIOE_PCLK_DI()     (RCC->AHB1ENR &=~(1<<4))
#define GPIOF_PCLK_DI()     (RCC->AHB1ENR &=~(1<<5))
#define GPIOG_PCLK_DI()     (RCC->AHB1ENR &=~(1<<6))
#define GPIOH_PCLK_DI()     (RCC->AHB1ENR &=~(1<<7))
#define GPIOI_PCLK_DI()     (RCC->AHB1ENR &=~(1<<8))

/*
 *ClockDisablee Macros for I2Cx peripherals
 */
#define I2C1_PCLK_DI()     ((RCC->APB1ENR &=~ (1<<21))
#define I2C2_PCLK_DI()     ((RCC->APB1ENR &=~ (1<<22))
#define I2C3_PCLK_DI()     ((RCC->APB1ENR &=~ (1<<23))


/*
 * cLOCK Disable MACROS FOR THE SPI
 */
#define SPI1_PCLK_DI()     ((RCC->APB2ENR &=~ (1<<12))
#define SPI2_PCLK_DI()     ((RCC->APB1ENR &=~ (1<<14))
#define SPI3_PCLK_DI()     ((RCC->APB1ENR &=~ (1<<15))


/*
 * Clock Disable macros for USARTx peripherals
 */
#define USART1_PCLK_DI()  ((RCC->APB2ENR &=~ (1<<4))
#define USART2_PCLK_DI()  ((RCC->APB1ENR &=~ (1<<17))
#define USART3_PCLK_DI()  ((RCC->APB1ENR &=~ (1<<18))
#define USART4_PCLK_DI()  ((RCC->APB1ENR &=~ (1<<19))
#define USART5_PCLK_DI()  ((RCC->APB1ENR &=~ (1<<20))
#define USART6_PCLK_DI()  ((RCC->APB2ENR &=~ (1<<5))

/*
 * Clock Disable for SYSCFG peripherals
 */
#define SYSCFG_PCLK_DI()  ((RCC->APB2ENR &=~ (1<<14))







//Some Generic Macros//

#define ENABLE   1
#define DISABLE 0
#define SET     ENABLE
#define RESET   DISABLE
#define GPIO_PIN_SET   SET
#define GPIO_PIN_RESET  RESET

#endif  INC_STM32F407XXXX_H_
