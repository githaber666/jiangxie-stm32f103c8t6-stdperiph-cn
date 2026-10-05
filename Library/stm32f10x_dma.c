/**
  ******************************************************************************
  * @file    stm32f10x_dma.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供所有 DMA 固件函数。
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

/* 包含文件 ------------------------------------------------------------------*/
#include "stm32f10x_dma.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup DMA 
  * @brief DMA 驱动模块
  * @{
  */ 

/** @defgroup DMA_Private_TypesDefinitions
  * @{
  */ 
/**
  * @}
  */

/** @defgroup DMA_Private_Defines
  * @{
  */


/* DMA1 通道 x 中断挂起位掩码 */
#define DMA1_Channel1_IT_Mask    ((uint32_t)(DMA_ISR_GIF1 | DMA_ISR_TCIF1 | DMA_ISR_HTIF1 | DMA_ISR_TEIF1))
#define DMA1_Channel2_IT_Mask    ((uint32_t)(DMA_ISR_GIF2 | DMA_ISR_TCIF2 | DMA_ISR_HTIF2 | DMA_ISR_TEIF2))
#define DMA1_Channel3_IT_Mask    ((uint32_t)(DMA_ISR_GIF3 | DMA_ISR_TCIF3 | DMA_ISR_HTIF3 | DMA_ISR_TEIF3))
#define DMA1_Channel4_IT_Mask    ((uint32_t)(DMA_ISR_GIF4 | DMA_ISR_TCIF4 | DMA_ISR_HTIF4 | DMA_ISR_TEIF4))
#define DMA1_Channel5_IT_Mask    ((uint32_t)(DMA_ISR_GIF5 | DMA_ISR_TCIF5 | DMA_ISR_HTIF5 | DMA_ISR_TEIF5))
#define DMA1_Channel6_IT_Mask    ((uint32_t)(DMA_ISR_GIF6 | DMA_ISR_TCIF6 | DMA_ISR_HTIF6 | DMA_ISR_TEIF6))
#define DMA1_Channel7_IT_Mask    ((uint32_t)(DMA_ISR_GIF7 | DMA_ISR_TCIF7 | DMA_ISR_HTIF7 | DMA_ISR_TEIF7))

/* DMA2 通道 x 中断挂起位掩码 */
#define DMA2_Channel1_IT_Mask    ((uint32_t)(DMA_ISR_GIF1 | DMA_ISR_TCIF1 | DMA_ISR_HTIF1 | DMA_ISR_TEIF1))
#define DMA2_Channel2_IT_Mask    ((uint32_t)(DMA_ISR_GIF2 | DMA_ISR_TCIF2 | DMA_ISR_HTIF2 | DMA_ISR_TEIF2))
#define DMA2_Channel3_IT_Mask    ((uint32_t)(DMA_ISR_GIF3 | DMA_ISR_TCIF3 | DMA_ISR_HTIF3 | DMA_ISR_TEIF3))
#define DMA2_Channel4_IT_Mask    ((uint32_t)(DMA_ISR_GIF4 | DMA_ISR_TCIF4 | DMA_ISR_HTIF4 | DMA_ISR_TEIF4))
#define DMA2_Channel5_IT_Mask    ((uint32_t)(DMA_ISR_GIF5 | DMA_ISR_TCIF5 | DMA_ISR_HTIF5 | DMA_ISR_TEIF5))

/* DMA2 FLAG 掩码 */
#define FLAG_Mask                ((uint32_t)0x10000000)

/* DMA 寄存器掩码 */
#define CCR_CLEAR_Mask           ((uint32_t)0xFFFF800F)

/**
  * @}
  */

/** @defgroup DMA_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup DMA_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup DMA_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup DMA_Private_Functions
  * @{
  */

/**
  * @brief  将 DMAy 通道 x 的寄存器复位为默认值。
  * @param  DMAy_Channelx: y 可为 1 或 2，用于选择 DMA，
  *   x 可为 1 至 7（DMA1）或 1 至 5（DMA2），用于选择 DMA 通道。
  * @retval 无
  */
void DMA_DeInit(DMA_Channel_TypeDef* DMAy_Channelx)
{
  /* 检查参数 */
  assert_param(IS_DMA_ALL_PERIPH(DMAy_Channelx));
  
  /* 失能选定的 DMAy 通道 x */
  DMAy_Channelx->CCR &= (uint16_t)(~DMA_CCR1_EN);
  
  /* 复位 DMAy 通道 x 控制寄存器 */
  DMAy_Channelx->CCR  = 0;
  
  /* 复位 DMAy 通道 x 剩余字节数寄存器 */
  DMAy_Channelx->CNDTR = 0;
  
  /* 复位 DMAy 通道 x 外设地址寄存器 */
  DMAy_Channelx->CPAR  = 0;
  
  /* 复位 DMAy 通道 x 存储器地址寄存器 */
  DMAy_Channelx->CMAR = 0;
  
  if (DMAy_Channelx == DMA1_Channel1)
  {
    /* 复位 DMA1 通道 1 的中断挂起位 */
    DMA1->IFCR |= DMA1_Channel1_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel2)
  {
    /* 复位 DMA1 通道 2 的中断挂起位 */
    DMA1->IFCR |= DMA1_Channel2_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel3)
  {
    /* 复位 DMA1 通道 3 的中断挂起位 */
    DMA1->IFCR |= DMA1_Channel3_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel4)
  {
    /* 复位 DMA1 通道 4 的中断挂起位 */
    DMA1->IFCR |= DMA1_Channel4_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel5)
  {
    /* 复位 DMA1 通道 5 的中断挂起位 */
    DMA1->IFCR |= DMA1_Channel5_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel6)
  {
    /* 复位 DMA1 通道 6 的中断挂起位 */
    DMA1->IFCR |= DMA1_Channel6_IT_Mask;
  }
  else if (DMAy_Channelx == DMA1_Channel7)
  {
    /* 复位 DMA1 通道 7 的中断挂起位 */
    DMA1->IFCR |= DMA1_Channel7_IT_Mask;
  }
  else if (DMAy_Channelx == DMA2_Channel1)
  {
    /* 复位 DMA2 通道 1 的中断挂起位 */
    DMA2->IFCR |= DMA2_Channel1_IT_Mask;
  }
  else if (DMAy_Channelx == DMA2_Channel2)
  {
    /* 复位 DMA2 通道 2 的中断挂起位 */
    DMA2->IFCR |= DMA2_Channel2_IT_Mask;
  }
  else if (DMAy_Channelx == DMA2_Channel3)
  {
    /* 复位 DMA2 通道 3 的中断挂起位 */
    DMA2->IFCR |= DMA2_Channel3_IT_Mask;
  }
  else if (DMAy_Channelx == DMA2_Channel4)
  {
    /* 复位 DMA2 通道 4 的中断挂起位 */
    DMA2->IFCR |= DMA2_Channel4_IT_Mask;
  }
  else
  { 
    if (DMAy_Channelx == DMA2_Channel5)
    {
      /* 复位 DMA2 通道 5 的中断挂起位 */
      DMA2->IFCR |= DMA2_Channel5_IT_Mask;
    }
  }
}

/**
  * @brief  根据指定的参数初始化 DMAy 通道 x，
  *         这些参数位于 DMA_InitStruct 中。
  * @param  DMAy_Channelx: y 可为 1 或 2，用于选择 DMA， 
  *   x 可为 1 至 7（DMA1）或 1 至 5（DMA2），用于选择 DMA 通道。
  * @param  DMA_InitStruct: 指向 DMA_InitTypeDef 结构的指针，
  *         其中包含指定 DMA 通道的配置信息。
  * @retval 无
  */
void DMA_Init(DMA_Channel_TypeDef* DMAy_Channelx, DMA_InitTypeDef* DMA_InitStruct)
{
  uint32_t tmpreg = 0;

  /* 检查参数 */
  assert_param(IS_DMA_ALL_PERIPH(DMAy_Channelx));
  assert_param(IS_DMA_DIR(DMA_InitStruct->DMA_DIR));
  assert_param(IS_DMA_BUFFER_SIZE(DMA_InitStruct->DMA_BufferSize));
  assert_param(IS_DMA_PERIPHERAL_INC_STATE(DMA_InitStruct->DMA_PeripheralInc));
  assert_param(IS_DMA_MEMORY_INC_STATE(DMA_InitStruct->DMA_MemoryInc));   
  assert_param(IS_DMA_PERIPHERAL_DATA_SIZE(DMA_InitStruct->DMA_PeripheralDataSize));
  assert_param(IS_DMA_MEMORY_DATA_SIZE(DMA_InitStruct->DMA_MemoryDataSize));
  assert_param(IS_DMA_MODE(DMA_InitStruct->DMA_Mode));
  assert_param(IS_DMA_PRIORITY(DMA_InitStruct->DMA_Priority));
  assert_param(IS_DMA_M2M_STATE(DMA_InitStruct->DMA_M2M));

/*--------------------------- DMAy 通道 x CCR 配置 -----------------*/
  /* 获取 DMAy_Channelx 的 CCR 值 */
  tmpreg = DMAy_Channelx->CCR;
  /* 清零 MEM2MEM、PL、MSIZE、PSIZE、MINC、PINC、CIRC 和 DIR 位 */
  tmpreg &= CCR_CLEAR_Mask;
  /* 配置 DMAy 通道 x：数据传输、数据宽度、优先级和模式 */
  /* 根据 DMA_DIR 的值设置 DIR 位 */
  /* 根据 DMA_Mode 的值设置 CIRC 位 */
  /* 根据 DMA_PeripheralInc 的值设置 PINC 位 */
  /* 根据 DMA_MemoryInc 的值设置 MINC 位 */
  /* 根据 DMA_PeripheralDataSize 的值设置 PSIZE 位 */
  /* 根据 DMA_MemoryDataSize 的值设置 MSIZE 位 */
  /* 根据 DMA_Priority 的值设置 PL 位 */
  /* 根据 DMA_M2M 的值设置 MEM2MEM 位 */
  tmpreg |= DMA_InitStruct->DMA_DIR | DMA_InitStruct->DMA_Mode |
            DMA_InitStruct->DMA_PeripheralInc | DMA_InitStruct->DMA_MemoryInc |
            DMA_InitStruct->DMA_PeripheralDataSize | DMA_InitStruct->DMA_MemoryDataSize |
            DMA_InitStruct->DMA_Priority | DMA_InitStruct->DMA_M2M;

  /* 写入 DMAy 通道 x 的 CCR 寄存器 */
  DMAy_Channelx->CCR = tmpreg;

/*--------------------------- DMAy 通道 x CNDTR 配置 ---------------*/
  /* 写入 DMAy 通道 x 的 CNDTR 寄存器 */
  DMAy_Channelx->CNDTR = DMA_InitStruct->DMA_BufferSize;

/*--------------------------- DMAy 通道 x CPAR 配置 ----------------*/
  /* 写入 DMAy 通道 x 的 CPAR 寄存器 */
  DMAy_Channelx->CPAR = DMA_InitStruct->DMA_PeripheralBaseAddr;

/*--------------------------- DMAy 通道 x CMAR 配置 ----------------*/
  /* 写入 DMAy 通道 x 的 CMAR 寄存器 */
  DMAy_Channelx->CMAR = DMA_InitStruct->DMA_MemoryBaseAddr;
}

/**
  * @brief  将 DMA_InitStruct 的每个成员填充为默认值。
  * @param  DMA_InitStruct : 指向将被初始化的 DMA_InitTypeDef 结构的指针。
  * @retval 无
  */
void DMA_StructInit(DMA_InitTypeDef* DMA_InitStruct)
{
/*-------------- 复位 DMA 初始化结构体参数值 ------------------*/
  /* 初始化 DMA_PeripheralBaseAddr 成员 */
  DMA_InitStruct->DMA_PeripheralBaseAddr = 0;
  /* 初始化 DMA_MemoryBaseAddr 成员 */
  DMA_InitStruct->DMA_MemoryBaseAddr = 0;
  /* 初始化 DMA_DIR 成员 */
  DMA_InitStruct->DMA_DIR = DMA_DIR_PeripheralSRC;
  /* 初始化 DMA_BufferSize 成员 */
  DMA_InitStruct->DMA_BufferSize = 0;
  /* 初始化 DMA_PeripheralInc 成员 */
  DMA_InitStruct->DMA_PeripheralInc = DMA_PeripheralInc_Disable;
  /* 初始化 DMA_MemoryInc 成员 */
  DMA_InitStruct->DMA_MemoryInc = DMA_MemoryInc_Disable;
  /* 初始化 DMA_PeripheralDataSize 成员 */
  DMA_InitStruct->DMA_PeripheralDataSize = DMA_PeripheralDataSize_Byte;
  /* 初始化 DMA_MemoryDataSize 成员 */
  DMA_InitStruct->DMA_MemoryDataSize = DMA_MemoryDataSize_Byte;
  /* 初始化 DMA_Mode 成员 */
  DMA_InitStruct->DMA_Mode = DMA_Mode_Normal;
  /* 初始化 DMA_Priority 成员 */
  DMA_InitStruct->DMA_Priority = DMA_Priority_Low;
  /* 初始化 DMA_M2M 成员 */
  DMA_InitStruct->DMA_M2M = DMA_M2M_Disable;
}

/**
  * @brief  使能或失能指定的 DMAy 通道 x。
  * @param  DMAy_Channelx: y 可为 1 或 2，用于选择 DMA， 
  *   x 可为 1 至 7（DMA1）或 1 至 5（DMA2），用于选择 DMA 通道。
  * @param  NewState: DMAy 通道 x 的新状态。 
  *   该参数可为：ENABLE 或 DISABLE。
  * @retval 无
  */
void DMA_Cmd(DMA_Channel_TypeDef* DMAy_Channelx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_DMA_ALL_PERIPH(DMAy_Channelx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* 使能选定的 DMAy 通道 x */
    DMAy_Channelx->CCR |= DMA_CCR1_EN;
  }
  else
  {
    /* 失能选定的 DMAy 通道 x */
    DMAy_Channelx->CCR &= (uint16_t)(~DMA_CCR1_EN);
  }
}

/**
  * @brief  使能或失能指定的 DMAy 通道 x 中断。
  * @param  DMAy_Channelx: y 可为 1 或 2，用于选择 DMA， 
  *   x 可为 1 至 7（DMA1）或 1 至 5（DMA2），用于选择 DMA 通道。
  * @param  DMA_IT: 指定要使能或失能的 DMA 中断源。 
  *   该参数可为以下值的任意组合：
  *     @arg DMA_IT_TC:  传输完成中断掩码
  *     @arg DMA_IT_HT:  半传输中断掩码
  *     @arg DMA_IT_TE:  传输错误中断掩码
  * @param  NewState: 指定 DMA 中断的新状态。
  *   该参数可为：ENABLE 或 DISABLE。
  * @retval 无
  */
void DMA_ITConfig(DMA_Channel_TypeDef* DMAy_Channelx, uint32_t DMA_IT, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_DMA_ALL_PERIPH(DMAy_Channelx));
  assert_param(IS_DMA_CONFIG_IT(DMA_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 DMA 中断 */
    DMAy_Channelx->CCR |= DMA_IT;
  }
  else
  {
    /* 失能选定的 DMA 中断 */
    DMAy_Channelx->CCR &= ~DMA_IT;
  }
}

/**
  * @brief  设置当前 DMAy 通道 x 传输中的数据单元数量。
  * @param  DMAy_Channelx: y 可为 1 或 2，用于选择 DMA， 
  *         x 可为 1 至 7（DMA1）或 1 至 5（DMA2），用于选择 DMA 通道。
  * @param  DataNumber: 当前 DMAy 通道 x 传输中的数据单元数量。   
  * @note   本函数只能在 DMAy_Channelx 处于失能状态时使用。                 
  * @retval 无。
  */
void DMA_SetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx, uint16_t DataNumber)
{
  /* 检查参数 */
  assert_param(IS_DMA_ALL_PERIPH(DMAy_Channelx));
  
/*--------------------------- DMAy 通道 x CNDTR 配置 ---------------*/
  /* 写入 DMAy 通道 x 的 CNDTR 寄存器 */
  DMAy_Channelx->CNDTR = DataNumber;  
}

