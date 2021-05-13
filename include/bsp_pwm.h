/*
 * @Author: MrTan
 * @Date: 2021-05-13 13:56:50
 * @LastEditTime: 2021-05-13 18:42:06
 * @LastEditors: MrTan
 * @Description: Timer pwm输出
 * @FilePath: /gd32_sipeed/include/bsp_pwm.h
 */
#ifndef TEST_PWM_H
#define TEST_PWM_H

#include <stdint.h>

/**
 * @description: 定时器1初始化
 *               定时器1通道对应的引脚关系：chx -> PAx
 * @param {uint16_t} channel: TIMER_CH_x(x=0..4)
 * @return none
 */
void bsp_pwm_timer1_init(uint16_t channel);

/**
 * @description: 调整通道的占空比(0-100)*10
 * @param {uint32_t} duty：占空比(0-100)*10
 * @return {*}
 */
void bsp_pwm_timer1_update_duty(uint16_t channel, uint32_t duty);
#endif