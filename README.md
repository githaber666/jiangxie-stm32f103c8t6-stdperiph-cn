# 江协科技 STM32F103C8T6 工程模板 · 标准库汉化版

![MCU](https://img.shields.io/badge/MCU-STM32F103C8T6-0091BD?logo=stmicroelectronics&logoColor=white)
![StdPeriph](https://img.shields.io/badge/StdPeriph%20Lib-V3.5.0-success)
![Toolchain](https://img.shields.io/badge/Toolchain-Keil%20MDK%20%2F%20ARMCC%205-ff8200)
![Comments](https://img.shields.io/badge/注释-简体中文-D1242F)
![Tutorial](https://img.shields.io/badge/教程-江协科技-6E49C1)

> 把 STM32F10x 标准外设库与 CMSIS 内核文件中的**全部英文注释汉化为简体中文**，代码逐字节保持不变，对照中文即可读懂每一个外设驱动的实现。

本工程基于 **江协科技《STM32 入门教程》** 的 Keil 工程模板，在 **STM32F10x Standard Peripheral Library V3.5.0** 的基础上完成注释汉化，既适合配合教程逐章学习，也可作为中文标准库工程直接二次开发。

## 特性

- **全中文注释**：23 组标准外设驱动 + CMSIS 内核 + 启动文件，共 63 个源文件、约 2 万处注释。
- **代码零改动**：只翻译注释，预处理指令、宏名与取值、函数名、变量名、类型名、寄存器名与位域名、常量、字符串、缩进、语句顺序全部逐字保留。
- **机器核验**：已用脚本「剥离全部注释后与 ST 官方 V3.5.0 库逐字比对」，对 **63/63** 个源文件完成核验，结果全部一致。
- **开箱即用**：自带 Keil MDK 工程文件，Build 即可生成 `.hex` / `.axf`。
- **术语统一、保留缩写**：统一翻译术语，同时保留 USART、PWM、ADC、DMA、RCC 等常用英文缩写。
- **保留 Doxygen 结构与 ST/ARM 法律声明原文**。

## 硬件平台

| 项目 | 参数 |
|---|---|
| 型号 | STM32F103C8T6 |
| 内核 | ARM Cortex-M3（32 位） |
| 最高主频 | 72 MHz |
| Flash | 64 KB |
| SRAM | 20 KB |
| 封装 | LQFP48 |
| GPIO | 37 个 |
| 定时器 | 高级 ×1（TIM1）、通用 ×3（TIM2/3/4）、基本 ×2（TIM6/7） |
| 通信接口 | USART ×3、SPI ×2、I2C ×2、CAN ×1、USB 2.0 ×1 |
| ADC | 2 × 12 位，最多 10 个外部通道 |
| 调试接口 | SWD / JTAG |
| 供电 | 2.0 ~ 3.6 V |
| 工作温度 | -40 ~ 85 °C |

> 教程使用 STM32F103C8T6 最小系统板，通过板载或外置 ST-Link / J-Link 以 SWD 方式下载调试。

## 软件环境

| 项目 | 版本 / 说明 |
|---|---|
| 标准外设库 | STM32F10x Standard Peripherals Library **V3.5.0**（2011-03-11） |
| CMSIS | Cortex-M3 核心文件（`core_cm3`、`system_stm32f10x`） |
| IDE | Keil uVision / MDK-ARM |
| 编译器 | ARMCC 5（AC5，工程记录为 V5.06） |
| 器件支持包 | Keil.STM32F1xx_DFP |

## 快速开始

1. **获取代码**

   ```bash
   git clone https://github.com/githaber666/jiangxie-stm32f103c8t6-stdperiph-cn.git
   ```

   或在本页面点击 `Code → Download ZIP`，解压后使用。

2. **安装器件支持包**：打开 Keil → `Pack Installer`，安装 `Keil::STM32F1xx_DFP`（多数 MDK 已自带）。
3. **打开工程**：双击 `Project.uvprojx`（或 Keil 内 `Project → Open Project`）。
4. **编译**：点击 `Build（F7）`，将在 `Objects/` 下生成 `.axf` 与 `.hex`。
5. **下载**：连接 ST-Link，在 `Options for Target → Debug` 选择 `ST-Link Debugger`，于 `Settings → Flash Download` 勾选 `Reset and Run`，随后 `Download（F8）`。

## 汉化范围

| 目录 | 内容 | 是否汉化 |
|---|---|---|
| `Library/` | 23 组驱动（各 `.c` + `.h`，共 46 个文件）：misc 及 GPIO、RCC、TIM、USART、ADC、DAC、SPI、I2C、DMA、EXTI、FLASH、PWR、BKP、RTC、IWDG、WWDG、CAN、CEC、CRC、FSMC、SDIO、DBGMCU | ✅ 全部 |
| `Start/` | `core_cm3.c/.h`、`stm32f10x.h`、`system_stm32f10x.c/.h`、8 个 `startup_stm32f10x_*.s` 启动文件（共 13 个） | ✅ 全部 |
| `User/` | `stm32f10x_it.c/.h`、`stm32f10x_conf.h`（共 3 个） | ✅ 全部 |
| `User/main.c` | 用户主程序 | ➖ 本身已是中文注释，未改动 |

其中 62 个英文源文件的注释完成汉化（`User/main.c` 原本即中文）；`stm32f10x.h` 单文件约 5970 处注释。全部 63 个源文件均通过「去注释后与官方库逐字比对」核验。

## 目录结构

```
.
├── Library/                    ST 标准外设库（23 组 .c/.h，共 46 个，注释已汉化，平铺存放）
│   ├── misc.c / misc.h         NVIC 与系统异常优先级配置
│   ├── stm32f10x_gpio.c/.h     其余 22 个外设模块（rcc/tim/usart/adc/dac/spi/
│   └── ...                       i2c/dma/exti/flash/pwr/bkp/rtc/iwdg/wwdg/can/
│                                   cec/crc/fsmc/sdio/dbgmcu）
├── Start/                      CMSIS 与启动相关（注释已汉化）
│   ├── core_cm3.c / core_cm3.h
│   ├── stm32f10x.h             器件寄存器 / 位域定义（约 5970 处注释）
│   ├── system_stm32f10x.c / system_stm32f10x.h
│   └── startup_stm32f10x_*.s   ld / md / hd / xl / ld_vl / md_vl / hd_vl / cl 共 8 个
├── User/                       用户代码
│   ├── main.c                  主程序（原本即中文注释）
│   ├── stm32f10x_conf.h        库配置、外设头文件总开关
│   └── stm32f10x_it.c / stm32f10x_it.h    中断服务程序
├── Objects/                    Keil 编译输出（不纳入版本管理）
├── Listings/                   Keil 编译清单（不纳入版本管理）
├── DebugConfig/                调试配置（不纳入版本管理）
├── Project.uvprojx             Keil MDK 工程文件
├── Project.uvoptx              Keil MDK 工程选项
├── .gitignore
└── README.md
```

## 汉化原则

1. **只改注释，代码零改动。** 预处理指令、宏名与取值、函数名、变量名、类型名、结构体成员名、
   寄存器名与位域名、数字常量、字符串字面量、缩进、语句顺序全部逐字保留。
2. **保留英文功能缩写**，必要时在括号内补中文说明，例如：
   `USART（通用同步异步收发器）`、`PWM（脉宽调制）`、`ADC（模数转换器）`、`DMA（直接存储器访问）`，
   以及 `RCC`、`HSE/HSI/LSE/LSI`、`PLL`、`NVIC`、`EXTI`、`CRC`、`IWDG/WWDG`、`FSMC`、`SDIO`、`CEC`、`DBGMCU` 等。
3. **保留 Doxygen 结构**：`@file/@author/@version/@date` 的字段值、`@brief/@param/@retval/@note/@arg`
   标签本身、`@defgroup/@addtogroup` 组名、`@ref` 符号名、`@code` 表格线与列结构均原样保留，只译说明文字。
4. **保留法律声明原文**：文件顶部 ST/ARM 版权与免责声明的大写英文段落、`COPYRIGHT` 相关行未作翻译。
5. **统一术语**（节选）：None→无、pointer→指针、buffer→缓冲区、flag→标志位、interrupt→中断、
   enable/disable→使能/失能、prescaler→预分频器、duty cycle→占空比、channel→通道、trigger→触发、
   assert→断言、pending→挂起、set/reset→置位/复位、regular/injected channel→规则/注入通道、
   capture/compare→输入捕获/输出比较、dead time→死区时间、break function→刹车功能、
   option bytes→选项字节、read out protection→读出保护、window watchdog→窗口看门狗、
   tamper→侵入检测、backup domain→后备区域、remap→重映射、alternate function→复用功能。

## 编码与格式

所有源文件统一为 **UTF-8（无 BOM）+ CRLF** 换行，与工程原有风格一致。

> 若 Keil 中显示中文注释为乱码，请在 `Edit → Configuration → Editor → Encoding` 选择
> `UTF-8`（或 `Encode in UTF-8 without signature`），然后重新打开文件。

## 常见问题 FAQ

**Q1：Keil 打开后中文注释显示乱码？**
`Edit → Configuration → Editor → Encoding` 选择 `UTF-8`（`Encode in UTF-8 without signature`），重新打开文件即可。

**Q2：编译提示找不到器件、选不到 STM32F103C8？**
未安装器件支持包，在 `Pack Installer` 中安装 `Keil::STM32F1xx_DFP`。

**Q3：提示 ARMCC 编译器版本不一致或编译器缺失？**
本工程基于 AC5（ARMCC 5）。若本机仅安装 AC6，请在 `Options for Target → Target → ARM Compiler` 选择已安装的 V5 版本；Keil 打开工程时也可能按本机编译器自动更新该字段，不影响源代码。

**Q4：ST-Link 下载报 "No target connected" / "SWD Communication Failure"？**
检查 SWDIO / SWCLK / GND / 3V3 接线与驱动、最小系统板供电；在 `Options → Debug → ST-Link → Settings` 确认能读到 IDCODE。若程序把 SWD 引脚配置成了普通 GPIO 会导致失联，可尝试 "Connect Under Reset"（按住复位再连接）。

**Q5：编译后没有生成 .hex？**
在 `Options for Target → Output` 勾选 `Create HEX File`。

## 如何验证「代码零改动」

对任一汉化文件，用脚本剥离全部 `// ...` 与 `/* ... */` 注释，并对空白做归一化后，与 ST 官方 V3.5.0
对应原文件逐字比对。本仓库已对全部 63 个源文件完成该核验，结果一致——发生变化的仅有注释文本。

## 推荐学习顺序（对应江协教程主线）

1. 工程框架，寄存器 / 标准库两种编程方式
2. GPIO：点亮 LED、蜂鸣器、数码管
3. 外部中断 EXTI：按键触发
4. 定时器 TIM：定时中断、PWM（呼吸灯 / 舵机）
5. 串口 USART：收发、重定向 `printf`
6. ADC / DAC：模拟量采集与输出
7. I2C（OLED 显示）、SPI（外部 Flash W25Qxx）
8. DMA：串口 / ADC 配合 DMA
9. 其他外设：RTC、IWDG / WWDG、CAN、USB 等按需学习

## 许可与免责声明

- 本仓库仅对官方库的**注释**进行汉化，源代码版权归 **STMicroelectronics / ARM** 所有，各文件开头的版权与免责声明原样保留。
- 工程模板与教程来自 **江协科技**（B 站《STM32 入门教程》），版权归原作者所有。
- 本仓库仅用于个人学习与教学交流，请勿用于商业用途；如内容涉及侵权，请联系删除。

## 致谢

- 感谢 **江协科技** 提供高质量的免费 STM32 入门教程与工程模板。
- 感谢 **STMicroelectronics** 提供 Standard Peripheral Library。