/**
  * @brief  返回当前 DMAy 通道 x 传输中剩余的数据单元数量。
  * @param  DMAy_Channelx: y 可为 1 或 2，用于选择 DMA， 
  *   x 可为 1 至 7（DMA1）或 1 至 5（DMA2），用于选择 DMA 通道。
  * @retval 当前 DMAy 通道 x 传输中剩余的数据单元数量。
  */
uint16_t DMA_GetCurrDataCounter(DMA_Channel_TypeDef* DMAy_Channelx)
{
  /* 检查参数 */
  assert_param(IS_DMA_ALL_PERIPH(DMAy_Channelx));
  /* 返回 DMAy 通道 x 剩余的数据单元数量 */
  return ((uint16_t)(DMAy_Channelx->CNDTR));
}

/**
  * @brief  检查指定的 DMAy 通道 x 标志位是否置位。
  * @param  DMAy_FLAG: 指定要检查的标志位。
  *   该参数可为以下值之一：
  *     @arg DMA1_FLAG_GL1: DMA1 通道 1 全局标志位。
  *     @arg DMA1_FLAG_TC1: DMA1 通道 1 传输完成标志位。
  *     @arg DMA1_FLAG_HT1: DMA1 通道 1 半传输标志位。
  *     @arg DMA1_FLAG_TE1: DMA1 通道 1 传输错误标志位。
  *     @arg DMA1_FLAG_GL2: DMA1 通道 2 全局标志位。
  *     @arg DMA1_FLAG_TC2: DMA1 通道 2 传输完成标志位。
  *     @arg DMA1_FLAG_HT2: DMA1 通道 2 半传输标志位。
  *     @arg DMA1_FLAG_TE2: DMA1 通道 2 传输错误标志位。
  *     @arg DMA1_FLAG_GL3: DMA1 通道 3 全局标志位。
  *     @arg DMA1_FLAG_TC3: DMA1 通道 3 传输完成标志位。
  *     @arg DMA1_FLAG_HT3: DMA1 通道 3 半传输标志位。
  *     @arg DMA1_FLAG_TE3: DMA1 通道 3 传输错误标志位。
  *     @arg DMA1_FLAG_GL4: DMA1 通道 4 全局标志位。
  *     @arg DMA1_FLAG_TC4: DMA1 通道 4 传输完成标志位。
  *     @arg DMA1_FLAG_HT4: DMA1 通道 4 半传输标志位。
  *     @arg DMA1_FLAG_TE4: DMA1 通道 4 传输错误标志位。
  *     @arg DMA1_FLAG_GL5: DMA1 通道 5 全局标志位。
  *     @arg DMA1_FLAG_TC5: DMA1 通道 5 传输完成标志位。
  *     @arg DMA1_FLAG_HT5: DMA1 通道 5 半传输标志位。
  *     @arg DMA1_FLAG_TE5: DMA1 通道 5 传输错误标志位。
  *     @arg DMA1_FLAG_GL6: DMA1 通道 6 全局标志位。
  *     @arg DMA1_FLAG_TC6: DMA1 通道 6 传输完成标志位。
  *     @arg DMA1_FLAG_HT6: DMA1 通道 6 半传输标志位。
  *     @arg DMA1_FLAG_TE6: DMA1 通道 6 传输错误标志位。
  *     @arg DMA1_FLAG_GL7: DMA1 通道 7 全局标志位。
  *     @arg DMA1_FLAG_TC7: DMA1 通道 7 传输完成标志位。
  *     @arg DMA1_FLAG_HT7: DMA1 通道 7 半传输标志位。
  *     @arg DMA1_FLAG_TE7: DMA1 通道 7 传输错误标志位。
  *     @arg DMA2_FLAG_GL1: DMA2 通道 1 全局标志位。
  *     @arg DMA2_FLAG_TC1: DMA2 通道 1 传输完成标志位。
  *     @arg DMA2_FLAG_HT1: DMA2 通道 1 半传输标志位。
  *     @arg DMA2_FLAG_TE1: DMA2 通道 1 传输错误标志位。
  *     @arg DMA2_FLAG_GL2: DMA2 通道 2 全局标志位。
  *     @arg DMA2_FLAG_TC2: DMA2 通道 2 传输完成标志位。
  *     @arg DMA2_FLAG_HT2: DMA2 通道 2 半传输标志位。
  *     @arg DMA2_FLAG_TE2: DMA2 通道 2 传输错误标志位。
  *     @arg DMA2_FLAG_GL3: DMA2 通道 3 全局标志位。
  *     @arg DMA2_FLAG_TC3: DMA2 通道 3 传输完成标志位。
  *     @arg DMA2_FLAG_HT3: DMA2 通道 3 半传输标志位。
  *     @arg DMA2_FLAG_TE3: DMA2 通道 3 传输错误标志位。
  *     @arg DMA2_FLAG_GL4: DMA2 通道 4 全局标志位。
  *     @arg DMA2_FLAG_TC4: DMA2 通道 4 传输完成标志位。
  *     @arg DMA2_FLAG_HT4: DMA2 通道 4 半传输标志位。
  *     @arg DMA2_FLAG_TE4: DMA2 通道 4 传输错误标志位。
  *     @arg DMA2_FLAG_GL5: DMA2 通道 5 全局标志位。
  *     @arg DMA2_FLAG_TC5: DMA2 通道 5 传输完成标志位。
  *     @arg DMA2_FLAG_HT5: DMA2 通道 5 半传输标志位。
  *     @arg DMA2_FLAG_TE5: DMA2 通道 5 传输错误标志位。
  * @retval DMAy_FLAG 的新状态（SET 或 RESET）。
  */
