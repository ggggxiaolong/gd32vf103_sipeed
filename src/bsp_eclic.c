#include "bsp_eclic.h"
#include "gd32vf103.h"

/**
 * 全局中断配置
 * */
void bsp_eclic_init(void)
{
    //全局中断使能
    eclic_global_interrupt_enable();
    //配置全局优先级分组
    eclic_priority_group_set(ECLIC_PRIGROUP_LEVEL4_PRIO0);
}