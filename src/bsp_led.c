#include "bsp_led.h"

void bsp_led_init(void)
{
    // 使能时钟
    rcu_periph_clock_enable(RCU_GPIOC);
    rcu_periph_clock_enable(RCU_GPIOA);
    // 配置GPIO端口 推挽输出 低频率
    gpio_init(BSP_LED_RED_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, BSP_LED_RED_PIN);
    gpio_init(BSP_LED_GREEN_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, BSP_LED_GREEN_PIN);
    gpio_init(BSP_LED_BLUE_PORT, GPIO_MODE_OUT_PP, GPIO_OSPEED_2MHZ, BSP_LED_BLUE_PIN);
    // 配置默认值, 高电平 关闭led
    GPIO_BOP(BSP_LED_RED_PORT) = BSP_LED_RED_PIN;
    GPIO_BOP(BSP_LED_GREEN_PORT) = BSP_LED_GREEN_PIN;
    GPIO_BOP(BSP_LED_BLUE_PORT) = BSP_LED_BLUE_PIN;
}
/**
 * @description: led 红灯打开
 */
void bsp_led_red_on(void)
{
    GPIO_BC(BSP_LED_RED_PORT) = BSP_LED_RED_PIN;
}
/**
 * @description: led 红灯关闭
 */
void bsp_led_red_off(void)
{
    GPIO_BOP(BSP_LED_RED_PORT) = BSP_LED_RED_PIN;
}
/**
 * @description: 切换led红灯状态
 * @param {*}
 * @return {*}
 */
void bsp_led_red_toogle(void)
{
    if ((uint32_t) RESET != (GPIO_OCTL(BSP_LED_RED_PORT) & (BSP_LED_RED_PIN))) {
        return GPIO_BC(BSP_LED_RED_PORT) = BSP_LED_RED_PIN;
    } else {
        return GPIO_BOP(BSP_LED_RED_PORT) = BSP_LED_RED_PIN;
    }
}

/**
 * @description: 绿灯打开
 * @param {*}
 * @return {*}
 */
void bsp_led_green_on(void)
{
    GPIO_BC(BSP_LED_GREEN_PORT) = BSP_LED_GREEN_PIN;
}
/**
 * @description: 绿灯关闭
 * @param {*}
 * @return {*}
 */
void bsp_led_green_off(void)
{
    GPIO_BOP(BSP_LED_GREEN_PORT) = BSP_LED_GREEN_PIN;
}
/**
 * @description: 切换绿灯状态
 * @param {*}
 * @return {*}
 */
void bsp_led_green_toogle(void)
{
    if ((uint32_t) RESET != (GPIO_OCTL(BSP_LED_GREEN_PORT) & (BSP_LED_GREEN_PIN))) {
        return GPIO_BC(BSP_LED_GREEN_PORT) = BSP_LED_GREEN_PIN;
    } else {
        return GPIO_BOP(BSP_LED_GREEN_PORT) = BSP_LED_GREEN_PIN;
    }
}

/**
 * @description: 蓝灯打开
 * @param {*}
 * @return {*}
 */
void bsp_led_blue_on(void)
{
    GPIO_BC(BSP_LED_BLUE_PORT) = BSP_LED_BLUE_PIN;
}
/**
 * @description: 蓝灯关闭
 * @param {*}
 * @return {*}
 */
void bsp_led_blue_off(void)
{
    GPIO_BOP(BSP_LED_BLUE_PORT) = BSP_LED_BLUE_PIN;
}
/**
 * @description: 切换蓝灯状态
 * @param {*}
 * @return {*}
 */
void bsp_led_blue_toogle(void)
{
    if ((uint32_t) RESET != (GPIO_OCTL(BSP_LED_BLUE_PORT) & (BSP_LED_BLUE_PIN))) {
        return GPIO_BC(BSP_LED_BLUE_PORT) = BSP_LED_BLUE_PIN;
    } else {
        return GPIO_BOP(BSP_LED_BLUE_PORT) = BSP_LED_BLUE_PIN;
    }
}