FlagStatus DMA_GetFlagStatus(uint32_t DMAy_FLAG)
{
  FlagStatus bitstatus = RESET;
  uint32_t tmpreg = 0;
  
  /* 检查参数 */
  assert_param(IS_DMA_GET_FLAG(DMAy_FLAG));

  /* 计算所使用的 DMAy */
  if ((DMAy_FLAG & FLAG_Mask) != (uint32_t)RESET)
  {
    /* 获取 DMA2 ISR 寄存器的值 */
    tmpreg = DMA2->ISR ;
  }
  else
  {
    /* 获取 DMA1 ISR 寄存器的值 */
    tmpreg = DMA1->ISR ;
  }

  /* 检查指定 DMAy 标志位的状态 */
  if ((tmpreg & DMAy_FLAG) != (uint32_t)RESET)
  {
    /* DMAy_FLAG 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* DMAy_FLAG 已复位 */
    bitstatus = RESET;
  }
  
  /* 返回 DMAy_FLAG 的状态 */
  return  bitstatus;
}

/**
  * @brief  清除 DMAy 通道 x 的挂起标志位。
  * @param  DMAy_FLAG: 指定要清除的标志位。
  *   该参数可为以下值的任意组合（限于同一个 DMA）：
  *     @arg DMA1_FLAG_GL1: DMA1 通道 1 全局标志位。
  *     @arg DMA1_FLAG_TC1: DMA1 通道 1 传输完成标志位。
  *     @arg DMA1_FLAG_HT1: DMA1 通道 1 半传输标志位。
  *     @arg DMA1_FLAG_TE1: DMA1 通道 1 传输错误标志位。
  *     @arg DMA1_FLAG_GL2: DMA1 通道 2 全局标志位。
  *     @arg DMA1_FLAG_TC2: DMA1 通道 2 传输完成标志位。
  *     @arg DMA1_FLAG_HT2: DMA1 通道 2 半传输标志位。
  *     @arg DMA1_FLAG_TE2: DMA1 通道 2 传输错误标志位。
  *     @arg DMA1_FLAG_GL3: DMA1 通道 3 全局标志位。
  *     @arg DMA1_FLAG_TC3: DMA1 通道 3 传输完成标志位。
  *     @arg DMA1_FLAG_HT3: DMA1 通道 3 半传输标志位。
  *     @arg DMA1_FLAG_TE3: DMA1 通道 3 传输错误标志位。
  *     @arg DMA1_FLAG_GL4: DMA1 通道 4 全局标志位。
  *     @arg DMA1_FLAG_TC4: DMA1 通道 4 传输完成标志位。
  *     @arg DMA1_FLAG_HT4: DMA1 通道 4 半传输标志位。
  *     @arg DMA1_FLAG_TE4: DMA1 通道 4 传输错误标志位。
  *     @arg DMA1_FLAG_GL5: DMA1 通道 5 全局标志位。
  *     @arg DMA1_FLAG_TC5: DMA1 通道 5 传输完成标志位。
  *     @arg DMA1_FLAG_HT5: DMA1 通道 5 半传输标志位。
  *     @arg DMA1_FLAG_TE5: DMA1 通道 5 传输错误标志位。
  *     @arg DMA1_FLAG_GL6: DMA1 通道 6 全局标志位。
  *     @arg DMA1_FLAG_TC6: DMA1 通道 6 传输完成标志位。
  *     @arg DMA1_FLAG_HT6: DMA1 通道 6 半传输标志位。
  *     @arg DMA1_FLAG_TE6: DMA1 通道 6 传输错误标志位。
  *     @arg DMA1_FLAG_GL7: DMA1 通道 7 全局标志位。
  *     @arg DMA1_FLAG_TC7: DMA1 通道 7 传输完成标志位。
  *     @arg DMA1_FLAG_HT7: DMA1 通道 7 半传输标志位。
  *     @arg DMA1_FLAG_TE7: DMA1 通道 7 传输错误标志位。
  *     @arg DMA2_FLAG_GL1: DMA2 通道 1 全局标志位。
  *     @arg DMA2_FLAG_TC1: DMA2 通道 1 传输完成标志位。
  *     @arg DMA2_FLAG_HT1: DMA2 通道 1 半传输标志位。
  *     @arg DMA2_FLAG_TE1: DMA2 通道 1 传输错误标志位。
  *     @arg DMA2_FLAG_GL2: DMA2 通道 2 全局标志位。
  *     @arg DMA2_FLAG_TC2: DMA2 通道 2 传输完成标志位。
  *     @arg DMA2_FLAG_HT2: DMA2 通道 2 半传输标志位。
  *     @arg DMA2_FLAG_TE2: DMA2 通道 2 传输错误标志位。
  *     @arg DMA2_FLAG_GL3: DMA2 通道 3 全局标志位。
  *     @arg DMA2_FLAG_TC3: DMA2 通道 3 传输完成标志位。
  *     @arg DMA2_FLAG_HT3: DMA2 通道 3 半传输标志位。
  *     @arg DMA2_FLAG_TE3: DMA2 通道 3 传输错误标志位。
  *     @arg DMA2_FLAG_GL4: DMA2 通道 4 全局标志位。
  *     @arg DMA2_FLAG_TC4: DMA2 通道 4 传输完成标志位。
  *     @arg DMA2_FLAG_HT4: DMA2 通道 4 半传输标志位。
  *     @arg DMA2_FLAG_TE4: DMA2 通道 4 传输错误标志位。
  *     @arg DMA2_FLAG_GL5: DMA2 通道 5 全局标志位。
  *     @arg DMA2_FLAG_TC5: DMA2 通道 5 传输完成标志位。
  *     @arg DMA2_FLAG_HT5: DMA2 通道 5 半传输标志位。
  *     @arg DMA2_FLAG_TE5: DMA2 通道 5 传输错误标志位。
  * @retval 无
  */
