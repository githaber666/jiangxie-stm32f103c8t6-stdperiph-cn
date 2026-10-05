/**
  ******************************************************************************
  * @file    stm32f10x_dac.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供 DAC 的所有固件函数。
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
#include "stm32f10x_dac.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup DAC 
  * @brief DAC 驱动模块
  * @{
  */ 

/** @defgroup DAC_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup DAC_Private_Defines
  * @{
  */

/* CR 寄存器掩码 */
#define CR_CLEAR_MASK              ((uint32_t)0x00000FFE)

/* DAC 双通道 SWTRIG 掩码 */
#define DUAL_SWTRIG_SET            ((uint32_t)0x00000003)
#define DUAL_SWTRIG_RESET          ((uint32_t)0xFFFFFFFC)

/* DHR 寄存器偏移 */
#define DHR12R1_OFFSET             ((uint32_t)0x00000008)
#define DHR12R2_OFFSET             ((uint32_t)0x00000014)
#define DHR12RD_OFFSET             ((uint32_t)0x00000020)

/* DOR 寄存器偏移 */
#define DOR_OFFSET                 ((uint32_t)0x0000002C)
/**
  * @}
  */

/** @defgroup DAC_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup DAC_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup DAC_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup DAC_Private_Functions
  * @{
  */

/**
  * @brief  将 DAC 外设寄存器复位为默认值。
  * @param  无
  * @retval 无
  */
void DAC_DeInit(void)
{
  /* 使能 DAC 复位状态 */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_DAC, ENABLE);
  /* 将 DAC 从复位状态释放 */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_DAC, DISABLE);
}

/**
  * @brief  根据 DAC_InitStruct 中指定的参数
  *         初始化 DAC 外设。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  DAC_InitStruct：指向 DAC_InitTypeDef 结构的指针，
  *        该结构包含指定 DAC 通道的配置信息。
  * @retval 无
  */
void DAC_Init(uint32_t DAC_Channel, DAC_InitTypeDef* DAC_InitStruct)
{
  uint32_t tmpreg1 = 0, tmpreg2 = 0;
  /* 检查 DAC 参数 */
  assert_param(IS_DAC_TRIGGER(DAC_InitStruct->DAC_Trigger));
  assert_param(IS_DAC_GENERATE_WAVE(DAC_InitStruct->DAC_WaveGeneration));
  assert_param(IS_DAC_LFSR_UNMASK_TRIANGLE_AMPLITUDE(DAC_InitStruct->DAC_LFSRUnmask_TriangleAmplitude));
  assert_param(IS_DAC_OUTPUT_BUFFER_STATE(DAC_InitStruct->DAC_OutputBuffer));
/*---------------------------- DAC CR 配置 --------------------------*/
  /* 读取 DAC CR 的值 */
  tmpreg1 = DAC->CR;
  /* 清除 BOFFx、TENx、TSELx、WAVEx 和 MAMPx 位 */
  tmpreg1 &= ~(CR_CLEAR_MASK << DAC_Channel);
  /* 为所选 DAC 通道进行配置：输出缓冲器、触发、波形生成、
     波形生成的掩码/幅度 */
  /* 根据 DAC_Trigger 的值设置 TSELx 和 TENx 位 */
  /* 根据 DAC_WaveGeneration 的值设置 WAVEx 位 */
  /* 根据 DAC_LFSRUnmask_TriangleAmplitude 的值设置 MAMPx 位 */ 
  /* 根据 DAC_OutputBuffer 的值设置 BOFFx 位 */   
  tmpreg2 = (DAC_InitStruct->DAC_Trigger | DAC_InitStruct->DAC_WaveGeneration |
             DAC_InitStruct->DAC_LFSRUnmask_TriangleAmplitude | DAC_InitStruct->DAC_OutputBuffer);
  /* 根据 DAC_Channel 计算 CR 寄存器的值 */
  tmpreg1 |= tmpreg2 << DAC_Channel;
  /* 写入 DAC CR */
  DAC->CR = tmpreg1;
}

/**
  * @brief  将 DAC_InitStruct 的每个成员填充为默认值。
  * @param  DAC_InitStruct：指向将被初始化的 DAC_InitTypeDef 结构的
  *         指针。
  * @retval 无
  */
