/*! 
   \Date: 2021-05-12 21:09:06
   \LastEditTime: 2021-05-12 21:12:51
   \LastEditors: MrTan
   \Description: ADC功能
   \FilePath: /gd32vf103_sipeed/include/bsp_adc.h
 */

#ifndef BSP_ADC_H
#define BSP_ADC_H

/*! 
   \brief   adc初始化
   \param[in] gpio_periph: GPIOx(x = A,B,C,D,E)
   \param[in] pin: GPIO_PIN_x(x=0..15)
   \retval: none
 */
void bsp_adc_init(uint32_t gpio_periph, uint32_t pin);
#endif // !BSP_ADC_H