void DMA_ClearFlag(uint32_t DMAy_FLAG)
{
  /* 检查参数 */
  assert_param(IS_DMA_CLEAR_FLAG(DMAy_FLAG));

  /* 计算所使用的 DMAy */
  if ((DMAy_FLAG & FLAG_Mask) != (uint32_t)RESET)
  {
    /* 清除选定的 DMAy 标志位 */
    DMA2->IFCR = DMAy_FLAG;
  }
  else
  {
    /* 清除选定的 DMAy 标志位 */
    DMA1->IFCR = DMAy_FLAG;
  }
}

/**
  * @brief  检查指定的 DMAy 通道 x 中断是否发生。
  * @param  DMAy_IT: 指定要检查的 DMAy 中断源。 
  *   该参数可为以下值之一：
  *     @arg DMA1_IT_GL1: DMA1 通道 1 全局中断。
  *     @arg DMA1_IT_TC1: DMA1 通道 1 传输完成中断。
  *     @arg DMA1_IT_HT1: DMA1 通道 1 半传输中断。
  *     @arg DMA1_IT_TE1: DMA1 通道 1 传输错误中断。
  *     @arg DMA1_IT_GL2: DMA1 通道 2 全局中断。
  *     @arg DMA1_IT_TC2: DMA1 通道 2 传输完成中断。
  *     @arg DMA1_IT_HT2: DMA1 通道 2 半传输中断。
  *     @arg DMA1_IT_TE2: DMA1 通道 2 传输错误中断。
  *     @arg DMA1_IT_GL3: DMA1 通道 3 全局中断。
  *     @arg DMA1_IT_TC3: DMA1 通道 3 传输完成中断。
  *     @arg DMA1_IT_HT3: DMA1 通道 3 半传输中断。
  *     @arg DMA1_IT_TE3: DMA1 通道 3 传输错误中断。
  *     @arg DMA1_IT_GL4: DMA1 通道 4 全局中断。
  *     @arg DMA1_IT_TC4: DMA1 通道 4 传输完成中断。
  *     @arg DMA1_IT_HT4: DMA1 通道 4 半传输中断。
  *     @arg DMA1_IT_TE4: DMA1 通道 4 传输错误中断。
  *     @arg DMA1_IT_GL5: DMA1 通道 5 全局中断。
  *     @arg DMA1_IT_TC5: DMA1 通道 5 传输完成中断。
  *     @arg DMA1_IT_HT5: DMA1 通道 5 半传输中断。
  *     @arg DMA1_IT_TE5: DMA1 通道 5 传输错误中断。
  *     @arg DMA1_IT_GL6: DMA1 通道 6 全局中断。
  *     @arg DMA1_IT_TC6: DMA1 通道 6 传输完成中断。
  *     @arg DMA1_IT_HT6: DMA1 通道 6 半传输中断。
  *     @arg DMA1_IT_TE6: DMA1 通道 6 传输错误中断。
  *     @arg DMA1_IT_GL7: DMA1 通道 7 全局中断。
  *     @arg DMA1_IT_TC7: DMA1 通道 7 传输完成中断。
  *     @arg DMA1_IT_HT7: DMA1 通道 7 半传输中断。
  *     @arg DMA1_IT_TE7: DMA1 通道 7 传输错误中断。
  *     @arg DMA2_IT_GL1: DMA2 通道 1 全局中断。
  *     @arg DMA2_IT_TC1: DMA2 通道 1 传输完成中断。
  *     @arg DMA2_IT_HT1: DMA2 通道 1 半传输中断。
  *     @arg DMA2_IT_TE1: DMA2 通道 1 传输错误中断。
  *     @arg DMA2_IT_GL2: DMA2 通道 2 全局中断。
  *     @arg DMA2_IT_TC2: DMA2 通道 2 传输完成中断。
  *     @arg DMA2_IT_HT2: DMA2 通道 2 半传输中断。
  *     @arg DMA2_IT_TE2: DMA2 通道 2 传输错误中断。
  *     @arg DMA2_IT_GL3: DMA2 通道 3 全局中断。
  *     @arg DMA2_IT_TC3: DMA2 通道 3 传输完成中断。
  *     @arg DMA2_IT_HT3: DMA2 通道 3 半传输中断。
  *     @arg DMA2_IT_TE3: DMA2 通道 3 传输错误中断。
  *     @arg DMA2_IT_GL4: DMA2 通道 4 全局中断。
  *     @arg DMA2_IT_TC4: DMA2 通道 4 传输完成中断。
  *     @arg DMA2_IT_HT4: DMA2 通道 4 半传输中断。
  *     @arg DMA2_IT_TE4: DMA2 通道 4 传输错误中断。
  *     @arg DMA2_IT_GL5: DMA2 通道 5 全局中断。
  *     @arg DMA2_IT_TC5: DMA2 通道 5 传输完成中断。
  *     @arg DMA2_IT_HT5: DMA2 通道 5 半传输中断。
  *     @arg DMA2_IT_TE5: DMA2 通道 5 传输错误中断。
  * @retval DMAy_IT 的新状态（SET 或 RESET）。
  */
