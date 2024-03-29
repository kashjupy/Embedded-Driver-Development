/*
 * stm32f407xx_gpio_driver.c
 *
 *  Created on: Feb 24, 2024
 *      Author: karth
 */


#include"stm32f407xx_gpio_driver.h"


/**********************************************************

   Creating API for GPIOs to contact
**********************************************************/
#include "stm32f407xx_gpio_driver.h"


/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */


//GPIO APIS Geneartion for the Clock

void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx,uint8_t EnorDi)/////EnorDi means Enable or Disable
{

	if(EnorDi == ENABLE )
	{
		if(pGPIOx ==GPIOA)
		{
			GPIOA_PCLK_EN();
		}else if (pGPIOx ==GPIOB)
		{
			GPIOB_PCLK_EN();
		}else if (pGPIOx ==GPIOC)
		{
			GPIOC_PCLK_EN();
		}else if (pGPIOx ==GPIOD)
		{
			GPIOD_PCLK_EN();
		}else if (pGPIOx ==GPIOE)
		{
			GPIOE_PCLK_EN();
		}else if (pGPIOx == GPIOF)
		{
			GPIOF_PCLK_EN();
		}else if (pGPIOx == GPIOG)
		{
			GPIOG_PCLK_EN();
		}else if (pGPIOx ==GPIOH)
		{
			GPIOH_PCLK_EN();
		}else if (pGPIOx ==GPIOI)
		{
			GPIOI_PCLK_EN();
		}
	}
	else
	{
		if(pGPIOx ==GPIOA)
				{
					GPIOA_PCLK_DI();
				}else if (pGPIOx ==GPIOB)
				{
					GPIOB_PCLK_DI();
				}else if (pGPIOx ==GPIOC)
				{
					GPIOC_PCLK_DI();
				}else if (pGPIOx ==GPIOD)
				{
					GPIOD_PCLK_DI();
				}else if (pGPIOx ==GPIOE)
				{
					GPIOE_PCLK_DI();
				}else if (pGPIOx == GPIOF)
				{
					GPIOF_PCLK_DI();
				}else if (pGPIOx == GPIOG)
				{
					GPIOG_PCLK_DI();
				}else if (pGPIOx ==GPIOH)
				{
					GPIOH_PCLK_DI();
				}else if (pGPIOx ==GPIOI)
				{
					GPIOI_PCLK_DI();
				}
	}
}


/*********************************************************************
 * @fn      		  - GPIO_PeriClockControl
 *
 * @brief             - This function enables or disables peripheral clock for the given GPIO port
 *
 * @param[in]         - base address of the gpio peripheral
 * @param[in]         - ENABLE or DISABLE macros
 * @param[in]         -
 *
 * @return            -  none
 *
 * @Note              -  none

 */


// This is for creating API for GPIO init and deinitialization

/*
 * GPIO initialization and deinitilization Macros
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle);
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx);












/*
 * Data read and write
 */

 uint8_t void GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);
 uint16_t void GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx);
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber,uint8_t Value);
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx,uint16_t Value);
void GPIO_ToggleOutptPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber);


/*
 * apis FOR INTERRUPT AND INTERRUPT hANdling
 */


void GPIO_IRQConfig(uint8_t IRQNumber , uint8_t IRQPriority, uint8_t EnorDi);
void GPIO_IRQHandling(uint8_t PinNumber);
