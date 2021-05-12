/*
 * @Author: MrTan
 * @Date: 2021-05-12 09:15:25
 * @LastEditTime: 2021-05-12 15:16:23
 * @LastEditors: MrTan
 * @Description: 添加按键配置，和中断配置，及按键检测
 * @FilePath: /gd32_sipeed/src/bsp_key.c
 */
#include "bsp_key.h"
#include "bsp_eclic.h"
//外置按键， 引脚PB9
void bsp_key_init(void)
{
    //使能key时钟
    rcu_periph_clock_enable(BSP_KEY_CLK);
    rcu_periph_clock_enable(RCU_AF);
    //配置key输入模式
    gpio_init(BSP_KEY_PORT, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, BSP_KEY_PIN);
}

void bsp_key_init_it(void)
{
    //使能key时钟
    rcu_periph_clock_enable(BSP_KEY_CLK);
    rcu_periph_clock_enable(RCU_AF);
    //配置key输入模式
    gpio_init(BSP_KEY_PORT, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, BSP_KEY_PIN);
    //设置中断优先级
    eclic_irq_enable(BSP_KEY_EXIT_IRQ, 1, 0);
    //配置key中断
    gpio_exti_source_select(BSP_KEY_SOURCE_PORT, BSP_KEY_SOURCE_PIN);
    //中断使能
    exti_init(BSP_KEY_EXIT_LINE, EXTI_INTERRUPT, EXTI_TRIG_RISING);
    //清空中断标志
    exti_interrupt_flag_clear(BSP_KEY_EXIT_LINE);
}

/**
 * @description: 检测按键是否被按下
 * @param {*}
 * @return {*}
 */
FlagStatus bsp_key_is_pressed(void)
{
    if(RESET != gpio_input_bit_get(BSP_KEY_PORT, BSP_KEY_PIN)){
        while (RESET != gpio_input_bit_get(BSP_KEY_PORT, BSP_KEY_PIN));
        return SET;
    }
    return RESET;
}