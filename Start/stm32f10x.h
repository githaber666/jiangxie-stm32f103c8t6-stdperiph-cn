/**
  ******************************************************************************
  * @file    stm32f10x.h
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief CMSIS Cortex-M3 设备外设访问层头文件。 
  *          本文件包含所有外设寄存器定义、位 
  *          定义和存储器映射，适用于 STM32F10x 互联型、 
  *          高密度、高密度超值型、中密度、 
  *          中密度超值型、低密度、低密度超值型 
  *          以及 XL 密度器件。
  *
  *          本文件是应用程序开发者
  *          在 C 源代码（通常是 main.c）中使用的唯一包含文件。本文件包含：
  *           - 配置段，用于选择：
  *              - 目标应用中使用的器件
  *              - 是否在应用程序代码中使用外设驱动（即 
  *                代码是直接访问外设寄存器 
  *                而非驱动 API），该选项由 
  *                "#define USE_STDPERIPH_DRIVER"
  *              - 修改少量应用相关参数，例如 HSE 
  *                晶振频率
  *           - 所有外设的数据结构和地址映射
  *           - 外设寄存器声明和位定义
  *           - 访问外设寄存器硬件的宏
  *
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f10x
  * @{
  */
    
#ifndef __STM32F10x_H
#define __STM32F10x_H

#ifdef __cplusplus
 extern "C" {
#endif 
  
/** @addtogroup Library_configuration_section
  * @{
  */
  
/* 根据您的应用中使用的目标 STM32 器件，
   取消注释下面这一行。 
  */

#if !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD) && !defined (STM32F10X_HD_VL) && !defined (STM32F10X_XL) && !defined (STM32F10X_CL) 
  /* #define STM32F10X_LD */     /*!< STM32F10X_LD: STM32 低密度设备 */
  /* #define STM32F10X_LD_VL */  /*!< STM32F10X_LD_VL: STM32 低密度超值型设备 */  
  /* #define STM32F10X_MD */     /*!< STM32F10X_MD: STM32 中密度设备 */
  /* #define STM32F10X_MD_VL */  /*!< STM32F10X_MD_VL: STM32 中密度超值型设备 */  
  /* #define STM32F10X_HD */     /*!< STM32F10X_HD: STM32 高密度设备 */
  /* #define STM32F10X_HD_VL */  /*!< STM32F10X_HD_VL: STM32 高密度超值型设备 */  
  /* #define STM32F10X_XL */     /*!< STM32F10X_XL: STM32 XL 密度设备 */
  /* #define STM32F10X_CL */     /*!< STM32F10X_CL: STM32 互联型设备 */
#endif
/*  提示：为避免每次在这些器件之间切换时都修改本文件，
        您可以在工具链编译器的预处理中定义该器件。

 - 低密度器件是 STM32F101xx、STM32F102xx 和 STM32F103xx 微控制器，
   其闪存容量在 16 至 32 K 字节之间。
 - 低密度超值型器件是 STM32F100xx 微控制器，其闪存
   容量在 16 至 32 K 字节之间。
 - 中密度器件是 STM32F101xx、STM32F102xx 和 STM32F103xx 微控制器，
   其闪存容量在 64 至 128 K 字节之间。
 - 中密度超值型器件是 STM32F100xx 微控制器，其 
   闪存容量在 64 至 128 K 字节之间。   
 - 高密度器件是 STM32F101xx 和 STM32F103xx 微控制器，
   其闪存容量在 256 至 512 K 字节之间。
 - 高密度超值型器件是 STM32F100xx 微控制器，其 
   闪存容量在 256 至 512 K 字节之间。   
 - XL 密度器件是 STM32F101xx 和 STM32F103xx 微控制器，
   其闪存容量在 512 至 1024 K 字节之间。
 - 互联型器件是 STM32F105xx 和 STM32F107xx 微控制器。
  */

#if !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD) && !defined (STM32F10X_HD_VL) && !defined (STM32F10X_XL) && !defined (STM32F10X_CL)
 #error "Please select first the target STM32F10x device used in your application (in stm32f10x.h file)"
#endif

#if !defined  USE_STDPERIPH_DRIVER
/**
 * @brief 如果您不使用外设驱动，请注释掉下面这一行。
   此时这些驱动将不会被包含，应用程序代码将 
   基于直接访问外设寄存器 
   */
  /*#define USE_STDPERIPH_DRIVER*/
#endif

/**
 * @brief 请在下面这一行中调整应用所使用的
   外部高速晶振（HSE）的值 
   
   提示：为避免每次使用不同的 HSE 时都修改本文件，
        您可以在工具链编译器的预处理中定义 HSE 值。
  */           
#if !defined  HSE_VALUE
 #ifdef STM32F10X_CL   
  #define HSE_VALUE    ((uint32_t)25000000) /*!< 外部晶振的频率值（单位 Hz） */
 #else 
  #define HSE_VALUE    ((uint32_t)8000000) /*!< 外部晶振的频率值（单位 Hz） */
 #endif /* STM32F10X_CL */
#endif /* HSE_VALUE */


/**
 * @brief 请在下面这一行中调整外部高速晶振（HSE）的启动 
   超时值 
   */
#define HSE_STARTUP_TIMEOUT   ((uint16_t)0x0500) /*!< HSE 启动超时时间 */

#define HSI_VALUE    ((uint32_t)8000000) /*!< 内部振荡器的频率值（单位 Hz）*/

/**
 * @brief STM32F10x 标准外设库版本号
   */
#define __STM32F10X_STDPERIPH_VERSION_MAIN   (0x03) /*!< [31:24] 主版本号 */                                  
#define __STM32F10X_STDPERIPH_VERSION_SUB1   (0x05) /*!< [23:16] 子版本号 1 */
#define __STM32F10X_STDPERIPH_VERSION_SUB2   (0x00) /*!< [15:8] 子版本号 2 */
#define __STM32F10X_STDPERIPH_VERSION_RC     (0x00) /*!< [7:0] 发行候选版本 */ 
#define __STM32F10X_STDPERIPH_VERSION       ( (__STM32F10X_STDPERIPH_VERSION_MAIN << 24)\
                                             |(__STM32F10X_STDPERIPH_VERSION_SUB1 << 16)\
                                             |(__STM32F10X_STDPERIPH_VERSION_SUB2 << 8)\
                                             |(__STM32F10X_STDPERIPH_VERSION_RC))

/**
  * @}
  */

/** @addtogroup Configuration_section_for_CMSIS
  * @{
  */

/**
 * @brief Cortex-M3 处理器和内核外设的配置 
 */
#ifdef STM32F10X_XL
 #define __MPU_PRESENT             1 /*!< STM32 XL 密度器件提供 MPU */
#else
 #define __MPU_PRESENT             0 /*!< 其他 STM32 器件不提供 MPU */
#endif /* STM32F10X_XL */
#define __NVIC_PRIO_BITS          4 /*!< STM32 使用 4 位表示优先级    */
#define __Vendor_SysTickConfig    0 /*!< 如果使用不同的 SysTick 配置，则设为 1 */

/**
 * @brief 根据所选器件定义的 STM32F10x 中断编号 
 *        见 @ref Library_configuration_section 
 */
typedef enum IRQn
{
/****** Cortex-M3 处理器异常编号 ****/
  NonMaskableInt_IRQn         = -14,    /*!< 2 不可屏蔽中断                             */
  MemoryManagement_IRQn       = -12,    /*!< 4 Cortex-M3 存储器管理中断              */
  BusFault_IRQn               = -11,    /*!< 5 Cortex-M3 总线故障中断                      */
  UsageFault_IRQn             = -10,    /*!< 6 Cortex-M3 用法故障中断                    */
  SVCall_IRQn                 = -5,     /*!< 11 Cortex-M3 系统服务调用中断                       */
  DebugMonitor_IRQn           = -4,     /*!< 12 Cortex-M3 调试监控中断                 */
  PendSV_IRQn                 = -2,     /*!< 14 Cortex-M3 可挂起系统服务中断                       */
  SysTick_IRQn                = -1,     /*!< 15 Cortex-M3 系统节拍中断                   */

/****** STM32 专用中断编号 ****/
  WWDG_IRQn                   = 0,      /*!< 窗口看门狗中断                            */
  PVD_IRQn                    = 1,      /*!< PVD 通过 EXTI 线检测中断            */
  TAMPER_IRQn                 = 2,      /*!< 侵入检测中断                                     */
  RTC_IRQn                    = 3,      /*!< RTC 全局中断                                 */
  FLASH_IRQn                  = 4,      /*!< FLASH 全局中断                               */
  RCC_IRQn                    = 5,      /*!< RCC 全局中断                                 */
  EXTI0_IRQn                  = 6,      /*!< EXTI 线 0 中断                                 */
  EXTI1_IRQn                  = 7,      /*!< EXTI 线 1 中断                                 */
  EXTI2_IRQn                  = 8,      /*!< EXTI 线 2 中断                                 */
  EXTI3_IRQn                  = 9,      /*!< EXTI 线 3 中断                                 */
  EXTI4_IRQn                  = 10,     /*!< EXTI 线 4 中断                                 */
  DMA1_Channel1_IRQn          = 11,     /*!< DMA1 通道 1 全局中断                      */
  DMA1_Channel2_IRQn          = 12,     /*!< DMA1 通道 2 全局中断                      */
  DMA1_Channel3_IRQn          = 13,     /*!< DMA1 通道 3 全局中断                      */
  DMA1_Channel4_IRQn          = 14,     /*!< DMA1 通道 4 全局中断                      */
  DMA1_Channel5_IRQn          = 15,     /*!< DMA1 通道 5 全局中断                      */
  DMA1_Channel6_IRQn          = 16,     /*!< DMA1 通道 6 全局中断                      */
  DMA1_Channel7_IRQn          = 17,     /*!< DMA1 通道 7 全局中断                      */

#ifdef STM32F10X_LD
  ADC1_2_IRQn                 = 18,     /*!< ADC1 和 ADC2 全局中断                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB 设备高优先级或 CAN1 发送中断       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB 设备低优先级或 CAN1 接收 0 中断       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 接收 1 中断                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 状态改变错误中断                                   */
  EXTI9_5_IRQn                = 23,     /*!< 外部线 [9:5] 中断                        */
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 刹车中断                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 更新中断                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 触发和换相中断               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 输入捕获/输出比较中断                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 全局中断                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 全局中断                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 事件中断                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 错误中断                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 全局中断                                */
  USART1_IRQn                 = 37,     /*!< USART1 全局中断                              */
  USART2_IRQn                 = 38,     /*!< USART2 全局中断                              */
  EXTI15_10_IRQn              = 40,     /*!< 外部线 [15:10] 中断                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC 闹钟通过 EXTI 线中断                */
  USBWakeUp_IRQn              = 42      /*!< USB 设备通过 EXTI 线从挂起唤醒中断 */    
#endif /* STM32F10X_LD */  

#ifdef STM32F10X_LD_VL
  ADC1_IRQn                   = 18,     /*!< ADC1 全局中断                                */
  EXTI9_5_IRQn                = 23,     /*!< 外部线 [9:5] 中断                        */
  TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 刹车和 TIM15 中断                      */
  TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 更新和 TIM16 中断                     */
  TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 触发和换相及 TIM17 中断     */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 输入捕获/输出比较中断                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 全局中断                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 全局中断                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 事件中断                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 错误中断                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 全局中断                                */
  USART1_IRQn                 = 37,     /*!< USART1 全局中断                              */
  USART2_IRQn                 = 38,     /*!< USART2 全局中断                              */
  EXTI15_10_IRQn              = 40,     /*!< 外部线 [15:10] 中断                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC 闹钟通过 EXTI 线中断                */
  CEC_IRQn                    = 42,     /*!< HDMI-CEC 中断                                   */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 和 DAC 下溢中断                      */
  TIM7_IRQn                   = 55      /*!< TIM7 中断                                       */       
#endif /* STM32F10X_LD_VL */

#ifdef STM32F10X_MD
  ADC1_2_IRQn                 = 18,     /*!< ADC1 和 ADC2 全局中断                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB 设备高优先级或 CAN1 发送中断       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB 设备低优先级或 CAN1 接收 0 中断       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 接收 1 中断                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 状态改变错误中断                                   */
  EXTI9_5_IRQn                = 23,     /*!< 外部线 [9:5] 中断                        */
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 刹车中断                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 更新中断                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 触发和换相中断               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 输入捕获/输出比较中断                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 全局中断                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 全局中断                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 全局中断                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 事件中断                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 错误中断                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 事件中断                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 错误中断                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 全局中断                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 全局中断                                */
  USART1_IRQn                 = 37,     /*!< USART1 全局中断                              */
  USART2_IRQn                 = 38,     /*!< USART2 全局中断                              */
  USART3_IRQn                 = 39,     /*!< USART3 全局中断                              */
  EXTI15_10_IRQn              = 40,     /*!< 外部线 [15:10] 中断                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC 闹钟通过 EXTI 线中断                */
  USBWakeUp_IRQn              = 42      /*!< USB 设备通过 EXTI 线从挂起唤醒中断 */  
#endif /* STM32F10X_MD */  

#ifdef STM32F10X_MD_VL
  ADC1_IRQn                   = 18,     /*!< ADC1 全局中断                                */
  EXTI9_5_IRQn                = 23,     /*!< 外部线 [9:5] 中断                        */
  TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 刹车和 TIM15 中断                      */
  TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 更新和 TIM16 中断                     */
  TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 触发和换相及 TIM17 中断     */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 输入捕获/输出比较中断                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 全局中断                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 全局中断                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 全局中断                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 事件中断                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 错误中断                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 事件中断                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 错误中断                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 全局中断                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 全局中断                                */
  USART1_IRQn                 = 37,     /*!< USART1 全局中断                              */
  USART2_IRQn                 = 38,     /*!< USART2 全局中断                              */
  USART3_IRQn                 = 39,     /*!< USART3 全局中断                              */
  EXTI15_10_IRQn              = 40,     /*!< 外部线 [15:10] 中断                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC 闹钟通过 EXTI 线中断                */
  CEC_IRQn                    = 42,     /*!< HDMI-CEC 中断                                   */
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 和 DAC 下溢中断                      */
  TIM7_IRQn                   = 55      /*!< TIM7 中断                                       */       
#endif /* STM32F10X_MD_VL */

#ifdef STM32F10X_HD
  ADC1_2_IRQn                 = 18,     /*!< ADC1 和 ADC2 全局中断                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB 设备高优先级或 CAN1 发送中断       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB 设备低优先级或 CAN1 接收 0 中断       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 接收 1 中断                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 状态改变错误中断                                   */
  EXTI9_5_IRQn                = 23,     /*!< 外部线 [9:5] 中断                        */
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 刹车中断                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 更新中断                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 触发和换相中断               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 输入捕获/输出比较中断                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 全局中断                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 全局中断                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 全局中断                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 事件中断                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 错误中断                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 事件中断                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 错误中断                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 全局中断                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 全局中断                                */
  USART1_IRQn                 = 37,     /*!< USART1 全局中断                              */
  USART2_IRQn                 = 38,     /*!< USART2 全局中断                              */
  USART3_IRQn                 = 39,     /*!< USART3 全局中断                              */
  EXTI15_10_IRQn              = 40,     /*!< 外部线 [15:10] 中断                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC 闹钟通过 EXTI 线中断                */
  USBWakeUp_IRQn              = 42,     /*!< USB 设备通过 EXTI 线从挂起唤醒中断 */
  TIM8_BRK_IRQn               = 43,     /*!< TIM8 刹车中断                                 */
  TIM8_UP_IRQn                = 44,     /*!< TIM8 更新中断                                */
  TIM8_TRG_COM_IRQn           = 45,     /*!< TIM8 触发和换相中断               */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 输入捕获/输出比较中断                       */
  ADC3_IRQn                   = 47,     /*!< ADC3 全局中断                                */
  FSMC_IRQn                   = 48,     /*!< FSMC 全局中断                                */
  SDIO_IRQn                   = 49,     /*!< SDIO 全局中断                                */
  TIM5_IRQn                   = 50,     /*!< TIM5 全局中断                                */
  SPI3_IRQn                   = 51,     /*!< SPI3 全局中断                                */
  UART4_IRQn                  = 52,     /*!< UART4 全局中断                               */
  UART5_IRQn                  = 53,     /*!< UART5 全局中断                               */
  TIM6_IRQn                   = 54,     /*!< TIM6 全局中断                                */
  TIM7_IRQn                   = 55,     /*!< TIM7 全局中断                                */
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 通道 1 全局中断                      */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 通道 2 全局中断                      */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 通道 3 全局中断                      */
  DMA2_Channel4_5_IRQn        = 59      /*!< DMA2 通道 4 和通道 5 全局中断        */
#endif /* STM32F10X_HD */  

#ifdef STM32F10X_HD_VL
  ADC1_IRQn                   = 18,     /*!< ADC1 全局中断                                */
  EXTI9_5_IRQn                = 23,     /*!< 外部线 [9:5] 中断                        */
  TIM1_BRK_TIM15_IRQn         = 24,     /*!< TIM1 刹车和 TIM15 中断                      */
  TIM1_UP_TIM16_IRQn          = 25,     /*!< TIM1 更新和 TIM16 中断                     */
  TIM1_TRG_COM_TIM17_IRQn     = 26,     /*!< TIM1 触发和换相及 TIM17 中断     */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 输入捕获/输出比较中断                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 全局中断                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 全局中断                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 全局中断                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 事件中断                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 错误中断                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 事件中断                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 错误中断                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 全局中断                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 全局中断                                */
  USART1_IRQn                 = 37,     /*!< USART1 全局中断                              */
  USART2_IRQn                 = 38,     /*!< USART2 全局中断                              */
  USART3_IRQn                 = 39,     /*!< USART3 全局中断                              */
  EXTI15_10_IRQn              = 40,     /*!< 外部线 [15:10] 中断                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC 闹钟通过 EXTI 线中断                */
  CEC_IRQn                    = 42,     /*!< HDMI-CEC 中断                                   */
  TIM12_IRQn                  = 43,     /*!< TIM12 全局中断                               */
  TIM13_IRQn                  = 44,     /*!< TIM13 全局中断                               */
  TIM14_IRQn                  = 45,     /*!< TIM14 全局中断                               */
  TIM5_IRQn                   = 50,     /*!< TIM5 全局中断                                */
  SPI3_IRQn                   = 51,     /*!< SPI3 全局中断                                */
  UART4_IRQn                  = 52,     /*!< UART4 全局中断                               */
  UART5_IRQn                  = 53,     /*!< UART5 全局中断                               */  
  TIM6_DAC_IRQn               = 54,     /*!< TIM6 和 DAC 下溢中断                      */
  TIM7_IRQn                   = 55,     /*!< TIM7 中断                                       */  
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 通道 1 全局中断                      */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 通道 2 全局中断                      */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 通道 3 全局中断                      */
  DMA2_Channel4_5_IRQn        = 59,     /*!< DMA2 通道 4 和通道 5 全局中断        */
  DMA2_Channel5_IRQn          = 60      /*!< DMA2 通道 5 全局中断（DMA2 通道 5 
                                             仅当 AFIO_MAPR2 寄存器中的 MISC_REMAP 
                                             位被置位时才映射到位置 60）                      */       
#endif /* STM32F10X_HD_VL */

#ifdef STM32F10X_XL
  ADC1_2_IRQn                 = 18,     /*!< ADC1 和 ADC2 全局中断                       */
  USB_HP_CAN1_TX_IRQn         = 19,     /*!< USB 设备高优先级或 CAN1 发送中断       */
  USB_LP_CAN1_RX0_IRQn        = 20,     /*!< USB 设备低优先级或 CAN1 接收 0 中断       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 接收 1 中断                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 状态改变错误中断                                   */
  EXTI9_5_IRQn                = 23,     /*!< 外部线 [9:5] 中断                        */
  TIM1_BRK_TIM9_IRQn          = 24,     /*!< TIM1 刹车中断和 TIM9 全局中断       */
  TIM1_UP_TIM10_IRQn          = 25,     /*!< TIM1 更新中断和 TIM10 全局中断     */
  TIM1_TRG_COM_TIM11_IRQn     = 26,     /*!< TIM1 触发和换相中断及 TIM11 全局中断 */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 输入捕获/输出比较中断                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 全局中断                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 全局中断                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 全局中断                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 事件中断                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 错误中断                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 事件中断                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 错误中断                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 全局中断                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 全局中断                                */
  USART1_IRQn                 = 37,     /*!< USART1 全局中断                              */
  USART2_IRQn                 = 38,     /*!< USART2 全局中断                              */
  USART3_IRQn                 = 39,     /*!< USART3 全局中断                              */
  EXTI15_10_IRQn              = 40,     /*!< 外部线 [15:10] 中断                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC 闹钟通过 EXTI 线中断                */
  USBWakeUp_IRQn              = 42,     /*!< USB 设备通过 EXTI 线从挂起唤醒中断 */
  TIM8_BRK_TIM12_IRQn         = 43,     /*!< TIM8 刹车中断和 TIM12 全局中断      */
  TIM8_UP_TIM13_IRQn          = 44,     /*!< TIM8 更新中断和 TIM13 全局中断     */
  TIM8_TRG_COM_TIM14_IRQn     = 45,     /*!< TIM8 触发和换相中断及 TIM14 全局中断 */
  TIM8_CC_IRQn                = 46,     /*!< TIM8 输入捕获/输出比较中断                       */
  ADC3_IRQn                   = 47,     /*!< ADC3 全局中断                                */
  FSMC_IRQn                   = 48,     /*!< FSMC 全局中断                                */
  SDIO_IRQn                   = 49,     /*!< SDIO 全局中断                                */
  TIM5_IRQn                   = 50,     /*!< TIM5 全局中断                                */
  SPI3_IRQn                   = 51,     /*!< SPI3 全局中断                                */
  UART4_IRQn                  = 52,     /*!< UART4 全局中断                               */
  UART5_IRQn                  = 53,     /*!< UART5 全局中断                               */
  TIM6_IRQn                   = 54,     /*!< TIM6 全局中断                                */
  TIM7_IRQn                   = 55,     /*!< TIM7 全局中断                                */
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 通道 1 全局中断                      */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 通道 2 全局中断                      */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 通道 3 全局中断                      */
  DMA2_Channel4_5_IRQn        = 59      /*!< DMA2 通道 4 和通道 5 全局中断        */
#endif /* STM32F10X_XL */  

#ifdef STM32F10X_CL
  ADC1_2_IRQn                 = 18,     /*!< ADC1 和 ADC2 全局中断                       */
  CAN1_TX_IRQn                = 19,     /*!< USB 设备高优先级或 CAN1 发送中断       */
  CAN1_RX0_IRQn               = 20,     /*!< USB 设备低优先级或 CAN1 接收 0 中断       */
  CAN1_RX1_IRQn               = 21,     /*!< CAN1 接收 1 中断                                   */
  CAN1_SCE_IRQn               = 22,     /*!< CAN1 状态改变错误中断                                   */
  EXTI9_5_IRQn                = 23,     /*!< 外部线 [9:5] 中断                        */
  TIM1_BRK_IRQn               = 24,     /*!< TIM1 刹车中断                                 */
  TIM1_UP_IRQn                = 25,     /*!< TIM1 更新中断                                */
  TIM1_TRG_COM_IRQn           = 26,     /*!< TIM1 触发和换相中断               */
  TIM1_CC_IRQn                = 27,     /*!< TIM1 输入捕获/输出比较中断                       */
  TIM2_IRQn                   = 28,     /*!< TIM2 全局中断                                */
  TIM3_IRQn                   = 29,     /*!< TIM3 全局中断                                */
  TIM4_IRQn                   = 30,     /*!< TIM4 全局中断                                */
  I2C1_EV_IRQn                = 31,     /*!< I2C1 事件中断                                 */
  I2C1_ER_IRQn                = 32,     /*!< I2C1 错误中断                                 */
  I2C2_EV_IRQn                = 33,     /*!< I2C2 事件中断                                 */
  I2C2_ER_IRQn                = 34,     /*!< I2C2 错误中断                                 */
  SPI1_IRQn                   = 35,     /*!< SPI1 全局中断                                */
  SPI2_IRQn                   = 36,     /*!< SPI2 全局中断                                */
  USART1_IRQn                 = 37,     /*!< USART1 全局中断                              */
  USART2_IRQn                 = 38,     /*!< USART2 全局中断                              */
  USART3_IRQn                 = 39,     /*!< USART3 全局中断                              */
  EXTI15_10_IRQn              = 40,     /*!< 外部线 [15:10] 中断                      */
  RTCAlarm_IRQn               = 41,     /*!< RTC 闹钟通过 EXTI 线中断                */
  OTG_FS_WKUP_IRQn            = 42,     /*!< USB OTG FS 通过 EXTI 线从挂起唤醒中断 */
  TIM5_IRQn                   = 50,     /*!< TIM5 全局中断                                */
  SPI3_IRQn                   = 51,     /*!< SPI3 全局中断                                */
  UART4_IRQn                  = 52,     /*!< UART4 全局中断                               */
  UART5_IRQn                  = 53,     /*!< UART5 全局中断                               */
  TIM6_IRQn                   = 54,     /*!< TIM6 全局中断                                */
  TIM7_IRQn                   = 55,     /*!< TIM7 全局中断                                */
  DMA2_Channel1_IRQn          = 56,     /*!< DMA2 通道 1 全局中断                      */
  DMA2_Channel2_IRQn          = 57,     /*!< DMA2 通道 2 全局中断                      */
  DMA2_Channel3_IRQn          = 58,     /*!< DMA2 通道 3 全局中断                      */
  DMA2_Channel4_IRQn          = 59,     /*!< DMA2 通道 4 全局中断                      */
  DMA2_Channel5_IRQn          = 60,     /*!< DMA2 通道 5 全局中断                      */
  ETH_IRQn                    = 61,     /*!< 以太网全局中断                            */
  ETH_WKUP_IRQn               = 62,     /*!< 以太网通过 EXTI 线唤醒中断          */
  CAN2_TX_IRQn                = 63,     /*!< CAN2 发送中断                                    */
  CAN2_RX0_IRQn               = 64,     /*!< CAN2 接收 0 中断                                   */
  CAN2_RX1_IRQn               = 65,     /*!< CAN2 接收 1 中断                                   */
  CAN2_SCE_IRQn               = 66,     /*!< CAN2 状态改变错误中断                                   */
  OTG_FS_IRQn                 = 67      /*!< USB OTG FS 全局中断                          */
#endif /* STM32F10X_CL */     
} IRQn_Type;

/**
  * @}
  */

#include "core_cm3.h"
#include "system_stm32f10x.h"
#include <stdint.h>

/** @addtogroup Exported_types
  * @{
  */  

/*!< STM32F10x 标准外设库旧类型（为兼容性保留） */
typedef int32_t  s32;
typedef int16_t s16;
typedef int8_t  s8;

typedef const int32_t sc32;  /*!< 只读 */
typedef const int16_t sc16;  /*!< 只读 */
typedef const int8_t sc8;   /*!< 只读 */

typedef __IO int32_t  vs32;
typedef __IO int16_t  vs16;
typedef __IO int8_t   vs8;

typedef __I int32_t vsc32;  /*!< 只读 */
typedef __I int16_t vsc16;  /*!< 只读 */
typedef __I int8_t vsc8;   /*!< 只读 */

typedef uint32_t  u32;
typedef uint16_t u16;
typedef uint8_t  u8;

typedef const uint32_t uc32;  /*!< 只读 */
typedef const uint16_t uc16;  /*!< 只读 */
typedef const uint8_t uc8;   /*!< 只读 */

typedef __IO uint32_t  vu32;
typedef __IO uint16_t vu16;
typedef __IO uint8_t  vu8;

typedef __I uint32_t vuc32;  /*!< 只读 */
typedef __I uint16_t vuc16;  /*!< 只读 */
typedef __I uint8_t vuc8;   /*!< 只读 */

typedef enum {RESET = 0, SET = !RESET} FlagStatus, ITStatus;

typedef enum {DISABLE = 0, ENABLE = !DISABLE} FunctionalState;
#define IS_FUNCTIONAL_STATE(STATE) (((STATE) == DISABLE) || ((STATE) == ENABLE))

typedef enum {ERROR = 0, SUCCESS = !ERROR} ErrorStatus;

/*!< STM32F10x 标准外设库旧定义（为兼容性保留） */
#define HSEStartUp_TimeOut   HSE_STARTUP_TIMEOUT
#define HSE_Value            HSE_VALUE
#define HSI_Value            HSI_VALUE
/**
  * @}
  */

/** @addtogroup Peripheral_registers_structures
  * @{
  */   

/** 
  * @brief 模数转换器  
  */

typedef struct
{
  __IO uint32_t SR;
  __IO uint32_t CR1;
  __IO uint32_t CR2;
  __IO uint32_t SMPR1;
  __IO uint32_t SMPR2;
  __IO uint32_t JOFR1;
  __IO uint32_t JOFR2;
  __IO uint32_t JOFR3;
  __IO uint32_t JOFR4;
  __IO uint32_t HTR;
  __IO uint32_t LTR;
  __IO uint32_t SQR1;
  __IO uint32_t SQR2;
  __IO uint32_t SQR3;
  __IO uint32_t JSQR;
  __IO uint32_t JDR1;
  __IO uint32_t JDR2;
  __IO uint32_t JDR3;
  __IO uint32_t JDR4;
  __IO uint32_t DR;
} ADC_TypeDef;

/** 
  * @brief 备份寄存器  
  */

typedef struct
{
  uint32_t  RESERVED0;
  __IO uint16_t DR1;
  uint16_t  RESERVED1;
  __IO uint16_t DR2;
  uint16_t  RESERVED2;
  __IO uint16_t DR3;
  uint16_t  RESERVED3;
  __IO uint16_t DR4;
  uint16_t  RESERVED4;
  __IO uint16_t DR5;
  uint16_t  RESERVED5;
  __IO uint16_t DR6;
  uint16_t  RESERVED6;
  __IO uint16_t DR7;
  uint16_t  RESERVED7;
  __IO uint16_t DR8;
  uint16_t  RESERVED8;
  __IO uint16_t DR9;
  uint16_t  RESERVED9;
  __IO uint16_t DR10;
  uint16_t  RESERVED10; 
  __IO uint16_t RTCCR;
  uint16_t  RESERVED11;
  __IO uint16_t CR;
  uint16_t  RESERVED12;
  __IO uint16_t CSR;
  uint16_t  RESERVED13[5];
  __IO uint16_t DR11;
  uint16_t  RESERVED14;
  __IO uint16_t DR12;
  uint16_t  RESERVED15;
  __IO uint16_t DR13;
  uint16_t  RESERVED16;
  __IO uint16_t DR14;
  uint16_t  RESERVED17;
  __IO uint16_t DR15;
  uint16_t  RESERVED18;
  __IO uint16_t DR16;
  uint16_t  RESERVED19;
  __IO uint16_t DR17;
  uint16_t  RESERVED20;
  __IO uint16_t DR18;
  uint16_t  RESERVED21;
  __IO uint16_t DR19;
  uint16_t  RESERVED22;
  __IO uint16_t DR20;
  uint16_t  RESERVED23;
  __IO uint16_t DR21;
  uint16_t  RESERVED24;
  __IO uint16_t DR22;
  uint16_t  RESERVED25;
  __IO uint16_t DR23;
  uint16_t  RESERVED26;
  __IO uint16_t DR24;
  uint16_t  RESERVED27;
  __IO uint16_t DR25;
  uint16_t  RESERVED28;
  __IO uint16_t DR26;
  uint16_t  RESERVED29;
  __IO uint16_t DR27;
  uint16_t  RESERVED30;
  __IO uint16_t DR28;
  uint16_t  RESERVED31;
  __IO uint16_t DR29;
  uint16_t  RESERVED32;
  __IO uint16_t DR30;
  uint16_t  RESERVED33; 
  __IO uint16_t DR31;
  uint16_t  RESERVED34;
  __IO uint16_t DR32;
  uint16_t  RESERVED35;
  __IO uint16_t DR33;
  uint16_t  RESERVED36;
  __IO uint16_t DR34;
  uint16_t  RESERVED37;
  __IO uint16_t DR35;
  uint16_t  RESERVED38;
  __IO uint16_t DR36;
  uint16_t  RESERVED39;
  __IO uint16_t DR37;
  uint16_t  RESERVED40;
  __IO uint16_t DR38;
  uint16_t  RESERVED41;
  __IO uint16_t DR39;
  uint16_t  RESERVED42;
  __IO uint16_t DR40;
  uint16_t  RESERVED43;
  __IO uint16_t DR41;
  uint16_t  RESERVED44;
  __IO uint16_t DR42;
  uint16_t  RESERVED45;    
} BKP_TypeDef;
  
/** 
  * @brief 控制器局域网发送邮箱 
  */

typedef struct
{
  __IO uint32_t TIR;
  __IO uint32_t TDTR;
  __IO uint32_t TDLR;
  __IO uint32_t TDHR;
} CAN_TxMailBox_TypeDef;

/** 
  * @brief 控制器局域网 FIFO 邮箱 
  */
  
typedef struct
{
  __IO uint32_t RIR;
  __IO uint32_t RDTR;
  __IO uint32_t RDLR;
  __IO uint32_t RDHR;
} CAN_FIFOMailBox_TypeDef;

/** 
  * @brief 控制器局域网过滤器寄存器 
  */
  
typedef struct
{
  __IO uint32_t FR1;
  __IO uint32_t FR2;
} CAN_FilterRegister_TypeDef;

/** 
  * @brief 控制器局域网 
  */
  
typedef struct
{
  __IO uint32_t MCR;
  __IO uint32_t MSR;
  __IO uint32_t TSR;
  __IO uint32_t RF0R;
  __IO uint32_t RF1R;
  __IO uint32_t IER;
  __IO uint32_t ESR;
  __IO uint32_t BTR;
  uint32_t  RESERVED0[88];
  CAN_TxMailBox_TypeDef sTxMailBox[3];
  CAN_FIFOMailBox_TypeDef sFIFOMailBox[2];
  uint32_t  RESERVED1[12];
  __IO uint32_t FMR;
  __IO uint32_t FM1R;
  uint32_t  RESERVED2;
  __IO uint32_t FS1R;
  uint32_t  RESERVED3;
  __IO uint32_t FFA1R;
  uint32_t  RESERVED4;
  __IO uint32_t FA1R;
  uint32_t  RESERVED5[8];
#ifndef STM32F10X_CL
  CAN_FilterRegister_TypeDef sFilterRegister[14];
#else
  CAN_FilterRegister_TypeDef sFilterRegister[28];
#endif /* STM32F10X_CL */  
} CAN_TypeDef;

/** 
  * @brief 消费电子控制（CEC）
  */
typedef struct
{
  __IO uint32_t CFGR;
  __IO uint32_t OAR;
  __IO uint32_t PRES;
  __IO uint32_t ESR;
  __IO uint32_t CSR;
  __IO uint32_t TXD;
  __IO uint32_t RXD;  
} CEC_TypeDef;

/** 
  * @brief CRC 计算单元 
  */

typedef struct
{
  __IO uint32_t DR;
  __IO uint8_t  IDR;
  uint8_t   RESERVED0;
  uint16_t  RESERVED1;
  __IO uint32_t CR;
} CRC_TypeDef;

/** 
  * @brief 数模转换器
  */

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t SWTRIGR;
  __IO uint32_t DHR12R1;
  __IO uint32_t DHR12L1;
  __IO uint32_t DHR8R1;
  __IO uint32_t DHR12R2;
  __IO uint32_t DHR12L2;
  __IO uint32_t DHR8R2;
  __IO uint32_t DHR12RD;
  __IO uint32_t DHR12LD;
  __IO uint32_t DHR8RD;
  __IO uint32_t DOR1;
  __IO uint32_t DOR2;
#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
  __IO uint32_t SR;
#endif
} DAC_TypeDef;

/** 
  * @brief 调试 MCU
  */

typedef struct
{
  __IO uint32_t IDCODE;
  __IO uint32_t CR;	
}DBGMCU_TypeDef;

/** 
  * @brief DMA 控制器
  */

typedef struct
{
  __IO uint32_t CCR;
  __IO uint32_t CNDTR;
  __IO uint32_t CPAR;
  __IO uint32_t CMAR;
} DMA_Channel_TypeDef;

typedef struct
{
  __IO uint32_t ISR;
  __IO uint32_t IFCR;
} DMA_TypeDef;

/** 
  * @brief 以太网 MAC
  */

typedef struct
{
  __IO uint32_t MACCR;
  __IO uint32_t MACFFR;
  __IO uint32_t MACHTHR;
  __IO uint32_t MACHTLR;
  __IO uint32_t MACMIIAR;
  __IO uint32_t MACMIIDR;
  __IO uint32_t MACFCR;
  __IO uint32_t MACVLANTR;             /*    8 */
       uint32_t RESERVED0[2];
  __IO uint32_t MACRWUFFR;             /*   11 */
  __IO uint32_t MACPMTCSR;
       uint32_t RESERVED1[2];
  __IO uint32_t MACSR;                 /*   15 */
  __IO uint32_t MACIMR;
  __IO uint32_t MACA0HR;
  __IO uint32_t MACA0LR;
  __IO uint32_t MACA1HR;
  __IO uint32_t MACA1LR;
  __IO uint32_t MACA2HR;
  __IO uint32_t MACA2LR;
  __IO uint32_t MACA3HR;
  __IO uint32_t MACA3LR;               /*   24 */
       uint32_t RESERVED2[40];
  __IO uint32_t MMCCR;                 /*   65 */
  __IO uint32_t MMCRIR;
  __IO uint32_t MMCTIR;
  __IO uint32_t MMCRIMR;
  __IO uint32_t MMCTIMR;               /*   69 */
       uint32_t RESERVED3[14];
  __IO uint32_t MMCTGFSCCR;            /*   84 */
  __IO uint32_t MMCTGFMSCCR;
       uint32_t RESERVED4[5];
  __IO uint32_t MMCTGFCR;
       uint32_t RESERVED5[10];
  __IO uint32_t MMCRFCECR;
  __IO uint32_t MMCRFAECR;
       uint32_t RESERVED6[10];
  __IO uint32_t MMCRGUFCR;
       uint32_t RESERVED7[334];
  __IO uint32_t PTPTSCR;
  __IO uint32_t PTPSSIR;
  __IO uint32_t PTPTSHR;
  __IO uint32_t PTPTSLR;
  __IO uint32_t PTPTSHUR;
  __IO uint32_t PTPTSLUR;
  __IO uint32_t PTPTSAR;
  __IO uint32_t PTPTTHR;
  __IO uint32_t PTPTTLR;
       uint32_t RESERVED8[567];
  __IO uint32_t DMABMR;
  __IO uint32_t DMATPDR;
  __IO uint32_t DMARPDR;
  __IO uint32_t DMARDLAR;
  __IO uint32_t DMATDLAR;
  __IO uint32_t DMASR;
  __IO uint32_t DMAOMR;
  __IO uint32_t DMAIER;
  __IO uint32_t DMAMFBOCR;
       uint32_t RESERVED9[9];
  __IO uint32_t DMACHTDR;
  __IO uint32_t DMACHRDR;
  __IO uint32_t DMACHTBAR;
  __IO uint32_t DMACHRBAR;
} ETH_TypeDef;

/** 
  * @brief 外部中断/事件控制器
  */

typedef struct
{
  __IO uint32_t IMR;
  __IO uint32_t EMR;
  __IO uint32_t RTSR;
  __IO uint32_t FTSR;
  __IO uint32_t SWIER;
  __IO uint32_t PR;
} EXTI_TypeDef;

/** 
  * @brief 闪存寄存器
  */

typedef struct
{
  __IO uint32_t ACR;
  __IO uint32_t KEYR;
  __IO uint32_t OPTKEYR;
  __IO uint32_t SR;
  __IO uint32_t CR;
  __IO uint32_t AR;
  __IO uint32_t RESERVED;
  __IO uint32_t OBR;
  __IO uint32_t WRPR;
#ifdef STM32F10X_XL
  uint32_t RESERVED1[8]; 
  __IO uint32_t KEYR2;
  uint32_t RESERVED2;   
  __IO uint32_t SR2;
  __IO uint32_t CR2;
  __IO uint32_t AR2; 
#endif /* STM32F10X_XL */  
} FLASH_TypeDef;

/** 
  * @brief 选项字节寄存器
  */
  
typedef struct
{
  __IO uint16_t RDP;
  __IO uint16_t USER;
  __IO uint16_t Data0;
  __IO uint16_t Data1;
  __IO uint16_t WRP0;
  __IO uint16_t WRP1;
  __IO uint16_t WRP2;
  __IO uint16_t WRP3;
} OB_TypeDef;

/** 
  * @brief 灵活的静态存储器控制器
  */

typedef struct
{
  __IO uint32_t BTCR[8];   
} FSMC_Bank1_TypeDef; 

/** 
  * @brief 灵活的静态存储器控制器 Bank1E
  */
  
typedef struct
{
  __IO uint32_t BWTR[7];
} FSMC_Bank1E_TypeDef;

/** 
  * @brief 灵活的静态存储器控制器 Bank2
  */
  
typedef struct
{
  __IO uint32_t PCR2;
  __IO uint32_t SR2;
  __IO uint32_t PMEM2;
  __IO uint32_t PATT2;
  uint32_t  RESERVED0;   
  __IO uint32_t ECCR2; 
} FSMC_Bank2_TypeDef;  

/** 
  * @brief 灵活的静态存储器控制器 Bank3
  */
  
typedef struct
{
  __IO uint32_t PCR3;
  __IO uint32_t SR3;
  __IO uint32_t PMEM3;
  __IO uint32_t PATT3;
  uint32_t  RESERVED0;   
  __IO uint32_t ECCR3; 
} FSMC_Bank3_TypeDef; 

/** 
  * @brief 灵活的静态存储器控制器 Bank4
  */
  
typedef struct
{
  __IO uint32_t PCR4;
  __IO uint32_t SR4;
  __IO uint32_t PMEM4;
  __IO uint32_t PATT4;
  __IO uint32_t PIO4; 
} FSMC_Bank4_TypeDef; 

/** 
  * @brief 通用输入/输出
  */

typedef struct
{
  __IO uint32_t CRL;
  __IO uint32_t CRH;
  __IO uint32_t IDR;
  __IO uint32_t ODR;
  __IO uint32_t BSRR;
  __IO uint32_t BRR;
  __IO uint32_t LCKR;
} GPIO_TypeDef;

/** 
  * @brief 复用功能 I/O
  */

typedef struct
{
  __IO uint32_t EVCR;
  __IO uint32_t MAPR;
  __IO uint32_t EXTICR[4];
  uint32_t RESERVED0;
  __IO uint32_t MAPR2;  
} AFIO_TypeDef;
/** 
  * @brief 内部集成电路接口
  */

typedef struct
{
  __IO uint16_t CR1;
  uint16_t  RESERVED0;
  __IO uint16_t CR2;
  uint16_t  RESERVED1;
  __IO uint16_t OAR1;
  uint16_t  RESERVED2;
  __IO uint16_t OAR2;
  uint16_t  RESERVED3;
  __IO uint16_t DR;
  uint16_t  RESERVED4;
  __IO uint16_t SR1;
  uint16_t  RESERVED5;
  __IO uint16_t SR2;
  uint16_t  RESERVED6;
  __IO uint16_t CCR;
  uint16_t  RESERVED7;
  __IO uint16_t TRISE;
  uint16_t  RESERVED8;
} I2C_TypeDef;

/** 
  * @brief 独立看门狗
  */

typedef struct
{
  __IO uint32_t KR;
  __IO uint32_t PR;
  __IO uint32_t RLR;
  __IO uint32_t SR;
} IWDG_TypeDef;

/** 
  * @brief 电源控制
  */

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CSR;
} PWR_TypeDef;

/** 
  * @brief 复位和时钟控制
  */

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFGR;
  __IO uint32_t CIR;
  __IO uint32_t APB2RSTR;
  __IO uint32_t APB1RSTR;
  __IO uint32_t AHBENR;
  __IO uint32_t APB2ENR;
  __IO uint32_t APB1ENR;
  __IO uint32_t BDCR;
  __IO uint32_t CSR;

#ifdef STM32F10X_CL  
  __IO uint32_t AHBRSTR;
  __IO uint32_t CFGR2;
#endif /* STM32F10X_CL */ 

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)   
  uint32_t RESERVED0;
  __IO uint32_t CFGR2;
#endif /* STM32F10X_LD_VL || STM32F10X_MD_VL || STM32F10X_HD_VL */ 
} RCC_TypeDef;

/** 
  * @brief 实时时钟
  */

typedef struct
{
  __IO uint16_t CRH;
  uint16_t  RESERVED0;
  __IO uint16_t CRL;
  uint16_t  RESERVED1;
  __IO uint16_t PRLH;
  uint16_t  RESERVED2;
  __IO uint16_t PRLL;
  uint16_t  RESERVED3;
  __IO uint16_t DIVH;
  uint16_t  RESERVED4;
  __IO uint16_t DIVL;
  uint16_t  RESERVED5;
  __IO uint16_t CNTH;
  uint16_t  RESERVED6;
  __IO uint16_t CNTL;
  uint16_t  RESERVED7;
  __IO uint16_t ALRH;
  uint16_t  RESERVED8;
  __IO uint16_t ALRL;
  uint16_t  RESERVED9;
} RTC_TypeDef;

/** 
  * @brief SD 主机接口
  */

typedef struct
{
  __IO uint32_t POWER;
  __IO uint32_t CLKCR;
  __IO uint32_t ARG;
  __IO uint32_t CMD;
  __I uint32_t RESPCMD;
  __I uint32_t RESP1;
  __I uint32_t RESP2;
  __I uint32_t RESP3;
  __I uint32_t RESP4;
  __IO uint32_t DTIMER;
  __IO uint32_t DLEN;
  __IO uint32_t DCTRL;
  __I uint32_t DCOUNT;
  __I uint32_t STA;
  __IO uint32_t ICR;
  __IO uint32_t MASK;
  uint32_t  RESERVED0[2];
  __I uint32_t FIFOCNT;
  uint32_t  RESERVED1[13];
  __IO uint32_t FIFO;
} SDIO_TypeDef;

/** 
  * @brief 串行外设接口
  */

typedef struct
{
  __IO uint16_t CR1;
  uint16_t  RESERVED0;
  __IO uint16_t CR2;
  uint16_t  RESERVED1;
  __IO uint16_t SR;
  uint16_t  RESERVED2;
  __IO uint16_t DR;
  uint16_t  RESERVED3;
  __IO uint16_t CRCPR;
  uint16_t  RESERVED4;
  __IO uint16_t RXCRCR;
  uint16_t  RESERVED5;
  __IO uint16_t TXCRCR;
  uint16_t  RESERVED6;
  __IO uint16_t I2SCFGR;
  uint16_t  RESERVED7;
  __IO uint16_t I2SPR;
  uint16_t  RESERVED8;  
} SPI_TypeDef;

/** 
  * @brief 定时器
  */

typedef struct
{
  __IO uint16_t CR1;
  uint16_t  RESERVED0;
  __IO uint16_t CR2;
  uint16_t  RESERVED1;
  __IO uint16_t SMCR;
  uint16_t  RESERVED2;
  __IO uint16_t DIER;
  uint16_t  RESERVED3;
  __IO uint16_t SR;
  uint16_t  RESERVED4;
  __IO uint16_t EGR;
  uint16_t  RESERVED5;
  __IO uint16_t CCMR1;
  uint16_t  RESERVED6;
  __IO uint16_t CCMR2;
  uint16_t  RESERVED7;
  __IO uint16_t CCER;
  uint16_t  RESERVED8;
  __IO uint16_t CNT;
  uint16_t  RESERVED9;
  __IO uint16_t PSC;
  uint16_t  RESERVED10;
  __IO uint16_t ARR;
  uint16_t  RESERVED11;
  __IO uint16_t RCR;
  uint16_t  RESERVED12;
  __IO uint16_t CCR1;
  uint16_t  RESERVED13;
  __IO uint16_t CCR2;
  uint16_t  RESERVED14;
  __IO uint16_t CCR3;
  uint16_t  RESERVED15;
  __IO uint16_t CCR4;
  uint16_t  RESERVED16;
  __IO uint16_t BDTR;
  uint16_t  RESERVED17;
  __IO uint16_t DCR;
  uint16_t  RESERVED18;
  __IO uint16_t DMAR;
  uint16_t  RESERVED19;
} TIM_TypeDef;

/** 
  * @brief 通用同步异步收发器
  */
 
typedef struct
{
  __IO uint16_t SR;
  uint16_t  RESERVED0;
  __IO uint16_t DR;
  uint16_t  RESERVED1;
  __IO uint16_t BRR;
  uint16_t  RESERVED2;
  __IO uint16_t CR1;
  uint16_t  RESERVED3;
  __IO uint16_t CR2;
  uint16_t  RESERVED4;
  __IO uint16_t CR3;
  uint16_t  RESERVED5;
  __IO uint16_t GTPR;
  uint16_t  RESERVED6;
} USART_TypeDef;

/** 
  * @brief 窗口看门狗
  */

typedef struct
{
  __IO uint32_t CR;
  __IO uint32_t CFR;
  __IO uint32_t SR;
} WWDG_TypeDef;

/**
  * @}
  */
  
/** @addtogroup Peripheral_memory_map
  * @{
  */


#define FLASH_BASE            ((uint32_t)0x08000000) /*!< 别名区中的 FLASH 基地址 */
#define SRAM_BASE             ((uint32_t)0x20000000) /*!< 别名区中的 SRAM 基地址 */
#define PERIPH_BASE           ((uint32_t)0x40000000) /*!< 别名区中的外设基地址 */

#define SRAM_BB_BASE          ((uint32_t)0x22000000) /*!< 位带区中的 SRAM 基地址 */
#define PERIPH_BB_BASE        ((uint32_t)0x42000000) /*!< 位带区中的外设基地址 */

#define FSMC_R_BASE           ((uint32_t)0xA0000000) /*!< FSMC 寄存器基地址 */

/*!< 外设存储器映射 */
#define APB1PERIPH_BASE       PERIPH_BASE
#define APB2PERIPH_BASE       (PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE        (PERIPH_BASE + 0x20000)

#define TIM2_BASE             (APB1PERIPH_BASE + 0x0000)
#define TIM3_BASE             (APB1PERIPH_BASE + 0x0400)
#define TIM4_BASE             (APB1PERIPH_BASE + 0x0800)
#define TIM5_BASE             (APB1PERIPH_BASE + 0x0C00)
#define TIM6_BASE             (APB1PERIPH_BASE + 0x1000)
#define TIM7_BASE             (APB1PERIPH_BASE + 0x1400)
#define TIM12_BASE            (APB1PERIPH_BASE + 0x1800)
#define TIM13_BASE            (APB1PERIPH_BASE + 0x1C00)
#define TIM14_BASE            (APB1PERIPH_BASE + 0x2000)
#define RTC_BASE              (APB1PERIPH_BASE + 0x2800)
#define WWDG_BASE             (APB1PERIPH_BASE + 0x2C00)
#define IWDG_BASE             (APB1PERIPH_BASE + 0x3000)
#define SPI2_BASE             (APB1PERIPH_BASE + 0x3800)
#define SPI3_BASE             (APB1PERIPH_BASE + 0x3C00)
#define USART2_BASE           (APB1PERIPH_BASE + 0x4400)
#define USART3_BASE           (APB1PERIPH_BASE + 0x4800)
#define UART4_BASE            (APB1PERIPH_BASE + 0x4C00)
#define UART5_BASE            (APB1PERIPH_BASE + 0x5000)
#define I2C1_BASE             (APB1PERIPH_BASE + 0x5400)
#define I2C2_BASE             (APB1PERIPH_BASE + 0x5800)
#define CAN1_BASE             (APB1PERIPH_BASE + 0x6400)
#define CAN2_BASE             (APB1PERIPH_BASE + 0x6800)
#define BKP_BASE              (APB1PERIPH_BASE + 0x6C00)
#define PWR_BASE              (APB1PERIPH_BASE + 0x7000)
#define DAC_BASE              (APB1PERIPH_BASE + 0x7400)
#define CEC_BASE              (APB1PERIPH_BASE + 0x7800)

#define AFIO_BASE             (APB2PERIPH_BASE + 0x0000)
#define EXTI_BASE             (APB2PERIPH_BASE + 0x0400)
#define GPIOA_BASE            (APB2PERIPH_BASE + 0x0800)
#define GPIOB_BASE            (APB2PERIPH_BASE + 0x0C00)
#define GPIOC_BASE            (APB2PERIPH_BASE + 0x1000)
#define GPIOD_BASE            (APB2PERIPH_BASE + 0x1400)
#define GPIOE_BASE            (APB2PERIPH_BASE + 0x1800)
#define GPIOF_BASE            (APB2PERIPH_BASE + 0x1C00)
#define GPIOG_BASE            (APB2PERIPH_BASE + 0x2000)
#define ADC1_BASE             (APB2PERIPH_BASE + 0x2400)
#define ADC2_BASE             (APB2PERIPH_BASE + 0x2800)
#define TIM1_BASE             (APB2PERIPH_BASE + 0x2C00)
#define SPI1_BASE             (APB2PERIPH_BASE + 0x3000)
#define TIM8_BASE             (APB2PERIPH_BASE + 0x3400)
#define USART1_BASE           (APB2PERIPH_BASE + 0x3800)
#define ADC3_BASE             (APB2PERIPH_BASE + 0x3C00)
#define TIM15_BASE            (APB2PERIPH_BASE + 0x4000)
#define TIM16_BASE            (APB2PERIPH_BASE + 0x4400)
#define TIM17_BASE            (APB2PERIPH_BASE + 0x4800)
#define TIM9_BASE             (APB2PERIPH_BASE + 0x4C00)
#define TIM10_BASE            (APB2PERIPH_BASE + 0x5000)
#define TIM11_BASE            (APB2PERIPH_BASE + 0x5400)

#define SDIO_BASE             (PERIPH_BASE + 0x18000)

#define DMA1_BASE             (AHBPERIPH_BASE + 0x0000)
#define DMA1_Channel1_BASE    (AHBPERIPH_BASE + 0x0008)
#define DMA1_Channel2_BASE    (AHBPERIPH_BASE + 0x001C)
#define DMA1_Channel3_BASE    (AHBPERIPH_BASE + 0x0030)
#define DMA1_Channel4_BASE    (AHBPERIPH_BASE + 0x0044)
#define DMA1_Channel5_BASE    (AHBPERIPH_BASE + 0x0058)
#define DMA1_Channel6_BASE    (AHBPERIPH_BASE + 0x006C)
#define DMA1_Channel7_BASE    (AHBPERIPH_BASE + 0x0080)
#define DMA2_BASE             (AHBPERIPH_BASE + 0x0400)
#define DMA2_Channel1_BASE    (AHBPERIPH_BASE + 0x0408)
#define DMA2_Channel2_BASE    (AHBPERIPH_BASE + 0x041C)
#define DMA2_Channel3_BASE    (AHBPERIPH_BASE + 0x0430)
#define DMA2_Channel4_BASE    (AHBPERIPH_BASE + 0x0444)
#define DMA2_Channel5_BASE    (AHBPERIPH_BASE + 0x0458)
#define RCC_BASE              (AHBPERIPH_BASE + 0x1000)
#define CRC_BASE              (AHBPERIPH_BASE + 0x3000)

#define FLASH_R_BASE          (AHBPERIPH_BASE + 0x2000) /*!< 闪存寄存器基地址 */
#define OB_BASE               ((uint32_t)0x1FFFF800)    /*!< 闪存选项字节基地址 */

#define ETH_BASE              (AHBPERIPH_BASE + 0x8000)
#define ETH_MAC_BASE          (ETH_BASE)
#define ETH_MMC_BASE          (ETH_BASE + 0x0100)
#define ETH_PTP_BASE          (ETH_BASE + 0x0700)
#define ETH_DMA_BASE          (ETH_BASE + 0x1000)

#define FSMC_Bank1_R_BASE     (FSMC_R_BASE + 0x0000) /*!< FSMC Bank1 寄存器基地址 */
#define FSMC_Bank1E_R_BASE    (FSMC_R_BASE + 0x0104) /*!< FSMC Bank1E 寄存器基地址 */
#define FSMC_Bank2_R_BASE     (FSMC_R_BASE + 0x0060) /*!< FSMC Bank2 寄存器基地址 */
#define FSMC_Bank3_R_BASE     (FSMC_R_BASE + 0x0080) /*!< FSMC Bank3 寄存器基地址 */
#define FSMC_Bank4_R_BASE     (FSMC_R_BASE + 0x00A0) /*!< FSMC Bank4 寄存器基地址 */

#define DBGMCU_BASE          ((uint32_t)0xE0042000) /*!< 调试 MCU 寄存器基地址 */

/**
  * @}
  */
  
/** @addtogroup Peripheral_declaration
  * @{
  */  

#define TIM2                ((TIM_TypeDef *) TIM2_BASE)
#define TIM3                ((TIM_TypeDef *) TIM3_BASE)
#define TIM4                ((TIM_TypeDef *) TIM4_BASE)
#define TIM5                ((TIM_TypeDef *) TIM5_BASE)
#define TIM6                ((TIM_TypeDef *) TIM6_BASE)
#define TIM7                ((TIM_TypeDef *) TIM7_BASE)
#define TIM12               ((TIM_TypeDef *) TIM12_BASE)
#define TIM13               ((TIM_TypeDef *) TIM13_BASE)
#define TIM14               ((TIM_TypeDef *) TIM14_BASE)
#define RTC                 ((RTC_TypeDef *) RTC_BASE)
#define WWDG                ((WWDG_TypeDef *) WWDG_BASE)
#define IWDG                ((IWDG_TypeDef *) IWDG_BASE)
#define SPI2                ((SPI_TypeDef *) SPI2_BASE)
#define SPI3                ((SPI_TypeDef *) SPI3_BASE)
#define USART2              ((USART_TypeDef *) USART2_BASE)
#define USART3              ((USART_TypeDef *) USART3_BASE)
#define UART4               ((USART_TypeDef *) UART4_BASE)
#define UART5               ((USART_TypeDef *) UART5_BASE)
#define I2C1                ((I2C_TypeDef *) I2C1_BASE)
#define I2C2                ((I2C_TypeDef *) I2C2_BASE)
#define CAN1                ((CAN_TypeDef *) CAN1_BASE)
#define CAN2                ((CAN_TypeDef *) CAN2_BASE)
#define BKP                 ((BKP_TypeDef *) BKP_BASE)
#define PWR                 ((PWR_TypeDef *) PWR_BASE)
#define DAC                 ((DAC_TypeDef *) DAC_BASE)
#define CEC                 ((CEC_TypeDef *) CEC_BASE)
#define AFIO                ((AFIO_TypeDef *) AFIO_BASE)
#define EXTI                ((EXTI_TypeDef *) EXTI_BASE)
#define GPIOA               ((GPIO_TypeDef *) GPIOA_BASE)
#define GPIOB               ((GPIO_TypeDef *) GPIOB_BASE)
#define GPIOC               ((GPIO_TypeDef *) GPIOC_BASE)
#define GPIOD               ((GPIO_TypeDef *) GPIOD_BASE)
#define GPIOE               ((GPIO_TypeDef *) GPIOE_BASE)
#define GPIOF               ((GPIO_TypeDef *) GPIOF_BASE)
#define GPIOG               ((GPIO_TypeDef *) GPIOG_BASE)
#define ADC1                ((ADC_TypeDef *) ADC1_BASE)
#define ADC2                ((ADC_TypeDef *) ADC2_BASE)
#define TIM1                ((TIM_TypeDef *) TIM1_BASE)
#define SPI1                ((SPI_TypeDef *) SPI1_BASE)
#define TIM8                ((TIM_TypeDef *) TIM8_BASE)
#define USART1              ((USART_TypeDef *) USART1_BASE)
#define ADC3                ((ADC_TypeDef *) ADC3_BASE)
#define TIM15               ((TIM_TypeDef *) TIM15_BASE)
#define TIM16               ((TIM_TypeDef *) TIM16_BASE)
#define TIM17               ((TIM_TypeDef *) TIM17_BASE)
#define TIM9                ((TIM_TypeDef *) TIM9_BASE)
#define TIM10               ((TIM_TypeDef *) TIM10_BASE)
#define TIM11               ((TIM_TypeDef *) TIM11_BASE)
#define SDIO                ((SDIO_TypeDef *) SDIO_BASE)
#define DMA1                ((DMA_TypeDef *) DMA1_BASE)
#define DMA2                ((DMA_TypeDef *) DMA2_BASE)
#define DMA1_Channel1       ((DMA_Channel_TypeDef *) DMA1_Channel1_BASE)
#define DMA1_Channel2       ((DMA_Channel_TypeDef *) DMA1_Channel2_BASE)
#define DMA1_Channel3       ((DMA_Channel_TypeDef *) DMA1_Channel3_BASE)
#define DMA1_Channel4       ((DMA_Channel_TypeDef *) DMA1_Channel4_BASE)
#define DMA1_Channel5       ((DMA_Channel_TypeDef *) DMA1_Channel5_BASE)
#define DMA1_Channel6       ((DMA_Channel_TypeDef *) DMA1_Channel6_BASE)
#define DMA1_Channel7       ((DMA_Channel_TypeDef *) DMA1_Channel7_BASE)
#define DMA2_Channel1       ((DMA_Channel_TypeDef *) DMA2_Channel1_BASE)
#define DMA2_Channel2       ((DMA_Channel_TypeDef *) DMA2_Channel2_BASE)
#define DMA2_Channel3       ((DMA_Channel_TypeDef *) DMA2_Channel3_BASE)
#define DMA2_Channel4       ((DMA_Channel_TypeDef *) DMA2_Channel4_BASE)
#define DMA2_Channel5       ((DMA_Channel_TypeDef *) DMA2_Channel5_BASE)
#define RCC                 ((RCC_TypeDef *) RCC_BASE)
#define CRC                 ((CRC_TypeDef *) CRC_BASE)
#define FLASH               ((FLASH_TypeDef *) FLASH_R_BASE)
#define OB                  ((OB_TypeDef *) OB_BASE) 
#define ETH                 ((ETH_TypeDef *) ETH_BASE)
#define FSMC_Bank1          ((FSMC_Bank1_TypeDef *) FSMC_Bank1_R_BASE)
#define FSMC_Bank1E         ((FSMC_Bank1E_TypeDef *) FSMC_Bank1E_R_BASE)
#define FSMC_Bank2          ((FSMC_Bank2_TypeDef *) FSMC_Bank2_R_BASE)
#define FSMC_Bank3          ((FSMC_Bank3_TypeDef *) FSMC_Bank3_R_BASE)
#define FSMC_Bank4          ((FSMC_Bank4_TypeDef *) FSMC_Bank4_R_BASE)
#define DBGMCU              ((DBGMCU_TypeDef *) DBGMCU_BASE)

/**
  * @}
  */

/** @addtogroup Exported_constants
  * @{
  */
  
  /** @addtogroup Peripheral_Registers_Bits_Definition
  * @{
  */
    
/******************************************************************************/
/*                         外设寄存器位定义               */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*                          CRC 计算单元                              */
/*                                                                            */
/******************************************************************************/

/******************* CRC_DR 寄存器的位定义 *****************/
#define  CRC_DR_DR                           ((uint32_t)0xFFFFFFFF) /*!< 数据寄存器位 */


/******************* CRC_IDR 寄存器的位定义 *****************/
#define  CRC_IDR_IDR                         ((uint8_t)0xFF)        /*!< 通用 8 位数据寄存器位 */


/******************** CRC_CR 寄存器的位定义 ******************/
#define  CRC_CR_RESET                        ((uint8_t)0x01)        /*!< RESET 位 */

/******************************************************************************/
/*                                                                            */
/*                             电源控制                                  */
/*                                                                            */
/******************************************************************************/

/******************** PWR_CR 寄存器的位定义 ******************/
#define  PWR_CR_LPDS                         ((uint16_t)0x0001)     /*!< 低功耗深度睡眠 */
#define  PWR_CR_PDDS                         ((uint16_t)0x0002)     /*!< 掉电深度睡眠 */
#define  PWR_CR_CWUF                         ((uint16_t)0x0004)     /*!< 清除唤醒标志位 */
#define  PWR_CR_CSBF                         ((uint16_t)0x0008)     /*!< 清除待机标志位 */
#define  PWR_CR_PVDE                         ((uint16_t)0x0010)     /*!< 电源电压检测器使能 */

#define  PWR_CR_PLS                          ((uint16_t)0x00E0)     /*!< PLS[2:0] 位（PVD 电平选择） */
#define  PWR_CR_PLS_0                        ((uint16_t)0x0020)     /*!< 位 0 */
#define  PWR_CR_PLS_1                        ((uint16_t)0x0040)     /*!< 位 1 */
#define  PWR_CR_PLS_2                        ((uint16_t)0x0080)     /*!< 位 2 */

/*!< PVD 电平配置 */
#define  PWR_CR_PLS_2V2                      ((uint16_t)0x0000)     /*!< PVD 电平 2.2V */
#define  PWR_CR_PLS_2V3                      ((uint16_t)0x0020)     /*!< PVD 电平 2.3V */
#define  PWR_CR_PLS_2V4                      ((uint16_t)0x0040)     /*!< PVD 电平 2.4V */
#define  PWR_CR_PLS_2V5                      ((uint16_t)0x0060)     /*!< PVD 电平 2.5V */
#define  PWR_CR_PLS_2V6                      ((uint16_t)0x0080)     /*!< PVD 电平 2.6V */
#define  PWR_CR_PLS_2V7                      ((uint16_t)0x00A0)     /*!< PVD 电平 2.7V */
#define  PWR_CR_PLS_2V8                      ((uint16_t)0x00C0)     /*!< PVD 电平 2.8V */
#define  PWR_CR_PLS_2V9                      ((uint16_t)0x00E0)     /*!< PVD 电平 2.9V */

#define  PWR_CR_DBP                          ((uint16_t)0x0100)     /*!< 失能备份域写保护 */


/******************* PWR_CSR 寄存器的位定义 *****************/
#define  PWR_CSR_WUF                         ((uint16_t)0x0001)     /*!< 唤醒标志位 */
#define  PWR_CSR_SBF                         ((uint16_t)0x0002)     /*!< 待机标志位 */
#define  PWR_CSR_PVDO                        ((uint16_t)0x0004)     /*!< PVD 输出 */
#define  PWR_CSR_EWUP                        ((uint16_t)0x0100)     /*!< 使能 WKUP 引脚 */

/******************************************************************************/
/*                                                                            */
/*                            备份寄存器                                */
/*                                                                            */
/******************************************************************************/

/******************* BKP_DR1 寄存器的位定义 *****************/
#define  BKP_DR1_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR2 寄存器的位定义 *****************/
#define  BKP_DR2_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR3 寄存器的位定义 *****************/
#define  BKP_DR3_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR4 寄存器的位定义 *****************/
#define  BKP_DR4_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR5 寄存器的位定义 *****************/
#define  BKP_DR5_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR6 寄存器的位定义 *****************/
#define  BKP_DR6_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR7 寄存器的位定义 *****************/
#define  BKP_DR7_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR8 寄存器的位定义 *****************/
#define  BKP_DR8_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR9 寄存器的位定义 *****************/
#define  BKP_DR9_D                           ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR10 寄存器的位定义 *****************/
#define  BKP_DR10_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR11 寄存器的位定义 *****************/
#define  BKP_DR11_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR12 寄存器的位定义 *****************/
#define  BKP_DR12_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR13 寄存器的位定义 *****************/
#define  BKP_DR13_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR14 寄存器的位定义 *****************/
#define  BKP_DR14_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR15 寄存器的位定义 *****************/
#define  BKP_DR15_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR16 寄存器的位定义 *****************/
#define  BKP_DR16_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR17 寄存器的位定义 *****************/
#define  BKP_DR17_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/****************** BKP_DR18 寄存器的位定义 ****************/
#define  BKP_DR18_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR19 寄存器的位定义 *****************/
#define  BKP_DR19_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR20 寄存器的位定义 *****************/
#define  BKP_DR20_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR21 寄存器的位定义 *****************/
#define  BKP_DR21_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR22 寄存器的位定义 *****************/
#define  BKP_DR22_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR23 寄存器的位定义 *****************/
#define  BKP_DR23_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR24 寄存器的位定义 *****************/
#define  BKP_DR24_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR25 寄存器的位定义 *****************/
#define  BKP_DR25_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR26 寄存器的位定义 *****************/
#define  BKP_DR26_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR27 寄存器的位定义 *****************/
#define  BKP_DR27_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR28 寄存器的位定义 *****************/
#define  BKP_DR28_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR29 寄存器的位定义 *****************/
#define  BKP_DR29_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR30 寄存器的位定义 *****************/
#define  BKP_DR30_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR31 寄存器的位定义 *****************/
#define  BKP_DR31_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR32 寄存器的位定义 *****************/
#define  BKP_DR32_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR33 寄存器的位定义 *****************/
#define  BKP_DR33_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR34 寄存器的位定义 *****************/
#define  BKP_DR34_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR35 寄存器的位定义 *****************/
#define  BKP_DR35_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR36 寄存器的位定义 *****************/
#define  BKP_DR36_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR37 寄存器的位定义 *****************/
#define  BKP_DR37_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR38 寄存器的位定义 *****************/
#define  BKP_DR38_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR39 寄存器的位定义 *****************/
#define  BKP_DR39_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR40 寄存器的位定义 *****************/
#define  BKP_DR40_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR41 寄存器的位定义 *****************/
#define  BKP_DR41_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/******************* BKP_DR42 寄存器的位定义 *****************/
#define  BKP_DR42_D                          ((uint16_t)0xFFFF)     /*!< 备份数据 */

/****************** BKP_RTCCR 寄存器的位定义 ****************/
#define  BKP_RTCCR_CAL                       ((uint16_t)0x007F)     /*!< 校准值 */
#define  BKP_RTCCR_CCO                       ((uint16_t)0x0080)     /*!< 校准时钟输出 */
#define  BKP_RTCCR_ASOE                      ((uint16_t)0x0100)     /*!< 闹钟或秒输出使能 */
#define  BKP_RTCCR_ASOS                      ((uint16_t)0x0200)     /*!< 闹钟或秒输出选择 */

/******************** BKP_CR 寄存器的位定义 ******************/
#define  BKP_CR_TPE                          ((uint8_t)0x01)        /*!< TAMPER 引脚使能 */
#define  BKP_CR_TPAL                         ((uint8_t)0x02)        /*!< TAMPER 引脚有效电平 */

/******************* BKP_CSR 寄存器的位定义 *****************/
#define  BKP_CSR_CTE                         ((uint16_t)0x0001)     /*!< 清除侵入事件 */
#define  BKP_CSR_CTI                         ((uint16_t)0x0002)     /*!< 清除侵入中断 */
#define  BKP_CSR_TPIE                        ((uint16_t)0x0004)     /*!< TAMPER 引脚中断使能 */
#define  BKP_CSR_TEF                         ((uint16_t)0x0100)     /*!< 侵入事件标志位 */
#define  BKP_CSR_TIF                         ((uint16_t)0x0200)     /*!< 侵入中断标志位 */

/******************************************************************************/
/*                                                                            */
/*                         复位和时钟控制                            */
/*                                                                            */
/******************************************************************************/

/******************** RCC_CR 寄存器的位定义 ******************/
#define  RCC_CR_HSION                        ((uint32_t)0x00000001)        /*!< 内部高速时钟使能 */
#define  RCC_CR_HSIRDY                       ((uint32_t)0x00000002)        /*!< 内部高速时钟就绪标志位 */
#define  RCC_CR_HSITRIM                      ((uint32_t)0x000000F8)        /*!< 内部高速时钟微调 */
#define  RCC_CR_HSICAL                       ((uint32_t)0x0000FF00)        /*!< 内部高速时钟校准 */
#define  RCC_CR_HSEON                        ((uint32_t)0x00010000)        /*!< 外部高速时钟使能 */
#define  RCC_CR_HSERDY                       ((uint32_t)0x00020000)        /*!< 外部高速时钟就绪标志位 */
#define  RCC_CR_HSEBYP                       ((uint32_t)0x00040000)        /*!< 外部高速时钟旁路 */
#define  RCC_CR_CSSON                        ((uint32_t)0x00080000)        /*!< 时钟安全系统使能 */
#define  RCC_CR_PLLON                        ((uint32_t)0x01000000)        /*!< PLL 使能 */
#define  RCC_CR_PLLRDY                       ((uint32_t)0x02000000)        /*!< PLL 时钟就绪标志位 */

#ifdef STM32F10X_CL
 #define  RCC_CR_PLL2ON                       ((uint32_t)0x04000000)        /*!< PLL2 使能 */
 #define  RCC_CR_PLL2RDY                      ((uint32_t)0x08000000)        /*!< PLL2 时钟就绪标志位 */
 #define  RCC_CR_PLL3ON                       ((uint32_t)0x10000000)        /*!< PLL3 使能 */
 #define  RCC_CR_PLL3RDY                      ((uint32_t)0x20000000)        /*!< PLL3 时钟就绪标志位 */
#endif /* STM32F10X_CL */

/******************* RCC_CFGR 寄存器的位定义 *****************/
/*!< SW 配置 */
#define  RCC_CFGR_SW                         ((uint32_t)0x00000003)        /*!< SW[1:0] 位（系统时钟切换） */
#define  RCC_CFGR_SW_0                       ((uint32_t)0x00000001)        /*!< 位 0 */
#define  RCC_CFGR_SW_1                       ((uint32_t)0x00000002)        /*!< 位 1 */

#define  RCC_CFGR_SW_HSI                     ((uint32_t)0x00000000)        /*!< 选择 HSI 作为系统时钟 */
#define  RCC_CFGR_SW_HSE                     ((uint32_t)0x00000001)        /*!< 选择 HSE 作为系统时钟 */
#define  RCC_CFGR_SW_PLL                     ((uint32_t)0x00000002)        /*!< 选择 PLL 作为系统时钟 */

/*!< SWS 配置 */
#define  RCC_CFGR_SWS                        ((uint32_t)0x0000000C)        /*!< SWS[1:0] 位（系统时钟切换状态） */
#define  RCC_CFGR_SWS_0                      ((uint32_t)0x00000004)        /*!< 位 0 */
#define  RCC_CFGR_SWS_1                      ((uint32_t)0x00000008)        /*!< 位 1 */

#define  RCC_CFGR_SWS_HSI                    ((uint32_t)0x00000000)        /*!< HSI 振荡器用作系统时钟 */
#define  RCC_CFGR_SWS_HSE                    ((uint32_t)0x00000004)        /*!< HSE 振荡器用作系统时钟 */
#define  RCC_CFGR_SWS_PLL                    ((uint32_t)0x00000008)        /*!< PLL 用作系统时钟 */

/*!< HPRE 配置 */
#define  RCC_CFGR_HPRE                       ((uint32_t)0x000000F0)        /*!< HPRE[3:0] 位（AHB 分频系数） */
#define  RCC_CFGR_HPRE_0                     ((uint32_t)0x00000010)        /*!< 位 0 */
#define  RCC_CFGR_HPRE_1                     ((uint32_t)0x00000020)        /*!< 位 1 */
#define  RCC_CFGR_HPRE_2                     ((uint32_t)0x00000040)        /*!< 位 2 */
#define  RCC_CFGR_HPRE_3                     ((uint32_t)0x00000080)        /*!< 位 3 */

#define  RCC_CFGR_HPRE_DIV1                  ((uint32_t)0x00000000)        /*!< SYSCLK 不分频 */
#define  RCC_CFGR_HPRE_DIV2                  ((uint32_t)0x00000080)        /*!< SYSCLK 2 分频 */
#define  RCC_CFGR_HPRE_DIV4                  ((uint32_t)0x00000090)        /*!< SYSCLK 4 分频 */
#define  RCC_CFGR_HPRE_DIV8                  ((uint32_t)0x000000A0)        /*!< SYSCLK 8 分频 */
#define  RCC_CFGR_HPRE_DIV16                 ((uint32_t)0x000000B0)        /*!< SYSCLK 16 分频 */
#define  RCC_CFGR_HPRE_DIV64                 ((uint32_t)0x000000C0)        /*!< SYSCLK 64 分频 */
#define  RCC_CFGR_HPRE_DIV128                ((uint32_t)0x000000D0)        /*!< SYSCLK 128 分频 */
#define  RCC_CFGR_HPRE_DIV256                ((uint32_t)0x000000E0)        /*!< SYSCLK 256 分频 */
#define  RCC_CFGR_HPRE_DIV512                ((uint32_t)0x000000F0)        /*!< SYSCLK 512 分频 */

/*!< PPRE1 配置 */
#define  RCC_CFGR_PPRE1                      ((uint32_t)0x00000700)        /*!< PRE1[2:0] 位（APB1 分频系数） */
#define  RCC_CFGR_PPRE1_0                    ((uint32_t)0x00000100)        /*!< 位 0 */
#define  RCC_CFGR_PPRE1_1                    ((uint32_t)0x00000200)        /*!< 位 1 */
#define  RCC_CFGR_PPRE1_2                    ((uint32_t)0x00000400)        /*!< 位 2 */

#define  RCC_CFGR_PPRE1_DIV1                 ((uint32_t)0x00000000)        /*!< HCLK 不分频 */
#define  RCC_CFGR_PPRE1_DIV2                 ((uint32_t)0x00000400)        /*!< HCLK 2 分频 */
#define  RCC_CFGR_PPRE1_DIV4                 ((uint32_t)0x00000500)        /*!< HCLK 4 分频 */
#define  RCC_CFGR_PPRE1_DIV8                 ((uint32_t)0x00000600)        /*!< HCLK 8 分频 */
#define  RCC_CFGR_PPRE1_DIV16                ((uint32_t)0x00000700)        /*!< HCLK 16 分频 */

/*!< PPRE2 配置 */
#define  RCC_CFGR_PPRE2                      ((uint32_t)0x00003800)        /*!< PRE2[2:0] 位（APB2 分频系数） */
#define  RCC_CFGR_PPRE2_0                    ((uint32_t)0x00000800)        /*!< 位 0 */
#define  RCC_CFGR_PPRE2_1                    ((uint32_t)0x00001000)        /*!< 位 1 */
#define  RCC_CFGR_PPRE2_2                    ((uint32_t)0x00002000)        /*!< 位 2 */

#define  RCC_CFGR_PPRE2_DIV1                 ((uint32_t)0x00000000)        /*!< HCLK 不分频 */
#define  RCC_CFGR_PPRE2_DIV2                 ((uint32_t)0x00002000)        /*!< HCLK 2 分频 */
#define  RCC_CFGR_PPRE2_DIV4                 ((uint32_t)0x00002800)        /*!< HCLK 4 分频 */
#define  RCC_CFGR_PPRE2_DIV8                 ((uint32_t)0x00003000)        /*!< HCLK 8 分频 */
#define  RCC_CFGR_PPRE2_DIV16                ((uint32_t)0x00003800)        /*!< HCLK 16 分频 */

/*!< ADCPRE 配置 */
#define  RCC_CFGR_ADCPRE                     ((uint32_t)0x0000C000)        /*!< ADCPRE[1:0] 位（ADC 分频系数） */
#define  RCC_CFGR_ADCPRE_0                   ((uint32_t)0x00004000)        /*!< 位 0 */
#define  RCC_CFGR_ADCPRE_1                   ((uint32_t)0x00008000)        /*!< 位 1 */

#define  RCC_CFGR_ADCPRE_DIV2                ((uint32_t)0x00000000)        /*!< PCLK2 2 分频 */
#define  RCC_CFGR_ADCPRE_DIV4                ((uint32_t)0x00004000)        /*!< PCLK2 4 分频 */
#define  RCC_CFGR_ADCPRE_DIV6                ((uint32_t)0x00008000)        /*!< PCLK2 6 分频 */
#define  RCC_CFGR_ADCPRE_DIV8                ((uint32_t)0x0000C000)        /*!< PCLK2 8 分频 */

#define  RCC_CFGR_PLLSRC                     ((uint32_t)0x00010000)        /*!< PLL 输入时钟源 */

#define  RCC_CFGR_PLLXTPRE                   ((uint32_t)0x00020000)        /*!< PLL 输入的 HSE 分频 */

/*!< PLLMUL 配置 */
#define  RCC_CFGR_PLLMULL                    ((uint32_t)0x003C0000)        /*!< PLLMUL[3:0] 位（PLL 倍频系数） */
#define  RCC_CFGR_PLLMULL_0                  ((uint32_t)0x00040000)        /*!< 位 0 */
#define  RCC_CFGR_PLLMULL_1                  ((uint32_t)0x00080000)        /*!< 位 1 */
#define  RCC_CFGR_PLLMULL_2                  ((uint32_t)0x00100000)        /*!< 位 2 */
#define  RCC_CFGR_PLLMULL_3                  ((uint32_t)0x00200000)        /*!< 位 3 */

#ifdef STM32F10X_CL
 #define  RCC_CFGR_PLLSRC_HSI_Div2           ((uint32_t)0x00000000)        /*!< 选择 HSI 时钟 2 分频作为 PLL 输入时钟源 */
 #define  RCC_CFGR_PLLSRC_PREDIV1            ((uint32_t)0x00010000)        /*!< 选择 PREDIV1 时钟作为 PLL 输入时钟源 */

 #define  RCC_CFGR_PLLXTPRE_PREDIV1          ((uint32_t)0x00000000)        /*!< PREDIV1 时钟不分频作为 PLL 输入 */
 #define  RCC_CFGR_PLLXTPRE_PREDIV1_Div2     ((uint32_t)0x00020000)        /*!< PREDIV1 时钟 2 分频作为 PLL 输入 */

 #define  RCC_CFGR_PLLMULL4                  ((uint32_t)0x00080000)        /*!< PLL 输入时钟 * 4 */
 #define  RCC_CFGR_PLLMULL5                  ((uint32_t)0x000C0000)        /*!< PLL 输入时钟 * 5 */
 #define  RCC_CFGR_PLLMULL6                  ((uint32_t)0x00100000)        /*!< PLL 输入时钟 * 6 */
 #define  RCC_CFGR_PLLMULL7                  ((uint32_t)0x00140000)        /*!< PLL 输入时钟 * 7 */
 #define  RCC_CFGR_PLLMULL8                  ((uint32_t)0x00180000)        /*!< PLL 输入时钟 * 8 */
 #define  RCC_CFGR_PLLMULL9                  ((uint32_t)0x001C0000)        /*!< PLL 输入时钟 * 9 */
 #define  RCC_CFGR_PLLMULL6_5                ((uint32_t)0x00340000)        /*!< PLL 输入时钟 * 6.5 */
 
 #define  RCC_CFGR_OTGFSPRE                  ((uint32_t)0x00400000)        /*!< USB OTG FS 分频系数 */
 
/*!< MCO 配置 */
 #define  RCC_CFGR_MCO                       ((uint32_t)0x0F000000)        /*!< MCO[3:0] 位（微控制器时钟输出） */
 #define  RCC_CFGR_MCO_0                     ((uint32_t)0x01000000)        /*!< 位 0 */
 #define  RCC_CFGR_MCO_1                     ((uint32_t)0x02000000)        /*!< 位 1 */
 #define  RCC_CFGR_MCO_2                     ((uint32_t)0x04000000)        /*!< 位 2 */
 #define  RCC_CFGR_MCO_3                     ((uint32_t)0x08000000)        /*!< 位 3 */

 #define  RCC_CFGR_MCO_NOCLOCK               ((uint32_t)0x00000000)        /*!< 无时钟 */
 #define  RCC_CFGR_MCO_SYSCLK                ((uint32_t)0x04000000)        /*!< 选择系统时钟作为 MCO 源 */
 #define  RCC_CFGR_MCO_HSI                   ((uint32_t)0x05000000)        /*!< 选择 HSI 时钟作为 MCO 源 */
 #define  RCC_CFGR_MCO_HSE                   ((uint32_t)0x06000000)        /*!< 选择 HSE 时钟作为 MCO 源 */
 #define  RCC_CFGR_MCO_PLLCLK_Div2           ((uint32_t)0x07000000)        /*!< 选择 PLL 时钟 2 分频作为 MCO 源 */
 #define  RCC_CFGR_MCO_PLL2CLK               ((uint32_t)0x08000000)        /*!< 选择 PLL2 时钟作为 MCO 源*/
 #define  RCC_CFGR_MCO_PLL3CLK_Div2          ((uint32_t)0x09000000)        /*!< 选择 PLL3 时钟 2 分频作为 MCO 源*/
 #define  RCC_CFGR_MCO_Ext_HSE               ((uint32_t)0x0A000000)        /*!< 选择 XT1 外部 3-25 MHz 振荡器时钟作为 MCO 源 */
 #define  RCC_CFGR_MCO_PLL3CLK               ((uint32_t)0x0B000000)        /*!< 选择 PLL3 时钟作为 MCO 源 */
#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
 #define  RCC_CFGR_PLLSRC_HSI_Div2           ((uint32_t)0x00000000)        /*!< 选择 HSI 时钟 2 分频作为 PLL 输入时钟源 */
 #define  RCC_CFGR_PLLSRC_PREDIV1            ((uint32_t)0x00010000)        /*!< 选择 PREDIV1 时钟作为 PLL 输入时钟源 */

 #define  RCC_CFGR_PLLXTPRE_PREDIV1          ((uint32_t)0x00000000)        /*!< PREDIV1 时钟不分频作为 PLL 输入 */
 #define  RCC_CFGR_PLLXTPRE_PREDIV1_Div2     ((uint32_t)0x00020000)        /*!< PREDIV1 时钟 2 分频作为 PLL 输入 */

 #define  RCC_CFGR_PLLMULL2                  ((uint32_t)0x00000000)        /*!< PLL 输入时钟 * 2 */
 #define  RCC_CFGR_PLLMULL3                  ((uint32_t)0x00040000)        /*!< PLL 输入时钟 * 3 */
 #define  RCC_CFGR_PLLMULL4                  ((uint32_t)0x00080000)        /*!< PLL 输入时钟 * 4 */
 #define  RCC_CFGR_PLLMULL5                  ((uint32_t)0x000C0000)        /*!< PLL 输入时钟 * 5 */
 #define  RCC_CFGR_PLLMULL6                  ((uint32_t)0x00100000)        /*!< PLL 输入时钟 * 6 */
 #define  RCC_CFGR_PLLMULL7                  ((uint32_t)0x00140000)        /*!< PLL 输入时钟 * 7 */
 #define  RCC_CFGR_PLLMULL8                  ((uint32_t)0x00180000)        /*!< PLL 输入时钟 * 8 */
 #define  RCC_CFGR_PLLMULL9                  ((uint32_t)0x001C0000)        /*!< PLL 输入时钟 * 9 */
 #define  RCC_CFGR_PLLMULL10                 ((uint32_t)0x00200000)        /*!< PLL 输入时钟 * 10 */
 #define  RCC_CFGR_PLLMULL11                 ((uint32_t)0x00240000)        /*!< PLL 输入时钟 * 11 */
 #define  RCC_CFGR_PLLMULL12                 ((uint32_t)0x00280000)        /*!< PLL 输入时钟 * 12 */
 #define  RCC_CFGR_PLLMULL13                 ((uint32_t)0x002C0000)        /*!< PLL 输入时钟 * 13 */
 #define  RCC_CFGR_PLLMULL14                 ((uint32_t)0x00300000)        /*!< PLL 输入时钟 * 14 */
 #define  RCC_CFGR_PLLMULL15                 ((uint32_t)0x00340000)        /*!< PLL 输入时钟 * 15 */
 #define  RCC_CFGR_PLLMULL16                 ((uint32_t)0x00380000)        /*!< PLL 输入时钟 * 16 */

/*!< MCO 配置 */
 #define  RCC_CFGR_MCO                       ((uint32_t)0x07000000)        /*!< MCO[2:0] 位（微控制器时钟输出） */
 #define  RCC_CFGR_MCO_0                     ((uint32_t)0x01000000)        /*!< 位 0 */
 #define  RCC_CFGR_MCO_1                     ((uint32_t)0x02000000)        /*!< 位 1 */
 #define  RCC_CFGR_MCO_2                     ((uint32_t)0x04000000)        /*!< 位 2 */

 #define  RCC_CFGR_MCO_NOCLOCK               ((uint32_t)0x00000000)        /*!< 无时钟 */
 #define  RCC_CFGR_MCO_SYSCLK                ((uint32_t)0x04000000)        /*!< 选择系统时钟作为 MCO 源 */
 #define  RCC_CFGR_MCO_HSI                   ((uint32_t)0x05000000)        /*!< 选择 HSI 时钟作为 MCO 源 */
 #define  RCC_CFGR_MCO_HSE                   ((uint32_t)0x06000000)        /*!< 选择 HSE 时钟作为 MCO 源  */
 #define  RCC_CFGR_MCO_PLL                   ((uint32_t)0x07000000)        /*!< 选择 PLL 时钟 2 分频作为 MCO 源 */
#else
 #define  RCC_CFGR_PLLSRC_HSI_Div2           ((uint32_t)0x00000000)        /*!< 选择 HSI 时钟 2 分频作为 PLL 输入时钟源 */
 #define  RCC_CFGR_PLLSRC_HSE                ((uint32_t)0x00010000)        /*!< 选择 HSE 时钟作为 PLL 输入时钟源 */

 #define  RCC_CFGR_PLLXTPRE_HSE              ((uint32_t)0x00000000)        /*!< HSE 时钟不分频作为 PLL 输入 */
 #define  RCC_CFGR_PLLXTPRE_HSE_Div2         ((uint32_t)0x00020000)        /*!< HSE 时钟 2 分频作为 PLL 输入 */

 #define  RCC_CFGR_PLLMULL2                  ((uint32_t)0x00000000)        /*!< PLL 输入时钟 * 2 */
 #define  RCC_CFGR_PLLMULL3                  ((uint32_t)0x00040000)        /*!< PLL 输入时钟 * 3 */
 #define  RCC_CFGR_PLLMULL4                  ((uint32_t)0x00080000)        /*!< PLL 输入时钟 * 4 */
 #define  RCC_CFGR_PLLMULL5                  ((uint32_t)0x000C0000)        /*!< PLL 输入时钟 * 5 */
 #define  RCC_CFGR_PLLMULL6                  ((uint32_t)0x00100000)        /*!< PLL 输入时钟 * 6 */
 #define  RCC_CFGR_PLLMULL7                  ((uint32_t)0x00140000)        /*!< PLL 输入时钟 * 7 */
 #define  RCC_CFGR_PLLMULL8                  ((uint32_t)0x00180000)        /*!< PLL 输入时钟 * 8 */
 #define  RCC_CFGR_PLLMULL9                  ((uint32_t)0x001C0000)        /*!< PLL 输入时钟 * 9 */
 #define  RCC_CFGR_PLLMULL10                 ((uint32_t)0x00200000)        /*!< PLL 输入时钟 * 10 */
 #define  RCC_CFGR_PLLMULL11                 ((uint32_t)0x00240000)        /*!< PLL 输入时钟 * 11 */
 #define  RCC_CFGR_PLLMULL12                 ((uint32_t)0x00280000)        /*!< PLL 输入时钟 * 12 */
 #define  RCC_CFGR_PLLMULL13                 ((uint32_t)0x002C0000)        /*!< PLL 输入时钟 * 13 */
 #define  RCC_CFGR_PLLMULL14                 ((uint32_t)0x00300000)        /*!< PLL 输入时钟 * 14 */
 #define  RCC_CFGR_PLLMULL15                 ((uint32_t)0x00340000)        /*!< PLL 输入时钟 * 15 */
 #define  RCC_CFGR_PLLMULL16                 ((uint32_t)0x00380000)        /*!< PLL 输入时钟 * 16 */
 #define  RCC_CFGR_USBPRE                    ((uint32_t)0x00400000)        /*!< USB 设备分频系数 */

/*!< MCO 配置 */
 #define  RCC_CFGR_MCO                       ((uint32_t)0x07000000)        /*!< MCO[2:0] 位（微控制器时钟输出） */
 #define  RCC_CFGR_MCO_0                     ((uint32_t)0x01000000)        /*!< 位 0 */
 #define  RCC_CFGR_MCO_1                     ((uint32_t)0x02000000)        /*!< 位 1 */
 #define  RCC_CFGR_MCO_2                     ((uint32_t)0x04000000)        /*!< 位 2 */

 #define  RCC_CFGR_MCO_NOCLOCK               ((uint32_t)0x00000000)        /*!< 无时钟 */
 #define  RCC_CFGR_MCO_SYSCLK                ((uint32_t)0x04000000)        /*!< 选择系统时钟作为 MCO 源 */
 #define  RCC_CFGR_MCO_HSI                   ((uint32_t)0x05000000)        /*!< 选择 HSI 时钟作为 MCO 源 */
 #define  RCC_CFGR_MCO_HSE                   ((uint32_t)0x06000000)        /*!< 选择 HSE 时钟作为 MCO 源  */
 #define  RCC_CFGR_MCO_PLL                   ((uint32_t)0x07000000)        /*!< 选择 PLL 时钟 2 分频作为 MCO 源 */
#endif /* STM32F10X_CL */

/*!<****************** RCC_CIR 寄存器的位定义 ******************/
#define  RCC_CIR_LSIRDYF                     ((uint32_t)0x00000001)        /*!< LSI 就绪中断标志位 */
#define  RCC_CIR_LSERDYF                     ((uint32_t)0x00000002)        /*!< LSE 就绪中断标志位 */
#define  RCC_CIR_HSIRDYF                     ((uint32_t)0x00000004)        /*!< HSI 就绪中断标志位 */
#define  RCC_CIR_HSERDYF                     ((uint32_t)0x00000008)        /*!< HSE 就绪中断标志位 */
#define  RCC_CIR_PLLRDYF                     ((uint32_t)0x00000010)        /*!< PLL 就绪中断标志位 */
#define  RCC_CIR_CSSF                        ((uint32_t)0x00000080)        /*!< 时钟安全系统中断标志位 */
#define  RCC_CIR_LSIRDYIE                    ((uint32_t)0x00000100)        /*!< LSI 就绪中断使能 */
#define  RCC_CIR_LSERDYIE                    ((uint32_t)0x00000200)        /*!< LSE 就绪中断使能 */
#define  RCC_CIR_HSIRDYIE                    ((uint32_t)0x00000400)        /*!< HSI 就绪中断使能 */
#define  RCC_CIR_HSERDYIE                    ((uint32_t)0x00000800)        /*!< HSE 就绪中断使能 */
#define  RCC_CIR_PLLRDYIE                    ((uint32_t)0x00001000)        /*!< PLL 就绪中断使能 */
#define  RCC_CIR_LSIRDYC                     ((uint32_t)0x00010000)        /*!< LSI 就绪中断清除 */
#define  RCC_CIR_LSERDYC                     ((uint32_t)0x00020000)        /*!< LSE 就绪中断清除 */
#define  RCC_CIR_HSIRDYC                     ((uint32_t)0x00040000)        /*!< HSI 就绪中断清除 */
#define  RCC_CIR_HSERDYC                     ((uint32_t)0x00080000)        /*!< HSE 就绪中断清除 */
#define  RCC_CIR_PLLRDYC                     ((uint32_t)0x00100000)        /*!< PLL 就绪中断清除 */
#define  RCC_CIR_CSSC                        ((uint32_t)0x00800000)        /*!< 时钟安全系统中断清除 */

#ifdef STM32F10X_CL
 #define  RCC_CIR_PLL2RDYF                    ((uint32_t)0x00000020)        /*!< PLL2 就绪中断标志位 */
 #define  RCC_CIR_PLL3RDYF                    ((uint32_t)0x00000040)        /*!< PLL3 就绪中断标志位 */
 #define  RCC_CIR_PLL2RDYIE                   ((uint32_t)0x00002000)        /*!< PLL2 就绪中断使能 */
 #define  RCC_CIR_PLL3RDYIE                   ((uint32_t)0x00004000)        /*!< PLL3 就绪中断使能 */
 #define  RCC_CIR_PLL2RDYC                    ((uint32_t)0x00200000)        /*!< PLL2 就绪中断清除 */
 #define  RCC_CIR_PLL3RDYC                    ((uint32_t)0x00400000)        /*!< PLL3 就绪中断清除 */
#endif /* STM32F10X_CL */

/***************** RCC_APB2RSTR 寄存器的位定义 ***************/
#define  RCC_APB2RSTR_AFIORST                ((uint32_t)0x00000001)        /*!< 复用功能 I/O 复位 */
#define  RCC_APB2RSTR_IOPARST                ((uint32_t)0x00000004)        /*!< I/O 端口 A 复位 */
#define  RCC_APB2RSTR_IOPBRST                ((uint32_t)0x00000008)        /*!< I/O 端口 B 复位 */
#define  RCC_APB2RSTR_IOPCRST                ((uint32_t)0x00000010)        /*!< I/O 端口 C 复位 */
#define  RCC_APB2RSTR_IOPDRST                ((uint32_t)0x00000020)        /*!< I/O 端口 D 复位 */
#define  RCC_APB2RSTR_ADC1RST                ((uint32_t)0x00000200)        /*!< ADC 1 接口复位 */

#if !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD_VL)
#define  RCC_APB2RSTR_ADC2RST                ((uint32_t)0x00000400)        /*!< ADC 2 接口复位 */
#endif

#define  RCC_APB2RSTR_TIM1RST                ((uint32_t)0x00000800)        /*!< TIM1 定时器复位 */
#define  RCC_APB2RSTR_SPI1RST                ((uint32_t)0x00001000)        /*!< SPI 1 复位 */
#define  RCC_APB2RSTR_USART1RST              ((uint32_t)0x00004000)        /*!< USART1 复位 */

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
#define  RCC_APB2RSTR_TIM15RST               ((uint32_t)0x00010000)        /*!< TIM15 定时器复位 */
#define  RCC_APB2RSTR_TIM16RST               ((uint32_t)0x00020000)        /*!< TIM16 定时器复位 */
#define  RCC_APB2RSTR_TIM17RST               ((uint32_t)0x00040000)        /*!< TIM17 定时器复位 */
#endif

#if !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL)
 #define  RCC_APB2RSTR_IOPERST               ((uint32_t)0x00000040)        /*!< I/O 端口 E 复位 */
#endif /* STM32F10X_LD && STM32F10X_LD_VL */

#if defined (STM32F10X_HD) || defined (STM32F10X_XL)
 #define  RCC_APB2RSTR_IOPFRST               ((uint32_t)0x00000080)        /*!< I/O 端口 F 复位 */
 #define  RCC_APB2RSTR_IOPGRST               ((uint32_t)0x00000100)        /*!< I/O 端口 G 复位 */
 #define  RCC_APB2RSTR_TIM8RST               ((uint32_t)0x00002000)        /*!< TIM8 定时器复位 */
 #define  RCC_APB2RSTR_ADC3RST               ((uint32_t)0x00008000)        /*!< ADC3 接口复位 */
#endif

#if defined (STM32F10X_HD_VL)
 #define  RCC_APB2RSTR_IOPFRST               ((uint32_t)0x00000080)        /*!< I/O 端口 F 复位 */
 #define  RCC_APB2RSTR_IOPGRST               ((uint32_t)0x00000100)        /*!< I/O 端口 G 复位 */
#endif

#ifdef STM32F10X_XL
 #define  RCC_APB2RSTR_TIM9RST               ((uint32_t)0x00080000)         /*!< TIM9 定时器复位 */
 #define  RCC_APB2RSTR_TIM10RST              ((uint32_t)0x00100000)         /*!< TIM10 定时器复位 */
 #define  RCC_APB2RSTR_TIM11RST              ((uint32_t)0x00200000)         /*!< TIM11 定时器复位 */
#endif /* STM32F10X_XL */

/***************** RCC_APB1RSTR 寄存器的位定义 ***************/
#define  RCC_APB1RSTR_TIM2RST                ((uint32_t)0x00000001)        /*!< 定时器 2 复位 */
#define  RCC_APB1RSTR_TIM3RST                ((uint32_t)0x00000002)        /*!< 定时器 3 复位 */
#define  RCC_APB1RSTR_WWDGRST                ((uint32_t)0x00000800)        /*!< 窗口看门狗复位 */
#define  RCC_APB1RSTR_USART2RST              ((uint32_t)0x00020000)        /*!< USART 2 复位 */
#define  RCC_APB1RSTR_I2C1RST                ((uint32_t)0x00200000)        /*!< I2C 1 复位 */

#if !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD_VL)
#define  RCC_APB1RSTR_CAN1RST                ((uint32_t)0x02000000)        /*!< CAN1 复位 */
#endif

#define  RCC_APB1RSTR_BKPRST                 ((uint32_t)0x08000000)        /*!< 备份接口复位 */
#define  RCC_APB1RSTR_PWRRST                 ((uint32_t)0x10000000)        /*!< 电源接口复位 */

#if !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL)
 #define  RCC_APB1RSTR_TIM4RST               ((uint32_t)0x00000004)        /*!< 定时器 4 复位 */
 #define  RCC_APB1RSTR_SPI2RST               ((uint32_t)0x00004000)        /*!< SPI 2 复位 */
 #define  RCC_APB1RSTR_USART3RST             ((uint32_t)0x00040000)        /*!< USART 3 复位 */
 #define  RCC_APB1RSTR_I2C2RST               ((uint32_t)0x00400000)        /*!< I2C 2 复位 */
#endif /* STM32F10X_LD && STM32F10X_LD_VL */

#if defined (STM32F10X_HD) || defined (STM32F10X_MD) || defined (STM32F10X_LD) || defined  (STM32F10X_XL)
 #define  RCC_APB1RSTR_USBRST                ((uint32_t)0x00800000)        /*!< USB 设备复位 */
#endif

#if defined (STM32F10X_HD) || defined  (STM32F10X_CL) || defined  (STM32F10X_XL)
 #define  RCC_APB1RSTR_TIM5RST                ((uint32_t)0x00000008)        /*!< 定时器 5 复位 */
 #define  RCC_APB1RSTR_TIM6RST                ((uint32_t)0x00000010)        /*!< 定时器 6 复位 */
 #define  RCC_APB1RSTR_TIM7RST                ((uint32_t)0x00000020)        /*!< 定时器 7 复位 */
 #define  RCC_APB1RSTR_SPI3RST                ((uint32_t)0x00008000)        /*!< SPI 3 复位 */
 #define  RCC_APB1RSTR_UART4RST               ((uint32_t)0x00080000)        /*!< UART 4 复位 */
 #define  RCC_APB1RSTR_UART5RST               ((uint32_t)0x00100000)        /*!< UART 5 复位 */
 #define  RCC_APB1RSTR_DACRST                 ((uint32_t)0x20000000)        /*!< DAC 接口复位 */
#endif

#if defined (STM32F10X_LD_VL) || defined  (STM32F10X_MD_VL) || defined  (STM32F10X_HD_VL)
 #define  RCC_APB1RSTR_TIM6RST                ((uint32_t)0x00000010)        /*!< 定时器 6 复位 */
 #define  RCC_APB1RSTR_TIM7RST                ((uint32_t)0x00000020)        /*!< 定时器 7 复位 */
 #define  RCC_APB1RSTR_DACRST                 ((uint32_t)0x20000000)        /*!< DAC 接口复位 */
 #define  RCC_APB1RSTR_CECRST                 ((uint32_t)0x40000000)        /*!< CEC 接口复位 */ 
#endif

#if defined  (STM32F10X_HD_VL)
 #define  RCC_APB1RSTR_TIM5RST                ((uint32_t)0x00000008)        /*!< 定时器 5 复位 */
 #define  RCC_APB1RSTR_TIM12RST               ((uint32_t)0x00000040)        /*!< TIM12 定时器复位 */
 #define  RCC_APB1RSTR_TIM13RST               ((uint32_t)0x00000080)        /*!< TIM13 定时器复位 */
 #define  RCC_APB1RSTR_TIM14RST               ((uint32_t)0x00000100)        /*!< TIM14 定时器复位 */
 #define  RCC_APB1RSTR_SPI3RST                ((uint32_t)0x00008000)        /*!< SPI 3 复位 */ 
 #define  RCC_APB1RSTR_UART4RST               ((uint32_t)0x00080000)        /*!< UART 4 复位 */
 #define  RCC_APB1RSTR_UART5RST               ((uint32_t)0x00100000)        /*!< UART 5 复位 */ 
#endif

#ifdef STM32F10X_CL
 #define  RCC_APB1RSTR_CAN2RST                ((uint32_t)0x04000000)        /*!< CAN2 复位 */
#endif /* STM32F10X_CL */

#ifdef STM32F10X_XL
 #define  RCC_APB1RSTR_TIM12RST               ((uint32_t)0x00000040)         /*!< TIM12 定时器复位 */
 #define  RCC_APB1RSTR_TIM13RST               ((uint32_t)0x00000080)         /*!< TIM13 定时器复位 */
 #define  RCC_APB1RSTR_TIM14RST               ((uint32_t)0x00000100)         /*!< TIM14 定时器复位 */
#endif /* STM32F10X_XL */

/****************** RCC_AHBENR 寄存器的位定义 ****************/
#define  RCC_AHBENR_DMA1EN                   ((uint16_t)0x0001)            /*!< DMA1 时钟使能 */
#define  RCC_AHBENR_SRAMEN                   ((uint16_t)0x0004)            /*!< SRAM 接口时钟使能 */
#define  RCC_AHBENR_FLITFEN                  ((uint16_t)0x0010)            /*!< FLITF 时钟使能 */
#define  RCC_AHBENR_CRCEN                    ((uint16_t)0x0040)            /*!< CRC 时钟使能 */

#if defined (STM32F10X_HD) || defined  (STM32F10X_CL) || defined  (STM32F10X_HD_VL)
 #define  RCC_AHBENR_DMA2EN                  ((uint16_t)0x0002)            /*!< DMA2 时钟使能 */
#endif

#if defined (STM32F10X_HD) || defined (STM32F10X_XL)
 #define  RCC_AHBENR_FSMCEN                  ((uint16_t)0x0100)            /*!< FSMC 时钟使能 */
 #define  RCC_AHBENR_SDIOEN                  ((uint16_t)0x0400)            /*!< SDIO 时钟使能 */
#endif

#if defined (STM32F10X_HD_VL)
 #define  RCC_AHBENR_FSMCEN                  ((uint16_t)0x0100)            /*!< FSMC 时钟使能 */
#endif

#ifdef STM32F10X_CL
 #define  RCC_AHBENR_OTGFSEN                 ((uint32_t)0x00001000)         /*!< USB OTG FS 时钟使能 */
 #define  RCC_AHBENR_ETHMACEN                ((uint32_t)0x00004000)         /*!< 以太网 MAC 时钟使能 */
 #define  RCC_AHBENR_ETHMACTXEN              ((uint32_t)0x00008000)         /*!< 以太网 MAC 发送时钟使能 */
 #define  RCC_AHBENR_ETHMACRXEN              ((uint32_t)0x00010000)         /*!< 以太网 MAC 接收时钟使能 */
#endif /* STM32F10X_CL */

/****************** RCC_APB2ENR 寄存器的位定义 ****************/
#define  RCC_APB2ENR_AFIOEN                  ((uint32_t)0x00000001)         /*!< 复用功能 I/O 时钟使能 */
#define  RCC_APB2ENR_IOPAEN                  ((uint32_t)0x00000004)         /*!< I/O 端口 A 时钟使能 */
#define  RCC_APB2ENR_IOPBEN                  ((uint32_t)0x00000008)         /*!< I/O 端口 B 时钟使能 */
#define  RCC_APB2ENR_IOPCEN                  ((uint32_t)0x00000010)         /*!< I/O 端口 C 时钟使能 */
#define  RCC_APB2ENR_IOPDEN                  ((uint32_t)0x00000020)         /*!< I/O 端口 D 时钟使能 */
#define  RCC_APB2ENR_ADC1EN                  ((uint32_t)0x00000200)         /*!< ADC 1 接口时钟使能 */

#if !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD_VL)
#define  RCC_APB2ENR_ADC2EN                  ((uint32_t)0x00000400)         /*!< ADC 2 接口时钟使能 */
#endif

#define  RCC_APB2ENR_TIM1EN                  ((uint32_t)0x00000800)         /*!< TIM1 定时器时钟使能 */
#define  RCC_APB2ENR_SPI1EN                  ((uint32_t)0x00001000)         /*!< SPI 1 时钟使能 */
#define  RCC_APB2ENR_USART1EN                ((uint32_t)0x00004000)         /*!< USART1 时钟使能 */

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
#define  RCC_APB2ENR_TIM15EN                 ((uint32_t)0x00010000)         /*!< TIM15 定时器时钟使能 */
#define  RCC_APB2ENR_TIM16EN                 ((uint32_t)0x00020000)         /*!< TIM16 定时器时钟使能 */
#define  RCC_APB2ENR_TIM17EN                 ((uint32_t)0x00040000)         /*!< TIM17 定时器时钟使能 */
#endif

#if !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL)
 #define  RCC_APB2ENR_IOPEEN                 ((uint32_t)0x00000040)         /*!< I/O 端口 E 时钟使能 */
#endif /* STM32F10X_LD && STM32F10X_LD_VL */

#if defined (STM32F10X_HD) || defined (STM32F10X_XL)
 #define  RCC_APB2ENR_IOPFEN                 ((uint32_t)0x00000080)         /*!< I/O 端口 F 时钟使能 */
 #define  RCC_APB2ENR_IOPGEN                 ((uint32_t)0x00000100)         /*!< I/O 端口 G 时钟使能 */
 #define  RCC_APB2ENR_TIM8EN                 ((uint32_t)0x00002000)         /*!< TIM8 定时器时钟使能 */
 #define  RCC_APB2ENR_ADC3EN                 ((uint32_t)0x00008000)         /*!< DMA1 时钟使能 */
#endif

#if defined (STM32F10X_HD_VL)
 #define  RCC_APB2ENR_IOPFEN                 ((uint32_t)0x00000080)         /*!< I/O 端口 F 时钟使能 */
 #define  RCC_APB2ENR_IOPGEN                 ((uint32_t)0x00000100)         /*!< I/O 端口 G 时钟使能 */
#endif

#ifdef STM32F10X_XL
 #define  RCC_APB2ENR_TIM9EN                 ((uint32_t)0x00080000)         /*!< TIM9 定时器时钟使能  */
 #define  RCC_APB2ENR_TIM10EN                ((uint32_t)0x00100000)         /*!< TIM10 定时器时钟使能  */
 #define  RCC_APB2ENR_TIM11EN                ((uint32_t)0x00200000)         /*!< TIM11 定时器时钟使能 */
#endif

/***************** RCC_APB1ENR 寄存器的位定义 ***************/
#define  RCC_APB1ENR_TIM2EN                  ((uint32_t)0x00000001)        /*!< 定时器 2 时钟使能*/
#define  RCC_APB1ENR_TIM3EN                  ((uint32_t)0x00000002)        /*!< 定时器 3 时钟使能 */
#define  RCC_APB1ENR_WWDGEN                  ((uint32_t)0x00000800)        /*!< 窗口看门狗时钟使能 */
#define  RCC_APB1ENR_USART2EN                ((uint32_t)0x00020000)        /*!< USART 2 时钟使能 */
#define  RCC_APB1ENR_I2C1EN                  ((uint32_t)0x00200000)        /*!< I2C 1 时钟使能 */

#if !defined (STM32F10X_LD_VL) && !defined (STM32F10X_MD_VL) && !defined (STM32F10X_HD_VL)
#define  RCC_APB1ENR_CAN1EN                  ((uint32_t)0x02000000)        /*!< CAN1 时钟使能 */
#endif

#define  RCC_APB1ENR_BKPEN                   ((uint32_t)0x08000000)        /*!< 备份接口时钟使能 */
#define  RCC_APB1ENR_PWREN                   ((uint32_t)0x10000000)        /*!< 电源接口时钟使能 */

#if !defined (STM32F10X_LD) && !defined (STM32F10X_LD_VL)
 #define  RCC_APB1ENR_TIM4EN                 ((uint32_t)0x00000004)        /*!< 定时器 4 时钟使能 */
 #define  RCC_APB1ENR_SPI2EN                 ((uint32_t)0x00004000)        /*!< SPI 2 时钟使能 */
 #define  RCC_APB1ENR_USART3EN               ((uint32_t)0x00040000)        /*!< USART 3 时钟使能 */
 #define  RCC_APB1ENR_I2C2EN                 ((uint32_t)0x00400000)        /*!< I2C 2 时钟使能 */
#endif /* STM32F10X_LD && STM32F10X_LD_VL */

#if defined (STM32F10X_HD) || defined (STM32F10X_MD) || defined  (STM32F10X_LD)
 #define  RCC_APB1ENR_USBEN                  ((uint32_t)0x00800000)        /*!< USB 设备时钟使能 */
#endif

#if defined (STM32F10X_HD) || defined  (STM32F10X_CL)
 #define  RCC_APB1ENR_TIM5EN                 ((uint32_t)0x00000008)        /*!< 定时器 5 时钟使能 */
 #define  RCC_APB1ENR_TIM6EN                 ((uint32_t)0x00000010)        /*!< 定时器 6 时钟使能 */
 #define  RCC_APB1ENR_TIM7EN                 ((uint32_t)0x00000020)        /*!< 定时器 7 时钟使能 */
 #define  RCC_APB1ENR_SPI3EN                 ((uint32_t)0x00008000)        /*!< SPI 3 时钟使能 */
 #define  RCC_APB1ENR_UART4EN                ((uint32_t)0x00080000)        /*!< UART 4 时钟使能 */
 #define  RCC_APB1ENR_UART5EN                ((uint32_t)0x00100000)        /*!< UART 5 时钟使能 */
 #define  RCC_APB1ENR_DACEN                  ((uint32_t)0x20000000)        /*!< DAC 接口时钟使能 */
#endif

#if defined (STM32F10X_LD_VL) || defined  (STM32F10X_MD_VL) || defined  (STM32F10X_HD_VL)
 #define  RCC_APB1ENR_TIM6EN                 ((uint32_t)0x00000010)        /*!< 定时器 6 时钟使能 */
 #define  RCC_APB1ENR_TIM7EN                 ((uint32_t)0x00000020)        /*!< 定时器 7 时钟使能 */
 #define  RCC_APB1ENR_DACEN                  ((uint32_t)0x20000000)        /*!< DAC 接口时钟使能 */
 #define  RCC_APB1ENR_CECEN                  ((uint32_t)0x40000000)        /*!< CEC 接口时钟使能 */ 
#endif

#ifdef STM32F10X_HD_VL
 #define  RCC_APB1ENR_TIM5EN                 ((uint32_t)0x00000008)        /*!< 定时器 5 时钟使能 */
 #define  RCC_APB1ENR_TIM12EN                ((uint32_t)0x00000040)         /*!< TIM12 定时器时钟使能  */
 #define  RCC_APB1ENR_TIM13EN                ((uint32_t)0x00000080)         /*!< TIM13 定时器时钟使能  */
 #define  RCC_APB1ENR_TIM14EN                ((uint32_t)0x00000100)         /*!< TIM14 定时器时钟使能 */
 #define  RCC_APB1ENR_SPI3EN                 ((uint32_t)0x00008000)        /*!< SPI 3 时钟使能 */
 #define  RCC_APB1ENR_UART4EN                ((uint32_t)0x00080000)        /*!< UART 4 时钟使能 */
 #define  RCC_APB1ENR_UART5EN                ((uint32_t)0x00100000)        /*!< UART 5 时钟使能 */ 
#endif /* STM32F10X_HD_VL */

#ifdef STM32F10X_CL
 #define  RCC_APB1ENR_CAN2EN                  ((uint32_t)0x04000000)        /*!< CAN2 时钟使能 */
#endif /* STM32F10X_CL */

#ifdef STM32F10X_XL
 #define  RCC_APB1ENR_TIM12EN                ((uint32_t)0x00000040)         /*!< TIM12 定时器时钟使能  */
 #define  RCC_APB1ENR_TIM13EN                ((uint32_t)0x00000080)         /*!< TIM13 定时器时钟使能  */
 #define  RCC_APB1ENR_TIM14EN                ((uint32_t)0x00000100)         /*!< TIM14 定时器时钟使能 */
#endif /* STM32F10X_XL */

/******************* RCC_BDCR 寄存器的位定义 *****************/
#define  RCC_BDCR_LSEON                      ((uint32_t)0x00000001)        /*!< 外部低速振荡器使能 */
#define  RCC_BDCR_LSERDY                     ((uint32_t)0x00000002)        /*!< 外部低速振荡器就绪 */
#define  RCC_BDCR_LSEBYP                     ((uint32_t)0x00000004)        /*!< 外部低速振荡器旁路 */

#define  RCC_BDCR_RTCSEL                     ((uint32_t)0x00000300)        /*!< RTCSEL[1:0] 位（RTC 时钟源选择） */
#define  RCC_BDCR_RTCSEL_0                   ((uint32_t)0x00000100)        /*!< 位 0 */
#define  RCC_BDCR_RTCSEL_1                   ((uint32_t)0x00000200)        /*!< 位 1 */

/*!< RTC 配置 */
#define  RCC_BDCR_RTCSEL_NOCLOCK             ((uint32_t)0x00000000)        /*!< 无时钟 */
#define  RCC_BDCR_RTCSEL_LSE                 ((uint32_t)0x00000100)        /*!< LSE 振荡器时钟用作 RTC 时钟 */
#define  RCC_BDCR_RTCSEL_LSI                 ((uint32_t)0x00000200)        /*!< LSI 振荡器时钟用作 RTC 时钟 */
#define  RCC_BDCR_RTCSEL_HSE                 ((uint32_t)0x00000300)        /*!< HSE 振荡器时钟 128 分频用作 RTC 时钟 */

#define  RCC_BDCR_RTCEN                      ((uint32_t)0x00008000)        /*!< RTC 时钟使能 */
#define  RCC_BDCR_BDRST                      ((uint32_t)0x00010000)        /*!< 备份域软件复位  */

/******************* RCC_CSR 寄存器的位定义 *****************/  
#define  RCC_CSR_LSION                       ((uint32_t)0x00000001)        /*!< 内部低速振荡器使能 */
#define  RCC_CSR_LSIRDY                      ((uint32_t)0x00000002)        /*!< 内部低速振荡器就绪 */
#define  RCC_CSR_RMVF                        ((uint32_t)0x01000000)        /*!< 清除复位标志位 */
#define  RCC_CSR_PINRSTF                     ((uint32_t)0x04000000)        /*!< 引脚复位标志位 */
#define  RCC_CSR_PORRSTF                     ((uint32_t)0x08000000)        /*!< POR/PDR 复位标志位 */
#define  RCC_CSR_SFTRSTF                     ((uint32_t)0x10000000)        /*!< 软件复位标志位 */
#define  RCC_CSR_IWDGRSTF                    ((uint32_t)0x20000000)        /*!< 独立看门狗复位标志位 */
#define  RCC_CSR_WWDGRSTF                    ((uint32_t)0x40000000)        /*!< 窗口看门狗复位标志位 */
#define  RCC_CSR_LPWRRSTF                    ((uint32_t)0x80000000)        /*!< 低功耗复位标志位 */

#ifdef STM32F10X_CL
/******************* RCC_AHBRSTR 寄存器的位定义 *****************/
 #define  RCC_AHBRSTR_OTGFSRST               ((uint32_t)0x00001000)         /*!< USB OTG FS 复位 */
 #define  RCC_AHBRSTR_ETHMACRST              ((uint32_t)0x00004000)         /*!< 以太网 MAC 复位 */

/******************* RCC_CFGR2 寄存器的位定义 *****************/
/*!< PREDIV1 配置 */
 #define  RCC_CFGR2_PREDIV1                  ((uint32_t)0x0000000F)        /*!< PREDIV1[3:0] 位 */
 #define  RCC_CFGR2_PREDIV1_0                ((uint32_t)0x00000001)        /*!< 位 0 */
 #define  RCC_CFGR2_PREDIV1_1                ((uint32_t)0x00000002)        /*!< 位 1 */
 #define  RCC_CFGR2_PREDIV1_2                ((uint32_t)0x00000004)        /*!< 位 2 */
 #define  RCC_CFGR2_PREDIV1_3                ((uint32_t)0x00000008)        /*!< 位 3 */

 #define  RCC_CFGR2_PREDIV1_DIV1             ((uint32_t)0x00000000)        /*!< PREDIV1 输入时钟不分频 */
 #define  RCC_CFGR2_PREDIV1_DIV2             ((uint32_t)0x00000001)        /*!< PREDIV1 输入时钟 2 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV3             ((uint32_t)0x00000002)        /*!< PREDIV1 输入时钟 3 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV4             ((uint32_t)0x00000003)        /*!< PREDIV1 输入时钟 4 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV5             ((uint32_t)0x00000004)        /*!< PREDIV1 输入时钟 5 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV6             ((uint32_t)0x00000005)        /*!< PREDIV1 输入时钟 6 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV7             ((uint32_t)0x00000006)        /*!< PREDIV1 输入时钟 7 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV8             ((uint32_t)0x00000007)        /*!< PREDIV1 输入时钟 8 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV9             ((uint32_t)0x00000008)        /*!< PREDIV1 输入时钟 9 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV10            ((uint32_t)0x00000009)        /*!< PREDIV1 输入时钟 10 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV11            ((uint32_t)0x0000000A)        /*!< PREDIV1 输入时钟 11 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV12            ((uint32_t)0x0000000B)        /*!< PREDIV1 输入时钟 12 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV13            ((uint32_t)0x0000000C)        /*!< PREDIV1 输入时钟 13 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV14            ((uint32_t)0x0000000D)        /*!< PREDIV1 输入时钟 14 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV15            ((uint32_t)0x0000000E)        /*!< PREDIV1 输入时钟 15 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV16            ((uint32_t)0x0000000F)        /*!< PREDIV1 输入时钟 16 分频 */

/*!< PREDIV2 配置 */
 #define  RCC_CFGR2_PREDIV2                  ((uint32_t)0x000000F0)        /*!< PREDIV2[3:0] 位 */
 #define  RCC_CFGR2_PREDIV2_0                ((uint32_t)0x00000010)        /*!< 位 0 */
 #define  RCC_CFGR2_PREDIV2_1                ((uint32_t)0x00000020)        /*!< 位 1 */
 #define  RCC_CFGR2_PREDIV2_2                ((uint32_t)0x00000040)        /*!< 位 2 */
 #define  RCC_CFGR2_PREDIV2_3                ((uint32_t)0x00000080)        /*!< 位 3 */

 #define  RCC_CFGR2_PREDIV2_DIV1             ((uint32_t)0x00000000)        /*!< PREDIV2 输入时钟不分频 */
 #define  RCC_CFGR2_PREDIV2_DIV2             ((uint32_t)0x00000010)        /*!< PREDIV2 输入时钟 2 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV3             ((uint32_t)0x00000020)        /*!< PREDIV2 输入时钟 3 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV4             ((uint32_t)0x00000030)        /*!< PREDIV2 输入时钟 4 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV5             ((uint32_t)0x00000040)        /*!< PREDIV2 输入时钟 5 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV6             ((uint32_t)0x00000050)        /*!< PREDIV2 输入时钟 6 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV7             ((uint32_t)0x00000060)        /*!< PREDIV2 输入时钟 7 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV8             ((uint32_t)0x00000070)        /*!< PREDIV2 输入时钟 8 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV9             ((uint32_t)0x00000080)        /*!< PREDIV2 输入时钟 9 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV10            ((uint32_t)0x00000090)        /*!< PREDIV2 输入时钟 10 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV11            ((uint32_t)0x000000A0)        /*!< PREDIV2 输入时钟 11 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV12            ((uint32_t)0x000000B0)        /*!< PREDIV2 输入时钟 12 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV13            ((uint32_t)0x000000C0)        /*!< PREDIV2 输入时钟 13 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV14            ((uint32_t)0x000000D0)        /*!< PREDIV2 输入时钟 14 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV15            ((uint32_t)0x000000E0)        /*!< PREDIV2 输入时钟 15 分频 */
 #define  RCC_CFGR2_PREDIV2_DIV16            ((uint32_t)0x000000F0)        /*!< PREDIV2 输入时钟 16 分频 */

/*!< PLL2MUL 配置 */
 #define  RCC_CFGR2_PLL2MUL                  ((uint32_t)0x00000F00)        /*!< PLL2MUL[3:0] 位 */
 #define  RCC_CFGR2_PLL2MUL_0                ((uint32_t)0x00000100)        /*!< 位 0 */
 #define  RCC_CFGR2_PLL2MUL_1                ((uint32_t)0x00000200)        /*!< 位 1 */
 #define  RCC_CFGR2_PLL2MUL_2                ((uint32_t)0x00000400)        /*!< 位 2 */
 #define  RCC_CFGR2_PLL2MUL_3                ((uint32_t)0x00000800)        /*!< 位 3 */

 #define  RCC_CFGR2_PLL2MUL8                 ((uint32_t)0x00000600)        /*!< PLL2 输入时钟 * 8 */
 #define  RCC_CFGR2_PLL2MUL9                 ((uint32_t)0x00000700)        /*!< PLL2 输入时钟 * 9 */
 #define  RCC_CFGR2_PLL2MUL10                ((uint32_t)0x00000800)        /*!< PLL2 输入时钟 * 10 */
 #define  RCC_CFGR2_PLL2MUL11                ((uint32_t)0x00000900)        /*!< PLL2 输入时钟 * 11 */
 #define  RCC_CFGR2_PLL2MUL12                ((uint32_t)0x00000A00)        /*!< PLL2 输入时钟 * 12 */
 #define  RCC_CFGR2_PLL2MUL13                ((uint32_t)0x00000B00)        /*!< PLL2 输入时钟 * 13 */
 #define  RCC_CFGR2_PLL2MUL14                ((uint32_t)0x00000C00)        /*!< PLL2 输入时钟 * 14 */
 #define  RCC_CFGR2_PLL2MUL16                ((uint32_t)0x00000E00)        /*!< PLL2 输入时钟 * 16 */
 #define  RCC_CFGR2_PLL2MUL20                ((uint32_t)0x00000F00)        /*!< PLL2 输入时钟 * 20 */

/*!< PLL3MUL 配置 */
 #define  RCC_CFGR2_PLL3MUL                  ((uint32_t)0x0000F000)        /*!< PLL3MUL[3:0] 位 */
 #define  RCC_CFGR2_PLL3MUL_0                ((uint32_t)0x00001000)        /*!< 位 0 */
 #define  RCC_CFGR2_PLL3MUL_1                ((uint32_t)0x00002000)        /*!< 位 1 */
 #define  RCC_CFGR2_PLL3MUL_2                ((uint32_t)0x00004000)        /*!< 位 2 */
 #define  RCC_CFGR2_PLL3MUL_3                ((uint32_t)0x00008000)        /*!< 位 3 */

 #define  RCC_CFGR2_PLL3MUL8                 ((uint32_t)0x00006000)        /*!< PLL3 输入时钟 * 8 */
 #define  RCC_CFGR2_PLL3MUL9                 ((uint32_t)0x00007000)        /*!< PLL3 输入时钟 * 9 */
 #define  RCC_CFGR2_PLL3MUL10                ((uint32_t)0x00008000)        /*!< PLL3 输入时钟 * 10 */
 #define  RCC_CFGR2_PLL3MUL11                ((uint32_t)0x00009000)        /*!< PLL3 输入时钟 * 11 */
 #define  RCC_CFGR2_PLL3MUL12                ((uint32_t)0x0000A000)        /*!< PLL3 输入时钟 * 12 */
 #define  RCC_CFGR2_PLL3MUL13                ((uint32_t)0x0000B000)        /*!< PLL3 输入时钟 * 13 */
 #define  RCC_CFGR2_PLL3MUL14                ((uint32_t)0x0000C000)        /*!< PLL3 输入时钟 * 14 */
 #define  RCC_CFGR2_PLL3MUL16                ((uint32_t)0x0000E000)        /*!< PLL3 输入时钟 * 16 */
 #define  RCC_CFGR2_PLL3MUL20                ((uint32_t)0x0000F000)        /*!< PLL3 输入时钟 * 20 */

 #define  RCC_CFGR2_PREDIV1SRC               ((uint32_t)0x00010000)        /*!< PREDIV1 输入时钟源 */
 #define  RCC_CFGR2_PREDIV1SRC_PLL2          ((uint32_t)0x00010000)        /*!< 选择 PLL2 作为 PREDIV1 输入时钟源 */
 #define  RCC_CFGR2_PREDIV1SRC_HSE           ((uint32_t)0x00000000)        /*!< 选择 HSE 作为 PREDIV1 输入时钟源 */
 #define  RCC_CFGR2_I2S2SRC                  ((uint32_t)0x00020000)        /*!< I2S2 输入时钟源 */
 #define  RCC_CFGR2_I2S3SRC                  ((uint32_t)0x00040000)        /*!< I2S3 时钟源 */
#endif /* STM32F10X_CL */

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
/******************* RCC_CFGR2 寄存器的位定义 *****************/
/*!< PREDIV1 配置 */
 #define  RCC_CFGR2_PREDIV1                  ((uint32_t)0x0000000F)        /*!< PREDIV1[3:0] 位 */
 #define  RCC_CFGR2_PREDIV1_0                ((uint32_t)0x00000001)        /*!< 位 0 */
 #define  RCC_CFGR2_PREDIV1_1                ((uint32_t)0x00000002)        /*!< 位 1 */
 #define  RCC_CFGR2_PREDIV1_2                ((uint32_t)0x00000004)        /*!< 位 2 */
 #define  RCC_CFGR2_PREDIV1_3                ((uint32_t)0x00000008)        /*!< 位 3 */

 #define  RCC_CFGR2_PREDIV1_DIV1             ((uint32_t)0x00000000)        /*!< PREDIV1 输入时钟不分频 */
 #define  RCC_CFGR2_PREDIV1_DIV2             ((uint32_t)0x00000001)        /*!< PREDIV1 输入时钟 2 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV3             ((uint32_t)0x00000002)        /*!< PREDIV1 输入时钟 3 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV4             ((uint32_t)0x00000003)        /*!< PREDIV1 输入时钟 4 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV5             ((uint32_t)0x00000004)        /*!< PREDIV1 输入时钟 5 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV6             ((uint32_t)0x00000005)        /*!< PREDIV1 输入时钟 6 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV7             ((uint32_t)0x00000006)        /*!< PREDIV1 输入时钟 7 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV8             ((uint32_t)0x00000007)        /*!< PREDIV1 输入时钟 8 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV9             ((uint32_t)0x00000008)        /*!< PREDIV1 输入时钟 9 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV10            ((uint32_t)0x00000009)        /*!< PREDIV1 输入时钟 10 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV11            ((uint32_t)0x0000000A)        /*!< PREDIV1 输入时钟 11 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV12            ((uint32_t)0x0000000B)        /*!< PREDIV1 输入时钟 12 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV13            ((uint32_t)0x0000000C)        /*!< PREDIV1 输入时钟 13 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV14            ((uint32_t)0x0000000D)        /*!< PREDIV1 输入时钟 14 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV15            ((uint32_t)0x0000000E)        /*!< PREDIV1 输入时钟 15 分频 */
 #define  RCC_CFGR2_PREDIV1_DIV16            ((uint32_t)0x0000000F)        /*!< PREDIV1 输入时钟 16 分频 */
#endif
 
/******************************************************************************/
/*                                                                            */
/*                通用和复用功能 I/O                  */
/*                                                                            */
/******************************************************************************/

/******************* GPIO_CRL 寄存器的位定义 *****************/
#define  GPIO_CRL_MODE                       ((uint32_t)0x33333333)        /*!< 端口 x 模式位 */

#define  GPIO_CRL_MODE0                      ((uint32_t)0x00000003)        /*!< MODE0[1:0] 位（端口 x 模式位，引脚 0） */
#define  GPIO_CRL_MODE0_0                    ((uint32_t)0x00000001)        /*!< 位 0 */
#define  GPIO_CRL_MODE0_1                    ((uint32_t)0x00000002)        /*!< 位 1 */

#define  GPIO_CRL_MODE1                      ((uint32_t)0x00000030)        /*!< MODE1[1:0] 位（端口 x 模式位，引脚 1） */
#define  GPIO_CRL_MODE1_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  GPIO_CRL_MODE1_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  GPIO_CRL_MODE2                      ((uint32_t)0x00000300)        /*!< MODE2[1:0] 位（端口 x 模式位，引脚 2） */
#define  GPIO_CRL_MODE2_0                    ((uint32_t)0x00000100)        /*!< 位 0 */
#define  GPIO_CRL_MODE2_1                    ((uint32_t)0x00000200)        /*!< 位 1 */

#define  GPIO_CRL_MODE3                      ((uint32_t)0x00003000)        /*!< MODE3[1:0] 位（端口 x 模式位，引脚 3） */
#define  GPIO_CRL_MODE3_0                    ((uint32_t)0x00001000)        /*!< 位 0 */
#define  GPIO_CRL_MODE3_1                    ((uint32_t)0x00002000)        /*!< 位 1 */

#define  GPIO_CRL_MODE4                      ((uint32_t)0x00030000)        /*!< MODE4[1:0] 位（端口 x 模式位，引脚 4） */
#define  GPIO_CRL_MODE4_0                    ((uint32_t)0x00010000)        /*!< 位 0 */
#define  GPIO_CRL_MODE4_1                    ((uint32_t)0x00020000)        /*!< 位 1 */

#define  GPIO_CRL_MODE5                      ((uint32_t)0x00300000)        /*!< MODE5[1:0] 位（端口 x 模式位，引脚 5） */
#define  GPIO_CRL_MODE5_0                    ((uint32_t)0x00100000)        /*!< 位 0 */
#define  GPIO_CRL_MODE5_1                    ((uint32_t)0x00200000)        /*!< 位 1 */

#define  GPIO_CRL_MODE6                      ((uint32_t)0x03000000)        /*!< MODE6[1:0] 位（端口 x 模式位，引脚 6） */
#define  GPIO_CRL_MODE6_0                    ((uint32_t)0x01000000)        /*!< 位 0 */
#define  GPIO_CRL_MODE6_1                    ((uint32_t)0x02000000)        /*!< 位 1 */

#define  GPIO_CRL_MODE7                      ((uint32_t)0x30000000)        /*!< MODE7[1:0] 位（端口 x 模式位，引脚 7） */
#define  GPIO_CRL_MODE7_0                    ((uint32_t)0x10000000)        /*!< 位 0 */
#define  GPIO_CRL_MODE7_1                    ((uint32_t)0x20000000)        /*!< 位 1 */

#define  GPIO_CRL_CNF                        ((uint32_t)0xCCCCCCCC)        /*!< 端口 x 配置位 */

#define  GPIO_CRL_CNF0                       ((uint32_t)0x0000000C)        /*!< CNF0[1:0] 位（端口 x 配置位，引脚 0） */
#define  GPIO_CRL_CNF0_0                     ((uint32_t)0x00000004)        /*!< 位 0 */
#define  GPIO_CRL_CNF0_1                     ((uint32_t)0x00000008)        /*!< 位 1 */

#define  GPIO_CRL_CNF1                       ((uint32_t)0x000000C0)        /*!< CNF1[1:0] 位（端口 x 配置位，引脚 1） */
#define  GPIO_CRL_CNF1_0                     ((uint32_t)0x00000040)        /*!< 位 0 */
#define  GPIO_CRL_CNF1_1                     ((uint32_t)0x00000080)        /*!< 位 1 */

#define  GPIO_CRL_CNF2                       ((uint32_t)0x00000C00)        /*!< CNF2[1:0] 位（端口 x 配置位，引脚 2） */
#define  GPIO_CRL_CNF2_0                     ((uint32_t)0x00000400)        /*!< 位 0 */
#define  GPIO_CRL_CNF2_1                     ((uint32_t)0x00000800)        /*!< 位 1 */

#define  GPIO_CRL_CNF3                       ((uint32_t)0x0000C000)        /*!< CNF3[1:0] 位（端口 x 配置位，引脚 3） */
#define  GPIO_CRL_CNF3_0                     ((uint32_t)0x00004000)        /*!< 位 0 */
#define  GPIO_CRL_CNF3_1                     ((uint32_t)0x00008000)        /*!< 位 1 */

#define  GPIO_CRL_CNF4                       ((uint32_t)0x000C0000)        /*!< CNF4[1:0] 位（端口 x 配置位，引脚 4） */
#define  GPIO_CRL_CNF4_0                     ((uint32_t)0x00040000)        /*!< 位 0 */
#define  GPIO_CRL_CNF4_1                     ((uint32_t)0x00080000)        /*!< 位 1 */

#define  GPIO_CRL_CNF5                       ((uint32_t)0x00C00000)        /*!< CNF5[1:0] 位（端口 x 配置位，引脚 5） */
#define  GPIO_CRL_CNF5_0                     ((uint32_t)0x00400000)        /*!< 位 0 */
#define  GPIO_CRL_CNF5_1                     ((uint32_t)0x00800000)        /*!< 位 1 */

#define  GPIO_CRL_CNF6                       ((uint32_t)0x0C000000)        /*!< CNF6[1:0] 位（端口 x 配置位，引脚 6） */
#define  GPIO_CRL_CNF6_0                     ((uint32_t)0x04000000)        /*!< 位 0 */
#define  GPIO_CRL_CNF6_1                     ((uint32_t)0x08000000)        /*!< 位 1 */

#define  GPIO_CRL_CNF7                       ((uint32_t)0xC0000000)        /*!< CNF7[1:0] 位（端口 x 配置位，引脚 7） */
#define  GPIO_CRL_CNF7_0                     ((uint32_t)0x40000000)        /*!< 位 0 */
#define  GPIO_CRL_CNF7_1                     ((uint32_t)0x80000000)        /*!< 位 1 */

/******************* GPIO_CRH 寄存器的位定义 *****************/
#define  GPIO_CRH_MODE                       ((uint32_t)0x33333333)        /*!< 端口 x 模式位 */

#define  GPIO_CRH_MODE8                      ((uint32_t)0x00000003)        /*!< MODE8[1:0] 位（端口 x 模式位，引脚 8） */
#define  GPIO_CRH_MODE8_0                    ((uint32_t)0x00000001)        /*!< 位 0 */
#define  GPIO_CRH_MODE8_1                    ((uint32_t)0x00000002)        /*!< 位 1 */

#define  GPIO_CRH_MODE9                      ((uint32_t)0x00000030)        /*!< MODE9[1:0] 位（端口 x 模式位，引脚 9） */
#define  GPIO_CRH_MODE9_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  GPIO_CRH_MODE9_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  GPIO_CRH_MODE10                     ((uint32_t)0x00000300)        /*!< MODE10[1:0] 位（端口 x 模式位，引脚 10） */
#define  GPIO_CRH_MODE10_0                   ((uint32_t)0x00000100)        /*!< 位 0 */
#define  GPIO_CRH_MODE10_1                   ((uint32_t)0x00000200)        /*!< 位 1 */

#define  GPIO_CRH_MODE11                     ((uint32_t)0x00003000)        /*!< MODE11[1:0] 位（端口 x 模式位，引脚 11） */
#define  GPIO_CRH_MODE11_0                   ((uint32_t)0x00001000)        /*!< 位 0 */
#define  GPIO_CRH_MODE11_1                   ((uint32_t)0x00002000)        /*!< 位 1 */

#define  GPIO_CRH_MODE12                     ((uint32_t)0x00030000)        /*!< MODE12[1:0] 位（端口 x 模式位，引脚 12） */
#define  GPIO_CRH_MODE12_0                   ((uint32_t)0x00010000)        /*!< 位 0 */
#define  GPIO_CRH_MODE12_1                   ((uint32_t)0x00020000)        /*!< 位 1 */

#define  GPIO_CRH_MODE13                     ((uint32_t)0x00300000)        /*!< MODE13[1:0] 位（端口 x 模式位，引脚 13） */
#define  GPIO_CRH_MODE13_0                   ((uint32_t)0x00100000)        /*!< 位 0 */
#define  GPIO_CRH_MODE13_1                   ((uint32_t)0x00200000)        /*!< 位 1 */

#define  GPIO_CRH_MODE14                     ((uint32_t)0x03000000)        /*!< MODE14[1:0] 位（端口 x 模式位，引脚 14） */
#define  GPIO_CRH_MODE14_0                   ((uint32_t)0x01000000)        /*!< 位 0 */
#define  GPIO_CRH_MODE14_1                   ((uint32_t)0x02000000)        /*!< 位 1 */

#define  GPIO_CRH_MODE15                     ((uint32_t)0x30000000)        /*!< MODE15[1:0] 位（端口 x 模式位，引脚 15） */
#define  GPIO_CRH_MODE15_0                   ((uint32_t)0x10000000)        /*!< 位 0 */
#define  GPIO_CRH_MODE15_1                   ((uint32_t)0x20000000)        /*!< 位 1 */

#define  GPIO_CRH_CNF                        ((uint32_t)0xCCCCCCCC)        /*!< 端口 x 配置位 */

#define  GPIO_CRH_CNF8                       ((uint32_t)0x0000000C)        /*!< CNF8[1:0] 位（端口 x 配置位，引脚 8） */
#define  GPIO_CRH_CNF8_0                     ((uint32_t)0x00000004)        /*!< 位 0 */
#define  GPIO_CRH_CNF8_1                     ((uint32_t)0x00000008)        /*!< 位 1 */

#define  GPIO_CRH_CNF9                       ((uint32_t)0x000000C0)        /*!< CNF9[1:0] 位（端口 x 配置位，引脚 9） */
#define  GPIO_CRH_CNF9_0                     ((uint32_t)0x00000040)        /*!< 位 0 */
#define  GPIO_CRH_CNF9_1                     ((uint32_t)0x00000080)        /*!< 位 1 */

#define  GPIO_CRH_CNF10                      ((uint32_t)0x00000C00)        /*!< CNF10[1:0] 位（端口 x 配置位，引脚 10） */
#define  GPIO_CRH_CNF10_0                    ((uint32_t)0x00000400)        /*!< 位 0 */
#define  GPIO_CRH_CNF10_1                    ((uint32_t)0x00000800)        /*!< 位 1 */

#define  GPIO_CRH_CNF11                      ((uint32_t)0x0000C000)        /*!< CNF11[1:0] 位（端口 x 配置位，引脚 11） */
#define  GPIO_CRH_CNF11_0                    ((uint32_t)0x00004000)        /*!< 位 0 */
#define  GPIO_CRH_CNF11_1                    ((uint32_t)0x00008000)        /*!< 位 1 */

#define  GPIO_CRH_CNF12                      ((uint32_t)0x000C0000)        /*!< CNF12[1:0] 位（端口 x 配置位，引脚 12） */
#define  GPIO_CRH_CNF12_0                    ((uint32_t)0x00040000)        /*!< 位 0 */
#define  GPIO_CRH_CNF12_1                    ((uint32_t)0x00080000)        /*!< 位 1 */

#define  GPIO_CRH_CNF13                      ((uint32_t)0x00C00000)        /*!< CNF13[1:0] 位（端口 x 配置位，引脚 13） */
#define  GPIO_CRH_CNF13_0                    ((uint32_t)0x00400000)        /*!< 位 0 */
#define  GPIO_CRH_CNF13_1                    ((uint32_t)0x00800000)        /*!< 位 1 */

#define  GPIO_CRH_CNF14                      ((uint32_t)0x0C000000)        /*!< CNF14[1:0] 位（端口 x 配置位，引脚 14） */
#define  GPIO_CRH_CNF14_0                    ((uint32_t)0x04000000)        /*!< 位 0 */
#define  GPIO_CRH_CNF14_1                    ((uint32_t)0x08000000)        /*!< 位 1 */

#define  GPIO_CRH_CNF15                      ((uint32_t)0xC0000000)        /*!< CNF15[1:0] 位（端口 x 配置位，引脚 15） */
#define  GPIO_CRH_CNF15_0                    ((uint32_t)0x40000000)        /*!< 位 0 */
#define  GPIO_CRH_CNF15_1                    ((uint32_t)0x80000000)        /*!< 位 1 */

/*!<****************** GPIO_IDR 寄存器的位定义 ******************/
#define GPIO_IDR_IDR0                        ((uint16_t)0x0001)            /*!< 端口输入数据，位 0 */
#define GPIO_IDR_IDR1                        ((uint16_t)0x0002)            /*!< 端口输入数据，位 1 */
#define GPIO_IDR_IDR2                        ((uint16_t)0x0004)            /*!< 端口输入数据，位 2 */
#define GPIO_IDR_IDR3                        ((uint16_t)0x0008)            /*!< 端口输入数据，位 3 */
#define GPIO_IDR_IDR4                        ((uint16_t)0x0010)            /*!< 端口输入数据，位 4 */
#define GPIO_IDR_IDR5                        ((uint16_t)0x0020)            /*!< 端口输入数据，位 5 */
#define GPIO_IDR_IDR6                        ((uint16_t)0x0040)            /*!< 端口输入数据，位 6 */
#define GPIO_IDR_IDR7                        ((uint16_t)0x0080)            /*!< 端口输入数据，位 7 */
#define GPIO_IDR_IDR8                        ((uint16_t)0x0100)            /*!< 端口输入数据，位 8 */
#define GPIO_IDR_IDR9                        ((uint16_t)0x0200)            /*!< 端口输入数据，位 9 */
#define GPIO_IDR_IDR10                       ((uint16_t)0x0400)            /*!< 端口输入数据，位 10 */
#define GPIO_IDR_IDR11                       ((uint16_t)0x0800)            /*!< 端口输入数据，位 11 */
#define GPIO_IDR_IDR12                       ((uint16_t)0x1000)            /*!< 端口输入数据，位 12 */
#define GPIO_IDR_IDR13                       ((uint16_t)0x2000)            /*!< 端口输入数据，位 13 */
#define GPIO_IDR_IDR14                       ((uint16_t)0x4000)            /*!< 端口输入数据，位 14 */
#define GPIO_IDR_IDR15                       ((uint16_t)0x8000)            /*!< 端口输入数据，位 15 */

/******************* GPIO_ODR 寄存器的位定义 *****************/
#define GPIO_ODR_ODR0                        ((uint16_t)0x0001)            /*!< 端口输出数据，位 0 */
#define GPIO_ODR_ODR1                        ((uint16_t)0x0002)            /*!< 端口输出数据，位 1 */
#define GPIO_ODR_ODR2                        ((uint16_t)0x0004)            /*!< 端口输出数据，位 2 */
#define GPIO_ODR_ODR3                        ((uint16_t)0x0008)            /*!< 端口输出数据，位 3 */
#define GPIO_ODR_ODR4                        ((uint16_t)0x0010)            /*!< 端口输出数据，位 4 */
#define GPIO_ODR_ODR5                        ((uint16_t)0x0020)            /*!< 端口输出数据，位 5 */
#define GPIO_ODR_ODR6                        ((uint16_t)0x0040)            /*!< 端口输出数据，位 6 */
#define GPIO_ODR_ODR7                        ((uint16_t)0x0080)            /*!< 端口输出数据，位 7 */
#define GPIO_ODR_ODR8                        ((uint16_t)0x0100)            /*!< 端口输出数据，位 8 */
#define GPIO_ODR_ODR9                        ((uint16_t)0x0200)            /*!< 端口输出数据，位 9 */
#define GPIO_ODR_ODR10                       ((uint16_t)0x0400)            /*!< 端口输出数据，位 10 */
#define GPIO_ODR_ODR11                       ((uint16_t)0x0800)            /*!< 端口输出数据，位 11 */
#define GPIO_ODR_ODR12                       ((uint16_t)0x1000)            /*!< 端口输出数据，位 12 */
#define GPIO_ODR_ODR13                       ((uint16_t)0x2000)            /*!< 端口输出数据，位 13 */
#define GPIO_ODR_ODR14                       ((uint16_t)0x4000)            /*!< 端口输出数据，位 14 */
#define GPIO_ODR_ODR15                       ((uint16_t)0x8000)            /*!< 端口输出数据，位 15 */

/****************** GPIO_BSRR 寄存器的位定义 ****************/
#define GPIO_BSRR_BS0                        ((uint32_t)0x00000001)        /*!< 端口 x 置位位 0 */
#define GPIO_BSRR_BS1                        ((uint32_t)0x00000002)        /*!< 端口 x 置位位 1 */
#define GPIO_BSRR_BS2                        ((uint32_t)0x00000004)        /*!< 端口 x 置位位 2 */
#define GPIO_BSRR_BS3                        ((uint32_t)0x00000008)        /*!< 端口 x 置位位 3 */
#define GPIO_BSRR_BS4                        ((uint32_t)0x00000010)        /*!< 端口 x 置位位 4 */
#define GPIO_BSRR_BS5                        ((uint32_t)0x00000020)        /*!< 端口 x 置位位 5 */
#define GPIO_BSRR_BS6                        ((uint32_t)0x00000040)        /*!< 端口 x 置位位 6 */
#define GPIO_BSRR_BS7                        ((uint32_t)0x00000080)        /*!< 端口 x 置位位 7 */
#define GPIO_BSRR_BS8                        ((uint32_t)0x00000100)        /*!< 端口 x 置位位 8 */
#define GPIO_BSRR_BS9                        ((uint32_t)0x00000200)        /*!< 端口 x 置位位 9 */
#define GPIO_BSRR_BS10                       ((uint32_t)0x00000400)        /*!< 端口 x 置位位 10 */
#define GPIO_BSRR_BS11                       ((uint32_t)0x00000800)        /*!< 端口 x 置位位 11 */
#define GPIO_BSRR_BS12                       ((uint32_t)0x00001000)        /*!< 端口 x 置位位 12 */
#define GPIO_BSRR_BS13                       ((uint32_t)0x00002000)        /*!< 端口 x 置位位 13 */
#define GPIO_BSRR_BS14                       ((uint32_t)0x00004000)        /*!< 端口 x 置位位 14 */
#define GPIO_BSRR_BS15                       ((uint32_t)0x00008000)        /*!< 端口 x 置位位 15 */

#define GPIO_BSRR_BR0                        ((uint32_t)0x00010000)        /*!< 端口 x 复位位 0 */
#define GPIO_BSRR_BR1                        ((uint32_t)0x00020000)        /*!< 端口 x 复位位 1 */
#define GPIO_BSRR_BR2                        ((uint32_t)0x00040000)        /*!< 端口 x 复位位 2 */
#define GPIO_BSRR_BR3                        ((uint32_t)0x00080000)        /*!< 端口 x 复位位 3 */
#define GPIO_BSRR_BR4                        ((uint32_t)0x00100000)        /*!< 端口 x 复位位 4 */
#define GPIO_BSRR_BR5                        ((uint32_t)0x00200000)        /*!< 端口 x 复位位 5 */
#define GPIO_BSRR_BR6                        ((uint32_t)0x00400000)        /*!< 端口 x 复位位 6 */
#define GPIO_BSRR_BR7                        ((uint32_t)0x00800000)        /*!< 端口 x 复位位 7 */
#define GPIO_BSRR_BR8                        ((uint32_t)0x01000000)        /*!< 端口 x 复位位 8 */
#define GPIO_BSRR_BR9                        ((uint32_t)0x02000000)        /*!< 端口 x 复位位 9 */
#define GPIO_BSRR_BR10                       ((uint32_t)0x04000000)        /*!< 端口 x 复位位 10 */
#define GPIO_BSRR_BR11                       ((uint32_t)0x08000000)        /*!< 端口 x 复位位 11 */
#define GPIO_BSRR_BR12                       ((uint32_t)0x10000000)        /*!< 端口 x 复位位 12 */
#define GPIO_BSRR_BR13                       ((uint32_t)0x20000000)        /*!< 端口 x 复位位 13 */
#define GPIO_BSRR_BR14                       ((uint32_t)0x40000000)        /*!< 端口 x 复位位 14 */
#define GPIO_BSRR_BR15                       ((uint32_t)0x80000000)        /*!< 端口 x 复位位 15 */

/******************* GPIO_BRR 寄存器的位定义 *****************/
#define GPIO_BRR_BR0                         ((uint16_t)0x0001)            /*!< 端口 x 复位位 0 */
#define GPIO_BRR_BR1                         ((uint16_t)0x0002)            /*!< 端口 x 复位位 1 */
#define GPIO_BRR_BR2                         ((uint16_t)0x0004)            /*!< 端口 x 复位位 2 */
#define GPIO_BRR_BR3                         ((uint16_t)0x0008)            /*!< 端口 x 复位位 3 */
#define GPIO_BRR_BR4                         ((uint16_t)0x0010)            /*!< 端口 x 复位位 4 */
#define GPIO_BRR_BR5                         ((uint16_t)0x0020)            /*!< 端口 x 复位位 5 */
#define GPIO_BRR_BR6                         ((uint16_t)0x0040)            /*!< 端口 x 复位位 6 */
#define GPIO_BRR_BR7                         ((uint16_t)0x0080)            /*!< 端口 x 复位位 7 */
#define GPIO_BRR_BR8                         ((uint16_t)0x0100)            /*!< 端口 x 复位位 8 */
#define GPIO_BRR_BR9                         ((uint16_t)0x0200)            /*!< 端口 x 复位位 9 */
#define GPIO_BRR_BR10                        ((uint16_t)0x0400)            /*!< 端口 x 复位位 10 */
#define GPIO_BRR_BR11                        ((uint16_t)0x0800)            /*!< 端口 x 复位位 11 */
#define GPIO_BRR_BR12                        ((uint16_t)0x1000)            /*!< 端口 x 复位位 12 */
#define GPIO_BRR_BR13                        ((uint16_t)0x2000)            /*!< 端口 x 复位位 13 */
#define GPIO_BRR_BR14                        ((uint16_t)0x4000)            /*!< 端口 x 复位位 14 */
#define GPIO_BRR_BR15                        ((uint16_t)0x8000)            /*!< 端口 x 复位位 15 */

/****************** GPIO_LCKR 寄存器的位定义 ****************/
#define GPIO_LCKR_LCK0                       ((uint32_t)0x00000001)        /*!< 端口 x 锁定位 0 */
#define GPIO_LCKR_LCK1                       ((uint32_t)0x00000002)        /*!< 端口 x 锁定位 1 */
#define GPIO_LCKR_LCK2                       ((uint32_t)0x00000004)        /*!< 端口 x 锁定位 2 */
#define GPIO_LCKR_LCK3                       ((uint32_t)0x00000008)        /*!< 端口 x 锁定位 3 */
#define GPIO_LCKR_LCK4                       ((uint32_t)0x00000010)        /*!< 端口 x 锁定位 4 */
#define GPIO_LCKR_LCK5                       ((uint32_t)0x00000020)        /*!< 端口 x 锁定位 5 */
#define GPIO_LCKR_LCK6                       ((uint32_t)0x00000040)        /*!< 端口 x 锁定位 6 */
#define GPIO_LCKR_LCK7                       ((uint32_t)0x00000080)        /*!< 端口 x 锁定位 7 */
#define GPIO_LCKR_LCK8                       ((uint32_t)0x00000100)        /*!< 端口 x 锁定位 8 */
#define GPIO_LCKR_LCK9                       ((uint32_t)0x00000200)        /*!< 端口 x 锁定位 9 */
#define GPIO_LCKR_LCK10                      ((uint32_t)0x00000400)        /*!< 端口 x 锁定位 10 */
#define GPIO_LCKR_LCK11                      ((uint32_t)0x00000800)        /*!< 端口 x 锁定位 11 */
#define GPIO_LCKR_LCK12                      ((uint32_t)0x00001000)        /*!< 端口 x 锁定位 12 */
#define GPIO_LCKR_LCK13                      ((uint32_t)0x00002000)        /*!< 端口 x 锁定位 13 */
#define GPIO_LCKR_LCK14                      ((uint32_t)0x00004000)        /*!< 端口 x 锁定位 14 */
#define GPIO_LCKR_LCK15                      ((uint32_t)0x00008000)        /*!< 端口 x 锁定位 15 */
#define GPIO_LCKR_LCKK                       ((uint32_t)0x00010000)        /*!< 锁定键 */

/*----------------------------------------------------------------------------*/

/****************** AFIO_EVCR 寄存器的位定义 ****************/
#define AFIO_EVCR_PIN                        ((uint8_t)0x0F)               /*!< PIN[3:0] 位（引脚选择） */
#define AFIO_EVCR_PIN_0                      ((uint8_t)0x01)               /*!< 位 0 */
#define AFIO_EVCR_PIN_1                      ((uint8_t)0x02)               /*!< 位 1 */
#define AFIO_EVCR_PIN_2                      ((uint8_t)0x04)               /*!< 位 2 */
#define AFIO_EVCR_PIN_3                      ((uint8_t)0x08)               /*!< 位 3 */

/*!< PIN 配置 */
#define AFIO_EVCR_PIN_PX0                    ((uint8_t)0x00)               /*!< 选择引脚 0 */
#define AFIO_EVCR_PIN_PX1                    ((uint8_t)0x01)               /*!< 选择引脚 1 */
#define AFIO_EVCR_PIN_PX2                    ((uint8_t)0x02)               /*!< 选择引脚 2 */
#define AFIO_EVCR_PIN_PX3                    ((uint8_t)0x03)               /*!< 选择引脚 3 */
#define AFIO_EVCR_PIN_PX4                    ((uint8_t)0x04)               /*!< 选择引脚 4 */
#define AFIO_EVCR_PIN_PX5                    ((uint8_t)0x05)               /*!< 选择引脚 5 */
#define AFIO_EVCR_PIN_PX6                    ((uint8_t)0x06)               /*!< 选择引脚 6 */
#define AFIO_EVCR_PIN_PX7                    ((uint8_t)0x07)               /*!< 选择引脚 7 */
#define AFIO_EVCR_PIN_PX8                    ((uint8_t)0x08)               /*!< 选择引脚 8 */
#define AFIO_EVCR_PIN_PX9                    ((uint8_t)0x09)               /*!< 选择引脚 9 */
#define AFIO_EVCR_PIN_PX10                   ((uint8_t)0x0A)               /*!< 选择引脚 10 */
#define AFIO_EVCR_PIN_PX11                   ((uint8_t)0x0B)               /*!< 选择引脚 11 */
#define AFIO_EVCR_PIN_PX12                   ((uint8_t)0x0C)               /*!< 选择引脚 12 */
#define AFIO_EVCR_PIN_PX13                   ((uint8_t)0x0D)               /*!< 选择引脚 13 */
#define AFIO_EVCR_PIN_PX14                   ((uint8_t)0x0E)               /*!< 选择引脚 14 */
#define AFIO_EVCR_PIN_PX15                   ((uint8_t)0x0F)               /*!< 选择引脚 15 */

#define AFIO_EVCR_PORT                       ((uint8_t)0x70)               /*!< PORT[2:0] 位（端口选择） */
#define AFIO_EVCR_PORT_0                     ((uint8_t)0x10)               /*!< 位 0 */
#define AFIO_EVCR_PORT_1                     ((uint8_t)0x20)               /*!< 位 1 */
#define AFIO_EVCR_PORT_2                     ((uint8_t)0x40)               /*!< 位 2 */

/*!< PORT 配置 */
#define AFIO_EVCR_PORT_PA                    ((uint8_t)0x00)               /*!< 选择端口 A */
#define AFIO_EVCR_PORT_PB                    ((uint8_t)0x10)               /*!< 选择端口 B */
#define AFIO_EVCR_PORT_PC                    ((uint8_t)0x20)               /*!< 选择端口 C */
#define AFIO_EVCR_PORT_PD                    ((uint8_t)0x30)               /*!< 选择端口 D */
#define AFIO_EVCR_PORT_PE                    ((uint8_t)0x40)               /*!< 选择端口 E */

#define AFIO_EVCR_EVOE                       ((uint8_t)0x80)               /*!< 事件输出使能 */

/****************** AFIO_MAPR 寄存器的位定义 ****************/
#define AFIO_MAPR_SPI1_REMAP                 ((uint32_t)0x00000001)        /*!< SPI1 重映射 */
#define AFIO_MAPR_I2C1_REMAP                 ((uint32_t)0x00000002)        /*!< I2C1 重映射 */
#define AFIO_MAPR_USART1_REMAP               ((uint32_t)0x00000004)        /*!< USART1 重映射 */
#define AFIO_MAPR_USART2_REMAP               ((uint32_t)0x00000008)        /*!< USART2 重映射 */

#define AFIO_MAPR_USART3_REMAP               ((uint32_t)0x00000030)        /*!< USART3_REMAP[1:0] 位（USART3 重映射） */
#define AFIO_MAPR_USART3_REMAP_0             ((uint32_t)0x00000010)        /*!< 位 0 */
#define AFIO_MAPR_USART3_REMAP_1             ((uint32_t)0x00000020)        /*!< 位 1 */

/* USART3_REMAP 配置 */
#define AFIO_MAPR_USART3_REMAP_NOREMAP       ((uint32_t)0x00000000)        /*!< 不重映射（TX/PB10, RX/PB11, CK/PB12, CTS/PB13, RTS/PB14） */
#define AFIO_MAPR_USART3_REMAP_PARTIALREMAP  ((uint32_t)0x00000010)        /*!< 部分重映射（TX/PC10, RX/PC11, CK/PC12, CTS/PB13, RTS/PB14） */
#define AFIO_MAPR_USART3_REMAP_FULLREMAP     ((uint32_t)0x00000030)        /*!< 完全重映射（TX/PD8, RX/PD9, CK/PD10, CTS/PD11, RTS/PD12） */

#define AFIO_MAPR_TIM1_REMAP                 ((uint32_t)0x000000C0)        /*!< TIM1_REMAP[1:0] 位（TIM1 重映射） */
#define AFIO_MAPR_TIM1_REMAP_0               ((uint32_t)0x00000040)        /*!< 位 0 */
#define AFIO_MAPR_TIM1_REMAP_1               ((uint32_t)0x00000080)        /*!< 位 1 */

/*!< TIM1_REMAP 配置 */
#define AFIO_MAPR_TIM1_REMAP_NOREMAP         ((uint32_t)0x00000000)        /*!< 不重映射（ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PB12, CH1N/PB13, CH2N/PB14, CH3N/PB15） */
#define AFIO_MAPR_TIM1_REMAP_PARTIALREMAP    ((uint32_t)0x00000040)        /*!< 部分重映射（ETR/PA12, CH1/PA8, CH2/PA9, CH3/PA10, CH4/PA11, BKIN/PA6, CH1N/PA7, CH2N/PB0, CH3N/PB1） */
#define AFIO_MAPR_TIM1_REMAP_FULLREMAP       ((uint32_t)0x000000C0)        /*!< 完全重映射（ETR/PE7, CH1/PE9, CH2/PE11, CH3/PE13, CH4/PE14, BKIN/PE15, CH1N/PE8, CH2N/PE10, CH3N/PE12） */

#define AFIO_MAPR_TIM2_REMAP                 ((uint32_t)0x00000300)        /*!< TIM2_REMAP[1:0] 位（TIM2 重映射） */
#define AFIO_MAPR_TIM2_REMAP_0               ((uint32_t)0x00000100)        /*!< 位 0 */
#define AFIO_MAPR_TIM2_REMAP_1               ((uint32_t)0x00000200)        /*!< 位 1 */

/*!< TIM2_REMAP 配置 */
#define AFIO_MAPR_TIM2_REMAP_NOREMAP         ((uint32_t)0x00000000)        /*!< 不重映射（CH1/ETR/PA0, CH2/PA1, CH3/PA2, CH4/PA3） */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP1   ((uint32_t)0x00000100)        /*!< 部分重映射（CH1/ETR/PA15, CH2/PB3, CH3/PA2, CH4/PA3） */
#define AFIO_MAPR_TIM2_REMAP_PARTIALREMAP2   ((uint32_t)0x00000200)        /*!< 部分重映射（CH1/ETR/PA0, CH2/PA1, CH3/PB10, CH4/PB11） */
#define AFIO_MAPR_TIM2_REMAP_FULLREMAP       ((uint32_t)0x00000300)        /*!< 完全重映射（CH1/ETR/PA15, CH2/PB3, CH3/PB10, CH4/PB11） */

#define AFIO_MAPR_TIM3_REMAP                 ((uint32_t)0x00000C00)        /*!< TIM3_REMAP[1:0] 位（TIM3 重映射） */
#define AFIO_MAPR_TIM3_REMAP_0               ((uint32_t)0x00000400)        /*!< 位 0 */
#define AFIO_MAPR_TIM3_REMAP_1               ((uint32_t)0x00000800)        /*!< 位 1 */

/*!< TIM3_REMAP 配置 */
#define AFIO_MAPR_TIM3_REMAP_NOREMAP         ((uint32_t)0x00000000)        /*!< 不重映射（CH1/PA6, CH2/PA7, CH3/PB0, CH4/PB1） */
#define AFIO_MAPR_TIM3_REMAP_PARTIALREMAP    ((uint32_t)0x00000800)        /*!< 部分重映射（CH1/PB4, CH2/PB5, CH3/PB0, CH4/PB1） */
#define AFIO_MAPR_TIM3_REMAP_FULLREMAP       ((uint32_t)0x00000C00)        /*!< 完全重映射（CH1/PC6, CH2/PC7, CH3/PC8, CH4/PC9） */

#define AFIO_MAPR_TIM4_REMAP                 ((uint32_t)0x00001000)        /*!< TIM4_REMAP 位（TIM4 重映射） */

#define AFIO_MAPR_CAN_REMAP                  ((uint32_t)0x00006000)        /*!< CAN_REMAP[1:0] 位（CAN 复用功能重映射） */
#define AFIO_MAPR_CAN_REMAP_0                ((uint32_t)0x00002000)        /*!< 位 0 */
#define AFIO_MAPR_CAN_REMAP_1                ((uint32_t)0x00004000)        /*!< 位 1 */

/*!< CAN_REMAP 配置 */
#define AFIO_MAPR_CAN_REMAP_REMAP1           ((uint32_t)0x00000000)        /*!< CANRX 映射到 PA11，CANTX 映射到 PA12 */
#define AFIO_MAPR_CAN_REMAP_REMAP2           ((uint32_t)0x00004000)        /*!< CANRX 映射到 PB8，CANTX 映射到 PB9 */
#define AFIO_MAPR_CAN_REMAP_REMAP3           ((uint32_t)0x00006000)        /*!< CANRX 映射到 PD0，CANTX 映射到 PD1 */

#define AFIO_MAPR_PD01_REMAP                 ((uint32_t)0x00008000)        /*!< Port D0/Port D1 映射到 OSC_IN/OSC_OUT */
#define AFIO_MAPR_TIM5CH4_IREMAP             ((uint32_t)0x00010000)        /*!< TIM5 通道 4 内部重映射 */
#define AFIO_MAPR_ADC1_ETRGINJ_REMAP         ((uint32_t)0x00020000)        /*!< ADC 1 外部触发注入转换重映射 */
#define AFIO_MAPR_ADC1_ETRGREG_REMAP         ((uint32_t)0x00040000)        /*!< ADC 1 外部触发规则转换重映射 */
#define AFIO_MAPR_ADC2_ETRGINJ_REMAP         ((uint32_t)0x00080000)        /*!< ADC 2 外部触发注入转换重映射 */
#define AFIO_MAPR_ADC2_ETRGREG_REMAP         ((uint32_t)0x00100000)        /*!< ADC 2 外部触发规则转换重映射 */

/*!< SWJ_CFG 配置 */
#define AFIO_MAPR_SWJ_CFG                    ((uint32_t)0x07000000)        /*!< SWJ_CFG[2:0] 位（串行线 JTAG 配置） */
#define AFIO_MAPR_SWJ_CFG_0                  ((uint32_t)0x01000000)        /*!< 位 0 */
#define AFIO_MAPR_SWJ_CFG_1                  ((uint32_t)0x02000000)        /*!< 位 1 */
#define AFIO_MAPR_SWJ_CFG_2                  ((uint32_t)0x04000000)        /*!< 位 2 */

#define AFIO_MAPR_SWJ_CFG_RESET              ((uint32_t)0x00000000)        /*!< 完整 SWJ（JTAG-DP + SW-DP）：复位状态 */
#define AFIO_MAPR_SWJ_CFG_NOJNTRST           ((uint32_t)0x01000000)        /*!< 完整 SWJ（JTAG-DP + SW-DP），但无 JNTRST */
#define AFIO_MAPR_SWJ_CFG_JTAGDISABLE        ((uint32_t)0x02000000)        /*!< JTAG-DP 失能，SW-DP 使能 */
#define AFIO_MAPR_SWJ_CFG_DISABLE            ((uint32_t)0x04000000)        /*!< JTAG-DP 失能，SW-DP 失能 */

#ifdef STM32F10X_CL
/*!< ETH_REMAP 配置 */
 #define AFIO_MAPR_ETH_REMAP                  ((uint32_t)0x00200000)        /*!< SPI3_REMAP 位（以太网 MAC I/O 重映射） */

/*!< CAN2_REMAP 配置 */
 #define AFIO_MAPR_CAN2_REMAP                 ((uint32_t)0x00400000)        /*!< CAN2_REMAP 位（CAN2 I/O 重映射） */

/*!< MII_RMII_SEL 配置 */
 #define AFIO_MAPR_MII_RMII_SEL               ((uint32_t)0x00800000)        /*!< MII_RMII_SEL 位（以太网 MII 或 RMII 选择） */

/*!< SPI3_REMAP 配置 */
 #define AFIO_MAPR_SPI3_REMAP                 ((uint32_t)0x10000000)        /*!< SPI3_REMAP 位（SPI3 重映射） */

/*!< TIM2ITR1_IREMAP 配置 */
 #define AFIO_MAPR_TIM2ITR1_IREMAP            ((uint32_t)0x20000000)        /*!< TIM2ITR1_IREMAP 位（TIM2 内部触发 1 重映射） */

/*!< PTP_PPS_REMAP 配置 */
 #define AFIO_MAPR_PTP_PPS_REMAP              ((uint32_t)0x40000000)        /*!< PTP_PPS_REMAP 位（以太网 PTP PPS 重映射） */
#endif

/***************** AFIO_EXTICR1 寄存器的位定义 ***************/
#define AFIO_EXTICR1_EXTI0                   ((uint16_t)0x000F)            /*!< EXTI 0 配置 */
#define AFIO_EXTICR1_EXTI1                   ((uint16_t)0x00F0)            /*!< EXTI 1 配置 */
#define AFIO_EXTICR1_EXTI2                   ((uint16_t)0x0F00)            /*!< EXTI 2 配置 */
#define AFIO_EXTICR1_EXTI3                   ((uint16_t)0xF000)            /*!< EXTI 3 配置 */

/*!< EXTI0 配置 */
#define AFIO_EXTICR1_EXTI0_PA                ((uint16_t)0x0000)            /*!< PA[0] 引脚 */
#define AFIO_EXTICR1_EXTI0_PB                ((uint16_t)0x0001)            /*!< PB[0] 引脚 */
#define AFIO_EXTICR1_EXTI0_PC                ((uint16_t)0x0002)            /*!< PC[0] 引脚 */
#define AFIO_EXTICR1_EXTI0_PD                ((uint16_t)0x0003)            /*!< PD[0] 引脚 */
#define AFIO_EXTICR1_EXTI0_PE                ((uint16_t)0x0004)            /*!< PE[0] 引脚 */
#define AFIO_EXTICR1_EXTI0_PF                ((uint16_t)0x0005)            /*!< PF[0] 引脚 */
#define AFIO_EXTICR1_EXTI0_PG                ((uint16_t)0x0006)            /*!< PG[0] 引脚 */

/*!< EXTI1 配置 */
#define AFIO_EXTICR1_EXTI1_PA                ((uint16_t)0x0000)            /*!< PA[1] 引脚 */
#define AFIO_EXTICR1_EXTI1_PB                ((uint16_t)0x0010)            /*!< PB[1] 引脚 */
#define AFIO_EXTICR1_EXTI1_PC                ((uint16_t)0x0020)            /*!< PC[1] 引脚 */
#define AFIO_EXTICR1_EXTI1_PD                ((uint16_t)0x0030)            /*!< PD[1] 引脚 */
#define AFIO_EXTICR1_EXTI1_PE                ((uint16_t)0x0040)            /*!< PE[1] 引脚 */
#define AFIO_EXTICR1_EXTI1_PF                ((uint16_t)0x0050)            /*!< PF[1] 引脚 */
#define AFIO_EXTICR1_EXTI1_PG                ((uint16_t)0x0060)            /*!< PG[1] 引脚 */

/*!< EXTI2 配置 */  
#define AFIO_EXTICR1_EXTI2_PA                ((uint16_t)0x0000)            /*!< PA[2] 引脚 */
#define AFIO_EXTICR1_EXTI2_PB                ((uint16_t)0x0100)            /*!< PB[2] 引脚 */
#define AFIO_EXTICR1_EXTI2_PC                ((uint16_t)0x0200)            /*!< PC[2] 引脚 */
#define AFIO_EXTICR1_EXTI2_PD                ((uint16_t)0x0300)            /*!< PD[2] 引脚 */
#define AFIO_EXTICR1_EXTI2_PE                ((uint16_t)0x0400)            /*!< PE[2] 引脚 */
#define AFIO_EXTICR1_EXTI2_PF                ((uint16_t)0x0500)            /*!< PF[2] 引脚 */
#define AFIO_EXTICR1_EXTI2_PG                ((uint16_t)0x0600)            /*!< PG[2] 引脚 */

/*!< EXTI3 配置 */
#define AFIO_EXTICR1_EXTI3_PA                ((uint16_t)0x0000)            /*!< PA[3] 引脚 */
#define AFIO_EXTICR1_EXTI3_PB                ((uint16_t)0x1000)            /*!< PB[3] 引脚 */
#define AFIO_EXTICR1_EXTI3_PC                ((uint16_t)0x2000)            /*!< PC[3] 引脚 */
#define AFIO_EXTICR1_EXTI3_PD                ((uint16_t)0x3000)            /*!< PD[3] 引脚 */
#define AFIO_EXTICR1_EXTI3_PE                ((uint16_t)0x4000)            /*!< PE[3] 引脚 */
#define AFIO_EXTICR1_EXTI3_PF                ((uint16_t)0x5000)            /*!< PF[3] 引脚 */
#define AFIO_EXTICR1_EXTI3_PG                ((uint16_t)0x6000)            /*!< PG[3] 引脚 */

/***************** AFIO_EXTICR2 寄存器的位定义 ***************/
#define AFIO_EXTICR2_EXTI4                   ((uint16_t)0x000F)            /*!< EXTI 4 配置 */
#define AFIO_EXTICR2_EXTI5                   ((uint16_t)0x00F0)            /*!< EXTI 5 配置 */
#define AFIO_EXTICR2_EXTI6                   ((uint16_t)0x0F00)            /*!< EXTI 6 配置 */
#define AFIO_EXTICR2_EXTI7                   ((uint16_t)0xF000)            /*!< EXTI 7 配置 */

/*!< EXTI4 配置 */
#define AFIO_EXTICR2_EXTI4_PA                ((uint16_t)0x0000)            /*!< PA[4] 引脚 */
#define AFIO_EXTICR2_EXTI4_PB                ((uint16_t)0x0001)            /*!< PB[4] 引脚 */
#define AFIO_EXTICR2_EXTI4_PC                ((uint16_t)0x0002)            /*!< PC[4] 引脚 */
#define AFIO_EXTICR2_EXTI4_PD                ((uint16_t)0x0003)            /*!< PD[4] 引脚 */
#define AFIO_EXTICR2_EXTI4_PE                ((uint16_t)0x0004)            /*!< PE[4] 引脚 */
#define AFIO_EXTICR2_EXTI4_PF                ((uint16_t)0x0005)            /*!< PF[4] 引脚 */
#define AFIO_EXTICR2_EXTI4_PG                ((uint16_t)0x0006)            /*!< PG[4] 引脚 */

/* EXTI5 配置 */
#define AFIO_EXTICR2_EXTI5_PA                ((uint16_t)0x0000)            /*!< PA[5] 引脚 */
#define AFIO_EXTICR2_EXTI5_PB                ((uint16_t)0x0010)            /*!< PB[5] 引脚 */
#define AFIO_EXTICR2_EXTI5_PC                ((uint16_t)0x0020)            /*!< PC[5] 引脚 */
#define AFIO_EXTICR2_EXTI5_PD                ((uint16_t)0x0030)            /*!< PD[5] 引脚 */
#define AFIO_EXTICR2_EXTI5_PE                ((uint16_t)0x0040)            /*!< PE[5] 引脚 */
#define AFIO_EXTICR2_EXTI5_PF                ((uint16_t)0x0050)            /*!< PF[5] 引脚 */
#define AFIO_EXTICR2_EXTI5_PG                ((uint16_t)0x0060)            /*!< PG[5] 引脚 */

/*!< EXTI6 配置 */  
#define AFIO_EXTICR2_EXTI6_PA                ((uint16_t)0x0000)            /*!< PA[6] 引脚 */
#define AFIO_EXTICR2_EXTI6_PB                ((uint16_t)0x0100)            /*!< PB[6] 引脚 */
#define AFIO_EXTICR2_EXTI6_PC                ((uint16_t)0x0200)            /*!< PC[6] 引脚 */
#define AFIO_EXTICR2_EXTI6_PD                ((uint16_t)0x0300)            /*!< PD[6] 引脚 */
#define AFIO_EXTICR2_EXTI6_PE                ((uint16_t)0x0400)            /*!< PE[6] 引脚 */
#define AFIO_EXTICR2_EXTI6_PF                ((uint16_t)0x0500)            /*!< PF[6] 引脚 */
#define AFIO_EXTICR2_EXTI6_PG                ((uint16_t)0x0600)            /*!< PG[6] 引脚 */

/*!< EXTI7 配置 */
#define AFIO_EXTICR2_EXTI7_PA                ((uint16_t)0x0000)            /*!< PA[7] 引脚 */
#define AFIO_EXTICR2_EXTI7_PB                ((uint16_t)0x1000)            /*!< PB[7] 引脚 */
#define AFIO_EXTICR2_EXTI7_PC                ((uint16_t)0x2000)            /*!< PC[7] 引脚 */
#define AFIO_EXTICR2_EXTI7_PD                ((uint16_t)0x3000)            /*!< PD[7] 引脚 */
#define AFIO_EXTICR2_EXTI7_PE                ((uint16_t)0x4000)            /*!< PE[7] 引脚 */
#define AFIO_EXTICR2_EXTI7_PF                ((uint16_t)0x5000)            /*!< PF[7] 引脚 */
#define AFIO_EXTICR2_EXTI7_PG                ((uint16_t)0x6000)            /*!< PG[7] 引脚 */

/***************** AFIO_EXTICR3 寄存器的位定义 ***************/
#define AFIO_EXTICR3_EXTI8                   ((uint16_t)0x000F)            /*!< EXTI 8 配置 */
#define AFIO_EXTICR3_EXTI9                   ((uint16_t)0x00F0)            /*!< EXTI 9 配置 */
#define AFIO_EXTICR3_EXTI10                  ((uint16_t)0x0F00)            /*!< EXTI 10 配置 */
#define AFIO_EXTICR3_EXTI11                  ((uint16_t)0xF000)            /*!< EXTI 11 配置 */

/*!< EXTI8 配置 */
#define AFIO_EXTICR3_EXTI8_PA                ((uint16_t)0x0000)            /*!< PA[8] 引脚 */
#define AFIO_EXTICR3_EXTI8_PB                ((uint16_t)0x0001)            /*!< PB[8] 引脚 */
#define AFIO_EXTICR3_EXTI8_PC                ((uint16_t)0x0002)            /*!< PC[8] 引脚 */
#define AFIO_EXTICR3_EXTI8_PD                ((uint16_t)0x0003)            /*!< PD[8] 引脚 */
#define AFIO_EXTICR3_EXTI8_PE                ((uint16_t)0x0004)            /*!< PE[8] 引脚 */
#define AFIO_EXTICR3_EXTI8_PF                ((uint16_t)0x0005)            /*!< PF[8] 引脚 */
#define AFIO_EXTICR3_EXTI8_PG                ((uint16_t)0x0006)            /*!< PG[8] 引脚 */

/*!< EXTI9 配置 */
#define AFIO_EXTICR3_EXTI9_PA                ((uint16_t)0x0000)            /*!< PA[9] 引脚 */
#define AFIO_EXTICR3_EXTI9_PB                ((uint16_t)0x0010)            /*!< PB[9] 引脚 */
#define AFIO_EXTICR3_EXTI9_PC                ((uint16_t)0x0020)            /*!< PC[9] 引脚 */
#define AFIO_EXTICR3_EXTI9_PD                ((uint16_t)0x0030)            /*!< PD[9] 引脚 */
#define AFIO_EXTICR3_EXTI9_PE                ((uint16_t)0x0040)            /*!< PE[9] 引脚 */
#define AFIO_EXTICR3_EXTI9_PF                ((uint16_t)0x0050)            /*!< PF[9] 引脚 */
#define AFIO_EXTICR3_EXTI9_PG                ((uint16_t)0x0060)            /*!< PG[9] 引脚 */

/*!< EXTI10 配置 */  
#define AFIO_EXTICR3_EXTI10_PA               ((uint16_t)0x0000)            /*!< PA[10] 引脚 */
#define AFIO_EXTICR3_EXTI10_PB               ((uint16_t)0x0100)            /*!< PB[10] 引脚 */
#define AFIO_EXTICR3_EXTI10_PC               ((uint16_t)0x0200)            /*!< PC[10] 引脚 */
#define AFIO_EXTICR3_EXTI10_PD               ((uint16_t)0x0300)            /*!< PD[10] 引脚 */
#define AFIO_EXTICR3_EXTI10_PE               ((uint16_t)0x0400)            /*!< PE[10] 引脚 */
#define AFIO_EXTICR3_EXTI10_PF               ((uint16_t)0x0500)            /*!< PF[10] 引脚 */
#define AFIO_EXTICR3_EXTI10_PG               ((uint16_t)0x0600)            /*!< PG[10] 引脚 */

/*!< EXTI11 配置 */
#define AFIO_EXTICR3_EXTI11_PA               ((uint16_t)0x0000)            /*!< PA[11] 引脚 */
#define AFIO_EXTICR3_EXTI11_PB               ((uint16_t)0x1000)            /*!< PB[11] 引脚 */
#define AFIO_EXTICR3_EXTI11_PC               ((uint16_t)0x2000)            /*!< PC[11] 引脚 */
#define AFIO_EXTICR3_EXTI11_PD               ((uint16_t)0x3000)            /*!< PD[11] 引脚 */
#define AFIO_EXTICR3_EXTI11_PE               ((uint16_t)0x4000)            /*!< PE[11] 引脚 */
#define AFIO_EXTICR3_EXTI11_PF               ((uint16_t)0x5000)            /*!< PF[11] 引脚 */
#define AFIO_EXTICR3_EXTI11_PG               ((uint16_t)0x6000)            /*!< PG[11] 引脚 */

/***************** AFIO_EXTICR4 寄存器的位定义 ***************/
#define AFIO_EXTICR4_EXTI12                  ((uint16_t)0x000F)            /*!< EXTI 12 配置 */
#define AFIO_EXTICR4_EXTI13                  ((uint16_t)0x00F0)            /*!< EXTI 13 配置 */
#define AFIO_EXTICR4_EXTI14                  ((uint16_t)0x0F00)            /*!< EXTI 14 配置 */
#define AFIO_EXTICR4_EXTI15                  ((uint16_t)0xF000)            /*!< EXTI 15 配置 */

/* EXTI12 配置 */
#define AFIO_EXTICR4_EXTI12_PA               ((uint16_t)0x0000)            /*!< PA[12] 引脚 */
#define AFIO_EXTICR4_EXTI12_PB               ((uint16_t)0x0001)            /*!< PB[12] 引脚 */
#define AFIO_EXTICR4_EXTI12_PC               ((uint16_t)0x0002)            /*!< PC[12] 引脚 */
#define AFIO_EXTICR4_EXTI12_PD               ((uint16_t)0x0003)            /*!< PD[12] 引脚 */
#define AFIO_EXTICR4_EXTI12_PE               ((uint16_t)0x0004)            /*!< PE[12] 引脚 */
#define AFIO_EXTICR4_EXTI12_PF               ((uint16_t)0x0005)            /*!< PF[12] 引脚 */
#define AFIO_EXTICR4_EXTI12_PG               ((uint16_t)0x0006)            /*!< PG[12] 引脚 */

/* EXTI13 配置 */
#define AFIO_EXTICR4_EXTI13_PA               ((uint16_t)0x0000)            /*!< PA[13] 引脚 */
#define AFIO_EXTICR4_EXTI13_PB               ((uint16_t)0x0010)            /*!< PB[13] 引脚 */
#define AFIO_EXTICR4_EXTI13_PC               ((uint16_t)0x0020)            /*!< PC[13] 引脚 */
#define AFIO_EXTICR4_EXTI13_PD               ((uint16_t)0x0030)            /*!< PD[13] 引脚 */
#define AFIO_EXTICR4_EXTI13_PE               ((uint16_t)0x0040)            /*!< PE[13] 引脚 */
#define AFIO_EXTICR4_EXTI13_PF               ((uint16_t)0x0050)            /*!< PF[13] 引脚 */
#define AFIO_EXTICR4_EXTI13_PG               ((uint16_t)0x0060)            /*!< PG[13] 引脚 */

/*!< EXTI14 配置 */  
#define AFIO_EXTICR4_EXTI14_PA               ((uint16_t)0x0000)            /*!< PA[14] 引脚 */
#define AFIO_EXTICR4_EXTI14_PB               ((uint16_t)0x0100)            /*!< PB[14] 引脚 */
#define AFIO_EXTICR4_EXTI14_PC               ((uint16_t)0x0200)            /*!< PC[14] 引脚 */
#define AFIO_EXTICR4_EXTI14_PD               ((uint16_t)0x0300)            /*!< PD[14] 引脚 */
#define AFIO_EXTICR4_EXTI14_PE               ((uint16_t)0x0400)            /*!< PE[14] 引脚 */
#define AFIO_EXTICR4_EXTI14_PF               ((uint16_t)0x0500)            /*!< PF[14] 引脚 */
#define AFIO_EXTICR4_EXTI14_PG               ((uint16_t)0x0600)            /*!< PG[14] 引脚 */

/*!< EXTI15 配置 */
#define AFIO_EXTICR4_EXTI15_PA               ((uint16_t)0x0000)            /*!< PA[15] 引脚 */
#define AFIO_EXTICR4_EXTI15_PB               ((uint16_t)0x1000)            /*!< PB[15] 引脚 */
#define AFIO_EXTICR4_EXTI15_PC               ((uint16_t)0x2000)            /*!< PC[15] 引脚 */
#define AFIO_EXTICR4_EXTI15_PD               ((uint16_t)0x3000)            /*!< PD[15] 引脚 */
#define AFIO_EXTICR4_EXTI15_PE               ((uint16_t)0x4000)            /*!< PE[15] 引脚 */
#define AFIO_EXTICR4_EXTI15_PF               ((uint16_t)0x5000)            /*!< PF[15] 引脚 */
#define AFIO_EXTICR4_EXTI15_PG               ((uint16_t)0x6000)            /*!< PG[15] 引脚 */

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
/****************** AFIO_MAPR2 寄存器的位定义 ****************/
#define AFIO_MAPR2_TIM15_REMAP               ((uint32_t)0x00000001)        /*!< TIM15 重映射 */
#define AFIO_MAPR2_TIM16_REMAP               ((uint32_t)0x00000002)        /*!< TIM16 重映射 */
#define AFIO_MAPR2_TIM17_REMAP               ((uint32_t)0x00000004)        /*!< TIM17 重映射 */
#define AFIO_MAPR2_CEC_REMAP                 ((uint32_t)0x00000008)        /*!< CEC 重映射 */
#define AFIO_MAPR2_TIM1_DMA_REMAP            ((uint32_t)0x00000010)        /*!< TIM1_DMA 重映射 */
#endif

#ifdef STM32F10X_HD_VL
#define AFIO_MAPR2_TIM13_REMAP               ((uint32_t)0x00000100)        /*!< TIM13 重映射 */
#define AFIO_MAPR2_TIM14_REMAP               ((uint32_t)0x00000200)        /*!< TIM14 重映射 */
#define AFIO_MAPR2_FSMC_NADV_REMAP           ((uint32_t)0x00000400)        /*!< FSMC NADV 重映射 */
#define AFIO_MAPR2_TIM67_DAC_DMA_REMAP       ((uint32_t)0x00000800)        /*!< TIM6/TIM7 和 DAC DMA 重映射 */
#define AFIO_MAPR2_TIM12_REMAP               ((uint32_t)0x00001000)        /*!< TIM12 重映射 */
#define AFIO_MAPR2_MISC_REMAP                ((uint32_t)0x00002000)        /*!< 其他重映射 */
#endif

#ifdef STM32F10X_XL 
/****************** AFIO_MAPR2 寄存器的位定义 ****************/
#define AFIO_MAPR2_TIM9_REMAP                ((uint32_t)0x00000020)        /*!< TIM9 重映射 */
#define AFIO_MAPR2_TIM10_REMAP               ((uint32_t)0x00000040)        /*!< TIM10 重映射 */
#define AFIO_MAPR2_TIM11_REMAP               ((uint32_t)0x00000080)        /*!< TIM11 重映射 */
#define AFIO_MAPR2_TIM13_REMAP               ((uint32_t)0x00000100)        /*!< TIM13 重映射 */
#define AFIO_MAPR2_TIM14_REMAP               ((uint32_t)0x00000200)        /*!< TIM14 重映射 */
#define AFIO_MAPR2_FSMC_NADV_REMAP           ((uint32_t)0x00000400)        /*!< FSMC NADV 重映射 */
#endif

/******************************************************************************/
/*                                                                            */
/*                               系统节拍定时器                                   */
/*                                                                            */
/******************************************************************************/

/***************** SysTick_CTRL 寄存器的位定义 ***************/
#define  SysTick_CTRL_ENABLE                 ((uint32_t)0x00000001)        /*!< 计数器使能 */
#define  SysTick_CTRL_TICKINT                ((uint32_t)0x00000002)        /*!< 倒计数到 0 时挂起 SysTick 异常处理 */
#define  SysTick_CTRL_CLKSOURCE              ((uint32_t)0x00000004)        /*!< 时钟源 */
#define  SysTick_CTRL_COUNTFLAG              ((uint32_t)0x00010000)        /*!< 计数标志位 */

/***************** SysTick_LOAD 寄存器的位定义 ***************/
#define  SysTick_LOAD_RELOAD                 ((uint32_t)0x00FFFFFF)        /*!< 计数器减到 0 时装载到 SysTick 当前值寄存器的值 */

/***************** SysTick_VAL 寄存器的位定义 ***************/
#define  SysTick_VAL_CURRENT                 ((uint32_t)0x00FFFFFF)        /*!< 访问该寄存器时的当前值 */

/***************** SysTick_CALIB 寄存器的位定义 ***************/
#define  SysTick_CALIB_TENMS                 ((uint32_t)0x00FFFFFF)        /*!< 用于 10ms 定时的重装载值 */
#define  SysTick_CALIB_SKEW                  ((uint32_t)0x40000000)        /*!< 校准值并非恰好 10 ms */
#define  SysTick_CALIB_NOREF                 ((uint32_t)0x80000000)        /*!< 未提供参考时钟 */

/******************************************************************************/
/*                                                                            */
/*                  嵌套向量中断控制器                      */
/*                                                                            */
/******************************************************************************/

/****************** NVIC_ISER 寄存器的位定义 ****************/
#define  NVIC_ISER_SETENA                    ((uint32_t)0xFFFFFFFF)        /*!< 中断置能位 */
#define  NVIC_ISER_SETENA_0                  ((uint32_t)0x00000001)        /*!< 位 0 */
#define  NVIC_ISER_SETENA_1                  ((uint32_t)0x00000002)        /*!< 位 1 */
#define  NVIC_ISER_SETENA_2                  ((uint32_t)0x00000004)        /*!< 位 2 */
#define  NVIC_ISER_SETENA_3                  ((uint32_t)0x00000008)        /*!< 位 3 */
#define  NVIC_ISER_SETENA_4                  ((uint32_t)0x00000010)        /*!< 位 4 */
#define  NVIC_ISER_SETENA_5                  ((uint32_t)0x00000020)        /*!< 位 5 */
#define  NVIC_ISER_SETENA_6                  ((uint32_t)0x00000040)        /*!< 位 6 */
#define  NVIC_ISER_SETENA_7                  ((uint32_t)0x00000080)        /*!< 位 7 */
#define  NVIC_ISER_SETENA_8                  ((uint32_t)0x00000100)        /*!< 位 8 */
#define  NVIC_ISER_SETENA_9                  ((uint32_t)0x00000200)        /*!< 位 9 */
#define  NVIC_ISER_SETENA_10                 ((uint32_t)0x00000400)        /*!< 位 10 */
#define  NVIC_ISER_SETENA_11                 ((uint32_t)0x00000800)        /*!< 位 11 */
#define  NVIC_ISER_SETENA_12                 ((uint32_t)0x00001000)        /*!< 位 12 */
#define  NVIC_ISER_SETENA_13                 ((uint32_t)0x00002000)        /*!< 位 13 */
#define  NVIC_ISER_SETENA_14                 ((uint32_t)0x00004000)        /*!< 位 14 */
#define  NVIC_ISER_SETENA_15                 ((uint32_t)0x00008000)        /*!< 位 15 */
#define  NVIC_ISER_SETENA_16                 ((uint32_t)0x00010000)        /*!< 位 16 */
#define  NVIC_ISER_SETENA_17                 ((uint32_t)0x00020000)        /*!< 位 17 */
#define  NVIC_ISER_SETENA_18                 ((uint32_t)0x00040000)        /*!< 位 18 */
#define  NVIC_ISER_SETENA_19                 ((uint32_t)0x00080000)        /*!< 位 19 */
#define  NVIC_ISER_SETENA_20                 ((uint32_t)0x00100000)        /*!< 位 20 */
#define  NVIC_ISER_SETENA_21                 ((uint32_t)0x00200000)        /*!< 位 21 */
#define  NVIC_ISER_SETENA_22                 ((uint32_t)0x00400000)        /*!< 位 22 */
#define  NVIC_ISER_SETENA_23                 ((uint32_t)0x00800000)        /*!< 位 23 */
#define  NVIC_ISER_SETENA_24                 ((uint32_t)0x01000000)        /*!< 位 24 */
#define  NVIC_ISER_SETENA_25                 ((uint32_t)0x02000000)        /*!< 位 25 */
#define  NVIC_ISER_SETENA_26                 ((uint32_t)0x04000000)        /*!< 位 26 */
#define  NVIC_ISER_SETENA_27                 ((uint32_t)0x08000000)        /*!< 位 27 */
#define  NVIC_ISER_SETENA_28                 ((uint32_t)0x10000000)        /*!< 位 28 */
#define  NVIC_ISER_SETENA_29                 ((uint32_t)0x20000000)        /*!< 位 29 */
#define  NVIC_ISER_SETENA_30                 ((uint32_t)0x40000000)        /*!< 位 30 */
#define  NVIC_ISER_SETENA_31                 ((uint32_t)0x80000000)        /*!< 位 31 */

/****************** NVIC_ICER 寄存器的位定义 ****************/
#define  NVIC_ICER_CLRENA                   ((uint32_t)0xFFFFFFFF)        /*!< 中断清能位 */
#define  NVIC_ICER_CLRENA_0                  ((uint32_t)0x00000001)        /*!< 位 0 */
#define  NVIC_ICER_CLRENA_1                  ((uint32_t)0x00000002)        /*!< 位 1 */
#define  NVIC_ICER_CLRENA_2                  ((uint32_t)0x00000004)        /*!< 位 2 */
#define  NVIC_ICER_CLRENA_3                  ((uint32_t)0x00000008)        /*!< 位 3 */
#define  NVIC_ICER_CLRENA_4                  ((uint32_t)0x00000010)        /*!< 位 4 */
#define  NVIC_ICER_CLRENA_5                  ((uint32_t)0x00000020)        /*!< 位 5 */
#define  NVIC_ICER_CLRENA_6                  ((uint32_t)0x00000040)        /*!< 位 6 */
#define  NVIC_ICER_CLRENA_7                  ((uint32_t)0x00000080)        /*!< 位 7 */
#define  NVIC_ICER_CLRENA_8                  ((uint32_t)0x00000100)        /*!< 位 8 */
#define  NVIC_ICER_CLRENA_9                  ((uint32_t)0x00000200)        /*!< 位 9 */
#define  NVIC_ICER_CLRENA_10                 ((uint32_t)0x00000400)        /*!< 位 10 */
#define  NVIC_ICER_CLRENA_11                 ((uint32_t)0x00000800)        /*!< 位 11 */
#define  NVIC_ICER_CLRENA_12                 ((uint32_t)0x00001000)        /*!< 位 12 */
#define  NVIC_ICER_CLRENA_13                 ((uint32_t)0x00002000)        /*!< 位 13 */
#define  NVIC_ICER_CLRENA_14                 ((uint32_t)0x00004000)        /*!< 位 14 */
#define  NVIC_ICER_CLRENA_15                 ((uint32_t)0x00008000)        /*!< 位 15 */
#define  NVIC_ICER_CLRENA_16                 ((uint32_t)0x00010000)        /*!< 位 16 */
#define  NVIC_ICER_CLRENA_17                 ((uint32_t)0x00020000)        /*!< 位 17 */
#define  NVIC_ICER_CLRENA_18                 ((uint32_t)0x00040000)        /*!< 位 18 */
#define  NVIC_ICER_CLRENA_19                 ((uint32_t)0x00080000)        /*!< 位 19 */
#define  NVIC_ICER_CLRENA_20                 ((uint32_t)0x00100000)        /*!< 位 20 */
#define  NVIC_ICER_CLRENA_21                 ((uint32_t)0x00200000)        /*!< 位 21 */
#define  NVIC_ICER_CLRENA_22                 ((uint32_t)0x00400000)        /*!< 位 22 */
#define  NVIC_ICER_CLRENA_23                 ((uint32_t)0x00800000)        /*!< 位 23 */
#define  NVIC_ICER_CLRENA_24                 ((uint32_t)0x01000000)        /*!< 位 24 */
#define  NVIC_ICER_CLRENA_25                 ((uint32_t)0x02000000)        /*!< 位 25 */
#define  NVIC_ICER_CLRENA_26                 ((uint32_t)0x04000000)        /*!< 位 26 */
#define  NVIC_ICER_CLRENA_27                 ((uint32_t)0x08000000)        /*!< 位 27 */
#define  NVIC_ICER_CLRENA_28                 ((uint32_t)0x10000000)        /*!< 位 28 */
#define  NVIC_ICER_CLRENA_29                 ((uint32_t)0x20000000)        /*!< 位 29 */
#define  NVIC_ICER_CLRENA_30                 ((uint32_t)0x40000000)        /*!< 位 30 */
#define  NVIC_ICER_CLRENA_31                 ((uint32_t)0x80000000)        /*!< 位 31 */

/****************** NVIC_ISPR 寄存器的位定义 ****************/
#define  NVIC_ISPR_SETPEND                   ((uint32_t)0xFFFFFFFF)        /*!< 中断置挂起位 */
#define  NVIC_ISPR_SETPEND_0                 ((uint32_t)0x00000001)        /*!< 位 0 */
#define  NVIC_ISPR_SETPEND_1                 ((uint32_t)0x00000002)        /*!< 位 1 */
#define  NVIC_ISPR_SETPEND_2                 ((uint32_t)0x00000004)        /*!< 位 2 */
#define  NVIC_ISPR_SETPEND_3                 ((uint32_t)0x00000008)        /*!< 位 3 */
#define  NVIC_ISPR_SETPEND_4                 ((uint32_t)0x00000010)        /*!< 位 4 */
#define  NVIC_ISPR_SETPEND_5                 ((uint32_t)0x00000020)        /*!< 位 5 */
#define  NVIC_ISPR_SETPEND_6                 ((uint32_t)0x00000040)        /*!< 位 6 */
#define  NVIC_ISPR_SETPEND_7                 ((uint32_t)0x00000080)        /*!< 位 7 */
#define  NVIC_ISPR_SETPEND_8                 ((uint32_t)0x00000100)        /*!< 位 8 */
#define  NVIC_ISPR_SETPEND_9                 ((uint32_t)0x00000200)        /*!< 位 9 */
#define  NVIC_ISPR_SETPEND_10                ((uint32_t)0x00000400)        /*!< 位 10 */
#define  NVIC_ISPR_SETPEND_11                ((uint32_t)0x00000800)        /*!< 位 11 */
#define  NVIC_ISPR_SETPEND_12                ((uint32_t)0x00001000)        /*!< 位 12 */
#define  NVIC_ISPR_SETPEND_13                ((uint32_t)0x00002000)        /*!< 位 13 */
#define  NVIC_ISPR_SETPEND_14                ((uint32_t)0x00004000)        /*!< 位 14 */
#define  NVIC_ISPR_SETPEND_15                ((uint32_t)0x00008000)        /*!< 位 15 */
#define  NVIC_ISPR_SETPEND_16                ((uint32_t)0x00010000)        /*!< 位 16 */
#define  NVIC_ISPR_SETPEND_17                ((uint32_t)0x00020000)        /*!< 位 17 */
#define  NVIC_ISPR_SETPEND_18                ((uint32_t)0x00040000)        /*!< 位 18 */
#define  NVIC_ISPR_SETPEND_19                ((uint32_t)0x00080000)        /*!< 位 19 */
#define  NVIC_ISPR_SETPEND_20                ((uint32_t)0x00100000)        /*!< 位 20 */
#define  NVIC_ISPR_SETPEND_21                ((uint32_t)0x00200000)        /*!< 位 21 */
#define  NVIC_ISPR_SETPEND_22                ((uint32_t)0x00400000)        /*!< 位 22 */
#define  NVIC_ISPR_SETPEND_23                ((uint32_t)0x00800000)        /*!< 位 23 */
#define  NVIC_ISPR_SETPEND_24                ((uint32_t)0x01000000)        /*!< 位 24 */
#define  NVIC_ISPR_SETPEND_25                ((uint32_t)0x02000000)        /*!< 位 25 */
#define  NVIC_ISPR_SETPEND_26                ((uint32_t)0x04000000)        /*!< 位 26 */
#define  NVIC_ISPR_SETPEND_27                ((uint32_t)0x08000000)        /*!< 位 27 */
#define  NVIC_ISPR_SETPEND_28                ((uint32_t)0x10000000)        /*!< 位 28 */
#define  NVIC_ISPR_SETPEND_29                ((uint32_t)0x20000000)        /*!< 位 29 */
#define  NVIC_ISPR_SETPEND_30                ((uint32_t)0x40000000)        /*!< 位 30 */
#define  NVIC_ISPR_SETPEND_31                ((uint32_t)0x80000000)        /*!< 位 31 */

/****************** NVIC_ICPR 寄存器的位定义 ****************/
#define  NVIC_ICPR_CLRPEND                   ((uint32_t)0xFFFFFFFF)        /*!< 中断清挂起位 */
#define  NVIC_ICPR_CLRPEND_0                 ((uint32_t)0x00000001)        /*!< 位 0 */
#define  NVIC_ICPR_CLRPEND_1                 ((uint32_t)0x00000002)        /*!< 位 1 */
#define  NVIC_ICPR_CLRPEND_2                 ((uint32_t)0x00000004)        /*!< 位 2 */
#define  NVIC_ICPR_CLRPEND_3                 ((uint32_t)0x00000008)        /*!< 位 3 */
#define  NVIC_ICPR_CLRPEND_4                 ((uint32_t)0x00000010)        /*!< 位 4 */
#define  NVIC_ICPR_CLRPEND_5                 ((uint32_t)0x00000020)        /*!< 位 5 */
#define  NVIC_ICPR_CLRPEND_6                 ((uint32_t)0x00000040)        /*!< 位 6 */
#define  NVIC_ICPR_CLRPEND_7                 ((uint32_t)0x00000080)        /*!< 位 7 */
#define  NVIC_ICPR_CLRPEND_8                 ((uint32_t)0x00000100)        /*!< 位 8 */
#define  NVIC_ICPR_CLRPEND_9                 ((uint32_t)0x00000200)        /*!< 位 9 */
#define  NVIC_ICPR_CLRPEND_10                ((uint32_t)0x00000400)        /*!< 位 10 */
#define  NVIC_ICPR_CLRPEND_11                ((uint32_t)0x00000800)        /*!< 位 11 */
#define  NVIC_ICPR_CLRPEND_12                ((uint32_t)0x00001000)        /*!< 位 12 */
#define  NVIC_ICPR_CLRPEND_13                ((uint32_t)0x00002000)        /*!< 位 13 */
#define  NVIC_ICPR_CLRPEND_14                ((uint32_t)0x00004000)        /*!< 位 14 */
#define  NVIC_ICPR_CLRPEND_15                ((uint32_t)0x00008000)        /*!< 位 15 */
#define  NVIC_ICPR_CLRPEND_16                ((uint32_t)0x00010000)        /*!< 位 16 */
#define  NVIC_ICPR_CLRPEND_17                ((uint32_t)0x00020000)        /*!< 位 17 */
#define  NVIC_ICPR_CLRPEND_18                ((uint32_t)0x00040000)        /*!< 位 18 */
#define  NVIC_ICPR_CLRPEND_19                ((uint32_t)0x00080000)        /*!< 位 19 */
#define  NVIC_ICPR_CLRPEND_20                ((uint32_t)0x00100000)        /*!< 位 20 */
#define  NVIC_ICPR_CLRPEND_21                ((uint32_t)0x00200000)        /*!< 位 21 */
#define  NVIC_ICPR_CLRPEND_22                ((uint32_t)0x00400000)        /*!< 位 22 */
#define  NVIC_ICPR_CLRPEND_23                ((uint32_t)0x00800000)        /*!< 位 23 */
#define  NVIC_ICPR_CLRPEND_24                ((uint32_t)0x01000000)        /*!< 位 24 */
#define  NVIC_ICPR_CLRPEND_25                ((uint32_t)0x02000000)        /*!< 位 25 */
#define  NVIC_ICPR_CLRPEND_26                ((uint32_t)0x04000000)        /*!< 位 26 */
#define  NVIC_ICPR_CLRPEND_27                ((uint32_t)0x08000000)        /*!< 位 27 */
#define  NVIC_ICPR_CLRPEND_28                ((uint32_t)0x10000000)        /*!< 位 28 */
#define  NVIC_ICPR_CLRPEND_29                ((uint32_t)0x20000000)        /*!< 位 29 */
#define  NVIC_ICPR_CLRPEND_30                ((uint32_t)0x40000000)        /*!< 位 30 */
#define  NVIC_ICPR_CLRPEND_31                ((uint32_t)0x80000000)        /*!< 位 31 */

/****************** NVIC_IABR 寄存器的位定义 ****************/
#define  NVIC_IABR_ACTIVE                    ((uint32_t)0xFFFFFFFF)        /*!< 中断激活标志位 */
#define  NVIC_IABR_ACTIVE_0                  ((uint32_t)0x00000001)        /*!< 位 0 */
#define  NVIC_IABR_ACTIVE_1                  ((uint32_t)0x00000002)        /*!< 位 1 */
#define  NVIC_IABR_ACTIVE_2                  ((uint32_t)0x00000004)        /*!< 位 2 */
#define  NVIC_IABR_ACTIVE_3                  ((uint32_t)0x00000008)        /*!< 位 3 */
#define  NVIC_IABR_ACTIVE_4                  ((uint32_t)0x00000010)        /*!< 位 4 */
#define  NVIC_IABR_ACTIVE_5                  ((uint32_t)0x00000020)        /*!< 位 5 */
#define  NVIC_IABR_ACTIVE_6                  ((uint32_t)0x00000040)        /*!< 位 6 */
#define  NVIC_IABR_ACTIVE_7                  ((uint32_t)0x00000080)        /*!< 位 7 */
#define  NVIC_IABR_ACTIVE_8                  ((uint32_t)0x00000100)        /*!< 位 8 */
#define  NVIC_IABR_ACTIVE_9                  ((uint32_t)0x00000200)        /*!< 位 9 */
#define  NVIC_IABR_ACTIVE_10                 ((uint32_t)0x00000400)        /*!< 位 10 */
#define  NVIC_IABR_ACTIVE_11                 ((uint32_t)0x00000800)        /*!< 位 11 */
#define  NVIC_IABR_ACTIVE_12                 ((uint32_t)0x00001000)        /*!< 位 12 */
#define  NVIC_IABR_ACTIVE_13                 ((uint32_t)0x00002000)        /*!< 位 13 */
#define  NVIC_IABR_ACTIVE_14                 ((uint32_t)0x00004000)        /*!< 位 14 */
#define  NVIC_IABR_ACTIVE_15                 ((uint32_t)0x00008000)        /*!< 位 15 */
#define  NVIC_IABR_ACTIVE_16                 ((uint32_t)0x00010000)        /*!< 位 16 */
#define  NVIC_IABR_ACTIVE_17                 ((uint32_t)0x00020000)        /*!< 位 17 */
#define  NVIC_IABR_ACTIVE_18                 ((uint32_t)0x00040000)        /*!< 位 18 */
#define  NVIC_IABR_ACTIVE_19                 ((uint32_t)0x00080000)        /*!< 位 19 */
#define  NVIC_IABR_ACTIVE_20                 ((uint32_t)0x00100000)        /*!< 位 20 */
#define  NVIC_IABR_ACTIVE_21                 ((uint32_t)0x00200000)        /*!< 位 21 */
#define  NVIC_IABR_ACTIVE_22                 ((uint32_t)0x00400000)        /*!< 位 22 */
#define  NVIC_IABR_ACTIVE_23                 ((uint32_t)0x00800000)        /*!< 位 23 */
#define  NVIC_IABR_ACTIVE_24                 ((uint32_t)0x01000000)        /*!< 位 24 */
#define  NVIC_IABR_ACTIVE_25                 ((uint32_t)0x02000000)        /*!< 位 25 */
#define  NVIC_IABR_ACTIVE_26                 ((uint32_t)0x04000000)        /*!< 位 26 */
#define  NVIC_IABR_ACTIVE_27                 ((uint32_t)0x08000000)        /*!< 位 27 */
#define  NVIC_IABR_ACTIVE_28                 ((uint32_t)0x10000000)        /*!< 位 28 */
#define  NVIC_IABR_ACTIVE_29                 ((uint32_t)0x20000000)        /*!< 位 29 */
#define  NVIC_IABR_ACTIVE_30                 ((uint32_t)0x40000000)        /*!< 位 30 */
#define  NVIC_IABR_ACTIVE_31                 ((uint32_t)0x80000000)        /*!< 位 31 */

/****************** NVIC_PRI0 寄存器的位定义 ****************/
#define  NVIC_IPR0_PRI_0                     ((uint32_t)0x000000FF)        /*!< 中断 0 的优先级 */
#define  NVIC_IPR0_PRI_1                     ((uint32_t)0x0000FF00)        /*!< 中断 1 的优先级 */
#define  NVIC_IPR0_PRI_2                     ((uint32_t)0x00FF0000)        /*!< 中断 2 的优先级 */
#define  NVIC_IPR0_PRI_3                     ((uint32_t)0xFF000000)        /*!< 中断 3 的优先级 */

/****************** NVIC_PRI1 寄存器的位定义 ****************/
#define  NVIC_IPR1_PRI_4                     ((uint32_t)0x000000FF)        /*!< 中断 4 的优先级 */
#define  NVIC_IPR1_PRI_5                     ((uint32_t)0x0000FF00)        /*!< 中断 5 的优先级 */
#define  NVIC_IPR1_PRI_6                     ((uint32_t)0x00FF0000)        /*!< 中断 6 的优先级 */
#define  NVIC_IPR1_PRI_7                     ((uint32_t)0xFF000000)        /*!< 中断 7 的优先级 */

/****************** NVIC_PRI2 寄存器的位定义 ****************/
#define  NVIC_IPR2_PRI_8                     ((uint32_t)0x000000FF)        /*!< 中断 8 的优先级 */
#define  NVIC_IPR2_PRI_9                     ((uint32_t)0x0000FF00)        /*!< 中断 9 的优先级 */
#define  NVIC_IPR2_PRI_10                    ((uint32_t)0x00FF0000)        /*!< 中断 10 的优先级 */
#define  NVIC_IPR2_PRI_11                    ((uint32_t)0xFF000000)        /*!< 中断 11 的优先级 */

/****************** NVIC_PRI3 寄存器的位定义 ****************/
#define  NVIC_IPR3_PRI_12                    ((uint32_t)0x000000FF)        /*!< 中断 12 的优先级 */
#define  NVIC_IPR3_PRI_13                    ((uint32_t)0x0000FF00)        /*!< 中断 13 的优先级 */
#define  NVIC_IPR3_PRI_14                    ((uint32_t)0x00FF0000)        /*!< 中断 14 的优先级 */
#define  NVIC_IPR3_PRI_15                    ((uint32_t)0xFF000000)        /*!< 中断 15 的优先级 */

/****************** NVIC_PRI4 寄存器的位定义 ****************/
#define  NVIC_IPR4_PRI_16                    ((uint32_t)0x000000FF)        /*!< 中断 16 的优先级 */
#define  NVIC_IPR4_PRI_17                    ((uint32_t)0x0000FF00)        /*!< 中断 17 的优先级 */
#define  NVIC_IPR4_PRI_18                    ((uint32_t)0x00FF0000)        /*!< 中断 18 的优先级 */
#define  NVIC_IPR4_PRI_19                    ((uint32_t)0xFF000000)        /*!< 中断 19 的优先级 */

/****************** NVIC_PRI5 寄存器的位定义 ****************/
#define  NVIC_IPR5_PRI_20                    ((uint32_t)0x000000FF)        /*!< 中断 20 的优先级 */
#define  NVIC_IPR5_PRI_21                    ((uint32_t)0x0000FF00)        /*!< 中断 21 的优先级 */
#define  NVIC_IPR5_PRI_22                    ((uint32_t)0x00FF0000)        /*!< 中断 22 的优先级 */
#define  NVIC_IPR5_PRI_23                    ((uint32_t)0xFF000000)        /*!< 中断 23 的优先级 */

/****************** NVIC_PRI6 寄存器的位定义 ****************/
#define  NVIC_IPR6_PRI_24                    ((uint32_t)0x000000FF)        /*!< 中断 24 的优先级 */
#define  NVIC_IPR6_PRI_25                    ((uint32_t)0x0000FF00)        /*!< 中断 25 的优先级 */
#define  NVIC_IPR6_PRI_26                    ((uint32_t)0x00FF0000)        /*!< 中断 26 的优先级 */
#define  NVIC_IPR6_PRI_27                    ((uint32_t)0xFF000000)        /*!< 中断 27 的优先级 */

/****************** NVIC_PRI7 寄存器的位定义 ****************/
#define  NVIC_IPR7_PRI_28                    ((uint32_t)0x000000FF)        /*!< 中断 28 的优先级 */
#define  NVIC_IPR7_PRI_29                    ((uint32_t)0x0000FF00)        /*!< 中断 29 的优先级 */
#define  NVIC_IPR7_PRI_30                    ((uint32_t)0x00FF0000)        /*!< 中断 30 的优先级 */
#define  NVIC_IPR7_PRI_31                    ((uint32_t)0xFF000000)        /*!< 中断 31 的优先级 */

/****************** SCB_CPUID 寄存器的位定义 ****************/
#define  SCB_CPUID_REVISION                  ((uint32_t)0x0000000F)        /*!< 由实现定义的修订号 */
#define  SCB_CPUID_PARTNO                    ((uint32_t)0x0000FFF0)        /*!< 系列内处理器编号 */
#define  SCB_CPUID_Constant                  ((uint32_t)0x000F0000)        /*!< 读回值为 0x0F */
#define  SCB_CPUID_VARIANT                   ((uint32_t)0x00F00000)        /*!< 由实现定义的变型号 */
#define  SCB_CPUID_IMPLEMENTER               ((uint32_t)0xFF000000)        /*!< 实现者代码。ARM 为 0x41 */

/******************* SCB_ICSR 寄存器的位定义 *****************/
#define  SCB_ICSR_VECTACTIVE                 ((uint32_t)0x000001FF)        /*!< 活动 ISR 编号域 */
#define  SCB_ICSR_RETTOBASE                  ((uint32_t)0x00000800)        /*!< 所有活动异常减去 IPSR_current_exception 后为空集 */
#define  SCB_ICSR_VECTPENDING                ((uint32_t)0x003FF000)        /*!< 挂起 ISR 编号域 */
#define  SCB_ICSR_ISRPENDING                 ((uint32_t)0x00400000)        /*!< 中断挂起标志位 */
#define  SCB_ICSR_ISRPREEMPT                 ((uint32_t)0x00800000)        /*!< 它表示挂起的中断将在下一个运行周期变为活动状态 */
#define  SCB_ICSR_PENDSTCLR                  ((uint32_t)0x02000000)        /*!< 清除 SysTick 挂起位 */
#define  SCB_ICSR_PENDSTSET                  ((uint32_t)0x04000000)        /*!< 置位 SysTick 挂起位 */
#define  SCB_ICSR_PENDSVCLR                  ((uint32_t)0x08000000)        /*!< 清除 PendSV 挂起位 */
#define  SCB_ICSR_PENDSVSET                  ((uint32_t)0x10000000)        /*!< 置位 PendSV 挂起位 */
#define  SCB_ICSR_NMIPENDSET                 ((uint32_t)0x80000000)        /*!< 置位 NMI 挂起位 */

/******************* SCB_VTOR 寄存器的位定义 *****************/
#define  SCB_VTOR_TBLOFF                     ((uint32_t)0x1FFFFF80)        /*!< 向量表基地址偏移域 */
#define  SCB_VTOR_TBLBASE                    ((uint32_t)0x20000000)        /*!< 表基地址位于代码区（0）或 RAM（1） */

/*!<***************** SCB_AIRCR 寄存器的位定义 *****************/
#define  SCB_AIRCR_VECTRESET                 ((uint32_t)0x00000001)        /*!< 系统复位位 */
#define  SCB_AIRCR_VECTCLRACTIVE             ((uint32_t)0x00000002)        /*!< 清除活动向量位 */
#define  SCB_AIRCR_SYSRESETREQ               ((uint32_t)0x00000004)        /*!< 请求芯片控制逻辑产生复位 */

#define  SCB_AIRCR_PRIGROUP                  ((uint32_t)0x00000700)        /*!< PRIGROUP[2:0] 位（优先级分组） */
#define  SCB_AIRCR_PRIGROUP_0                ((uint32_t)0x00000100)        /*!< 位 0 */
#define  SCB_AIRCR_PRIGROUP_1                ((uint32_t)0x00000200)        /*!< 位 1 */
#define  SCB_AIRCR_PRIGROUP_2                ((uint32_t)0x00000400)        /*!< 位 2  */

/* 优先级分组配置 */
#define  SCB_AIRCR_PRIGROUP0                 ((uint32_t)0x00000000)        /*!< 优先级组=0（7 位抢占优先级，1 位子优先级） */
#define  SCB_AIRCR_PRIGROUP1                 ((uint32_t)0x00000100)        /*!< 优先级组=1（6 位抢占优先级，2 位子优先级） */
#define  SCB_AIRCR_PRIGROUP2                 ((uint32_t)0x00000200)        /*!< 优先级组=2（5 位抢占优先级，3 位子优先级） */
#define  SCB_AIRCR_PRIGROUP3                 ((uint32_t)0x00000300)        /*!< 优先级组=3（4 位抢占优先级，4 位子优先级） */
#define  SCB_AIRCR_PRIGROUP4                 ((uint32_t)0x00000400)        /*!< 优先级组=4（3 位抢占优先级，5 位子优先级） */
#define  SCB_AIRCR_PRIGROUP5                 ((uint32_t)0x00000500)        /*!< 优先级组=5（2 位抢占优先级，6 位子优先级） */
#define  SCB_AIRCR_PRIGROUP6                 ((uint32_t)0x00000600)        /*!< 优先级组=6（1 位抢占优先级，7 位子优先级） */
#define  SCB_AIRCR_PRIGROUP7                 ((uint32_t)0x00000700)        /*!< 优先级组=7（无抢占优先级，8 位子优先级） */

#define  SCB_AIRCR_ENDIANESS                 ((uint32_t)0x00008000)        /*!< 数据字节序位 */
#define  SCB_AIRCR_VECTKEY                   ((uint32_t)0xFFFF0000)        /*!< 寄存器关键字（VECTKEY）- 读回值为 0xFA05（VECTKEYSTAT） */

/******************* SCB_SCR 寄存器的位定义 *****************/
#define  SCB_SCR_SLEEPONEXIT                 ((uint8_t)0x02)               /*!< 退出时睡眠位 */
#define  SCB_SCR_SLEEPDEEP                   ((uint8_t)0x04)               /*!< 深度睡眠位 */
#define  SCB_SCR_SEVONPEND                   ((uint8_t)0x10)               /*!< 从 WFE 唤醒 */

/******************** SCB_CCR 寄存器的位定义 ******************/
#define  SCB_CCR_NONBASETHRDENA              ((uint16_t)0x0001)            /*!< 通过受控的返回值，可以从处理模式的任何级别进入线程模式 */
#define  SCB_CCR_USERSETMPEND                ((uint16_t)0x0002)            /*!< 允许用户代码写软件触发中断寄存器来触发（挂起）一个主异常 */
#define  SCB_CCR_UNALIGN_TRP                 ((uint16_t)0x0008)            /*!< 非对齐访问陷阱 */
#define  SCB_CCR_DIV_0_TRP                   ((uint16_t)0x0010)            /*!< 除以 0 陷阱 */
#define  SCB_CCR_BFHFNMIGN                   ((uint16_t)0x0100)            /*!< 在优先级 -1 和 -2 下运行的异常处理 */
#define  SCB_CCR_STKALIGN                    ((uint16_t)0x0200)            /*!< 异常进入时，异常前使用的 SP 被调整为 8 字节对齐 */

/******************* SCB_SHPR 寄存器的位定义 *****************/
#define  SCB_SHPR_PRI_N                      ((uint32_t)0x000000FF)        /*!< 系统异常 4、8 和 12 的优先级。存储器管理、保留和调试监控 */
#define  SCB_SHPR_PRI_N1                     ((uint32_t)0x0000FF00)        /*!< 系统异常 5、9 和 13 的优先级。总线故障、保留和保留 */
#define  SCB_SHPR_PRI_N2                     ((uint32_t)0x00FF0000)        /*!< 系统异常 6、10 和 14 的优先级。用法故障、保留和 PendSV */
#define  SCB_SHPR_PRI_N3                     ((uint32_t)0xFF000000)        /*!< 系统异常 7、11 和 15 的优先级。保留、SVCall 和 SysTick */

/****************** SCB_SHCSR 寄存器的位定义 ****************/
#define  SCB_SHCSR_MEMFAULTACT               ((uint32_t)0x00000001)        /*!< MemManage 处于活动状态 */
#define  SCB_SHCSR_BUSFAULTACT               ((uint32_t)0x00000002)        /*!< BusFault 处于活动状态 */
#define  SCB_SHCSR_USGFAULTACT               ((uint32_t)0x00000008)        /*!< UsageFault 处于活动状态 */
#define  SCB_SHCSR_SVCALLACT                 ((uint32_t)0x00000080)        /*!< SVCall 处于活动状态 */
#define  SCB_SHCSR_MONITORACT                ((uint32_t)0x00000100)        /*!< Monitor 处于活动状态 */
#define  SCB_SHCSR_PENDSVACT                 ((uint32_t)0x00000400)        /*!< PendSV 处于活动状态 */
#define  SCB_SHCSR_SYSTICKACT                ((uint32_t)0x00000800)        /*!< SysTick 处于活动状态 */
#define  SCB_SHCSR_USGFAULTPENDED            ((uint32_t)0x00001000)        /*!< 用法故障处于挂起状态 */
#define  SCB_SHCSR_MEMFAULTPENDED            ((uint32_t)0x00002000)        /*!< MemManage 处于挂起状态 */
#define  SCB_SHCSR_BUSFAULTPENDED            ((uint32_t)0x00004000)        /*!< 总线故障处于挂起状态 */
#define  SCB_SHCSR_SVCALLPENDED              ((uint32_t)0x00008000)        /*!< SVCall 处于挂起状态 */
#define  SCB_SHCSR_MEMFAULTENA               ((uint32_t)0x00010000)        /*!< MemManage 使能 */
#define  SCB_SHCSR_BUSFAULTENA               ((uint32_t)0x00020000)        /*!< 总线故障使能 */
#define  SCB_SHCSR_USGFAULTENA               ((uint32_t)0x00040000)        /*!< UsageFault 使能 */

/******************* SCB_CFSR 寄存器的位定义 *****************/
/*!< MFSR */
#define  SCB_CFSR_IACCVIOL                   ((uint32_t)0x00000001)        /*!< 取指访问违例 */
#define  SCB_CFSR_DACCVIOL                   ((uint32_t)0x00000002)        /*!< 数据访问违例 */
#define  SCB_CFSR_MUNSTKERR                  ((uint32_t)0x00000008)        /*!< 出栈错误 */
#define  SCB_CFSR_MSTKERR                    ((uint32_t)0x00000010)        /*!< 入栈错误 */
#define  SCB_CFSR_MMARVALID                  ((uint32_t)0x00000080)        /*!< 存储器管理地址寄存器地址有效标志位 */
/*!< BFSR */
#define  SCB_CFSR_IBUSERR                    ((uint32_t)0x00000100)        /*!< 取指总线错误标志位 */
#define  SCB_CFSR_PRECISERR                  ((uint32_t)0x00000200)        /*!< 精确数据总线错误 */
#define  SCB_CFSR_IMPRECISERR                ((uint32_t)0x00000400)        /*!< 不精确数据总线错误 */
#define  SCB_CFSR_UNSTKERR                   ((uint32_t)0x00000800)        /*!< 出栈错误 */
#define  SCB_CFSR_STKERR                     ((uint32_t)0x00001000)        /*!< 入栈错误 */
#define  SCB_CFSR_BFARVALID                  ((uint32_t)0x00008000)        /*!< 总线故障地址寄存器地址有效标志位 */
/*!< UFSR */
#define  SCB_CFSR_UNDEFINSTR                 ((uint32_t)0x00010000)        /*!< 处理器试图执行未定义的指令 */
#define  SCB_CFSR_INVSTATE                   ((uint32_t)0x00020000)        /*!< EPSR 与指令的无效组合 */
#define  SCB_CFSR_INVPC                      ((uint32_t)0x00040000)        /*!< 试图非法将 EXC_RETURN 装载到 pc */
#define  SCB_CFSR_NOCP                       ((uint32_t)0x00080000)        /*!< 试图使用协处理器指令 */
#define  SCB_CFSR_UNALIGNED                  ((uint32_t)0x01000000)        /*!< 试图进行非对齐存储器访问时产生故障 */
#define  SCB_CFSR_DIVBYZERO                  ((uint32_t)0x02000000)        /*!< 使用 SDIV 或 DIV 指令且除数为 0 时产生故障 */

/******************* SCB_HFSR 寄存器的位定义 *****************/
#define  SCB_HFSR_VECTTBL                    ((uint32_t)0x00000002)        /*!< 异常处理时读取向量表导致故障 */
#define  SCB_HFSR_FORCED                     ((uint32_t)0x40000000)        /*!< 收到可配置故障但无法激活时，硬故障被激活 */
#define  SCB_HFSR_DEBUGEVT                   ((uint32_t)0x80000000)        /*!< 与调试相关的故障 */

/******************* SCB_DFSR 寄存器的位定义 *****************/
#define  SCB_DFSR_HALTED                     ((uint8_t)0x01)               /*!< 停机请求标志位 */
#define  SCB_DFSR_BKPT                       ((uint8_t)0x02)               /*!< BKPT 标志位 */
#define  SCB_DFSR_DWTTRAP                    ((uint8_t)0x04)               /*!< 数据观察点与跟踪（DWT）标志位 */
#define  SCB_DFSR_VCATCH                     ((uint8_t)0x08)               /*!< 向量捕获标志位 */
#define  SCB_DFSR_EXTERNAL                   ((uint8_t)0x10)               /*!< 外部调试请求标志位 */

/******************* SCB_MMFAR 寄存器的位定义 *****************/
#define  SCB_MMFAR_ADDRESS                   ((uint32_t)0xFFFFFFFF)        /*!< 存储器管理故障地址域 */

/******************* SCB_BFAR 寄存器的位定义 *****************/
#define  SCB_BFAR_ADDRESS                    ((uint32_t)0xFFFFFFFF)        /*!< 总线故障地址域 */

/******************* SCB_afsr 寄存器的位定义 *****************/
#define  SCB_AFSR_IMPDEF                     ((uint32_t)0xFFFFFFFF)        /*!< 由实现定义 */

/******************************************************************************/
/*                                                                            */
/*                    外部中断/事件控制器                     */
/*                                                                            */
/******************************************************************************/

/******************* EXTI_IMR 寄存器的位定义 *****************/
#define  EXTI_IMR_MR0                        ((uint32_t)0x00000001)        /*!< 线 0 的中断屏蔽 */
#define  EXTI_IMR_MR1                        ((uint32_t)0x00000002)        /*!< 线 1 的中断屏蔽 */
#define  EXTI_IMR_MR2                        ((uint32_t)0x00000004)        /*!< 线 2 的中断屏蔽 */
#define  EXTI_IMR_MR3                        ((uint32_t)0x00000008)        /*!< 线 3 的中断屏蔽 */
#define  EXTI_IMR_MR4                        ((uint32_t)0x00000010)        /*!< 线 4 的中断屏蔽 */
#define  EXTI_IMR_MR5                        ((uint32_t)0x00000020)        /*!< 线 5 的中断屏蔽 */
#define  EXTI_IMR_MR6                        ((uint32_t)0x00000040)        /*!< 线 6 的中断屏蔽 */
#define  EXTI_IMR_MR7                        ((uint32_t)0x00000080)        /*!< 线 7 的中断屏蔽 */
#define  EXTI_IMR_MR8                        ((uint32_t)0x00000100)        /*!< 线 8 的中断屏蔽 */
#define  EXTI_IMR_MR9                        ((uint32_t)0x00000200)        /*!< 线 9 的中断屏蔽 */
#define  EXTI_IMR_MR10                       ((uint32_t)0x00000400)        /*!< 线 10 的中断屏蔽 */
#define  EXTI_IMR_MR11                       ((uint32_t)0x00000800)        /*!< 线 11 的中断屏蔽 */
#define  EXTI_IMR_MR12                       ((uint32_t)0x00001000)        /*!< 线 12 的中断屏蔽 */
#define  EXTI_IMR_MR13                       ((uint32_t)0x00002000)        /*!< 线 13 的中断屏蔽 */
#define  EXTI_IMR_MR14                       ((uint32_t)0x00004000)        /*!< 线 14 的中断屏蔽 */
#define  EXTI_IMR_MR15                       ((uint32_t)0x00008000)        /*!< 线 15 的中断屏蔽 */
#define  EXTI_IMR_MR16                       ((uint32_t)0x00010000)        /*!< 线 16 的中断屏蔽 */
#define  EXTI_IMR_MR17                       ((uint32_t)0x00020000)        /*!< 线 17 的中断屏蔽 */
#define  EXTI_IMR_MR18                       ((uint32_t)0x00040000)        /*!< 线 18 的中断屏蔽 */
#define  EXTI_IMR_MR19                       ((uint32_t)0x00080000)        /*!< 线 19 的中断屏蔽 */

/******************* EXTI_EMR 寄存器的位定义 *****************/
#define  EXTI_EMR_MR0                        ((uint32_t)0x00000001)        /*!< 线 0 的事件屏蔽 */
#define  EXTI_EMR_MR1                        ((uint32_t)0x00000002)        /*!< 线 1 的事件屏蔽 */
#define  EXTI_EMR_MR2                        ((uint32_t)0x00000004)        /*!< 线 2 的事件屏蔽 */
#define  EXTI_EMR_MR3                        ((uint32_t)0x00000008)        /*!< 线 3 的事件屏蔽 */
#define  EXTI_EMR_MR4                        ((uint32_t)0x00000010)        /*!< 线 4 的事件屏蔽 */
#define  EXTI_EMR_MR5                        ((uint32_t)0x00000020)        /*!< 线 5 的事件屏蔽 */
#define  EXTI_EMR_MR6                        ((uint32_t)0x00000040)        /*!< 线 6 的事件屏蔽 */
#define  EXTI_EMR_MR7                        ((uint32_t)0x00000080)        /*!< 线 7 的事件屏蔽 */
#define  EXTI_EMR_MR8                        ((uint32_t)0x00000100)        /*!< 线 8 的事件屏蔽 */
#define  EXTI_EMR_MR9                        ((uint32_t)0x00000200)        /*!< 线 9 的事件屏蔽 */
#define  EXTI_EMR_MR10                       ((uint32_t)0x00000400)        /*!< 线 10 的事件屏蔽 */
#define  EXTI_EMR_MR11                       ((uint32_t)0x00000800)        /*!< 线 11 的事件屏蔽 */
#define  EXTI_EMR_MR12                       ((uint32_t)0x00001000)        /*!< 线 12 的事件屏蔽 */
#define  EXTI_EMR_MR13                       ((uint32_t)0x00002000)        /*!< 线 13 的事件屏蔽 */
#define  EXTI_EMR_MR14                       ((uint32_t)0x00004000)        /*!< 线 14 的事件屏蔽 */
#define  EXTI_EMR_MR15                       ((uint32_t)0x00008000)        /*!< 线 15 的事件屏蔽 */
#define  EXTI_EMR_MR16                       ((uint32_t)0x00010000)        /*!< 线 16 的事件屏蔽 */
#define  EXTI_EMR_MR17                       ((uint32_t)0x00020000)        /*!< 线 17 的事件屏蔽 */
#define  EXTI_EMR_MR18                       ((uint32_t)0x00040000)        /*!< 线 18 的事件屏蔽 */
#define  EXTI_EMR_MR19                       ((uint32_t)0x00080000)        /*!< 线 19 的事件屏蔽 */

/****************** EXTI_RTSR 寄存器的位定义 ****************/
#define  EXTI_RTSR_TR0                       ((uint32_t)0x00000001)        /*!< 线 0 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR1                       ((uint32_t)0x00000002)        /*!< 线 1 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR2                       ((uint32_t)0x00000004)        /*!< 线 2 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR3                       ((uint32_t)0x00000008)        /*!< 线 3 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR4                       ((uint32_t)0x00000010)        /*!< 线 4 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR5                       ((uint32_t)0x00000020)        /*!< 线 5 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR6                       ((uint32_t)0x00000040)        /*!< 线 6 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR7                       ((uint32_t)0x00000080)        /*!< 线 7 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR8                       ((uint32_t)0x00000100)        /*!< 线 8 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR9                       ((uint32_t)0x00000200)        /*!< 线 9 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR10                      ((uint32_t)0x00000400)        /*!< 线 10 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR11                      ((uint32_t)0x00000800)        /*!< 线 11 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR12                      ((uint32_t)0x00001000)        /*!< 线 12 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR13                      ((uint32_t)0x00002000)        /*!< 线 13 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR14                      ((uint32_t)0x00004000)        /*!< 线 14 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR15                      ((uint32_t)0x00008000)        /*!< 线 15 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR16                      ((uint32_t)0x00010000)        /*!< 线 16 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR17                      ((uint32_t)0x00020000)        /*!< 线 17 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR18                      ((uint32_t)0x00040000)        /*!< 线 18 的上升沿触发事件配置位 */
#define  EXTI_RTSR_TR19                      ((uint32_t)0x00080000)        /*!< 线 19 的上升沿触发事件配置位 */

/****************** EXTI_FTSR 寄存器的位定义 ****************/
#define  EXTI_FTSR_TR0                       ((uint32_t)0x00000001)        /*!< 线 0 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR1                       ((uint32_t)0x00000002)        /*!< 线 1 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR2                       ((uint32_t)0x00000004)        /*!< 线 2 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR3                       ((uint32_t)0x00000008)        /*!< 线 3 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR4                       ((uint32_t)0x00000010)        /*!< 线 4 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR5                       ((uint32_t)0x00000020)        /*!< 线 5 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR6                       ((uint32_t)0x00000040)        /*!< 线 6 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR7                       ((uint32_t)0x00000080)        /*!< 线 7 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR8                       ((uint32_t)0x00000100)        /*!< 线 8 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR9                       ((uint32_t)0x00000200)        /*!< 线 9 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR10                      ((uint32_t)0x00000400)        /*!< 线 10 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR11                      ((uint32_t)0x00000800)        /*!< 线 11 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR12                      ((uint32_t)0x00001000)        /*!< 线 12 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR13                      ((uint32_t)0x00002000)        /*!< 线 13 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR14                      ((uint32_t)0x00004000)        /*!< 线 14 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR15                      ((uint32_t)0x00008000)        /*!< 线 15 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR16                      ((uint32_t)0x00010000)        /*!< 线 16 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR17                      ((uint32_t)0x00020000)        /*!< 线 17 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR18                      ((uint32_t)0x00040000)        /*!< 线 18 的下降沿触发事件配置位 */
#define  EXTI_FTSR_TR19                      ((uint32_t)0x00080000)        /*!< 线 19 的下降沿触发事件配置位 */

/****************** EXTI_SWIER 寄存器的位定义 ****************/
#define  EXTI_SWIER_SWIER0                   ((uint32_t)0x00000001)        /*!< 线 0 的软件中断 */
#define  EXTI_SWIER_SWIER1                   ((uint32_t)0x00000002)        /*!< 线 1 的软件中断 */
#define  EXTI_SWIER_SWIER2                   ((uint32_t)0x00000004)        /*!< 线 2 的软件中断 */
#define  EXTI_SWIER_SWIER3                   ((uint32_t)0x00000008)        /*!< 线 3 的软件中断 */
#define  EXTI_SWIER_SWIER4                   ((uint32_t)0x00000010)        /*!< 线 4 的软件中断 */
#define  EXTI_SWIER_SWIER5                   ((uint32_t)0x00000020)        /*!< 线 5 的软件中断 */
#define  EXTI_SWIER_SWIER6                   ((uint32_t)0x00000040)        /*!< 线 6 的软件中断 */
#define  EXTI_SWIER_SWIER7                   ((uint32_t)0x00000080)        /*!< 线 7 的软件中断 */
#define  EXTI_SWIER_SWIER8                   ((uint32_t)0x00000100)        /*!< 线 8 的软件中断 */
#define  EXTI_SWIER_SWIER9                   ((uint32_t)0x00000200)        /*!< 线 9 的软件中断 */
#define  EXTI_SWIER_SWIER10                  ((uint32_t)0x00000400)        /*!< 线 10 的软件中断 */
#define  EXTI_SWIER_SWIER11                  ((uint32_t)0x00000800)        /*!< 线 11 的软件中断 */
#define  EXTI_SWIER_SWIER12                  ((uint32_t)0x00001000)        /*!< 线 12 的软件中断 */
#define  EXTI_SWIER_SWIER13                  ((uint32_t)0x00002000)        /*!< 线 13 的软件中断 */
#define  EXTI_SWIER_SWIER14                  ((uint32_t)0x00004000)        /*!< 线 14 的软件中断 */
#define  EXTI_SWIER_SWIER15                  ((uint32_t)0x00008000)        /*!< 线 15 的软件中断 */
#define  EXTI_SWIER_SWIER16                  ((uint32_t)0x00010000)        /*!< 线 16 的软件中断 */
#define  EXTI_SWIER_SWIER17                  ((uint32_t)0x00020000)        /*!< 线 17 的软件中断 */
#define  EXTI_SWIER_SWIER18                  ((uint32_t)0x00040000)        /*!< 线 18 的软件中断 */
#define  EXTI_SWIER_SWIER19                  ((uint32_t)0x00080000)        /*!< 线 19 的软件中断 */

/******************* EXTI_PR 寄存器的位定义 *****************/
#define  EXTI_PR_PR0                         ((uint32_t)0x00000001)        /*!< 线 0 的挂起位 */
#define  EXTI_PR_PR1                         ((uint32_t)0x00000002)        /*!< 线 1 的挂起位 */
#define  EXTI_PR_PR2                         ((uint32_t)0x00000004)        /*!< 线 2 的挂起位 */
#define  EXTI_PR_PR3                         ((uint32_t)0x00000008)        /*!< 线 3 的挂起位 */
#define  EXTI_PR_PR4                         ((uint32_t)0x00000010)        /*!< 线 4 的挂起位 */
#define  EXTI_PR_PR5                         ((uint32_t)0x00000020)        /*!< 线 5 的挂起位 */
#define  EXTI_PR_PR6                         ((uint32_t)0x00000040)        /*!< 线 6 的挂起位 */
#define  EXTI_PR_PR7                         ((uint32_t)0x00000080)        /*!< 线 7 的挂起位 */
#define  EXTI_PR_PR8                         ((uint32_t)0x00000100)        /*!< 线 8 的挂起位 */
#define  EXTI_PR_PR9                         ((uint32_t)0x00000200)        /*!< 线 9 的挂起位 */
#define  EXTI_PR_PR10                        ((uint32_t)0x00000400)        /*!< 线 10 的挂起位 */
#define  EXTI_PR_PR11                        ((uint32_t)0x00000800)        /*!< 线 11 的挂起位 */
#define  EXTI_PR_PR12                        ((uint32_t)0x00001000)        /*!< 线 12 的挂起位 */
#define  EXTI_PR_PR13                        ((uint32_t)0x00002000)        /*!< 线 13 的挂起位 */
#define  EXTI_PR_PR14                        ((uint32_t)0x00004000)        /*!< 线 14 的挂起位 */
#define  EXTI_PR_PR15                        ((uint32_t)0x00008000)        /*!< 线 15 的挂起位 */
#define  EXTI_PR_PR16                        ((uint32_t)0x00010000)        /*!< 线 16 的挂起位 */
#define  EXTI_PR_PR17                        ((uint32_t)0x00020000)        /*!< 线 17 的挂起位 */
#define  EXTI_PR_PR18                        ((uint32_t)0x00040000)        /*!< 线 18 的挂起位 */
#define  EXTI_PR_PR19                        ((uint32_t)0x00080000)        /*!< 线 19 的挂起位 */

/******************************************************************************/
/*                                                                            */
/*                             DMA 控制器                                 */
/*                                                                            */
/******************************************************************************/

/******************* DMA_ISR 寄存器的位定义 *****************/
#define  DMA_ISR_GIF1                        ((uint32_t)0x00000001)        /*!< 通道 1 全局中断标志位 */
#define  DMA_ISR_TCIF1                       ((uint32_t)0x00000002)        /*!< 通道 1 传输完成标志位 */
#define  DMA_ISR_HTIF1                       ((uint32_t)0x00000004)        /*!< 通道 1 半传输标志位 */
#define  DMA_ISR_TEIF1                       ((uint32_t)0x00000008)        /*!< 通道 1 传输错误标志位 */
#define  DMA_ISR_GIF2                        ((uint32_t)0x00000010)        /*!< 通道 2 全局中断标志位 */
#define  DMA_ISR_TCIF2                       ((uint32_t)0x00000020)        /*!< 通道 2 传输完成标志位 */
#define  DMA_ISR_HTIF2                       ((uint32_t)0x00000040)        /*!< 通道 2 半传输标志位 */
#define  DMA_ISR_TEIF2                       ((uint32_t)0x00000080)        /*!< 通道 2 传输错误标志位 */
#define  DMA_ISR_GIF3                        ((uint32_t)0x00000100)        /*!< 通道 3 全局中断标志位 */
#define  DMA_ISR_TCIF3                       ((uint32_t)0x00000200)        /*!< 通道 3 传输完成标志位 */
#define  DMA_ISR_HTIF3                       ((uint32_t)0x00000400)        /*!< 通道 3 半传输标志位 */
#define  DMA_ISR_TEIF3                       ((uint32_t)0x00000800)        /*!< 通道 3 传输错误标志位 */
#define  DMA_ISR_GIF4                        ((uint32_t)0x00001000)        /*!< 通道 4 全局中断标志位 */
#define  DMA_ISR_TCIF4                       ((uint32_t)0x00002000)        /*!< 通道 4 传输完成标志位 */
#define  DMA_ISR_HTIF4                       ((uint32_t)0x00004000)        /*!< 通道 4 半传输标志位 */
#define  DMA_ISR_TEIF4                       ((uint32_t)0x00008000)        /*!< 通道 4 传输错误标志位 */
#define  DMA_ISR_GIF5                        ((uint32_t)0x00010000)        /*!< 通道 5 全局中断标志位 */
#define  DMA_ISR_TCIF5                       ((uint32_t)0x00020000)        /*!< 通道 5 传输完成标志位 */
#define  DMA_ISR_HTIF5                       ((uint32_t)0x00040000)        /*!< 通道 5 半传输标志位 */
#define  DMA_ISR_TEIF5                       ((uint32_t)0x00080000)        /*!< 通道 5 传输错误标志位 */
#define  DMA_ISR_GIF6                        ((uint32_t)0x00100000)        /*!< 通道 6 全局中断标志位 */
#define  DMA_ISR_TCIF6                       ((uint32_t)0x00200000)        /*!< 通道 6 传输完成标志位 */
#define  DMA_ISR_HTIF6                       ((uint32_t)0x00400000)        /*!< 通道 6 半传输标志位 */
#define  DMA_ISR_TEIF6                       ((uint32_t)0x00800000)        /*!< 通道 6 传输错误标志位 */
#define  DMA_ISR_GIF7                        ((uint32_t)0x01000000)        /*!< 通道 7 全局中断标志位 */
#define  DMA_ISR_TCIF7                       ((uint32_t)0x02000000)        /*!< 通道 7 传输完成标志位 */
#define  DMA_ISR_HTIF7                       ((uint32_t)0x04000000)        /*!< 通道 7 半传输标志位 */
#define  DMA_ISR_TEIF7                       ((uint32_t)0x08000000)        /*!< 通道 7 传输错误标志位 */

/******************* DMA_IFCR 寄存器的位定义 *****************/
#define  DMA_IFCR_CGIF1                      ((uint32_t)0x00000001)        /*!< 通道 1 全局中断清除 */
#define  DMA_IFCR_CTCIF1                     ((uint32_t)0x00000002)        /*!< 通道 1 传输完成清除 */
#define  DMA_IFCR_CHTIF1                     ((uint32_t)0x00000004)        /*!< 通道 1 半传输清除 */
#define  DMA_IFCR_CTEIF1                     ((uint32_t)0x00000008)        /*!< 通道 1 传输错误清除 */
#define  DMA_IFCR_CGIF2                      ((uint32_t)0x00000010)        /*!< 通道 2 全局中断清除 */
#define  DMA_IFCR_CTCIF2                     ((uint32_t)0x00000020)        /*!< 通道 2 传输完成清除 */
#define  DMA_IFCR_CHTIF2                     ((uint32_t)0x00000040)        /*!< 通道 2 半传输清除 */
#define  DMA_IFCR_CTEIF2                     ((uint32_t)0x00000080)        /*!< 通道 2 传输错误清除 */
#define  DMA_IFCR_CGIF3                      ((uint32_t)0x00000100)        /*!< 通道 3 全局中断清除 */
#define  DMA_IFCR_CTCIF3                     ((uint32_t)0x00000200)        /*!< 通道 3 传输完成清除 */
#define  DMA_IFCR_CHTIF3                     ((uint32_t)0x00000400)        /*!< 通道 3 半传输清除 */
#define  DMA_IFCR_CTEIF3                     ((uint32_t)0x00000800)        /*!< 通道 3 传输错误清除 */
#define  DMA_IFCR_CGIF4                      ((uint32_t)0x00001000)        /*!< 通道 4 全局中断清除 */
#define  DMA_IFCR_CTCIF4                     ((uint32_t)0x00002000)        /*!< 通道 4 传输完成清除 */
#define  DMA_IFCR_CHTIF4                     ((uint32_t)0x00004000)        /*!< 通道 4 半传输清除 */
#define  DMA_IFCR_CTEIF4                     ((uint32_t)0x00008000)        /*!< 通道 4 传输错误清除 */
#define  DMA_IFCR_CGIF5                      ((uint32_t)0x00010000)        /*!< 通道 5 全局中断清除 */
#define  DMA_IFCR_CTCIF5                     ((uint32_t)0x00020000)        /*!< 通道 5 传输完成清除 */
#define  DMA_IFCR_CHTIF5                     ((uint32_t)0x00040000)        /*!< 通道 5 半传输清除 */
#define  DMA_IFCR_CTEIF5                     ((uint32_t)0x00080000)        /*!< 通道 5 传输错误清除 */
#define  DMA_IFCR_CGIF6                      ((uint32_t)0x00100000)        /*!< 通道 6 全局中断清除 */
#define  DMA_IFCR_CTCIF6                     ((uint32_t)0x00200000)        /*!< 通道 6 传输完成清除 */
#define  DMA_IFCR_CHTIF6                     ((uint32_t)0x00400000)        /*!< 通道 6 半传输清除 */
#define  DMA_IFCR_CTEIF6                     ((uint32_t)0x00800000)        /*!< 通道 6 传输错误清除 */
#define  DMA_IFCR_CGIF7                      ((uint32_t)0x01000000)        /*!< 通道 7 全局中断清除 */
#define  DMA_IFCR_CTCIF7                     ((uint32_t)0x02000000)        /*!< 通道 7 传输完成清除 */
#define  DMA_IFCR_CHTIF7                     ((uint32_t)0x04000000)        /*!< 通道 7 半传输清除 */
#define  DMA_IFCR_CTEIF7                     ((uint32_t)0x08000000)        /*!< 通道 7 传输错误清除 */

/******************* DMA_CCR1 寄存器的位定义 *****************/
#define  DMA_CCR1_EN                         ((uint16_t)0x0001)            /*!< 通道使能*/
#define  DMA_CCR1_TCIE                       ((uint16_t)0x0002)            /*!< 传输完成中断使能 */
#define  DMA_CCR1_HTIE                       ((uint16_t)0x0004)            /*!< 半传输中断使能 */
#define  DMA_CCR1_TEIE                       ((uint16_t)0x0008)            /*!< 传输错误中断使能 */
#define  DMA_CCR1_DIR                        ((uint16_t)0x0010)            /*!< 数据传输方向 */
#define  DMA_CCR1_CIRC                       ((uint16_t)0x0020)            /*!< 循环模式 */
#define  DMA_CCR1_PINC                       ((uint16_t)0x0040)            /*!< 外设地址增量模式 */
#define  DMA_CCR1_MINC                       ((uint16_t)0x0080)            /*!< 存储器地址增量模式 */

#define  DMA_CCR1_PSIZE                      ((uint16_t)0x0300)            /*!< PSIZE[1:0] 位（外设数据宽度） */
#define  DMA_CCR1_PSIZE_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  DMA_CCR1_PSIZE_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  DMA_CCR1_MSIZE                      ((uint16_t)0x0C00)            /*!< MSIZE[1:0] 位（存储器数据宽度） */
#define  DMA_CCR1_MSIZE_0                    ((uint16_t)0x0400)            /*!< 位 0 */
#define  DMA_CCR1_MSIZE_1                    ((uint16_t)0x0800)            /*!< 位 1 */

#define  DMA_CCR1_PL                         ((uint16_t)0x3000)            /*!< PL[1:0] 位（通道优先级） */
#define  DMA_CCR1_PL_0                       ((uint16_t)0x1000)            /*!< 位 0 */
#define  DMA_CCR1_PL_1                       ((uint16_t)0x2000)            /*!< 位 1 */

#define  DMA_CCR1_MEM2MEM                    ((uint16_t)0x4000)            /*!< 存储器到存储器模式 */

/******************* DMA_CCR2 寄存器的位定义 *****************/
#define  DMA_CCR2_EN                         ((uint16_t)0x0001)            /*!< 通道使能 */
#define  DMA_CCR2_TCIE                       ((uint16_t)0x0002)            /*!< 传输完成中断使能 */
#define  DMA_CCR2_HTIE                       ((uint16_t)0x0004)            /*!< 半传输中断使能 */
#define  DMA_CCR2_TEIE                       ((uint16_t)0x0008)            /*!< 传输错误中断使能 */
#define  DMA_CCR2_DIR                        ((uint16_t)0x0010)            /*!< 数据传输方向 */
#define  DMA_CCR2_CIRC                       ((uint16_t)0x0020)            /*!< 循环模式 */
#define  DMA_CCR2_PINC                       ((uint16_t)0x0040)            /*!< 外设地址增量模式 */
#define  DMA_CCR2_MINC                       ((uint16_t)0x0080)            /*!< 存储器地址增量模式 */

#define  DMA_CCR2_PSIZE                      ((uint16_t)0x0300)            /*!< PSIZE[1:0] 位（外设数据宽度） */
#define  DMA_CCR2_PSIZE_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  DMA_CCR2_PSIZE_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  DMA_CCR2_MSIZE                      ((uint16_t)0x0C00)            /*!< MSIZE[1:0] 位（存储器数据宽度） */
#define  DMA_CCR2_MSIZE_0                    ((uint16_t)0x0400)            /*!< 位 0 */
#define  DMA_CCR2_MSIZE_1                    ((uint16_t)0x0800)            /*!< 位 1 */

#define  DMA_CCR2_PL                         ((uint16_t)0x3000)            /*!< PL[1:0] 位（通道优先级） */
#define  DMA_CCR2_PL_0                       ((uint16_t)0x1000)            /*!< 位 0 */
#define  DMA_CCR2_PL_1                       ((uint16_t)0x2000)            /*!< 位 1 */

#define  DMA_CCR2_MEM2MEM                    ((uint16_t)0x4000)            /*!< 存储器到存储器模式 */

/******************* DMA_CCR3 寄存器的位定义 *****************/
#define  DMA_CCR3_EN                         ((uint16_t)0x0001)            /*!< 通道使能 */
#define  DMA_CCR3_TCIE                       ((uint16_t)0x0002)            /*!< 传输完成中断使能 */
#define  DMA_CCR3_HTIE                       ((uint16_t)0x0004)            /*!< 半传输中断使能 */
#define  DMA_CCR3_TEIE                       ((uint16_t)0x0008)            /*!< 传输错误中断使能 */
#define  DMA_CCR3_DIR                        ((uint16_t)0x0010)            /*!< 数据传输方向 */
#define  DMA_CCR3_CIRC                       ((uint16_t)0x0020)            /*!< 循环模式 */
#define  DMA_CCR3_PINC                       ((uint16_t)0x0040)            /*!< 外设地址增量模式 */
#define  DMA_CCR3_MINC                       ((uint16_t)0x0080)            /*!< 存储器地址增量模式 */

#define  DMA_CCR3_PSIZE                      ((uint16_t)0x0300)            /*!< PSIZE[1:0] 位（外设数据宽度） */
#define  DMA_CCR3_PSIZE_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  DMA_CCR3_PSIZE_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  DMA_CCR3_MSIZE                      ((uint16_t)0x0C00)            /*!< MSIZE[1:0] 位（存储器数据宽度） */
#define  DMA_CCR3_MSIZE_0                    ((uint16_t)0x0400)            /*!< 位 0 */
#define  DMA_CCR3_MSIZE_1                    ((uint16_t)0x0800)            /*!< 位 1 */

#define  DMA_CCR3_PL                         ((uint16_t)0x3000)            /*!< PL[1:0] 位（通道优先级） */
#define  DMA_CCR3_PL_0                       ((uint16_t)0x1000)            /*!< 位 0 */
#define  DMA_CCR3_PL_1                       ((uint16_t)0x2000)            /*!< 位 1 */

#define  DMA_CCR3_MEM2MEM                    ((uint16_t)0x4000)            /*!< 存储器到存储器模式 */

/*!<****************** DMA_CCR4 寄存器的位定义 ******************/
#define  DMA_CCR4_EN                         ((uint16_t)0x0001)            /*!< 通道使能 */
#define  DMA_CCR4_TCIE                       ((uint16_t)0x0002)            /*!< 传输完成中断使能 */
#define  DMA_CCR4_HTIE                       ((uint16_t)0x0004)            /*!< 半传输中断使能 */
#define  DMA_CCR4_TEIE                       ((uint16_t)0x0008)            /*!< 传输错误中断使能 */
#define  DMA_CCR4_DIR                        ((uint16_t)0x0010)            /*!< 数据传输方向 */
#define  DMA_CCR4_CIRC                       ((uint16_t)0x0020)            /*!< 循环模式 */
#define  DMA_CCR4_PINC                       ((uint16_t)0x0040)            /*!< 外设地址增量模式 */
#define  DMA_CCR4_MINC                       ((uint16_t)0x0080)            /*!< 存储器地址增量模式 */

#define  DMA_CCR4_PSIZE                      ((uint16_t)0x0300)            /*!< PSIZE[1:0] 位（外设数据宽度） */
#define  DMA_CCR4_PSIZE_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  DMA_CCR4_PSIZE_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  DMA_CCR4_MSIZE                      ((uint16_t)0x0C00)            /*!< MSIZE[1:0] 位（存储器数据宽度） */
#define  DMA_CCR4_MSIZE_0                    ((uint16_t)0x0400)            /*!< 位 0 */
#define  DMA_CCR4_MSIZE_1                    ((uint16_t)0x0800)            /*!< 位 1 */

#define  DMA_CCR4_PL                         ((uint16_t)0x3000)            /*!< PL[1:0] 位（通道优先级） */
#define  DMA_CCR4_PL_0                       ((uint16_t)0x1000)            /*!< 位 0 */
#define  DMA_CCR4_PL_1                       ((uint16_t)0x2000)            /*!< 位 1 */

#define  DMA_CCR4_MEM2MEM                    ((uint16_t)0x4000)            /*!< 存储器到存储器模式 */

/****************** DMA_CCR5 寄存器的位定义 ****************/
#define  DMA_CCR5_EN                         ((uint16_t)0x0001)            /*!< 通道使能 */
#define  DMA_CCR5_TCIE                       ((uint16_t)0x0002)            /*!< 传输完成中断使能 */
#define  DMA_CCR5_HTIE                       ((uint16_t)0x0004)            /*!< 半传输中断使能 */
#define  DMA_CCR5_TEIE                       ((uint16_t)0x0008)            /*!< 传输错误中断使能 */
#define  DMA_CCR5_DIR                        ((uint16_t)0x0010)            /*!< 数据传输方向 */
#define  DMA_CCR5_CIRC                       ((uint16_t)0x0020)            /*!< 循环模式 */
#define  DMA_CCR5_PINC                       ((uint16_t)0x0040)            /*!< 外设地址增量模式 */
#define  DMA_CCR5_MINC                       ((uint16_t)0x0080)            /*!< 存储器地址增量模式 */

#define  DMA_CCR5_PSIZE                      ((uint16_t)0x0300)            /*!< PSIZE[1:0] 位（外设数据宽度） */
#define  DMA_CCR5_PSIZE_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  DMA_CCR5_PSIZE_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  DMA_CCR5_MSIZE                      ((uint16_t)0x0C00)            /*!< MSIZE[1:0] 位（存储器数据宽度） */
#define  DMA_CCR5_MSIZE_0                    ((uint16_t)0x0400)            /*!< 位 0 */
#define  DMA_CCR5_MSIZE_1                    ((uint16_t)0x0800)            /*!< 位 1 */

#define  DMA_CCR5_PL                         ((uint16_t)0x3000)            /*!< PL[1:0] 位（通道优先级） */
#define  DMA_CCR5_PL_0                       ((uint16_t)0x1000)            /*!< 位 0 */
#define  DMA_CCR5_PL_1                       ((uint16_t)0x2000)            /*!< 位 1 */

#define  DMA_CCR5_MEM2MEM                    ((uint16_t)0x4000)            /*!< 存储器到存储器模式使能 */

/******************* DMA_CCR6 寄存器的位定义 *****************/
#define  DMA_CCR6_EN                         ((uint16_t)0x0001)            /*!< 通道使能 */
#define  DMA_CCR6_TCIE                       ((uint16_t)0x0002)            /*!< 传输完成中断使能 */
#define  DMA_CCR6_HTIE                       ((uint16_t)0x0004)            /*!< 半传输中断使能 */
#define  DMA_CCR6_TEIE                       ((uint16_t)0x0008)            /*!< 传输错误中断使能 */
#define  DMA_CCR6_DIR                        ((uint16_t)0x0010)            /*!< 数据传输方向 */
#define  DMA_CCR6_CIRC                       ((uint16_t)0x0020)            /*!< 循环模式 */
#define  DMA_CCR6_PINC                       ((uint16_t)0x0040)            /*!< 外设地址增量模式 */
#define  DMA_CCR6_MINC                       ((uint16_t)0x0080)            /*!< 存储器地址增量模式 */

#define  DMA_CCR6_PSIZE                      ((uint16_t)0x0300)            /*!< PSIZE[1:0] 位（外设数据宽度） */
#define  DMA_CCR6_PSIZE_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  DMA_CCR6_PSIZE_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  DMA_CCR6_MSIZE                      ((uint16_t)0x0C00)            /*!< MSIZE[1:0] 位（存储器数据宽度） */
#define  DMA_CCR6_MSIZE_0                    ((uint16_t)0x0400)            /*!< 位 0 */
#define  DMA_CCR6_MSIZE_1                    ((uint16_t)0x0800)            /*!< 位 1 */

#define  DMA_CCR6_PL                         ((uint16_t)0x3000)            /*!< PL[1:0] 位（通道优先级） */
#define  DMA_CCR6_PL_0                       ((uint16_t)0x1000)            /*!< 位 0 */
#define  DMA_CCR6_PL_1                       ((uint16_t)0x2000)            /*!< 位 1 */

#define  DMA_CCR6_MEM2MEM                    ((uint16_t)0x4000)            /*!< 存储器到存储器模式 */

/******************* DMA_CCR7 寄存器的位定义 *****************/
#define  DMA_CCR7_EN                         ((uint16_t)0x0001)            /*!< 通道使能 */
#define  DMA_CCR7_TCIE                       ((uint16_t)0x0002)            /*!< 传输完成中断使能 */
#define  DMA_CCR7_HTIE                       ((uint16_t)0x0004)            /*!< 半传输中断使能 */
#define  DMA_CCR7_TEIE                       ((uint16_t)0x0008)            /*!< 传输错误中断使能 */
#define  DMA_CCR7_DIR                        ((uint16_t)0x0010)            /*!< 数据传输方向 */
#define  DMA_CCR7_CIRC                       ((uint16_t)0x0020)            /*!< 循环模式 */
#define  DMA_CCR7_PINC                       ((uint16_t)0x0040)            /*!< 外设地址增量模式 */
#define  DMA_CCR7_MINC                       ((uint16_t)0x0080)            /*!< 存储器地址增量模式 */

#define  DMA_CCR7_PSIZE            ,         ((uint16_t)0x0300)            /*!< PSIZE[1:0] 位（外设数据宽度） */
#define  DMA_CCR7_PSIZE_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  DMA_CCR7_PSIZE_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  DMA_CCR7_MSIZE                      ((uint16_t)0x0C00)            /*!< MSIZE[1:0] 位（存储器数据宽度） */
#define  DMA_CCR7_MSIZE_0                    ((uint16_t)0x0400)            /*!< 位 0 */
#define  DMA_CCR7_MSIZE_1                    ((uint16_t)0x0800)            /*!< 位 1 */

#define  DMA_CCR7_PL                         ((uint16_t)0x3000)            /*!< PL[1:0] 位（通道优先级） */
#define  DMA_CCR7_PL_0                       ((uint16_t)0x1000)            /*!< 位 0 */
#define  DMA_CCR7_PL_1                       ((uint16_t)0x2000)            /*!< 位 1 */

#define  DMA_CCR7_MEM2MEM                    ((uint16_t)0x4000)            /*!< 存储器到存储器模式使能 */

/****************** DMA_CNDTR1 寄存器的位定义 ****************/
#define  DMA_CNDTR1_NDT                      ((uint16_t)0xFFFF)            /*!< 要传输的数据个数 */

/****************** DMA_CNDTR2 寄存器的位定义 ****************/
#define  DMA_CNDTR2_NDT                      ((uint16_t)0xFFFF)            /*!< 要传输的数据个数 */

/****************** DMA_CNDTR3 寄存器的位定义 ****************/
#define  DMA_CNDTR3_NDT                      ((uint16_t)0xFFFF)            /*!< 要传输的数据个数 */

/****************** DMA_CNDTR4 寄存器的位定义 ****************/
#define  DMA_CNDTR4_NDT                      ((uint16_t)0xFFFF)            /*!< 要传输的数据个数 */

/****************** DMA_CNDTR5 寄存器的位定义 ****************/
#define  DMA_CNDTR5_NDT                      ((uint16_t)0xFFFF)            /*!< 要传输的数据个数 */

/****************** DMA_CNDTR6 寄存器的位定义 ****************/
#define  DMA_CNDTR6_NDT                      ((uint16_t)0xFFFF)            /*!< 要传输的数据个数 */

/****************** DMA_CNDTR7 寄存器的位定义 ****************/
#define  DMA_CNDTR7_NDT                      ((uint16_t)0xFFFF)            /*!< 要传输的数据个数 */

/****************** DMA_CPAR1 寄存器的位定义 ****************/
#define  DMA_CPAR1_PA                        ((uint32_t)0xFFFFFFFF)        /*!< 外设地址 */

/****************** DMA_CPAR2 寄存器的位定义 ****************/
#define  DMA_CPAR2_PA                        ((uint32_t)0xFFFFFFFF)        /*!< 外设地址 */

/****************** DMA_CPAR3 寄存器的位定义 ****************/
#define  DMA_CPAR3_PA                        ((uint32_t)0xFFFFFFFF)        /*!< 外设地址 */


/****************** DMA_CPAR4 寄存器的位定义 ****************/
#define  DMA_CPAR4_PA                        ((uint32_t)0xFFFFFFFF)        /*!< 外设地址 */

/****************** DMA_CPAR5 寄存器的位定义 ****************/
#define  DMA_CPAR5_PA                        ((uint32_t)0xFFFFFFFF)        /*!< 外设地址 */

/****************** DMA_CPAR6 寄存器的位定义 ****************/
#define  DMA_CPAR6_PA                        ((uint32_t)0xFFFFFFFF)        /*!< 外设地址 */


/****************** DMA_CPAR7 寄存器的位定义 ****************/
#define  DMA_CPAR7_PA                        ((uint32_t)0xFFFFFFFF)        /*!< 外设地址 */

/****************** DMA_CMAR1 寄存器的位定义 ****************/
#define  DMA_CMAR1_MA                        ((uint32_t)0xFFFFFFFF)        /*!< 存储器地址 */

/****************** DMA_CMAR2 寄存器的位定义 ****************/
#define  DMA_CMAR2_MA                        ((uint32_t)0xFFFFFFFF)        /*!< 存储器地址 */

/****************** DMA_CMAR3 寄存器的位定义 ****************/
#define  DMA_CMAR3_MA                        ((uint32_t)0xFFFFFFFF)        /*!< 存储器地址 */


/****************** DMA_CMAR4 寄存器的位定义 ****************/
#define  DMA_CMAR4_MA                        ((uint32_t)0xFFFFFFFF)        /*!< 存储器地址 */

/****************** DMA_CMAR5 寄存器的位定义 ****************/
#define  DMA_CMAR5_MA                        ((uint32_t)0xFFFFFFFF)        /*!< 存储器地址 */

/****************** DMA_CMAR6 寄存器的位定义 ****************/
#define  DMA_CMAR6_MA                        ((uint32_t)0xFFFFFFFF)        /*!< 存储器地址 */

/****************** DMA_CMAR7 寄存器的位定义 ****************/
#define  DMA_CMAR7_MA                        ((uint32_t)0xFFFFFFFF)        /*!< 存储器地址 */

/******************************************************************************/
/*                                                                            */
/*                        模数转换器                         */
/*                                                                            */
/******************************************************************************/

/******************** ADC_SR 寄存器的位定义 ******************/
#define  ADC_SR_AWD                          ((uint8_t)0x01)               /*!< 模拟看门狗标志位 */
#define  ADC_SR_EOC                          ((uint8_t)0x02)               /*!< 转换结束 */
#define  ADC_SR_JEOC                         ((uint8_t)0x04)               /*!< 注入通道转换结束 */
#define  ADC_SR_JSTRT                        ((uint8_t)0x08)               /*!< 注入通道启动标志位 */
#define  ADC_SR_STRT                         ((uint8_t)0x10)               /*!< 规则通道启动标志位 */

/******************* ADC_CR1 寄存器的位定义 *****************/
#define  ADC_CR1_AWDCH                       ((uint32_t)0x0000001F)        /*!< AWDCH[4:0] 位（模拟看门狗通道选择位） */
#define  ADC_CR1_AWDCH_0                     ((uint32_t)0x00000001)        /*!< 位 0 */
#define  ADC_CR1_AWDCH_1                     ((uint32_t)0x00000002)        /*!< 位 1 */
#define  ADC_CR1_AWDCH_2                     ((uint32_t)0x00000004)        /*!< 位 2 */
#define  ADC_CR1_AWDCH_3                     ((uint32_t)0x00000008)        /*!< 位 3 */
#define  ADC_CR1_AWDCH_4                     ((uint32_t)0x00000010)        /*!< 位 4 */

#define  ADC_CR1_EOCIE                       ((uint32_t)0x00000020)        /*!< EOC 中断使能 */
#define  ADC_CR1_AWDIE                       ((uint32_t)0x00000040)        /*!< 模拟看门狗中断使能 */
#define  ADC_CR1_JEOCIE                      ((uint32_t)0x00000080)        /*!< 注入通道中断使能 */
#define  ADC_CR1_SCAN                        ((uint32_t)0x00000100)        /*!< 扫描模式 */
#define  ADC_CR1_AWDSGL                      ((uint32_t)0x00000200)        /*!< 在扫描模式下对单个通道使能看门狗 */
#define  ADC_CR1_JAUTO                       ((uint32_t)0x00000400)        /*!< 自动注入组转换 */
#define  ADC_CR1_DISCEN                      ((uint32_t)0x00000800)        /*!< 规则通道的间断模式 */
#define  ADC_CR1_JDISCEN                     ((uint32_t)0x00001000)        /*!< 注入通道的间断模式 */

#define  ADC_CR1_DISCNUM                     ((uint32_t)0x0000E000)        /*!< DISCNUM[2:0] 位（间断模式通道数） */
#define  ADC_CR1_DISCNUM_0                   ((uint32_t)0x00002000)        /*!< 位 0 */
#define  ADC_CR1_DISCNUM_1                   ((uint32_t)0x00004000)        /*!< 位 1 */
#define  ADC_CR1_DISCNUM_2                   ((uint32_t)0x00008000)        /*!< 位 2 */

#define  ADC_CR1_DUALMOD                     ((uint32_t)0x000F0000)        /*!< DUALMOD[3:0] 位（双重模式选择） */
#define  ADC_CR1_DUALMOD_0                   ((uint32_t)0x00010000)        /*!< 位 0 */
#define  ADC_CR1_DUALMOD_1                   ((uint32_t)0x00020000)        /*!< 位 1 */
#define  ADC_CR1_DUALMOD_2                   ((uint32_t)0x00040000)        /*!< 位 2 */
#define  ADC_CR1_DUALMOD_3                   ((uint32_t)0x00080000)        /*!< 位 3 */

#define  ADC_CR1_JAWDEN                      ((uint32_t)0x00400000)        /*!< 注入通道的模拟看门狗使能 */
#define  ADC_CR1_AWDEN                       ((uint32_t)0x00800000)        /*!< 规则通道的模拟看门狗使能 */

  
/******************* ADC_CR2 寄存器的位定义 *****************/
#define  ADC_CR2_ADON                        ((uint32_t)0x00000001)        /*!< A/D 转换器开 / 关 */
#define  ADC_CR2_CONT                        ((uint32_t)0x00000002)        /*!< 连续转换 */
#define  ADC_CR2_CAL                         ((uint32_t)0x00000004)        /*!< A/D 校准 */
#define  ADC_CR2_RSTCAL                      ((uint32_t)0x00000008)        /*!< 复位校准 */
#define  ADC_CR2_DMA                         ((uint32_t)0x00000100)        /*!< 直接存储器访问模式 */
#define  ADC_CR2_ALIGN                       ((uint32_t)0x00000800)        /*!< 数据对齐 */

#define  ADC_CR2_JEXTSEL                     ((uint32_t)0x00007000)        /*!< JEXTSEL[2:0] 位（注入组的外部事件选择） */
#define  ADC_CR2_JEXTSEL_0                   ((uint32_t)0x00001000)        /*!< 位 0 */
#define  ADC_CR2_JEXTSEL_1                   ((uint32_t)0x00002000)        /*!< 位 1 */
#define  ADC_CR2_JEXTSEL_2                   ((uint32_t)0x00004000)        /*!< 位 2 */

#define  ADC_CR2_JEXTTRIG                    ((uint32_t)0x00008000)        /*!< 注入通道的外部触发转换模式 */

#define  ADC_CR2_EXTSEL                      ((uint32_t)0x000E0000)        /*!< EXTSEL[2:0] 位（规则组的外部事件选择） */
#define  ADC_CR2_EXTSEL_0                    ((uint32_t)0x00020000)        /*!< 位 0 */
#define  ADC_CR2_EXTSEL_1                    ((uint32_t)0x00040000)        /*!< 位 1 */
#define  ADC_CR2_EXTSEL_2                    ((uint32_t)0x00080000)        /*!< 位 2 */

#define  ADC_CR2_EXTTRIG                     ((uint32_t)0x00100000)        /*!< 规则通道的外部触发转换模式 */
#define  ADC_CR2_JSWSTART                    ((uint32_t)0x00200000)        /*!< 启动注入通道转换 */
#define  ADC_CR2_SWSTART                     ((uint32_t)0x00400000)        /*!< 启动规则通道转换 */
#define  ADC_CR2_TSVREFE                     ((uint32_t)0x00800000)        /*!< 温度传感器和 VREFINT 使能 */

/****************** ADC_SMPR1 寄存器的位定义 ****************/
#define  ADC_SMPR1_SMP10                     ((uint32_t)0x00000007)        /*!< SMP10[2:0] 位（通道 10 采样时间选择） */
#define  ADC_SMPR1_SMP10_0                   ((uint32_t)0x00000001)        /*!< 位 0 */
#define  ADC_SMPR1_SMP10_1                   ((uint32_t)0x00000002)        /*!< 位 1 */
#define  ADC_SMPR1_SMP10_2                   ((uint32_t)0x00000004)        /*!< 位 2 */

#define  ADC_SMPR1_SMP11                     ((uint32_t)0x00000038)        /*!< SMP11[2:0] 位（通道 11 采样时间选择） */
#define  ADC_SMPR1_SMP11_0                   ((uint32_t)0x00000008)        /*!< 位 0 */
#define  ADC_SMPR1_SMP11_1                   ((uint32_t)0x00000010)        /*!< 位 1 */
#define  ADC_SMPR1_SMP11_2                   ((uint32_t)0x00000020)        /*!< 位 2 */

#define  ADC_SMPR1_SMP12                     ((uint32_t)0x000001C0)        /*!< SMP12[2:0] 位（通道 12 采样时间选择） */
#define  ADC_SMPR1_SMP12_0                   ((uint32_t)0x00000040)        /*!< 位 0 */
#define  ADC_SMPR1_SMP12_1                   ((uint32_t)0x00000080)        /*!< 位 1 */
#define  ADC_SMPR1_SMP12_2                   ((uint32_t)0x00000100)        /*!< 位 2 */

#define  ADC_SMPR1_SMP13                     ((uint32_t)0x00000E00)        /*!< SMP13[2:0] 位（通道 13 采样时间选择） */
#define  ADC_SMPR1_SMP13_0                   ((uint32_t)0x00000200)        /*!< 位 0 */
#define  ADC_SMPR1_SMP13_1                   ((uint32_t)0x00000400)        /*!< 位 1 */
#define  ADC_SMPR1_SMP13_2                   ((uint32_t)0x00000800)        /*!< 位 2 */

#define  ADC_SMPR1_SMP14                     ((uint32_t)0x00007000)        /*!< SMP14[2:0] 位（通道 14 采样时间选择） */
#define  ADC_SMPR1_SMP14_0                   ((uint32_t)0x00001000)        /*!< 位 0 */
#define  ADC_SMPR1_SMP14_1                   ((uint32_t)0x00002000)        /*!< 位 1 */
#define  ADC_SMPR1_SMP14_2                   ((uint32_t)0x00004000)        /*!< 位 2 */

#define  ADC_SMPR1_SMP15                     ((uint32_t)0x00038000)        /*!< SMP15[2:0] 位（通道 15 采样时间选择） */
#define  ADC_SMPR1_SMP15_0                   ((uint32_t)0x00008000)        /*!< 位 0 */
#define  ADC_SMPR1_SMP15_1                   ((uint32_t)0x00010000)        /*!< 位 1 */
#define  ADC_SMPR1_SMP15_2                   ((uint32_t)0x00020000)        /*!< 位 2 */

#define  ADC_SMPR1_SMP16                     ((uint32_t)0x001C0000)        /*!< SMP16[2:0] 位（通道 16 采样时间选择） */
#define  ADC_SMPR1_SMP16_0                   ((uint32_t)0x00040000)        /*!< 位 0 */
#define  ADC_SMPR1_SMP16_1                   ((uint32_t)0x00080000)        /*!< 位 1 */
#define  ADC_SMPR1_SMP16_2                   ((uint32_t)0x00100000)        /*!< 位 2 */

#define  ADC_SMPR1_SMP17                     ((uint32_t)0x00E00000)        /*!< SMP17[2:0] 位（通道 17 采样时间选择） */
#define  ADC_SMPR1_SMP17_0                   ((uint32_t)0x00200000)        /*!< 位 0 */
#define  ADC_SMPR1_SMP17_1                   ((uint32_t)0x00400000)        /*!< 位 1 */
#define  ADC_SMPR1_SMP17_2                   ((uint32_t)0x00800000)        /*!< 位 2 */

/****************** ADC_SMPR2 寄存器的位定义 ****************/
#define  ADC_SMPR2_SMP0                      ((uint32_t)0x00000007)        /*!< SMP0[2:0] 位（通道 0 采样时间选择） */
#define  ADC_SMPR2_SMP0_0                    ((uint32_t)0x00000001)        /*!< 位 0 */
#define  ADC_SMPR2_SMP0_1                    ((uint32_t)0x00000002)        /*!< 位 1 */
#define  ADC_SMPR2_SMP0_2                    ((uint32_t)0x00000004)        /*!< 位 2 */

#define  ADC_SMPR2_SMP1                      ((uint32_t)0x00000038)        /*!< SMP1[2:0] 位（通道 1 采样时间选择） */
#define  ADC_SMPR2_SMP1_0                    ((uint32_t)0x00000008)        /*!< 位 0 */
#define  ADC_SMPR2_SMP1_1                    ((uint32_t)0x00000010)        /*!< 位 1 */
#define  ADC_SMPR2_SMP1_2                    ((uint32_t)0x00000020)        /*!< 位 2 */

#define  ADC_SMPR2_SMP2                      ((uint32_t)0x000001C0)        /*!< SMP2[2:0] 位（通道 2 采样时间选择） */
#define  ADC_SMPR2_SMP2_0                    ((uint32_t)0x00000040)        /*!< 位 0 */
#define  ADC_SMPR2_SMP2_1                    ((uint32_t)0x00000080)        /*!< 位 1 */
#define  ADC_SMPR2_SMP2_2                    ((uint32_t)0x00000100)        /*!< 位 2 */

#define  ADC_SMPR2_SMP3                      ((uint32_t)0x00000E00)        /*!< SMP3[2:0] 位（通道 3 采样时间选择） */
#define  ADC_SMPR2_SMP3_0                    ((uint32_t)0x00000200)        /*!< 位 0 */
#define  ADC_SMPR2_SMP3_1                    ((uint32_t)0x00000400)        /*!< 位 1 */
#define  ADC_SMPR2_SMP3_2                    ((uint32_t)0x00000800)        /*!< 位 2 */

#define  ADC_SMPR2_SMP4                      ((uint32_t)0x00007000)        /*!< SMP4[2:0] 位（通道 4 采样时间选择） */
#define  ADC_SMPR2_SMP4_0                    ((uint32_t)0x00001000)        /*!< 位 0 */
#define  ADC_SMPR2_SMP4_1                    ((uint32_t)0x00002000)        /*!< 位 1 */
#define  ADC_SMPR2_SMP4_2                    ((uint32_t)0x00004000)        /*!< 位 2 */

#define  ADC_SMPR2_SMP5                      ((uint32_t)0x00038000)        /*!< SMP5[2:0] 位（通道 5 采样时间选择） */
#define  ADC_SMPR2_SMP5_0                    ((uint32_t)0x00008000)        /*!< 位 0 */
#define  ADC_SMPR2_SMP5_1                    ((uint32_t)0x00010000)        /*!< 位 1 */
#define  ADC_SMPR2_SMP5_2                    ((uint32_t)0x00020000)        /*!< 位 2 */

#define  ADC_SMPR2_SMP6                      ((uint32_t)0x001C0000)        /*!< SMP6[2:0] 位（通道 6 采样时间选择） */
#define  ADC_SMPR2_SMP6_0                    ((uint32_t)0x00040000)        /*!< 位 0 */
#define  ADC_SMPR2_SMP6_1                    ((uint32_t)0x00080000)        /*!< 位 1 */
#define  ADC_SMPR2_SMP6_2                    ((uint32_t)0x00100000)        /*!< 位 2 */

#define  ADC_SMPR2_SMP7                      ((uint32_t)0x00E00000)        /*!< SMP7[2:0] 位（通道 7 采样时间选择） */
#define  ADC_SMPR2_SMP7_0                    ((uint32_t)0x00200000)        /*!< 位 0 */
#define  ADC_SMPR2_SMP7_1                    ((uint32_t)0x00400000)        /*!< 位 1 */
#define  ADC_SMPR2_SMP7_2                    ((uint32_t)0x00800000)        /*!< 位 2 */

#define  ADC_SMPR2_SMP8                      ((uint32_t)0x07000000)        /*!< SMP8[2:0] 位（通道 8 采样时间选择） */
#define  ADC_SMPR2_SMP8_0                    ((uint32_t)0x01000000)        /*!< 位 0 */
#define  ADC_SMPR2_SMP8_1                    ((uint32_t)0x02000000)        /*!< 位 1 */
#define  ADC_SMPR2_SMP8_2                    ((uint32_t)0x04000000)        /*!< 位 2 */

#define  ADC_SMPR2_SMP9                      ((uint32_t)0x38000000)        /*!< SMP9[2:0] 位（通道 9 采样时间选择） */
#define  ADC_SMPR2_SMP9_0                    ((uint32_t)0x08000000)        /*!< 位 0 */
#define  ADC_SMPR2_SMP9_1                    ((uint32_t)0x10000000)        /*!< 位 1 */
#define  ADC_SMPR2_SMP9_2                    ((uint32_t)0x20000000)        /*!< 位 2 */

/****************** ADC_JOFR1 寄存器的位定义 ****************/
#define  ADC_JOFR1_JOFFSET1                  ((uint16_t)0x0FFF)            /*!< 注入通道 1 的数据偏移 */

/****************** ADC_JOFR2 寄存器的位定义 ****************/
#define  ADC_JOFR2_JOFFSET2                  ((uint16_t)0x0FFF)            /*!< 注入通道 2 的数据偏移 */

/****************** ADC_JOFR3 寄存器的位定义 ****************/
#define  ADC_JOFR3_JOFFSET3                  ((uint16_t)0x0FFF)            /*!< 注入通道 3 的数据偏移 */

/****************** ADC_JOFR4 寄存器的位定义 ****************/
#define  ADC_JOFR4_JOFFSET4                  ((uint16_t)0x0FFF)            /*!< 注入通道 4 的数据偏移 */

/******************* ADC_HTR 寄存器的位定义 *****************/
#define  ADC_HTR_HT                          ((uint16_t)0x0FFF)            /*!< 模拟看门狗高阈值 */

/******************* ADC_LTR 寄存器的位定义 *****************/
#define  ADC_LTR_LT                          ((uint16_t)0x0FFF)            /*!< 模拟看门狗低阈值 */

/******************* ADC_SQR1 寄存器的位定义 *****************/
#define  ADC_SQR1_SQ13                       ((uint32_t)0x0000001F)        /*!< SQ13[4:0] 位（规则序列中的第 13 次转换） */
#define  ADC_SQR1_SQ13_0                     ((uint32_t)0x00000001)        /*!< 位 0 */
#define  ADC_SQR1_SQ13_1                     ((uint32_t)0x00000002)        /*!< 位 1 */
#define  ADC_SQR1_SQ13_2                     ((uint32_t)0x00000004)        /*!< 位 2 */
#define  ADC_SQR1_SQ13_3                     ((uint32_t)0x00000008)        /*!< 位 3 */
#define  ADC_SQR1_SQ13_4                     ((uint32_t)0x00000010)        /*!< 位 4 */

#define  ADC_SQR1_SQ14                       ((uint32_t)0x000003E0)        /*!< SQ14[4:0] 位（规则序列中的第 14 次转换） */
#define  ADC_SQR1_SQ14_0                     ((uint32_t)0x00000020)        /*!< 位 0 */
#define  ADC_SQR1_SQ14_1                     ((uint32_t)0x00000040)        /*!< 位 1 */
#define  ADC_SQR1_SQ14_2                     ((uint32_t)0x00000080)        /*!< 位 2 */
#define  ADC_SQR1_SQ14_3                     ((uint32_t)0x00000100)        /*!< 位 3 */
#define  ADC_SQR1_SQ14_4                     ((uint32_t)0x00000200)        /*!< 位 4 */

#define  ADC_SQR1_SQ15                       ((uint32_t)0x00007C00)        /*!< SQ15[4:0] 位（规则序列中的第 15 次转换） */
#define  ADC_SQR1_SQ15_0                     ((uint32_t)0x00000400)        /*!< 位 0 */
#define  ADC_SQR1_SQ15_1                     ((uint32_t)0x00000800)        /*!< 位 1 */
#define  ADC_SQR1_SQ15_2                     ((uint32_t)0x00001000)        /*!< 位 2 */
#define  ADC_SQR1_SQ15_3                     ((uint32_t)0x00002000)        /*!< 位 3 */
#define  ADC_SQR1_SQ15_4                     ((uint32_t)0x00004000)        /*!< 位 4 */

#define  ADC_SQR1_SQ16                       ((uint32_t)0x000F8000)        /*!< SQ16[4:0] 位（规则序列中的第 16 次转换） */
#define  ADC_SQR1_SQ16_0                     ((uint32_t)0x00008000)        /*!< 位 0 */
#define  ADC_SQR1_SQ16_1                     ((uint32_t)0x00010000)        /*!< 位 1 */
#define  ADC_SQR1_SQ16_2                     ((uint32_t)0x00020000)        /*!< 位 2 */
#define  ADC_SQR1_SQ16_3                     ((uint32_t)0x00040000)        /*!< 位 3 */
#define  ADC_SQR1_SQ16_4                     ((uint32_t)0x00080000)        /*!< 位 4 */

#define  ADC_SQR1_L                          ((uint32_t)0x00F00000)        /*!< L[3:0] 位（规则通道序列长度） */
#define  ADC_SQR1_L_0                        ((uint32_t)0x00100000)        /*!< 位 0 */
#define  ADC_SQR1_L_1                        ((uint32_t)0x00200000)        /*!< 位 1 */
#define  ADC_SQR1_L_2                        ((uint32_t)0x00400000)        /*!< 位 2 */
#define  ADC_SQR1_L_3                        ((uint32_t)0x00800000)        /*!< 位 3 */

/******************* ADC_SQR2 寄存器的位定义 *****************/
#define  ADC_SQR2_SQ7                        ((uint32_t)0x0000001F)        /*!< SQ7[4:0] 位（规则序列中的第 7 次转换） */
#define  ADC_SQR2_SQ7_0                      ((uint32_t)0x00000001)        /*!< 位 0 */
#define  ADC_SQR2_SQ7_1                      ((uint32_t)0x00000002)        /*!< 位 1 */
#define  ADC_SQR2_SQ7_2                      ((uint32_t)0x00000004)        /*!< 位 2 */
#define  ADC_SQR2_SQ7_3                      ((uint32_t)0x00000008)        /*!< 位 3 */
#define  ADC_SQR2_SQ7_4                      ((uint32_t)0x00000010)        /*!< 位 4 */

#define  ADC_SQR2_SQ8                        ((uint32_t)0x000003E0)        /*!< SQ8[4:0] 位（规则序列中的第 8 次转换） */
#define  ADC_SQR2_SQ8_0                      ((uint32_t)0x00000020)        /*!< 位 0 */
#define  ADC_SQR2_SQ8_1                      ((uint32_t)0x00000040)        /*!< 位 1 */
#define  ADC_SQR2_SQ8_2                      ((uint32_t)0x00000080)        /*!< 位 2 */
#define  ADC_SQR2_SQ8_3                      ((uint32_t)0x00000100)        /*!< 位 3 */
#define  ADC_SQR2_SQ8_4                      ((uint32_t)0x00000200)        /*!< 位 4 */

#define  ADC_SQR2_SQ9                        ((uint32_t)0x00007C00)        /*!< SQ9[4:0] 位（规则序列中的第 9 次转换） */
#define  ADC_SQR2_SQ9_0                      ((uint32_t)0x00000400)        /*!< 位 0 */
#define  ADC_SQR2_SQ9_1                      ((uint32_t)0x00000800)        /*!< 位 1 */
#define  ADC_SQR2_SQ9_2                      ((uint32_t)0x00001000)        /*!< 位 2 */
#define  ADC_SQR2_SQ9_3                      ((uint32_t)0x00002000)        /*!< 位 3 */
#define  ADC_SQR2_SQ9_4                      ((uint32_t)0x00004000)        /*!< 位 4 */

#define  ADC_SQR2_SQ10                       ((uint32_t)0x000F8000)        /*!< SQ10[4:0] 位（规则序列中的第 10 次转换） */
#define  ADC_SQR2_SQ10_0                     ((uint32_t)0x00008000)        /*!< 位 0 */
#define  ADC_SQR2_SQ10_1                     ((uint32_t)0x00010000)        /*!< 位 1 */
#define  ADC_SQR2_SQ10_2                     ((uint32_t)0x00020000)        /*!< 位 2 */
#define  ADC_SQR2_SQ10_3                     ((uint32_t)0x00040000)        /*!< 位 3 */
#define  ADC_SQR2_SQ10_4                     ((uint32_t)0x00080000)        /*!< 位 4 */

#define  ADC_SQR2_SQ11                       ((uint32_t)0x01F00000)        /*!< SQ11[4:0] 位（规则序列中的第 11 次转换） */
#define  ADC_SQR2_SQ11_0                     ((uint32_t)0x00100000)        /*!< 位 0 */
#define  ADC_SQR2_SQ11_1                     ((uint32_t)0x00200000)        /*!< 位 1 */
#define  ADC_SQR2_SQ11_2                     ((uint32_t)0x00400000)        /*!< 位 2 */
#define  ADC_SQR2_SQ11_3                     ((uint32_t)0x00800000)        /*!< 位 3 */
#define  ADC_SQR2_SQ11_4                     ((uint32_t)0x01000000)        /*!< 位 4 */

#define  ADC_SQR2_SQ12                       ((uint32_t)0x3E000000)        /*!< SQ12[4:0] 位（规则序列中的第 12 次转换） */
#define  ADC_SQR2_SQ12_0                     ((uint32_t)0x02000000)        /*!< 位 0 */
#define  ADC_SQR2_SQ12_1                     ((uint32_t)0x04000000)        /*!< 位 1 */
#define  ADC_SQR2_SQ12_2                     ((uint32_t)0x08000000)        /*!< 位 2 */
#define  ADC_SQR2_SQ12_3                     ((uint32_t)0x10000000)        /*!< 位 3 */
#define  ADC_SQR2_SQ12_4                     ((uint32_t)0x20000000)        /*!< 位 4 */

/******************* ADC_SQR3 寄存器的位定义 *****************/
#define  ADC_SQR3_SQ1                        ((uint32_t)0x0000001F)        /*!< SQ1[4:0] 位（规则序列中的第 1 次转换） */
#define  ADC_SQR3_SQ1_0                      ((uint32_t)0x00000001)        /*!< 位 0 */
#define  ADC_SQR3_SQ1_1                      ((uint32_t)0x00000002)        /*!< 位 1 */
#define  ADC_SQR3_SQ1_2                      ((uint32_t)0x00000004)        /*!< 位 2 */
#define  ADC_SQR3_SQ1_3                      ((uint32_t)0x00000008)        /*!< 位 3 */
#define  ADC_SQR3_SQ1_4                      ((uint32_t)0x00000010)        /*!< 位 4 */

#define  ADC_SQR3_SQ2                        ((uint32_t)0x000003E0)        /*!< SQ2[4:0] 位（规则序列中的第 2 次转换） */
#define  ADC_SQR3_SQ2_0                      ((uint32_t)0x00000020)        /*!< 位 0 */
#define  ADC_SQR3_SQ2_1                      ((uint32_t)0x00000040)        /*!< 位 1 */
#define  ADC_SQR3_SQ2_2                      ((uint32_t)0x00000080)        /*!< 位 2 */
#define  ADC_SQR3_SQ2_3                      ((uint32_t)0x00000100)        /*!< 位 3 */
#define  ADC_SQR3_SQ2_4                      ((uint32_t)0x00000200)        /*!< 位 4 */

#define  ADC_SQR3_SQ3                        ((uint32_t)0x00007C00)        /*!< SQ3[4:0] 位（规则序列中的第 3 次转换） */
#define  ADC_SQR3_SQ3_0                      ((uint32_t)0x00000400)        /*!< 位 0 */
#define  ADC_SQR3_SQ3_1                      ((uint32_t)0x00000800)        /*!< 位 1 */
#define  ADC_SQR3_SQ3_2                      ((uint32_t)0x00001000)        /*!< 位 2 */
#define  ADC_SQR3_SQ3_3                      ((uint32_t)0x00002000)        /*!< 位 3 */
#define  ADC_SQR3_SQ3_4                      ((uint32_t)0x00004000)        /*!< 位 4 */

#define  ADC_SQR3_SQ4                        ((uint32_t)0x000F8000)        /*!< SQ4[4:0] 位（规则序列中的第 4 次转换） */
#define  ADC_SQR3_SQ4_0                      ((uint32_t)0x00008000)        /*!< 位 0 */
#define  ADC_SQR3_SQ4_1                      ((uint32_t)0x00010000)        /*!< 位 1 */
#define  ADC_SQR3_SQ4_2                      ((uint32_t)0x00020000)        /*!< 位 2 */
#define  ADC_SQR3_SQ4_3                      ((uint32_t)0x00040000)        /*!< 位 3 */
#define  ADC_SQR3_SQ4_4                      ((uint32_t)0x00080000)        /*!< 位 4 */

#define  ADC_SQR3_SQ5                        ((uint32_t)0x01F00000)        /*!< SQ5[4:0] 位（规则序列中的第 5 次转换） */
#define  ADC_SQR3_SQ5_0                      ((uint32_t)0x00100000)        /*!< 位 0 */
#define  ADC_SQR3_SQ5_1                      ((uint32_t)0x00200000)        /*!< 位 1 */
#define  ADC_SQR3_SQ5_2                      ((uint32_t)0x00400000)        /*!< 位 2 */
#define  ADC_SQR3_SQ5_3                      ((uint32_t)0x00800000)        /*!< 位 3 */
#define  ADC_SQR3_SQ5_4                      ((uint32_t)0x01000000)        /*!< 位 4 */

#define  ADC_SQR3_SQ6                        ((uint32_t)0x3E000000)        /*!< SQ6[4:0] 位（规则序列中的第 6 次转换） */
#define  ADC_SQR3_SQ6_0                      ((uint32_t)0x02000000)        /*!< 位 0 */
#define  ADC_SQR3_SQ6_1                      ((uint32_t)0x04000000)        /*!< 位 1 */
#define  ADC_SQR3_SQ6_2                      ((uint32_t)0x08000000)        /*!< 位 2 */
#define  ADC_SQR3_SQ6_3                      ((uint32_t)0x10000000)        /*!< 位 3 */
#define  ADC_SQR3_SQ6_4                      ((uint32_t)0x20000000)        /*!< 位 4 */

/******************* ADC_JSQR 寄存器的位定义 *****************/
#define  ADC_JSQR_JSQ1                       ((uint32_t)0x0000001F)        /*!< JSQ1[4:0] 位（注入序列中的第 1 次转换） */  
#define  ADC_JSQR_JSQ1_0                     ((uint32_t)0x00000001)        /*!< 位 0 */
#define  ADC_JSQR_JSQ1_1                     ((uint32_t)0x00000002)        /*!< 位 1 */
#define  ADC_JSQR_JSQ1_2                     ((uint32_t)0x00000004)        /*!< 位 2 */
#define  ADC_JSQR_JSQ1_3                     ((uint32_t)0x00000008)        /*!< 位 3 */
#define  ADC_JSQR_JSQ1_4                     ((uint32_t)0x00000010)        /*!< 位 4 */

#define  ADC_JSQR_JSQ2                       ((uint32_t)0x000003E0)        /*!< JSQ2[4:0] 位（注入序列中的第 2 次转换） */
#define  ADC_JSQR_JSQ2_0                     ((uint32_t)0x00000020)        /*!< 位 0 */
#define  ADC_JSQR_JSQ2_1                     ((uint32_t)0x00000040)        /*!< 位 1 */
#define  ADC_JSQR_JSQ2_2                     ((uint32_t)0x00000080)        /*!< 位 2 */
#define  ADC_JSQR_JSQ2_3                     ((uint32_t)0x00000100)        /*!< 位 3 */
#define  ADC_JSQR_JSQ2_4                     ((uint32_t)0x00000200)        /*!< 位 4 */

#define  ADC_JSQR_JSQ3                       ((uint32_t)0x00007C00)        /*!< JSQ3[4:0] 位（注入序列中的第 3 次转换） */
#define  ADC_JSQR_JSQ3_0                     ((uint32_t)0x00000400)        /*!< 位 0 */
#define  ADC_JSQR_JSQ3_1                     ((uint32_t)0x00000800)        /*!< 位 1 */
#define  ADC_JSQR_JSQ3_2                     ((uint32_t)0x00001000)        /*!< 位 2 */
#define  ADC_JSQR_JSQ3_3                     ((uint32_t)0x00002000)        /*!< 位 3 */
#define  ADC_JSQR_JSQ3_4                     ((uint32_t)0x00004000)        /*!< 位 4 */

#define  ADC_JSQR_JSQ4                       ((uint32_t)0x000F8000)        /*!< JSQ4[4:0] 位（注入序列中的第 4 次转换） */
#define  ADC_JSQR_JSQ4_0                     ((uint32_t)0x00008000)        /*!< 位 0 */
#define  ADC_JSQR_JSQ4_1                     ((uint32_t)0x00010000)        /*!< 位 1 */
#define  ADC_JSQR_JSQ4_2                     ((uint32_t)0x00020000)        /*!< 位 2 */
#define  ADC_JSQR_JSQ4_3                     ((uint32_t)0x00040000)        /*!< 位 3 */
#define  ADC_JSQR_JSQ4_4                     ((uint32_t)0x00080000)        /*!< 位 4 */

#define  ADC_JSQR_JL                         ((uint32_t)0x00300000)        /*!< JL[1:0] 位（注入序列长度） */
#define  ADC_JSQR_JL_0                       ((uint32_t)0x00100000)        /*!< 位 0 */
#define  ADC_JSQR_JL_1                       ((uint32_t)0x00200000)        /*!< 位 1 */

/******************* ADC_JDR1 寄存器的位定义 *****************/
#define  ADC_JDR1_JDATA                      ((uint16_t)0xFFFF)            /*!< 注入数据 */

/******************* ADC_JDR2 寄存器的位定义 *****************/
#define  ADC_JDR2_JDATA                      ((uint16_t)0xFFFF)            /*!< 注入数据 */

/******************* ADC_JDR3 寄存器的位定义 *****************/
#define  ADC_JDR3_JDATA                      ((uint16_t)0xFFFF)            /*!< 注入数据 */

/******************* ADC_JDR4 寄存器的位定义 *****************/
#define  ADC_JDR4_JDATA                      ((uint16_t)0xFFFF)            /*!< 注入数据 */

/******************** ADC_DR 寄存器的位定义 ******************/
#define  ADC_DR_DATA                         ((uint32_t)0x0000FFFF)        /*!< 规则数据 */
#define  ADC_DR_ADC2DATA                     ((uint32_t)0xFFFF0000)        /*!< ADC2 数据 */

/******************************************************************************/
/*                                                                            */
/*                      数模转换器                           */
/*                                                                            */
/******************************************************************************/

/******************** DAC_CR 寄存器的位定义 ******************/
#define  DAC_CR_EN1                          ((uint32_t)0x00000001)        /*!< DAC 通道 1 使能 */
#define  DAC_CR_BOFF1                        ((uint32_t)0x00000002)        /*!< DAC 通道 1 输出缓冲失能 */
#define  DAC_CR_TEN1                         ((uint32_t)0x00000004)        /*!< DAC 通道 1 触发使能 */

#define  DAC_CR_TSEL1                        ((uint32_t)0x00000038)        /*!< TSEL1[2:0]（DAC 通道 1 触发选择） */
#define  DAC_CR_TSEL1_0                      ((uint32_t)0x00000008)        /*!< 位 0 */
#define  DAC_CR_TSEL1_1                      ((uint32_t)0x00000010)        /*!< 位 1 */
#define  DAC_CR_TSEL1_2                      ((uint32_t)0x00000020)        /*!< 位 2 */

#define  DAC_CR_WAVE1                        ((uint32_t)0x000000C0)        /*!< WAVE1[1:0]（DAC 通道 1 噪声/三角波生成使能） */
#define  DAC_CR_WAVE1_0                      ((uint32_t)0x00000040)        /*!< 位 0 */
#define  DAC_CR_WAVE1_1                      ((uint32_t)0x00000080)        /*!< 位 1 */

#define  DAC_CR_MAMP1                        ((uint32_t)0x00000F00)        /*!< MAMP1[3:0]（DAC 通道 1 屏蔽/幅度选择器） */
#define  DAC_CR_MAMP1_0                      ((uint32_t)0x00000100)        /*!< 位 0 */
#define  DAC_CR_MAMP1_1                      ((uint32_t)0x00000200)        /*!< 位 1 */
#define  DAC_CR_MAMP1_2                      ((uint32_t)0x00000400)        /*!< 位 2 */
#define  DAC_CR_MAMP1_3                      ((uint32_t)0x00000800)        /*!< 位 3 */

#define  DAC_CR_DMAEN1                       ((uint32_t)0x00001000)        /*!< DAC 通道 1 DMA 使能 */
#define  DAC_CR_EN2                          ((uint32_t)0x00010000)        /*!< DAC 通道 2 使能 */
#define  DAC_CR_BOFF2                        ((uint32_t)0x00020000)        /*!< DAC 通道 2 输出缓冲失能 */
#define  DAC_CR_TEN2                         ((uint32_t)0x00040000)        /*!< DAC 通道 2 触发使能 */

#define  DAC_CR_TSEL2                        ((uint32_t)0x00380000)        /*!< TSEL2[2:0]（DAC 通道 2 触发选择） */
#define  DAC_CR_TSEL2_0                      ((uint32_t)0x00080000)        /*!< 位 0 */
#define  DAC_CR_TSEL2_1                      ((uint32_t)0x00100000)        /*!< 位 1 */
#define  DAC_CR_TSEL2_2                      ((uint32_t)0x00200000)        /*!< 位 2 */

#define  DAC_CR_WAVE2                        ((uint32_t)0x00C00000)        /*!< WAVE2[1:0]（DAC 通道 2 噪声/三角波生成使能） */
#define  DAC_CR_WAVE2_0                      ((uint32_t)0x00400000)        /*!< 位 0 */
#define  DAC_CR_WAVE2_1                      ((uint32_t)0x00800000)        /*!< 位 1 */

#define  DAC_CR_MAMP2                        ((uint32_t)0x0F000000)        /*!< MAMP2[3:0]（DAC 通道 2 屏蔽/幅度选择器） */
#define  DAC_CR_MAMP2_0                      ((uint32_t)0x01000000)        /*!< 位 0 */
#define  DAC_CR_MAMP2_1                      ((uint32_t)0x02000000)        /*!< 位 1 */
#define  DAC_CR_MAMP2_2                      ((uint32_t)0x04000000)        /*!< 位 2 */
#define  DAC_CR_MAMP2_3                      ((uint32_t)0x08000000)        /*!< 位 3 */

#define  DAC_CR_DMAEN2                       ((uint32_t)0x10000000)        /*!< DAC 通道 2 DMA 使能 */

/***************** DAC_SWTRIGR 寄存器的位定义 ***************/
#define  DAC_SWTRIGR_SWTRIG1                 ((uint8_t)0x01)               /*!< DAC 通道 1 软件触发 */
#define  DAC_SWTRIGR_SWTRIG2                 ((uint8_t)0x02)               /*!< DAC 通道 2 软件触发 */

/***************** DAC_DHR12R1 寄存器的位定义 ***************/
#define  DAC_DHR12R1_DACC1DHR                ((uint16_t)0x0FFF)            /*!< DAC 通道 1 12 位右对齐数据 */

/***************** DAC_DHR12L1 寄存器的位定义 ***************/
#define  DAC_DHR12L1_DACC1DHR                ((uint16_t)0xFFF0)            /*!< DAC 通道 1 12 位左对齐数据 */

/****************** DAC_DHR8R1 寄存器的位定义 ****************/
#define  DAC_DHR8R1_DACC1DHR                 ((uint8_t)0xFF)               /*!< DAC 通道 1 8 位右对齐数据 */

/***************** DAC_DHR12R2 寄存器的位定义 ***************/
#define  DAC_DHR12R2_DACC2DHR                ((uint16_t)0x0FFF)            /*!< DAC 通道 2 12 位右对齐数据 */

/***************** DAC_DHR12L2 寄存器的位定义 ***************/
#define  DAC_DHR12L2_DACC2DHR                ((uint16_t)0xFFF0)            /*!< DAC 通道 2 12 位左对齐数据 */

/****************** DAC_DHR8R2 寄存器的位定义 ****************/
#define  DAC_DHR8R2_DACC2DHR                 ((uint8_t)0xFF)               /*!< DAC 通道 2 8 位右对齐数据 */

/***************** DAC_DHR12RD 寄存器的位定义 ***************/
#define  DAC_DHR12RD_DACC1DHR                ((uint32_t)0x00000FFF)        /*!< DAC 通道 1 12 位右对齐数据 */
#define  DAC_DHR12RD_DACC2DHR                ((uint32_t)0x0FFF0000)        /*!< DAC 通道 2 12 位右对齐数据 */

/***************** DAC_DHR12LD 寄存器的位定义 ***************/
#define  DAC_DHR12LD_DACC1DHR                ((uint32_t)0x0000FFF0)        /*!< DAC 通道 1 12 位左对齐数据 */
#define  DAC_DHR12LD_DACC2DHR                ((uint32_t)0xFFF00000)        /*!< DAC 通道 2 12 位左对齐数据 */

/****************** DAC_DHR8RD 寄存器的位定义 ****************/
#define  DAC_DHR8RD_DACC1DHR                 ((uint16_t)0x00FF)            /*!< DAC 通道 1 8 位右对齐数据 */
#define  DAC_DHR8RD_DACC2DHR                 ((uint16_t)0xFF00)            /*!< DAC 通道 2 8 位右对齐数据 */

/******************* DAC_DOR1 寄存器的位定义 *****************/
#define  DAC_DOR1_DACC1DOR                   ((uint16_t)0x0FFF)            /*!< DAC 通道 1 数据输出 */

/******************* DAC_DOR2 寄存器的位定义 *****************/
#define  DAC_DOR2_DACC2DOR                   ((uint16_t)0x0FFF)            /*!< DAC 通道 2 数据输出 */

/******************** DAC_SR 寄存器的位定义 ******************/
#define  DAC_SR_DMAUDR1                      ((uint32_t)0x00002000)        /*!< DAC 通道 1 DMA 下溢标志位 */
#define  DAC_SR_DMAUDR2                      ((uint32_t)0x20000000)        /*!< DAC 通道 2 DMA 下溢标志位 */

/******************************************************************************/
/*                                                                            */
/*                                    CEC                                     */
/*                                                                            */
/******************************************************************************/
/******************** CEC_CFGR 寄存器的位定义 ******************/
#define  CEC_CFGR_PE              ((uint16_t)0x0001)     /*!<  外设使能 */
#define  CEC_CFGR_IE              ((uint16_t)0x0002)     /*!<  中断使能 */
#define  CEC_CFGR_BTEM            ((uint16_t)0x0004)     /*!<  位时序错误模式 */
#define  CEC_CFGR_BPEM            ((uint16_t)0x0008)     /*!<  位周期错误模式 */

/******************** CEC_OAR 寄存器的位定义 ******************/
#define  CEC_OAR_OA               ((uint16_t)0x000F)     /*!<  OA[3:0]：自身地址 */
#define  CEC_OAR_OA_0             ((uint16_t)0x0001)     /*!<  位 0 */
#define  CEC_OAR_OA_1             ((uint16_t)0x0002)     /*!<  位 1 */
#define  CEC_OAR_OA_2             ((uint16_t)0x0004)     /*!<  位 2 */
#define  CEC_OAR_OA_3             ((uint16_t)0x0008)     /*!<  位 3 */

/******************** CEC_PRES 寄存器的位定义 ******************/
#define  CEC_PRES_PRES            ((uint16_t)0x3FFF)   /*!<  预分频计数器值 */

/******************** CEC_ESR 寄存器的位定义 ******************/
#define  CEC_ESR_BTE              ((uint16_t)0x0001)     /*!<  位时序错误 */
#define  CEC_ESR_BPE              ((uint16_t)0x0002)     /*!<  位周期错误 */
#define  CEC_ESR_RBTFE            ((uint16_t)0x0004)     /*!<  接收块传输完成错误 */
#define  CEC_ESR_SBE              ((uint16_t)0x0008)     /*!<  起始位错误 */
#define  CEC_ESR_ACKE             ((uint16_t)0x0010)     /*!<  块应答错误 */
#define  CEC_ESR_LINE             ((uint16_t)0x0020)     /*!<  线路错误 */
#define  CEC_ESR_TBTFE            ((uint16_t)0x0040)     /*!<  发送块传输完成错误 */

/******************** CEC_CSR 寄存器的位定义 ******************/
#define  CEC_CSR_TSOM             ((uint16_t)0x0001)     /*!<  发送消息起始 */
#define  CEC_CSR_TEOM             ((uint16_t)0x0002)     /*!<  发送消息结束 */
#define  CEC_CSR_TERR             ((uint16_t)0x0004)     /*!<  发送错误 */
#define  CEC_CSR_TBTRF            ((uint16_t)0x0008)     /*!<  发送字节传输请求或块传输完成 */
#define  CEC_CSR_RSOM             ((uint16_t)0x0010)     /*!<  接收消息起始 */
#define  CEC_CSR_REOM             ((uint16_t)0x0020)     /*!<  接收消息结束 */
#define  CEC_CSR_RERR             ((uint16_t)0x0040)     /*!<  接收错误 */
#define  CEC_CSR_RBTF             ((uint16_t)0x0080)     /*!<  接收块传输完成 */

/******************** CEC_TXD 寄存器的位定义 ******************/
#define  CEC_TXD_TXD              ((uint16_t)0x00FF)     /*!<  发送数据寄存器 */

/******************** CEC_RXD 寄存器的位定义 ******************/
#define  CEC_RXD_RXD              ((uint16_t)0x00FF)     /*!<  接收数据寄存器 */

/******************************************************************************/
/*                                                                            */
/*                                    TIM                                     */
/*                                                                            */
/******************************************************************************/

/******************* TIM_CR1 寄存器的位定义 *****************/
#define  TIM_CR1_CEN                         ((uint16_t)0x0001)            /*!< 计数器使能 */
#define  TIM_CR1_UDIS                        ((uint16_t)0x0002)            /*!< 更新禁止 */
#define  TIM_CR1_URS                         ((uint16_t)0x0004)            /*!< 更新请求源 */
#define  TIM_CR1_OPM                         ((uint16_t)0x0008)            /*!< 单脉冲模式 */
#define  TIM_CR1_DIR                         ((uint16_t)0x0010)            /*!< 计数方向 */

#define  TIM_CR1_CMS                         ((uint16_t)0x0060)            /*!< CMS[1:0] 位（中央对齐模式选择） */
#define  TIM_CR1_CMS_0                       ((uint16_t)0x0020)            /*!< 位 0 */
#define  TIM_CR1_CMS_1                       ((uint16_t)0x0040)            /*!< 位 1 */

#define  TIM_CR1_ARPE                        ((uint16_t)0x0080)            /*!< 自动重装载预装载使能 */

#define  TIM_CR1_CKD                         ((uint16_t)0x0300)            /*!< CKD[1:0] 位（时钟分频） */
#define  TIM_CR1_CKD_0                       ((uint16_t)0x0100)            /*!< 位 0 */
#define  TIM_CR1_CKD_1                       ((uint16_t)0x0200)            /*!< 位 1 */

/******************* TIM_CR2 寄存器的位定义 *****************/
#define  TIM_CR2_CCPC                        ((uint16_t)0x0001)            /*!< 捕获/比较预装载控制 */
#define  TIM_CR2_CCUS                        ((uint16_t)0x0004)            /*!< 捕获/比较控制更新选择 */
#define  TIM_CR2_CCDS                        ((uint16_t)0x0008)            /*!< 捕获/比较 DMA 选择 */

#define  TIM_CR2_MMS                         ((uint16_t)0x0070)            /*!< MMS[2:0] 位（主模式选择） */
#define  TIM_CR2_MMS_0                       ((uint16_t)0x0010)            /*!< 位 0 */
#define  TIM_CR2_MMS_1                       ((uint16_t)0x0020)            /*!< 位 1 */
#define  TIM_CR2_MMS_2                       ((uint16_t)0x0040)            /*!< 位 2 */

#define  TIM_CR2_TI1S                        ((uint16_t)0x0080)            /*!< TI1 选择 */
#define  TIM_CR2_OIS1                        ((uint16_t)0x0100)            /*!< 输出空闲状态 1（OC1 输出） */
#define  TIM_CR2_OIS1N                       ((uint16_t)0x0200)            /*!< 输出空闲状态 1（OC1N 输出） */
#define  TIM_CR2_OIS2                        ((uint16_t)0x0400)            /*!< 输出空闲状态 2（OC2 输出） */
#define  TIM_CR2_OIS2N                       ((uint16_t)0x0800)            /*!< 输出空闲状态 2（OC2N 输出） */
#define  TIM_CR2_OIS3                        ((uint16_t)0x1000)            /*!< 输出空闲状态 3（OC3 输出） */
#define  TIM_CR2_OIS3N                       ((uint16_t)0x2000)            /*!< 输出空闲状态 3（OC3N 输出） */
#define  TIM_CR2_OIS4                        ((uint16_t)0x4000)            /*!< 输出空闲状态 4（OC4 输出） */

/******************* TIM_SMCR 寄存器的位定义 *****************/
#define  TIM_SMCR_SMS                        ((uint16_t)0x0007)            /*!< SMS[2:0] 位（从模式选择） */
#define  TIM_SMCR_SMS_0                      ((uint16_t)0x0001)            /*!< 位 0 */
#define  TIM_SMCR_SMS_1                      ((uint16_t)0x0002)            /*!< 位 1 */
#define  TIM_SMCR_SMS_2                      ((uint16_t)0x0004)            /*!< 位 2 */

#define  TIM_SMCR_TS                         ((uint16_t)0x0070)            /*!< TS[2:0] 位（触发选择） */
#define  TIM_SMCR_TS_0                       ((uint16_t)0x0010)            /*!< 位 0 */
#define  TIM_SMCR_TS_1                       ((uint16_t)0x0020)            /*!< 位 1 */
#define  TIM_SMCR_TS_2                       ((uint16_t)0x0040)            /*!< 位 2 */

#define  TIM_SMCR_MSM                        ((uint16_t)0x0080)            /*!< 主/从模式 */

#define  TIM_SMCR_ETF                        ((uint16_t)0x0F00)            /*!< ETF[3:0] 位（外部触发滤波） */
#define  TIM_SMCR_ETF_0                      ((uint16_t)0x0100)            /*!< 位 0 */
#define  TIM_SMCR_ETF_1                      ((uint16_t)0x0200)            /*!< 位 1 */
#define  TIM_SMCR_ETF_2                      ((uint16_t)0x0400)            /*!< 位 2 */
#define  TIM_SMCR_ETF_3                      ((uint16_t)0x0800)            /*!< 位 3 */

#define  TIM_SMCR_ETPS                       ((uint16_t)0x3000)            /*!< ETPS[1:0] 位（外部触发预分频） */
#define  TIM_SMCR_ETPS_0                     ((uint16_t)0x1000)            /*!< 位 0 */
#define  TIM_SMCR_ETPS_1                     ((uint16_t)0x2000)            /*!< 位 1 */

#define  TIM_SMCR_ECE                        ((uint16_t)0x4000)            /*!< 外部时钟使能 */
#define  TIM_SMCR_ETP                        ((uint16_t)0x8000)            /*!< 外部触发极性 */

/******************* TIM_DIER 寄存器的位定义 *****************/
#define  TIM_DIER_UIE                        ((uint16_t)0x0001)            /*!< 更新中断使能 */
#define  TIM_DIER_CC1IE                      ((uint16_t)0x0002)            /*!< 捕获/比较 1 中断使能 */
#define  TIM_DIER_CC2IE                      ((uint16_t)0x0004)            /*!< 捕获/比较 2 中断使能 */
#define  TIM_DIER_CC3IE                      ((uint16_t)0x0008)            /*!< 捕获/比较 3 中断使能 */
#define  TIM_DIER_CC4IE                      ((uint16_t)0x0010)            /*!< 捕获/比较 4 中断使能 */
#define  TIM_DIER_COMIE                      ((uint16_t)0x0020)            /*!< COM 中断使能 */
#define  TIM_DIER_TIE                        ((uint16_t)0x0040)            /*!< 触发中断使能 */
#define  TIM_DIER_BIE                        ((uint16_t)0x0080)            /*!< 刹车中断使能 */
#define  TIM_DIER_UDE                        ((uint16_t)0x0100)            /*!< 更新 DMA 请求使能 */
#define  TIM_DIER_CC1DE                      ((uint16_t)0x0200)            /*!< 捕获/比较 1 DMA 请求使能 */
#define  TIM_DIER_CC2DE                      ((uint16_t)0x0400)            /*!< 捕获/比较 2 DMA 请求使能 */
#define  TIM_DIER_CC3DE                      ((uint16_t)0x0800)            /*!< 捕获/比较 3 DMA 请求使能 */
#define  TIM_DIER_CC4DE                      ((uint16_t)0x1000)            /*!< 捕获/比较 4 DMA 请求使能 */
#define  TIM_DIER_COMDE                      ((uint16_t)0x2000)            /*!< COM DMA 请求使能 */
#define  TIM_DIER_TDE                        ((uint16_t)0x4000)            /*!< 触发 DMA 请求使能 */

/******************** TIM_SR 寄存器的位定义 ******************/
#define  TIM_SR_UIF                          ((uint16_t)0x0001)            /*!< 更新中断标志位 */
#define  TIM_SR_CC1IF                        ((uint16_t)0x0002)            /*!< 捕获/比较 1 中断标志位 */
#define  TIM_SR_CC2IF                        ((uint16_t)0x0004)            /*!< 捕获/比较 2 中断标志位 */
#define  TIM_SR_CC3IF                        ((uint16_t)0x0008)            /*!< 捕获/比较 3 中断标志位 */
#define  TIM_SR_CC4IF                        ((uint16_t)0x0010)            /*!< 捕获/比较 4 中断标志位 */
#define  TIM_SR_COMIF                        ((uint16_t)0x0020)            /*!< COM 中断标志位 */
#define  TIM_SR_TIF                          ((uint16_t)0x0040)            /*!< 触发中断标志位 */
#define  TIM_SR_BIF                          ((uint16_t)0x0080)            /*!< 刹车中断标志位 */
#define  TIM_SR_CC1OF                        ((uint16_t)0x0200)            /*!< 捕获/比较 1 重复捕获标志位 */
#define  TIM_SR_CC2OF                        ((uint16_t)0x0400)            /*!< 捕获/比较 2 重复捕获标志位 */
#define  TIM_SR_CC3OF                        ((uint16_t)0x0800)            /*!< 捕获/比较 3 重复捕获标志位 */
#define  TIM_SR_CC4OF                        ((uint16_t)0x1000)            /*!< 捕获/比较 4 重复捕获标志位 */

/******************* TIM_EGR 寄存器的位定义 *****************/
#define  TIM_EGR_UG                          ((uint8_t)0x01)               /*!< 更新事件产生 */
#define  TIM_EGR_CC1G                        ((uint8_t)0x02)               /*!< 捕获/比较 1 事件产生 */
#define  TIM_EGR_CC2G                        ((uint8_t)0x04)               /*!< 捕获/比较 2 事件产生 */
#define  TIM_EGR_CC3G                        ((uint8_t)0x08)               /*!< 捕获/比较 3 事件产生 */
#define  TIM_EGR_CC4G                        ((uint8_t)0x10)               /*!< 捕获/比较 4 事件产生 */
#define  TIM_EGR_COMG                        ((uint8_t)0x20)               /*!< 捕获/比较控制更新事件产生 */
#define  TIM_EGR_TG                          ((uint8_t)0x40)               /*!< 触发事件产生 */
#define  TIM_EGR_BG                          ((uint8_t)0x80)               /*!< 刹车事件产生 */

/****************** TIM_CCMR1 寄存器的位定义 ****************/
#define  TIM_CCMR1_CC1S                      ((uint16_t)0x0003)            /*!< CC1S[1:0] 位（捕获/比较 1 选择） */
#define  TIM_CCMR1_CC1S_0                    ((uint16_t)0x0001)            /*!< 位 0 */
#define  TIM_CCMR1_CC1S_1                    ((uint16_t)0x0002)            /*!< 位 1 */

#define  TIM_CCMR1_OC1FE                     ((uint16_t)0x0004)            /*!< 输出比较 1 快速使能 */
#define  TIM_CCMR1_OC1PE                     ((uint16_t)0x0008)            /*!< 输出比较 1 预装载使能 */

#define  TIM_CCMR1_OC1M                      ((uint16_t)0x0070)            /*!< OC1M[2:0] 位（输出比较 1 模式） */
#define  TIM_CCMR1_OC1M_0                    ((uint16_t)0x0010)            /*!< 位 0 */
#define  TIM_CCMR1_OC1M_1                    ((uint16_t)0x0020)            /*!< 位 1 */
#define  TIM_CCMR1_OC1M_2                    ((uint16_t)0x0040)            /*!< 位 2 */

#define  TIM_CCMR1_OC1CE                     ((uint16_t)0x0080)            /*!< 输出比较 1 清除使能 */

#define  TIM_CCMR1_CC2S                      ((uint16_t)0x0300)            /*!< CC2S[1:0] 位（捕获/比较 2 选择） */
#define  TIM_CCMR1_CC2S_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  TIM_CCMR1_CC2S_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  TIM_CCMR1_OC2FE                     ((uint16_t)0x0400)            /*!< 输出比较 2 快速使能 */
#define  TIM_CCMR1_OC2PE                     ((uint16_t)0x0800)            /*!< 输出比较 2 预装载使能 */

#define  TIM_CCMR1_OC2M                      ((uint16_t)0x7000)            /*!< OC2M[2:0] 位（输出比较 2 模式） */
#define  TIM_CCMR1_OC2M_0                    ((uint16_t)0x1000)            /*!< 位 0 */
#define  TIM_CCMR1_OC2M_1                    ((uint16_t)0x2000)            /*!< 位 1 */
#define  TIM_CCMR1_OC2M_2                    ((uint16_t)0x4000)            /*!< 位 2 */

#define  TIM_CCMR1_OC2CE                     ((uint16_t)0x8000)            /*!< 输出比较 2 清除使能 */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR1_IC1PSC                    ((uint16_t)0x000C)            /*!< IC1PSC[1:0] 位（输入捕获 1 预分频） */
#define  TIM_CCMR1_IC1PSC_0                  ((uint16_t)0x0004)            /*!< 位 0 */
#define  TIM_CCMR1_IC1PSC_1                  ((uint16_t)0x0008)            /*!< 位 1 */

#define  TIM_CCMR1_IC1F                      ((uint16_t)0x00F0)            /*!< IC1F[3:0] 位（输入捕获 1 滤波） */
#define  TIM_CCMR1_IC1F_0                    ((uint16_t)0x0010)            /*!< 位 0 */
#define  TIM_CCMR1_IC1F_1                    ((uint16_t)0x0020)            /*!< 位 1 */
#define  TIM_CCMR1_IC1F_2                    ((uint16_t)0x0040)            /*!< 位 2 */
#define  TIM_CCMR1_IC1F_3                    ((uint16_t)0x0080)            /*!< 位 3 */

#define  TIM_CCMR1_IC2PSC                    ((uint16_t)0x0C00)            /*!< IC2PSC[1:0] 位（输入捕获 2 预分频） */
#define  TIM_CCMR1_IC2PSC_0                  ((uint16_t)0x0400)            /*!< 位 0 */
#define  TIM_CCMR1_IC2PSC_1                  ((uint16_t)0x0800)            /*!< 位 1 */

#define  TIM_CCMR1_IC2F                      ((uint16_t)0xF000)            /*!< IC2F[3:0] 位（输入捕获 2 滤波） */
#define  TIM_CCMR1_IC2F_0                    ((uint16_t)0x1000)            /*!< 位 0 */
#define  TIM_CCMR1_IC2F_1                    ((uint16_t)0x2000)            /*!< 位 1 */
#define  TIM_CCMR1_IC2F_2                    ((uint16_t)0x4000)            /*!< 位 2 */
#define  TIM_CCMR1_IC2F_3                    ((uint16_t)0x8000)            /*!< 位 3 */

/****************** TIM_CCMR2 寄存器的位定义 ****************/
#define  TIM_CCMR2_CC3S                      ((uint16_t)0x0003)            /*!< CC3S[1:0] 位（捕获/比较 3 选择） */
#define  TIM_CCMR2_CC3S_0                    ((uint16_t)0x0001)            /*!< 位 0 */
#define  TIM_CCMR2_CC3S_1                    ((uint16_t)0x0002)            /*!< 位 1 */

#define  TIM_CCMR2_OC3FE                     ((uint16_t)0x0004)            /*!< 输出比较 3 快速使能 */
#define  TIM_CCMR2_OC3PE                     ((uint16_t)0x0008)            /*!< 输出比较 3 预装载使能 */

#define  TIM_CCMR2_OC3M                      ((uint16_t)0x0070)            /*!< OC3M[2:0] 位（输出比较 3 模式） */
#define  TIM_CCMR2_OC3M_0                    ((uint16_t)0x0010)            /*!< 位 0 */
#define  TIM_CCMR2_OC3M_1                    ((uint16_t)0x0020)            /*!< 位 1 */
#define  TIM_CCMR2_OC3M_2                    ((uint16_t)0x0040)            /*!< 位 2 */

#define  TIM_CCMR2_OC3CE                     ((uint16_t)0x0080)            /*!< 输出比较 3 清除使能 */

#define  TIM_CCMR2_CC4S                      ((uint16_t)0x0300)            /*!< CC4S[1:0] 位（捕获/比较 4 选择） */
#define  TIM_CCMR2_CC4S_0                    ((uint16_t)0x0100)            /*!< 位 0 */
#define  TIM_CCMR2_CC4S_1                    ((uint16_t)0x0200)            /*!< 位 1 */

#define  TIM_CCMR2_OC4FE                     ((uint16_t)0x0400)            /*!< 输出比较 4 快速使能 */
#define  TIM_CCMR2_OC4PE                     ((uint16_t)0x0800)            /*!< 输出比较 4 预装载使能 */

#define  TIM_CCMR2_OC4M                      ((uint16_t)0x7000)            /*!< OC4M[2:0] 位（输出比较 4 模式） */
#define  TIM_CCMR2_OC4M_0                    ((uint16_t)0x1000)            /*!< 位 0 */
#define  TIM_CCMR2_OC4M_1                    ((uint16_t)0x2000)            /*!< 位 1 */
#define  TIM_CCMR2_OC4M_2                    ((uint16_t)0x4000)            /*!< 位 2 */

#define  TIM_CCMR2_OC4CE                     ((uint16_t)0x8000)            /*!< 输出比较 4 清除使能 */

/*----------------------------------------------------------------------------*/

#define  TIM_CCMR2_IC3PSC                    ((uint16_t)0x000C)            /*!< IC3PSC[1:0] 位（输入捕获 3 预分频） */
#define  TIM_CCMR2_IC3PSC_0                  ((uint16_t)0x0004)            /*!< 位 0 */
#define  TIM_CCMR2_IC3PSC_1                  ((uint16_t)0x0008)            /*!< 位 1 */

#define  TIM_CCMR2_IC3F                      ((uint16_t)0x00F0)            /*!< IC3F[3:0] 位（输入捕获 3 滤波） */
#define  TIM_CCMR2_IC3F_0                    ((uint16_t)0x0010)            /*!< 位 0 */
#define  TIM_CCMR2_IC3F_1                    ((uint16_t)0x0020)            /*!< 位 1 */
#define  TIM_CCMR2_IC3F_2                    ((uint16_t)0x0040)            /*!< 位 2 */
#define  TIM_CCMR2_IC3F_3                    ((uint16_t)0x0080)            /*!< 位 3 */

#define  TIM_CCMR2_IC4PSC                    ((uint16_t)0x0C00)            /*!< IC4PSC[1:0] 位（输入捕获 4 预分频） */
#define  TIM_CCMR2_IC4PSC_0                  ((uint16_t)0x0400)            /*!< 位 0 */
#define  TIM_CCMR2_IC4PSC_1                  ((uint16_t)0x0800)            /*!< 位 1 */

#define  TIM_CCMR2_IC4F                      ((uint16_t)0xF000)            /*!< IC4F[3:0] 位（输入捕获 4 滤波） */
#define  TIM_CCMR2_IC4F_0                    ((uint16_t)0x1000)            /*!< 位 0 */
#define  TIM_CCMR2_IC4F_1                    ((uint16_t)0x2000)            /*!< 位 1 */
#define  TIM_CCMR2_IC4F_2                    ((uint16_t)0x4000)            /*!< 位 2 */
#define  TIM_CCMR2_IC4F_3                    ((uint16_t)0x8000)            /*!< 位 3 */

/******************* TIM_CCER 寄存器的位定义 *****************/
#define  TIM_CCER_CC1E                       ((uint16_t)0x0001)            /*!< 捕获/比较 1 输出使能 */
#define  TIM_CCER_CC1P                       ((uint16_t)0x0002)            /*!< 捕获/比较 1 输出极性 */
#define  TIM_CCER_CC1NE                      ((uint16_t)0x0004)            /*!< 捕获/比较 1 互补输出使能 */
#define  TIM_CCER_CC1NP                      ((uint16_t)0x0008)            /*!< 捕获/比较 1 互补输出极性 */
#define  TIM_CCER_CC2E                       ((uint16_t)0x0010)            /*!< 捕获/比较 2 输出使能 */
#define  TIM_CCER_CC2P                       ((uint16_t)0x0020)            /*!< 捕获/比较 2 输出极性 */
#define  TIM_CCER_CC2NE                      ((uint16_t)0x0040)            /*!< 捕获/比较 2 互补输出使能 */
#define  TIM_CCER_CC2NP                      ((uint16_t)0x0080)            /*!< 捕获/比较 2 互补输出极性 */
#define  TIM_CCER_CC3E                       ((uint16_t)0x0100)            /*!< 捕获/比较 3 输出使能 */
#define  TIM_CCER_CC3P                       ((uint16_t)0x0200)            /*!< 捕获/比较 3 输出极性 */
#define  TIM_CCER_CC3NE                      ((uint16_t)0x0400)            /*!< 捕获/比较 3 互补输出使能 */
#define  TIM_CCER_CC3NP                      ((uint16_t)0x0800)            /*!< 捕获/比较 3 互补输出极性 */
#define  TIM_CCER_CC4E                       ((uint16_t)0x1000)            /*!< 捕获/比较 4 输出使能 */
#define  TIM_CCER_CC4P                       ((uint16_t)0x2000)            /*!< 捕获/比较 4 输出极性 */
#define  TIM_CCER_CC4NP                      ((uint16_t)0x8000)            /*!< 捕获/比较 4 互补输出极性 */

/******************* TIM_CNT 寄存器的位定义 *****************/
#define  TIM_CNT_CNT                         ((uint16_t)0xFFFF)            /*!< 计数值 */

/******************* TIM_PSC 寄存器的位定义 *****************/
#define  TIM_PSC_PSC                         ((uint16_t)0xFFFF)            /*!< 预分频值 */

/******************* TIM_ARR 寄存器的位定义 *****************/
#define  TIM_ARR_ARR                         ((uint16_t)0xFFFF)            /*!< 实际自动重装载值 */

/******************* TIM_RCR 寄存器的位定义 *****************/
#define  TIM_RCR_REP                         ((uint8_t)0xFF)               /*!< 重复计数值 */

/******************* TIM_CCR1 寄存器的位定义 *****************/
#define  TIM_CCR1_CCR1                       ((uint16_t)0xFFFF)            /*!< 捕获/比较 1 值 */

/******************* TIM_CCR2 寄存器的位定义 *****************/
#define  TIM_CCR2_CCR2                       ((uint16_t)0xFFFF)            /*!< 捕获/比较 2 值 */

/******************* TIM_CCR3 寄存器的位定义 *****************/
#define  TIM_CCR3_CCR3                       ((uint16_t)0xFFFF)            /*!< 捕获/比较 3 值 */

/******************* TIM_CCR4 寄存器的位定义 *****************/
#define  TIM_CCR4_CCR4                       ((uint16_t)0xFFFF)            /*!< 捕获/比较 4 值 */

/******************* TIM_BDTR 寄存器的位定义 *****************/
#define  TIM_BDTR_DTG                        ((uint16_t)0x00FF)            /*!< DTG[0:7] 位（死区时间发生器设置） */
#define  TIM_BDTR_DTG_0                      ((uint16_t)0x0001)            /*!< 位 0 */
#define  TIM_BDTR_DTG_1                      ((uint16_t)0x0002)            /*!< 位 1 */
#define  TIM_BDTR_DTG_2                      ((uint16_t)0x0004)            /*!< 位 2 */
#define  TIM_BDTR_DTG_3                      ((uint16_t)0x0008)            /*!< 位 3 */
#define  TIM_BDTR_DTG_4                      ((uint16_t)0x0010)            /*!< 位 4 */
#define  TIM_BDTR_DTG_5                      ((uint16_t)0x0020)            /*!< 位 5 */
#define  TIM_BDTR_DTG_6                      ((uint16_t)0x0040)            /*!< 位 6 */
#define  TIM_BDTR_DTG_7                      ((uint16_t)0x0080)            /*!< 位 7 */

#define  TIM_BDTR_LOCK                       ((uint16_t)0x0300)            /*!< LOCK[1:0] 位（锁定配置） */
#define  TIM_BDTR_LOCK_0                     ((uint16_t)0x0100)            /*!< 位 0 */
#define  TIM_BDTR_LOCK_1                     ((uint16_t)0x0200)            /*!< 位 1 */

#define  TIM_BDTR_OSSI                       ((uint16_t)0x0400)            /*!< 空闲模式的关闭状态选择 */
#define  TIM_BDTR_OSSR                       ((uint16_t)0x0800)            /*!< 运行模式的关闭状态选择 */
#define  TIM_BDTR_BKE                        ((uint16_t)0x1000)            /*!< 刹车使能 */
#define  TIM_BDTR_BKP                        ((uint16_t)0x2000)            /*!< 刹车极性 */
#define  TIM_BDTR_AOE                        ((uint16_t)0x4000)            /*!< 自动输出使能 */
#define  TIM_BDTR_MOE                        ((uint16_t)0x8000)            /*!< 主输出使能 */

/******************* TIM_DCR 寄存器的位定义 *****************/
#define  TIM_DCR_DBA                         ((uint16_t)0x001F)            /*!< DBA[4:0] 位（DMA 基地址） */
#define  TIM_DCR_DBA_0                       ((uint16_t)0x0001)            /*!< 位 0 */
#define  TIM_DCR_DBA_1                       ((uint16_t)0x0002)            /*!< 位 1 */
#define  TIM_DCR_DBA_2                       ((uint16_t)0x0004)            /*!< 位 2 */
#define  TIM_DCR_DBA_3                       ((uint16_t)0x0008)            /*!< 位 3 */
#define  TIM_DCR_DBA_4                       ((uint16_t)0x0010)            /*!< 位 4 */

#define  TIM_DCR_DBL                         ((uint16_t)0x1F00)            /*!< DBL[4:0] 位（DMA 突发长度） */
#define  TIM_DCR_DBL_0                       ((uint16_t)0x0100)            /*!< 位 0 */
#define  TIM_DCR_DBL_1                       ((uint16_t)0x0200)            /*!< 位 1 */
#define  TIM_DCR_DBL_2                       ((uint16_t)0x0400)            /*!< 位 2 */
#define  TIM_DCR_DBL_3                       ((uint16_t)0x0800)            /*!< 位 3 */
#define  TIM_DCR_DBL_4                       ((uint16_t)0x1000)            /*!< 位 4 */

/******************* TIM_DMAR 寄存器的位定义 *****************/
#define  TIM_DMAR_DMAB                       ((uint16_t)0xFFFF)            /*!< 用于突发访问的 DMA 寄存器 */

/******************************************************************************/
/*                                                                            */
/*                             实时时钟                                */
/*                                                                            */
/******************************************************************************/

/******************* RTC_CRH 寄存器的位定义 *****************/
#define  RTC_CRH_SECIE                       ((uint8_t)0x01)               /*!< 秒中断使能 */
#define  RTC_CRH_ALRIE                       ((uint8_t)0x02)               /*!< 闹钟中断使能 */
#define  RTC_CRH_OWIE                        ((uint8_t)0x04)               /*!< 溢出中断使能 */

/******************* RTC_CRL 寄存器的位定义 *****************/
#define  RTC_CRL_SECF                        ((uint8_t)0x01)               /*!< 秒标志位 */
#define  RTC_CRL_ALRF                        ((uint8_t)0x02)               /*!< 闹钟标志位 */
#define  RTC_CRL_OWF                         ((uint8_t)0x04)               /*!< 溢出标志位 */
#define  RTC_CRL_RSF                         ((uint8_t)0x08)               /*!< 寄存器同步标志位 */
#define  RTC_CRL_CNF                         ((uint8_t)0x10)               /*!< 配置标志位 */
#define  RTC_CRL_RTOFF                       ((uint8_t)0x20)               /*!< RTC 操作关闭 */

/******************* RTC_PRLH 寄存器的位定义 *****************/
#define  RTC_PRLH_PRL                        ((uint16_t)0x000F)            /*!< RTC 预分频重装载值高位 */

/******************* RTC_PRLL 寄存器的位定义 *****************/
#define  RTC_PRLL_PRL                        ((uint16_t)0xFFFF)            /*!< RTC 预分频重装载值低位 */

/******************* RTC_DIVH 寄存器的位定义 *****************/
#define  RTC_DIVH_RTC_DIV                    ((uint16_t)0x000F)            /*!< RTC 时钟分频高位 */

/******************* RTC_DIVL 寄存器的位定义 *****************/
#define  RTC_DIVL_RTC_DIV                    ((uint16_t)0xFFFF)            /*!< RTC 时钟分频低位 */

/******************* RTC_CNTH 寄存器的位定义 *****************/
#define  RTC_CNTH_RTC_CNT                    ((uint16_t)0xFFFF)            /*!< RTC 计数器高位 */

/******************* RTC_CNTL 寄存器的位定义 *****************/
#define  RTC_CNTL_RTC_CNT                    ((uint16_t)0xFFFF)            /*!< RTC 计数器低位 */

/******************* RTC_ALRH 寄存器的位定义 *****************/
#define  RTC_ALRH_RTC_ALR                    ((uint16_t)0xFFFF)            /*!< RTC 闹钟高位 */

/******************* RTC_ALRL 寄存器的位定义 *****************/
#define  RTC_ALRL_RTC_ALR                    ((uint16_t)0xFFFF)            /*!< RTC 闹钟低位 */

/******************************************************************************/
/*                                                                            */
/*                           独立看门狗                             */
/*                                                                            */
/******************************************************************************/

/******************* IWDG_KR 寄存器的位定义 *****************/
#define  IWDG_KR_KEY                         ((uint16_t)0xFFFF)            /*!< 键值（只写，读回 0000h） */

/******************* IWDG_PR 寄存器的位定义 *****************/
#define  IWDG_PR_PR                          ((uint8_t)0x07)               /*!< PR[2:0]（预分频系数） */
#define  IWDG_PR_PR_0                        ((uint8_t)0x01)               /*!< 位 0 */
#define  IWDG_PR_PR_1                        ((uint8_t)0x02)               /*!< 位 1 */
#define  IWDG_PR_PR_2                        ((uint8_t)0x04)               /*!< 位 2 */

/******************* IWDG_RLR 寄存器的位定义 *****************/
#define  IWDG_RLR_RL                         ((uint16_t)0x0FFF)            /*!< 看门狗计数器重装载值 */

/******************* IWDG_SR 寄存器的位定义 *****************/
#define  IWDG_SR_PVU                         ((uint8_t)0x01)               /*!< 看门狗预分频值更新 */
#define  IWDG_SR_RVU                         ((uint8_t)0x02)               /*!< 看门狗计数器重装载值更新 */

/******************************************************************************/
/*                                                                            */
/*                            窗口看门狗                                 */
/*                                                                            */
/******************************************************************************/

/******************* WWDG_CR 寄存器的位定义 *****************/
#define  WWDG_CR_T                           ((uint8_t)0x7F)               /*!< T[6:0] 位（7 位计数器（MSB 到 LSB）） */
#define  WWDG_CR_T0                          ((uint8_t)0x01)               /*!< 位 0 */
#define  WWDG_CR_T1                          ((uint8_t)0x02)               /*!< 位 1 */
#define  WWDG_CR_T2                          ((uint8_t)0x04)               /*!< 位 2 */
#define  WWDG_CR_T3                          ((uint8_t)0x08)               /*!< 位 3 */
#define  WWDG_CR_T4                          ((uint8_t)0x10)               /*!< 位 4 */
#define  WWDG_CR_T5                          ((uint8_t)0x20)               /*!< 位 5 */
#define  WWDG_CR_T6                          ((uint8_t)0x40)               /*!< 位 6 */

#define  WWDG_CR_WDGA                        ((uint8_t)0x80)               /*!< 激活位 */

/******************* WWDG_CFR 寄存器的位定义 *****************/
#define  WWDG_CFR_W                          ((uint16_t)0x007F)            /*!< W[6:0] 位（7 位窗口值） */
#define  WWDG_CFR_W0                         ((uint16_t)0x0001)            /*!< 位 0 */
#define  WWDG_CFR_W1                         ((uint16_t)0x0002)            /*!< 位 1 */
#define  WWDG_CFR_W2                         ((uint16_t)0x0004)            /*!< 位 2 */
#define  WWDG_CFR_W3                         ((uint16_t)0x0008)            /*!< 位 3 */
#define  WWDG_CFR_W4                         ((uint16_t)0x0010)            /*!< 位 4 */
#define  WWDG_CFR_W5                         ((uint16_t)0x0020)            /*!< 位 5 */
#define  WWDG_CFR_W6                         ((uint16_t)0x0040)            /*!< 位 6 */

#define  WWDG_CFR_WDGTB                      ((uint16_t)0x0180)            /*!< WDGTB[1:0] 位（定时器时基） */
#define  WWDG_CFR_WDGTB0                     ((uint16_t)0x0080)            /*!< 位 0 */
#define  WWDG_CFR_WDGTB1                     ((uint16_t)0x0100)            /*!< 位 1 */

#define  WWDG_CFR_EWI                        ((uint16_t)0x0200)            /*!< 提前唤醒中断 */

/******************* WWDG_SR 寄存器的位定义 *****************/
#define  WWDG_SR_EWIF                        ((uint8_t)0x01)               /*!< 提前唤醒中断标志位 */

/******************************************************************************/
/*                                                                            */
/*                       灵活的静态存储器控制器                    */
/*                                                                            */
/******************************************************************************/

/****************** FSMC_BCR1 寄存器的位定义 ****************/
#define  FSMC_BCR1_MBKEN                     ((uint32_t)0x00000001)        /*!< 存储块使能位 */
#define  FSMC_BCR1_MUXEN                     ((uint32_t)0x00000002)        /*!< 地址/数据复用使能位 */

#define  FSMC_BCR1_MTYP                      ((uint32_t)0x0000000C)        /*!< MTYP[1:0] 位（存储器类型） */
#define  FSMC_BCR1_MTYP_0                    ((uint32_t)0x00000004)        /*!< 位 0 */
#define  FSMC_BCR1_MTYP_1                    ((uint32_t)0x00000008)        /*!< 位 1 */

#define  FSMC_BCR1_MWID                      ((uint32_t)0x00000030)        /*!< MWID[1:0] 位（存储器数据总线宽度） */
#define  FSMC_BCR1_MWID_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BCR1_MWID_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  FSMC_BCR1_FACCEN                    ((uint32_t)0x00000040)        /*!< 闪存访问使能 */
#define  FSMC_BCR1_BURSTEN                   ((uint32_t)0x00000100)        /*!< 突发使能位 */
#define  FSMC_BCR1_WAITPOL                   ((uint32_t)0x00000200)        /*!< 等待信号极性位 */
#define  FSMC_BCR1_WRAPMOD                   ((uint32_t)0x00000400)        /*!< 回卷突发模式支持 */
#define  FSMC_BCR1_WAITCFG                   ((uint32_t)0x00000800)        /*!< 等待时序配置 */
#define  FSMC_BCR1_WREN                      ((uint32_t)0x00001000)        /*!< 写使能位 */
#define  FSMC_BCR1_WAITEN                    ((uint32_t)0x00002000)        /*!< 等待使能位 */
#define  FSMC_BCR1_EXTMOD                    ((uint32_t)0x00004000)        /*!< 扩展模式使能 */
#define  FSMC_BCR1_ASYNCWAIT                 ((uint32_t)0x00008000)       /*!< 异步等待 */
#define  FSMC_BCR1_CBURSTRW                  ((uint32_t)0x00080000)        /*!< 写突发使能 */

/****************** FSMC_BCR2 寄存器的位定义 ****************/
#define  FSMC_BCR2_MBKEN                     ((uint32_t)0x00000001)        /*!< 存储块使能位 */
#define  FSMC_BCR2_MUXEN                     ((uint32_t)0x00000002)        /*!< 地址/数据复用使能位 */

#define  FSMC_BCR2_MTYP                      ((uint32_t)0x0000000C)        /*!< MTYP[1:0] 位（存储器类型） */
#define  FSMC_BCR2_MTYP_0                    ((uint32_t)0x00000004)        /*!< 位 0 */
#define  FSMC_BCR2_MTYP_1                    ((uint32_t)0x00000008)        /*!< 位 1 */

#define  FSMC_BCR2_MWID                      ((uint32_t)0x00000030)        /*!< MWID[1:0] 位（存储器数据总线宽度） */
#define  FSMC_BCR2_MWID_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BCR2_MWID_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  FSMC_BCR2_FACCEN                    ((uint32_t)0x00000040)        /*!< 闪存访问使能 */
#define  FSMC_BCR2_BURSTEN                   ((uint32_t)0x00000100)        /*!< 突发使能位 */
#define  FSMC_BCR2_WAITPOL                   ((uint32_t)0x00000200)        /*!< 等待信号极性位 */
#define  FSMC_BCR2_WRAPMOD                   ((uint32_t)0x00000400)        /*!< 回卷突发模式支持 */
#define  FSMC_BCR2_WAITCFG                   ((uint32_t)0x00000800)        /*!< 等待时序配置 */
#define  FSMC_BCR2_WREN                      ((uint32_t)0x00001000)        /*!< 写使能位 */
#define  FSMC_BCR2_WAITEN                    ((uint32_t)0x00002000)        /*!< 等待使能位 */
#define  FSMC_BCR2_EXTMOD                    ((uint32_t)0x00004000)        /*!< 扩展模式使能 */
#define  FSMC_BCR2_ASYNCWAIT                 ((uint32_t)0x00008000)       /*!< 异步等待 */
#define  FSMC_BCR2_CBURSTRW                  ((uint32_t)0x00080000)        /*!< 写突发使能 */

/****************** FSMC_BCR3 寄存器的位定义 ****************/
#define  FSMC_BCR3_MBKEN                     ((uint32_t)0x00000001)        /*!< 存储块使能位 */
#define  FSMC_BCR3_MUXEN                     ((uint32_t)0x00000002)        /*!< 地址/数据复用使能位 */

#define  FSMC_BCR3_MTYP                      ((uint32_t)0x0000000C)        /*!< MTYP[1:0] 位（存储器类型） */
#define  FSMC_BCR3_MTYP_0                    ((uint32_t)0x00000004)        /*!< 位 0 */
#define  FSMC_BCR3_MTYP_1                    ((uint32_t)0x00000008)        /*!< 位 1 */

#define  FSMC_BCR3_MWID                      ((uint32_t)0x00000030)        /*!< MWID[1:0] 位（存储器数据总线宽度） */
#define  FSMC_BCR3_MWID_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BCR3_MWID_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  FSMC_BCR3_FACCEN                    ((uint32_t)0x00000040)        /*!< 闪存访问使能 */
#define  FSMC_BCR3_BURSTEN                   ((uint32_t)0x00000100)        /*!< 突发使能位 */
#define  FSMC_BCR3_WAITPOL                   ((uint32_t)0x00000200)        /*!< 等待信号极性位。 */
#define  FSMC_BCR3_WRAPMOD                   ((uint32_t)0x00000400)        /*!< 回卷突发模式支持 */
#define  FSMC_BCR3_WAITCFG                   ((uint32_t)0x00000800)        /*!< 等待时序配置 */
#define  FSMC_BCR3_WREN                      ((uint32_t)0x00001000)        /*!< 写使能位 */
#define  FSMC_BCR3_WAITEN                    ((uint32_t)0x00002000)        /*!< 等待使能位 */
#define  FSMC_BCR3_EXTMOD                    ((uint32_t)0x00004000)        /*!< 扩展模式使能 */
#define  FSMC_BCR3_ASYNCWAIT                 ((uint32_t)0x00008000)       /*!< 异步等待 */
#define  FSMC_BCR3_CBURSTRW                  ((uint32_t)0x00080000)        /*!< 写突发使能 */

/****************** FSMC_BCR4 寄存器的位定义 ****************/
#define  FSMC_BCR4_MBKEN                     ((uint32_t)0x00000001)        /*!< 存储块使能位 */
#define  FSMC_BCR4_MUXEN                     ((uint32_t)0x00000002)        /*!< 地址/数据复用使能位 */

#define  FSMC_BCR4_MTYP                      ((uint32_t)0x0000000C)        /*!< MTYP[1:0] 位（存储器类型） */
#define  FSMC_BCR4_MTYP_0                    ((uint32_t)0x00000004)        /*!< 位 0 */
#define  FSMC_BCR4_MTYP_1                    ((uint32_t)0x00000008)        /*!< 位 1 */

#define  FSMC_BCR4_MWID                      ((uint32_t)0x00000030)        /*!< MWID[1:0] 位（存储器数据总线宽度） */
#define  FSMC_BCR4_MWID_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BCR4_MWID_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  FSMC_BCR4_FACCEN                    ((uint32_t)0x00000040)        /*!< 闪存访问使能 */
#define  FSMC_BCR4_BURSTEN                   ((uint32_t)0x00000100)        /*!< 突发使能位 */
#define  FSMC_BCR4_WAITPOL                   ((uint32_t)0x00000200)        /*!< 等待信号极性位 */
#define  FSMC_BCR4_WRAPMOD                   ((uint32_t)0x00000400)        /*!< 回卷突发模式支持 */
#define  FSMC_BCR4_WAITCFG                   ((uint32_t)0x00000800)        /*!< 等待时序配置 */
#define  FSMC_BCR4_WREN                      ((uint32_t)0x00001000)        /*!< 写使能位 */
#define  FSMC_BCR4_WAITEN                    ((uint32_t)0x00002000)        /*!< 等待使能位 */
#define  FSMC_BCR4_EXTMOD                    ((uint32_t)0x00004000)        /*!< 扩展模式使能 */
#define  FSMC_BCR4_ASYNCWAIT                 ((uint32_t)0x00008000)       /*!< 异步等待 */
#define  FSMC_BCR4_CBURSTRW                  ((uint32_t)0x00080000)        /*!< 写突发使能 */

/****************** FSMC_BTR1 寄存器的位定义 ****************/
#define  FSMC_BTR1_ADDSET                    ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] 位（地址建立阶段持续时间） */
#define  FSMC_BTR1_ADDSET_0                  ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_BTR1_ADDSET_1                  ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_BTR1_ADDSET_2                  ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_BTR1_ADDSET_3                  ((uint32_t)0x00000008)        /*!< 位 3 */

#define  FSMC_BTR1_ADDHLD                    ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] 位（地址保持阶段持续时间） */
#define  FSMC_BTR1_ADDHLD_0                  ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BTR1_ADDHLD_1                  ((uint32_t)0x00000020)        /*!< 位 1 */
#define  FSMC_BTR1_ADDHLD_2                  ((uint32_t)0x00000040)        /*!< 位 2 */
#define  FSMC_BTR1_ADDHLD_3                  ((uint32_t)0x00000080)        /*!< 位 3 */

#define  FSMC_BTR1_DATAST                    ((uint32_t)0x0000FF00)        /*!< DATAST[3:0] 位（数据阶段持续时间） */
#define  FSMC_BTR1_DATAST_0                  ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_BTR1_DATAST_1                  ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_BTR1_DATAST_2                  ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_BTR1_DATAST_3                  ((uint32_t)0x00000800)        /*!< 位 3 */

#define  FSMC_BTR1_BUSTURN                   ((uint32_t)0x000F0000)        /*!< BUSTURN[3:0] 位（总线周转阶段持续时间） */
#define  FSMC_BTR1_BUSTURN_0                 ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_BTR1_BUSTURN_1                 ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_BTR1_BUSTURN_2                 ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_BTR1_BUSTURN_3                 ((uint32_t)0x00080000)        /*!< 位 3 */

#define  FSMC_BTR1_CLKDIV                    ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] 位（时钟分频比） */
#define  FSMC_BTR1_CLKDIV_0                  ((uint32_t)0x00100000)        /*!< 位 0 */
#define  FSMC_BTR1_CLKDIV_1                  ((uint32_t)0x00200000)        /*!< 位 1 */
#define  FSMC_BTR1_CLKDIV_2                  ((uint32_t)0x00400000)        /*!< 位 2 */
#define  FSMC_BTR1_CLKDIV_3                  ((uint32_t)0x00800000)        /*!< 位 3 */

#define  FSMC_BTR1_DATLAT                    ((uint32_t)0x0F000000)        /*!< DATLA[3:0] 位（数据延迟） */
#define  FSMC_BTR1_DATLAT_0                  ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_BTR1_DATLAT_1                  ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_BTR1_DATLAT_2                  ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_BTR1_DATLAT_3                  ((uint32_t)0x08000000)        /*!< 位 3 */

#define  FSMC_BTR1_ACCMOD                    ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] 位（访问模式） */
#define  FSMC_BTR1_ACCMOD_0                  ((uint32_t)0x10000000)        /*!< 位 0 */
#define  FSMC_BTR1_ACCMOD_1                  ((uint32_t)0x20000000)        /*!< 位 1 */

/****************** FSMC_BTR2 寄存器的位定义 ****************/
#define  FSMC_BTR2_ADDSET                    ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] 位（地址建立阶段持续时间） */
#define  FSMC_BTR2_ADDSET_0                  ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_BTR2_ADDSET_1                  ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_BTR2_ADDSET_2                  ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_BTR2_ADDSET_3                  ((uint32_t)0x00000008)        /*!< 位 3 */

#define  FSMC_BTR2_ADDHLD                    ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] 位（地址保持阶段持续时间） */
#define  FSMC_BTR2_ADDHLD_0                  ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BTR2_ADDHLD_1                  ((uint32_t)0x00000020)        /*!< 位 1 */
#define  FSMC_BTR2_ADDHLD_2                  ((uint32_t)0x00000040)        /*!< 位 2 */
#define  FSMC_BTR2_ADDHLD_3                  ((uint32_t)0x00000080)        /*!< 位 3 */

#define  FSMC_BTR2_DATAST                    ((uint32_t)0x0000FF00)        /*!< DATAST[3:0] 位（数据阶段持续时间） */
#define  FSMC_BTR2_DATAST_0                  ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_BTR2_DATAST_1                  ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_BTR2_DATAST_2                  ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_BTR2_DATAST_3                  ((uint32_t)0x00000800)        /*!< 位 3 */

#define  FSMC_BTR2_BUSTURN                   ((uint32_t)0x000F0000)        /*!< BUSTURN[3:0] 位（总线周转阶段持续时间） */
#define  FSMC_BTR2_BUSTURN_0                 ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_BTR2_BUSTURN_1                 ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_BTR2_BUSTURN_2                 ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_BTR2_BUSTURN_3                 ((uint32_t)0x00080000)        /*!< 位 3 */

#define  FSMC_BTR2_CLKDIV                    ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] 位（时钟分频比） */
#define  FSMC_BTR2_CLKDIV_0                  ((uint32_t)0x00100000)        /*!< 位 0 */
#define  FSMC_BTR2_CLKDIV_1                  ((uint32_t)0x00200000)        /*!< 位 1 */
#define  FSMC_BTR2_CLKDIV_2                  ((uint32_t)0x00400000)        /*!< 位 2 */
#define  FSMC_BTR2_CLKDIV_3                  ((uint32_t)0x00800000)        /*!< 位 3 */

#define  FSMC_BTR2_DATLAT                    ((uint32_t)0x0F000000)        /*!< DATLA[3:0] 位（数据延迟） */
#define  FSMC_BTR2_DATLAT_0                  ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_BTR2_DATLAT_1                  ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_BTR2_DATLAT_2                  ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_BTR2_DATLAT_3                  ((uint32_t)0x08000000)        /*!< 位 3 */

#define  FSMC_BTR2_ACCMOD                    ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] 位（访问模式） */
#define  FSMC_BTR2_ACCMOD_0                  ((uint32_t)0x10000000)        /*!< 位 0 */
#define  FSMC_BTR2_ACCMOD_1                  ((uint32_t)0x20000000)        /*!< 位 1 */

/******************* FSMC_BTR3 寄存器的位定义 *****************/
#define  FSMC_BTR3_ADDSET                    ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] 位（地址建立阶段持续时间） */
#define  FSMC_BTR3_ADDSET_0                  ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_BTR3_ADDSET_1                  ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_BTR3_ADDSET_2                  ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_BTR3_ADDSET_3                  ((uint32_t)0x00000008)        /*!< 位 3 */

#define  FSMC_BTR3_ADDHLD                    ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] 位（地址保持阶段持续时间） */
#define  FSMC_BTR3_ADDHLD_0                  ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BTR3_ADDHLD_1                  ((uint32_t)0x00000020)        /*!< 位 1 */
#define  FSMC_BTR3_ADDHLD_2                  ((uint32_t)0x00000040)        /*!< 位 2 */
#define  FSMC_BTR3_ADDHLD_3                  ((uint32_t)0x00000080)        /*!< 位 3 */

#define  FSMC_BTR3_DATAST                    ((uint32_t)0x0000FF00)        /*!< DATAST[3:0] 位（数据阶段持续时间） */
#define  FSMC_BTR3_DATAST_0                  ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_BTR3_DATAST_1                  ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_BTR3_DATAST_2                  ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_BTR3_DATAST_3                  ((uint32_t)0x00000800)        /*!< 位 3 */

#define  FSMC_BTR3_BUSTURN                   ((uint32_t)0x000F0000)        /*!< BUSTURN[3:0] 位（总线周转阶段持续时间） */
#define  FSMC_BTR3_BUSTURN_0                 ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_BTR3_BUSTURN_1                 ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_BTR3_BUSTURN_2                 ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_BTR3_BUSTURN_3                 ((uint32_t)0x00080000)        /*!< 位 3 */

#define  FSMC_BTR3_CLKDIV                    ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] 位（时钟分频比） */
#define  FSMC_BTR3_CLKDIV_0                  ((uint32_t)0x00100000)        /*!< 位 0 */
#define  FSMC_BTR3_CLKDIV_1                  ((uint32_t)0x00200000)        /*!< 位 1 */
#define  FSMC_BTR3_CLKDIV_2                  ((uint32_t)0x00400000)        /*!< 位 2 */
#define  FSMC_BTR3_CLKDIV_3                  ((uint32_t)0x00800000)        /*!< 位 3 */

#define  FSMC_BTR3_DATLAT                    ((uint32_t)0x0F000000)        /*!< DATLA[3:0] 位（数据延迟） */
#define  FSMC_BTR3_DATLAT_0                  ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_BTR3_DATLAT_1                  ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_BTR3_DATLAT_2                  ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_BTR3_DATLAT_3                  ((uint32_t)0x08000000)        /*!< 位 3 */

#define  FSMC_BTR3_ACCMOD                    ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] 位（访问模式） */
#define  FSMC_BTR3_ACCMOD_0                  ((uint32_t)0x10000000)        /*!< 位 0 */
#define  FSMC_BTR3_ACCMOD_1                  ((uint32_t)0x20000000)        /*!< 位 1 */

/****************** FSMC_BTR4 寄存器的位定义 ****************/
#define  FSMC_BTR4_ADDSET                    ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] 位（地址建立阶段持续时间） */
#define  FSMC_BTR4_ADDSET_0                  ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_BTR4_ADDSET_1                  ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_BTR4_ADDSET_2                  ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_BTR4_ADDSET_3                  ((uint32_t)0x00000008)        /*!< 位 3 */

#define  FSMC_BTR4_ADDHLD                    ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] 位（地址保持阶段持续时间） */
#define  FSMC_BTR4_ADDHLD_0                  ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BTR4_ADDHLD_1                  ((uint32_t)0x00000020)        /*!< 位 1 */
#define  FSMC_BTR4_ADDHLD_2                  ((uint32_t)0x00000040)        /*!< 位 2 */
#define  FSMC_BTR4_ADDHLD_3                  ((uint32_t)0x00000080)        /*!< 位 3 */

#define  FSMC_BTR4_DATAST                    ((uint32_t)0x0000FF00)        /*!< DATAST[3:0] 位（数据阶段持续时间） */
#define  FSMC_BTR4_DATAST_0                  ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_BTR4_DATAST_1                  ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_BTR4_DATAST_2                  ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_BTR4_DATAST_3                  ((uint32_t)0x00000800)        /*!< 位 3 */

#define  FSMC_BTR4_BUSTURN                   ((uint32_t)0x000F0000)        /*!< BUSTURN[3:0] 位（总线周转阶段持续时间） */
#define  FSMC_BTR4_BUSTURN_0                 ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_BTR4_BUSTURN_1                 ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_BTR4_BUSTURN_2                 ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_BTR4_BUSTURN_3                 ((uint32_t)0x00080000)        /*!< 位 3 */

#define  FSMC_BTR4_CLKDIV                    ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] 位（时钟分频比） */
#define  FSMC_BTR4_CLKDIV_0                  ((uint32_t)0x00100000)        /*!< 位 0 */
#define  FSMC_BTR4_CLKDIV_1                  ((uint32_t)0x00200000)        /*!< 位 1 */
#define  FSMC_BTR4_CLKDIV_2                  ((uint32_t)0x00400000)        /*!< 位 2 */
#define  FSMC_BTR4_CLKDIV_3                  ((uint32_t)0x00800000)        /*!< 位 3 */

#define  FSMC_BTR4_DATLAT                    ((uint32_t)0x0F000000)        /*!< DATLA[3:0] 位（数据延迟） */
#define  FSMC_BTR4_DATLAT_0                  ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_BTR4_DATLAT_1                  ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_BTR4_DATLAT_2                  ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_BTR4_DATLAT_3                  ((uint32_t)0x08000000)        /*!< 位 3 */

#define  FSMC_BTR4_ACCMOD                    ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] 位（访问模式） */
#define  FSMC_BTR4_ACCMOD_0                  ((uint32_t)0x10000000)        /*!< 位 0 */
#define  FSMC_BTR4_ACCMOD_1                  ((uint32_t)0x20000000)        /*!< 位 1 */

/****************** FSMC_BWTR1 寄存器的位定义 ****************/
#define  FSMC_BWTR1_ADDSET                   ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] 位（地址建立阶段持续时间） */
#define  FSMC_BWTR1_ADDSET_0                 ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_BWTR1_ADDSET_1                 ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_BWTR1_ADDSET_2                 ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_BWTR1_ADDSET_3                 ((uint32_t)0x00000008)        /*!< 位 3 */

#define  FSMC_BWTR1_ADDHLD                   ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] 位（地址保持阶段持续时间） */
#define  FSMC_BWTR1_ADDHLD_0                 ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BWTR1_ADDHLD_1                 ((uint32_t)0x00000020)        /*!< 位 1 */
#define  FSMC_BWTR1_ADDHLD_2                 ((uint32_t)0x00000040)        /*!< 位 2 */
#define  FSMC_BWTR1_ADDHLD_3                 ((uint32_t)0x00000080)        /*!< 位 3 */

#define  FSMC_BWTR1_DATAST                   ((uint32_t)0x0000FF00)        /*!< DATAST[3:0] 位（数据阶段持续时间） */
#define  FSMC_BWTR1_DATAST_0                 ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_BWTR1_DATAST_1                 ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_BWTR1_DATAST_2                 ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_BWTR1_DATAST_3                 ((uint32_t)0x00000800)        /*!< 位 3 */

#define  FSMC_BWTR1_CLKDIV                   ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] 位（时钟分频比） */
#define  FSMC_BWTR1_CLKDIV_0                 ((uint32_t)0x00100000)        /*!< 位 0 */
#define  FSMC_BWTR1_CLKDIV_1                 ((uint32_t)0x00200000)        /*!< 位 1 */
#define  FSMC_BWTR1_CLKDIV_2                 ((uint32_t)0x00400000)        /*!< 位 2 */
#define  FSMC_BWTR1_CLKDIV_3                 ((uint32_t)0x00800000)        /*!< 位 3 */

#define  FSMC_BWTR1_DATLAT                   ((uint32_t)0x0F000000)        /*!< DATLA[3:0] 位（数据延迟） */
#define  FSMC_BWTR1_DATLAT_0                 ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_BWTR1_DATLAT_1                 ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_BWTR1_DATLAT_2                 ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_BWTR1_DATLAT_3                 ((uint32_t)0x08000000)        /*!< 位 3 */

#define  FSMC_BWTR1_ACCMOD                   ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] 位（访问模式） */
#define  FSMC_BWTR1_ACCMOD_0                 ((uint32_t)0x10000000)        /*!< 位 0 */
#define  FSMC_BWTR1_ACCMOD_1                 ((uint32_t)0x20000000)        /*!< 位 1 */

/****************** FSMC_BWTR2 寄存器的位定义 ****************/
#define  FSMC_BWTR2_ADDSET                   ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] 位（地址建立阶段持续时间） */
#define  FSMC_BWTR2_ADDSET_0                 ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_BWTR2_ADDSET_1                 ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_BWTR2_ADDSET_2                 ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_BWTR2_ADDSET_3                 ((uint32_t)0x00000008)        /*!< 位 3 */

#define  FSMC_BWTR2_ADDHLD                   ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] 位（地址保持阶段持续时间） */
#define  FSMC_BWTR2_ADDHLD_0                 ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BWTR2_ADDHLD_1                 ((uint32_t)0x00000020)        /*!< 位 1 */
#define  FSMC_BWTR2_ADDHLD_2                 ((uint32_t)0x00000040)        /*!< 位 2 */
#define  FSMC_BWTR2_ADDHLD_3                 ((uint32_t)0x00000080)        /*!< 位 3 */

#define  FSMC_BWTR2_DATAST                   ((uint32_t)0x0000FF00)        /*!< DATAST[3:0] 位（数据阶段持续时间） */
#define  FSMC_BWTR2_DATAST_0                 ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_BWTR2_DATAST_1                 ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_BWTR2_DATAST_2                 ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_BWTR2_DATAST_3                 ((uint32_t)0x00000800)        /*!< 位 3 */

#define  FSMC_BWTR2_CLKDIV                   ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] 位（时钟分频比） */
#define  FSMC_BWTR2_CLKDIV_0                 ((uint32_t)0x00100000)        /*!< 位 0 */
#define  FSMC_BWTR2_CLKDIV_1                 ((uint32_t)0x00200000)        /*!< 位 1*/
#define  FSMC_BWTR2_CLKDIV_2                 ((uint32_t)0x00400000)        /*!< 位 2 */
#define  FSMC_BWTR2_CLKDIV_3                 ((uint32_t)0x00800000)        /*!< 位 3 */

#define  FSMC_BWTR2_DATLAT                   ((uint32_t)0x0F000000)        /*!< DATLA[3:0] 位（数据延迟） */
#define  FSMC_BWTR2_DATLAT_0                 ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_BWTR2_DATLAT_1                 ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_BWTR2_DATLAT_2                 ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_BWTR2_DATLAT_3                 ((uint32_t)0x08000000)        /*!< 位 3 */

#define  FSMC_BWTR2_ACCMOD                   ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] 位（访问模式） */
#define  FSMC_BWTR2_ACCMOD_0                 ((uint32_t)0x10000000)        /*!< 位 0 */
#define  FSMC_BWTR2_ACCMOD_1                 ((uint32_t)0x20000000)        /*!< 位 1 */

/****************** FSMC_BWTR3 寄存器的位定义 ****************/
#define  FSMC_BWTR3_ADDSET                   ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] 位（地址建立阶段持续时间） */
#define  FSMC_BWTR3_ADDSET_0                 ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_BWTR3_ADDSET_1                 ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_BWTR3_ADDSET_2                 ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_BWTR3_ADDSET_3                 ((uint32_t)0x00000008)        /*!< 位 3 */

#define  FSMC_BWTR3_ADDHLD                   ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] 位（地址保持阶段持续时间） */
#define  FSMC_BWTR3_ADDHLD_0                 ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BWTR3_ADDHLD_1                 ((uint32_t)0x00000020)        /*!< 位 1 */
#define  FSMC_BWTR3_ADDHLD_2                 ((uint32_t)0x00000040)        /*!< 位 2 */
#define  FSMC_BWTR3_ADDHLD_3                 ((uint32_t)0x00000080)        /*!< 位 3 */

#define  FSMC_BWTR3_DATAST                   ((uint32_t)0x0000FF00)        /*!< DATAST[3:0] 位（数据阶段持续时间） */
#define  FSMC_BWTR3_DATAST_0                 ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_BWTR3_DATAST_1                 ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_BWTR3_DATAST_2                 ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_BWTR3_DATAST_3                 ((uint32_t)0x00000800)        /*!< 位 3 */

#define  FSMC_BWTR3_CLKDIV                   ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] 位（时钟分频比） */
#define  FSMC_BWTR3_CLKDIV_0                 ((uint32_t)0x00100000)        /*!< 位 0 */
#define  FSMC_BWTR3_CLKDIV_1                 ((uint32_t)0x00200000)        /*!< 位 1 */
#define  FSMC_BWTR3_CLKDIV_2                 ((uint32_t)0x00400000)        /*!< 位 2 */
#define  FSMC_BWTR3_CLKDIV_3                 ((uint32_t)0x00800000)        /*!< 位 3 */

#define  FSMC_BWTR3_DATLAT                   ((uint32_t)0x0F000000)        /*!< DATLA[3:0] 位（数据延迟） */
#define  FSMC_BWTR3_DATLAT_0                 ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_BWTR3_DATLAT_1                 ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_BWTR3_DATLAT_2                 ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_BWTR3_DATLAT_3                 ((uint32_t)0x08000000)        /*!< 位 3 */

#define  FSMC_BWTR3_ACCMOD                   ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] 位（访问模式） */
#define  FSMC_BWTR3_ACCMOD_0                 ((uint32_t)0x10000000)        /*!< 位 0 */
#define  FSMC_BWTR3_ACCMOD_1                 ((uint32_t)0x20000000)        /*!< 位 1 */

/****************** FSMC_BWTR4 寄存器的位定义 ****************/
#define  FSMC_BWTR4_ADDSET                   ((uint32_t)0x0000000F)        /*!< ADDSET[3:0] 位（地址建立阶段持续时间） */
#define  FSMC_BWTR4_ADDSET_0                 ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_BWTR4_ADDSET_1                 ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_BWTR4_ADDSET_2                 ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_BWTR4_ADDSET_3                 ((uint32_t)0x00000008)        /*!< 位 3 */

#define  FSMC_BWTR4_ADDHLD                   ((uint32_t)0x000000F0)        /*!< ADDHLD[3:0] 位（地址保持阶段持续时间） */
#define  FSMC_BWTR4_ADDHLD_0                 ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_BWTR4_ADDHLD_1                 ((uint32_t)0x00000020)        /*!< 位 1 */
#define  FSMC_BWTR4_ADDHLD_2                 ((uint32_t)0x00000040)        /*!< 位 2 */
#define  FSMC_BWTR4_ADDHLD_3                 ((uint32_t)0x00000080)        /*!< 位 3 */

#define  FSMC_BWTR4_DATAST                   ((uint32_t)0x0000FF00)        /*!< DATAST[3:0] 位（数据阶段持续时间） */
#define  FSMC_BWTR4_DATAST_0                 ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_BWTR4_DATAST_1                 ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_BWTR4_DATAST_2                 ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_BWTR4_DATAST_3                 ((uint32_t)0x00000800)        /*!< 位 3 */

#define  FSMC_BWTR4_CLKDIV                   ((uint32_t)0x00F00000)        /*!< CLKDIV[3:0] 位（时钟分频比） */
#define  FSMC_BWTR4_CLKDIV_0                 ((uint32_t)0x00100000)        /*!< 位 0 */
#define  FSMC_BWTR4_CLKDIV_1                 ((uint32_t)0x00200000)        /*!< 位 1 */
#define  FSMC_BWTR4_CLKDIV_2                 ((uint32_t)0x00400000)        /*!< 位 2 */
#define  FSMC_BWTR4_CLKDIV_3                 ((uint32_t)0x00800000)        /*!< 位 3 */

#define  FSMC_BWTR4_DATLAT                   ((uint32_t)0x0F000000)        /*!< DATLA[3:0] 位（数据延迟） */
#define  FSMC_BWTR4_DATLAT_0                 ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_BWTR4_DATLAT_1                 ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_BWTR4_DATLAT_2                 ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_BWTR4_DATLAT_3                 ((uint32_t)0x08000000)        /*!< 位 3 */

#define  FSMC_BWTR4_ACCMOD                   ((uint32_t)0x30000000)        /*!< ACCMOD[1:0] 位（访问模式） */
#define  FSMC_BWTR4_ACCMOD_0                 ((uint32_t)0x10000000)        /*!< 位 0 */
#define  FSMC_BWTR4_ACCMOD_1                 ((uint32_t)0x20000000)        /*!< 位 1 */

/****************** FSMC_PCR2 寄存器的位定义 ****************/
#define  FSMC_PCR2_PWAITEN                   ((uint32_t)0x00000002)        /*!< 等待功能使能位 */
#define  FSMC_PCR2_PBKEN                     ((uint32_t)0x00000004)        /*!< PC 卡/NAND 闪存存储块使能位 */
#define  FSMC_PCR2_PTYP                      ((uint32_t)0x00000008)        /*!< 存储器类型 */

#define  FSMC_PCR2_PWID                      ((uint32_t)0x00000030)        /*!< PWID[1:0] 位（NAND 闪存数据总线宽度） */
#define  FSMC_PCR2_PWID_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_PCR2_PWID_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  FSMC_PCR2_ECCEN                     ((uint32_t)0x00000040)        /*!< ECC 计算逻辑使能位 */

#define  FSMC_PCR2_TCLR                      ((uint32_t)0x00001E00)        /*!< TCLR[3:0] 位（CLE 到 RE 延迟） */
#define  FSMC_PCR2_TCLR_0                    ((uint32_t)0x00000200)        /*!< 位 0 */
#define  FSMC_PCR2_TCLR_1                    ((uint32_t)0x00000400)        /*!< 位 1 */
#define  FSMC_PCR2_TCLR_2                    ((uint32_t)0x00000800)        /*!< 位 2 */
#define  FSMC_PCR2_TCLR_3                    ((uint32_t)0x00001000)        /*!< 位 3 */

#define  FSMC_PCR2_TAR                       ((uint32_t)0x0001E000)        /*!< TAR[3:0] 位（ALE 到 RE 延迟） */
#define  FSMC_PCR2_TAR_0                     ((uint32_t)0x00002000)        /*!< 位 0 */
#define  FSMC_PCR2_TAR_1                     ((uint32_t)0x00004000)        /*!< 位 1 */
#define  FSMC_PCR2_TAR_2                     ((uint32_t)0x00008000)        /*!< 位 2 */
#define  FSMC_PCR2_TAR_3                     ((uint32_t)0x00010000)        /*!< 位 3 */

#define  FSMC_PCR2_ECCPS                     ((uint32_t)0x000E0000)        /*!< ECCPS[1:0] 位（ECC 页大小） */
#define  FSMC_PCR2_ECCPS_0                   ((uint32_t)0x00020000)        /*!< 位 0 */
#define  FSMC_PCR2_ECCPS_1                   ((uint32_t)0x00040000)        /*!< 位 1 */
#define  FSMC_PCR2_ECCPS_2                   ((uint32_t)0x00080000)        /*!< 位 2 */

/****************** FSMC_PCR3 寄存器的位定义 ****************/
#define  FSMC_PCR3_PWAITEN                   ((uint32_t)0x00000002)        /*!< 等待功能使能位 */
#define  FSMC_PCR3_PBKEN                     ((uint32_t)0x00000004)        /*!< PC 卡/NAND 闪存存储块使能位 */
#define  FSMC_PCR3_PTYP                      ((uint32_t)0x00000008)        /*!< 存储器类型 */

#define  FSMC_PCR3_PWID                      ((uint32_t)0x00000030)        /*!< PWID[1:0] 位（NAND 闪存数据总线宽度） */
#define  FSMC_PCR3_PWID_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_PCR3_PWID_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  FSMC_PCR3_ECCEN                     ((uint32_t)0x00000040)        /*!< ECC 计算逻辑使能位 */

#define  FSMC_PCR3_TCLR                      ((uint32_t)0x00001E00)        /*!< TCLR[3:0] 位（CLE 到 RE 延迟） */
#define  FSMC_PCR3_TCLR_0                    ((uint32_t)0x00000200)        /*!< 位 0 */
#define  FSMC_PCR3_TCLR_1                    ((uint32_t)0x00000400)        /*!< 位 1 */
#define  FSMC_PCR3_TCLR_2                    ((uint32_t)0x00000800)        /*!< 位 2 */
#define  FSMC_PCR3_TCLR_3                    ((uint32_t)0x00001000)        /*!< 位 3 */

#define  FSMC_PCR3_TAR                       ((uint32_t)0x0001E000)        /*!< TAR[3:0] 位（ALE 到 RE 延迟） */
#define  FSMC_PCR3_TAR_0                     ((uint32_t)0x00002000)        /*!< 位 0 */
#define  FSMC_PCR3_TAR_1                     ((uint32_t)0x00004000)        /*!< 位 1 */
#define  FSMC_PCR3_TAR_2                     ((uint32_t)0x00008000)        /*!< 位 2 */
#define  FSMC_PCR3_TAR_3                     ((uint32_t)0x00010000)        /*!< 位 3 */

#define  FSMC_PCR3_ECCPS                     ((uint32_t)0x000E0000)        /*!< ECCPS[2:0] 位（ECC 页大小） */
#define  FSMC_PCR3_ECCPS_0                   ((uint32_t)0x00020000)        /*!< 位 0 */
#define  FSMC_PCR3_ECCPS_1                   ((uint32_t)0x00040000)        /*!< 位 1 */
#define  FSMC_PCR3_ECCPS_2                   ((uint32_t)0x00080000)        /*!< 位 2 */

/****************** FSMC_PCR4 寄存器的位定义 ****************/
#define  FSMC_PCR4_PWAITEN                   ((uint32_t)0x00000002)        /*!< 等待功能使能位 */
#define  FSMC_PCR4_PBKEN                     ((uint32_t)0x00000004)        /*!< PC 卡/NAND 闪存存储块使能位 */
#define  FSMC_PCR4_PTYP                      ((uint32_t)0x00000008)        /*!< 存储器类型 */

#define  FSMC_PCR4_PWID                      ((uint32_t)0x00000030)        /*!< PWID[1:0] 位（NAND 闪存数据总线宽度） */
#define  FSMC_PCR4_PWID_0                    ((uint32_t)0x00000010)        /*!< 位 0 */
#define  FSMC_PCR4_PWID_1                    ((uint32_t)0x00000020)        /*!< 位 1 */

#define  FSMC_PCR4_ECCEN                     ((uint32_t)0x00000040)        /*!< ECC 计算逻辑使能位 */

#define  FSMC_PCR4_TCLR                      ((uint32_t)0x00001E00)        /*!< TCLR[3:0] 位（CLE 到 RE 延迟） */
#define  FSMC_PCR4_TCLR_0                    ((uint32_t)0x00000200)        /*!< 位 0 */
#define  FSMC_PCR4_TCLR_1                    ((uint32_t)0x00000400)        /*!< 位 1 */
#define  FSMC_PCR4_TCLR_2                    ((uint32_t)0x00000800)        /*!< 位 2 */
#define  FSMC_PCR4_TCLR_3                    ((uint32_t)0x00001000)        /*!< 位 3 */

#define  FSMC_PCR4_TAR                       ((uint32_t)0x0001E000)        /*!< TAR[3:0] 位（ALE 到 RE 延迟） */
#define  FSMC_PCR4_TAR_0                     ((uint32_t)0x00002000)        /*!< 位 0 */
#define  FSMC_PCR4_TAR_1                     ((uint32_t)0x00004000)        /*!< 位 1 */
#define  FSMC_PCR4_TAR_2                     ((uint32_t)0x00008000)        /*!< 位 2 */
#define  FSMC_PCR4_TAR_3                     ((uint32_t)0x00010000)        /*!< 位 3 */

#define  FSMC_PCR4_ECCPS                     ((uint32_t)0x000E0000)        /*!< ECCPS[2:0] 位（ECC 页大小） */
#define  FSMC_PCR4_ECCPS_0                   ((uint32_t)0x00020000)        /*!< 位 0 */
#define  FSMC_PCR4_ECCPS_1                   ((uint32_t)0x00040000)        /*!< 位 1 */
#define  FSMC_PCR4_ECCPS_2                   ((uint32_t)0x00080000)        /*!< 位 2 */

/******************* FSMC_SR2 寄存器的位定义 *****************/
#define  FSMC_SR2_IRS                        ((uint8_t)0x01)               /*!< 中断上升沿状态 */
#define  FSMC_SR2_ILS                        ((uint8_t)0x02)               /*!< 中断电平状态 */
#define  FSMC_SR2_IFS                        ((uint8_t)0x04)               /*!< 中断下降沿状态 */
#define  FSMC_SR2_IREN                       ((uint8_t)0x08)               /*!< 中断上升沿检测使能位 */
#define  FSMC_SR2_ILEN                       ((uint8_t)0x10)               /*!< 中断电平检测使能位 */
#define  FSMC_SR2_IFEN                       ((uint8_t)0x20)               /*!< 中断下降沿检测使能位 */
#define  FSMC_SR2_FEMPT                      ((uint8_t)0x40)               /*!< FIFO 空 */

/******************* FSMC_SR3 寄存器的位定义 *****************/
#define  FSMC_SR3_IRS                        ((uint8_t)0x01)               /*!< 中断上升沿状态 */
#define  FSMC_SR3_ILS                        ((uint8_t)0x02)               /*!< 中断电平状态 */
#define  FSMC_SR3_IFS                        ((uint8_t)0x04)               /*!< 中断下降沿状态 */
#define  FSMC_SR3_IREN                       ((uint8_t)0x08)               /*!< 中断上升沿检测使能位 */
#define  FSMC_SR3_ILEN                       ((uint8_t)0x10)               /*!< 中断电平检测使能位 */
#define  FSMC_SR3_IFEN                       ((uint8_t)0x20)               /*!< 中断下降沿检测使能位 */
#define  FSMC_SR3_FEMPT                      ((uint8_t)0x40)               /*!< FIFO 空 */

/******************* FSMC_SR4 寄存器的位定义 *****************/
#define  FSMC_SR4_IRS                        ((uint8_t)0x01)               /*!< 中断上升沿状态 */
#define  FSMC_SR4_ILS                        ((uint8_t)0x02)               /*!< 中断电平状态 */
#define  FSMC_SR4_IFS                        ((uint8_t)0x04)               /*!< 中断下降沿状态 */
#define  FSMC_SR4_IREN                       ((uint8_t)0x08)               /*!< 中断上升沿检测使能位 */
#define  FSMC_SR4_ILEN                       ((uint8_t)0x10)               /*!< 中断电平检测使能位 */
#define  FSMC_SR4_IFEN                       ((uint8_t)0x20)               /*!< 中断下降沿检测使能位 */
#define  FSMC_SR4_FEMPT                      ((uint8_t)0x40)               /*!< FIFO 空 */

/****************** FSMC_PMEM2 寄存器的位定义 ****************/
#define  FSMC_PMEM2_MEMSET2                  ((uint32_t)0x000000FF)        /*!< MEMSET2[7:0] 位（公共存储器 2 建立时间） */
#define  FSMC_PMEM2_MEMSET2_0                ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_PMEM2_MEMSET2_1                ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_PMEM2_MEMSET2_2                ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_PMEM2_MEMSET2_3                ((uint32_t)0x00000008)        /*!< 位 3 */
#define  FSMC_PMEM2_MEMSET2_4                ((uint32_t)0x00000010)        /*!< 位 4 */
#define  FSMC_PMEM2_MEMSET2_5                ((uint32_t)0x00000020)        /*!< 位 5 */
#define  FSMC_PMEM2_MEMSET2_6                ((uint32_t)0x00000040)        /*!< 位 6 */
#define  FSMC_PMEM2_MEMSET2_7                ((uint32_t)0x00000080)        /*!< 位 7 */

#define  FSMC_PMEM2_MEMWAIT2                 ((uint32_t)0x0000FF00)        /*!< MEMWAIT2[7:0] 位（公共存储器 2 等待时间） */
#define  FSMC_PMEM2_MEMWAIT2_0               ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_PMEM2_MEMWAIT2_1               ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_PMEM2_MEMWAIT2_2               ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_PMEM2_MEMWAIT2_3               ((uint32_t)0x00000800)        /*!< 位 3 */
#define  FSMC_PMEM2_MEMWAIT2_4               ((uint32_t)0x00001000)        /*!< 位 4 */
#define  FSMC_PMEM2_MEMWAIT2_5               ((uint32_t)0x00002000)        /*!< 位 5 */
#define  FSMC_PMEM2_MEMWAIT2_6               ((uint32_t)0x00004000)        /*!< 位 6 */
#define  FSMC_PMEM2_MEMWAIT2_7               ((uint32_t)0x00008000)        /*!< 位 7 */

#define  FSMC_PMEM2_MEMHOLD2                 ((uint32_t)0x00FF0000)        /*!< MEMHOLD2[7:0] 位（公共存储器 2 保持时间） */
#define  FSMC_PMEM2_MEMHOLD2_0               ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_PMEM2_MEMHOLD2_1               ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_PMEM2_MEMHOLD2_2               ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_PMEM2_MEMHOLD2_3               ((uint32_t)0x00080000)        /*!< 位 3 */
#define  FSMC_PMEM2_MEMHOLD2_4               ((uint32_t)0x00100000)        /*!< 位 4 */
#define  FSMC_PMEM2_MEMHOLD2_5               ((uint32_t)0x00200000)        /*!< 位 5 */
#define  FSMC_PMEM2_MEMHOLD2_6               ((uint32_t)0x00400000)        /*!< 位 6 */
#define  FSMC_PMEM2_MEMHOLD2_7               ((uint32_t)0x00800000)        /*!< 位 7 */

#define  FSMC_PMEM2_MEMHIZ2                  ((uint32_t)0xFF000000)        /*!< MEMHIZ2[7:0] 位（公共存储器 2 数据总线高阻时间） */
#define  FSMC_PMEM2_MEMHIZ2_0                ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_PMEM2_MEMHIZ2_1                ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_PMEM2_MEMHIZ2_2                ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_PMEM2_MEMHIZ2_3                ((uint32_t)0x08000000)        /*!< 位 3 */
#define  FSMC_PMEM2_MEMHIZ2_4                ((uint32_t)0x10000000)        /*!< 位 4 */
#define  FSMC_PMEM2_MEMHIZ2_5                ((uint32_t)0x20000000)        /*!< 位 5 */
#define  FSMC_PMEM2_MEMHIZ2_6                ((uint32_t)0x40000000)        /*!< 位 6 */
#define  FSMC_PMEM2_MEMHIZ2_7                ((uint32_t)0x80000000)        /*!< 位 7 */

/****************** FSMC_PMEM3 寄存器的位定义 ****************/
#define  FSMC_PMEM3_MEMSET3                  ((uint32_t)0x000000FF)        /*!< MEMSET3[7:0] 位（公共存储器 3 建立时间） */
#define  FSMC_PMEM3_MEMSET3_0                ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_PMEM3_MEMSET3_1                ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_PMEM3_MEMSET3_2                ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_PMEM3_MEMSET3_3                ((uint32_t)0x00000008)        /*!< 位 3 */
#define  FSMC_PMEM3_MEMSET3_4                ((uint32_t)0x00000010)        /*!< 位 4 */
#define  FSMC_PMEM3_MEMSET3_5                ((uint32_t)0x00000020)        /*!< 位 5 */
#define  FSMC_PMEM3_MEMSET3_6                ((uint32_t)0x00000040)        /*!< 位 6 */
#define  FSMC_PMEM3_MEMSET3_7                ((uint32_t)0x00000080)        /*!< 位 7 */

#define  FSMC_PMEM3_MEMWAIT3                 ((uint32_t)0x0000FF00)        /*!< MEMWAIT3[7:0] 位（公共存储器 3 等待时间） */
#define  FSMC_PMEM3_MEMWAIT3_0               ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_PMEM3_MEMWAIT3_1               ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_PMEM3_MEMWAIT3_2               ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_PMEM3_MEMWAIT3_3               ((uint32_t)0x00000800)        /*!< 位 3 */
#define  FSMC_PMEM3_MEMWAIT3_4               ((uint32_t)0x00001000)        /*!< 位 4 */
#define  FSMC_PMEM3_MEMWAIT3_5               ((uint32_t)0x00002000)        /*!< 位 5 */
#define  FSMC_PMEM3_MEMWAIT3_6               ((uint32_t)0x00004000)        /*!< 位 6 */
#define  FSMC_PMEM3_MEMWAIT3_7               ((uint32_t)0x00008000)        /*!< 位 7 */

#define  FSMC_PMEM3_MEMHOLD3                 ((uint32_t)0x00FF0000)        /*!< MEMHOLD3[7:0] 位（公共存储器 3 保持时间） */
#define  FSMC_PMEM3_MEMHOLD3_0               ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_PMEM3_MEMHOLD3_1               ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_PMEM3_MEMHOLD3_2               ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_PMEM3_MEMHOLD3_3               ((uint32_t)0x00080000)        /*!< 位 3 */
#define  FSMC_PMEM3_MEMHOLD3_4               ((uint32_t)0x00100000)        /*!< 位 4 */
#define  FSMC_PMEM3_MEMHOLD3_5               ((uint32_t)0x00200000)        /*!< 位 5 */
#define  FSMC_PMEM3_MEMHOLD3_6               ((uint32_t)0x00400000)        /*!< 位 6 */
#define  FSMC_PMEM3_MEMHOLD3_7               ((uint32_t)0x00800000)        /*!< 位 7 */

#define  FSMC_PMEM3_MEMHIZ3                  ((uint32_t)0xFF000000)        /*!< MEMHIZ3[7:0] 位（公共存储器 3 数据总线高阻时间） */
#define  FSMC_PMEM3_MEMHIZ3_0                ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_PMEM3_MEMHIZ3_1                ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_PMEM3_MEMHIZ3_2                ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_PMEM3_MEMHIZ3_3                ((uint32_t)0x08000000)        /*!< 位 3 */
#define  FSMC_PMEM3_MEMHIZ3_4                ((uint32_t)0x10000000)        /*!< 位 4 */
#define  FSMC_PMEM3_MEMHIZ3_5                ((uint32_t)0x20000000)        /*!< 位 5 */
#define  FSMC_PMEM3_MEMHIZ3_6                ((uint32_t)0x40000000)        /*!< 位 6 */
#define  FSMC_PMEM3_MEMHIZ3_7                ((uint32_t)0x80000000)        /*!< 位 7 */

/****************** FSMC_PMEM4 寄存器的位定义 ****************/
#define  FSMC_PMEM4_MEMSET4                  ((uint32_t)0x000000FF)        /*!< MEMSET4[7:0] 位（公共存储器 4 建立时间） */
#define  FSMC_PMEM4_MEMSET4_0                ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_PMEM4_MEMSET4_1                ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_PMEM4_MEMSET4_2                ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_PMEM4_MEMSET4_3                ((uint32_t)0x00000008)        /*!< 位 3 */
#define  FSMC_PMEM4_MEMSET4_4                ((uint32_t)0x00000010)        /*!< 位 4 */
#define  FSMC_PMEM4_MEMSET4_5                ((uint32_t)0x00000020)        /*!< 位 5 */
#define  FSMC_PMEM4_MEMSET4_6                ((uint32_t)0x00000040)        /*!< 位 6 */
#define  FSMC_PMEM4_MEMSET4_7                ((uint32_t)0x00000080)        /*!< 位 7 */

#define  FSMC_PMEM4_MEMWAIT4                 ((uint32_t)0x0000FF00)        /*!< MEMWAIT4[7:0] 位（公共存储器 4 等待时间） */
#define  FSMC_PMEM4_MEMWAIT4_0               ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_PMEM4_MEMWAIT4_1               ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_PMEM4_MEMWAIT4_2               ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_PMEM4_MEMWAIT4_3               ((uint32_t)0x00000800)        /*!< 位 3 */
#define  FSMC_PMEM4_MEMWAIT4_4               ((uint32_t)0x00001000)        /*!< 位 4 */
#define  FSMC_PMEM4_MEMWAIT4_5               ((uint32_t)0x00002000)        /*!< 位 5 */
#define  FSMC_PMEM4_MEMWAIT4_6               ((uint32_t)0x00004000)        /*!< 位 6 */
#define  FSMC_PMEM4_MEMWAIT4_7               ((uint32_t)0x00008000)        /*!< 位 7 */

#define  FSMC_PMEM4_MEMHOLD4                 ((uint32_t)0x00FF0000)        /*!< MEMHOLD4[7:0] 位（公共存储器 4 保持时间） */
#define  FSMC_PMEM4_MEMHOLD4_0               ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_PMEM4_MEMHOLD4_1               ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_PMEM4_MEMHOLD4_2               ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_PMEM4_MEMHOLD4_3               ((uint32_t)0x00080000)        /*!< 位 3 */
#define  FSMC_PMEM4_MEMHOLD4_4               ((uint32_t)0x00100000)        /*!< 位 4 */
#define  FSMC_PMEM4_MEMHOLD4_5               ((uint32_t)0x00200000)        /*!< 位 5 */
#define  FSMC_PMEM4_MEMHOLD4_6               ((uint32_t)0x00400000)        /*!< 位 6 */
#define  FSMC_PMEM4_MEMHOLD4_7               ((uint32_t)0x00800000)        /*!< 位 7 */

#define  FSMC_PMEM4_MEMHIZ4                  ((uint32_t)0xFF000000)        /*!< MEMHIZ4[7:0] 位（公共存储器 4 数据总线高阻时间） */
#define  FSMC_PMEM4_MEMHIZ4_0                ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_PMEM4_MEMHIZ4_1                ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_PMEM4_MEMHIZ4_2                ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_PMEM4_MEMHIZ4_3                ((uint32_t)0x08000000)        /*!< 位 3 */
#define  FSMC_PMEM4_MEMHIZ4_4                ((uint32_t)0x10000000)        /*!< 位 4 */
#define  FSMC_PMEM4_MEMHIZ4_5                ((uint32_t)0x20000000)        /*!< 位 5 */
#define  FSMC_PMEM4_MEMHIZ4_6                ((uint32_t)0x40000000)        /*!< 位 6 */
#define  FSMC_PMEM4_MEMHIZ4_7                ((uint32_t)0x80000000)        /*!< 位 7 */

/****************** FSMC_PATT2 寄存器的位定义 ****************/
#define  FSMC_PATT2_ATTSET2                  ((uint32_t)0x000000FF)        /*!< ATTSET2[7:0] 位（属性存储器 2 建立时间） */
#define  FSMC_PATT2_ATTSET2_0                ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_PATT2_ATTSET2_1                ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_PATT2_ATTSET2_2                ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_PATT2_ATTSET2_3                ((uint32_t)0x00000008)        /*!< 位 3 */
#define  FSMC_PATT2_ATTSET2_4                ((uint32_t)0x00000010)        /*!< 位 4 */
#define  FSMC_PATT2_ATTSET2_5                ((uint32_t)0x00000020)        /*!< 位 5 */
#define  FSMC_PATT2_ATTSET2_6                ((uint32_t)0x00000040)        /*!< 位 6 */
#define  FSMC_PATT2_ATTSET2_7                ((uint32_t)0x00000080)        /*!< 位 7 */

#define  FSMC_PATT2_ATTWAIT2                 ((uint32_t)0x0000FF00)        /*!< ATTWAIT2[7:0] 位（属性存储器 2 等待时间） */
#define  FSMC_PATT2_ATTWAIT2_0               ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_PATT2_ATTWAIT2_1               ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_PATT2_ATTWAIT2_2               ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_PATT2_ATTWAIT2_3               ((uint32_t)0x00000800)        /*!< 位 3 */
#define  FSMC_PATT2_ATTWAIT2_4               ((uint32_t)0x00001000)        /*!< 位 4 */
#define  FSMC_PATT2_ATTWAIT2_5               ((uint32_t)0x00002000)        /*!< 位 5 */
#define  FSMC_PATT2_ATTWAIT2_6               ((uint32_t)0x00004000)        /*!< 位 6 */
#define  FSMC_PATT2_ATTWAIT2_7               ((uint32_t)0x00008000)        /*!< 位 7 */

#define  FSMC_PATT2_ATTHOLD2                 ((uint32_t)0x00FF0000)        /*!< ATTHOLD2[7:0] 位（属性存储器 2 保持时间） */
#define  FSMC_PATT2_ATTHOLD2_0               ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_PATT2_ATTHOLD2_1               ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_PATT2_ATTHOLD2_2               ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_PATT2_ATTHOLD2_3               ((uint32_t)0x00080000)        /*!< 位 3 */
#define  FSMC_PATT2_ATTHOLD2_4               ((uint32_t)0x00100000)        /*!< 位 4 */
#define  FSMC_PATT2_ATTHOLD2_5               ((uint32_t)0x00200000)        /*!< 位 5 */
#define  FSMC_PATT2_ATTHOLD2_6               ((uint32_t)0x00400000)        /*!< 位 6 */
#define  FSMC_PATT2_ATTHOLD2_7               ((uint32_t)0x00800000)        /*!< 位 7 */

#define  FSMC_PATT2_ATTHIZ2                  ((uint32_t)0xFF000000)        /*!< ATTHIZ2[7:0] 位（属性存储器 2 数据总线高阻时间） */
#define  FSMC_PATT2_ATTHIZ2_0                ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_PATT2_ATTHIZ2_1                ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_PATT2_ATTHIZ2_2                ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_PATT2_ATTHIZ2_3                ((uint32_t)0x08000000)        /*!< 位 3 */
#define  FSMC_PATT2_ATTHIZ2_4                ((uint32_t)0x10000000)        /*!< 位 4 */
#define  FSMC_PATT2_ATTHIZ2_5                ((uint32_t)0x20000000)        /*!< 位 5 */
#define  FSMC_PATT2_ATTHIZ2_6                ((uint32_t)0x40000000)        /*!< 位 6 */
#define  FSMC_PATT2_ATTHIZ2_7                ((uint32_t)0x80000000)        /*!< 位 7 */

/****************** FSMC_PATT3 寄存器的位定义 ****************/
#define  FSMC_PATT3_ATTSET3                  ((uint32_t)0x000000FF)        /*!< ATTSET3[7:0] 位（属性存储器 3 建立时间） */
#define  FSMC_PATT3_ATTSET3_0                ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_PATT3_ATTSET3_1                ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_PATT3_ATTSET3_2                ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_PATT3_ATTSET3_3                ((uint32_t)0x00000008)        /*!< 位 3 */
#define  FSMC_PATT3_ATTSET3_4                ((uint32_t)0x00000010)        /*!< 位 4 */
#define  FSMC_PATT3_ATTSET3_5                ((uint32_t)0x00000020)        /*!< 位 5 */
#define  FSMC_PATT3_ATTSET3_6                ((uint32_t)0x00000040)        /*!< 位 6 */
#define  FSMC_PATT3_ATTSET3_7                ((uint32_t)0x00000080)        /*!< 位 7 */

#define  FSMC_PATT3_ATTWAIT3                 ((uint32_t)0x0000FF00)        /*!< ATTWAIT3[7:0] 位（属性存储器 3 等待时间） */
#define  FSMC_PATT3_ATTWAIT3_0               ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_PATT3_ATTWAIT3_1               ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_PATT3_ATTWAIT3_2               ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_PATT3_ATTWAIT3_3               ((uint32_t)0x00000800)        /*!< 位 3 */
#define  FSMC_PATT3_ATTWAIT3_4               ((uint32_t)0x00001000)        /*!< 位 4 */
#define  FSMC_PATT3_ATTWAIT3_5               ((uint32_t)0x00002000)        /*!< 位 5 */
#define  FSMC_PATT3_ATTWAIT3_6               ((uint32_t)0x00004000)        /*!< 位 6 */
#define  FSMC_PATT3_ATTWAIT3_7               ((uint32_t)0x00008000)        /*!< 位 7 */

#define  FSMC_PATT3_ATTHOLD3                 ((uint32_t)0x00FF0000)        /*!< ATTHOLD3[7:0] 位（属性存储器 3 保持时间） */
#define  FSMC_PATT3_ATTHOLD3_0               ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_PATT3_ATTHOLD3_1               ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_PATT3_ATTHOLD3_2               ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_PATT3_ATTHOLD3_3               ((uint32_t)0x00080000)        /*!< 位 3 */
#define  FSMC_PATT3_ATTHOLD3_4               ((uint32_t)0x00100000)        /*!< 位 4 */
#define  FSMC_PATT3_ATTHOLD3_5               ((uint32_t)0x00200000)        /*!< 位 5 */
#define  FSMC_PATT3_ATTHOLD3_6               ((uint32_t)0x00400000)        /*!< 位 6 */
#define  FSMC_PATT3_ATTHOLD3_7               ((uint32_t)0x00800000)        /*!< 位 7 */

#define  FSMC_PATT3_ATTHIZ3                  ((uint32_t)0xFF000000)        /*!< ATTHIZ3[7:0] 位（属性存储器 3 数据总线高阻时间） */
#define  FSMC_PATT3_ATTHIZ3_0                ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_PATT3_ATTHIZ3_1                ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_PATT3_ATTHIZ3_2                ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_PATT3_ATTHIZ3_3                ((uint32_t)0x08000000)        /*!< 位 3 */
#define  FSMC_PATT3_ATTHIZ3_4                ((uint32_t)0x10000000)        /*!< 位 4 */
#define  FSMC_PATT3_ATTHIZ3_5                ((uint32_t)0x20000000)        /*!< 位 5 */
#define  FSMC_PATT3_ATTHIZ3_6                ((uint32_t)0x40000000)        /*!< 位 6 */
#define  FSMC_PATT3_ATTHIZ3_7                ((uint32_t)0x80000000)        /*!< 位 7 */

/****************** FSMC_PATT4 寄存器的位定义 ****************/
#define  FSMC_PATT4_ATTSET4                  ((uint32_t)0x000000FF)        /*!< ATTSET4[7:0] 位（属性存储器 4 建立时间） */
#define  FSMC_PATT4_ATTSET4_0                ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_PATT4_ATTSET4_1                ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_PATT4_ATTSET4_2                ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_PATT4_ATTSET4_3                ((uint32_t)0x00000008)        /*!< 位 3 */
#define  FSMC_PATT4_ATTSET4_4                ((uint32_t)0x00000010)        /*!< 位 4 */
#define  FSMC_PATT4_ATTSET4_5                ((uint32_t)0x00000020)        /*!< 位 5 */
#define  FSMC_PATT4_ATTSET4_6                ((uint32_t)0x00000040)        /*!< 位 6 */
#define  FSMC_PATT4_ATTSET4_7                ((uint32_t)0x00000080)        /*!< 位 7 */

#define  FSMC_PATT4_ATTWAIT4                 ((uint32_t)0x0000FF00)        /*!< ATTWAIT4[7:0] 位（属性存储器 4 等待时间） */
#define  FSMC_PATT4_ATTWAIT4_0               ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_PATT4_ATTWAIT4_1               ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_PATT4_ATTWAIT4_2               ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_PATT4_ATTWAIT4_3               ((uint32_t)0x00000800)        /*!< 位 3 */
#define  FSMC_PATT4_ATTWAIT4_4               ((uint32_t)0x00001000)        /*!< 位 4 */
#define  FSMC_PATT4_ATTWAIT4_5               ((uint32_t)0x00002000)        /*!< 位 5 */
#define  FSMC_PATT4_ATTWAIT4_6               ((uint32_t)0x00004000)        /*!< 位 6 */
#define  FSMC_PATT4_ATTWAIT4_7               ((uint32_t)0x00008000)        /*!< 位 7 */

#define  FSMC_PATT4_ATTHOLD4                 ((uint32_t)0x00FF0000)        /*!< ATTHOLD4[7:0] 位（属性存储器 4 保持时间） */
#define  FSMC_PATT4_ATTHOLD4_0               ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_PATT4_ATTHOLD4_1               ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_PATT4_ATTHOLD4_2               ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_PATT4_ATTHOLD4_3               ((uint32_t)0x00080000)        /*!< 位 3 */
#define  FSMC_PATT4_ATTHOLD4_4               ((uint32_t)0x00100000)        /*!< 位 4 */
#define  FSMC_PATT4_ATTHOLD4_5               ((uint32_t)0x00200000)        /*!< 位 5 */
#define  FSMC_PATT4_ATTHOLD4_6               ((uint32_t)0x00400000)        /*!< 位 6 */
#define  FSMC_PATT4_ATTHOLD4_7               ((uint32_t)0x00800000)        /*!< 位 7 */

#define  FSMC_PATT4_ATTHIZ4                  ((uint32_t)0xFF000000)        /*!< ATTHIZ4[7:0] 位（属性存储器 4 数据总线高阻时间） */
#define  FSMC_PATT4_ATTHIZ4_0                ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_PATT4_ATTHIZ4_1                ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_PATT4_ATTHIZ4_2                ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_PATT4_ATTHIZ4_3                ((uint32_t)0x08000000)        /*!< 位 3 */
#define  FSMC_PATT4_ATTHIZ4_4                ((uint32_t)0x10000000)        /*!< 位 4 */
#define  FSMC_PATT4_ATTHIZ4_5                ((uint32_t)0x20000000)        /*!< 位 5 */
#define  FSMC_PATT4_ATTHIZ4_6                ((uint32_t)0x40000000)        /*!< 位 6 */
#define  FSMC_PATT4_ATTHIZ4_7                ((uint32_t)0x80000000)        /*!< 位 7 */

/****************** FSMC_PIO4 寄存器的位定义 ****************/
#define  FSMC_PIO4_IOSET4                    ((uint32_t)0x000000FF)        /*!< IOSET4[7:0] 位（I/O 4 建立时间） */
#define  FSMC_PIO4_IOSET4_0                  ((uint32_t)0x00000001)        /*!< 位 0 */
#define  FSMC_PIO4_IOSET4_1                  ((uint32_t)0x00000002)        /*!< 位 1 */
#define  FSMC_PIO4_IOSET4_2                  ((uint32_t)0x00000004)        /*!< 位 2 */
#define  FSMC_PIO4_IOSET4_3                  ((uint32_t)0x00000008)        /*!< 位 3 */
#define  FSMC_PIO4_IOSET4_4                  ((uint32_t)0x00000010)        /*!< 位 4 */
#define  FSMC_PIO4_IOSET4_5                  ((uint32_t)0x00000020)        /*!< 位 5 */
#define  FSMC_PIO4_IOSET4_6                  ((uint32_t)0x00000040)        /*!< 位 6 */
#define  FSMC_PIO4_IOSET4_7                  ((uint32_t)0x00000080)        /*!< 位 7 */

#define  FSMC_PIO4_IOWAIT4                   ((uint32_t)0x0000FF00)        /*!< IOWAIT4[7:0] 位（I/O 4 等待时间） */
#define  FSMC_PIO4_IOWAIT4_0                 ((uint32_t)0x00000100)        /*!< 位 0 */
#define  FSMC_PIO4_IOWAIT4_1                 ((uint32_t)0x00000200)        /*!< 位 1 */
#define  FSMC_PIO4_IOWAIT4_2                 ((uint32_t)0x00000400)        /*!< 位 2 */
#define  FSMC_PIO4_IOWAIT4_3                 ((uint32_t)0x00000800)        /*!< 位 3 */
#define  FSMC_PIO4_IOWAIT4_4                 ((uint32_t)0x00001000)        /*!< 位 4 */
#define  FSMC_PIO4_IOWAIT4_5                 ((uint32_t)0x00002000)        /*!< 位 5 */
#define  FSMC_PIO4_IOWAIT4_6                 ((uint32_t)0x00004000)        /*!< 位 6 */
#define  FSMC_PIO4_IOWAIT4_7                 ((uint32_t)0x00008000)        /*!< 位 7 */

#define  FSMC_PIO4_IOHOLD4                   ((uint32_t)0x00FF0000)        /*!< IOHOLD4[7:0] 位（I/O 4 保持时间） */
#define  FSMC_PIO4_IOHOLD4_0                 ((uint32_t)0x00010000)        /*!< 位 0 */
#define  FSMC_PIO4_IOHOLD4_1                 ((uint32_t)0x00020000)        /*!< 位 1 */
#define  FSMC_PIO4_IOHOLD4_2                 ((uint32_t)0x00040000)        /*!< 位 2 */
#define  FSMC_PIO4_IOHOLD4_3                 ((uint32_t)0x00080000)        /*!< 位 3 */
#define  FSMC_PIO4_IOHOLD4_4                 ((uint32_t)0x00100000)        /*!< 位 4 */
#define  FSMC_PIO4_IOHOLD4_5                 ((uint32_t)0x00200000)        /*!< 位 5 */
#define  FSMC_PIO4_IOHOLD4_6                 ((uint32_t)0x00400000)        /*!< 位 6 */
#define  FSMC_PIO4_IOHOLD4_7                 ((uint32_t)0x00800000)        /*!< 位 7 */

#define  FSMC_PIO4_IOHIZ4                    ((uint32_t)0xFF000000)        /*!< IOHIZ4[7:0] 位（I/O 4 数据总线高阻时间） */
#define  FSMC_PIO4_IOHIZ4_0                  ((uint32_t)0x01000000)        /*!< 位 0 */
#define  FSMC_PIO4_IOHIZ4_1                  ((uint32_t)0x02000000)        /*!< 位 1 */
#define  FSMC_PIO4_IOHIZ4_2                  ((uint32_t)0x04000000)        /*!< 位 2 */
#define  FSMC_PIO4_IOHIZ4_3                  ((uint32_t)0x08000000)        /*!< 位 3 */
#define  FSMC_PIO4_IOHIZ4_4                  ((uint32_t)0x10000000)        /*!< 位 4 */
#define  FSMC_PIO4_IOHIZ4_5                  ((uint32_t)0x20000000)        /*!< 位 5 */
#define  FSMC_PIO4_IOHIZ4_6                  ((uint32_t)0x40000000)        /*!< 位 6 */
#define  FSMC_PIO4_IOHIZ4_7                  ((uint32_t)0x80000000)        /*!< 位 7 */

/****************** FSMC_ECCR2 寄存器的位定义 ****************/
#define  FSMC_ECCR2_ECC2                     ((uint32_t)0xFFFFFFFF)        /*!< ECC 结果 */

/****************** FSMC_ECCR3 寄存器的位定义 ****************/
#define  FSMC_ECCR3_ECC3                     ((uint32_t)0xFFFFFFFF)        /*!< ECC 结果 */

/******************************************************************************/
/*                                                                            */
/*                          SD 主机接口                                 */
/*                                                                            */
/******************************************************************************/

/****************** SDIO_POWER 寄存器的位定义 ****************/
#define  SDIO_POWER_PWRCTRL                  ((uint8_t)0x03)               /*!< PWRCTRL[1:0] 位（电源控制位） */
#define  SDIO_POWER_PWRCTRL_0                ((uint8_t)0x01)               /*!< 位 0 */
#define  SDIO_POWER_PWRCTRL_1                ((uint8_t)0x02)               /*!< 位 1 */

/****************** SDIO_CLKCR 寄存器的位定义 ****************/
#define  SDIO_CLKCR_CLKDIV                   ((uint16_t)0x00FF)            /*!< 时钟分频系数 */
#define  SDIO_CLKCR_CLKEN                    ((uint16_t)0x0100)            /*!< 时钟使能位 */
#define  SDIO_CLKCR_PWRSAV                   ((uint16_t)0x0200)            /*!< 省电配置位 */
#define  SDIO_CLKCR_BYPASS                   ((uint16_t)0x0400)            /*!< 时钟分频旁路使能位 */

#define  SDIO_CLKCR_WIDBUS                   ((uint16_t)0x1800)            /*!< WIDBUS[1:0] 位（宽总线模式使能位） */
#define  SDIO_CLKCR_WIDBUS_0                 ((uint16_t)0x0800)            /*!< 位 0 */
#define  SDIO_CLKCR_WIDBUS_1                 ((uint16_t)0x1000)            /*!< 位 1 */

#define  SDIO_CLKCR_NEGEDGE                  ((uint16_t)0x2000)            /*!< SDIO_CK 相移选择位 */
#define  SDIO_CLKCR_HWFC_EN                  ((uint16_t)0x4000)            /*!< 硬件流控制使能 */

/******************* SDIO_ARG 寄存器的位定义 *****************/
#define  SDIO_ARG_CMDARG                     ((uint32_t)0xFFFFFFFF)            /*!< 命令参数 */

/******************* SDIO_CMD 寄存器的位定义 *****************/
#define  SDIO_CMD_CMDINDEX                   ((uint16_t)0x003F)            /*!< 命令索引 */

#define  SDIO_CMD_WAITRESP                   ((uint16_t)0x00C0)            /*!< WAITRESP[1:0] 位（等待响应位） */
#define  SDIO_CMD_WAITRESP_0                 ((uint16_t)0x0040)            /*!<  位 0 */
#define  SDIO_CMD_WAITRESP_1                 ((uint16_t)0x0080)            /*!<  位 1 */

#define  SDIO_CMD_WAITINT                    ((uint16_t)0x0100)            /*!< CPSM 等待中断请求 */
#define  SDIO_CMD_WAITPEND                   ((uint16_t)0x0200)            /*!< CPSM 等待数据传输结束（CmdPend 内部信号） */
#define  SDIO_CMD_CPSMEN                     ((uint16_t)0x0400)            /*!< 命令路径状态机（CPSM）使能位 */
#define  SDIO_CMD_SDIOSUSPEND                ((uint16_t)0x0800)            /*!< SD I/O 挂起命令 */
#define  SDIO_CMD_ENCMDCOMPL                 ((uint16_t)0x1000)            /*!< 使能 CMD 完成 */
#define  SDIO_CMD_NIEN                       ((uint16_t)0x2000)            /*!< 非中断使能 */
#define  SDIO_CMD_CEATACMD                   ((uint16_t)0x4000)            /*!< CE-ATA 命令 */

/***************** SDIO_RESPCMD 寄存器的位定义 ***************/
#define  SDIO_RESPCMD_RESPCMD                ((uint8_t)0x3F)               /*!< 响应命令索引 */

/****************** SDIO_RESP0 寄存器的位定义 ****************/
#define  SDIO_RESP0_CARDSTATUS0              ((uint32_t)0xFFFFFFFF)        /*!< 卡状态 */

/****************** SDIO_RESP1 寄存器的位定义 ****************/
#define  SDIO_RESP1_CARDSTATUS1              ((uint32_t)0xFFFFFFFF)        /*!< 卡状态 */

/****************** SDIO_RESP2 寄存器的位定义 ****************/
#define  SDIO_RESP2_CARDSTATUS2              ((uint32_t)0xFFFFFFFF)        /*!< 卡状态 */

/****************** SDIO_RESP3 寄存器的位定义 ****************/
#define  SDIO_RESP3_CARDSTATUS3              ((uint32_t)0xFFFFFFFF)        /*!< 卡状态 */

/****************** SDIO_RESP4 寄存器的位定义 ****************/
#define  SDIO_RESP4_CARDSTATUS4              ((uint32_t)0xFFFFFFFF)        /*!< 卡状态 */

/****************** SDIO_DTIMER 寄存器的位定义 ****************/
#define  SDIO_DTIMER_DATATIME                ((uint32_t)0xFFFFFFFF)        /*!< 数据超时周期。 */

/****************** SDIO_DLEN 寄存器的位定义 ****************/
#define  SDIO_DLEN_DATALENGTH                ((uint32_t)0x01FFFFFF)        /*!< 数据长度值 */

/****************** SDIO_DCTRL 寄存器的位定义 ****************/
#define  SDIO_DCTRL_DTEN                     ((uint16_t)0x0001)            /*!< 数据传输使能位 */
#define  SDIO_DCTRL_DTDIR                    ((uint16_t)0x0002)            /*!< 数据传输方向选择 */
#define  SDIO_DCTRL_DTMODE                   ((uint16_t)0x0004)            /*!< 数据传输模式选择 */
#define  SDIO_DCTRL_DMAEN                    ((uint16_t)0x0008)            /*!< DMA 使能位 */

#define  SDIO_DCTRL_DBLOCKSIZE               ((uint16_t)0x00F0)            /*!< DBLOCKSIZE[3:0] 位（数据块大小） */
#define  SDIO_DCTRL_DBLOCKSIZE_0             ((uint16_t)0x0010)            /*!< 位 0 */
#define  SDIO_DCTRL_DBLOCKSIZE_1             ((uint16_t)0x0020)            /*!< 位 1 */
#define  SDIO_DCTRL_DBLOCKSIZE_2             ((uint16_t)0x0040)            /*!< 位 2 */
#define  SDIO_DCTRL_DBLOCKSIZE_3             ((uint16_t)0x0080)            /*!< 位 3 */

#define  SDIO_DCTRL_RWSTART                  ((uint16_t)0x0100)            /*!< 读等待开始 */
#define  SDIO_DCTRL_RWSTOP                   ((uint16_t)0x0200)            /*!< 读等待停止 */
#define  SDIO_DCTRL_RWMOD                    ((uint16_t)0x0400)            /*!< 读等待模式 */
#define  SDIO_DCTRL_SDIOEN                   ((uint16_t)0x0800)            /*!< SD I/O 使能功能 */

/****************** SDIO_DCOUNT 寄存器的位定义 ****************/
#define  SDIO_DCOUNT_DATACOUNT               ((uint32_t)0x01FFFFFF)        /*!< 数据计数值 */

/****************** SDIO_STA 寄存器的位定义 ****************/
#define  SDIO_STA_CCRCFAIL                   ((uint32_t)0x00000001)        /*!< 收到命令响应（CRC 校验失败） */
#define  SDIO_STA_DCRCFAIL                   ((uint32_t)0x00000002)        /*!< 数据块已发送/接收（CRC 校验失败） */
#define  SDIO_STA_CTIMEOUT                   ((uint32_t)0x00000004)        /*!< 命令响应超时 */
#define  SDIO_STA_DTIMEOUT                   ((uint32_t)0x00000008)        /*!< 数据超时 */
#define  SDIO_STA_TXUNDERR                   ((uint32_t)0x00000010)        /*!< 发送 FIFO 下溢错误 */
#define  SDIO_STA_RXOVERR                    ((uint32_t)0x00000020)        /*!< 接收 FIFO 上溢错误 */
#define  SDIO_STA_CMDREND                    ((uint32_t)0x00000040)        /*!< 收到命令响应（CRC 校验通过） */
#define  SDIO_STA_CMDSENT                    ((uint32_t)0x00000080)        /*!< 命令已发送（无需响应） */
#define  SDIO_STA_DATAEND                    ((uint32_t)0x00000100)        /*!< 数据结束（数据计数器 SDIDCOUNT 为零） */
#define  SDIO_STA_STBITERR                   ((uint32_t)0x00000200)        /*!< 宽总线模式下未在所有数据信号上检测到起始位 */
#define  SDIO_STA_DBCKEND                    ((uint32_t)0x00000400)        /*!< 数据块已发送/接收（CRC 校验通过） */
#define  SDIO_STA_CMDACT                     ((uint32_t)0x00000800)        /*!< 命令传输进行中 */
#define  SDIO_STA_TXACT                      ((uint32_t)0x00001000)        /*!< 数据发送进行中 */
#define  SDIO_STA_RXACT                      ((uint32_t)0x00002000)        /*!< 数据接收进行中 */
#define  SDIO_STA_TXFIFOHE                   ((uint32_t)0x00004000)        /*!< 发送 FIFO 半空：至少可向 FIFO 写入 8 个字 */
#define  SDIO_STA_RXFIFOHF                   ((uint32_t)0x00008000)        /*!< 接收 FIFO 半满：FIFO 中至少有 8 个字 */
#define  SDIO_STA_TXFIFOF                    ((uint32_t)0x00010000)        /*!< 发送 FIFO 满 */
#define  SDIO_STA_RXFIFOF                    ((uint32_t)0x00020000)        /*!< 接收 FIFO 满 */
#define  SDIO_STA_TXFIFOE                    ((uint32_t)0x00040000)        /*!< 发送 FIFO 空 */
#define  SDIO_STA_RXFIFOE                    ((uint32_t)0x00080000)        /*!< 接收 FIFO 空 */
#define  SDIO_STA_TXDAVL                     ((uint32_t)0x00100000)        /*!< 发送 FIFO 中有可用数据 */
#define  SDIO_STA_RXDAVL                     ((uint32_t)0x00200000)        /*!< 接收 FIFO 中有可用数据 */
#define  SDIO_STA_SDIOIT                     ((uint32_t)0x00400000)        /*!< 收到 SDIO 中断 */
#define  SDIO_STA_CEATAEND                   ((uint32_t)0x00800000)        /*!< 收到 CMD61 的 CE-ATA 命令完成信号 */

/******************* SDIO_ICR 寄存器的位定义 *****************/
#define  SDIO_ICR_CCRCFAILC                  ((uint32_t)0x00000001)        /*!< CCRCFAIL 标志位清除位 */
#define  SDIO_ICR_DCRCFAILC                  ((uint32_t)0x00000002)        /*!< DCRCFAIL 标志位清除位 */
#define  SDIO_ICR_CTIMEOUTC                  ((uint32_t)0x00000004)        /*!< CTIMEOUT 标志位清除位 */
#define  SDIO_ICR_DTIMEOUTC                  ((uint32_t)0x00000008)        /*!< DTIMEOUT 标志位清除位 */
#define  SDIO_ICR_TXUNDERRC                  ((uint32_t)0x00000010)        /*!< TXUNDERR 标志位清除位 */
#define  SDIO_ICR_RXOVERRC                   ((uint32_t)0x00000020)        /*!< RXOVERR 标志位清除位 */
#define  SDIO_ICR_CMDRENDC                   ((uint32_t)0x00000040)        /*!< CMDREND 标志位清除位 */
#define  SDIO_ICR_CMDSENTC                   ((uint32_t)0x00000080)        /*!< CMDSENT 标志位清除位 */
#define  SDIO_ICR_DATAENDC                   ((uint32_t)0x00000100)        /*!< DATAEND 标志位清除位 */
#define  SDIO_ICR_STBITERRC                  ((uint32_t)0x00000200)        /*!< STBITERR 标志位清除位 */
#define  SDIO_ICR_DBCKENDC                   ((uint32_t)0x00000400)        /*!< DBCKEND 标志位清除位 */
#define  SDIO_ICR_SDIOITC                    ((uint32_t)0x00400000)        /*!< SDIOIT 标志位清除位 */
#define  SDIO_ICR_CEATAENDC                  ((uint32_t)0x00800000)        /*!< CEATAEND 标志位清除位 */

/****************** SDIO_MASK 寄存器的位定义 ****************/
#define  SDIO_MASK_CCRCFAILIE                ((uint32_t)0x00000001)        /*!< 命令 CRC 失败中断使能 */
#define  SDIO_MASK_DCRCFAILIE                ((uint32_t)0x00000002)        /*!< 数据 CRC 失败中断使能 */
#define  SDIO_MASK_CTIMEOUTIE                ((uint32_t)0x00000004)        /*!< 命令超时中断使能 */
#define  SDIO_MASK_DTIMEOUTIE                ((uint32_t)0x00000008)        /*!< 数据超时中断使能 */
#define  SDIO_MASK_TXUNDERRIE                ((uint32_t)0x00000010)        /*!< 发送 FIFO 下溢错误中断使能 */
#define  SDIO_MASK_RXOVERRIE                 ((uint32_t)0x00000020)        /*!< 接收 FIFO 上溢错误中断使能 */
#define  SDIO_MASK_CMDRENDIE                 ((uint32_t)0x00000040)        /*!< 收到命令响应中断使能 */
#define  SDIO_MASK_CMDSENTIE                 ((uint32_t)0x00000080)        /*!< 命令已发送中断使能 */
#define  SDIO_MASK_DATAENDIE                 ((uint32_t)0x00000100)        /*!< 数据结束中断使能 */
#define  SDIO_MASK_STBITERRIE                ((uint32_t)0x00000200)        /*!< 起始位错误中断使能 */
#define  SDIO_MASK_DBCKENDIE                 ((uint32_t)0x00000400)        /*!< 数据块结束中断使能 */
#define  SDIO_MASK_CMDACTIE                  ((uint32_t)0x00000800)        /*!< 命令进行中中断使能 */
#define  SDIO_MASK_TXACTIE                   ((uint32_t)0x00001000)        /*!< 数据发送进行中中断使能 */
#define  SDIO_MASK_RXACTIE                   ((uint32_t)0x00002000)        /*!< 数据接收进行中中断使能 */
#define  SDIO_MASK_TXFIFOHEIE                ((uint32_t)0x00004000)        /*!< 发送 FIFO 半空中断使能 */
#define  SDIO_MASK_RXFIFOHFIE                ((uint32_t)0x00008000)        /*!< 接收 FIFO 半满中断使能 */
#define  SDIO_MASK_TXFIFOFIE                 ((uint32_t)0x00010000)        /*!< 发送 FIFO 满中断使能 */
#define  SDIO_MASK_RXFIFOFIE                 ((uint32_t)0x00020000)        /*!< 接收 FIFO 满中断使能 */
#define  SDIO_MASK_TXFIFOEIE                 ((uint32_t)0x00040000)        /*!< 发送 FIFO 空中断使能 */
#define  SDIO_MASK_RXFIFOEIE                 ((uint32_t)0x00080000)        /*!< 接收 FIFO 空中断使能 */
#define  SDIO_MASK_TXDAVLIE                  ((uint32_t)0x00100000)        /*!< 发送 FIFO 中有可用数据中断使能 */
#define  SDIO_MASK_RXDAVLIE                  ((uint32_t)0x00200000)        /*!< 接收 FIFO 中有可用数据中断使能 */
#define  SDIO_MASK_SDIOITIE                  ((uint32_t)0x00400000)        /*!< 收到 SDIO 模式中断使能 */
#define  SDIO_MASK_CEATAENDIE                ((uint32_t)0x00800000)        /*!< 收到 CE-ATA 命令完成信号中断使能 */

/***************** SDIO_FIFOCNT 寄存器的位定义 ***************/
#define  SDIO_FIFOCNT_FIFOCOUNT              ((uint32_t)0x00FFFFFF)        /*!< 待写入或读取的 FIFO 剩余字数 */

/****************** SDIO_FIFO 寄存器的位定义 ****************/
#define  SDIO_FIFO_FIFODATA                  ((uint32_t)0xFFFFFFFF)        /*!< 接收和发送 FIFO 数据 */

/******************************************************************************/
/*                                                                            */
/*                                   USB 设备 FS                            */
/*                                                                            */
/******************************************************************************/

/*!< 端点专用寄存器 */
/******************* USB_EP0R 寄存器的位定义 *****************/
#define  USB_EP0R_EA                         ((uint16_t)0x000F)            /*!< 端点地址 */

#define  USB_EP0R_STAT_TX                    ((uint16_t)0x0030)            /*!< STAT_TX[1:0] 位（发送传输的状态位） */
#define  USB_EP0R_STAT_TX_0                  ((uint16_t)0x0010)            /*!< 位 0 */
#define  USB_EP0R_STAT_TX_1                  ((uint16_t)0x0020)            /*!< 位 1 */

#define  USB_EP0R_DTOG_TX                    ((uint16_t)0x0040)            /*!< 数据翻转，用于发送传输 */
#define  USB_EP0R_CTR_TX                     ((uint16_t)0x0080)            /*!< 发送正确传输 */
#define  USB_EP0R_EP_KIND                    ((uint16_t)0x0100)            /*!< 端点类型 */

#define  USB_EP0R_EP_TYPE                    ((uint16_t)0x0600)            /*!< EP_TYPE[1:0] 位（端点类型） */
#define  USB_EP0R_EP_TYPE_0                  ((uint16_t)0x0200)            /*!< 位 0 */
#define  USB_EP0R_EP_TYPE_1                  ((uint16_t)0x0400)            /*!< 位 1 */

#define  USB_EP0R_SETUP                      ((uint16_t)0x0800)            /*!< SETUP 事务完成 */

#define  USB_EP0R_STAT_RX                    ((uint16_t)0x3000)            /*!< STAT_RX[1:0] 位（接收传输的状态位） */
#define  USB_EP0R_STAT_RX_0                  ((uint16_t)0x1000)            /*!< 位 0 */
#define  USB_EP0R_STAT_RX_1                  ((uint16_t)0x2000)            /*!< 位 1 */

#define  USB_EP0R_DTOG_RX                    ((uint16_t)0x4000)            /*!< 数据翻转，用于接收传输 */
#define  USB_EP0R_CTR_RX                     ((uint16_t)0x8000)            /*!< 接收正确传输 */

/******************* USB_EP1R 寄存器的位定义 *****************/
#define  USB_EP1R_EA                         ((uint16_t)0x000F)            /*!< 端点地址 */

#define  USB_EP1R_STAT_TX                    ((uint16_t)0x0030)            /*!< STAT_TX[1:0] 位（发送传输的状态位） */
#define  USB_EP1R_STAT_TX_0                  ((uint16_t)0x0010)            /*!< 位 0 */
#define  USB_EP1R_STAT_TX_1                  ((uint16_t)0x0020)            /*!< 位 1 */

#define  USB_EP1R_DTOG_TX                    ((uint16_t)0x0040)            /*!< 数据翻转，用于发送传输 */
#define  USB_EP1R_CTR_TX                     ((uint16_t)0x0080)            /*!< 发送正确传输 */
#define  USB_EP1R_EP_KIND                    ((uint16_t)0x0100)            /*!< 端点类型 */

#define  USB_EP1R_EP_TYPE                    ((uint16_t)0x0600)            /*!< EP_TYPE[1:0] 位（端点类型） */
#define  USB_EP1R_EP_TYPE_0                  ((uint16_t)0x0200)            /*!< 位 0 */
#define  USB_EP1R_EP_TYPE_1                  ((uint16_t)0x0400)            /*!< 位 1 */

#define  USB_EP1R_SETUP                      ((uint16_t)0x0800)            /*!< SETUP 事务完成 */

#define  USB_EP1R_STAT_RX                    ((uint16_t)0x3000)            /*!< STAT_RX[1:0] 位（接收传输的状态位） */
#define  USB_EP1R_STAT_RX_0                  ((uint16_t)0x1000)            /*!< 位 0 */
#define  USB_EP1R_STAT_RX_1                  ((uint16_t)0x2000)            /*!< 位 1 */

#define  USB_EP1R_DTOG_RX                    ((uint16_t)0x4000)            /*!< 数据翻转，用于接收传输 */
#define  USB_EP1R_CTR_RX                     ((uint16_t)0x8000)            /*!< 接收正确传输 */

/******************* USB_EP2R 寄存器的位定义 *****************/
#define  USB_EP2R_EA                         ((uint16_t)0x000F)            /*!< 端点地址 */

#define  USB_EP2R_STAT_TX                    ((uint16_t)0x0030)            /*!< STAT_TX[1:0] 位（发送传输的状态位） */
#define  USB_EP2R_STAT_TX_0                  ((uint16_t)0x0010)            /*!< 位 0 */
#define  USB_EP2R_STAT_TX_1                  ((uint16_t)0x0020)            /*!< 位 1 */

#define  USB_EP2R_DTOG_TX                    ((uint16_t)0x0040)            /*!< 数据翻转，用于发送传输 */
#define  USB_EP2R_CTR_TX                     ((uint16_t)0x0080)            /*!< 发送正确传输 */
#define  USB_EP2R_EP_KIND                    ((uint16_t)0x0100)            /*!< 端点类型 */

#define  USB_EP2R_EP_TYPE                    ((uint16_t)0x0600)            /*!< EP_TYPE[1:0] 位（端点类型） */
#define  USB_EP2R_EP_TYPE_0                  ((uint16_t)0x0200)            /*!< 位 0 */
#define  USB_EP2R_EP_TYPE_1                  ((uint16_t)0x0400)            /*!< 位 1 */

#define  USB_EP2R_SETUP                      ((uint16_t)0x0800)            /*!< SETUP 事务完成 */

#define  USB_EP2R_STAT_RX                    ((uint16_t)0x3000)            /*!< STAT_RX[1:0] 位（接收传输的状态位） */
#define  USB_EP2R_STAT_RX_0                  ((uint16_t)0x1000)            /*!< 位 0 */
#define  USB_EP2R_STAT_RX_1                  ((uint16_t)0x2000)            /*!< 位 1 */

#define  USB_EP2R_DTOG_RX                    ((uint16_t)0x4000)            /*!< 数据翻转，用于接收传输 */
#define  USB_EP2R_CTR_RX                     ((uint16_t)0x8000)            /*!< 接收正确传输 */

/******************* USB_EP3R 寄存器的位定义 *****************/
#define  USB_EP3R_EA                         ((uint16_t)0x000F)            /*!< 端点地址 */

#define  USB_EP3R_STAT_TX                    ((uint16_t)0x0030)            /*!< STAT_TX[1:0] 位（发送传输的状态位） */
#define  USB_EP3R_STAT_TX_0                  ((uint16_t)0x0010)            /*!< 位 0 */
#define  USB_EP3R_STAT_TX_1                  ((uint16_t)0x0020)            /*!< 位 1 */

#define  USB_EP3R_DTOG_TX                    ((uint16_t)0x0040)            /*!< 数据翻转，用于发送传输 */
#define  USB_EP3R_CTR_TX                     ((uint16_t)0x0080)            /*!< 发送正确传输 */
#define  USB_EP3R_EP_KIND                    ((uint16_t)0x0100)            /*!< 端点类型 */

#define  USB_EP3R_EP_TYPE                    ((uint16_t)0x0600)            /*!< EP_TYPE[1:0] 位（端点类型） */
#define  USB_EP3R_EP_TYPE_0                  ((uint16_t)0x0200)            /*!< 位 0 */
#define  USB_EP3R_EP_TYPE_1                  ((uint16_t)0x0400)            /*!< 位 1 */

#define  USB_EP3R_SETUP                      ((uint16_t)0x0800)            /*!< SETUP 事务完成 */

#define  USB_EP3R_STAT_RX                    ((uint16_t)0x3000)            /*!< STAT_RX[1:0] 位（接收传输的状态位） */
#define  USB_EP3R_STAT_RX_0                  ((uint16_t)0x1000)            /*!< 位 0 */
#define  USB_EP3R_STAT_RX_1                  ((uint16_t)0x2000)            /*!< 位 1 */

#define  USB_EP3R_DTOG_RX                    ((uint16_t)0x4000)            /*!< 数据翻转，用于接收传输 */
#define  USB_EP3R_CTR_RX                     ((uint16_t)0x8000)            /*!< 接收正确传输 */

/******************* USB_EP4R 寄存器的位定义 *****************/
#define  USB_EP4R_EA                         ((uint16_t)0x000F)            /*!< 端点地址 */

#define  USB_EP4R_STAT_TX                    ((uint16_t)0x0030)            /*!< STAT_TX[1:0] 位（发送传输的状态位） */
#define  USB_EP4R_STAT_TX_0                  ((uint16_t)0x0010)            /*!< 位 0 */
#define  USB_EP4R_STAT_TX_1                  ((uint16_t)0x0020)            /*!< 位 1 */

#define  USB_EP4R_DTOG_TX                    ((uint16_t)0x0040)            /*!< 数据翻转，用于发送传输 */
#define  USB_EP4R_CTR_TX                     ((uint16_t)0x0080)            /*!< 发送正确传输 */
#define  USB_EP4R_EP_KIND                    ((uint16_t)0x0100)            /*!< 端点类型 */

#define  USB_EP4R_EP_TYPE                    ((uint16_t)0x0600)            /*!< EP_TYPE[1:0] 位（端点类型） */
#define  USB_EP4R_EP_TYPE_0                  ((uint16_t)0x0200)            /*!< 位 0 */
#define  USB_EP4R_EP_TYPE_1                  ((uint16_t)0x0400)            /*!< 位 1 */

#define  USB_EP4R_SETUP                      ((uint16_t)0x0800)            /*!< SETUP 事务完成 */

#define  USB_EP4R_STAT_RX                    ((uint16_t)0x3000)            /*!< STAT_RX[1:0] 位（接收传输的状态位） */
#define  USB_EP4R_STAT_RX_0                  ((uint16_t)0x1000)            /*!< 位 0 */
#define  USB_EP4R_STAT_RX_1                  ((uint16_t)0x2000)            /*!< 位 1 */

#define  USB_EP4R_DTOG_RX                    ((uint16_t)0x4000)            /*!< 数据翻转，用于接收传输 */
#define  USB_EP4R_CTR_RX                     ((uint16_t)0x8000)            /*!< 接收正确传输 */

/******************* USB_EP5R 寄存器的位定义 *****************/
#define  USB_EP5R_EA                         ((uint16_t)0x000F)            /*!< 端点地址 */

#define  USB_EP5R_STAT_TX                    ((uint16_t)0x0030)            /*!< STAT_TX[1:0] 位（发送传输的状态位） */
#define  USB_EP5R_STAT_TX_0                  ((uint16_t)0x0010)            /*!< 位 0 */
#define  USB_EP5R_STAT_TX_1                  ((uint16_t)0x0020)            /*!< 位 1 */

#define  USB_EP5R_DTOG_TX                    ((uint16_t)0x0040)            /*!< 数据翻转，用于发送传输 */
#define  USB_EP5R_CTR_TX                     ((uint16_t)0x0080)            /*!< 发送正确传输 */
#define  USB_EP5R_EP_KIND                    ((uint16_t)0x0100)            /*!< 端点类型 */

#define  USB_EP5R_EP_TYPE                    ((uint16_t)0x0600)            /*!< EP_TYPE[1:0] 位（端点类型） */
#define  USB_EP5R_EP_TYPE_0                  ((uint16_t)0x0200)            /*!< 位 0 */
#define  USB_EP5R_EP_TYPE_1                  ((uint16_t)0x0400)            /*!< 位 1 */

#define  USB_EP5R_SETUP                      ((uint16_t)0x0800)            /*!< SETUP 事务完成 */

#define  USB_EP5R_STAT_RX                    ((uint16_t)0x3000)            /*!< STAT_RX[1:0] 位（接收传输的状态位） */
#define  USB_EP5R_STAT_RX_0                  ((uint16_t)0x1000)            /*!< 位 0 */
#define  USB_EP5R_STAT_RX_1                  ((uint16_t)0x2000)            /*!< 位 1 */

#define  USB_EP5R_DTOG_RX                    ((uint16_t)0x4000)            /*!< 数据翻转，用于接收传输 */
#define  USB_EP5R_CTR_RX                     ((uint16_t)0x8000)            /*!< 接收正确传输 */

/******************* USB_EP6R 寄存器的位定义 *****************/
#define  USB_EP6R_EA                         ((uint16_t)0x000F)            /*!< 端点地址 */

#define  USB_EP6R_STAT_TX                    ((uint16_t)0x0030)            /*!< STAT_TX[1:0] 位（发送传输的状态位） */
#define  USB_EP6R_STAT_TX_0                  ((uint16_t)0x0010)            /*!< 位 0 */
#define  USB_EP6R_STAT_TX_1                  ((uint16_t)0x0020)            /*!< 位 1 */

#define  USB_EP6R_DTOG_TX                    ((uint16_t)0x0040)            /*!< 数据翻转，用于发送传输 */
#define  USB_EP6R_CTR_TX                     ((uint16_t)0x0080)            /*!< 发送正确传输 */
#define  USB_EP6R_EP_KIND                    ((uint16_t)0x0100)            /*!< 端点类型 */

#define  USB_EP6R_EP_TYPE                    ((uint16_t)0x0600)            /*!< EP_TYPE[1:0] 位（端点类型） */
#define  USB_EP6R_EP_TYPE_0                  ((uint16_t)0x0200)            /*!< 位 0 */
#define  USB_EP6R_EP_TYPE_1                  ((uint16_t)0x0400)            /*!< 位 1 */

#define  USB_EP6R_SETUP                      ((uint16_t)0x0800)            /*!< SETUP 事务完成 */

#define  USB_EP6R_STAT_RX                    ((uint16_t)0x3000)            /*!< STAT_RX[1:0] 位（接收传输的状态位） */
#define  USB_EP6R_STAT_RX_0                  ((uint16_t)0x1000)            /*!< 位 0 */
#define  USB_EP6R_STAT_RX_1                  ((uint16_t)0x2000)            /*!< 位 1 */

#define  USB_EP6R_DTOG_RX                    ((uint16_t)0x4000)            /*!< 数据翻转，用于接收传输 */
#define  USB_EP6R_CTR_RX                     ((uint16_t)0x8000)            /*!< 接收正确传输 */

/******************* USB_EP7R 寄存器的位定义 *****************/
#define  USB_EP7R_EA                         ((uint16_t)0x000F)            /*!< 端点地址 */

#define  USB_EP7R_STAT_TX                    ((uint16_t)0x0030)            /*!< STAT_TX[1:0] 位（发送传输的状态位） */
#define  USB_EP7R_STAT_TX_0                  ((uint16_t)0x0010)            /*!< 位 0 */
#define  USB_EP7R_STAT_TX_1                  ((uint16_t)0x0020)            /*!< 位 1 */

#define  USB_EP7R_DTOG_TX                    ((uint16_t)0x0040)            /*!< 数据翻转，用于发送传输 */
#define  USB_EP7R_CTR_TX                     ((uint16_t)0x0080)            /*!< 发送正确传输 */
#define  USB_EP7R_EP_KIND                    ((uint16_t)0x0100)            /*!< 端点类型 */

#define  USB_EP7R_EP_TYPE                    ((uint16_t)0x0600)            /*!< EP_TYPE[1:0] 位（端点类型） */
#define  USB_EP7R_EP_TYPE_0                  ((uint16_t)0x0200)            /*!< 位 0 */
#define  USB_EP7R_EP_TYPE_1                  ((uint16_t)0x0400)            /*!< 位 1 */

#define  USB_EP7R_SETUP                      ((uint16_t)0x0800)            /*!< SETUP 事务完成 */

#define  USB_EP7R_STAT_RX                    ((uint16_t)0x3000)            /*!< STAT_RX[1:0] 位（接收传输的状态位） */
#define  USB_EP7R_STAT_RX_0                  ((uint16_t)0x1000)            /*!< 位 0 */
#define  USB_EP7R_STAT_RX_1                  ((uint16_t)0x2000)            /*!< 位 1 */

#define  USB_EP7R_DTOG_RX                    ((uint16_t)0x4000)            /*!< 数据翻转，用于接收传输 */
#define  USB_EP7R_CTR_RX                     ((uint16_t)0x8000)            /*!< 接收正确传输 */

/*!< 公共寄存器 */
/******************* USB_CNTR 寄存器的位定义 *****************/
#define  USB_CNTR_FRES                       ((uint16_t)0x0001)            /*!< 强制 USB 复位 */
#define  USB_CNTR_PDWN                       ((uint16_t)0x0002)            /*!< 掉电 */
#define  USB_CNTR_LP_MODE                    ((uint16_t)0x0004)            /*!< 低功耗模式 */
#define  USB_CNTR_FSUSP                      ((uint16_t)0x0008)            /*!< 强制挂起 */
#define  USB_CNTR_RESUME                     ((uint16_t)0x0010)            /*!< 恢复请求 */
#define  USB_CNTR_ESOFM                      ((uint16_t)0x0100)            /*!< 期望帧起始中断屏蔽 */
#define  USB_CNTR_SOFM                       ((uint16_t)0x0200)            /*!< 帧起始中断屏蔽 */
#define  USB_CNTR_RESETM                     ((uint16_t)0x0400)            /*!< RESET 中断屏蔽 */
#define  USB_CNTR_SUSPM                      ((uint16_t)0x0800)            /*!< 挂起模式中断屏蔽 */
#define  USB_CNTR_WKUPM                      ((uint16_t)0x1000)            /*!< 唤醒中断屏蔽 */
#define  USB_CNTR_ERRM                       ((uint16_t)0x2000)            /*!< 错误中断屏蔽 */
#define  USB_CNTR_PMAOVRM                    ((uint16_t)0x4000)            /*!< 数据包存储区上溢 / 下溢中断屏蔽 */
#define  USB_CNTR_CTRM                       ((uint16_t)0x8000)            /*!< 正确传输中断屏蔽 */

/******************* USB_ISTR 寄存器的位定义 *****************/
#define  USB_ISTR_EP_ID                      ((uint16_t)0x000F)            /*!< 端点标识符 */
#define  USB_ISTR_DIR                        ((uint16_t)0x0010)            /*!< 事务方向 */
#define  USB_ISTR_ESOF                       ((uint16_t)0x0100)            /*!< 期望帧起始 */
#define  USB_ISTR_SOF                        ((uint16_t)0x0200)            /*!< 帧起始 */
#define  USB_ISTR_RESET                      ((uint16_t)0x0400)            /*!< USB RESET 请求 */
#define  USB_ISTR_SUSP                       ((uint16_t)0x0800)            /*!< 挂起模式请求 */
#define  USB_ISTR_WKUP                       ((uint16_t)0x1000)            /*!< 唤醒 */
#define  USB_ISTR_ERR                        ((uint16_t)0x2000)            /*!< 错误 */
#define  USB_ISTR_PMAOVR                     ((uint16_t)0x4000)            /*!< 数据包存储区上溢 / 下溢 */
#define  USB_ISTR_CTR                        ((uint16_t)0x8000)            /*!< 正确传输 */

/******************* USB_FNR 寄存器的位定义 *****************/
#define  USB_FNR_FN                          ((uint16_t)0x07FF)            /*!< 帧编号 */
#define  USB_FNR_LSOF                        ((uint16_t)0x1800)            /*!< SOF 丢失 */
#define  USB_FNR_LCK                         ((uint16_t)0x2000)            /*!< 已锁定 */
#define  USB_FNR_RXDM                        ((uint16_t)0x4000)            /*!< 接收数据 - 线状态 */
#define  USB_FNR_RXDP                        ((uint16_t)0x8000)            /*!< 接收数据 + 线状态 */

/****************** USB_DADDR 寄存器的位定义 ****************/
#define  USB_DADDR_ADD                       ((uint8_t)0x7F)               /*!< ADD[6:0] 位（设备地址） */
#define  USB_DADDR_ADD0                      ((uint8_t)0x01)               /*!< 位 0 */
#define  USB_DADDR_ADD1                      ((uint8_t)0x02)               /*!< 位 1 */
#define  USB_DADDR_ADD2                      ((uint8_t)0x04)               /*!< 位 2 */
#define  USB_DADDR_ADD3                      ((uint8_t)0x08)               /*!< 位 3 */
#define  USB_DADDR_ADD4                      ((uint8_t)0x10)               /*!< 位 4 */
#define  USB_DADDR_ADD5                      ((uint8_t)0x20)               /*!< 位 5 */
#define  USB_DADDR_ADD6                      ((uint8_t)0x40)               /*!< 位 6 */

#define  USB_DADDR_EF                        ((uint8_t)0x80)               /*!< 使能功能 */

/****************** USB_BTABLE 寄存器的位定义 ****************/    
#define  USB_BTABLE_BTABLE                   ((uint16_t)0xFFF8)            /*!< 缓冲区表 */

/*!< 缓冲区描述符表 */
/***************** USB_ADDR0_TX 寄存器的位定义 ***************/
#define  USB_ADDR0_TX_ADDR0_TX               ((uint16_t)0xFFFE)            /*!< 发送缓冲区地址 0 */

/***************** USB_ADDR1_TX 寄存器的位定义 ***************/
#define  USB_ADDR1_TX_ADDR1_TX               ((uint16_t)0xFFFE)            /*!< 发送缓冲区地址 1 */

/***************** USB_ADDR2_TX 寄存器的位定义 ***************/
#define  USB_ADDR2_TX_ADDR2_TX               ((uint16_t)0xFFFE)            /*!< 发送缓冲区地址 2 */

/***************** USB_ADDR3_TX 寄存器的位定义 ***************/
#define  USB_ADDR3_TX_ADDR3_TX               ((uint16_t)0xFFFE)            /*!< 发送缓冲区地址 3 */

/***************** USB_ADDR4_TX 寄存器的位定义 ***************/
#define  USB_ADDR4_TX_ADDR4_TX               ((uint16_t)0xFFFE)            /*!< 发送缓冲区地址 4 */

/***************** USB_ADDR5_TX 寄存器的位定义 ***************/
#define  USB_ADDR5_TX_ADDR5_TX               ((uint16_t)0xFFFE)            /*!< 发送缓冲区地址 5 */

/***************** USB_ADDR6_TX 寄存器的位定义 ***************/
#define  USB_ADDR6_TX_ADDR6_TX               ((uint16_t)0xFFFE)            /*!< 发送缓冲区地址 6 */

/***************** USB_ADDR7_TX 寄存器的位定义 ***************/
#define  USB_ADDR7_TX_ADDR7_TX               ((uint16_t)0xFFFE)            /*!< 发送缓冲区地址 7 */

/*----------------------------------------------------------------------------*/

/***************** USB_COUNT0_TX 寄存器的位定义 ***************/
#define  USB_COUNT0_TX_COUNT0_TX             ((uint16_t)0x03FF)            /*!< 发送字节数 0 */

/***************** USB_COUNT1_TX 寄存器的位定义 ***************/
#define  USB_COUNT1_TX_COUNT1_TX             ((uint16_t)0x03FF)            /*!< 发送字节数 1 */

/***************** USB_COUNT2_TX 寄存器的位定义 ***************/
#define  USB_COUNT2_TX_COUNT2_TX             ((uint16_t)0x03FF)            /*!< 发送字节数 2 */

/***************** USB_COUNT3_TX 寄存器的位定义 ***************/
#define  USB_COUNT3_TX_COUNT3_TX             ((uint16_t)0x03FF)            /*!< 发送字节数 3 */

/***************** USB_COUNT4_TX 寄存器的位定义 ***************/
#define  USB_COUNT4_TX_COUNT4_TX             ((uint16_t)0x03FF)            /*!< 发送字节数 4 */

/***************** USB_COUNT5_TX 寄存器的位定义 ***************/
#define  USB_COUNT5_TX_COUNT5_TX             ((uint16_t)0x03FF)            /*!< 发送字节数 5 */

/***************** USB_COUNT6_TX 寄存器的位定义 ***************/
#define  USB_COUNT6_TX_COUNT6_TX             ((uint16_t)0x03FF)            /*!< 发送字节数 6 */

/***************** USB_COUNT7_TX 寄存器的位定义 ***************/
#define  USB_COUNT7_TX_COUNT7_TX             ((uint16_t)0x03FF)            /*!< 发送字节数 7 */

/*----------------------------------------------------------------------------*/

/**************** USB_COUNT0_TX_0 寄存器的位定义 **************/
#define  USB_COUNT0_TX_0_COUNT0_TX_0         ((uint32_t)0x000003FF)        /*!< 发送字节数 0（低字节） */

/**************** USB_COUNT0_TX_1 寄存器的位定义 **************/
#define  USB_COUNT0_TX_1_COUNT0_TX_1         ((uint32_t)0x03FF0000)        /*!< 发送字节数 0（高字节） */

/**************** USB_COUNT1_TX_0 寄存器的位定义 **************/
#define  USB_COUNT1_TX_0_COUNT1_TX_0          ((uint32_t)0x000003FF)        /*!< 发送字节数 1（低字节） */

/**************** USB_COUNT1_TX_1 寄存器的位定义 **************/
#define  USB_COUNT1_TX_1_COUNT1_TX_1          ((uint32_t)0x03FF0000)        /*!< 发送字节数 1（高字节） */

/**************** USB_COUNT2_TX_0 寄存器的位定义 **************/
#define  USB_COUNT2_TX_0_COUNT2_TX_0         ((uint32_t)0x000003FF)        /*!< 发送字节数 2（低字节） */

/**************** USB_COUNT2_TX_1 寄存器的位定义 **************/
#define  USB_COUNT2_TX_1_COUNT2_TX_1         ((uint32_t)0x03FF0000)        /*!< 发送字节数 2（高字节） */

/**************** USB_COUNT3_TX_0 寄存器的位定义 **************/
#define  USB_COUNT3_TX_0_COUNT3_TX_0         ((uint16_t)0x000003FF)        /*!< 发送字节数 3（低字节） */

/**************** USB_COUNT3_TX_1 寄存器的位定义 **************/
#define  USB_COUNT3_TX_1_COUNT3_TX_1         ((uint16_t)0x03FF0000)        /*!< 发送字节数 3（高字节） */

/**************** USB_COUNT4_TX_0 寄存器的位定义 **************/
#define  USB_COUNT4_TX_0_COUNT4_TX_0         ((uint32_t)0x000003FF)        /*!< 发送字节数 4（低字节） */

/**************** USB_COUNT4_TX_1 寄存器的位定义 **************/
#define  USB_COUNT4_TX_1_COUNT4_TX_1         ((uint32_t)0x03FF0000)        /*!< 发送字节数 4（高字节） */

/**************** USB_COUNT5_TX_0 寄存器的位定义 **************/
#define  USB_COUNT5_TX_0_COUNT5_TX_0         ((uint32_t)0x000003FF)        /*!< 发送字节数 5（低字节） */

/**************** USB_COUNT5_TX_1 寄存器的位定义 **************/
#define  USB_COUNT5_TX_1_COUNT5_TX_1         ((uint32_t)0x03FF0000)        /*!< 发送字节数 5（高字节） */

/**************** USB_COUNT6_TX_0 寄存器的位定义 **************/
#define  USB_COUNT6_TX_0_COUNT6_TX_0         ((uint32_t)0x000003FF)        /*!< 发送字节数 6（低字节） */

/**************** USB_COUNT6_TX_1 寄存器的位定义 **************/
#define  USB_COUNT6_TX_1_COUNT6_TX_1         ((uint32_t)0x03FF0000)        /*!< 发送字节数 6（高字节） */

/**************** USB_COUNT7_TX_0 寄存器的位定义 **************/
#define  USB_COUNT7_TX_0_COUNT7_TX_0         ((uint32_t)0x000003FF)        /*!< 发送字节数 7（低字节） */

/**************** USB_COUNT7_TX_1 寄存器的位定义 **************/
#define  USB_COUNT7_TX_1_COUNT7_TX_1         ((uint32_t)0x03FF0000)        /*!< 发送字节数 7（高字节） */

/*----------------------------------------------------------------------------*/

/***************** USB_ADDR0_RX 寄存器的位定义 ***************/
#define  USB_ADDR0_RX_ADDR0_RX               ((uint16_t)0xFFFE)            /*!< 接收缓冲区地址 0 */

/***************** USB_ADDR1_RX 寄存器的位定义 ***************/
#define  USB_ADDR1_RX_ADDR1_RX               ((uint16_t)0xFFFE)            /*!< 接收缓冲区地址 1 */

/***************** USB_ADDR2_RX 寄存器的位定义 ***************/
#define  USB_ADDR2_RX_ADDR2_RX               ((uint16_t)0xFFFE)            /*!< 接收缓冲区地址 2 */

/***************** USB_ADDR3_RX 寄存器的位定义 ***************/
#define  USB_ADDR3_RX_ADDR3_RX               ((uint16_t)0xFFFE)            /*!< 接收缓冲区地址 3 */

/***************** USB_ADDR4_RX 寄存器的位定义 ***************/
#define  USB_ADDR4_RX_ADDR4_RX               ((uint16_t)0xFFFE)            /*!< 接收缓冲区地址 4 */

/***************** USB_ADDR5_RX 寄存器的位定义 ***************/
#define  USB_ADDR5_RX_ADDR5_RX               ((uint16_t)0xFFFE)            /*!< 接收缓冲区地址 5 */

/***************** USB_ADDR6_RX 寄存器的位定义 ***************/
#define  USB_ADDR6_RX_ADDR6_RX               ((uint16_t)0xFFFE)            /*!< 接收缓冲区地址 6 */

/***************** USB_ADDR7_RX 寄存器的位定义 ***************/
#define  USB_ADDR7_RX_ADDR7_RX               ((uint16_t)0xFFFE)            /*!< 接收缓冲区地址 7 */

/*----------------------------------------------------------------------------*/

/***************** USB_COUNT0_RX 寄存器的位定义 ***************/
#define  USB_COUNT0_RX_COUNT0_RX             ((uint16_t)0x03FF)            /*!< 接收字节数 */

#define  USB_COUNT0_RX_NUM_BLOCK             ((uint16_t)0x7C00)            /*!< NUM_BLOCK[4:0] 位（块数量） */
#define  USB_COUNT0_RX_NUM_BLOCK_0           ((uint16_t)0x0400)            /*!< 位 0 */
#define  USB_COUNT0_RX_NUM_BLOCK_1           ((uint16_t)0x0800)            /*!< 位 1 */
#define  USB_COUNT0_RX_NUM_BLOCK_2           ((uint16_t)0x1000)            /*!< 位 2 */
#define  USB_COUNT0_RX_NUM_BLOCK_3           ((uint16_t)0x2000)            /*!< 位 3 */
#define  USB_COUNT0_RX_NUM_BLOCK_4           ((uint16_t)0x4000)            /*!< 位 4 */

#define  USB_COUNT0_RX_BLSIZE                ((uint16_t)0x8000)            /*!< 块大小 */

/***************** USB_COUNT1_RX 寄存器的位定义 ***************/
#define  USB_COUNT1_RX_COUNT1_RX             ((uint16_t)0x03FF)            /*!< 接收字节数 */

#define  USB_COUNT1_RX_NUM_BLOCK             ((uint16_t)0x7C00)            /*!< NUM_BLOCK[4:0] 位（块数量） */
#define  USB_COUNT1_RX_NUM_BLOCK_0           ((uint16_t)0x0400)            /*!< 位 0 */
#define  USB_COUNT1_RX_NUM_BLOCK_1           ((uint16_t)0x0800)            /*!< 位 1 */
#define  USB_COUNT1_RX_NUM_BLOCK_2           ((uint16_t)0x1000)            /*!< 位 2 */
#define  USB_COUNT1_RX_NUM_BLOCK_3           ((uint16_t)0x2000)            /*!< 位 3 */
#define  USB_COUNT1_RX_NUM_BLOCK_4           ((uint16_t)0x4000)            /*!< 位 4 */

#define  USB_COUNT1_RX_BLSIZE                ((uint16_t)0x8000)            /*!< 块大小 */

/***************** USB_COUNT2_RX 寄存器的位定义 ***************/
#define  USB_COUNT2_RX_COUNT2_RX             ((uint16_t)0x03FF)            /*!< 接收字节数 */

#define  USB_COUNT2_RX_NUM_BLOCK             ((uint16_t)0x7C00)            /*!< NUM_BLOCK[4:0] 位（块数量） */
#define  USB_COUNT2_RX_NUM_BLOCK_0           ((uint16_t)0x0400)            /*!< 位 0 */
#define  USB_COUNT2_RX_NUM_BLOCK_1           ((uint16_t)0x0800)            /*!< 位 1 */
#define  USB_COUNT2_RX_NUM_BLOCK_2           ((uint16_t)0x1000)            /*!< 位 2 */
#define  USB_COUNT2_RX_NUM_BLOCK_3           ((uint16_t)0x2000)            /*!< 位 3 */
#define  USB_COUNT2_RX_NUM_BLOCK_4           ((uint16_t)0x4000)            /*!< 位 4 */

#define  USB_COUNT2_RX_BLSIZE                ((uint16_t)0x8000)            /*!< 块大小 */

/***************** USB_COUNT3_RX 寄存器的位定义 ***************/
#define  USB_COUNT3_RX_COUNT3_RX             ((uint16_t)0x03FF)            /*!< 接收字节数 */

#define  USB_COUNT3_RX_NUM_BLOCK             ((uint16_t)0x7C00)            /*!< NUM_BLOCK[4:0] 位（块数量） */
#define  USB_COUNT3_RX_NUM_BLOCK_0           ((uint16_t)0x0400)            /*!< 位 0 */
#define  USB_COUNT3_RX_NUM_BLOCK_1           ((uint16_t)0x0800)            /*!< 位 1 */
#define  USB_COUNT3_RX_NUM_BLOCK_2           ((uint16_t)0x1000)            /*!< 位 2 */
#define  USB_COUNT3_RX_NUM_BLOCK_3           ((uint16_t)0x2000)            /*!< 位 3 */
#define  USB_COUNT3_RX_NUM_BLOCK_4           ((uint16_t)0x4000)            /*!< 位 4 */

#define  USB_COUNT3_RX_BLSIZE                ((uint16_t)0x8000)            /*!< 块大小 */

/***************** USB_COUNT4_RX 寄存器的位定义 ***************/
#define  USB_COUNT4_RX_COUNT4_RX             ((uint16_t)0x03FF)            /*!< 接收字节数 */

#define  USB_COUNT4_RX_NUM_BLOCK             ((uint16_t)0x7C00)            /*!< NUM_BLOCK[4:0] 位（块数量） */
#define  USB_COUNT4_RX_NUM_BLOCK_0           ((uint16_t)0x0400)            /*!< 位 0 */
#define  USB_COUNT4_RX_NUM_BLOCK_1           ((uint16_t)0x0800)            /*!< 位 1 */
#define  USB_COUNT4_RX_NUM_BLOCK_2           ((uint16_t)0x1000)            /*!< 位 2 */
#define  USB_COUNT4_RX_NUM_BLOCK_3           ((uint16_t)0x2000)            /*!< 位 3 */
#define  USB_COUNT4_RX_NUM_BLOCK_4           ((uint16_t)0x4000)            /*!< 位 4 */

#define  USB_COUNT4_RX_BLSIZE                ((uint16_t)0x8000)            /*!< 块大小 */

/***************** USB_COUNT5_RX 寄存器的位定义 ***************/
#define  USB_COUNT5_RX_COUNT5_RX             ((uint16_t)0x03FF)            /*!< 接收字节数 */

#define  USB_COUNT5_RX_NUM_BLOCK             ((uint16_t)0x7C00)            /*!< NUM_BLOCK[4:0] 位（块数量） */
#define  USB_COUNT5_RX_NUM_BLOCK_0           ((uint16_t)0x0400)            /*!< 位 0 */
#define  USB_COUNT5_RX_NUM_BLOCK_1           ((uint16_t)0x0800)            /*!< 位 1 */
#define  USB_COUNT5_RX_NUM_BLOCK_2           ((uint16_t)0x1000)            /*!< 位 2 */
#define  USB_COUNT5_RX_NUM_BLOCK_3           ((uint16_t)0x2000)            /*!< 位 3 */
#define  USB_COUNT5_RX_NUM_BLOCK_4           ((uint16_t)0x4000)            /*!< 位 4 */

#define  USB_COUNT5_RX_BLSIZE                ((uint16_t)0x8000)            /*!< 块大小 */

/***************** USB_COUNT6_RX 寄存器的位定义 ***************/
#define  USB_COUNT6_RX_COUNT6_RX             ((uint16_t)0x03FF)            /*!< 接收字节数 */

#define  USB_COUNT6_RX_NUM_BLOCK             ((uint16_t)0x7C00)            /*!< NUM_BLOCK[4:0] 位（块数量） */
#define  USB_COUNT6_RX_NUM_BLOCK_0           ((uint16_t)0x0400)            /*!< 位 0 */
#define  USB_COUNT6_RX_NUM_BLOCK_1           ((uint16_t)0x0800)            /*!< 位 1 */
#define  USB_COUNT6_RX_NUM_BLOCK_2           ((uint16_t)0x1000)            /*!< 位 2 */
#define  USB_COUNT6_RX_NUM_BLOCK_3           ((uint16_t)0x2000)            /*!< 位 3 */
#define  USB_COUNT6_RX_NUM_BLOCK_4           ((uint16_t)0x4000)            /*!< 位 4 */

#define  USB_COUNT6_RX_BLSIZE                ((uint16_t)0x8000)            /*!< 块大小 */

/***************** USB_COUNT7_RX 寄存器的位定义 ***************/
#define  USB_COUNT7_RX_COUNT7_RX             ((uint16_t)0x03FF)            /*!< 接收字节数 */

#define  USB_COUNT7_RX_NUM_BLOCK             ((uint16_t)0x7C00)            /*!< NUM_BLOCK[4:0] 位（块数量） */
#define  USB_COUNT7_RX_NUM_BLOCK_0           ((uint16_t)0x0400)            /*!< 位 0 */
#define  USB_COUNT7_RX_NUM_BLOCK_1           ((uint16_t)0x0800)            /*!< 位 1 */
#define  USB_COUNT7_RX_NUM_BLOCK_2           ((uint16_t)0x1000)            /*!< 位 2 */
#define  USB_COUNT7_RX_NUM_BLOCK_3           ((uint16_t)0x2000)            /*!< 位 3 */
#define  USB_COUNT7_RX_NUM_BLOCK_4           ((uint16_t)0x4000)            /*!< 位 4 */

#define  USB_COUNT7_RX_BLSIZE                ((uint16_t)0x8000)            /*!< 块大小 */

/*----------------------------------------------------------------------------*/

/**************** USB_COUNT0_RX_0 寄存器的位定义 **************/
#define  USB_COUNT0_RX_0_COUNT0_RX_0         ((uint32_t)0x000003FF)        /*!< 接收字节数（低字节） */

#define  USB_COUNT0_RX_0_NUM_BLOCK_0         ((uint32_t)0x00007C00)        /*!< NUM_BLOCK_0[4:0] 位（块数量）（低字节） */
#define  USB_COUNT0_RX_0_NUM_BLOCK_0_0       ((uint32_t)0x00000400)        /*!< 位 0 */
#define  USB_COUNT0_RX_0_NUM_BLOCK_0_1       ((uint32_t)0x00000800)        /*!< 位 1 */
#define  USB_COUNT0_RX_0_NUM_BLOCK_0_2       ((uint32_t)0x00001000)        /*!< 位 2 */
#define  USB_COUNT0_RX_0_NUM_BLOCK_0_3       ((uint32_t)0x00002000)        /*!< 位 3 */
#define  USB_COUNT0_RX_0_NUM_BLOCK_0_4       ((uint32_t)0x00004000)        /*!< 位 4 */

#define  USB_COUNT0_RX_0_BLSIZE_0            ((uint32_t)0x00008000)        /*!< 块大小（低字节） */

/**************** USB_COUNT0_RX_1 寄存器的位定义 **************/
#define  USB_COUNT0_RX_1_COUNT0_RX_1         ((uint32_t)0x03FF0000)        /*!< 接收字节数（高字节） */

#define  USB_COUNT0_RX_1_NUM_BLOCK_1         ((uint32_t)0x7C000000)        /*!< NUM_BLOCK_1[4:0] 位（块数量）（高字节） */
#define  USB_COUNT0_RX_1_NUM_BLOCK_1_0       ((uint32_t)0x04000000)        /*!< 位 1 */
#define  USB_COUNT0_RX_1_NUM_BLOCK_1_1       ((uint32_t)0x08000000)        /*!< 位 1 */
#define  USB_COUNT0_RX_1_NUM_BLOCK_1_2       ((uint32_t)0x10000000)        /*!< 位 2 */
#define  USB_COUNT0_RX_1_NUM_BLOCK_1_3       ((uint32_t)0x20000000)        /*!< 位 3 */
#define  USB_COUNT0_RX_1_NUM_BLOCK_1_4       ((uint32_t)0x40000000)        /*!< 位 4 */

#define  USB_COUNT0_RX_1_BLSIZE_1            ((uint32_t)0x80000000)        /*!< 块大小（高字节） */

/**************** USB_COUNT1_RX_0 寄存器的位定义 **************/
#define  USB_COUNT1_RX_0_COUNT1_RX_0         ((uint32_t)0x000003FF)        /*!< 接收字节数（低字节） */

#define  USB_COUNT1_RX_0_NUM_BLOCK_0         ((uint32_t)0x00007C00)        /*!< NUM_BLOCK_0[4:0] 位（块数量）（低字节） */
#define  USB_COUNT1_RX_0_NUM_BLOCK_0_0       ((uint32_t)0x00000400)        /*!< 位 0 */
#define  USB_COUNT1_RX_0_NUM_BLOCK_0_1       ((uint32_t)0x00000800)        /*!< 位 1 */
#define  USB_COUNT1_RX_0_NUM_BLOCK_0_2       ((uint32_t)0x00001000)        /*!< 位 2 */
#define  USB_COUNT1_RX_0_NUM_BLOCK_0_3       ((uint32_t)0x00002000)        /*!< 位 3 */
#define  USB_COUNT1_RX_0_NUM_BLOCK_0_4       ((uint32_t)0x00004000)        /*!< 位 4 */

#define  USB_COUNT1_RX_0_BLSIZE_0            ((uint32_t)0x00008000)        /*!< 块大小（低字节） */

/**************** USB_COUNT1_RX_1 寄存器的位定义 **************/
#define  USB_COUNT1_RX_1_COUNT1_RX_1         ((uint32_t)0x03FF0000)        /*!< 接收字节数（高字节） */

#define  USB_COUNT1_RX_1_NUM_BLOCK_1         ((uint32_t)0x7C000000)        /*!< NUM_BLOCK_1[4:0] 位（块数量）（高字节） */
#define  USB_COUNT1_RX_1_NUM_BLOCK_1_0       ((uint32_t)0x04000000)        /*!< 位 0 */
#define  USB_COUNT1_RX_1_NUM_BLOCK_1_1       ((uint32_t)0x08000000)        /*!< 位 1 */
#define  USB_COUNT1_RX_1_NUM_BLOCK_1_2       ((uint32_t)0x10000000)        /*!< 位 2 */
#define  USB_COUNT1_RX_1_NUM_BLOCK_1_3       ((uint32_t)0x20000000)        /*!< 位 3 */
#define  USB_COUNT1_RX_1_NUM_BLOCK_1_4       ((uint32_t)0x40000000)        /*!< 位 4 */

#define  USB_COUNT1_RX_1_BLSIZE_1            ((uint32_t)0x80000000)        /*!< 块大小（高字节） */

/**************** USB_COUNT2_RX_0 寄存器的位定义 **************/
#define  USB_COUNT2_RX_0_COUNT2_RX_0         ((uint32_t)0x000003FF)        /*!< 接收字节数（低字节） */

#define  USB_COUNT2_RX_0_NUM_BLOCK_0         ((uint32_t)0x00007C00)        /*!< NUM_BLOCK_0[4:0] 位（块数量）（低字节） */
#define  USB_COUNT2_RX_0_NUM_BLOCK_0_0       ((uint32_t)0x00000400)        /*!< 位 0 */
#define  USB_COUNT2_RX_0_NUM_BLOCK_0_1       ((uint32_t)0x00000800)        /*!< 位 1 */
#define  USB_COUNT2_RX_0_NUM_BLOCK_0_2       ((uint32_t)0x00001000)        /*!< 位 2 */
#define  USB_COUNT2_RX_0_NUM_BLOCK_0_3       ((uint32_t)0x00002000)        /*!< 位 3 */
#define  USB_COUNT2_RX_0_NUM_BLOCK_0_4       ((uint32_t)0x00004000)        /*!< 位 4 */

#define  USB_COUNT2_RX_0_BLSIZE_0            ((uint32_t)0x00008000)        /*!< 块大小（低字节） */

/**************** USB_COUNT2_RX_1 寄存器的位定义 **************/
#define  USB_COUNT2_RX_1_COUNT2_RX_1         ((uint32_t)0x03FF0000)        /*!< 接收字节数（高字节） */

#define  USB_COUNT2_RX_1_NUM_BLOCK_1         ((uint32_t)0x7C000000)        /*!< NUM_BLOCK_1[4:0] 位（块数量）（高字节） */
#define  USB_COUNT2_RX_1_NUM_BLOCK_1_0       ((uint32_t)0x04000000)        /*!< 位 0 */
#define  USB_COUNT2_RX_1_NUM_BLOCK_1_1       ((uint32_t)0x08000000)        /*!< 位 1 */
#define  USB_COUNT2_RX_1_NUM_BLOCK_1_2       ((uint32_t)0x10000000)        /*!< 位 2 */
#define  USB_COUNT2_RX_1_NUM_BLOCK_1_3       ((uint32_t)0x20000000)        /*!< 位 3 */
#define  USB_COUNT2_RX_1_NUM_BLOCK_1_4       ((uint32_t)0x40000000)        /*!< 位 4 */

#define  USB_COUNT2_RX_1_BLSIZE_1            ((uint32_t)0x80000000)        /*!< 块大小（高字节） */

/**************** USB_COUNT3_RX_0 寄存器的位定义 **************/
#define  USB_COUNT3_RX_0_COUNT3_RX_0         ((uint32_t)0x000003FF)        /*!< 接收字节数（低字节） */

#define  USB_COUNT3_RX_0_NUM_BLOCK_0         ((uint32_t)0x00007C00)        /*!< NUM_BLOCK_0[4:0] 位（块数量）（低字节） */
#define  USB_COUNT3_RX_0_NUM_BLOCK_0_0       ((uint32_t)0x00000400)        /*!< 位 0 */
#define  USB_COUNT3_RX_0_NUM_BLOCK_0_1       ((uint32_t)0x00000800)        /*!< 位 1 */
#define  USB_COUNT3_RX_0_NUM_BLOCK_0_2       ((uint32_t)0x00001000)        /*!< 位 2 */
#define  USB_COUNT3_RX_0_NUM_BLOCK_0_3       ((uint32_t)0x00002000)        /*!< 位 3 */
#define  USB_COUNT3_RX_0_NUM_BLOCK_0_4       ((uint32_t)0x00004000)        /*!< 位 4 */

#define  USB_COUNT3_RX_0_BLSIZE_0            ((uint32_t)0x00008000)        /*!< 块大小（低字节） */

/**************** USB_COUNT3_RX_1 寄存器的位定义 **************/
#define  USB_COUNT3_RX_1_COUNT3_RX_1         ((uint32_t)0x03FF0000)        /*!< 接收字节数（高字节） */

#define  USB_COUNT3_RX_1_NUM_BLOCK_1         ((uint32_t)0x7C000000)        /*!< NUM_BLOCK_1[4:0] 位（块数量）（高字节） */
#define  USB_COUNT3_RX_1_NUM_BLOCK_1_0       ((uint32_t)0x04000000)        /*!< 位 0 */
#define  USB_COUNT3_RX_1_NUM_BLOCK_1_1       ((uint32_t)0x08000000)        /*!< 位 1 */
#define  USB_COUNT3_RX_1_NUM_BLOCK_1_2       ((uint32_t)0x10000000)        /*!< 位 2 */
#define  USB_COUNT3_RX_1_NUM_BLOCK_1_3       ((uint32_t)0x20000000)        /*!< 位 3 */
#define  USB_COUNT3_RX_1_NUM_BLOCK_1_4       ((uint32_t)0x40000000)        /*!< 位 4 */

#define  USB_COUNT3_RX_1_BLSIZE_1            ((uint32_t)0x80000000)        /*!< 块大小（高字节） */

/**************** USB_COUNT4_RX_0 寄存器的位定义 **************/
#define  USB_COUNT4_RX_0_COUNT4_RX_0         ((uint32_t)0x000003FF)        /*!< 接收字节数（低字节） */

#define  USB_COUNT4_RX_0_NUM_BLOCK_0         ((uint32_t)0x00007C00)        /*!< NUM_BLOCK_0[4:0] 位（块数量）（低字节） */
#define  USB_COUNT4_RX_0_NUM_BLOCK_0_0      ((uint32_t)0x00000400)        /*!< 位 0 */
#define  USB_COUNT4_RX_0_NUM_BLOCK_0_1      ((uint32_t)0x00000800)        /*!< 位 1 */
#define  USB_COUNT4_RX_0_NUM_BLOCK_0_2      ((uint32_t)0x00001000)        /*!< 位 2 */
#define  USB_COUNT4_RX_0_NUM_BLOCK_0_3      ((uint32_t)0x00002000)        /*!< 位 3 */
#define  USB_COUNT4_RX_0_NUM_BLOCK_0_4      ((uint32_t)0x00004000)        /*!< 位 4 */

#define  USB_COUNT4_RX_0_BLSIZE_0            ((uint32_t)0x00008000)        /*!< 块大小（低字节） */

/**************** USB_COUNT4_RX_1 寄存器的位定义 **************/
#define  USB_COUNT4_RX_1_COUNT4_RX_1         ((uint32_t)0x03FF0000)        /*!< 接收字节数（高字节） */

#define  USB_COUNT4_RX_1_NUM_BLOCK_1         ((uint32_t)0x7C000000)        /*!< NUM_BLOCK_1[4:0] 位（块数量）（高字节） */
#define  USB_COUNT4_RX_1_NUM_BLOCK_1_0       ((uint32_t)0x04000000)        /*!< 位 0 */
#define  USB_COUNT4_RX_1_NUM_BLOCK_1_1       ((uint32_t)0x08000000)        /*!< 位 1 */
#define  USB_COUNT4_RX_1_NUM_BLOCK_1_2       ((uint32_t)0x10000000)        /*!< 位 2 */
#define  USB_COUNT4_RX_1_NUM_BLOCK_1_3       ((uint32_t)0x20000000)        /*!< 位 3 */
#define  USB_COUNT4_RX_1_NUM_BLOCK_1_4       ((uint32_t)0x40000000)        /*!< 位 4 */

#define  USB_COUNT4_RX_1_BLSIZE_1            ((uint32_t)0x80000000)        /*!< 块大小（高字节） */

/**************** USB_COUNT5_RX_0 寄存器的位定义 **************/
#define  USB_COUNT5_RX_0_COUNT5_RX_0         ((uint32_t)0x000003FF)        /*!< 接收字节数（低字节） */

#define  USB_COUNT5_RX_0_NUM_BLOCK_0         ((uint32_t)0x00007C00)        /*!< NUM_BLOCK_0[4:0] 位（块数量）（低字节） */
#define  USB_COUNT5_RX_0_NUM_BLOCK_0_0       ((uint32_t)0x00000400)        /*!< 位 0 */
#define  USB_COUNT5_RX_0_NUM_BLOCK_0_1       ((uint32_t)0x00000800)        /*!< 位 1 */
#define  USB_COUNT5_RX_0_NUM_BLOCK_0_2       ((uint32_t)0x00001000)        /*!< 位 2 */
#define  USB_COUNT5_RX_0_NUM_BLOCK_0_3       ((uint32_t)0x00002000)        /*!< 位 3 */
#define  USB_COUNT5_RX_0_NUM_BLOCK_0_4       ((uint32_t)0x00004000)        /*!< 位 4 */

#define  USB_COUNT5_RX_0_BLSIZE_0            ((uint32_t)0x00008000)        /*!< 块大小（低字节） */

/**************** USB_COUNT5_RX_1 寄存器的位定义 **************/
#define  USB_COUNT5_RX_1_COUNT5_RX_1         ((uint32_t)0x03FF0000)        /*!< 接收字节数（高字节） */

#define  USB_COUNT5_RX_1_NUM_BLOCK_1         ((uint32_t)0x7C000000)        /*!< NUM_BLOCK_1[4:0] 位（块数量）（高字节） */
#define  USB_COUNT5_RX_1_NUM_BLOCK_1_0       ((uint32_t)0x04000000)        /*!< 位 0 */
#define  USB_COUNT5_RX_1_NUM_BLOCK_1_1       ((uint32_t)0x08000000)        /*!< 位 1 */
#define  USB_COUNT5_RX_1_NUM_BLOCK_1_2       ((uint32_t)0x10000000)        /*!< 位 2 */
#define  USB_COUNT5_RX_1_NUM_BLOCK_1_3       ((uint32_t)0x20000000)        /*!< 位 3 */
#define  USB_COUNT5_RX_1_NUM_BLOCK_1_4       ((uint32_t)0x40000000)        /*!< 位 4 */

#define  USB_COUNT5_RX_1_BLSIZE_1            ((uint32_t)0x80000000)        /*!< 块大小（高字节） */

/*************** USB_COUNT6_RX_0  寄存器的位定义 *************/
#define  USB_COUNT6_RX_0_COUNT6_RX_0         ((uint32_t)0x000003FF)        /*!< 接收字节数（低字节） */

#define  USB_COUNT6_RX_0_NUM_BLOCK_0         ((uint32_t)0x00007C00)        /*!< NUM_BLOCK_0[4:0] 位（块数量）（低字节） */
#define  USB_COUNT6_RX_0_NUM_BLOCK_0_0       ((uint32_t)0x00000400)        /*!< 位 0 */
#define  USB_COUNT6_RX_0_NUM_BLOCK_0_1       ((uint32_t)0x00000800)        /*!< 位 1 */
#define  USB_COUNT6_RX_0_NUM_BLOCK_0_2       ((uint32_t)0x00001000)        /*!< 位 2 */
#define  USB_COUNT6_RX_0_NUM_BLOCK_0_3       ((uint32_t)0x00002000)        /*!< 位 3 */
#define  USB_COUNT6_RX_0_NUM_BLOCK_0_4       ((uint32_t)0x00004000)        /*!< 位 4 */

#define  USB_COUNT6_RX_0_BLSIZE_0            ((uint32_t)0x00008000)        /*!< 块大小（低字节） */

/**************** USB_COUNT6_RX_1 寄存器的位定义 **************/
#define  USB_COUNT6_RX_1_COUNT6_RX_1         ((uint32_t)0x03FF0000)        /*!< 接收字节数（高字节） */

#define  USB_COUNT6_RX_1_NUM_BLOCK_1         ((uint32_t)0x7C000000)        /*!< NUM_BLOCK_1[4:0] 位（块数量）（高字节） */
#define  USB_COUNT6_RX_1_NUM_BLOCK_1_0       ((uint32_t)0x04000000)        /*!< 位 0 */
#define  USB_COUNT6_RX_1_NUM_BLOCK_1_1       ((uint32_t)0x08000000)        /*!< 位 1 */
#define  USB_COUNT6_RX_1_NUM_BLOCK_1_2       ((uint32_t)0x10000000)        /*!< 位 2 */
#define  USB_COUNT6_RX_1_NUM_BLOCK_1_3       ((uint32_t)0x20000000)        /*!< 位 3 */
#define  USB_COUNT6_RX_1_NUM_BLOCK_1_4       ((uint32_t)0x40000000)        /*!< 位 4 */

#define  USB_COUNT6_RX_1_BLSIZE_1            ((uint32_t)0x80000000)        /*!< 块大小（高字节） */

/*************** USB_COUNT7_RX_0 寄存器的位定义 *************/
#define  USB_COUNT7_RX_0_COUNT7_RX_0         ((uint32_t)0x000003FF)        /*!< 接收字节数（低字节） */

#define  USB_COUNT7_RX_0_NUM_BLOCK_0         ((uint32_t)0x00007C00)        /*!< NUM_BLOCK_0[4:0] 位（块数量）（低字节） */
#define  USB_COUNT7_RX_0_NUM_BLOCK_0_0       ((uint32_t)0x00000400)        /*!< 位 0 */
#define  USB_COUNT7_RX_0_NUM_BLOCK_0_1       ((uint32_t)0x00000800)        /*!< 位 1 */
#define  USB_COUNT7_RX_0_NUM_BLOCK_0_2       ((uint32_t)0x00001000)        /*!< 位 2 */
#define  USB_COUNT7_RX_0_NUM_BLOCK_0_3       ((uint32_t)0x00002000)        /*!< 位 3 */
#define  USB_COUNT7_RX_0_NUM_BLOCK_0_4       ((uint32_t)0x00004000)        /*!< 位 4 */

#define  USB_COUNT7_RX_0_BLSIZE_0            ((uint32_t)0x00008000)        /*!< 块大小（低字节） */

/*************** USB_COUNT7_RX_1 寄存器的位定义 *************/
#define  USB_COUNT7_RX_1_COUNT7_RX_1         ((uint32_t)0x03FF0000)        /*!< 接收字节数（高字节） */

#define  USB_COUNT7_RX_1_NUM_BLOCK_1         ((uint32_t)0x7C000000)        /*!< NUM_BLOCK_1[4:0] 位（块数量）（高字节） */
#define  USB_COUNT7_RX_1_NUM_BLOCK_1_0       ((uint32_t)0x04000000)        /*!< 位 0 */
#define  USB_COUNT7_RX_1_NUM_BLOCK_1_1       ((uint32_t)0x08000000)        /*!< 位 1 */
#define  USB_COUNT7_RX_1_NUM_BLOCK_1_2       ((uint32_t)0x10000000)        /*!< 位 2 */
#define  USB_COUNT7_RX_1_NUM_BLOCK_1_3       ((uint32_t)0x20000000)        /*!< 位 3 */
#define  USB_COUNT7_RX_1_NUM_BLOCK_1_4       ((uint32_t)0x40000000)        /*!< 位 4 */

#define  USB_COUNT7_RX_1_BLSIZE_1            ((uint32_t)0x80000000)        /*!< 块大小（高字节） */

/******************************************************************************/
/*                                                                            */
/*                         控制器局域网                            */
/*                                                                            */
/******************************************************************************/

/*!< CAN 控制和状态寄存器 */
/******************* CAN_MCR 寄存器的位定义 *****************/
#define  CAN_MCR_INRQ                        ((uint16_t)0x0001)            /*!< 初始化请求 */
#define  CAN_MCR_SLEEP                       ((uint16_t)0x0002)            /*!< 睡眠模式请求 */
#define  CAN_MCR_TXFP                        ((uint16_t)0x0004)            /*!< 发送 FIFO 优先级 */
#define  CAN_MCR_RFLM                        ((uint16_t)0x0008)            /*!< 接收 FIFO 锁定模式 */
#define  CAN_MCR_NART                        ((uint16_t)0x0010)            /*!< 禁止自动重传 */
#define  CAN_MCR_AWUM                        ((uint16_t)0x0020)            /*!< 自动唤醒模式 */
#define  CAN_MCR_ABOM                        ((uint16_t)0x0040)            /*!< 自动总线关闭管理 */
#define  CAN_MCR_TTCM                        ((uint16_t)0x0080)            /*!< 时间触发通信模式 */
#define  CAN_MCR_RESET                       ((uint16_t)0x8000)            /*!< CAN 软件主复位 */

/******************* CAN_MSR 寄存器的位定义 *****************/
#define  CAN_MSR_INAK                        ((uint16_t)0x0001)            /*!< 初始化确认 */
#define  CAN_MSR_SLAK                        ((uint16_t)0x0002)            /*!< 睡眠确认 */
#define  CAN_MSR_ERRI                        ((uint16_t)0x0004)            /*!< 错误中断 */
#define  CAN_MSR_WKUI                        ((uint16_t)0x0008)            /*!< 唤醒中断 */
#define  CAN_MSR_SLAKI                       ((uint16_t)0x0010)            /*!< 睡眠确认中断 */
#define  CAN_MSR_TXM                         ((uint16_t)0x0100)            /*!< 发送模式 */
#define  CAN_MSR_RXM                         ((uint16_t)0x0200)            /*!< 接收模式 */
#define  CAN_MSR_SAMP                        ((uint16_t)0x0400)            /*!< 最后采样点 */
#define  CAN_MSR_RX                          ((uint16_t)0x0800)            /*!< CAN 接收信号 */

/******************* CAN_TSR 寄存器的位定义 *****************/
#define  CAN_TSR_RQCP0                       ((uint32_t)0x00000001)        /*!< 邮箱 0 请求完成 */
#define  CAN_TSR_TXOK0                       ((uint32_t)0x00000002)        /*!< 邮箱 0 发送成功 */
#define  CAN_TSR_ALST0                       ((uint32_t)0x00000004)        /*!< 邮箱 0 仲裁丢失 */
#define  CAN_TSR_TERR0                       ((uint32_t)0x00000008)        /*!< 邮箱 0 发送错误 */
#define  CAN_TSR_ABRQ0                       ((uint32_t)0x00000080)        /*!< 邮箱 0 中止请求 */
#define  CAN_TSR_RQCP1                       ((uint32_t)0x00000100)        /*!< 邮箱 1 请求完成 */
#define  CAN_TSR_TXOK1                       ((uint32_t)0x00000200)        /*!< 邮箱 1 发送成功 */
#define  CAN_TSR_ALST1                       ((uint32_t)0x00000400)        /*!< 邮箱 1 仲裁丢失 */
#define  CAN_TSR_TERR1                       ((uint32_t)0x00000800)        /*!< 邮箱 1 发送错误 */
#define  CAN_TSR_ABRQ1                       ((uint32_t)0x00008000)        /*!< 邮箱 1 中止请求 */
#define  CAN_TSR_RQCP2                       ((uint32_t)0x00010000)        /*!< 邮箱 2 请求完成 */
#define  CAN_TSR_TXOK2                       ((uint32_t)0x00020000)        /*!< 邮箱 2 发送成功 */
#define  CAN_TSR_ALST2                       ((uint32_t)0x00040000)        /*!< 邮箱 2 仲裁丢失 */
#define  CAN_TSR_TERR2                       ((uint32_t)0x00080000)        /*!< 邮箱 2 发送错误 */
#define  CAN_TSR_ABRQ2                       ((uint32_t)0x00800000)        /*!< 邮箱 2 中止请求 */
#define  CAN_TSR_CODE                        ((uint32_t)0x03000000)        /*!< 邮箱代码 */

#define  CAN_TSR_TME                         ((uint32_t)0x1C000000)        /*!< TME[2:0] 位 */
#define  CAN_TSR_TME0                        ((uint32_t)0x04000000)        /*!< 发送邮箱 0 空 */
#define  CAN_TSR_TME1                        ((uint32_t)0x08000000)        /*!< 发送邮箱 1 空 */
#define  CAN_TSR_TME2                        ((uint32_t)0x10000000)        /*!< 发送邮箱 2 空 */

#define  CAN_TSR_LOW                         ((uint32_t)0xE0000000)        /*!< LOW[2:0] 位 */
#define  CAN_TSR_LOW0                        ((uint32_t)0x20000000)        /*!< 邮箱 0 的最低优先级标志位 */
#define  CAN_TSR_LOW1                        ((uint32_t)0x40000000)        /*!< 邮箱 1 的最低优先级标志位 */
#define  CAN_TSR_LOW2                        ((uint32_t)0x80000000)        /*!< 邮箱 2 的最低优先级标志位 */

/******************* CAN_RF0R 寄存器的位定义 *****************/
#define  CAN_RF0R_FMP0                       ((uint8_t)0x03)               /*!< FIFO 0 报文挂起 */
#define  CAN_RF0R_FULL0                      ((uint8_t)0x08)               /*!< FIFO 0 满 */
#define  CAN_RF0R_FOVR0                      ((uint8_t)0x10)               /*!< FIFO 0 上溢 */
#define  CAN_RF0R_RFOM0                      ((uint8_t)0x20)               /*!< 释放 FIFO 0 输出邮箱 */

/******************* CAN_RF1R 寄存器的位定义 *****************/
#define  CAN_RF1R_FMP1                       ((uint8_t)0x03)               /*!< FIFO 1 报文挂起 */
#define  CAN_RF1R_FULL1                      ((uint8_t)0x08)               /*!< FIFO 1 满 */
#define  CAN_RF1R_FOVR1                      ((uint8_t)0x10)               /*!< FIFO 1 上溢 */
#define  CAN_RF1R_RFOM1                      ((uint8_t)0x20)               /*!< 释放 FIFO 1 输出邮箱 */

/******************** CAN_IER 寄存器的位定义 ******************/
#define  CAN_IER_TMEIE                       ((uint32_t)0x00000001)        /*!< 发送邮箱空中断使能 */
#define  CAN_IER_FMPIE0                      ((uint32_t)0x00000002)        /*!< FIFO 报文挂起中断使能 */
#define  CAN_IER_FFIE0                       ((uint32_t)0x00000004)        /*!< FIFO 满中断使能 */
#define  CAN_IER_FOVIE0                      ((uint32_t)0x00000008)        /*!< FIFO 上溢中断使能 */
#define  CAN_IER_FMPIE1                      ((uint32_t)0x00000010)        /*!< FIFO 报文挂起中断使能 */
#define  CAN_IER_FFIE1                       ((uint32_t)0x00000020)        /*!< FIFO 满中断使能 */
#define  CAN_IER_FOVIE1                      ((uint32_t)0x00000040)        /*!< FIFO 上溢中断使能 */
#define  CAN_IER_EWGIE                       ((uint32_t)0x00000100)        /*!< 错误警告中断使能 */
#define  CAN_IER_EPVIE                       ((uint32_t)0x00000200)        /*!< 错误被动中断使能 */
#define  CAN_IER_BOFIE                       ((uint32_t)0x00000400)        /*!< 总线关闭中断使能 */
#define  CAN_IER_LECIE                       ((uint32_t)0x00000800)        /*!< 最后错误代码中断使能 */
#define  CAN_IER_ERRIE                       ((uint32_t)0x00008000)        /*!< 错误中断使能 */
#define  CAN_IER_WKUIE                       ((uint32_t)0x00010000)        /*!< 唤醒中断使能 */
#define  CAN_IER_SLKIE                       ((uint32_t)0x00020000)        /*!< 睡眠中断使能 */

/******************** CAN_ESR 寄存器的位定义 ******************/
#define  CAN_ESR_EWGF                        ((uint32_t)0x00000001)        /*!< 错误警告标志位 */
#define  CAN_ESR_EPVF                        ((uint32_t)0x00000002)        /*!< 错误被动标志位 */
#define  CAN_ESR_BOFF                        ((uint32_t)0x00000004)        /*!< 总线关闭标志位 */

#define  CAN_ESR_LEC                         ((uint32_t)0x00000070)        /*!< LEC[2:0] 位（最后错误代码） */
#define  CAN_ESR_LEC_0                       ((uint32_t)0x00000010)        /*!< 位 0 */
#define  CAN_ESR_LEC_1                       ((uint32_t)0x00000020)        /*!< 位 1 */
#define  CAN_ESR_LEC_2                       ((uint32_t)0x00000040)        /*!< 位 2 */

#define  CAN_ESR_TEC                         ((uint32_t)0x00FF0000)        /*!< 9 位发送错误计数器的低字节 */
#define  CAN_ESR_REC                         ((uint32_t)0xFF000000)        /*!< 接收错误计数器 */

/******************* CAN_BTR 寄存器的位定义 *****************/
#define  CAN_BTR_BRP                         ((uint32_t)0x000003FF)        /*!< 波特率预分频 */
#define  CAN_BTR_TS1                         ((uint32_t)0x000F0000)        /*!< 时间段 1 */
#define  CAN_BTR_TS2                         ((uint32_t)0x00700000)        /*!< 时间段 2 */
#define  CAN_BTR_SJW                         ((uint32_t)0x03000000)        /*!< 重新同步跳变宽度 */
#define  CAN_BTR_LBKM                        ((uint32_t)0x40000000)        /*!< 回环模式（调试） */
#define  CAN_BTR_SILM                        ((uint32_t)0x80000000)        /*!< 静默模式 */

/*!< 邮箱寄存器 */
/****************** CAN_TI0R 寄存器的位定义 ****************/
#define  CAN_TI0R_TXRQ                       ((uint32_t)0x00000001)        /*!< 发送邮箱请求 */
#define  CAN_TI0R_RTR                        ((uint32_t)0x00000002)        /*!< 远程发送请求 */
#define  CAN_TI0R_IDE                        ((uint32_t)0x00000004)        /*!< 标识符扩展 */
#define  CAN_TI0R_EXID                       ((uint32_t)0x001FFFF8)        /*!< 扩展标识符 */
#define  CAN_TI0R_STID                       ((uint32_t)0xFFE00000)        /*!< 标准标识符或扩展标识符 */

/****************** CAN_TDT0R 寄存器的位定义 ****************/
#define  CAN_TDT0R_DLC                       ((uint32_t)0x0000000F)        /*!< 数据长度代码 */
#define  CAN_TDT0R_TGT                       ((uint32_t)0x00000100)        /*!< 发送全局时间 */
#define  CAN_TDT0R_TIME                      ((uint32_t)0xFFFF0000)        /*!< 报文时间戳 */

/****************** CAN_TDL0R 寄存器的位定义 ****************/
#define  CAN_TDL0R_DATA0                     ((uint32_t)0x000000FF)        /*!< 数据字节 0 */
#define  CAN_TDL0R_DATA1                     ((uint32_t)0x0000FF00)        /*!< 数据字节 1 */
#define  CAN_TDL0R_DATA2                     ((uint32_t)0x00FF0000)        /*!< 数据字节 2 */
#define  CAN_TDL0R_DATA3                     ((uint32_t)0xFF000000)        /*!< 数据字节 3 */

/****************** CAN_TDH0R 寄存器的位定义 ****************/
#define  CAN_TDH0R_DATA4                     ((uint32_t)0x000000FF)        /*!< 数据字节 4 */
#define  CAN_TDH0R_DATA5                     ((uint32_t)0x0000FF00)        /*!< 数据字节 5 */
#define  CAN_TDH0R_DATA6                     ((uint32_t)0x00FF0000)        /*!< 数据字节 6 */
#define  CAN_TDH0R_DATA7                     ((uint32_t)0xFF000000)        /*!< 数据字节 7 */

/******************* CAN_TI1R 寄存器的位定义 *****************/
#define  CAN_TI1R_TXRQ                       ((uint32_t)0x00000001)        /*!< 发送邮箱请求 */
#define  CAN_TI1R_RTR                        ((uint32_t)0x00000002)        /*!< 远程发送请求 */
#define  CAN_TI1R_IDE                        ((uint32_t)0x00000004)        /*!< 标识符扩展 */
#define  CAN_TI1R_EXID                       ((uint32_t)0x001FFFF8)        /*!< 扩展标识符 */
#define  CAN_TI1R_STID                       ((uint32_t)0xFFE00000)        /*!< 标准标识符或扩展标识符 */

/******************* CAN_TDT1R 寄存器的位定义 *****************/
#define  CAN_TDT1R_DLC                       ((uint32_t)0x0000000F)        /*!< 数据长度代码 */
#define  CAN_TDT1R_TGT                       ((uint32_t)0x00000100)        /*!< 发送全局时间 */
#define  CAN_TDT1R_TIME                      ((uint32_t)0xFFFF0000)        /*!< 报文时间戳 */

/******************* CAN_TDL1R 寄存器的位定义 *****************/
#define  CAN_TDL1R_DATA0                     ((uint32_t)0x000000FF)        /*!< 数据字节 0 */
#define  CAN_TDL1R_DATA1                     ((uint32_t)0x0000FF00)        /*!< 数据字节 1 */
#define  CAN_TDL1R_DATA2                     ((uint32_t)0x00FF0000)        /*!< 数据字节 2 */
#define  CAN_TDL1R_DATA3                     ((uint32_t)0xFF000000)        /*!< 数据字节 3 */

/******************* CAN_TDH1R 寄存器的位定义 *****************/
#define  CAN_TDH1R_DATA4                     ((uint32_t)0x000000FF)        /*!< 数据字节 4 */
#define  CAN_TDH1R_DATA5                     ((uint32_t)0x0000FF00)        /*!< 数据字节 5 */
#define  CAN_TDH1R_DATA6                     ((uint32_t)0x00FF0000)        /*!< 数据字节 6 */
#define  CAN_TDH1R_DATA7                     ((uint32_t)0xFF000000)        /*!< 数据字节 7 */

/******************* CAN_TI2R 寄存器的位定义 *****************/
#define  CAN_TI2R_TXRQ                       ((uint32_t)0x00000001)        /*!< 发送邮箱请求 */
#define  CAN_TI2R_RTR                        ((uint32_t)0x00000002)        /*!< 远程发送请求 */
#define  CAN_TI2R_IDE                        ((uint32_t)0x00000004)        /*!< 标识符扩展 */
#define  CAN_TI2R_EXID                       ((uint32_t)0x001FFFF8)        /*!< 扩展标识符 */
#define  CAN_TI2R_STID                       ((uint32_t)0xFFE00000)        /*!< 标准标识符或扩展标识符 */

/******************* CAN_TDT2R 寄存器的位定义 *****************/  
#define  CAN_TDT2R_DLC                       ((uint32_t)0x0000000F)        /*!< 数据长度代码 */
#define  CAN_TDT2R_TGT                       ((uint32_t)0x00000100)        /*!< 发送全局时间 */
#define  CAN_TDT2R_TIME                      ((uint32_t)0xFFFF0000)        /*!< 报文时间戳 */

/******************* CAN_TDL2R 寄存器的位定义 *****************/
#define  CAN_TDL2R_DATA0                     ((uint32_t)0x000000FF)        /*!< 数据字节 0 */
#define  CAN_TDL2R_DATA1                     ((uint32_t)0x0000FF00)        /*!< 数据字节 1 */
#define  CAN_TDL2R_DATA2                     ((uint32_t)0x00FF0000)        /*!< 数据字节 2 */
#define  CAN_TDL2R_DATA3                     ((uint32_t)0xFF000000)        /*!< 数据字节 3 */

/******************* CAN_TDH2R 寄存器的位定义 *****************/
#define  CAN_TDH2R_DATA4                     ((uint32_t)0x000000FF)        /*!< 数据字节 4 */
#define  CAN_TDH2R_DATA5                     ((uint32_t)0x0000FF00)        /*!< 数据字节 5 */
#define  CAN_TDH2R_DATA6                     ((uint32_t)0x00FF0000)        /*!< 数据字节 6 */
#define  CAN_TDH2R_DATA7                     ((uint32_t)0xFF000000)        /*!< 数据字节 7 */

/******************* CAN_RI0R 寄存器的位定义 *****************/
#define  CAN_RI0R_RTR                        ((uint32_t)0x00000002)        /*!< 远程发送请求 */
#define  CAN_RI0R_IDE                        ((uint32_t)0x00000004)        /*!< 标识符扩展 */
#define  CAN_RI0R_EXID                       ((uint32_t)0x001FFFF8)        /*!< 扩展标识符 */
#define  CAN_RI0R_STID                       ((uint32_t)0xFFE00000)        /*!< 标准标识符或扩展标识符 */

/******************* CAN_RDT0R 寄存器的位定义 *****************/
#define  CAN_RDT0R_DLC                       ((uint32_t)0x0000000F)        /*!< 数据长度代码 */
#define  CAN_RDT0R_FMI                       ((uint32_t)0x0000FF00)        /*!< 过滤器匹配索引 */
#define  CAN_RDT0R_TIME                      ((uint32_t)0xFFFF0000)        /*!< 报文时间戳 */

/******************* CAN_RDL0R 寄存器的位定义 *****************/
#define  CAN_RDL0R_DATA0                     ((uint32_t)0x000000FF)        /*!< 数据字节 0 */
#define  CAN_RDL0R_DATA1                     ((uint32_t)0x0000FF00)        /*!< 数据字节 1 */
#define  CAN_RDL0R_DATA2                     ((uint32_t)0x00FF0000)        /*!< 数据字节 2 */
#define  CAN_RDL0R_DATA3                     ((uint32_t)0xFF000000)        /*!< 数据字节 3 */

/******************* CAN_RDH0R 寄存器的位定义 *****************/
#define  CAN_RDH0R_DATA4                     ((uint32_t)0x000000FF)        /*!< 数据字节 4 */
#define  CAN_RDH0R_DATA5                     ((uint32_t)0x0000FF00)        /*!< 数据字节 5 */
#define  CAN_RDH0R_DATA6                     ((uint32_t)0x00FF0000)        /*!< 数据字节 6 */
#define  CAN_RDH0R_DATA7                     ((uint32_t)0xFF000000)        /*!< 数据字节 7 */

/******************* CAN_RI1R 寄存器的位定义 *****************/
#define  CAN_RI1R_RTR                        ((uint32_t)0x00000002)        /*!< 远程发送请求 */
#define  CAN_RI1R_IDE                        ((uint32_t)0x00000004)        /*!< 标识符扩展 */
#define  CAN_RI1R_EXID                       ((uint32_t)0x001FFFF8)        /*!< 扩展标识符 */
#define  CAN_RI1R_STID                       ((uint32_t)0xFFE00000)        /*!< 标准标识符或扩展标识符 */

/******************* CAN_RDT1R 寄存器的位定义 *****************/
#define  CAN_RDT1R_DLC                       ((uint32_t)0x0000000F)        /*!< 数据长度代码 */
#define  CAN_RDT1R_FMI                       ((uint32_t)0x0000FF00)        /*!< 过滤器匹配索引 */
#define  CAN_RDT1R_TIME                      ((uint32_t)0xFFFF0000)        /*!< 报文时间戳 */

/******************* CAN_RDL1R 寄存器的位定义 *****************/
#define  CAN_RDL1R_DATA0                     ((uint32_t)0x000000FF)        /*!< 数据字节 0 */
#define  CAN_RDL1R_DATA1                     ((uint32_t)0x0000FF00)        /*!< 数据字节 1 */
#define  CAN_RDL1R_DATA2                     ((uint32_t)0x00FF0000)        /*!< 数据字节 2 */
#define  CAN_RDL1R_DATA3                     ((uint32_t)0xFF000000)        /*!< 数据字节 3 */

/******************* CAN_RDH1R 寄存器的位定义 *****************/
#define  CAN_RDH1R_DATA4                     ((uint32_t)0x000000FF)        /*!< 数据字节 4 */
#define  CAN_RDH1R_DATA5                     ((uint32_t)0x0000FF00)        /*!< 数据字节 5 */
#define  CAN_RDH1R_DATA6                     ((uint32_t)0x00FF0000)        /*!< 数据字节 6 */
#define  CAN_RDH1R_DATA7                     ((uint32_t)0xFF000000)        /*!< 数据字节 7 */

/*!< CAN 过滤器寄存器 */
/******************* CAN_FMR 寄存器的位定义 *****************/
#define  CAN_FMR_FINIT                       ((uint8_t)0x01)               /*!< 过滤器初始化模式 */

/******************* CAN_FM1R 寄存器的位定义 *****************/
#define  CAN_FM1R_FBM                        ((uint16_t)0x3FFF)            /*!< 过滤器模式 */
#define  CAN_FM1R_FBM0                       ((uint16_t)0x0001)            /*!< 过滤器初始化模式位 0 */
#define  CAN_FM1R_FBM1                       ((uint16_t)0x0002)            /*!< 过滤器初始化模式位 1 */
#define  CAN_FM1R_FBM2                       ((uint16_t)0x0004)            /*!< 过滤器初始化模式位 2 */
#define  CAN_FM1R_FBM3                       ((uint16_t)0x0008)            /*!< 过滤器初始化模式位 3 */
#define  CAN_FM1R_FBM4                       ((uint16_t)0x0010)            /*!< 过滤器初始化模式位 4 */
#define  CAN_FM1R_FBM5                       ((uint16_t)0x0020)            /*!< 过滤器初始化模式位 5 */
#define  CAN_FM1R_FBM6                       ((uint16_t)0x0040)            /*!< 过滤器初始化模式位 6 */
#define  CAN_FM1R_FBM7                       ((uint16_t)0x0080)            /*!< 过滤器初始化模式位 7 */
#define  CAN_FM1R_FBM8                       ((uint16_t)0x0100)            /*!< 过滤器初始化模式位 8 */
#define  CAN_FM1R_FBM9                       ((uint16_t)0x0200)            /*!< 过滤器初始化模式位 9 */
#define  CAN_FM1R_FBM10                      ((uint16_t)0x0400)            /*!< 过滤器初始化模式位 10 */
#define  CAN_FM1R_FBM11                      ((uint16_t)0x0800)            /*!< 过滤器初始化模式位 11 */
#define  CAN_FM1R_FBM12                      ((uint16_t)0x1000)            /*!< 过滤器初始化模式位 12 */
#define  CAN_FM1R_FBM13                      ((uint16_t)0x2000)            /*!< 过滤器初始化模式位 13 */

/******************* CAN_FS1R 寄存器的位定义 *****************/
#define  CAN_FS1R_FSC                        ((uint16_t)0x3FFF)            /*!< 过滤器位宽配置 */
#define  CAN_FS1R_FSC0                       ((uint16_t)0x0001)            /*!< 过滤器位宽配置位 0 */
#define  CAN_FS1R_FSC1                       ((uint16_t)0x0002)            /*!< 过滤器位宽配置位 1 */
#define  CAN_FS1R_FSC2                       ((uint16_t)0x0004)            /*!< 过滤器位宽配置位 2 */
#define  CAN_FS1R_FSC3                       ((uint16_t)0x0008)            /*!< 过滤器位宽配置位 3 */
#define  CAN_FS1R_FSC4                       ((uint16_t)0x0010)            /*!< 过滤器位宽配置位 4 */
#define  CAN_FS1R_FSC5                       ((uint16_t)0x0020)            /*!< 过滤器位宽配置位 5 */
#define  CAN_FS1R_FSC6                       ((uint16_t)0x0040)            /*!< 过滤器位宽配置位 6 */
#define  CAN_FS1R_FSC7                       ((uint16_t)0x0080)            /*!< 过滤器位宽配置位 7 */
#define  CAN_FS1R_FSC8                       ((uint16_t)0x0100)            /*!< 过滤器位宽配置位 8 */
#define  CAN_FS1R_FSC9                       ((uint16_t)0x0200)            /*!< 过滤器位宽配置位 9 */
#define  CAN_FS1R_FSC10                      ((uint16_t)0x0400)            /*!< 过滤器位宽配置位 10 */
#define  CAN_FS1R_FSC11                      ((uint16_t)0x0800)            /*!< 过滤器位宽配置位 11 */
#define  CAN_FS1R_FSC12                      ((uint16_t)0x1000)            /*!< 过滤器位宽配置位 12 */
#define  CAN_FS1R_FSC13                      ((uint16_t)0x2000)            /*!< 过滤器位宽配置位 13 */

/****************** CAN_FFA1R 寄存器的位定义 ****************/
#define  CAN_FFA1R_FFA                       ((uint16_t)0x3FFF)            /*!< 过滤器 FIFO 分配 */
#define  CAN_FFA1R_FFA0                      ((uint16_t)0x0001)            /*!< 过滤器 0 的 FIFO 分配 */
#define  CAN_FFA1R_FFA1                      ((uint16_t)0x0002)            /*!< 过滤器 1 的 FIFO 分配 */
#define  CAN_FFA1R_FFA2                      ((uint16_t)0x0004)            /*!< 过滤器 2 的 FIFO 分配 */
#define  CAN_FFA1R_FFA3                      ((uint16_t)0x0008)            /*!< 过滤器 3 的 FIFO 分配 */
#define  CAN_FFA1R_FFA4                      ((uint16_t)0x0010)            /*!< 过滤器 4 的 FIFO 分配 */
#define  CAN_FFA1R_FFA5                      ((uint16_t)0x0020)            /*!< 过滤器 5 的 FIFO 分配 */
#define  CAN_FFA1R_FFA6                      ((uint16_t)0x0040)            /*!< 过滤器 6 的 FIFO 分配 */
#define  CAN_FFA1R_FFA7                      ((uint16_t)0x0080)            /*!< 过滤器 7 的 FIFO 分配 */
#define  CAN_FFA1R_FFA8                      ((uint16_t)0x0100)            /*!< 过滤器 8 的 FIFO 分配 */
#define  CAN_FFA1R_FFA9                      ((uint16_t)0x0200)            /*!< 过滤器 9 的 FIFO 分配 */
#define  CAN_FFA1R_FFA10                     ((uint16_t)0x0400)            /*!< 过滤器 10 的 FIFO 分配 */
#define  CAN_FFA1R_FFA11                     ((uint16_t)0x0800)            /*!< 过滤器 11 的 FIFO 分配 */
#define  CAN_FFA1R_FFA12                     ((uint16_t)0x1000)            /*!< 过滤器 12 的 FIFO 分配 */
#define  CAN_FFA1R_FFA13                     ((uint16_t)0x2000)            /*!< 过滤器 13 的 FIFO 分配 */

/******************* CAN_FA1R 寄存器的位定义 *****************/
#define  CAN_FA1R_FACT                       ((uint16_t)0x3FFF)            /*!< 过滤器激活 */
#define  CAN_FA1R_FACT0                      ((uint16_t)0x0001)            /*!< 过滤器 0 激活 */
#define  CAN_FA1R_FACT1                      ((uint16_t)0x0002)            /*!< 过滤器 1 激活 */
#define  CAN_FA1R_FACT2                      ((uint16_t)0x0004)            /*!< 过滤器 2 激活 */
#define  CAN_FA1R_FACT3                      ((uint16_t)0x0008)            /*!< 过滤器 3 激活 */
#define  CAN_FA1R_FACT4                      ((uint16_t)0x0010)            /*!< 过滤器 4 激活 */
#define  CAN_FA1R_FACT5                      ((uint16_t)0x0020)            /*!< 过滤器 5 激活 */
#define  CAN_FA1R_FACT6                      ((uint16_t)0x0040)            /*!< 过滤器 6 激活 */
#define  CAN_FA1R_FACT7                      ((uint16_t)0x0080)            /*!< 过滤器 7 激活 */
#define  CAN_FA1R_FACT8                      ((uint16_t)0x0100)            /*!< 过滤器 8 激活 */
#define  CAN_FA1R_FACT9                      ((uint16_t)0x0200)            /*!< 过滤器 9 激活 */
#define  CAN_FA1R_FACT10                     ((uint16_t)0x0400)            /*!< 过滤器 10 激活 */
#define  CAN_FA1R_FACT11                     ((uint16_t)0x0800)            /*!< 过滤器 11 激活 */
#define  CAN_FA1R_FACT12                     ((uint16_t)0x1000)            /*!< 过滤器 12 激活 */
#define  CAN_FA1R_FACT13                     ((uint16_t)0x2000)            /*!< 过滤器 13 激活 */

/******************* CAN_F0R1 寄存器的位定义 *****************/
#define  CAN_F0R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F0R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F0R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F0R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F0R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F0R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F0R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F0R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F0R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F0R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F0R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F0R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F0R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F0R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F0R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F0R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F0R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F0R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F0R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F0R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F0R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F0R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F0R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F0R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F0R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F0R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F0R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F0R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F0R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F0R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F0R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F0R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F1R1 寄存器的位定义 *****************/
#define  CAN_F1R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F1R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F1R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F1R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F1R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F1R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F1R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F1R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F1R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F1R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F1R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F1R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F1R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F1R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F1R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F1R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F1R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F1R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F1R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F1R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F1R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F1R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F1R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F1R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F1R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F1R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F1R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F1R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F1R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F1R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F1R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F1R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F2R1 寄存器的位定义 *****************/
#define  CAN_F2R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F2R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F2R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F2R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F2R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F2R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F2R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F2R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F2R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F2R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F2R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F2R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F2R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F2R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F2R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F2R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F2R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F2R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F2R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F2R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F2R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F2R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F2R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F2R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F2R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F2R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F2R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F2R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F2R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F2R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F2R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F2R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F3R1 寄存器的位定义 *****************/
#define  CAN_F3R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F3R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F3R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F3R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F3R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F3R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F3R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F3R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F3R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F3R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F3R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F3R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F3R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F3R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F3R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F3R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F3R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F3R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F3R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F3R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F3R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F3R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F3R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F3R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F3R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F3R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F3R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F3R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F3R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F3R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F3R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F3R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F4R1 寄存器的位定义 *****************/
#define  CAN_F4R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F4R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F4R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F4R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F4R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F4R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F4R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F4R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F4R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F4R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F4R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F4R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F4R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F4R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F4R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F4R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F4R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F4R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F4R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F4R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F4R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F4R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F4R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F4R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F4R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F4R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F4R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F4R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F4R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F4R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F4R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F4R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F5R1 寄存器的位定义 *****************/
#define  CAN_F5R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F5R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F5R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F5R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F5R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F5R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F5R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F5R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F5R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F5R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F5R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F5R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F5R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F5R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F5R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F5R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F5R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F5R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F5R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F5R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F5R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F5R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F5R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F5R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F5R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F5R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F5R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F5R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F5R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F5R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F5R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F5R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F6R1 寄存器的位定义 *****************/
#define  CAN_F6R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F6R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F6R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F6R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F6R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F6R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F6R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F6R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F6R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F6R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F6R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F6R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F6R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F6R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F6R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F6R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F6R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F6R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F6R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F6R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F6R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F6R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F6R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F6R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F6R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F6R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F6R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F6R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F6R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F6R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F6R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F6R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F7R1 寄存器的位定义 *****************/
#define  CAN_F7R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F7R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F7R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F7R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F7R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F7R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F7R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F7R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F7R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F7R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F7R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F7R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F7R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F7R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F7R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F7R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F7R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F7R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F7R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F7R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F7R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F7R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F7R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F7R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F7R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F7R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F7R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F7R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F7R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F7R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F7R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F7R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F8R1 寄存器的位定义 *****************/
#define  CAN_F8R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F8R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F8R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F8R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F8R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F8R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F8R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F8R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F8R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F8R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F8R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F8R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F8R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F8R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F8R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F8R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F8R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F8R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F8R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F8R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F8R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F8R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F8R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F8R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F8R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F8R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F8R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F8R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F8R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F8R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F8R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F8R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F9R1 寄存器的位定义 *****************/
#define  CAN_F9R1_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F9R1_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F9R1_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F9R1_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F9R1_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F9R1_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F9R1_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F9R1_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F9R1_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F9R1_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F9R1_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F9R1_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F9R1_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F9R1_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F9R1_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F9R1_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F9R1_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F9R1_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F9R1_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F9R1_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F9R1_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F9R1_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F9R1_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F9R1_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F9R1_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F9R1_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F9R1_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F9R1_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F9R1_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F9R1_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F9R1_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F9R1_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F10R1 寄存器的位定义 *****************/
#define  CAN_F10R1_FB0                       ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F10R1_FB1                       ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F10R1_FB2                       ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F10R1_FB3                       ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F10R1_FB4                       ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F10R1_FB5                       ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F10R1_FB6                       ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F10R1_FB7                       ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F10R1_FB8                       ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F10R1_FB9                       ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F10R1_FB10                      ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F10R1_FB11                      ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F10R1_FB12                      ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F10R1_FB13                      ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F10R1_FB14                      ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F10R1_FB15                      ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F10R1_FB16                      ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F10R1_FB17                      ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F10R1_FB18                      ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F10R1_FB19                      ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F10R1_FB20                      ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F10R1_FB21                      ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F10R1_FB22                      ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F10R1_FB23                      ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F10R1_FB24                      ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F10R1_FB25                      ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F10R1_FB26                      ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F10R1_FB27                      ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F10R1_FB28                      ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F10R1_FB29                      ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F10R1_FB30                      ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F10R1_FB31                      ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F11R1 寄存器的位定义 *****************/
#define  CAN_F11R1_FB0                       ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F11R1_FB1                       ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F11R1_FB2                       ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F11R1_FB3                       ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F11R1_FB4                       ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F11R1_FB5                       ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F11R1_FB6                       ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F11R1_FB7                       ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F11R1_FB8                       ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F11R1_FB9                       ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F11R1_FB10                      ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F11R1_FB11                      ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F11R1_FB12                      ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F11R1_FB13                      ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F11R1_FB14                      ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F11R1_FB15                      ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F11R1_FB16                      ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F11R1_FB17                      ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F11R1_FB18                      ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F11R1_FB19                      ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F11R1_FB20                      ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F11R1_FB21                      ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F11R1_FB22                      ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F11R1_FB23                      ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F11R1_FB24                      ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F11R1_FB25                      ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F11R1_FB26                      ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F11R1_FB27                      ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F11R1_FB28                      ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F11R1_FB29                      ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F11R1_FB30                      ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F11R1_FB31                      ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F12R1 寄存器的位定义 *****************/
#define  CAN_F12R1_FB0                       ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F12R1_FB1                       ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F12R1_FB2                       ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F12R1_FB3                       ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F12R1_FB4                       ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F12R1_FB5                       ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F12R1_FB6                       ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F12R1_FB7                       ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F12R1_FB8                       ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F12R1_FB9                       ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F12R1_FB10                      ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F12R1_FB11                      ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F12R1_FB12                      ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F12R1_FB13                      ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F12R1_FB14                      ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F12R1_FB15                      ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F12R1_FB16                      ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F12R1_FB17                      ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F12R1_FB18                      ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F12R1_FB19                      ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F12R1_FB20                      ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F12R1_FB21                      ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F12R1_FB22                      ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F12R1_FB23                      ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F12R1_FB24                      ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F12R1_FB25                      ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F12R1_FB26                      ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F12R1_FB27                      ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F12R1_FB28                      ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F12R1_FB29                      ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F12R1_FB30                      ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F12R1_FB31                      ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F13R1 寄存器的位定义 *****************/
#define  CAN_F13R1_FB0                       ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F13R1_FB1                       ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F13R1_FB2                       ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F13R1_FB3                       ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F13R1_FB4                       ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F13R1_FB5                       ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F13R1_FB6                       ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F13R1_FB7                       ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F13R1_FB8                       ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F13R1_FB9                       ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F13R1_FB10                      ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F13R1_FB11                      ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F13R1_FB12                      ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F13R1_FB13                      ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F13R1_FB14                      ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F13R1_FB15                      ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F13R1_FB16                      ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F13R1_FB17                      ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F13R1_FB18                      ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F13R1_FB19                      ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F13R1_FB20                      ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F13R1_FB21                      ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F13R1_FB22                      ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F13R1_FB23                      ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F13R1_FB24                      ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F13R1_FB25                      ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F13R1_FB26                      ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F13R1_FB27                      ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F13R1_FB28                      ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F13R1_FB29                      ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F13R1_FB30                      ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F13R1_FB31                      ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F0R2 寄存器的位定义 *****************/
#define  CAN_F0R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F0R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F0R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F0R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F0R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F0R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F0R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F0R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F0R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F0R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F0R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F0R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F0R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F0R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F0R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F0R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F0R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F0R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F0R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F0R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F0R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F0R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F0R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F0R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F0R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F0R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F0R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F0R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F0R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F0R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F0R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F0R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F1R2 寄存器的位定义 *****************/
#define  CAN_F1R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F1R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F1R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F1R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F1R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F1R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F1R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F1R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F1R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F1R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F1R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F1R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F1R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F1R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F1R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F1R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F1R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F1R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F1R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F1R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F1R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F1R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F1R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F1R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F1R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F1R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F1R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F1R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F1R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F1R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F1R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F1R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F2R2 寄存器的位定义 *****************/
#define  CAN_F2R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F2R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F2R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F2R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F2R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F2R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F2R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F2R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F2R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F2R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F2R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F2R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F2R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F2R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F2R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F2R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F2R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F2R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F2R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F2R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F2R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F2R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F2R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F2R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F2R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F2R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F2R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F2R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F2R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F2R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F2R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F2R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F3R2 寄存器的位定义 *****************/
#define  CAN_F3R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F3R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F3R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F3R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F3R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F3R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F3R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F3R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F3R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F3R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F3R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F3R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F3R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F3R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F3R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F3R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F3R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F3R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F3R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F3R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F3R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F3R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F3R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F3R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F3R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F3R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F3R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F3R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F3R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F3R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F3R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F3R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F4R2 寄存器的位定义 *****************/
#define  CAN_F4R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F4R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F4R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F4R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F4R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F4R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F4R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F4R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F4R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F4R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F4R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F4R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F4R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F4R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F4R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F4R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F4R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F4R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F4R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F4R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F4R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F4R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F4R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F4R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F4R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F4R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F4R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F4R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F4R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F4R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F4R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F4R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F5R2 寄存器的位定义 *****************/
#define  CAN_F5R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F5R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F5R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F5R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F5R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F5R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F5R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F5R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F5R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F5R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F5R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F5R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F5R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F5R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F5R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F5R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F5R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F5R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F5R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F5R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F5R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F5R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F5R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F5R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F5R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F5R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F5R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F5R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F5R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F5R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F5R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F5R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F6R2 寄存器的位定义 *****************/
#define  CAN_F6R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F6R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F6R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F6R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F6R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F6R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F6R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F6R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F6R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F6R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F6R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F6R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F6R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F6R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F6R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F6R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F6R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F6R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F6R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F6R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F6R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F6R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F6R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F6R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F6R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F6R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F6R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F6R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F6R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F6R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F6R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F6R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F7R2 寄存器的位定义 *****************/
#define  CAN_F7R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F7R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F7R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F7R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F7R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F7R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F7R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F7R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F7R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F7R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F7R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F7R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F7R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F7R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F7R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F7R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F7R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F7R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F7R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F7R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F7R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F7R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F7R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F7R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F7R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F7R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F7R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F7R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F7R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F7R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F7R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F7R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F8R2 寄存器的位定义 *****************/
#define  CAN_F8R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F8R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F8R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F8R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F8R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F8R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F8R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F8R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F8R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F8R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F8R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F8R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F8R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F8R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F8R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F8R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F8R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F8R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F8R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F8R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F8R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F8R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F8R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F8R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F8R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F8R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F8R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F8R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F8R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F8R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F8R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F8R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F9R2 寄存器的位定义 *****************/
#define  CAN_F9R2_FB0                        ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F9R2_FB1                        ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F9R2_FB2                        ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F9R2_FB3                        ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F9R2_FB4                        ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F9R2_FB5                        ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F9R2_FB6                        ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F9R2_FB7                        ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F9R2_FB8                        ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F9R2_FB9                        ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F9R2_FB10                       ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F9R2_FB11                       ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F9R2_FB12                       ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F9R2_FB13                       ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F9R2_FB14                       ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F9R2_FB15                       ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F9R2_FB16                       ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F9R2_FB17                       ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F9R2_FB18                       ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F9R2_FB19                       ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F9R2_FB20                       ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F9R2_FB21                       ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F9R2_FB22                       ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F9R2_FB23                       ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F9R2_FB24                       ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F9R2_FB25                       ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F9R2_FB26                       ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F9R2_FB27                       ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F9R2_FB28                       ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F9R2_FB29                       ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F9R2_FB30                       ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F9R2_FB31                       ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F10R2 寄存器的位定义 *****************/
#define  CAN_F10R2_FB0                       ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F10R2_FB1                       ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F10R2_FB2                       ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F10R2_FB3                       ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F10R2_FB4                       ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F10R2_FB5                       ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F10R2_FB6                       ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F10R2_FB7                       ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F10R2_FB8                       ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F10R2_FB9                       ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F10R2_FB10                      ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F10R2_FB11                      ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F10R2_FB12                      ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F10R2_FB13                      ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F10R2_FB14                      ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F10R2_FB15                      ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F10R2_FB16                      ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F10R2_FB17                      ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F10R2_FB18                      ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F10R2_FB19                      ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F10R2_FB20                      ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F10R2_FB21                      ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F10R2_FB22                      ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F10R2_FB23                      ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F10R2_FB24                      ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F10R2_FB25                      ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F10R2_FB26                      ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F10R2_FB27                      ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F10R2_FB28                      ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F10R2_FB29                      ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F10R2_FB30                      ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F10R2_FB31                      ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F11R2 寄存器的位定义 *****************/
#define  CAN_F11R2_FB0                       ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F11R2_FB1                       ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F11R2_FB2                       ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F11R2_FB3                       ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F11R2_FB4                       ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F11R2_FB5                       ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F11R2_FB6                       ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F11R2_FB7                       ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F11R2_FB8                       ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F11R2_FB9                       ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F11R2_FB10                      ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F11R2_FB11                      ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F11R2_FB12                      ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F11R2_FB13                      ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F11R2_FB14                      ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F11R2_FB15                      ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F11R2_FB16                      ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F11R2_FB17                      ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F11R2_FB18                      ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F11R2_FB19                      ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F11R2_FB20                      ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F11R2_FB21                      ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F11R2_FB22                      ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F11R2_FB23                      ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F11R2_FB24                      ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F11R2_FB25                      ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F11R2_FB26                      ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F11R2_FB27                      ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F11R2_FB28                      ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F11R2_FB29                      ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F11R2_FB30                      ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F11R2_FB31                      ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F12R2 寄存器的位定义 *****************/
#define  CAN_F12R2_FB0                       ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F12R2_FB1                       ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F12R2_FB2                       ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F12R2_FB3                       ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F12R2_FB4                       ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F12R2_FB5                       ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F12R2_FB6                       ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F12R2_FB7                       ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F12R2_FB8                       ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F12R2_FB9                       ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F12R2_FB10                      ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F12R2_FB11                      ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F12R2_FB12                      ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F12R2_FB13                      ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F12R2_FB14                      ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F12R2_FB15                      ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F12R2_FB16                      ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F12R2_FB17                      ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F12R2_FB18                      ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F12R2_FB19                      ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F12R2_FB20                      ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F12R2_FB21                      ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F12R2_FB22                      ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F12R2_FB23                      ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F12R2_FB24                      ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F12R2_FB25                      ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F12R2_FB26                      ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F12R2_FB27                      ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F12R2_FB28                      ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F12R2_FB29                      ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F12R2_FB30                      ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F12R2_FB31                      ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************* CAN_F13R2 寄存器的位定义 *****************/
#define  CAN_F13R2_FB0                       ((uint32_t)0x00000001)        /*!< 过滤器位 0 */
#define  CAN_F13R2_FB1                       ((uint32_t)0x00000002)        /*!< 过滤器位 1 */
#define  CAN_F13R2_FB2                       ((uint32_t)0x00000004)        /*!< 过滤器位 2 */
#define  CAN_F13R2_FB3                       ((uint32_t)0x00000008)        /*!< 过滤器位 3 */
#define  CAN_F13R2_FB4                       ((uint32_t)0x00000010)        /*!< 过滤器位 4 */
#define  CAN_F13R2_FB5                       ((uint32_t)0x00000020)        /*!< 过滤器位 5 */
#define  CAN_F13R2_FB6                       ((uint32_t)0x00000040)        /*!< 过滤器位 6 */
#define  CAN_F13R2_FB7                       ((uint32_t)0x00000080)        /*!< 过滤器位 7 */
#define  CAN_F13R2_FB8                       ((uint32_t)0x00000100)        /*!< 过滤器位 8 */
#define  CAN_F13R2_FB9                       ((uint32_t)0x00000200)        /*!< 过滤器位 9 */
#define  CAN_F13R2_FB10                      ((uint32_t)0x00000400)        /*!< 过滤器位 10 */
#define  CAN_F13R2_FB11                      ((uint32_t)0x00000800)        /*!< 过滤器位 11 */
#define  CAN_F13R2_FB12                      ((uint32_t)0x00001000)        /*!< 过滤器位 12 */
#define  CAN_F13R2_FB13                      ((uint32_t)0x00002000)        /*!< 过滤器位 13 */
#define  CAN_F13R2_FB14                      ((uint32_t)0x00004000)        /*!< 过滤器位 14 */
#define  CAN_F13R2_FB15                      ((uint32_t)0x00008000)        /*!< 过滤器位 15 */
#define  CAN_F13R2_FB16                      ((uint32_t)0x00010000)        /*!< 过滤器位 16 */
#define  CAN_F13R2_FB17                      ((uint32_t)0x00020000)        /*!< 过滤器位 17 */
#define  CAN_F13R2_FB18                      ((uint32_t)0x00040000)        /*!< 过滤器位 18 */
#define  CAN_F13R2_FB19                      ((uint32_t)0x00080000)        /*!< 过滤器位 19 */
#define  CAN_F13R2_FB20                      ((uint32_t)0x00100000)        /*!< 过滤器位 20 */
#define  CAN_F13R2_FB21                      ((uint32_t)0x00200000)        /*!< 过滤器位 21 */
#define  CAN_F13R2_FB22                      ((uint32_t)0x00400000)        /*!< 过滤器位 22 */
#define  CAN_F13R2_FB23                      ((uint32_t)0x00800000)        /*!< 过滤器位 23 */
#define  CAN_F13R2_FB24                      ((uint32_t)0x01000000)        /*!< 过滤器位 24 */
#define  CAN_F13R2_FB25                      ((uint32_t)0x02000000)        /*!< 过滤器位 25 */
#define  CAN_F13R2_FB26                      ((uint32_t)0x04000000)        /*!< 过滤器位 26 */
#define  CAN_F13R2_FB27                      ((uint32_t)0x08000000)        /*!< 过滤器位 27 */
#define  CAN_F13R2_FB28                      ((uint32_t)0x10000000)        /*!< 过滤器位 28 */
#define  CAN_F13R2_FB29                      ((uint32_t)0x20000000)        /*!< 过滤器位 29 */
#define  CAN_F13R2_FB30                      ((uint32_t)0x40000000)        /*!< 过滤器位 30 */
#define  CAN_F13R2_FB31                      ((uint32_t)0x80000000)        /*!< 过滤器位 31 */

/******************************************************************************/
/*                                                                            */
/*                        串行外设接口                         */
/*                                                                            */
/******************************************************************************/

/******************* SPI_CR1 寄存器的位定义 *****************/
#define  SPI_CR1_CPHA                        ((uint16_t)0x0001)            /*!< 时钟相位 */
#define  SPI_CR1_CPOL                        ((uint16_t)0x0002)            /*!< 时钟极性 */
#define  SPI_CR1_MSTR                        ((uint16_t)0x0004)            /*!< 主选择 */

#define  SPI_CR1_BR                          ((uint16_t)0x0038)            /*!< BR[2:0] 位（波特率控制） */
#define  SPI_CR1_BR_0                        ((uint16_t)0x0008)            /*!< 位 0 */
#define  SPI_CR1_BR_1                        ((uint16_t)0x0010)            /*!< 位 1 */
#define  SPI_CR1_BR_2                        ((uint16_t)0x0020)            /*!< 位 2 */

#define  SPI_CR1_SPE                         ((uint16_t)0x0040)            /*!< SPI 使能 */
#define  SPI_CR1_LSBFIRST                    ((uint16_t)0x0080)            /*!< 帧格式 */
#define  SPI_CR1_SSI                         ((uint16_t)0x0100)            /*!< 内部从选择 */
#define  SPI_CR1_SSM                         ((uint16_t)0x0200)            /*!< 软件从管理 */
#define  SPI_CR1_RXONLY                      ((uint16_t)0x0400)            /*!< 仅接收 */
#define  SPI_CR1_DFF                         ((uint16_t)0x0800)            /*!< 数据帧格式 */
#define  SPI_CR1_CRCNEXT                     ((uint16_t)0x1000)            /*!< 下一个发送 CRC */
#define  SPI_CR1_CRCEN                       ((uint16_t)0x2000)            /*!< 硬件 CRC 计算使能 */
#define  SPI_CR1_BIDIOE                      ((uint16_t)0x4000)            /*!< 双向模式下的输出使能 */
#define  SPI_CR1_BIDIMODE                    ((uint16_t)0x8000)            /*!< 双向数据模式使能 */

/******************* SPI_CR2 寄存器的位定义 *****************/
#define  SPI_CR2_RXDMAEN                     ((uint8_t)0x01)               /*!< 接收缓冲区 DMA 使能 */
#define  SPI_CR2_TXDMAEN                     ((uint8_t)0x02)               /*!< 发送缓冲区 DMA 使能 */
#define  SPI_CR2_SSOE                        ((uint8_t)0x04)               /*!< SS 输出使能 */
#define  SPI_CR2_ERRIE                       ((uint8_t)0x20)               /*!< 错误中断使能 */
#define  SPI_CR2_RXNEIE                      ((uint8_t)0x40)               /*!< 接收缓冲区非空中断使能 */
#define  SPI_CR2_TXEIE                       ((uint8_t)0x80)               /*!< 发送缓冲区空中断使能 */

/******************** SPI_SR 寄存器的位定义 ******************/
#define  SPI_SR_RXNE                         ((uint8_t)0x01)               /*!< 接收缓冲区非空 */
#define  SPI_SR_TXE                          ((uint8_t)0x02)               /*!< 发送缓冲区空 */
#define  SPI_SR_CHSIDE                       ((uint8_t)0x04)               /*!< 通道侧 */
#define  SPI_SR_UDR                          ((uint8_t)0x08)               /*!< 下溢标志位 */
#define  SPI_SR_CRCERR                       ((uint8_t)0x10)               /*!< CRC 错误标志位 */
#define  SPI_SR_MODF                         ((uint8_t)0x20)               /*!< 模式错误 */
#define  SPI_SR_OVR                          ((uint8_t)0x40)               /*!< 上溢标志位 */
#define  SPI_SR_BSY                          ((uint8_t)0x80)               /*!< 忙标志位 */

/******************** SPI_DR 寄存器的位定义 ******************/
#define  SPI_DR_DR                           ((uint16_t)0xFFFF)            /*!< 数据寄存器 */

/******************* SPI_CRCPR 寄存器的位定义 *****************/
#define  SPI_CRCPR_CRCPOLY                   ((uint16_t)0xFFFF)            /*!< CRC 多项式寄存器 */

/****************** SPI_RXCRCR 寄存器的位定义 ****************/
#define  SPI_RXCRCR_RXCRC                    ((uint16_t)0xFFFF)            /*!< 接收 CRC 寄存器 */

/****************** SPI_TXCRCR 寄存器的位定义 ****************/
#define  SPI_TXCRCR_TXCRC                    ((uint16_t)0xFFFF)            /*!< 发送 CRC 寄存器 */

/****************** SPI_I2SCFGR 寄存器的位定义 ****************/
#define  SPI_I2SCFGR_CHLEN                   ((uint16_t)0x0001)            /*!< 通道长度（每个音频通道的位数） */

#define  SPI_I2SCFGR_DATLEN                  ((uint16_t)0x0006)            /*!< DATLEN[1:0] 位（要传输的数据长度） */
#define  SPI_I2SCFGR_DATLEN_0                ((uint16_t)0x0002)            /*!< 位 0 */
#define  SPI_I2SCFGR_DATLEN_1                ((uint16_t)0x0004)            /*!< 位 1 */

#define  SPI_I2SCFGR_CKPOL                   ((uint16_t)0x0008)            /*!< 稳态时钟极性 */

#define  SPI_I2SCFGR_I2SSTD                  ((uint16_t)0x0030)            /*!< I2SSTD[1:0] 位（I2S 标准选择） */
#define  SPI_I2SCFGR_I2SSTD_0                ((uint16_t)0x0010)            /*!< 位 0 */
#define  SPI_I2SCFGR_I2SSTD_1                ((uint16_t)0x0020)            /*!< 位 1 */

#define  SPI_I2SCFGR_PCMSYNC                 ((uint16_t)0x0080)            /*!< PCM 帧同步 */

#define  SPI_I2SCFGR_I2SCFG                  ((uint16_t)0x0300)            /*!< I2SCFG[1:0] 位（I2S 配置模式） */
#define  SPI_I2SCFGR_I2SCFG_0                ((uint16_t)0x0100)            /*!< 位 0 */
#define  SPI_I2SCFGR_I2SCFG_1                ((uint16_t)0x0200)            /*!< 位 1 */

#define  SPI_I2SCFGR_I2SE                    ((uint16_t)0x0400)            /*!< I2S 使能 */
#define  SPI_I2SCFGR_I2SMOD                  ((uint16_t)0x0800)            /*!< I2S 模式选择 */

/****************** SPI_I2SPR 寄存器的位定义 ****************/
#define  SPI_I2SPR_I2SDIV                    ((uint16_t)0x00FF)            /*!< I2S 线性预分频 */
#define  SPI_I2SPR_ODD                       ((uint16_t)0x0100)            /*!< 预分频器的奇数因子 */
#define  SPI_I2SPR_MCKOE                     ((uint16_t)0x0200)            /*!< 主时钟输出使能 */

/******************************************************************************/
/*                                                                            */
/*                      内部集成电路接口                    */
/*                                                                            */
/******************************************************************************/

/******************* I2C_CR1 寄存器的位定义 *****************/
#define  I2C_CR1_PE                          ((uint16_t)0x0001)            /*!< 外设使能 */
#define  I2C_CR1_SMBUS                       ((uint16_t)0x0002)            /*!< SMBus 模式 */
#define  I2C_CR1_SMBTYPE                     ((uint16_t)0x0008)            /*!< SMBus 类型 */
#define  I2C_CR1_ENARP                       ((uint16_t)0x0010)            /*!< ARP 使能 */
#define  I2C_CR1_ENPEC                       ((uint16_t)0x0020)            /*!< PEC 使能 */
#define  I2C_CR1_ENGC                        ((uint16_t)0x0040)            /*!< 通用呼叫使能 */
#define  I2C_CR1_NOSTRETCH                   ((uint16_t)0x0080)            /*!< 时钟延展禁止（从模式） */
#define  I2C_CR1_START                       ((uint16_t)0x0100)            /*!< 启动事件产生 */
#define  I2C_CR1_STOP                        ((uint16_t)0x0200)            /*!< 停止事件产生 */
#define  I2C_CR1_ACK                         ((uint16_t)0x0400)            /*!< 应答使能 */
#define  I2C_CR1_POS                         ((uint16_t)0x0800)            /*!< 应答/PEC 位置（用于数据接收） */
#define  I2C_CR1_PEC                         ((uint16_t)0x1000)            /*!< 数据包错误校验 */
#define  I2C_CR1_ALERT                       ((uint16_t)0x2000)            /*!< SMBus 报警 */
#define  I2C_CR1_SWRST                       ((uint16_t)0x8000)            /*!< 软件复位 */

/******************* I2C_CR2 寄存器的位定义 *****************/
#define  I2C_CR2_FREQ                        ((uint16_t)0x003F)            /*!< FREQ[5:0] 位（外设时钟频率） */
#define  I2C_CR2_FREQ_0                      ((uint16_t)0x0001)            /*!< 位 0 */
#define  I2C_CR2_FREQ_1                      ((uint16_t)0x0002)            /*!< 位 1 */
#define  I2C_CR2_FREQ_2                      ((uint16_t)0x0004)            /*!< 位 2 */
#define  I2C_CR2_FREQ_3                      ((uint16_t)0x0008)            /*!< 位 3 */
#define  I2C_CR2_FREQ_4                      ((uint16_t)0x0010)            /*!< 位 4 */
#define  I2C_CR2_FREQ_5                      ((uint16_t)0x0020)            /*!< 位 5 */

#define  I2C_CR2_ITERREN                     ((uint16_t)0x0100)            /*!< 错误中断使能 */
#define  I2C_CR2_ITEVTEN                     ((uint16_t)0x0200)            /*!< 事件中断使能 */
#define  I2C_CR2_ITBUFEN                     ((uint16_t)0x0400)            /*!< 缓冲区中断使能 */
#define  I2C_CR2_DMAEN                       ((uint16_t)0x0800)            /*!< DMA 请求使能 */
#define  I2C_CR2_LAST                        ((uint16_t)0x1000)            /*!< DMA 最后一次传输 */

/******************* I2C_OAR1 寄存器的位定义 *****************/
#define  I2C_OAR1_ADD1_7                     ((uint16_t)0x00FE)            /*!< 接口地址 */
#define  I2C_OAR1_ADD8_9                     ((uint16_t)0x0300)            /*!< 接口地址 */

#define  I2C_OAR1_ADD0                       ((uint16_t)0x0001)            /*!< 位 0 */
#define  I2C_OAR1_ADD1                       ((uint16_t)0x0002)            /*!< 位 1 */
#define  I2C_OAR1_ADD2                       ((uint16_t)0x0004)            /*!< 位 2 */
#define  I2C_OAR1_ADD3                       ((uint16_t)0x0008)            /*!< 位 3 */
#define  I2C_OAR1_ADD4                       ((uint16_t)0x0010)            /*!< 位 4 */
#define  I2C_OAR1_ADD5                       ((uint16_t)0x0020)            /*!< 位 5 */
#define  I2C_OAR1_ADD6                       ((uint16_t)0x0040)            /*!< 位 6 */
#define  I2C_OAR1_ADD7                       ((uint16_t)0x0080)            /*!< 位 7 */
#define  I2C_OAR1_ADD8                       ((uint16_t)0x0100)            /*!< 位 8 */
#define  I2C_OAR1_ADD9                       ((uint16_t)0x0200)            /*!< 位 9 */

#define  I2C_OAR1_ADDMODE                    ((uint16_t)0x8000)            /*!< 寻址模式（从模式） */

/******************* I2C_OAR2 寄存器的位定义 *****************/
#define  I2C_OAR2_ENDUAL                     ((uint8_t)0x01)               /*!< 双地址模式使能 */
#define  I2C_OAR2_ADD2                       ((uint8_t)0xFE)               /*!< 接口地址 */

/******************** I2C_DR 寄存器的位定义 ******************/
#define  I2C_DR_DR                           ((uint8_t)0xFF)               /*!< 8 位数据寄存器 */

/******************* I2C_SR1 寄存器的位定义 *****************/
#define  I2C_SR1_SB                          ((uint16_t)0x0001)            /*!< 起始位（主模式） */
#define  I2C_SR1_ADDR                        ((uint16_t)0x0002)            /*!< 地址已发送（主模式）/已匹配（从模式） */
#define  I2C_SR1_BTF                         ((uint16_t)0x0004)            /*!< 字节传输完成 */
#define  I2C_SR1_ADD10                       ((uint16_t)0x0008)            /*!< 已发送 10 位头（主模式） */
#define  I2C_SR1_STOPF                       ((uint16_t)0x0010)            /*!< 停止检测（从模式） */
#define  I2C_SR1_RXNE                        ((uint16_t)0x0040)            /*!< 数据寄存器非空（接收器） */
#define  I2C_SR1_TXE                         ((uint16_t)0x0080)            /*!< 数据寄存器空（发送器） */
#define  I2C_SR1_BERR                        ((uint16_t)0x0100)            /*!< 总线错误 */
#define  I2C_SR1_ARLO                        ((uint16_t)0x0200)            /*!< 仲裁丢失（主模式） */
#define  I2C_SR1_AF                          ((uint16_t)0x0400)            /*!< 应答失败 */
#define  I2C_SR1_OVR                         ((uint16_t)0x0800)            /*!< 上溢/下溢 */
#define  I2C_SR1_PECERR                      ((uint16_t)0x1000)            /*!< 接收中的 PEC 错误 */
#define  I2C_SR1_TIMEOUT                     ((uint16_t)0x4000)            /*!< 超时或 Tlow 错误 */
#define  I2C_SR1_SMBALERT                    ((uint16_t)0x8000)            /*!< SMBus 报警 */

/******************* I2C_SR2 寄存器的位定义 *****************/
#define  I2C_SR2_MSL                         ((uint16_t)0x0001)            /*!< 主/从 */
#define  I2C_SR2_BUSY                        ((uint16_t)0x0002)            /*!< 总线忙 */
#define  I2C_SR2_TRA                         ((uint16_t)0x0004)            /*!< 发送器/接收器 */
#define  I2C_SR2_GENCALL                     ((uint16_t)0x0010)            /*!< 通用呼叫地址（从模式） */
#define  I2C_SR2_SMBDEFAULT                  ((uint16_t)0x0020)            /*!< SMBus 器件默认地址（从模式） */
#define  I2C_SR2_SMBHOST                     ((uint16_t)0x0040)            /*!< SMBus 主机头（从模式） */
#define  I2C_SR2_DUALF                       ((uint16_t)0x0080)            /*!< 双标志位（从模式） */
#define  I2C_SR2_PEC                         ((uint16_t)0xFF00)            /*!< 数据包错误校验寄存器 */

/******************* I2C_CCR 寄存器的位定义 *****************/
#define  I2C_CCR_CCR                         ((uint16_t)0x0FFF)            /*!< 快速/标准模式下的时钟控制寄存器（主模式） */
#define  I2C_CCR_DUTY                        ((uint16_t)0x4000)            /*!< 快速模式占空比 */
#define  I2C_CCR_FS                          ((uint16_t)0x8000)            /*!< I2C 主模式选择 */

/****************** I2C_TRISE 寄存器的位定义 ****************/
#define  I2C_TRISE_TRISE                     ((uint8_t)0x3F)               /*!< 快速/标准模式下的最大上升时间（主模式） */

/******************************************************************************/
/*                                                                            */
/*         通用同步异步收发器            */
/*                                                                            */
/******************************************************************************/

/******************* USART_SR 寄存器的位定义 *****************/
#define  USART_SR_PE                         ((uint16_t)0x0001)            /*!< 奇偶校验错误 */
#define  USART_SR_FE                         ((uint16_t)0x0002)            /*!< 帧错误 */
#define  USART_SR_NE                         ((uint16_t)0x0004)            /*!< 噪声错误标志位 */
#define  USART_SR_ORE                        ((uint16_t)0x0008)            /*!< 上溢错误 */
#define  USART_SR_IDLE                       ((uint16_t)0x0010)            /*!< 检测到 IDLE 线 */
#define  USART_SR_RXNE                       ((uint16_t)0x0020)            /*!< 读数据寄存器非空 */
#define  USART_SR_TC                         ((uint16_t)0x0040)            /*!< 传输完成 */
#define  USART_SR_TXE                        ((uint16_t)0x0080)            /*!< 发送数据寄存器空 */
#define  USART_SR_LBD                        ((uint16_t)0x0100)            /*!< LIN 间隔检测标志位 */
#define  USART_SR_CTS                        ((uint16_t)0x0200)            /*!< CTS 标志位 */

/******************* USART_DR 寄存器的位定义 *****************/
#define  USART_DR_DR                         ((uint16_t)0x01FF)            /*!< 数据值 */

/****************** USART_BRR 寄存器的位定义 ****************/
#define  USART_BRR_DIV_Fraction              ((uint16_t)0x000F)            /*!< USARTDIV 的小数部分 */
#define  USART_BRR_DIV_Mantissa              ((uint16_t)0xFFF0)            /*!< USARTDIV 的尾数 */

/****************** USART_CR1 寄存器的位定义 ****************/
#define  USART_CR1_SBK                       ((uint16_t)0x0001)            /*!< 发送间隔 */
#define  USART_CR1_RWU                       ((uint16_t)0x0002)            /*!< 接收器唤醒 */
#define  USART_CR1_RE                        ((uint16_t)0x0004)            /*!< 接收器使能 */
#define  USART_CR1_TE                        ((uint16_t)0x0008)            /*!< 发送器使能 */
#define  USART_CR1_IDLEIE                    ((uint16_t)0x0010)            /*!< IDLE 中断使能 */
#define  USART_CR1_RXNEIE                    ((uint16_t)0x0020)            /*!< RXNE 中断使能 */
#define  USART_CR1_TCIE                      ((uint16_t)0x0040)            /*!< 传输完成中断使能 */
#define  USART_CR1_TXEIE                     ((uint16_t)0x0080)            /*!< PE 中断使能 */
#define  USART_CR1_PEIE                      ((uint16_t)0x0100)            /*!< PE 中断使能 */
#define  USART_CR1_PS                        ((uint16_t)0x0200)            /*!< 奇偶校验选择 */
#define  USART_CR1_PCE                       ((uint16_t)0x0400)            /*!< 奇偶校验控制使能 */
#define  USART_CR1_WAKE                      ((uint16_t)0x0800)            /*!< 唤醒方式 */
#define  USART_CR1_M                         ((uint16_t)0x1000)            /*!< 字长 */
#define  USART_CR1_UE                        ((uint16_t)0x2000)            /*!< USART 使能 */
#define  USART_CR1_OVER8                     ((uint16_t)0x8000)            /*!< USART 8 倍过采样 */

/****************** USART_CR2 寄存器的位定义 ****************/
#define  USART_CR2_ADD                       ((uint16_t)0x000F)            /*!< USART 节点的地址 */
#define  USART_CR2_LBDL                      ((uint16_t)0x0020)            /*!< LIN 间隔检测长度 */
#define  USART_CR2_LBDIE                     ((uint16_t)0x0040)            /*!< LIN 间隔检测中断使能 */
#define  USART_CR2_LBCL                      ((uint16_t)0x0100)            /*!< 最后一位时钟脉冲 */
#define  USART_CR2_CPHA                      ((uint16_t)0x0200)            /*!< 时钟相位 */
#define  USART_CR2_CPOL                      ((uint16_t)0x0400)            /*!< 时钟极性 */
#define  USART_CR2_CLKEN                     ((uint16_t)0x0800)            /*!< 时钟使能 */

#define  USART_CR2_STOP                      ((uint16_t)0x3000)            /*!< STOP[1:0] 位（STOP 位） */
#define  USART_CR2_STOP_0                    ((uint16_t)0x1000)            /*!< 位 0 */
#define  USART_CR2_STOP_1                    ((uint16_t)0x2000)            /*!< 位 1 */

#define  USART_CR2_LINEN                     ((uint16_t)0x4000)            /*!< LIN 模式使能 */

/****************** USART_CR3 寄存器的位定义 ****************/
#define  USART_CR3_EIE                       ((uint16_t)0x0001)            /*!< 错误中断使能 */
#define  USART_CR3_IREN                      ((uint16_t)0x0002)            /*!< IrDA 模式使能 */
#define  USART_CR3_IRLP                      ((uint16_t)0x0004)            /*!< IrDA 低功耗 */
#define  USART_CR3_HDSEL                     ((uint16_t)0x0008)            /*!< 半双工选择 */
#define  USART_CR3_NACK                      ((uint16_t)0x0010)            /*!< 智能卡 NACK 使能 */
#define  USART_CR3_SCEN                      ((uint16_t)0x0020)            /*!< 智能卡模式使能 */
#define  USART_CR3_DMAR                      ((uint16_t)0x0040)            /*!< DMA 接收使能 */
#define  USART_CR3_DMAT                      ((uint16_t)0x0080)            /*!< DMA 发送使能 */
#define  USART_CR3_RTSE                      ((uint16_t)0x0100)            /*!< RTS 使能 */
#define  USART_CR3_CTSE                      ((uint16_t)0x0200)            /*!< CTS 使能 */
#define  USART_CR3_CTSIE                     ((uint16_t)0x0400)            /*!< CTS 中断使能 */
#define  USART_CR3_ONEBIT                    ((uint16_t)0x0800)            /*!< 单位方法 */

/****************** USART_GTPR 寄存器的位定义 ****************/
#define  USART_GTPR_PSC                      ((uint16_t)0x00FF)            /*!< PSC[7:0] 位（预分频值） */
#define  USART_GTPR_PSC_0                    ((uint16_t)0x0001)            /*!< 位 0 */
#define  USART_GTPR_PSC_1                    ((uint16_t)0x0002)            /*!< 位 1 */
#define  USART_GTPR_PSC_2                    ((uint16_t)0x0004)            /*!< 位 2 */
#define  USART_GTPR_PSC_3                    ((uint16_t)0x0008)            /*!< 位 3 */
#define  USART_GTPR_PSC_4                    ((uint16_t)0x0010)            /*!< 位 4 */
#define  USART_GTPR_PSC_5                    ((uint16_t)0x0020)            /*!< 位 5 */
#define  USART_GTPR_PSC_6                    ((uint16_t)0x0040)            /*!< 位 6 */
#define  USART_GTPR_PSC_7                    ((uint16_t)0x0080)            /*!< 位 7 */

#define  USART_GTPR_GT                       ((uint16_t)0xFF00)            /*!< 保护时间值 */

/******************************************************************************/
/*                                                                            */
/*                                 调试 MCU                                  */
/*                                                                            */
/******************************************************************************/

/**************** DBGMCU_IDCODE 寄存器的位定义 **************/
#define  DBGMCU_IDCODE_DEV_ID                ((uint32_t)0x00000FFF)        /*!< 器件标识符 */

#define  DBGMCU_IDCODE_REV_ID                ((uint32_t)0xFFFF0000)        /*!< REV_ID[15:0] 位（修订标识符） */
#define  DBGMCU_IDCODE_REV_ID_0              ((uint32_t)0x00010000)        /*!< 位 0 */
#define  DBGMCU_IDCODE_REV_ID_1              ((uint32_t)0x00020000)        /*!< 位 1 */
#define  DBGMCU_IDCODE_REV_ID_2              ((uint32_t)0x00040000)        /*!< 位 2 */
#define  DBGMCU_IDCODE_REV_ID_3              ((uint32_t)0x00080000)        /*!< 位 3 */
#define  DBGMCU_IDCODE_REV_ID_4              ((uint32_t)0x00100000)        /*!< 位 4 */
#define  DBGMCU_IDCODE_REV_ID_5              ((uint32_t)0x00200000)        /*!< 位 5 */
#define  DBGMCU_IDCODE_REV_ID_6              ((uint32_t)0x00400000)        /*!< 位 6 */
#define  DBGMCU_IDCODE_REV_ID_7              ((uint32_t)0x00800000)        /*!< 位 7 */
#define  DBGMCU_IDCODE_REV_ID_8              ((uint32_t)0x01000000)        /*!< 位 8 */
#define  DBGMCU_IDCODE_REV_ID_9              ((uint32_t)0x02000000)        /*!< 位 9 */
#define  DBGMCU_IDCODE_REV_ID_10             ((uint32_t)0x04000000)        /*!< 位 10 */
#define  DBGMCU_IDCODE_REV_ID_11             ((uint32_t)0x08000000)        /*!< 位 11 */
#define  DBGMCU_IDCODE_REV_ID_12             ((uint32_t)0x10000000)        /*!< 位 12 */
#define  DBGMCU_IDCODE_REV_ID_13             ((uint32_t)0x20000000)        /*!< 位 13 */
#define  DBGMCU_IDCODE_REV_ID_14             ((uint32_t)0x40000000)        /*!< 位 14 */
#define  DBGMCU_IDCODE_REV_ID_15             ((uint32_t)0x80000000)        /*!< 位 15 */

/****************** DBGMCU_CR 寄存器的位定义 ****************/
#define  DBGMCU_CR_DBG_SLEEP                 ((uint32_t)0x00000001)        /*!< 调试睡眠模式 */
#define  DBGMCU_CR_DBG_STOP                  ((uint32_t)0x00000002)        /*!< 调试停止模式 */
#define  DBGMCU_CR_DBG_STANDBY               ((uint32_t)0x00000004)        /*!< 调试待机模式 */
#define  DBGMCU_CR_TRACE_IOEN                ((uint32_t)0x00000020)        /*!< 跟踪引脚分配控制 */

#define  DBGMCU_CR_TRACE_MODE                ((uint32_t)0x000000C0)        /*!< TRACE_MODE[1:0] 位（跟踪引脚分配控制） */
#define  DBGMCU_CR_TRACE_MODE_0              ((uint32_t)0x00000040)        /*!< 位 0 */
#define  DBGMCU_CR_TRACE_MODE_1              ((uint32_t)0x00000080)        /*!< 位 1 */

#define  DBGMCU_CR_DBG_IWDG_STOP             ((uint32_t)0x00000100)        /*!< 内核停止时调试独立看门狗停止 */
#define  DBGMCU_CR_DBG_WWDG_STOP             ((uint32_t)0x00000200)        /*!< 内核停止时调试窗口看门狗停止 */
#define  DBGMCU_CR_DBG_TIM1_STOP             ((uint32_t)0x00000400)        /*!< 内核停止时 TIM1 计数器停止 */
#define  DBGMCU_CR_DBG_TIM2_STOP             ((uint32_t)0x00000800)        /*!< 内核停止时 TIM2 计数器停止 */
#define  DBGMCU_CR_DBG_TIM3_STOP             ((uint32_t)0x00001000)        /*!< 内核停止时 TIM3 计数器停止 */
#define  DBGMCU_CR_DBG_TIM4_STOP             ((uint32_t)0x00002000)        /*!< 内核停止时 TIM4 计数器停止 */
#define  DBGMCU_CR_DBG_CAN1_STOP             ((uint32_t)0x00004000)        /*!< 内核停止时调试 CAN1 停止 */
#define  DBGMCU_CR_DBG_I2C1_SMBUS_TIMEOUT    ((uint32_t)0x00008000)        /*!< 内核停止时 SMBUS 超时模式停止 */
#define  DBGMCU_CR_DBG_I2C2_SMBUS_TIMEOUT    ((uint32_t)0x00010000)        /*!< 内核停止时 SMBUS 超时模式停止 */
#define  DBGMCU_CR_DBG_TIM8_STOP             ((uint32_t)0x00020000)        /*!< 内核停止时 TIM8 计数器停止 */
#define  DBGMCU_CR_DBG_TIM5_STOP             ((uint32_t)0x00040000)        /*!< 内核停止时 TIM5 计数器停止 */
#define  DBGMCU_CR_DBG_TIM6_STOP             ((uint32_t)0x00080000)        /*!< 内核停止时 TIM6 计数器停止 */
#define  DBGMCU_CR_DBG_TIM7_STOP             ((uint32_t)0x00100000)        /*!< 内核停止时 TIM7 计数器停止 */
#define  DBGMCU_CR_DBG_CAN2_STOP             ((uint32_t)0x00200000)        /*!< 内核停止时调试 CAN2 停止 */
#define  DBGMCU_CR_DBG_TIM15_STOP            ((uint32_t)0x00400000)        /*!< 内核停止时调试 TIM15 停止 */
#define  DBGMCU_CR_DBG_TIM16_STOP            ((uint32_t)0x00800000)        /*!< 内核停止时调试 TIM16 停止 */
#define  DBGMCU_CR_DBG_TIM17_STOP            ((uint32_t)0x01000000)        /*!< 内核停止时调试 TIM17 停止 */
#define  DBGMCU_CR_DBG_TIM12_STOP            ((uint32_t)0x02000000)        /*!< 内核停止时调试 TIM12 停止 */
#define  DBGMCU_CR_DBG_TIM13_STOP            ((uint32_t)0x04000000)        /*!< 内核停止时调试 TIM13 停止 */
#define  DBGMCU_CR_DBG_TIM14_STOP            ((uint32_t)0x08000000)        /*!< 内核停止时调试 TIM14 停止 */
#define  DBGMCU_CR_DBG_TIM9_STOP             ((uint32_t)0x10000000)        /*!< 内核停止时调试 TIM9 停止 */
#define  DBGMCU_CR_DBG_TIM10_STOP            ((uint32_t)0x20000000)        /*!< 内核停止时调试 TIM10 停止 */
#define  DBGMCU_CR_DBG_TIM11_STOP            ((uint32_t)0x40000000)        /*!< 内核停止时调试 TIM11 停止 */

/******************************************************************************/
/*                                                                            */
/*                      闪存和选项字节寄存器                      */
/*                                                                            */
/******************************************************************************/

/******************* FLASH_ACR 寄存器的位定义 *****************/
#define  FLASH_ACR_LATENCY                   ((uint8_t)0x03)               /*!< LATENCY[2:0] 位（延迟） */
#define  FLASH_ACR_LATENCY_0                 ((uint8_t)0x00)               /*!< 位 0 */
#define  FLASH_ACR_LATENCY_1                 ((uint8_t)0x01)               /*!< 位 0 */
#define  FLASH_ACR_LATENCY_2                 ((uint8_t)0x02)               /*!< 位 1 */

#define  FLASH_ACR_HLFCYA                    ((uint8_t)0x08)               /*!< 闪存半周期访问使能 */
#define  FLASH_ACR_PRFTBE                    ((uint8_t)0x10)               /*!< 预取缓冲区使能 */
#define  FLASH_ACR_PRFTBS                    ((uint8_t)0x20)               /*!< 预取缓冲区状态 */

/****************** FLASH_KEYR 寄存器的位定义 ****************/
#define  FLASH_KEYR_FKEYR                    ((uint32_t)0xFFFFFFFF)        /*!< FPEC 键 */

/***************** FLASH_OPTKEYR 寄存器的位定义 ***************/
#define  FLASH_OPTKEYR_OPTKEYR               ((uint32_t)0xFFFFFFFF)        /*!< 选项字节键 */

/****************** FLASH_SR 寄存器的位定义 ****************/
#define  FLASH_SR_BSY                        ((uint8_t)0x01)               /*!< 忙 */
#define  FLASH_SR_PGERR                      ((uint8_t)0x04)               /*!< 编程错误 */
#define  FLASH_SR_WRPRTERR                   ((uint8_t)0x10)               /*!< 写保护错误 */
#define  FLASH_SR_EOP                        ((uint8_t)0x20)               /*!< 操作结束 */

/******************* FLASH_CR 寄存器的位定义 *****************/
#define  FLASH_CR_PG                         ((uint16_t)0x0001)            /*!< 编程 */
#define  FLASH_CR_PER                        ((uint16_t)0x0002)            /*!< 页擦除 */
#define  FLASH_CR_MER                        ((uint16_t)0x0004)            /*!< 批量擦除 */
#define  FLASH_CR_OPTPG                      ((uint16_t)0x0010)            /*!< 选项字节编程 */
#define  FLASH_CR_OPTER                      ((uint16_t)0x0020)            /*!< 选项字节擦除 */
#define  FLASH_CR_STRT                       ((uint16_t)0x0040)            /*!< 启动 */
#define  FLASH_CR_LOCK                       ((uint16_t)0x0080)            /*!< 锁定 */
#define  FLASH_CR_OPTWRE                     ((uint16_t)0x0200)            /*!< 选项字节写使能 */
#define  FLASH_CR_ERRIE                      ((uint16_t)0x0400)            /*!< 错误中断使能 */
#define  FLASH_CR_EOPIE                      ((uint16_t)0x1000)            /*!< 操作结束中断使能 */

/******************* FLASH_AR 寄存器的位定义 *****************/
#define  FLASH_AR_FAR                        ((uint32_t)0xFFFFFFFF)        /*!< 闪存地址 */

/****************** FLASH_OBR 寄存器的位定义 ****************/
#define  FLASH_OBR_OPTERR                    ((uint16_t)0x0001)            /*!< 选项字节错误 */
#define  FLASH_OBR_RDPRT                     ((uint16_t)0x0002)            /*!< 读保护 */

#define  FLASH_OBR_USER                      ((uint16_t)0x03FC)            /*!< 用户选项字节 */
#define  FLASH_OBR_WDG_SW                    ((uint16_t)0x0004)            /*!< WDG_SW */
#define  FLASH_OBR_nRST_STOP                 ((uint16_t)0x0008)            /*!< nRST_STOP */
#define  FLASH_OBR_nRST_STDBY                ((uint16_t)0x0010)            /*!< nRST_STDBY */
#define  FLASH_OBR_BFB2                      ((uint16_t)0x0020)            /*!< BFB2 */

/****************** FLASH_WRPR 寄存器的位定义 ****************/
#define  FLASH_WRPR_WRP                        ((uint32_t)0xFFFFFFFF)        /*!< 写保护 */

/*----------------------------------------------------------------------------*/

/****************** FLASH_RDP 寄存器的位定义 ****************/
#define  FLASH_RDP_RDP                       ((uint32_t)0x000000FF)        /*!< 读保护选项字节 */
#define  FLASH_RDP_nRDP                      ((uint32_t)0x0000FF00)        /*!< 读保护互补选项字节 */

/****************** FLASH_USER 寄存器的位定义 ****************/
#define  FLASH_USER_USER                     ((uint32_t)0x00FF0000)        /*!< 用户选项字节 */
#define  FLASH_USER_nUSER                    ((uint32_t)0xFF000000)        /*!< 用户互补选项字节 */

/****************** FLASH_Data0 寄存器的位定义 ****************/
#define  FLASH_Data0_Data0                   ((uint32_t)0x000000FF)        /*!< 用户数据存储选项字节 */
#define  FLASH_Data0_nData0                  ((uint32_t)0x0000FF00)        /*!< 用户数据存储互补选项字节 */

/****************** FLASH_Data1 寄存器的位定义 ****************/
#define  FLASH_Data1_Data1                   ((uint32_t)0x00FF0000)        /*!< 用户数据存储选项字节 */
#define  FLASH_Data1_nData1                  ((uint32_t)0xFF000000)        /*!< 用户数据存储互补选项字节 */

/****************** FLASH_WRP0 寄存器的位定义 ****************/
#define  FLASH_WRP0_WRP0                     ((uint32_t)0x000000FF)        /*!< 闪存写保护选项字节 */
#define  FLASH_WRP0_nWRP0                    ((uint32_t)0x0000FF00)        /*!< 闪存写保护互补选项字节 */

/****************** FLASH_WRP1 寄存器的位定义 ****************/
#define  FLASH_WRP1_WRP1                     ((uint32_t)0x00FF0000)        /*!< 闪存写保护选项字节 */
#define  FLASH_WRP1_nWRP1                    ((uint32_t)0xFF000000)        /*!< 闪存写保护互补选项字节 */

/****************** FLASH_WRP2 寄存器的位定义 ****************/
#define  FLASH_WRP2_WRP2                     ((uint32_t)0x000000FF)        /*!< 闪存写保护选项字节 */
#define  FLASH_WRP2_nWRP2                    ((uint32_t)0x0000FF00)        /*!< 闪存写保护互补选项字节 */

/****************** FLASH_WRP3 寄存器的位定义 ****************/
#define  FLASH_WRP3_WRP3                     ((uint32_t)0x00FF0000)        /*!< 闪存写保护选项字节 */
#define  FLASH_WRP3_nWRP3                    ((uint32_t)0xFF000000)        /*!< 闪存写保护互补选项字节 */

#ifdef STM32F10X_CL
/******************************************************************************/
/*                以太网 MAC 寄存器位定义                     */
/******************************************************************************/
/* 以太网 MAC 控制寄存器位定义 */
#define ETH_MACCR_WD      ((uint32_t)0x00800000)  /* 看门狗禁止 */
#define ETH_MACCR_JD      ((uint32_t)0x00400000)  /* Jabber 禁止 */
#define ETH_MACCR_IFG     ((uint32_t)0x000E0000)  /* 帧间隔 */
  #define ETH_MACCR_IFG_96Bit     ((uint32_t)0x00000000)  /* 发送时帧间最小 IFG 为 96 位 */
  #define ETH_MACCR_IFG_88Bit     ((uint32_t)0x00020000)  /* 发送时帧间最小 IFG 为 88 位 */
  #define ETH_MACCR_IFG_80Bit     ((uint32_t)0x00040000)  /* 发送时帧间最小 IFG 为 80 位 */
  #define ETH_MACCR_IFG_72Bit     ((uint32_t)0x00060000)  /* 发送时帧间最小 IFG 为 72 位 */
  #define ETH_MACCR_IFG_64Bit     ((uint32_t)0x00080000)  /* 发送时帧间最小 IFG 为 64 位 */        
  #define ETH_MACCR_IFG_56Bit     ((uint32_t)0x000A0000)  /* 发送时帧间最小 IFG 为 56 位 */
  #define ETH_MACCR_IFG_48Bit     ((uint32_t)0x000C0000)  /* 发送时帧间最小 IFG 为 48 位 */
  #define ETH_MACCR_IFG_40Bit     ((uint32_t)0x000E0000)  /* 发送时帧间最小 IFG 为 40 位 */              
#define ETH_MACCR_CSD     ((uint32_t)0x00010000)  /* 载波侦听禁止（发送期间） */
#define ETH_MACCR_FES     ((uint32_t)0x00004000)  /* 快速以太网速率 */
#define ETH_MACCR_ROD     ((uint32_t)0x00002000)  /* 禁止接收自身 */
#define ETH_MACCR_LM      ((uint32_t)0x00001000)  /* 回环模式 */
#define ETH_MACCR_DM      ((uint32_t)0x00000800)  /* 双工模式 */
#define ETH_MACCR_IPCO    ((uint32_t)0x00000400)  /* IP 校验和卸载 */
#define ETH_MACCR_RD      ((uint32_t)0x00000200)  /* 重试禁止 */
#define ETH_MACCR_APCS    ((uint32_t)0x00000080)  /* 自动填充/CRC 剥离 */
#define ETH_MACCR_BL      ((uint32_t)0x00000060)  /* 退避上限：在重新调度之前，随机整数个（r）时隙延迟
                                                       用于冲突后的重传：0 =< r <2^k */
  #define ETH_MACCR_BL_10    ((uint32_t)0x00000000)  /* k = min (n, 10) */
  #define ETH_MACCR_BL_8     ((uint32_t)0x00000020)  /* k = min (n, 8) */
  #define ETH_MACCR_BL_4     ((uint32_t)0x00000040)  /* k = min (n, 4) */
  #define ETH_MACCR_BL_1     ((uint32_t)0x00000060)  /* k = min (n, 1) */ 
#define ETH_MACCR_DC      ((uint32_t)0x00000010)  /* 延迟检查 */
#define ETH_MACCR_TE      ((uint32_t)0x00000008)  /* 发送器使能 */
#define ETH_MACCR_RE      ((uint32_t)0x00000004)  /* 接收器使能 */

/* 以太网 MAC 帧过滤寄存器位定义 */
#define ETH_MACFFR_RA     ((uint32_t)0x80000000)  /* 接收全部 */ 
#define ETH_MACFFR_HPF    ((uint32_t)0x00000400)  /* 哈希或完美过滤 */ 
#define ETH_MACFFR_SAF    ((uint32_t)0x00000200)  /* 源地址过滤使能 */ 
#define ETH_MACFFR_SAIF   ((uint32_t)0x00000100)  /* SA 反向过滤 */ 
#define ETH_MACFFR_PCF    ((uint32_t)0x000000C0)  /* 通过控制帧：3 种情况 */
  #define ETH_MACFFR_PCF_BlockAll                ((uint32_t)0x00000040)  /* MAC 过滤所有控制帧，使其不传递给应用程序 */
  #define ETH_MACFFR_PCF_ForwardAll              ((uint32_t)0x00000080)  /* 即使控制帧未通过地址过滤，MAC 也将其全部转发给应用程序 */
  #define ETH_MACFFR_PCF_ForwardPassedAddrFilter ((uint32_t)0x000000C0)  /* MAC 转发通过地址过滤的控制帧。 */ 
#define ETH_MACFFR_BFD    ((uint32_t)0x00000020)  /* 广播帧禁止 */ 
#define ETH_MACFFR_PAM 	  ((uint32_t)0x00000010)  /* 通过所有多播 */ 
#define ETH_MACFFR_DAIF   ((uint32_t)0x00000008)  /* DA 反向过滤 */ 
#define ETH_MACFFR_HM     ((uint32_t)0x00000004)  /* 哈希多播 */ 
#define ETH_MACFFR_HU     ((uint32_t)0x00000002)  /* 哈希单播 */
#define ETH_MACFFR_PM     ((uint32_t)0x00000001)  /* 混杂模式 */

/* 以太网 MAC 哈希表高位寄存器位定义 */
#define ETH_MACHTHR_HTH   ((uint32_t)0xFFFFFFFF)  /* 哈希表高位 */

/* 以太网 MAC 哈希表低位寄存器位定义 */
#define ETH_MACHTLR_HTL   ((uint32_t)0xFFFFFFFF)  /* 哈希表低位 */

/* 以太网 MAC MII 地址寄存器位定义 */
#define ETH_MACMIIAR_PA   ((uint32_t)0x0000F800)  /* 物理层地址 */ 
#define ETH_MACMIIAR_MR   ((uint32_t)0x000007C0)  /* 所选 PHY 中的 MII 寄存器 */ 
#define ETH_MACMIIAR_CR   ((uint32_t)0x0000001C)  /* CR 时钟范围：6 种情况 */ 
  #define ETH_MACMIIAR_CR_Div42   ((uint32_t)0x00000000)  /* HCLK:60-72 MHz；MDC 时钟 = HCLK/42 */
  #define ETH_MACMIIAR_CR_Div16   ((uint32_t)0x00000008)  /* HCLK:20-35 MHz；MDC 时钟 = HCLK/16 */
  #define ETH_MACMIIAR_CR_Div26   ((uint32_t)0x0000000C)  /* HCLK:35-60 MHz；MDC 时钟 = HCLK/26 */
#define ETH_MACMIIAR_MW   ((uint32_t)0x00000002)  /* MII 写 */ 
#define ETH_MACMIIAR_MB   ((uint32_t)0x00000001)  /* MII 忙 */ 
  
/* 以太网 MAC MII 数据寄存器位定义 */
#define ETH_MACMIIDR_MD   ((uint32_t)0x0000FFFF)  /* MII 数据：与 PHY 之间读/写的数据 */

/* 以太网 MAC 流控制寄存器位定义 */
#define ETH_MACFCR_PT     ((uint32_t)0xFFFF0000)  /* 暂停时间 */
#define ETH_MACFCR_ZQPD   ((uint32_t)0x00000080)  /* 零量子暂停禁止 */
#define ETH_MACFCR_PLT    ((uint32_t)0x00000030)  /* 暂停低阈值：4 种情况 */
  #define ETH_MACFCR_PLT_Minus4   ((uint32_t)0x00000000)  /* 暂停时间减 4 个时隙 */
  #define ETH_MACFCR_PLT_Minus28  ((uint32_t)0x00000010)  /* 暂停时间减 28 个时隙 */
  #define ETH_MACFCR_PLT_Minus144 ((uint32_t)0x00000020)  /* 暂停时间减 144 个时隙 */
  #define ETH_MACFCR_PLT_Minus256 ((uint32_t)0x00000030)  /* 暂停时间减 256 个时隙 */      
#define ETH_MACFCR_UPFD   ((uint32_t)0x00000008)  /* 单播暂停帧检测 */
#define ETH_MACFCR_RFCE   ((uint32_t)0x00000004)  /* 接收流控制使能 */
#define ETH_MACFCR_TFCE   ((uint32_t)0x00000002)  /* 发送流控制使能 */
#define ETH_MACFCR_FCBBPA ((uint32_t)0x00000001)  /* 流控制忙/反压激活 */

/* 以太网 MAC VLAN 标签寄存器位定义 */
#define ETH_MACVLANTR_VLANTC ((uint32_t)0x00010000)  /* 12 位 VLAN 标签比较 */
#define ETH_MACVLANTR_VLANTI ((uint32_t)0x0000FFFF)  /* VLAN 标签标识符（用于接收帧） */

/* 以太网 MAC 远程唤醒帧过滤器寄存器位定义 */ 
#define ETH_MACRWUFFR_D   ((uint32_t)0xFFFFFFFF)  /* 唤醒帧过滤器寄存器数据 */
/* 对该地址（偏移 0x28）连续写入 8 次，将写入所有唤醒帧过滤器寄存器。
   对该地址（偏移 0x28）连续读取 8 次，将读取所有唤醒帧过滤器寄存器。 */
/* 唤醒帧过滤器寄存器 0：过滤器 0 字节屏蔽
   唤醒帧过滤器寄存器 1：过滤器 1 字节屏蔽
   唤醒帧过滤器寄存器 2：过滤器 2 字节屏蔽
   唤醒帧过滤器寄存器 3：过滤器 3 字节屏蔽
   唤醒帧过滤器寄存器 4：保留 - 过滤器 3 命令 - 保留 - 过滤器 2 命令 - 
                              保留 - 过滤器 1 命令 - 保留 - 过滤器 0 命令
   唤醒帧过滤器寄存器 5：过滤器 3 偏移 - 过滤器 2 偏移 - 过滤器 1 偏移 - 过滤器 0 偏移
   唤醒帧过滤器寄存器 6：过滤器 1 CRC16 - 过滤器 0 CRC16
   唤醒帧过滤器寄存器 7：过滤器 3 CRC16 - 过滤器 2 CRC16 */

/* 以太网 MAC PMT 控制与状态寄存器位定义 */ 
#define ETH_MACPMTCSR_WFFRPR ((uint32_t)0x80000000)  /* 唤醒帧过滤器寄存器指针复位 */
#define ETH_MACPMTCSR_GU     ((uint32_t)0x00000200)  /* 全局单播 */
#define ETH_MACPMTCSR_WFR    ((uint32_t)0x00000040)  /* 收到唤醒帧 */
#define ETH_MACPMTCSR_MPR    ((uint32_t)0x00000020)  /* 收到魔术包 */
#define ETH_MACPMTCSR_WFE    ((uint32_t)0x00000004)  /* 唤醒帧使能 */
#define ETH_MACPMTCSR_MPE    ((uint32_t)0x00000002)  /* 魔术包使能 */
#define ETH_MACPMTCSR_PD     ((uint32_t)0x00000001)  /* 掉电 */

/* 以太网 MAC 状态寄存器位定义 */
#define ETH_MACSR_TSTS      ((uint32_t)0x00000200)  /* 时间戳触发状态 */
#define ETH_MACSR_MMCTS     ((uint32_t)0x00000040)  /* MMC 发送状态 */
#define ETH_MACSR_MMMCRS    ((uint32_t)0x00000020)  /* MMC 接收状态 */
#define ETH_MACSR_MMCS      ((uint32_t)0x00000010)  /* MMC 状态 */
#define ETH_MACSR_PMTS      ((uint32_t)0x00000008)  /* PMT 状态 */

/* 以太网 MAC 中断屏蔽寄存器位定义 */
#define ETH_MACIMR_TSTIM     ((uint32_t)0x00000200)  /* 时间戳触发中断屏蔽 */
#define ETH_MACIMR_PMTIM     ((uint32_t)0x00000008)  /* PMT 中断屏蔽 */

/* 以太网 MAC 地址 0 高位寄存器位定义 */
#define ETH_MACA0HR_MACA0H   ((uint32_t)0x0000FFFF)  /* MAC 地址 0 高位 */

/* 以太网 MAC 地址 0 低位寄存器位定义 */
#define ETH_MACA0LR_MACA0L   ((uint32_t)0xFFFFFFFF)  /* MAC 地址 0 低位 */

/* 以太网 MAC 地址 1 高位寄存器位定义 */
#define ETH_MACA1HR_AE       ((uint32_t)0x80000000)  /* 地址使能 */
#define ETH_MACA1HR_SA       ((uint32_t)0x40000000)  /* 源地址 */
#define ETH_MACA1HR_MBC      ((uint32_t)0x3F000000)  /* 屏蔽字节控制：比较 MAC 地址字节时要屏蔽的位 */
  #define ETH_MACA1HR_MBC_HBits15_8    ((uint32_t)0x20000000)  /* 屏蔽 MAC 地址高位寄存器的位 [15:8] */
  #define ETH_MACA1HR_MBC_HBits7_0     ((uint32_t)0x10000000)  /* 屏蔽 MAC 地址高位寄存器的位 [7:0] */
  #define ETH_MACA1HR_MBC_LBits31_24   ((uint32_t)0x08000000)  /* 屏蔽 MAC 地址低位寄存器的位 [31:24] */
  #define ETH_MACA1HR_MBC_LBits23_16   ((uint32_t)0x04000000)  /* 屏蔽 MAC 地址低位寄存器的位 [23:16] */
  #define ETH_MACA1HR_MBC_LBits15_8    ((uint32_t)0x02000000)  /* 屏蔽 MAC 地址低位寄存器的位 [15:8] */
  #define ETH_MACA1HR_MBC_LBits7_0     ((uint32_t)0x01000000)  /* 屏蔽 MAC 地址低位寄存器的位 [7:0] */ 
#define ETH_MACA1HR_MACA1H   ((uint32_t)0x0000FFFF)  /* MAC 地址 1 高位 */

/* 以太网 MAC 地址 1 低位寄存器位定义 */
#define ETH_MACA1LR_MACA1L   ((uint32_t)0xFFFFFFFF)  /* MAC 地址 1 低位 */

/* 以太网 MAC 地址 2 高位寄存器位定义 */
#define ETH_MACA2HR_AE       ((uint32_t)0x80000000)  /* 地址使能 */
#define ETH_MACA2HR_SA       ((uint32_t)0x40000000)  /* 源地址 */
#define ETH_MACA2HR_MBC      ((uint32_t)0x3F000000)  /* 屏蔽字节控制 */
  #define ETH_MACA2HR_MBC_HBits15_8    ((uint32_t)0x20000000)  /* 屏蔽 MAC 地址高位寄存器的位 [15:8] */
  #define ETH_MACA2HR_MBC_HBits7_0     ((uint32_t)0x10000000)  /* 屏蔽 MAC 地址高位寄存器的位 [7:0] */
  #define ETH_MACA2HR_MBC_LBits31_24   ((uint32_t)0x08000000)  /* 屏蔽 MAC 地址低位寄存器的位 [31:24] */
  #define ETH_MACA2HR_MBC_LBits23_16   ((uint32_t)0x04000000)  /* 屏蔽 MAC 地址低位寄存器的位 [23:16] */
  #define ETH_MACA2HR_MBC_LBits15_8    ((uint32_t)0x02000000)  /* 屏蔽 MAC 地址低位寄存器的位 [15:8] */
  #define ETH_MACA2HR_MBC_LBits7_0     ((uint32_t)0x01000000)  /* 屏蔽 MAC 地址低位寄存器的位 [70] */
#define ETH_MACA2HR_MACA2H   ((uint32_t)0x0000FFFF)  /* MAC 地址 1 高位 */

/* 以太网 MAC 地址 2 低位寄存器位定义 */
#define ETH_MACA2LR_MACA2L   ((uint32_t)0xFFFFFFFF)  /* MAC 地址 2 低位 */

/* 以太网 MAC 地址 3 高位寄存器位定义 */
#define ETH_MACA3HR_AE       ((uint32_t)0x80000000)  /* 地址使能 */
#define ETH_MACA3HR_SA       ((uint32_t)0x40000000)  /* 源地址 */
#define ETH_MACA3HR_MBC      ((uint32_t)0x3F000000)  /* 屏蔽字节控制 */
  #define ETH_MACA3HR_MBC_HBits15_8    ((uint32_t)0x20000000)  /* 屏蔽 MAC 地址高位寄存器的位 [15:8] */
  #define ETH_MACA3HR_MBC_HBits7_0     ((uint32_t)0x10000000)  /* 屏蔽 MAC 地址高位寄存器的位 [7:0] */
  #define ETH_MACA3HR_MBC_LBits31_24   ((uint32_t)0x08000000)  /* 屏蔽 MAC 地址低位寄存器的位 [31:24] */
  #define ETH_MACA3HR_MBC_LBits23_16   ((uint32_t)0x04000000)  /* 屏蔽 MAC 地址低位寄存器的位 [23:16] */
  #define ETH_MACA3HR_MBC_LBits15_8    ((uint32_t)0x02000000)  /* 屏蔽 MAC 地址低位寄存器的位 [15:8] */
  #define ETH_MACA3HR_MBC_LBits7_0     ((uint32_t)0x01000000)  /* 屏蔽 MAC 地址低位寄存器的位 [70] */
#define ETH_MACA3HR_MACA3H   ((uint32_t)0x0000FFFF)  /* MAC 地址 3 高位 */

/* 以太网 MAC 地址 3 低位寄存器位定义 */
#define ETH_MACA3LR_MACA3L   ((uint32_t)0xFFFFFFFF)  /* MAC 地址 3 低位 */

/******************************************************************************/
/*                以太网 MMC 寄存器位定义                      */
/******************************************************************************/

/* 以太网 MMC 控制寄存器位定义 */
#define ETH_MMCCR_MCF        ((uint32_t)0x00000008)  /* MMC 计数器冻结 */
#define ETH_MMCCR_ROR        ((uint32_t)0x00000004)  /* 读取时复位 */
#define ETH_MMCCR_CSR        ((uint32_t)0x00000002)  /* 计数器停止时回绕 */
#define ETH_MMCCR_CR         ((uint32_t)0x00000001)  /* 计数器复位 */

/* 以太网 MMC 接收中断寄存器位定义 */
#define ETH_MMCRIR_RGUFS     ((uint32_t)0x00020000)  /* 当接收有效单播帧计数器达到最大值一半时置位 */
#define ETH_MMCRIR_RFAES     ((uint32_t)0x00000040)  /* 当接收对齐错误计数器达到最大值一半时置位 */
#define ETH_MMCRIR_RFCES     ((uint32_t)0x00000020)  /* 当接收 CRC 错误计数器达到最大值一半时置位 */

/* 以太网 MMC 发送中断寄存器位定义 */
#define ETH_MMCTIR_TGFS      ((uint32_t)0x00200000)  /* 当发送有效帧计数计数器达到最大值一半时置位 */
#define ETH_MMCTIR_TGFMSCS   ((uint32_t)0x00008000)  /* 当发送多次冲突有效帧计数器达到最大值一半时置位 */
#define ETH_MMCTIR_TGFSCS    ((uint32_t)0x00004000)  /* 当发送单次冲突有效帧计数器达到最大值一半时置位 */

/* 以太网 MMC 接收中断屏蔽寄存器位定义 */
#define ETH_MMCRIMR_RGUFM    ((uint32_t)0x00020000)  /* 当接收有效单播帧计数器达到最大值一半时屏蔽中断 */
#define ETH_MMCRIMR_RFAEM    ((uint32_t)0x00000040)  /* 当接收对齐错误计数器达到最大值一半时屏蔽中断 */
#define ETH_MMCRIMR_RFCEM    ((uint32_t)0x00000020)  /* 当接收 CRC 错误计数器达到最大值一半时屏蔽中断 */

/* 以太网 MMC 发送中断屏蔽寄存器位定义 */
#define ETH_MMCTIMR_TGFM     ((uint32_t)0x00200000)  /* 当发送有效帧计数计数器达到最大值一半时屏蔽中断 */
#define ETH_MMCTIMR_TGFMSCM  ((uint32_t)0x00008000)  /* 当发送多次冲突有效帧计数器达到最大值一半时屏蔽中断 */
#define ETH_MMCTIMR_TGFSCM   ((uint32_t)0x00004000)  /* 当发送单次冲突有效帧计数器达到最大值一半时屏蔽中断 */

/* 以太网 MMC 单次冲突后发送的有效帧计数器寄存器位定义 */
#define ETH_MMCTGFSCCR_TGFSCC     ((uint32_t)0xFFFFFFFF)  /* 半双工模式下单次冲突后成功发送的帧数。 */

/* 以太网 MMC 多于一次冲突后发送的有效帧计数器寄存器位定义 */
#define ETH_MMCTGFMSCCR_TGFMSCC   ((uint32_t)0xFFFFFFFF)  /* 半双工模式下多于一次冲突后成功发送的帧数。 */

/* 以太网 MMC 发送的有效帧计数器寄存器位定义 */
#define ETH_MMCTGFCR_TGFC    ((uint32_t)0xFFFFFFFF)  /* 发送的有效帧数。 */

/* 以太网 MMC 接收到的 CRC 错误帧计数器寄存器位定义 */
#define ETH_MMCRFCECR_RFCEC  ((uint32_t)0xFFFFFFFF)  /* 收到的 CRC 错误帧数。 */

/* 以太网 MMC 接收到的对齐错误帧计数器寄存器位定义 */
#define ETH_MMCRFAECR_RFAEC  ((uint32_t)0xFFFFFFFF)  /* 收到的对齐（漏位）错误帧数 */

/* 以太网 MMC 接收到的有效单播帧计数器寄存器位定义 */
#define ETH_MMCRGUFCR_RGUFC  ((uint32_t)0xFFFFFFFF)  /* 接收到的有效单播帧数。 */

/******************************************************************************/
/*               以太网 PTP 寄存器位定义                       */
/******************************************************************************/

/* 以太网 PTP 时间戳控制寄存器位定义 */
#define ETH_PTPTSCR_TSARU    ((uint32_t)0x00000020)  /* 加数寄存器更新 */
#define ETH_PTPTSCR_TSITE    ((uint32_t)0x00000010)  /* 时间戳中断触发使能 */
#define ETH_PTPTSCR_TSSTU    ((uint32_t)0x00000008)  /* 时间戳更新 */
#define ETH_PTPTSCR_TSSTI    ((uint32_t)0x00000004)  /* 时间戳初始化 */
#define ETH_PTPTSCR_TSFCU    ((uint32_t)0x00000002)  /* 时间戳精细或粗略更新 */
#define ETH_PTPTSCR_TSE      ((uint32_t)0x00000001)  /* 时间戳使能 */

/* 以太网 PTP 亚秒增量寄存器位定义 */
#define ETH_PTPSSIR_STSSI    ((uint32_t)0x000000FF)  /* 系统时间亚秒增量值 */

/* 以太网 PTP 时间戳高位寄存器位定义 */
#define ETH_PTPTSHR_STS      ((uint32_t)0xFFFFFFFF)  /* 系统时间秒 */

/* 以太网 PTP 时间戳低位寄存器位定义 */
#define ETH_PTPTSLR_STPNS    ((uint32_t)0x80000000)  /* 系统时间正或负 */
#define ETH_PTPTSLR_STSS     ((uint32_t)0x7FFFFFFF)  /* 系统时间亚秒 */

/* 以太网 PTP 时间戳高位更新寄存器位定义 */
#define ETH_PTPTSHUR_TSUS    ((uint32_t)0xFFFFFFFF)  /* 时间戳更新秒 */

/* 以太网 PTP 时间戳低位更新寄存器位定义 */
#define ETH_PTPTSLUR_TSUPNS  ((uint32_t)0x80000000)  /* 时间戳更新正或负 */
#define ETH_PTPTSLUR_TSUSS   ((uint32_t)0x7FFFFFFF)  /* 时间戳更新亚秒 */

/* 以太网 PTP 时间戳加数寄存器位定义 */
#define ETH_PTPTSAR_TSA      ((uint32_t)0xFFFFFFFF)  /* 时间戳加数 */

/* 以太网 PTP 目标时间高位寄存器位定义 */
#define ETH_PTPTTHR_TTSH     ((uint32_t)0xFFFFFFFF)  /* 目标时间戳高位 */

/* 以太网 PTP 目标时间低位寄存器位定义 */
#define ETH_PTPTTLR_TTSL     ((uint32_t)0xFFFFFFFF)  /* 目标时间戳低位 */

/******************************************************************************/
/*                 以太网 DMA 寄存器位定义                     */
/******************************************************************************/

/* 以太网 DMA 总线模式寄存器位定义 */
#define ETH_DMABMR_AAB       ((uint32_t)0x02000000)  /* 地址对齐节拍 */
#define ETH_DMABMR_FPM        ((uint32_t)0x01000000)  /* 4 倍 PBL 模式 */
#define ETH_DMABMR_USP       ((uint32_t)0x00800000)  /* 使用独立 PBL */
#define ETH_DMABMR_RDP       ((uint32_t)0x007E0000)  /* RxDMA PBL */
  #define ETH_DMABMR_RDP_1Beat    ((uint32_t)0x00020000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 1 */
  #define ETH_DMABMR_RDP_2Beat    ((uint32_t)0x00040000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 2 */
  #define ETH_DMABMR_RDP_4Beat    ((uint32_t)0x00080000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 4 */
  #define ETH_DMABMR_RDP_8Beat    ((uint32_t)0x00100000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 8 */
  #define ETH_DMABMR_RDP_16Beat   ((uint32_t)0x00200000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 16 */
  #define ETH_DMABMR_RDP_32Beat   ((uint32_t)0x00400000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 32 */                
  #define ETH_DMABMR_RDP_4xPBL_4Beat   ((uint32_t)0x01020000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 4 */
  #define ETH_DMABMR_RDP_4xPBL_8Beat   ((uint32_t)0x01040000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 8 */
  #define ETH_DMABMR_RDP_4xPBL_16Beat  ((uint32_t)0x01080000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 16 */
  #define ETH_DMABMR_RDP_4xPBL_32Beat  ((uint32_t)0x01100000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 32 */
  #define ETH_DMABMR_RDP_4xPBL_64Beat  ((uint32_t)0x01200000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 64 */
  #define ETH_DMABMR_RDP_4xPBL_128Beat ((uint32_t)0x01400000)  /* 在一次 RxDMA 事务中可传输的最大节拍数为 128 */  
#define ETH_DMABMR_FB        ((uint32_t)0x00010000)  /* 固定突发 */
#define ETH_DMABMR_RTPR      ((uint32_t)0x0000C000)  /* 接收发送优先级比 */
  #define ETH_DMABMR_RTPR_1_1     ((uint32_t)0x00000000)  /* 接收发送优先级比 */
  #define ETH_DMABMR_RTPR_2_1     ((uint32_t)0x00004000)  /* 接收发送优先级比 */
  #define ETH_DMABMR_RTPR_3_1     ((uint32_t)0x00008000)  /* 接收发送优先级比 */
  #define ETH_DMABMR_RTPR_4_1     ((uint32_t)0x0000C000)  /* 接收发送优先级比 */  
#define ETH_DMABMR_PBL    ((uint32_t)0x00003F00)  /* 可编程突发长度 */
  #define ETH_DMABMR_PBL_1Beat    ((uint32_t)0x00000100)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 1 */
  #define ETH_DMABMR_PBL_2Beat    ((uint32_t)0x00000200)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 2 */
  #define ETH_DMABMR_PBL_4Beat    ((uint32_t)0x00000400)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 4 */
  #define ETH_DMABMR_PBL_8Beat    ((uint32_t)0x00000800)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 8 */
  #define ETH_DMABMR_PBL_16Beat   ((uint32_t)0x00001000)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 16 */
  #define ETH_DMABMR_PBL_32Beat   ((uint32_t)0x00002000)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 32 */                
  #define ETH_DMABMR_PBL_4xPBL_4Beat   ((uint32_t)0x01000100)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 4 */
  #define ETH_DMABMR_PBL_4xPBL_8Beat   ((uint32_t)0x01000200)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 8 */
  #define ETH_DMABMR_PBL_4xPBL_16Beat  ((uint32_t)0x01000400)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 16 */
  #define ETH_DMABMR_PBL_4xPBL_32Beat  ((uint32_t)0x01000800)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 32 */
  #define ETH_DMABMR_PBL_4xPBL_64Beat  ((uint32_t)0x01001000)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 64 */
  #define ETH_DMABMR_PBL_4xPBL_128Beat ((uint32_t)0x01002000)  /* 在一次 TxDMA（或两者）事务中可传输的最大节拍数为 128 */
#define ETH_DMABMR_DSL       ((uint32_t)0x0000007C)  /* 描述符跳过长度 */
#define ETH_DMABMR_DA        ((uint32_t)0x00000002)  /* DMA 仲裁方案 */
#define ETH_DMABMR_SR        ((uint32_t)0x00000001)  /* 软件复位 */

/* 以太网 DMA 发送轮询请求寄存器位定义 */
#define ETH_DMATPDR_TPD      ((uint32_t)0xFFFFFFFF)  /* 发送轮询请求 */

/* 以太网 DMA 接收轮询请求寄存器位定义 */
#define ETH_DMARPDR_RPD      ((uint32_t)0xFFFFFFFF)  /* 接收轮询请求  */

/* 以太网 DMA 接收描述符列表地址寄存器位定义 */
#define ETH_DMARDLAR_SRL     ((uint32_t)0xFFFFFFFF)  /* 接收列表起始 */

/* 以太网 DMA 发送描述符列表地址寄存器位定义 */
#define ETH_DMATDLAR_STL     ((uint32_t)0xFFFFFFFF)  /* 发送列表起始 */

/* 以太网 DMA 状态寄存器位定义 */
#define ETH_DMASR_TSTS       ((uint32_t)0x20000000)  /* 时间戳触发状态 */
#define ETH_DMASR_PMTS       ((uint32_t)0x10000000)  /* PMT 状态 */
#define ETH_DMASR_MMCS       ((uint32_t)0x08000000)  /* MMC 状态 */
#define ETH_DMASR_EBS        ((uint32_t)0x03800000)  /* 错误位状态 */
  /* 与 EBS[2:0] 配合用于 GetFlagStatus 函数 */
  #define ETH_DMASR_EBS_DescAccess      ((uint32_t)0x02000000)  /* 错误位 0-数据缓冲区，1-描述符访问 */
  #define ETH_DMASR_EBS_ReadTransf      ((uint32_t)0x01000000)  /* 错误位 0-写传输，1-读传输 */
  #define ETH_DMASR_EBS_DataTransfTx    ((uint32_t)0x00800000)  /* 错误位 0-接收 DMA，1-发送 DMA */
#define ETH_DMASR_TPS         ((uint32_t)0x00700000)  /* 发送过程状态 */
  #define ETH_DMASR_TPS_Stopped         ((uint32_t)0x00000000)  /* 已停止 - 已发出复位或停止发送命令  */
  #define ETH_DMASR_TPS_Fetching        ((uint32_t)0x00100000)  /* 运行中 - 取发送描述符 */
  #define ETH_DMASR_TPS_Waiting         ((uint32_t)0x00200000)  /* 运行中 - 等待状态 */
  #define ETH_DMASR_TPS_Reading         ((uint32_t)0x00300000)  /* 运行中 - 从主机内存读取数据 */
  #define ETH_DMASR_TPS_Suspended       ((uint32_t)0x00600000)  /* 已挂起 - 发送描述符不可用 */
  #define ETH_DMASR_TPS_Closing         ((uint32_t)0x00700000)  /* 运行中 - 关闭接收描述符 */
#define ETH_DMASR_RPS         ((uint32_t)0x000E0000)  /* 接收过程状态 */
  #define ETH_DMASR_RPS_Stopped         ((uint32_t)0x00000000)  /* 已停止 - 已发出复位或停止接收命令 */
  #define ETH_DMASR_RPS_Fetching        ((uint32_t)0x00020000)  /* 运行中 - 取接收描述符 */
  #define ETH_DMASR_RPS_Waiting         ((uint32_t)0x00060000)  /* 运行中 - 等待数据包 */
  #define ETH_DMASR_RPS_Suspended       ((uint32_t)0x00080000)  /* 已挂起 - 接收描述符不可用 */
  #define ETH_DMASR_RPS_Closing         ((uint32_t)0x000A0000)  /* 运行中 - 关闭描述符 */
  #define ETH_DMASR_RPS_Queuing         ((uint32_t)0x000E0000)  /* 运行中 - 将接收帧排入主机内存 */
#define ETH_DMASR_NIS        ((uint32_t)0x00010000)  /* 正常中断摘要 */
#define ETH_DMASR_AIS        ((uint32_t)0x00008000)  /* 异常中断摘要 */
#define ETH_DMASR_ERS        ((uint32_t)0x00004000)  /* 提前接收状态 */
#define ETH_DMASR_FBES       ((uint32_t)0x00002000)  /* 致命总线错误状态 */
#define ETH_DMASR_ETS        ((uint32_t)0x00000400)  /* 提前发送状态 */
#define ETH_DMASR_RWTS       ((uint32_t)0x00000200)  /* 接收看门狗超时状态 */
#define ETH_DMASR_RPSS       ((uint32_t)0x00000100)  /* 接收过程停止状态 */
#define ETH_DMASR_RBUS       ((uint32_t)0x00000080)  /* 接收缓冲区不可用状态 */
#define ETH_DMASR_RS         ((uint32_t)0x00000040)  /* 接收状态 */
#define ETH_DMASR_TUS        ((uint32_t)0x00000020)  /* 发送下溢状态 */
#define ETH_DMASR_ROS        ((uint32_t)0x00000010)  /* 接收上溢状态 */
#define ETH_DMASR_TJTS       ((uint32_t)0x00000008)  /* 发送 Jabber 超时状态 */
#define ETH_DMASR_TBUS       ((uint32_t)0x00000004)  /* 发送缓冲区不可用状态 */
#define ETH_DMASR_TPSS       ((uint32_t)0x00000002)  /* 发送过程停止状态 */
#define ETH_DMASR_TS         ((uint32_t)0x00000001)  /* 发送状态 */

/* 以太网 DMA 操作模式寄存器位定义 */
#define ETH_DMAOMR_DTCEFD    ((uint32_t)0x04000000)  /* 禁止丢弃 TCP/IP 校验和错误帧 */
#define ETH_DMAOMR_RSF       ((uint32_t)0x02000000)  /* 接收存储转发 */
#define ETH_DMAOMR_DFRF      ((uint32_t)0x01000000)  /* 禁止清空接收到的帧 */
#define ETH_DMAOMR_TSF       ((uint32_t)0x00200000)  /* 发送存储转发 */
#define ETH_DMAOMR_FTF       ((uint32_t)0x00100000)  /* 清空发送 FIFO */
#define ETH_DMAOMR_TTC       ((uint32_t)0x0001C000)  /* 发送阈值控制 */
  #define ETH_DMAOMR_TTC_64Bytes       ((uint32_t)0x00000000)  /* MTL 发送 FIFO 的阈值为 64 字节 */
  #define ETH_DMAOMR_TTC_128Bytes      ((uint32_t)0x00004000)  /* MTL 发送 FIFO 的阈值为 128 字节 */
  #define ETH_DMAOMR_TTC_192Bytes      ((uint32_t)0x00008000)  /* MTL 发送 FIFO 的阈值为 192 字节 */
  #define ETH_DMAOMR_TTC_256Bytes      ((uint32_t)0x0000C000)  /* MTL 发送 FIFO 的阈值为 256 字节 */
  #define ETH_DMAOMR_TTC_40Bytes       ((uint32_t)0x00010000)  /* MTL 发送 FIFO 的阈值为 40 字节 */
  #define ETH_DMAOMR_TTC_32Bytes       ((uint32_t)0x00014000)  /* MTL 发送 FIFO 的阈值为 32 字节 */
  #define ETH_DMAOMR_TTC_24Bytes       ((uint32_t)0x00018000)  /* MTL 发送 FIFO 的阈值为 24 字节 */
  #define ETH_DMAOMR_TTC_16Bytes       ((uint32_t)0x0001C000)  /* MTL 发送 FIFO 的阈值为 16 字节 */
#define ETH_DMAOMR_ST        ((uint32_t)0x00002000)  /* 启动/停止发送命令 */
#define ETH_DMAOMR_FEF       ((uint32_t)0x00000080)  /* 转发错误帧 */
#define ETH_DMAOMR_FUGF      ((uint32_t)0x00000040)  /* 转发过小的有效帧 */
#define ETH_DMAOMR_RTC       ((uint32_t)0x00000018)  /* 接收阈值控制 */
  #define ETH_DMAOMR_RTC_64Bytes       ((uint32_t)0x00000000)  /* MTL 接收 FIFO 的阈值为 64 字节 */
  #define ETH_DMAOMR_RTC_32Bytes       ((uint32_t)0x00000008)  /* MTL 接收 FIFO 的阈值为 32 字节 */
  #define ETH_DMAOMR_RTC_96Bytes       ((uint32_t)0x00000010)  /* MTL 接收 FIFO 的阈值为 96 字节 */
  #define ETH_DMAOMR_RTC_128Bytes      ((uint32_t)0x00000018)  /* MTL 接收 FIFO 的阈值为 128 字节 */
#define ETH_DMAOMR_OSF       ((uint32_t)0x00000004)  /* 对第二帧进行操作 */
#define ETH_DMAOMR_SR        ((uint32_t)0x00000002)  /* 启动/停止接收 */

/* 以太网 DMA 中断使能寄存器位定义 */
#define ETH_DMAIER_NISE      ((uint32_t)0x00010000)  /* 正常中断摘要使能 */
#define ETH_DMAIER_AISE      ((uint32_t)0x00008000)  /* 异常中断摘要使能 */
#define ETH_DMAIER_ERIE      ((uint32_t)0x00004000)  /* 提前接收中断使能 */
#define ETH_DMAIER_FBEIE     ((uint32_t)0x00002000)  /* 致命总线错误中断使能 */
#define ETH_DMAIER_ETIE      ((uint32_t)0x00000400)  /* 提前发送中断使能 */
#define ETH_DMAIER_RWTIE     ((uint32_t)0x00000200)  /* 接收看门狗超时中断使能 */
#define ETH_DMAIER_RPSIE     ((uint32_t)0x00000100)  /* 接收过程停止中断使能 */
#define ETH_DMAIER_RBUIE     ((uint32_t)0x00000080)  /* 接收缓冲区不可用中断使能 */
#define ETH_DMAIER_RIE       ((uint32_t)0x00000040)  /* 接收中断使能 */
#define ETH_DMAIER_TUIE      ((uint32_t)0x00000020)  /* 发送下溢中断使能 */
#define ETH_DMAIER_ROIE      ((uint32_t)0x00000010)  /* 接收上溢中断使能 */
#define ETH_DMAIER_TJTIE     ((uint32_t)0x00000008)  /* 发送 Jabber 超时中断使能 */
#define ETH_DMAIER_TBUIE     ((uint32_t)0x00000004)  /* 发送缓冲区不可用中断使能 */
#define ETH_DMAIER_TPSIE     ((uint32_t)0x00000002)  /* 发送过程停止中断使能 */
#define ETH_DMAIER_TIE       ((uint32_t)0x00000001)  /* 发送中断使能 */

/* 以太网 DMA 丢失帧和缓冲区上溢计数器寄存器位定义 */
#define ETH_DMAMFBOCR_OFOC   ((uint32_t)0x10000000)  /* FIFO 上溢计数器的溢出位 */
#define ETH_DMAMFBOCR_MFA    ((uint32_t)0x0FFE0000)  /* 应用程序丢失的帧数 */
#define ETH_DMAMFBOCR_OMFC   ((uint32_t)0x00010000)  /* 丢失帧计数器的溢出位 */
#define ETH_DMAMFBOCR_MFC    ((uint32_t)0x0000FFFF)  /* 控制器丢失的帧数 */

/* 以太网 DMA 当前主机发送描述符寄存器位定义 */
#define ETH_DMACHTDR_HTDAP   ((uint32_t)0xFFFFFFFF)  /* 主机发送描述符地址指针 */

/* 以太网 DMA 当前主机接收描述符寄存器位定义 */
#define ETH_DMACHRDR_HRDAP   ((uint32_t)0xFFFFFFFF)  /* 主机接收描述符地址指针 */

/* 以太网 DMA 当前主机发送缓冲区地址寄存器位定义 */
#define ETH_DMACHTBAR_HTBAP  ((uint32_t)0xFFFFFFFF)  /* 主机发送缓冲区地址指针 */

/* 以太网 DMA 当前主机接收缓冲区地址寄存器位定义 */
#define ETH_DMACHRBAR_HRBAP  ((uint32_t)0xFFFFFFFF)  /* 主机接收缓冲区地址指针 */
#endif /* STM32F10X_CL */

/**
  * @}
  */

 /**
  * @}
  */ 

#ifdef USE_STDPERIPH_DRIVER
  #include "stm32f10x_conf.h"
#endif

/** @addtogroup Exported_macro
  * @{
  */

#define SET_BIT(REG, BIT)     ((REG) |= (BIT))

#define CLEAR_BIT(REG, BIT)   ((REG) &= ~(BIT))

#define READ_BIT(REG, BIT)    ((REG) & (BIT))

#define CLEAR_REG(REG)        ((REG) = (0x0))

#define WRITE_REG(REG, VAL)   ((REG) = (VAL))

#define READ_REG(REG)         ((REG))

#define MODIFY_REG(REG, CLEARMASK, SETMASK)  WRITE_REG((REG), (((READ_REG(REG)) & (~(CLEARMASK))) | (SETMASK)))

/**
  * @}
  */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_H */

/**
  * @}
  */

  /**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
