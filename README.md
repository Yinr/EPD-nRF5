# EPD-nRF5

墨水屏日历固件，支持农历、节气、节假日调休显示，也可以通过蓝牙传输图像到墨水屏作为相框使用。日历界面已适配常见的 4.2 寸和 7.5 寸墨水屏分辨率，且同一个固件可驱动不同尺寸屏幕（可通过上位机在线切换屏幕尺寸和驱动）。

支持的主控芯片有： `nrf51822` / `nrf51802` / `nrf52811` / `nrf52810`，墨水屏方面支持常见的 `UC81xx` / `SSD16xx` 系列驱动（黑白/三色/四色），同时还支持自定义墨水屏到 MCU 的引脚映射，支持睡眠唤醒（NFC / 无线充电器），支持蓝牙 OTA 固件升级。

![](docs/images/3.jpg)

## 上位机

本项目自带一个基于浏览器蓝牙接口实现的网页版上位机，可使用手机或电脑打开下面地址使用，或者在本地直接双击打开 `html/index.html` 来使用。

- 地址：https://tsl0922.github.io/EPD-nRF5
- 演示：https://www.bilibili.com/video/BV1KWAVe1EKs
- 交流群: [1033086563](https://qm.qq.com/q/SckzhfDxuu) (点击链接加入群聊)

![](docs/images/0.jpg)

上位机支持多种图片抖动算法，且可以对图片进行涂鸦、添加文字。除了显示图片作为电子相框外，还可以切换到日历模式，显示月历、农历节气、节假日、放假调休等信息。

## 支持设备

[查看文档](docs/devices.md)。

## 开发编译

[查看文档](docs/develop.md)。

## 致谢

本项目使用或参考了以下项目的代码：

- [ZinggJM/GxEPD2](https://github.com/ZinggJM/GxEPD2)
- [waveshareteam/e-Paper](https://github.com/waveshareteam/e-Paper)
- [atc1441/ATC_TLSR_Paper](https://github.com/atc1441/ATC_TLSR_Paper)
