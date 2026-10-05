/**
  ******************************************************************************
  * @file    stm32f10x_exti.h
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件包含 EXTI 固件库的所有函数原型。
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

/* 防止重复包含 -------------------------------------*/
#ifndef __STM32F10x_EXTI_H
#define __STM32F10x_EXTI_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含头文件 ------------------------------------------------------------------*/
#include "stm32f10x.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @addtogroup EXTI
  * @{
  */

/** @defgroup EXTI_Exported_Types
  * @{
  */

/** 
  * @brief  EXTI 模式枚举  
  */

typedef enum
{
  EXTI_Mode_Interrupt = 0x00,
  EXTI_Mode_Event = 0x04
}EXTIMode_TypeDef;

#define IS_EXTI_MODE(MODE) (((MODE) == EXTI_Mode_Interrupt) || ((MODE) == EXTI_Mode_Event))

/** 
  * @brief  EXTI 触发方式枚举  
  */

typedef enum
{
  EXTI_Trigger_Rising = 0x08,
  EXTI_Trigger_Falling = 0x0C,  
  EXTI_Trigger_Rising_Falling = 0x10
}EXTITrigger_TypeDef;

#define IS_EXTI_TRIGGER(TRIGGER) (((TRIGGER) == EXTI_Trigger_Rising) || \
                                  ((TRIGGER) == EXTI_Trigger_Falling) || \
                                  ((TRIGGER) == EXTI_Trigger_Rising_Falling))
/** 
  * @brief  EXTI 初始化结构体定义  
  */

typedef struct
{
  uint32_t EXTI_Line;               /*!< 指定要使能或失能的 EXTI 线。
                                         该参数可为 @ref EXTI_Lines 的任意组合 */
   
  EXTIMode_TypeDef EXTI_Mode;       /*!< 指定 EXTI 线的模式。
                                         该参数可为 @ref EXTIMode_TypeDef 的值 */

  EXTITrigger_TypeDef EXTI_Trigger; /*!< 指定 EXTI 线的触发信号有效边沿。
                                         该参数可为 @ref EXTIMode_TypeDef 的值 */

  FunctionalState EXTI_LineCmd;     /*!< 指定选定 EXTI 线的新状态。
                                         该参数可设置为 ENABLE 或 DISABLE */ 
}EXTI_InitTypeDef;

/**
  * @}
  */

/** @defgroup EXTI_Exported_Constants
  * @{
  */

/** @defgroup EXTI_Lines 
  * @{
  */

#define EXTI_Line0       ((uint32_t)0x00001)  /*!< 外部中断线 0 */
#define EXTI_Line1       ((uint32_t)0x00002)  /*!< 外部中断线 1 */
#define EXTI_Line2       ((uint32_t)0x00004)  /*!< 外部中断线 2 */
#define EXTI_Line3       ((uint32_t)0x00008)  /*!< 外部中断线 3 */
#define EXTI_Line4       ((uint32_t)0x00010)  /*!< 外部中断线 4 */
#define EXTI_Line5       ((uint32_t)0x00020)  /*!< 外部中断线 5 */
#define EXTI_Line6       ((uint32_t)0x00040)  /*!< 外部中断线 6 */
#define EXTI_Line7       ((uint32_t)0x00080)  /*!< 外部中断线 7 */
#define EXTI_Line8       ((uint32_t)0x00100)  /*!< 外部中断线 8 */
#define EXTI_Line9       ((uint32_t)0x00200)  /*!< 外部中断线 9 */
#define EXTI_Line10      ((uint32_t)0x00400)  /*!< 外部中断线 10 */
#define EXTI_Line11      ((uint32_t)0x00800)  /*!< 外部中断线 11 */
#define EXTI_Line12      ((uint32_t)0x01000)  /*!< 外部中断线 12 */
#define EXTI_Line13      ((uint32_t)0x02000)  /*!< 外部中断线 13 */
#define EXTI_Line14      ((uint32_t)0x04000)  /*!< 外部中断线 14 */
#define EXTI_Line15      ((uint32_t)0x08000)  /*!< 外部中断线 15 */
#define EXTI_Line16      ((uint32_t)0x10000)  /*!< 外部中断线 16 连接到 PVD 输出 */
#define EXTI_Line17      ((uint32_t)0x20000)  /*!< 外部中断线 17 连接到 RTC 闹钟事件 */
#define EXTI_Line18      ((uint32_t)0x40000)  /*!< 外部中断线 18 连接到 USB 设备/USB OTG FS
                                                  挂起事件唤醒 */                                    
#define EXTI_Line19      ((uint32_t)0x80000)  /*!< 外部中断线 19 连接到以太网唤醒事件 */
                                          
#define IS_EXTI_LINE(LINE) ((((LINE) & (uint32_t)0xFFF00000) == 0x00) && ((LINE) != (uint16_t)0x00))
#define IS_GET_EXTI_LINE(LINE) (((LINE) == EXTI_Line0) || ((LINE) == EXTI_Line1) || \
                            ((LINE) == EXTI_Line2) || ((LINE) == EXTI_Line3) || \
                            ((LINE) == EXTI_Line4) || ((LINE) == EXTI_Line5) || \
                            ((LINE) == EXTI_Line6) || ((LINE) == EXTI_Line7) || \
                            ((LINE) == EXTI_Line8) || ((LINE) == EXTI_Line9) || \
                            ((LINE) == EXTI_Line10) || ((LINE) == EXTI_Line11) || \
                            ((LINE) == EXTI_Line12) || ((LINE) == EXTI_Line13) || \
                            ((LINE) == EXTI_Line14) || ((LINE) == EXTI_Line15) || \
                            ((LINE) == EXTI_Line16) || ((LINE) == EXTI_Line17) || \
                            ((LINE) == EXTI_Line18) || ((LINE) == EXTI_Line19))

                    
/**
  * @}
  */

/**
  * @}
  */

/** @defgroup EXTI_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup EXTI_Exported_Functions
  * @{
  */

void EXTI_DeInit(void);
void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct);
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line);
FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line);
void EXTI_ClearFlag(uint32_t EXTI_Line);
ITStatus EXTI_GetITStatus(uint32_t EXTI_Line);
void EXTI_ClearITPendingBit(uint32_t EXTI_Line);

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_EXTI_H */
/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
