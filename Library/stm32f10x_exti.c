/**
  ******************************************************************************
  * @file    stm32f10x_exti.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供所有 EXTI 固件函数。
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

/* 包含头文件 ------------------------------------------------------------------*/
#include "stm32f10x_exti.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup EXTI 
  * @brief EXTI 驱动模块
  * @{
  */

/** @defgroup EXTI_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup EXTI_Private_Defines
  * @{
  */

#define EXTI_LINENONE    ((uint32_t)0x00000)  /* 未选择中断 */

/**
  * @}
  */

/** @defgroup EXTI_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup EXTI_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup EXTI_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup EXTI_Private_Functions
  * @{
  */

/**
  * @brief  将 EXTI 外设寄存器复位为默认值。
  * @param  无
  * @retval 无
  */
void EXTI_DeInit(void)
{
  EXTI->IMR = 0x00000000;
  EXTI->EMR = 0x00000000;
  EXTI->RTSR = 0x00000000; 
  EXTI->FTSR = 0x00000000; 
  EXTI->PR = 0x000FFFFF;
}

/**
  * @brief  根据 EXTI_InitStruct 中指定的参数初始化 EXTI 外设。
  * @param  EXTI_InitStruct: 指向 EXTI_InitTypeDef 结构的指针，
  *         包含 EXTI 外设的配置信息。
  * @retval 无
  */
void EXTI_Init(EXTI_InitTypeDef* EXTI_InitStruct)
{
  uint32_t tmp = 0;

  /* 检查参数 */
  assert_param(IS_EXTI_MODE(EXTI_InitStruct->EXTI_Mode));
  assert_param(IS_EXTI_TRIGGER(EXTI_InitStruct->EXTI_Trigger));
  assert_param(IS_EXTI_LINE(EXTI_InitStruct->EXTI_Line));  
  assert_param(IS_FUNCTIONAL_STATE(EXTI_InitStruct->EXTI_LineCmd));

  tmp = (uint32_t)EXTI_BASE;
     
  if (EXTI_InitStruct->EXTI_LineCmd != DISABLE)
  {
    /* 清除 EXTI 线配置 */
    EXTI->IMR &= ~EXTI_InitStruct->EXTI_Line;
    EXTI->EMR &= ~EXTI_InitStruct->EXTI_Line;
    
    tmp += EXTI_InitStruct->EXTI_Mode;

    *(__IO uint32_t *) tmp |= EXTI_InitStruct->EXTI_Line;

    /* 清除上升沿和下降沿配置 */
    EXTI->RTSR &= ~EXTI_InitStruct->EXTI_Line;
    EXTI->FTSR &= ~EXTI_InitStruct->EXTI_Line;
    
    /* 为选定的外部中断选择触发方式 */
    if (EXTI_InitStruct->EXTI_Trigger == EXTI_Trigger_Rising_Falling)
    {
      /* 上升沿和下降沿 */
      EXTI->RTSR |= EXTI_InitStruct->EXTI_Line;
      EXTI->FTSR |= EXTI_InitStruct->EXTI_Line;
    }
    else
    {
      tmp = (uint32_t)EXTI_BASE;
      tmp += EXTI_InitStruct->EXTI_Trigger;

      *(__IO uint32_t *) tmp |= EXTI_InitStruct->EXTI_Line;
    }
  }
  else
  {
    tmp += EXTI_InitStruct->EXTI_Mode;

    /* 失能选定的外部中断线 */
    *(__IO uint32_t *) tmp &= ~EXTI_InitStruct->EXTI_Line;
  }
}

/**
  * @brief  将 EXTI_InitStruct 的每个成员填充为复位值。
  * @param  EXTI_InitStruct: 指向将要初始化的 EXTI_InitTypeDef 结构的指针。
  * @retval 无
  */
void EXTI_StructInit(EXTI_InitTypeDef* EXTI_InitStruct)
{
  EXTI_InitStruct->EXTI_Line = EXTI_LINENONE;
  EXTI_InitStruct->EXTI_Mode = EXTI_Mode_Interrupt;
  EXTI_InitStruct->EXTI_Trigger = EXTI_Trigger_Falling;
  EXTI_InitStruct->EXTI_LineCmd = DISABLE;
}

/**
  * @brief  产生软件中断。
  * @param  EXTI_Line: 指定要使能或失能的 EXTI 线。
  *   该参数可为 EXTI_Linex 的任意组合，其中 x 可为 (0..19)。
  * @retval 无
  */
void EXTI_GenerateSWInterrupt(uint32_t EXTI_Line)
{
  /* 检查参数 */
  assert_param(IS_EXTI_LINE(EXTI_Line));
  
  EXTI->SWIER |= EXTI_Line;
}

/**
  * @brief  检查指定的 EXTI 线标志位是否置位。
  * @param  EXTI_Line: 指定要检查的 EXTI 线标志位。
  *   该参数可为：
  *     @arg EXTI_Linex: 外部中断线 x，其中 x 可为 (0..19)
  * @retval EXTI_Line 的新状态（SET 或 RESET）。
  */
FlagStatus EXTI_GetFlagStatus(uint32_t EXTI_Line)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_GET_EXTI_LINE(EXTI_Line));
  
  if ((EXTI->PR & EXTI_Line) != (uint32_t)RESET)
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}

/**
  * @brief  清除 EXTI 线的挂起标志位。
  * @param  EXTI_Line: 指定要清除的 EXTI 线标志位。
  *   该参数可为 EXTI_Linex 的任意组合，其中 x 可为 (0..19)。
  * @retval 无
  */
void EXTI_ClearFlag(uint32_t EXTI_Line)
{
  /* 检查参数 */
  assert_param(IS_EXTI_LINE(EXTI_Line));
  
  EXTI->PR = EXTI_Line;
}

/**
  * @brief  检查指定的 EXTI 线是否已触发。
  * @param  EXTI_Line: 指定要检查的 EXTI 线。
  *   该参数可为：
  *     @arg EXTI_Linex: 外部中断线 x，其中 x 可为 (0..19)
  * @retval EXTI_Line 的新状态（SET 或 RESET）。
  */
ITStatus EXTI_GetITStatus(uint32_t EXTI_Line)
{
  ITStatus bitstatus = RESET;
  uint32_t enablestatus = 0;
  /* 检查参数 */
  assert_param(IS_GET_EXTI_LINE(EXTI_Line));
  
  enablestatus =  EXTI->IMR & EXTI_Line;
  if (((EXTI->PR & EXTI_Line) != (uint32_t)RESET) && (enablestatus != (uint32_t)RESET))
  {
    bitstatus = SET;
  }
  else
  {
    bitstatus = RESET;
  }
  return bitstatus;
}

/**
  * @brief  清除 EXTI 线的挂起位。
  * @param  EXTI_Line: 指定要清除的 EXTI 线。
  *   该参数可为 EXTI_Linex 的任意组合，其中 x 可为 (0..19)。
  * @retval 无
  */
void EXTI_ClearITPendingBit(uint32_t EXTI_Line)
{
  /* 检查参数 */
  assert_param(IS_EXTI_LINE(EXTI_Line));
  
  EXTI->PR = EXTI_Line;
}

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
