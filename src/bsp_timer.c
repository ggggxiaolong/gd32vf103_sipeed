/*
 * @Author: MrTan
 * @Date: 2021-05-12 16:28:55
 * @LastEditTime: 2021-05-12 17:46:16
 * @LastEditors: MrTan
 * @Description: 定时器
 * @FilePath: /gd32_sipeed/src/bsp_timer.c
 */
#include "gd32vf103.h"
#include "bsp_timer.h"

/**
 * @description: 开启时钟,时钟1的频率是108Mhz
 *              需要提前配置全局中断，全局中断分组，时钟的中断优先级
 * @param {uint32_t} timer_periph: TIMERx(x=0..6)
 * @param {uint32_t} time_ms 中断剑河
 * @return {*}
 */
void bsp_timer_init(uint32_t timer_periph, uint32_t time_ms)
{
    // 使用时钟1进行定时，,产生一个500ms的中断

    timer_parameter_struct timer_cfg;
    // 开启时钟
    switch (timer_periph)
    {
    case TIMER0:
        rcu_periph_clock_enable(RCU_TIMER0);
        break;
    case TIMER1:
        rcu_periph_clock_enable(RCU_TIMER1);
        break;
    case TIMER2:
        rcu_periph_clock_enable(RCU_TIMER2);
        break;
    case TIMER3:
        rcu_periph_clock_enable(RCU_TIMER3);
        break;
    case TIMER4:
        rcu_periph_clock_enable(RCU_TIMER4);
        break;
    case TIMER5:
        rcu_periph_clock_enable(RCU_TIMER5);
        break;
    case TIMER6:
        rcu_periph_clock_enable(RCU_TIMER6);
        break;
    default:
        break;
    }
    // 清除定时器设置
    timer_deinit(timer_periph);
    // 设置定时器欲分频值 时钟频率54Mhz
    timer_cfg.prescaler = 10799; // 108Mhz / 10800 = 10Khz
    // 设置计数模式
    timer_cfg.alignedmode = TIMER_COUNTER_EDGE;
    timer_cfg.counterdirection = TIMER_COUNTER_UP;
    // 设置周期
    timer_cfg.period = (uint32_t)(10 * time_ms - 1);
    // 设置重复次数
    timer_cfg.repetitioncounter = 0U;
    // 设置时钟分频
    timer_cfg.clockdivision = TIMER_CKDIV_DIV1;
    // 时钟初始化
    timer_init(timer_periph, &timer_cfg);
    // 开启时钟中断
    timer_interrupt_enable(timer_periph, TIMER_INT_UP);
    // 使能时钟
    timer_enable(timer_periph);
}