void DAC_StructInit(DAC_InitTypeDef* DAC_InitStruct)
{
/*--------------- 复位 DAC 初始化结构体各参数的值 -----------------*/
  /* 初始化 DAC_Trigger 成员 */
  DAC_InitStruct->DAC_Trigger = DAC_Trigger_None;
  /* 初始化 DAC_WaveGeneration 成员 */
  DAC_InitStruct->DAC_WaveGeneration = DAC_WaveGeneration_None;
  /* 初始化 DAC_LFSRUnmask_TriangleAmplitude 成员 */
  DAC_InitStruct->DAC_LFSRUnmask_TriangleAmplitude = DAC_LFSRUnmask_Bit0;
  /* 初始化 DAC_OutputBuffer 成员 */
  DAC_InitStruct->DAC_OutputBuffer = DAC_OutputBuffer_Enable;
}

/**
  * @brief  使能或失能指定的 DAC 通道。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  NewState：DAC 通道的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void DAC_Cmd(uint32_t DAC_Channel, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 DAC 通道 */
    DAC->CR |= (DAC_CR_EN1 << DAC_Channel);
  }
  else
  {
    /* 失能选定的 DAC 通道 */
    DAC->CR &= ~(DAC_CR_EN1 << DAC_Channel);
  }
}
#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
/**
  * @brief  使能或失能指定的 DAC 中断。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  DAC_IT：指定要使能或失能的 DAC 中断源。
  *   该参数可以是以下值：
  *     @arg DAC_IT_DMAUDR：DMA 下溢中断掩码                      
  * @param  NewState：指定 DAC 中断的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */ 
void DAC_ITConfig(uint32_t DAC_Channel, uint32_t DAC_IT, FunctionalState NewState)  
{
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_DAC_IT(DAC_IT)); 

  if (NewState != DISABLE)
  {
    /* 使能选定的 DAC 中断 */
    DAC->CR |=  (DAC_IT << DAC_Channel);
  }
  else
  {
    /* 失能选定的 DAC 中断 */
    DAC->CR &= (~(uint32_t)(DAC_IT << DAC_Channel));
  }
}
#endif

/**
  * @brief  使能或失能指定的 DAC 通道 DMA 请求。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  NewState：选定 DAC 通道 DMA 请求的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void DAC_DMACmd(uint32_t DAC_Channel, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 DAC 通道 DMA 请求 */
    DAC->CR |= (DAC_CR_DMAEN1 << DAC_Channel);
  }
  else
  {
    /* 失能选定的 DAC 通道 DMA 请求 */
    DAC->CR &= ~(DAC_CR_DMAEN1 << DAC_Channel);
  }
}

/**
  * @brief  使能或失能选定的 DAC 通道软件触发。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  NewState：选定 DAC 通道软件触发的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void DAC_SoftwareTriggerCmd(uint32_t DAC_Channel, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定 DAC 通道的软件触发 */
    DAC->SWTRIGR |= (uint32_t)DAC_SWTRIGR_SWTRIG1 << (DAC_Channel >> 4);
  }
  else
  {
    /* 失能选定 DAC 通道的软件触发 */
    DAC->SWTRIGR &= ~((uint32_t)DAC_SWTRIGR_SWTRIG1 << (DAC_Channel >> 4));
  }
}

/**
  * @brief  同时使能或失能两个 DAC 通道的软件
  *   触发。
  * @param  NewState：DAC 通道软件触发的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void DAC_DualSoftwareTriggerCmd(FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能两个 DAC 通道的软件触发 */
    DAC->SWTRIGR |= DUAL_SWTRIG_SET ;
  }
  else
  {
    /* 失能两个 DAC 通道的软件触发 */
    DAC->SWTRIGR &= DUAL_SWTRIG_RESET;
  }
}

