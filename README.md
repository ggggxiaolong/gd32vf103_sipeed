### GD32VF103龙眼开发板

开发环境：

* VsCode
* Platformio
* gd32v

开发任务：

- [x]  点灯
- [ ]  按键中断
- [ ]  USART串口
- [ ]  ADC
- [ ]  定时器
- [ ]  PWM驱动舵机
- [ ]  RTC
- [ ]  RS485
- [ ]  CAN
- [ ]  SPI
- [ ]  电源管理
- [ ]  Flash

使用dfu模式或者串口下载需要配置 '/etc/udev/rules.d/70-ttyusb.rules' 文件

```
KERNEL=="ttyUSB[0-9]*", MODE="0666"
SUBSYSTEM=="usb", ATTRS{idVendor}=="28e9", ATTRS{idProduct}=="0189", MODE="0666"
SUBSYSTEM=="usb_device", ATTRS{idVendor}=="28e9", ATTRS{idProduct}=="0189", MODE="0666"
```