/*
 * @Author: MrTan
 * @Date: 2021-05-12 11:28:22
 * @LastEditTime: 2021-05-12 15:00:54
 * @LastEditors: MrTan
 * @Description: 串口配置 PA9 UART0_TX, PA10 UART0_RX
 * @FilePath: /gd32_sipeed/include/bsp_usart.h
 */
#ifndef BSP_USART_H
#define BSP_USART_H

#include "gd32vf103.h"
#define BSP_USART_USART_PORT USART0 //串口端口
#define BSP_USART_RX_PORT GPIOA //接收端口
#define BSP_USART_TX_PORT GPIOA //发送端口
#define BSP_USART_RX_PIN GPIO_PIN_10 //接收引脚
#define BSP_USART_TX_PIN GPIO_PIN_9 //发送引脚
#define BSP_USART_RX_RCU RCU_GPIOA  //接收时钟
#define BSP_USART_TX_RCU RCU_GPIOA  //发送时钟
#define BSP_USART_USART_RCU RCU_USART0 //串口时钟
#define BSP_USART_USART_IRQ USART0_IRQn //串口中断
#define BSP_USART_BAUD 115200U  //波特率

void bsp_usart_log_init(void);
#endif