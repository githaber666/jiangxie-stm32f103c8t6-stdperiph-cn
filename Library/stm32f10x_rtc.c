/**
  ******************************************************************************
  * @file    stm32f10x_rtc.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供 RTC 的所有固件函数。
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

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f10x_rtc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup RTC 
  * @brief RTC 驱动模块
  * @{
  */

/** @defgroup RTC_Private_TypesDefinitions
  * @{
  */ 
/**
  * @}
  */

/** @defgroup RTC_Private_Defines
  * @{
  */
#define RTC_LSB_MASK     ((uint32_t)0x0000FFFF)  /*!< RTC 低 16 位掩码 */
#define PRLH_MSB_MASK    ((uint32_t)0x000F0000)  /*!< RTC 预分频器高 16 位掩码 */

/**
  * @}
  */

/** @defgroup RTC_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup RTC_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup RTC_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup RTC_Private_Functions
  * @{
  */

/**
  * @brief  使能或失能指定的 RTC 中断。
  * @param  RTC_IT：指定要使能或失能的 RTC 中断源。
  *   该参数可以是以下值的任意组合：
  *     @arg RTC_IT_OW：溢出中断
  *     @arg RTC_IT_ALR：闹钟中断
  *     @arg RTC_IT_SEC：秒中断
  * @param  NewState：指定 RTC 中断的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void RTC_ITConfig(uint16_t RTC_IT, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_RTC_IT(RTC_IT));  
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    RTC->CRH |= RTC_IT;
  }
  else
  {
    RTC->CRH &= (uint16_t)~RTC_IT;
  }
}

/**
  * @brief  进入 RTC 配置模式。
  * @param  无
  * @retval 无
  */
void RTC_EnterConfigMode(void)
{
  /* 置位 CNF 标志位以进入配置模式 */
  RTC->CRL |= RTC_CRL_CNF;
}

/**
  * @brief  退出 RTC 配置模式。
  * @param  无
  * @retval 无
  */
void RTC_ExitConfigMode(void)
{
  /* 复位 CNF 标志位以退出配置模式 */
  RTC->CRL &= (uint16_t)~((uint16_t)RTC_CRL_CNF); 
}

/**
  * @brief  获取 RTC 计数器值。
  * @param  无
  * @retval RTC 计数器值。
  */
uint32_t RTC_GetCounter(void)
{
  uint16_t tmp = 0;
  tmp = RTC->CNTL;
  return (((uint32_t)RTC->CNTH << 16 ) | tmp) ;
}

/**
  * @brief  设置 RTC 计数器值。
  * @param  CounterValue：RTC 计数器的新值。
  * @retval 无
  */
void RTC_SetCounter(uint32_t CounterValue)
{ 
  RTC_EnterConfigMode();
  /* 设置 RTC 计数器高 16 位 */
  RTC->CNTH = CounterValue >> 16;
  /* 设置 RTC 计数器低 16 位 */
  RTC->CNTL = (CounterValue & RTC_LSB_MASK);
  RTC_ExitConfigMode();
}

/**
  * @brief  设置 RTC 预分频器值。
  * @param  PrescalerValue：RTC 预分频器的新值。
  * @retval 无
  */
void RTC_SetPrescaler(uint32_t PrescalerValue)
{
  /* 检查参数 */
  assert_param(IS_RTC_PRESCALER(PrescalerValue));
  
  RTC_EnterConfigMode();
  /* 设置 RTC 预分频器高 16 位 */
  RTC->PRLH = (PrescalerValue & PRLH_MSB_MASK) >> 16;
  /* 设置 RTC 预分频器低 16 位 */
  RTC->PRLL = (PrescalerValue & RTC_LSB_MASK);
  RTC_ExitConfigMode();
}

/**
  * @brief  设置 RTC 闹钟值。
  * @param  AlarmValue：RTC 闹钟的新值。
  * @retval 无
  */
void RTC_SetAlarm(uint32_t AlarmValue)
{  
  RTC_EnterConfigMode();
  /* 设置闹钟值高 16 位 */
  RTC->ALRH = AlarmValue >> 16;
  /* 设置闹钟值低 16 位 */
  RTC->ALRL = (AlarmValue & RTC_LSB_MASK);
  RTC_ExitConfigMode();
}

/**
  * @brief  获取 RTC 分频器值。
  * @param  无
  * @retval RTC 分频器值。
  */
uint32_t RTC_GetDivider(void)
{
  uint32_t tmp = 0x00;
  tmp = ((uint32_t)RTC->DIVH & (uint32_t)0x000F) << 16;
  tmp |= RTC->DIVL;
  return tmp;
}

