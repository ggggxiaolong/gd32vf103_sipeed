/*
 * @Author: your name
 * @Date: 2021-05-11 14:45:23
 * @LastEditTime: 2021-05-11 16:13:41
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: /gd32vf103/home/mrtan/Documents/PlatformIO/Projects/gd32_sipeed/src/main.c
 */

#include "gd32vf103.h"
#include "bsp_led.h"
#include "bsp_systick.h"

int main(void)
{
    //初始化板载led灯
    bsp_led_init();

    while (1)
    {
        delay_1ms(500);
        bsp_led_red_toogle();
        bsp_led_blue_off();
        bsp_led_red_on();
        delay_1ms(500);
        bsp_led_red_off();
        bsp_led_green_on();
        delay_1ms(500);
        bsp_led_green_off();
        bsp_led_blue_on();
    }
}