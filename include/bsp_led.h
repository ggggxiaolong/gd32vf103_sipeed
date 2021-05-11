/*
 * @Author: MrTan
 * @Date: 2021-05-11 10:25:21
 * @LastEditTime: 2021-05-11 14:46:34
 * @LastEditors: Please set LastEditors
 * @Description: 龙眼开发板LED板级支持包
 * @FilePath: /gd32vf103/include/bsp_led.h
 */

#ifndef __BSP_GPIO_LED__
#define __BSP_GPIO_LED__

#include "gd32vf103.h"

#define BSP_LED_RED_PORT GPIOC
#define BSP_LED_RED_PIN GPIO_PIN_13
#define BSP_LED_GREEN_PORT GPIOA
#define BSP_LED_GREEN_PIN GPIO_PIN_1
#define BSP_LED_BLUE_PORT GPIOA
#define BSP_LED_BLUE_PIN GPIO_PIN_2

/**
 * @description: 初始化LED灯
 */
void bsp_led_init(void);
void bsp_led_red_on(void);
void bsp_led_red_off(void);
void bsp_led_red_toogle(void);

void bsp_led_green_on(void);
void bsp_led_green_off(void);
void bsp_led_green_toogle(void);

void bsp_led_blue_on(void);
void bsp_led_blue_off(void);
void bsp_led_blue_toogle(void);
#endif