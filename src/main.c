/*
 * @Author: MrTan
 * @Date: 2021-05-11 14:45:23
 * @LastEditTime: 2021-05-13 19:18:25
 * @LastEditors: MrTan
 * @Description: 添加按键扫描
 * @FilePath: /gd32_sipeed/src/main.c
 */

#include "gd32vf103.h"
#include "bsp_pwm.h"
#include "bsp_systick.h"

int main(void)
{
    bsp_pwm_timer1_init(TIMER_CH_2);

    uint32_t duty = 50;
    while (1)
    {
        delay_1ms(100);
        bsp_pwm_timer1_update_duty(TIMER_CH_2, duty);
        duty += 2;
        if (duty>100)
        {
            duty=50;
        }
        
    }
}