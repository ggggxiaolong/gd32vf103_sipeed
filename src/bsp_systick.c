/*
 * @Author: your name
 * @Date: 2021-05-11 15:07:11
 * @LastEditTime: 2021-05-11 15:07:37
 * @LastEditors: your name
 * @Description: In User Settings Edit
 * @FilePath: /gd32vf103/home/mrtan/Documents/PlatformIO/Projects/gd32_sipeed/src/bsp_systick.c
 */
#include "gd32vf103.h"
#include "bsp_systick.h"

/*!
    \brief      delay a time in milliseconds
    \param[in]  count: count in milliseconds
    \param[out] none
    \retval     none
*/
void delay_1ms(uint32_t count)
{
    uint64_t start_mtime, delta_mtime;

    // Don't start measuruing until we see an mtime tick
    uint64_t tmp = get_timer_value();
    do {
    start_mtime = get_timer_value();
    } while (start_mtime == tmp);

    do {
    delta_mtime = get_timer_value() - start_mtime;
    }while(delta_mtime <(SystemCoreClock/4000.0 *count ));
}