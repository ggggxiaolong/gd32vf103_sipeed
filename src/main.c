/*
 * @Author: MrTan
 * @Date: 2021-05-11 14:45:23
 * @LastEditTime: 2021-05-12 17:49:26
 * @LastEditors: MrTan
 * @Description: 添加按键扫描
 * @FilePath: /gd32_sipeed/src/main.c
 */

#include "gd32vf103.h"
#include "bsp_led.h"
#include "bsp_systick.h"
#include "bsp_key.h"
#include "bsp_usart.h"
#include <stdio.h>
#include <string.h>
#include "bsp_timer.h"

int main(void)
{
    //全局中断使能
    bsp_eclic_init();
    //初始化板载led灯
    bsp_led_init();
    // 设置中断优先级
    eclic_irq_enable(TIMER1_IRQn, 1, 0);
    bsp_timer_init(TIMER1, 500);
    // bsp_led_blue_on();
    while (1)
    {
    }
}

void EXTI5_9_IRQHandler(void)
{
    if (RESET != exti_interrupt_flag_get(BSP_KEY_EXIT_LINE))
    {
        exti_interrupt_flag_clear(BSP_KEY_EXIT_LINE);
        bsp_led_red_toogle();
    }
}

void USART0_IRQHandler()
{
    uint8_t receive;
    if (RESET != usart_interrupt_flag_get(BSP_USART_USART_PORT, USART_INT_FLAG_RBNE))
    {
        // 一个读操作都可以清除RBNE位, 不需要额外的清空中断标记
        receive = usart_data_receive(BSP_USART_USART_PORT);
        usart_data_transmit(BSP_USART_USART_PORT, receive);
        switch (receive)
        {
        case 'r':
        case 'R':
            bsp_led_red_toogle();
            break;
        case 'g':
        case 'G':
            bsp_led_green_toogle();
            break;
        case 'b':
        case 'B':
            bsp_led_blue_toogle();
            break;
        default:
            break;
        }
    }
}

void TIMER1_IRQHandler(void)
{
    if(RESET != timer_interrupt_flag_get(TIMER1, TIMER_INT_FLAG_UP)){
        bsp_led_green_toogle();
        timer_interrupt_flag_clear(TIMER1, TIMER_INT_FLAG_UP);
    }
}