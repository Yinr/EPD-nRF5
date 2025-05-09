# EPD-nRF5

4.2 寸电子墨水屏固件，带有一个[网页版上位机](https://tsl0922.github.io/EPD-nRF5/)，可以通过蓝牙传输图像到墨水屏，也可以把墨水屏设置为日历模式（支持农历、节气）。

支持 `nrf51822` / `nrf51802` / `nrf52811` / `nrf52810` MCU 作为主控，驱动 IC 为 `UC8176` / `UC8276` / `SSD1619` / `SSD1683` 的 4.2 寸黑白/黑白红墨水屏，同时还支持自定义墨水屏到 MCU 的引脚映射，支持睡眠唤醒（NFC / 无线充电器）。

![](docs/images/3.jpg)

## 支持设备

- 老五 4.2 寸价签，黑白双色版本

    ```
    MCU：nrf51822
    RAM：16K
    ROM：128K

    驱动：UC8176 (EPD_4in2)
    屏幕引脚：0508090A0B0C0D
    线圈引脚：07
    ```

    ![](docs/images/1.jpg)

- 老五 4.2 寸价签，黑白红三色版本

    ```
    MCU：nrf51802
    RAM：16K
    ROM：256K

    驱动：UC8176 (EPD_4in2b_V2)
    屏幕引脚：0A0B0C0D0E0F10
    线圈引脚：09
    LED引脚：03/04/05 （有三个 LED，任选一个使用）
    ```

    ![](docs/images/2.jpg)

- 其它基于 `nrf51822` / `nrf51802` / `nrf52811` / `nrf52810` 的价签，理论上都支持

## 上位机

本项目自带一个基于浏览器蓝牙接口实现的网页版上位机，可通过上面网址访问，或者在本地直接双击打开 `html/index.html` 来使用。

- 地址：https://tsl0922.github.io/EPD-nRF5
- 演示：https://www.bilibili.com/video/BV1KWAVe1EKs
- 交流群: [1033086563](https://qm.qq.com/q/SckzhfDxuu) (点击链接加入群聊)

![](docs/images/0.jpg)

> **提示:** 上图展示的部分不常用的功能现已默认隐藏，如需显示可点击页面底部的 `开发模式` 链接。

## 开发

> **注意:**
> - 推荐使用 [Keil 5.36](https://img.anfulai.cn/bbs/96992/MDK536.EXE) 或以下版本（如遇到 pack 无法下载，可到群文件下载）
> - `sdk10` 分支为旧版 SDK 代码，蓝牙协议栈占用的空间小一些，用于支持 128K Flash 芯片（不再更新）

这里以 nRF51 版本项目为例 (`Keil/EPD-nRF51.uvprojx`)，项目配置有几个 `Target`：

- `nRF51822_xxAA`: 用于编译 256K Flash 固件
- `flash_softdevice`: 刷蓝牙协议栈用（只需刷一次）

烧录器可以使用 J-Link 或者 DAPLink（可使用 [RTTView](https://github.com/XIVN1987/RTTView) 查看 RTT 日志）。

**刷机流程:**

> **注意:** 这是自己编译代码的刷机流程。如不改代码，强烈建议到 [Releases](https://github.com/tsl0922/EPD-nRF5/releases) 下载编译好的固件，**不需要单独下载蓝牙协议栈**，且有 [刷机教程](https://b23.tv/AaphIZp) （没有 Keil 开发经验的，请不要给自己找麻烦去编译）

1. 全部擦除 (Keil 擦除后刷不了的话，使用烧录器的上位机软件擦除试试)
2. 切换到 `flash_softdevice`，下载蓝牙协议栈，**不要编译直接下载**（只需刷一次）
3. 切换到 `nRF51822_xxAA`，先编译再下载

### 模拟器

本项目提供了一个可在 Windows 下运行界面代码的模拟器，修改了界面代码后无需下载到单片机即可查看效果。

仿真效果图：

![](docs/images/4.jpg)

> **提示:** 按`R`键切换黑白、三色，空格键切换日历时钟界面，上下键切换月份，左右键切换日期。

**编译方法：**

下载并安装 [MSYS2](https://www.msys2.org) 后，打开 `MSYS2 MINGW64` 命令窗口执行：

```bash
pacman -Syu
pacman -S make mingw-w64-x86_64-gcc
cd <本项目目录>
make -f Makefile.win32
```

## 附录

上位机支持的指令列表（指令和参数全部要使用十六进制）：

- 驱动相关：
    - `00`+`引脚配置`: 设置引脚映射（见上面引脚配置）
    - `01`+`驱动ID`: 驱动初始化
    - `02`: 清空屏幕（把屏幕刷为白色）
    - `03`+`命令`: 发送命令到屏幕（请参考屏幕主控手册）
    - `04`+`数据`: 写入数据到屏幕内存（同上）
    - `05`: 刷新屏幕（显示已写入屏幕内存的数据）
    - `06`: 屏幕睡眠
- 日历模式：
    - `20`+`UNIX时间戳`+`时区`: 同步时间并开启日历模式
- 系统相关：
    - `90`+`配置数据`: 写入自定义配置（重启生效）
    - `91`: 系统重启
    - `92`: 系统睡眠
    - `99`: 恢复默认设置并重启

## 致谢

本项目使用或参考了以下项目的代码：

- [ZinggJM/GxEPD2](https://github.com/ZinggJM/GxEPD2)
- [waveshareteam/e-Paper](https://github.com/waveshareteam/e-Paper)
- [atc1441/ATC_TLSR_Paper](https://github.com/atc1441/ATC_TLSR_Paper)
