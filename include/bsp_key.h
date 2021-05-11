/*
 * @Author: MrTan
 * @Date: 2021-05-11 18:06:56
 * @LastEditTime: 2021-05-11 18:17:08
 * @Description: 外置按键， 引脚PB9
 * @FilePath: /gd32_sipeed/include/bsp_key.h
 */

#ifndef __BSP_GPIO_KEY__
#define __BSP_GPIO_KEY__

#include "gd32vf103.h"

#define BSP_KEY_PORT GPIOB
#define BSP_KEY_PIN GPIO_PIN_9

void bsp_key_init(void);
void bsp_key_init_it(void);
#endif