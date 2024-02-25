/*
 * stm32f407xx_gpio_driver.h
 *
 *  Created on: Feb 24, 2024
 *      Author: karth
 */

#ifndef INC_STM32F407XX_GPIO_DRIVER_H_
#define INC_STM32F407XX_GPIO_DRIVER_H_

#include"stm32f407xxxx.h"

typedef struct
{

	uint8_t GPIO_PinNumber;
	uint8_t GPIO_PinMode; //pOSSIBLE  @gpio_pin_modes
	uint8_t GPIO_PinSpeed;
	uint8_t GPIO_PinPuPdControl;
	uint8_t GPIO_Pin0PType;
	uint8_t GPIO_PinAltFunMode;
}GPIO_PinConfig_t;
/*
 * This is the Handle structure for a GPIO pin
 */

typedef struct
{
	//pointer to hold the base address of the GPIO peripheral//
	GPIO_RegDef_t *pGPIOx; // This holds the base address of the GPIO port to which the pin belongs > //
	GPIO_PinConfig_t GPIO_PinConfig;//This holds GPIO pin configuration settings //


}GPIO_Handle_t;


/*
 * gpio_pin_modes
 * GPIO pin possible modes
 *
 *
 */


#define  GPIO_PIN_NO_0 0
#define  GPIO_PIN_NO_1 1
#define  GPIO_PIN_NO_2 2
#define  GPIO_PIN_NO_3 3
#define  GPIO_PIN_NO_4 4
#define  GPIO_PIN_NO_5 5
#define  GPIO_PIN_NO_6 6
#define  GPIO_PIN_NO_7 7
#define  GPIO_PIN_NO_8 8
#define  GPIO_PIN_NO_9 9
#define  GPIO_PIN_NO_10 10
#define  GPIO_PIN_NO_11 11
#define  GPIO_PIN_NO_12 12
#define  GPIO_PIN_NO_13 13
#define  GPIO_PIN_NO_14 14
#define  GPIO_PIN_NO_15 15



































#define GPIO_MODE_IN     0
#define GPIO_MODE_OUT    1
#define GPIO_MODE_ALFN   2
#define GPIO_MODE_ANALOG 3
#define GPIO_MODE_IT_FT  4  //iNETRRUPT FALLING EDGE//
#define GPIO_MODE_IT_RT  5  // rISING EDGE//
#define GPIO_MODE_IT_RFT 6  //rISING FALLING EDGE//

/*
 * GPIO pin possible output types
 */
#define GPIO_OP_TYPE_PP  0
#define GPIO_OP_TYOE_OD  1

/*
 * GPIO pin possible  OUTPUT SPEED REGISTER types
 */
#define GPIO_SPEED_LOW    0
#define GPIO_SPEED_MEDIUM 1
#define GPIO_SPEED_FAST   2
#define GPIO_SPEED_HIGH   3

/*
 * GPIO pin possible PULL UP AND PULL DOWN configuration macros
 */

#define GPIO_NO_PUPD   0
#define GPIO_PIN_PU        1
#define GPIO_PIN_PD        2




#endif /* INC_STM32F407XX_GPIO_DRIVER_H_ */