/**
  * @brief  使能或失能选定的 DAC 通道波形生成。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  DAC_Wave：指定要使能或失能的波形类型。
  *   该参数可以是以下值之一：
  *     @arg DAC_Wave_Noise：噪声波生成
  *     @arg DAC_Wave_Triangle：三角波生成
  * @param  NewState：选定 DAC 通道波形生成的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void DAC_WaveGenerationCmd(uint32_t DAC_Channel, uint32_t DAC_Wave, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_DAC_WAVE(DAC_Wave)); 
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定 DAC 通道的波形生成 */
    DAC->CR |= DAC_Wave << DAC_Channel;
  }
  else
  {
    /* 失能选定 DAC 通道的波形生成 */
    DAC->CR &= ~(DAC_Wave << DAC_Channel);
  }
}

/**
  * @brief  设置 DAC 通道 1 的指定数据保持寄存器值。
  * @param  DAC_Align：指定 DAC 通道 1 的数据对齐方式。
  *   该参数可以是以下值之一：
  *     @arg DAC_Align_8b_R：选择 8 位右对齐
  *     @arg DAC_Align_12b_L：选择 12 位左对齐
  *     @arg DAC_Align_12b_R：选择 12 位右对齐
  * @param  Data：要装载到选定数据保持寄存器中的数据。
  * @retval 无
  */
void DAC_SetChannel1Data(uint32_t DAC_Align, uint16_t Data)
{  
  __IO uint32_t tmp = 0;
  
  /* 检查参数 */
  assert_param(IS_DAC_ALIGN(DAC_Align));
  assert_param(IS_DAC_DATA(Data));
  
  tmp = (uint32_t)DAC_BASE; 
  tmp += DHR12R1_OFFSET + DAC_Align;

  /* 设置 DAC 通道 1 选定的数据保持寄存器 */
  *(__IO uint32_t *) tmp = Data;
}

/**
  * @brief  设置 DAC 通道 2 的指定数据保持寄存器值。
  * @param  DAC_Align：指定 DAC 通道 2 的数据对齐方式。
  *   该参数可以是以下值之一：
  *     @arg DAC_Align_8b_R：选择 8 位右对齐
  *     @arg DAC_Align_12b_L：选择 12 位左对齐
  *     @arg DAC_Align_12b_R：选择 12 位右对齐
  * @param  Data：要装载到选定数据保持寄存器中的数据。
  * @retval 无
  */
void DAC_SetChannel2Data(uint32_t DAC_Align, uint16_t Data)
{
  __IO uint32_t tmp = 0;

  /* 检查参数 */
  assert_param(IS_DAC_ALIGN(DAC_Align));
  assert_param(IS_DAC_DATA(Data));
  
  tmp = (uint32_t)DAC_BASE;
  tmp += DHR12R2_OFFSET + DAC_Align;

  /* 设置 DAC 通道 2 选定的数据保持寄存器 */
  *(__IO uint32_t *)tmp = Data;
}

/**
  * @brief  设置双通道 DAC 的指定数据保持寄存器
  *   值。
  * @param  DAC_Align：指定双通道 DAC 的数据对齐方式。
  *   该参数可以是以下值之一：
  *     @arg DAC_Align_8b_R：选择 8 位右对齐
  *     @arg DAC_Align_12b_L：选择 12 位左对齐
  *     @arg DAC_Align_12b_R：选择 12 位右对齐
  * @param  Data2：要装载到选定数据保持寄存器中的
  *   DAC 通道 2 数据。
  * @param  Data1：要装载到选定数据保持寄存器中的
  *   DAC 通道 1 数据。
  * @retval 无
  */
void DAC_SetDualChannelData(uint32_t DAC_Align, uint16_t Data2, uint16_t Data1)
{
  uint32_t data = 0, tmp = 0;
  
  /* 检查参数 */
  assert_param(IS_DAC_ALIGN(DAC_Align));
  assert_param(IS_DAC_DATA(Data1));
  assert_param(IS_DAC_DATA(Data2));
  
  /* 计算并设置双通道 DAC 数据保持寄存器的值 */
  if (DAC_Align == DAC_Align_8b_R)
  {
    data = ((uint32_t)Data2 << 8) | Data1; 
  }
  else
  {
    data = ((uint32_t)Data2 << 16) | Data1;
  }
  
  tmp = (uint32_t)DAC_BASE;
  tmp += DHR12RD_OFFSET + DAC_Align;

  /* 设置双通道 DAC 选定的数据保持寄存器 */
  *(__IO uint32_t *)tmp = data;
}

