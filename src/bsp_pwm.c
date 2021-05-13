/*
 * @Author: MrTan
 * @Date: 2021-05-13 14:03:05
 * @LastEditTime: 2021-05-13 19:07:37
 * @LastEditors: MrTan
 * @Description: Timer Pwm输出
 * @FilePath: /gd32_sipeed/src/bsp_pwm.c
 */

#include "gd32vf103.h"
#include "bsp_pwm.h"

void bsp_pwm_timer1_init(uint16_t channel)
{
    /* -----------------------------------------------------------------------
    TIMER1CLK = SystemCoreClock / 108 = 1MHz
    ----------------------------------------------------------------------- */
    rcu_periph_clock_enable(RCU_GPIOA);
    rcu_periph_clock_enable(RCU_AF);
    switch (channel)
    {
    case TIMER_CH_0:
        gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_0);
        break;
    case TIMER_CH_1:
        gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_1);
        break;
    case TIMER_CH_2:
        gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_2);
        break;
    case TIMER_CH_3:
        gpio_init(GPIOA, GPIO_MODE_AF_PP, GPIO_OSPEED_50MHZ, GPIO_PIN_3);
        break;
    default:
        break;
    }

    timer_oc_parameter_struct timer_ocinitpara;
    timer_parameter_struct timer_initpara;
    rcu_periph_clock_enable(RCU_TIMER1);
    timer_deinit(TIMER1);
    timer_struct_para_init(&timer_initpara);
    timer_initpara.prescaler = 107; // 预分频 108Mhz / 108 = 1Mhz
    timer_initpara.alignedmode = TIMER_COUNTER_EDGE;
    timer_initpara.counterdirection = TIMER_COUNTER_UP;
    timer_initpara.period = 19999; // pwm的周期 1000ms / 1Mhz * 20000 = 20ms
    timer_initpara.clockdivision = TIMER_CKDIV_DIV1;
    timer_initpara.repetitioncounter = 0;
    timer_init(TIMER1, &timer_initpara);

    // 配置通道
    timer_channel_output_struct_para_init(&timer_ocinitpara);
    timer_ocinitpara.outputstate = TIMER_CCX_ENABLE;
    timer_ocinitpara.outputnstate = TIMER_CCXN_DISABLE;
    timer_ocinitpara.ocpolarity = TIMER_OC_POLARITY_HIGH;
    timer_ocinitpara.ocnpolarity = TIMER_OCN_POLARITY_HIGH;
    timer_ocinitpara.ocidlestate = TIMER_OC_IDLE_STATE_LOW;
    timer_ocinitpara.ocnidlestate = TIMER_OCN_IDLE_STATE_LOW;
    timer_channel_output_config(TIMER1, channel, &timer_ocinitpara);

    //设置比较值
    timer_channel_output_pulse_value_config(TIMER1, channel, 19999);
    timer_channel_output_mode_config(TIMER1, channel, TIMER_OC_MODE_PWM0);
    timer_channel_output_shadow_config(TIMER1, channel, TIMER_OC_SHADOW_DISABLE);
    timer_auto_reload_shadow_enable(TIMER1);
    timer_enable(TIMER1);
}

void bsp_pwm_timer1_update_duty(uint16_t channel, uint32_t duty)
{
    if (duty > 0 && duty <= 1000)
    {
        timer_channel_output_pulse_value_config(TIMER1, channel, 20 * duty - 1);
    }
}