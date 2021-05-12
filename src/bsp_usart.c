/*
 * @Author: MrTan
 * @Date: 2021-05-12 12:59:57
 * @LastEditTime: 2021-05-12 15:07:40
 * @LastEditors: MrTan
 * @Description: 串口
 * @FilePath: /gd32_sipeed/src/bsp_usart.c
 */

#include "gd32vf103.h"
#include "bsp_usart.h"
#include "bsp_eclic.h"

/**
 * @description: 日志串口初始化 
 */
void bsp_usart_log_init(void){
    // 使能时钟， GPIO 和 USART
    rcu_periph_clock_enable(BSP_USART_RX_RCU);
    rcu_periph_clock_enable(BSP_USART_USART_RCU);
    // 配置串口引脚功能 输出引脚：推挽输出
    gpio_init(BSP_USART_TX_PORT, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, BSP_USART_TX_PIN);        //输出引脚：推挽输出
    gpio_init(BSP_USART_RX_PORT, GPIO_MODE_IN_FLOATING, GPIO_OSPEED_50MHZ, BSP_USART_RX_PIN);   //接收引脚：输入浮空
    // 配置串口波特率，数据长度，校验，结束位
    usart_deinit(BSP_USART_USART_PORT);
    usart_baudrate_set(BSP_USART_USART_PORT, BSP_USART_BAUD);
    usart_word_length_set(BSP_USART_USART_PORT, USART_WL_8BIT);
    usart_stop_bit_set(BSP_USART_USART_PORT, USART_STB_1BIT);
    usart_parity_config(BSP_USART_USART_PORT, USART_PM_NONE);
    // 屏蔽cts rts功能
    usart_hardware_flow_rts_config(BSP_USART_USART_PORT, USART_RTS_DISABLE);
    usart_hardware_flow_cts_config(BSP_USART_USART_PORT, USART_CTS_DISABLE);
    // 串口接收使能
    usart_receive_config(BSP_USART_USART_PORT, USART_RECEIVE_ENABLE);
    // 串口发送使能
    usart_transmit_config(BSP_USART_USART_PORT, USART_TRANSMIT_ENABLE);
    //接收中断 接收到数据就中断
    usart_interrupt_enable(BSP_USART_USART_PORT, USART_INT_RBNE);
    //设置中断优先级
    eclic_irq_enable(BSP_USART_USART_IRQ, 1, 0);
    // 打开串口
    usart_enable(BSP_USART_USART_PORT);
}

//重定向 C库函数
int _put_char(int ch)
{
    usart_data_transmit(BSP_USART_USART_PORT, (uint8_t) ch );
    while ( usart_flag_get(BSP_USART_USART_PORT, USART_FLAG_TC) == RESET);
    return ch;
}