/**
  * @brief  返回选定 DAC 通道最后一次的数据输出值。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @retval 选定 DAC 通道的数据输出值。
  */
uint16_t DAC_GetDataOutputValue(uint32_t DAC_Channel)
{
  __IO uint32_t tmp = 0;
  
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  
  tmp = (uint32_t) DAC_BASE ;
  tmp += DOR_OFFSET + ((uint32_t)DAC_Channel >> 2);
  
  /* 返回 DAC 通道数据输出寄存器的值 */
  return (uint16_t) (*(__IO uint32_t*) tmp);
}

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
/**
  * @brief  检查指定的 DAC 标志位置位与否。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  DAC_FLAG：指定要检查的标志位。
  *   该参数只能是以下值：
  *     @arg DAC_FLAG_DMAUDR：DMA 下溢标志位                                                 
  * @retval DAC_FLAG 的新状态（SET 或 RESET）。
  */
FlagStatus DAC_GetFlagStatus(uint32_t DAC_Channel, uint32_t DAC_FLAG)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_DAC_FLAG(DAC_FLAG));

  /* 检查指定 DAC 标志位的状态 */
  if ((DAC->SR & (DAC_FLAG << DAC_Channel)) != (uint8_t)RESET)
  {
    /* DAC_FLAG 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* DAC_FLAG 已复位 */
    bitstatus = RESET;
  }
  /* 返回 DAC_FLAG 的状态 */
  return  bitstatus;
}

/**
  * @brief  清除 DAC 通道 x 的挂起标志位。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  DAC_FLAG：指定要清除的标志位。
  *   该参数可以是以下值：
  *     @arg DAC_FLAG_DMAUDR：DMA 下溢标志位                           
  * @retval 无
  */
void DAC_ClearFlag(uint32_t DAC_Channel, uint32_t DAC_FLAG)
{
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_DAC_FLAG(DAC_FLAG));

  /* 清除选定的 DAC 标志位 */
  DAC->SR = (DAC_FLAG << DAC_Channel);
}

/**
  * @brief  检查指定的 DAC 中断是否发生。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  DAC_IT：指定要检查的 DAC 中断源。
  *   该参数可以是以下值：
  *     @arg DAC_IT_DMAUDR：DMA 下溢中断掩码                       
  * @retval DAC_IT 的新状态（SET 或 RESET）。
  */
ITStatus DAC_GetITStatus(uint32_t DAC_Channel, uint32_t DAC_IT)
{
  ITStatus bitstatus = RESET;
  uint32_t enablestatus = 0;
  
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_DAC_IT(DAC_IT));

  /* 获取 DAC_IT 使能位的状态 */
  enablestatus = (DAC->CR & (DAC_IT << DAC_Channel)) ;
  
  /* 检查指定 DAC 中断的状态 */
  if (((DAC->SR & (DAC_IT << DAC_Channel)) != (uint32_t)RESET) && enablestatus)
  {
    /* DAC_IT 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* DAC_IT 已复位 */
    bitstatus = RESET;
  }
  /* 返回 DAC_IT 的状态 */
  return  bitstatus;
}

/**
  * @brief  清除 DAC 通道 x 的中断挂起位。
  * @param  DAC_Channel：所选的 DAC 通道。
  *   该参数可以是以下值之一：
  *     @arg DAC_Channel_1：选择 DAC 通道 1
  *     @arg DAC_Channel_2：选择 DAC 通道 2
  * @param  DAC_IT：指定要清除的 DAC 中断挂起位。
  *   该参数可以是以下值：
  *     @arg DAC_IT_DMAUDR：DMA 下溢中断掩码                         
  * @retval 无
  */
void DAC_ClearITPendingBit(uint32_t DAC_Channel, uint32_t DAC_IT)
{
  /* 检查参数 */
  assert_param(IS_DAC_CHANNEL(DAC_Channel));
  assert_param(IS_DAC_IT(DAC_IT)); 

  /* 清除选定的 DAC 中断挂起位 */
  DAC->SR = (DAC_IT << DAC_Channel);
}
#endif

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
