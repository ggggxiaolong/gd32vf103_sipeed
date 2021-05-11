/*
 * @Author: MrTan
 * @Date: 2021-05-11 18:06:56
 * @LastEditTime: 2021-05-11 18:17:08
 * @Description: 外置按键， 引脚PA0
 * @FilePath: /gd32_sipeed/include/bsp_key.h
 */

#ifndef __BSP_GPIO_KEY__
#define __BSP_GPIO_KEY__

#include "gd32vf103.h"

#define BSP_KEY_PORT GPIOA
#define BSP_KEY_PIN GPIO_PIN_0
#define BSP_KEY_CLK RCU_GPIOA
#define BSP_KEY_EXIT_IRQ EXTI0_IRQn
#define BSP_KEY_EXIT_LINE EXTI_0
#define BSP_KEY_SOURCE_PORT GPIO_PORT_SOURCE_GPIOA
#define BSP_KEY_SOURCE_PIN GPIO_PIN_SOURCE_0

void bsp_key_init(void);
void bsp_key_init_it(void);
#endif