/**
  * @brief  等待对 RTC 寄存器的最后一次写操作完成。
  * @note   在向 RTC 寄存器写入任何数据之前必须调用该函数。
  * @param  无
  * @retval 无
  */
void RTC_WaitForLastTask(void)
{
  /* 循环等待直到 RTOFF 标志位置位 */
  while ((RTC->CRL & RTC_FLAG_RTOFF) == (uint16_t)RESET)
  {
  }
}

/**
  * @brief  等待 RTC 寄存器（RTC_CNT、RTC_ALR 和 RTC_PRL）
  *   与 RTC APB 时钟同步。
  * @note   在 APB 复位或 APB 时钟停止后的任何读操作之前必须调用该函数。
  * @param  无
  * @retval 无
  */
void RTC_WaitForSynchro(void)
{
  /* 清除 RSF 标志位 */
  RTC->CRL &= (uint16_t)~RTC_FLAG_RSF;
  /* 循环等待直到 RSF 标志位置位 */
  while ((RTC->CRL & RTC_FLAG_RSF) == (uint16_t)RESET)
  {
  }
}

/**
  * @brief  检查指定的 RTC 标志位是否置位。
  * @param  RTC_FLAG：指定要检查的标志位。
  *   该参数可以是以下值之一：
  *     @arg RTC_FLAG_RTOFF：RTC 操作关闭标志位
  *     @arg RTC_FLAG_RSF：寄存器已同步标志位
  *     @arg RTC_FLAG_OW：溢出标志位
  *     @arg RTC_FLAG_ALR：闹钟标志位
  *     @arg RTC_FLAG_SEC：秒标志位
  * @retval RTC_FLAG 的新状态（SET 或 RESET）。
  */
FlagStatus RTC_GetFlagStatus(uint16_t RTC_FLAG)
{
  FlagStatus bitstatus = RESET;
  
  /* 检查参数 */
  assert_param(IS_RTC_GET_FLAG(RTC_FLAG)); 
  
  if ((RTC->CRL & RTC_FLAG) != (uint16_t)RESET)
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
  * @brief  清除 RTC 的挂起标志位。
  * @param  RTC_FLAG：指定要清除的标志位。
  *   该参数可以是以下值的任意组合：
  *     @arg RTC_FLAG_RSF：寄存器已同步标志位。该标志位仅在
  *                        APB 复位或 APB 时钟停止后才能被清除。
  *     @arg RTC_FLAG_OW：溢出标志位
  *     @arg RTC_FLAG_ALR：闹钟标志位
  *     @arg RTC_FLAG_SEC：秒标志位
  * @retval 无
  */
void RTC_ClearFlag(uint16_t RTC_FLAG)
{
  /* 检查参数 */
  assert_param(IS_RTC_CLEAR_FLAG(RTC_FLAG)); 
    
  /* 清除相应的 RTC 标志位 */
  RTC->CRL &= (uint16_t)~RTC_FLAG;
}

/**
  * @brief  检查指定的 RTC 中断是否发生。
  * @param  RTC_IT：指定要检查的 RTC 中断源。
  *   该参数可以是以下值之一：
  *     @arg RTC_IT_OW：溢出中断
  *     @arg RTC_IT_ALR：闹钟中断
  *     @arg RTC_IT_SEC：秒中断
  * @retval RTC_IT 的新状态（SET 或 RESET）。
  */
ITStatus RTC_GetITStatus(uint16_t RTC_IT)
{
  ITStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_RTC_GET_IT(RTC_IT)); 
  
  bitstatus = (ITStatus)(RTC->CRL & RTC_IT);
  if (((RTC->CRH & RTC_IT) != (uint16_t)RESET) && (bitstatus != (uint16_t)RESET))
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
  * @brief  清除 RTC 的中断挂起位。
  * @param  RTC_IT：指定要清除的中断挂起位。
  *   该参数可以是以下值的任意组合：
  *     @arg RTC_IT_OW：溢出中断
  *     @arg RTC_IT_ALR：闹钟中断
  *     @arg RTC_IT_SEC：秒中断
  * @retval 无
  */
void RTC_ClearITPendingBit(uint16_t RTC_IT)
{
  /* 检查参数 */
  assert_param(IS_RTC_IT(RTC_IT));  
  
  /* 清除相应的 RTC 挂起位 */
  RTC->CRL &= (uint16_t)~RTC_IT;
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
