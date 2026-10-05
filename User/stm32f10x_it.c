/**
  ******************************************************************************
  * @file    Project/STM32F10x_StdPeriph_Template/stm32f10x_it.c 
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    08-April-2011
  * @brief   主要中断服务程序（ISR）。
  *          本文件提供所有异常处理程序和外设中断服务程序的模板。
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

/* Includes ------------------------------------------------------------------*/
#include "stm32f10x_it.h"

/** @addtogroup STM32F10x_StdPeriph_Template
  * @{
  */

/* 私有类型定义 ---------------------------------------------------------------*/
/* 私有宏定义 -----------------------------------------------------------------*/
/* 私有宏 ---------------------------------------------------------------------*/
/* 私有变量 -------------------------------------------------------------------*/
/* 私有函数原型 ---------------------------------------------------------------*/
/* 私有函数 -------------------------------------------------------------------*/

/******************************************************************************/
/*              Cortex-M3 处理器异常处理程序                                   */
/******************************************************************************/

/**
  * @brief  本函数处理 NMI（不可屏蔽中断）异常。
  * @param  无
  * @retval 无
  */
void NMI_Handler(void)
{
}

/**
  * @brief    本函数处理硬件错误（Hard Fault）异常。
  * @param    无
  * @retval   无
  */
void HardFault_Handler(void)
{
  /* 发生硬件错误（Hard Fault）异常时进入死循环 */
  while (1)
  {
  }
}

/**
  * @brief    本函数处理存储器管理（MemManage）异常。
  * @param    无
  * @retval   无
  */
void MemManage_Handler(void)
{
  /* 发生存储器管理（MemManage）异常时进入死循环 */
  while (1)
  {
  }
}

/**
  * @brief    本函数处理总线错误（Bus Fault）异常。
  * @param    无
  * @retval   无
  */
void BusFault_Handler(void)
{
  /* 发生总线错误（Bus Fault）异常时进入死循环 */
  while (1)
  {
  }
}

/**
  * @brief    本函数处理用法错误（Usage Fault）异常。
  * @param    无
  * @retval   无
  */
void UsageFault_Handler(void)
{
  /* 发生用法错误（Usage Fault）异常时进入死循环 */
  while (1)
  {
  }
}

/**
  * @brief  本函数处理 SVC（系统服务调用）异常。
  * @param  无
  * @retval 无
  */
void SVC_Handler(void)
{
}

/**
  * @brief    本函数处理调试监视器（Debug Monitor）异常。
  * @param    无
  * @retval   无
  */
void DebugMon_Handler(void)
{
}

/**
  * @brief    本函数处理 PendSV（可挂起系统服务）异常。
  * @param    无
  * @retval   无
  */
void PendSV_Handler(void)
{
}

/**
  * @brief    本函数处理 SysTick（系统滴答定时器）中断。
  * @param    无
  * @retval   无
  */
void SysTick_Handler(void)
{
}

/******************************************************************************/
/*                 STM32F10x 外设中断处理程序                                 */
/*  请在此处添加所用外设（PPP）的中断处理程序，可用的外设中断处理程序名称      */
/*  请参考启动文件（startup_stm32f10x_xx.s）。                                 */
/******************************************************************************/

/**
  * @brief    本函数处理 PPP 中断请求。
  * @param    无
  * @retval   无
  */
/*void PPP_IRQHandler(void)
{
}*/

/**
  * @}
  */ 


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
