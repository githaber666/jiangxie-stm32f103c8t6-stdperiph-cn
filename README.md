# STM32F103 标准外设库工程模板（全中文注释版）

基于 **江协科技 STM32 入门教程** 的工程模板，把 STM32F10x 标准外设库（StdPeriph Lib V3.5.0）与
CMSIS 内核文件中的**全部英文注释汉化为简体中文**，代码保持逐字节不变，便于对照中文注释学习外设驱动实现。

- 芯片：**STM32F103C8**（中容量，Cortex-M3）
- 工具链：**Keil MDK / ARMCC 5**（`Project.uvprojx`）
- 库版本：**STM32F10x Standard Peripherals Library V3.5.0**（2011-03-11）

## 汉化范围

| 目录 | 内容 | 是否汉化 |
|---|---|---|
| `Library/` | 24 个外设模块（各 `.c` + `.h`，共 46 个文件）：GPIO、RCC、TIM、USART、ADC、DAC、SPI、I2C、DMA、EXTI、FLASH、PWR、BKP、RTC、IWDG、WWDG、CAN、CEC、CRC、FSMC、SDIO、DBGMCU、misc | ✅ 全部 |
| `Start/` | `core_cm3.c/.h`、`stm32f10x.h`、`system_stm32f10x.c/.h`、8 个 `startup_stm32f10x_*.s` 启动文件 | ✅ 全部 |
| `User/` | `stm32f10x_it.c/.h`、`stm32f10x_conf.h` | ✅ 全部 |
| `User/main.c` | 用户主程序 | ➖ 本身已是中文注释，未改动 |

共 **64 个源文件、约 2 万处注释**完成汉化（其中 `stm32f10x.h` 单文件 5970 处）。

## 汉化原则

1. **只改注释，代码零改动。** 预处理指令、宏名与取值、函数名、变量名、类型名、结构体成员名、
   寄存器名与位域名、数字常量、字符串字面量、缩进、语句顺序全部逐字保留。
   已用「剥离全部注释后与原始库逐字比对」的方式对 **63/63** 个文件做了机器核验。
2. **保留英文功能缩写**，必要时在括号内补中文说明，例如：
   `USART（通用同步异步收发器）`、`PWM（脉宽调制）`、`ADC（模数转换器）`、`DMA（直接存储器访问）`、
   `RCC`、`HSE/HSI/LSE/LSI`、`PLL`、`NVIC`、`EXTI`、`CRC`、`IWDG/WWDG`、`FSMC`、`SDIO`、`CEC`、`DBGMCU` 等。
3. **保留 Doxygen 结构**：`@file/@author/@version/@date` 的字段值、`@brief/@param/@retval/@note/@arg`
   标签本身、`@defgroup/@addtogroup` 组名、`@ref` 符号名、`@code` 表格线与列结构均原样保留，只译说明文字。
4. **保留法律声明原文**：文件顶部的 ST/ARM 版权与免责声明大写英文段落、`COPYRIGHT` 相关行未作翻译。
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

## 目录结构

```
├── Library/     ST 标准外设库（已汉化）
├── Start/       CMSIS 内核、器件头文件、系统初始化、启动文件（已汉化）
├── User/        中断服务程序、库配置、main.c
├── Objects/     Keil 编译输出（不纳入版本管理）
├── Listings/    Keil 编译清单（不纳入版本管理）
└── Project.uvprojx   Keil MDK 工程文件
```

## 编译

用 Keil uVision 打开 `Project.uvprojx`，直接 Build 即可（ARMCC 5）。首次编译前请确认已安装
STM32F1 器件支持包（Keil.STM32F1xx_DFP）。

## 说明

- 本工程仅对**注释**做了汉化，代码逻辑与 ST 官方 V3.5.0 库完全一致，行为不变。
- 原始版权归 STMicroelectronics / ARM 所有，本仓库仅为学习用途的注释汉化版本。
- 教程与原始工程模板来自江协科技（B 站 STM32 入门教程）。