ITStatus DMA_GetITStatus(uint32_t DMAy_IT)
{
  ITStatus bitstatus = RESET;
  uint32_t tmpreg = 0;

  /* 检查参数 */
  assert_param(IS_DMA_GET_IT(DMAy_IT));

  /* 计算所使用的 DMA */
  if ((DMAy_IT & FLAG_Mask) != (uint32_t)RESET)
  {
    /* 获取 DMA2 ISR 寄存器的值 */
    tmpreg = DMA2->ISR;
  }
  else
  {
    /* 获取 DMA1 ISR 寄存器的值 */
    tmpreg = DMA1->ISR;
  }

  /* 检查指定 DMAy 中断的状态 */
  if ((tmpreg & DMAy_IT) != (uint32_t)RESET)
  {
    /* DMAy_IT 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* DMAy_IT 已复位 */
    bitstatus = RESET;
  }
  /* 返回 DMA_IT 的状态 */
  return  bitstatus;
}

/**
  * @brief  清除 DMAy 通道 x 的中断挂起位。
  * @param  DMAy_IT: 指定要清除的 DMAy 中断挂起位。
  *   该参数可为以下值的任意组合（限于同一个 DMA）：
  *     @arg DMA1_IT_GL1: DMA1 通道 1 全局中断。
  *     @arg DMA1_IT_TC1: DMA1 通道 1 传输完成中断。
  *     @arg DMA1_IT_HT1: DMA1 通道 1 半传输中断。
  *     @arg DMA1_IT_TE1: DMA1 通道 1 传输错误中断。
  *     @arg DMA1_IT_GL2: DMA1 通道 2 全局中断。
  *     @arg DMA1_IT_TC2: DMA1 通道 2 传输完成中断。
  *     @arg DMA1_IT_HT2: DMA1 通道 2 半传输中断。
  *     @arg DMA1_IT_TE2: DMA1 通道 2 传输错误中断。
  *     @arg DMA1_IT_GL3: DMA1 通道 3 全局中断。
  *     @arg DMA1_IT_TC3: DMA1 通道 3 传输完成中断。
  *     @arg DMA1_IT_HT3: DMA1 通道 3 半传输中断。
  *     @arg DMA1_IT_TE3: DMA1 通道 3 传输错误中断。
  *     @arg DMA1_IT_GL4: DMA1 通道 4 全局中断。
  *     @arg DMA1_IT_TC4: DMA1 通道 4 传输完成中断。
  *     @arg DMA1_IT_HT4: DMA1 通道 4 半传输中断。
  *     @arg DMA1_IT_TE4: DMA1 通道 4 传输错误中断。
  *     @arg DMA1_IT_GL5: DMA1 通道 5 全局中断。
  *     @arg DMA1_IT_TC5: DMA1 通道 5 传输完成中断。
  *     @arg DMA1_IT_HT5: DMA1 通道 5 半传输中断。
  *     @arg DMA1_IT_TE5: DMA1 通道 5 传输错误中断。
  *     @arg DMA1_IT_GL6: DMA1 通道 6 全局中断。
  *     @arg DMA1_IT_TC6: DMA1 通道 6 传输完成中断。
  *     @arg DMA1_IT_HT6: DMA1 通道 6 半传输中断。
  *     @arg DMA1_IT_TE6: DMA1 通道 6 传输错误中断。
  *     @arg DMA1_IT_GL7: DMA1 通道 7 全局中断。
  *     @arg DMA1_IT_TC7: DMA1 通道 7 传输完成中断。
  *     @arg DMA1_IT_HT7: DMA1 通道 7 半传输中断。
  *     @arg DMA1_IT_TE7: DMA1 通道 7 传输错误中断。
  *     @arg DMA2_IT_GL1: DMA2 通道 1 全局中断。
  *     @arg DMA2_IT_TC1: DMA2 通道 1 传输完成中断。
  *     @arg DMA2_IT_HT1: DMA2 通道 1 半传输中断。
  *     @arg DMA2_IT_TE1: DMA2 通道 1 传输错误中断。
  *     @arg DMA2_IT_GL2: DMA2 通道 2 全局中断。
  *     @arg DMA2_IT_TC2: DMA2 通道 2 传输完成中断。
  *     @arg DMA2_IT_HT2: DMA2 通道 2 半传输中断。
  *     @arg DMA2_IT_TE2: DMA2 通道 2 传输错误中断。
  *     @arg DMA2_IT_GL3: DMA2 通道 3 全局中断。
  *     @arg DMA2_IT_TC3: DMA2 通道 3 传输完成中断。
  *     @arg DMA2_IT_HT3: DMA2 通道 3 半传输中断。
  *     @arg DMA2_IT_TE3: DMA2 通道 3 传输错误中断。
  *     @arg DMA2_IT_GL4: DMA2 通道 4 全局中断。
  *     @arg DMA2_IT_TC4: DMA2 通道 4 传输完成中断。
  *     @arg DMA2_IT_HT4: DMA2 通道 4 半传输中断。
  *     @arg DMA2_IT_TE4: DMA2 通道 4 传输错误中断。
  *     @arg DMA2_IT_GL5: DMA2 通道 5 全局中断。
  *     @arg DMA2_IT_TC5: DMA2 通道 5 传输完成中断。
  *     @arg DMA2_IT_HT5: DMA2 通道 5 半传输中断。
  *     @arg DMA2_IT_TE5: DMA2 通道 5 传输错误中断。
  * @retval 无
  */
void DMA_ClearITPendingBit(uint32_t DMAy_IT)
{
  /* 检查参数 */
  assert_param(IS_DMA_CLEAR_IT(DMAy_IT));

  /* 计算所使用的 DMAy */
  if ((DMAy_IT & FLAG_Mask) != (uint32_t)RESET)
  {
    /* 清除选定的 DMAy 中断挂起位 */
    DMA2->IFCR = DMAy_IT;
  }
  else
  {
    /* 清除选定的 DMAy 中断挂起位 */
    DMA1->IFCR = DMAy_IT;
  }
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
