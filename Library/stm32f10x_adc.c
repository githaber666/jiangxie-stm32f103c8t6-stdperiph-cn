/**
  ******************************************************************************
  * @file    stm32f10x_adc.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供 ADC 的所有固件函数。
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
#include "stm32f10x_adc.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup ADC 
  * @brief ADC 驱动模块
  * @{
  */

/** @defgroup ADC_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Defines
  * @{
  */

/* ADC DISCNUM 掩码 */
#define CR1_DISCNUM_Reset           ((uint32_t)0xFFFF1FFF)

/* ADC DISCEN 掩码 */
#define CR1_DISCEN_Set              ((uint32_t)0x00000800)
#define CR1_DISCEN_Reset            ((uint32_t)0xFFFFF7FF)

/* ADC JAUTO 掩码 */
#define CR1_JAUTO_Set               ((uint32_t)0x00000400)
#define CR1_JAUTO_Reset             ((uint32_t)0xFFFFFBFF)

/* ADC JDISCEN 掩码 */
#define CR1_JDISCEN_Set             ((uint32_t)0x00001000)
#define CR1_JDISCEN_Reset           ((uint32_t)0xFFFFEFFF)

/* ADC AWDCH 掩码 */
#define CR1_AWDCH_Reset             ((uint32_t)0xFFFFFFE0)

/* ADC 模拟看门狗使能模式掩码 */
#define CR1_AWDMode_Reset           ((uint32_t)0xFF3FFDFF)

/* CR1 寄存器掩码 */
#define CR1_CLEAR_Mask              ((uint32_t)0xFFF0FEFF)

/* ADC ADON 掩码 */
#define CR2_ADON_Set                ((uint32_t)0x00000001)
#define CR2_ADON_Reset              ((uint32_t)0xFFFFFFFE)

/* ADC DMA 掩码 */
#define CR2_DMA_Set                 ((uint32_t)0x00000100)
#define CR2_DMA_Reset               ((uint32_t)0xFFFFFEFF)

/* ADC RSTCAL 掩码 */
#define CR2_RSTCAL_Set              ((uint32_t)0x00000008)

/* ADC CAL 掩码 */
#define CR2_CAL_Set                 ((uint32_t)0x00000004)

/* ADC SWSTART 掩码 */
#define CR2_SWSTART_Set             ((uint32_t)0x00400000)

/* ADC EXTTRIG 掩码 */
#define CR2_EXTTRIG_Set             ((uint32_t)0x00100000)
#define CR2_EXTTRIG_Reset           ((uint32_t)0xFFEFFFFF)

/* ADC 软件启动掩码 */
#define CR2_EXTTRIG_SWSTART_Set     ((uint32_t)0x00500000)
#define CR2_EXTTRIG_SWSTART_Reset   ((uint32_t)0xFFAFFFFF)

/* ADC JEXTSEL 掩码 */
#define CR2_JEXTSEL_Reset           ((uint32_t)0xFFFF8FFF)

/* ADC JEXTTRIG 掩码 */
#define CR2_JEXTTRIG_Set            ((uint32_t)0x00008000)
#define CR2_JEXTTRIG_Reset          ((uint32_t)0xFFFF7FFF)

/* ADC JSWSTART 掩码 */
#define CR2_JSWSTART_Set            ((uint32_t)0x00200000)

/* ADC 注入通道软件启动掩码 */
#define CR2_JEXTTRIG_JSWSTART_Set   ((uint32_t)0x00208000)
#define CR2_JEXTTRIG_JSWSTART_Reset ((uint32_t)0xFFDF7FFF)

/* ADC TSPD 掩码 */
#define CR2_TSVREFE_Set             ((uint32_t)0x00800000)
#define CR2_TSVREFE_Reset           ((uint32_t)0xFF7FFFFF)

/* CR2 寄存器掩码 */
#define CR2_CLEAR_Mask              ((uint32_t)0xFFF1F7FD)

/* ADC SQx 掩码 */
#define SQR3_SQ_Set                 ((uint32_t)0x0000001F)
#define SQR2_SQ_Set                 ((uint32_t)0x0000001F)
#define SQR1_SQ_Set                 ((uint32_t)0x0000001F)

/* SQR1 寄存器掩码 */
#define SQR1_CLEAR_Mask             ((uint32_t)0xFF0FFFFF)

/* ADC JSQx 掩码 */
#define JSQR_JSQ_Set                ((uint32_t)0x0000001F)

/* ADC JL 掩码 */
#define JSQR_JL_Set                 ((uint32_t)0x00300000)
#define JSQR_JL_Reset               ((uint32_t)0xFFCFFFFF)

/* ADC SMPx 掩码 */
#define SMPR1_SMP_Set               ((uint32_t)0x00000007)
#define SMPR2_SMP_Set               ((uint32_t)0x00000007)

/* ADC JDRx 寄存器偏移 */
#define JDR_Offset                  ((uint8_t)0x28)

/* ADC1 DR 寄存器基地址 */
#define DR_ADDRESS                  ((uint32_t)0x4001244C)

/**
  * @}
  */

/** @defgroup ADC_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup ADC_Private_Functions
  * @{
  */

/**
  * @brief  将 ADCx 外设寄存器复位为默认值。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @retval 无
  */
void ADC_DeInit(ADC_TypeDef* ADCx)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  
  if (ADCx == ADC1)
  {
    /* 使能 ADC1 复位状态 */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1, ENABLE);
    /* 将 ADC1 从复位状态释放 */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC1, DISABLE);
  }
  else if (ADCx == ADC2)
  {
    /* 使能 ADC2 复位状态 */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC2, ENABLE);
    /* 将 ADC2 从复位状态释放 */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC2, DISABLE);
  }
  else
  {
    if (ADCx == ADC3)
    {
      /* 使能 ADC3 复位状态 */
      RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3, ENABLE);
      /* 将 ADC3 从复位状态释放 */
      RCC_APB2PeriphResetCmd(RCC_APB2Periph_ADC3, DISABLE);
    }
  }
}

/**
  * @brief  根据 ADC_InitStruct 中指定的参数初始化 ADCx 外设。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_InitStruct：指向 ADC_InitTypeDef 结构的指针，该结构包含
  *         指定 ADC 外设的配置信息。
  * @retval 无
  */
void ADC_Init(ADC_TypeDef* ADCx, ADC_InitTypeDef* ADC_InitStruct)
{
  uint32_t tmpreg1 = 0;
  uint8_t tmpreg2 = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_MODE(ADC_InitStruct->ADC_Mode));
  assert_param(IS_FUNCTIONAL_STATE(ADC_InitStruct->ADC_ScanConvMode));
  assert_param(IS_FUNCTIONAL_STATE(ADC_InitStruct->ADC_ContinuousConvMode));
  assert_param(IS_ADC_EXT_TRIG(ADC_InitStruct->ADC_ExternalTrigConv));   
  assert_param(IS_ADC_DATA_ALIGN(ADC_InitStruct->ADC_DataAlign)); 
  assert_param(IS_ADC_REGULAR_LENGTH(ADC_InitStruct->ADC_NbrOfChannel));

  /*---------------------------- ADCx CR1 配置 -----------------*/
  /* 读取 ADCx CR1 的值 */
  tmpreg1 = ADCx->CR1;
  /* 清除 DUALMOD 和 SCAN 位 */
  tmpreg1 &= CR1_CLEAR_Mask;
  /* 配置 ADCx：双重模式和扫描转换模式 */
  /* 根据 ADC_Mode 的值设置 DUALMOD 位 */
  /* 根据 ADC_ScanConvMode 的值设置 SCAN 位 */
  tmpreg1 |= (uint32_t)(ADC_InitStruct->ADC_Mode | ((uint32_t)ADC_InitStruct->ADC_ScanConvMode << 8));
  /* 写入 ADCx CR1 */
  ADCx->CR1 = tmpreg1;

  /*---------------------------- ADCx CR2 配置 -----------------*/
  /* 读取 ADCx CR2 的值 */
  tmpreg1 = ADCx->CR2;
  /* 清除 CONT、ALIGN 和 EXTSEL 位 */
  tmpreg1 &= CR2_CLEAR_Mask;
  /* 配置 ADCx：外部触发事件和连续转换模式 */
  /* 根据 ADC_DataAlign 的值设置 ALIGN 位 */
  /* 根据 ADC_ExternalTrigConv 的值设置 EXTSEL 位 */
  /* 根据 ADC_ContinuousConvMode 的值设置 CONT 位 */
  tmpreg1 |= (uint32_t)(ADC_InitStruct->ADC_DataAlign | ADC_InitStruct->ADC_ExternalTrigConv |
            ((uint32_t)ADC_InitStruct->ADC_ContinuousConvMode << 1));
  /* 写入 ADCx CR2 */
  ADCx->CR2 = tmpreg1;

  /*---------------------------- ADCx SQR1 配置 -----------------*/
  /* 读取 ADCx SQR1 的值 */
  tmpreg1 = ADCx->SQR1;
  /* 清除 L 位 */
  tmpreg1 &= SQR1_CLEAR_Mask;
  /* 配置 ADCx：规则通道序列长度 */
  /* 根据 ADC_NbrOfChannel 的值设置 L 位 */
  tmpreg2 |= (uint8_t) (ADC_InitStruct->ADC_NbrOfChannel - (uint8_t)1);
  tmpreg1 |= (uint32_t)tmpreg2 << 20;
  /* 写入 ADCx SQR1 */
  ADCx->SQR1 = tmpreg1;
}

/**
  * @brief  将 ADC_InitStruct 的每个成员填充为默认值。
  * @param  ADC_InitStruct：指向将被初始化的 ADC_InitTypeDef 结构的指针。
  * @retval 无
  */
void ADC_StructInit(ADC_InitTypeDef* ADC_InitStruct)
{
  /* 复位 ADC 初始化结构体各参数的值 */
  /* 初始化 ADC_Mode 成员 */
  ADC_InitStruct->ADC_Mode = ADC_Mode_Independent;
  /* 初始化 ADC_ScanConvMode 成员 */
  ADC_InitStruct->ADC_ScanConvMode = DISABLE;
  /* 初始化 ADC_ContinuousConvMode 成员 */
  ADC_InitStruct->ADC_ContinuousConvMode = DISABLE;
  /* 初始化 ADC_ExternalTrigConv 成员 */
  ADC_InitStruct->ADC_ExternalTrigConv = ADC_ExternalTrigConv_T1_CC1;
  /* 初始化 ADC_DataAlign 成员 */
  ADC_InitStruct->ADC_DataAlign = ADC_DataAlign_Right;
  /* 初始化 ADC_NbrOfChannel 成员 */
  ADC_InitStruct->ADC_NbrOfChannel = 1;
}

/**
  * @brief  使能或失能指定的 ADC 外设。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  NewState：ADCx 外设的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_Cmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 置位 ADON 位，将 ADC 从掉电模式唤醒 */
    ADCx->CR2 |= CR2_ADON_Set;
  }
  else
  {
    /* 失能选定的 ADC 外设 */
    ADCx->CR2 &= CR2_ADON_Reset;
  }
}

/**
  * @brief  使能或失能指定的 ADC DMA 请求。
  * @param  ADCx：x 可以是 1 或 3，用于选择 ADC 外设。
  *   注意：ADC2 不具备 DMA 功能。
  * @param  NewState：选定 ADC DMA 传输的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_DMACmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_DMA_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 ADC DMA 请求 */
    ADCx->CR2 |= CR2_DMA_Set;
  }
  else
  {
    /* 失能选定的 ADC DMA 请求 */
    ADCx->CR2 &= CR2_DMA_Reset;
  }
}

/**
  * @brief  使能或失能指定的 ADC 中断。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_IT：指定要使能或失能的 ADC 中断源。
  *   该参数可以是以下值的任意组合：
  *     @arg ADC_IT_EOC：转换结束中断掩码
  *     @arg ADC_IT_AWD：模拟看门狗中断掩码
  *     @arg ADC_IT_JEOC：注入转换结束中断掩码
  * @param  NewState：指定 ADC 中断的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_ITConfig(ADC_TypeDef* ADCx, uint16_t ADC_IT, FunctionalState NewState)
{
  uint8_t itmask = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_ADC_IT(ADC_IT));
  /* 获取 ADC 中断索引 */
  itmask = (uint8_t)ADC_IT;
  if (NewState != DISABLE)
  {
    /* 使能选定的 ADC 中断 */
    ADCx->CR1 |= itmask;
  }
  else
  {
    /* 失能选定的 ADC 中断 */
    ADCx->CR1 &= (~(uint32_t)itmask);
  }
}

/**
  * @brief  复位选定的 ADC 校准寄存器。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @retval 无
  */
void ADC_ResetCalibration(ADC_TypeDef* ADCx)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  /* 复位选定的 ADC 校准寄存器 */  
  ADCx->CR2 |= CR2_RSTCAL_Set;
}

/**
  * @brief  获取选定 ADC 校准寄存器复位的状态。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @retval ADC 校准寄存器复位的新状态（SET 或 RESET）。
  */
FlagStatus ADC_GetResetCalibrationStatus(ADC_TypeDef* ADCx)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  /* 检查 RSTCAL 位的状态 */
  if ((ADCx->CR2 & CR2_RSTCAL_Set) != (uint32_t)RESET)
  {
    /* RSTCAL 位已置位 */
    bitstatus = SET;
  }
  else
  {
    /* RSTCAL 位已复位 */
    bitstatus = RESET;
  }
  /* 返回 RSTCAL 位的状态 */
  return  bitstatus;
}

/**
  * @brief  启动选定的 ADC 校准过程。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @retval 无
  */
void ADC_StartCalibration(ADC_TypeDef* ADCx)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  /* 使能选定的 ADC 校准过程 */  
  ADCx->CR2 |= CR2_CAL_Set;
}

/**
  * @brief  获取选定的 ADC 校准状态。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @retval ADC 校准的新状态（SET 或 RESET）。
  */
FlagStatus ADC_GetCalibrationStatus(ADC_TypeDef* ADCx)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  /* 检查 CAL 位的状态 */
  if ((ADCx->CR2 & CR2_CAL_Set) != (uint32_t)RESET)
  {
    /* CAL 位已置位：校准正在进行 */
    bitstatus = SET;
  }
  else
  {
    /* CAL 位已复位：校准结束 */
    bitstatus = RESET;
  }
  /* 返回 CAL 位的状态 */
  return  bitstatus;
}

/**
  * @brief  使能或失能选定的 ADC 软件启动转换。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  NewState：选定 ADC 软件启动转换的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_SoftwareStartConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定 ADC 在外部事件上转换，并启动选定的 ADC 转换 */
    ADCx->CR2 |= CR2_EXTTRIG_SWSTART_Set;
  }
  else
  {
    /* 失能选定 ADC 在外部事件上转换，并停止选定的 ADC 转换 */
    ADCx->CR2 &= CR2_EXTTRIG_SWSTART_Reset;
  }
}

/**
  * @brief  获取选定的 ADC 软件启动转换状态。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @retval ADC 软件启动转换的新状态（SET 或 RESET）。
  */
FlagStatus ADC_GetSoftwareStartConvStatus(ADC_TypeDef* ADCx)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  /* 检查 SWSTART 位的状态 */
  if ((ADCx->CR2 & CR2_SWSTART_Set) != (uint32_t)RESET)
  {
    /* SWSTART 位已置位 */
    bitstatus = SET;
  }
  else
  {
    /* SWSTART 位已复位 */
    bitstatus = RESET;
  }
  /* 返回 SWSTART 位的状态 */
  return  bitstatus;
}

/**
  * @brief  为选定的 ADC 规则组通道配置间断模式。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  Number：指定间断模式下规则通道的计数值。
  *         该数值必须在 1 到 8 之间。
  * @retval 无
  */
void ADC_DiscModeChannelCountConfig(ADC_TypeDef* ADCx, uint8_t Number)
{
  uint32_t tmpreg1 = 0;
  uint32_t tmpreg2 = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_REGULAR_DISC_NUMBER(Number));
  /* 读取原寄存器值 */
  tmpreg1 = ADCx->CR1;
  /* 清除原有的间断模式通道计数 */
  tmpreg1 &= CR1_DISCNUM_Reset;
  /* 设置间断模式通道计数 */
  tmpreg2 = Number - 1;
  tmpreg1 |= tmpreg2 << 13;
  /* 保存新的寄存器值 */
  ADCx->CR1 = tmpreg1;
}

/**
  * @brief  为指定的 ADC 使能或失能规则组通道的间断模式
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  NewState：选定 ADC 规则组通道间断模式的新状态。
  *         该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_DiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 ADC 规则组间断模式 */
    ADCx->CR1 |= CR1_DISCEN_Set;
  }
  else
  {
    /* 失能选定的 ADC 规则组间断模式 */
    ADCx->CR1 &= CR1_DISCEN_Reset;
  }
}

/**
  * @brief  为选定的 ADC 规则通道配置其在序列器中的相应
  *         次序以及采样时间。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_Channel：要配置的 ADC 通道。
  *   该参数可以是以下值之一：
  *     @arg ADC_Channel_0：选择 ADC 通道 0
  *     @arg ADC_Channel_1：选择 ADC 通道 1
  *     @arg ADC_Channel_2：选择 ADC 通道 2
  *     @arg ADC_Channel_3：选择 ADC 通道 3
  *     @arg ADC_Channel_4：选择 ADC 通道 4
  *     @arg ADC_Channel_5：选择 ADC 通道 5
  *     @arg ADC_Channel_6：选择 ADC 通道 6
  *     @arg ADC_Channel_7：选择 ADC 通道 7
  *     @arg ADC_Channel_8：选择 ADC 通道 8
  *     @arg ADC_Channel_9：选择 ADC 通道 9
  *     @arg ADC_Channel_10：选择 ADC 通道 10
  *     @arg ADC_Channel_11：选择 ADC 通道 11
  *     @arg ADC_Channel_12：选择 ADC 通道 12
  *     @arg ADC_Channel_13：选择 ADC 通道 13
  *     @arg ADC_Channel_14：选择 ADC 通道 14
  *     @arg ADC_Channel_15：选择 ADC 通道 15
  *     @arg ADC_Channel_16：选择 ADC 通道 16
  *     @arg ADC_Channel_17：选择 ADC 通道 17
  * @param  Rank：规则组序列器中的次序。该参数必须在 1 到 16 之间。
  * @param  ADC_SampleTime：为选定通道设置的采样时间值。
  *   该参数可以是以下值之一：
  *     @arg ADC_SampleTime_1Cycles5：采样时间等于 1.5 个周期
  *     @arg ADC_SampleTime_7Cycles5：采样时间等于 7.5 个周期
  *     @arg ADC_SampleTime_13Cycles5：采样时间等于 13.5 个周期
  *     @arg ADC_SampleTime_28Cycles5：采样时间等于 28.5 个周期	
  *     @arg ADC_SampleTime_41Cycles5：采样时间等于 41.5 个周期	
  *     @arg ADC_SampleTime_55Cycles5：采样时间等于 55.5 个周期	
  *     @arg ADC_SampleTime_71Cycles5：采样时间等于 71.5 个周期	
  *     @arg ADC_SampleTime_239Cycles5：采样时间等于 239.5 个周期	
  * @retval 无
  */
void ADC_RegularChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime)
{
  uint32_t tmpreg1 = 0, tmpreg2 = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_CHANNEL(ADC_Channel));
  assert_param(IS_ADC_REGULAR_RANK(Rank));
  assert_param(IS_ADC_SAMPLE_TIME(ADC_SampleTime));
  /* 如果选择的是 ADC_Channel_10 ... ADC_Channel_17 */
  if (ADC_Channel > ADC_Channel_9)
  {
    /* 读取原寄存器值 */
    tmpreg1 = ADCx->SMPR1;
    /* 计算要清除的掩码 */
    tmpreg2 = SMPR1_SMP_Set << (3 * (ADC_Channel - 10));
    /* 清除原有的通道采样时间 */
    tmpreg1 &= ~tmpreg2;
    /* 计算要设置的掩码 */
    tmpreg2 = (uint32_t)ADC_SampleTime << (3 * (ADC_Channel - 10));
    /* 设置新的通道采样时间 */
    tmpreg1 |= tmpreg2;
    /* 保存新的寄存器值 */
    ADCx->SMPR1 = tmpreg1;
  }
  else /* ADC_Channel 属于 ADC_Channel_[0..9] */
  {
    /* 读取原寄存器值 */
    tmpreg1 = ADCx->SMPR2;
    /* 计算要清除的掩码 */
    tmpreg2 = SMPR2_SMP_Set << (3 * ADC_Channel);
    /* 清除原有的通道采样时间 */
    tmpreg1 &= ~tmpreg2;
    /* 计算要设置的掩码 */
    tmpreg2 = (uint32_t)ADC_SampleTime << (3 * ADC_Channel);
    /* 设置新的通道采样时间 */
    tmpreg1 |= tmpreg2;
    /* 保存新的寄存器值 */
    ADCx->SMPR2 = tmpreg1;
  }
  /* 次序 1 到 6 */
  if (Rank < 7)
  {
    /* 读取原寄存器值 */
    tmpreg1 = ADCx->SQR3;
    /* 计算要清除的掩码 */
    tmpreg2 = SQR3_SQ_Set << (5 * (Rank - 1));
    /* 清除选定次序原有的 SQx 位 */
    tmpreg1 &= ~tmpreg2;
    /* 计算要设置的掩码 */
    tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 1));
    /* 设置选定次序的 SQx 位 */
    tmpreg1 |= tmpreg2;
    /* 保存新的寄存器值 */
    ADCx->SQR3 = tmpreg1;
  }
  /* 次序 7 到 12 */
  else if (Rank < 13)
  {
    /* 读取原寄存器值 */
    tmpreg1 = ADCx->SQR2;
    /* 计算要清除的掩码 */
    tmpreg2 = SQR2_SQ_Set << (5 * (Rank - 7));
    /* 清除选定次序原有的 SQx 位 */
    tmpreg1 &= ~tmpreg2;
    /* 计算要设置的掩码 */
    tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 7));
    /* 设置选定次序的 SQx 位 */
    tmpreg1 |= tmpreg2;
    /* 保存新的寄存器值 */
    ADCx->SQR2 = tmpreg1;
  }
  /* 次序 13 到 16 */
  else
  {
    /* 读取原寄存器值 */
    tmpreg1 = ADCx->SQR1;
    /* 计算要清除的掩码 */
    tmpreg2 = SQR1_SQ_Set << (5 * (Rank - 13));
    /* 清除选定次序原有的 SQx 位 */
    tmpreg1 &= ~tmpreg2;
    /* 计算要设置的掩码 */
    tmpreg2 = (uint32_t)ADC_Channel << (5 * (Rank - 13));
    /* 设置选定次序的 SQx 位 */
    tmpreg1 |= tmpreg2;
    /* 保存新的寄存器值 */
    ADCx->SQR1 = tmpreg1;
  }
}

/**
  * @brief  使能或失能 ADCx 通过外部触发进行转换。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  NewState：选定 ADC 外部触发启动转换的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_ExternalTrigConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定 ADC 在外部事件上转换 */
    ADCx->CR2 |= CR2_EXTTRIG_Set;
  }
  else
  {
    /* 失能选定 ADC 在外部事件上转换 */
    ADCx->CR2 &= CR2_EXTTRIG_Reset;
  }
}

/**
  * @brief  返回规则通道最后一次 ADCx 转换结果数据。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @retval 数据转换值。
  */
uint16_t ADC_GetConversionValue(ADC_TypeDef* ADCx)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  /* 返回选定 ADC 的转换值 */
  return (uint16_t) ADCx->DR;
}

/**
  * @brief  返回双重模式下 ADC1 和 ADC2 最后一次转换结果数据。
  * @retval 数据转换值。
  */
uint32_t ADC_GetDualModeConversionValue(void)
{
  /* 返回双重模式转换值 */
  return (*(__IO uint32_t *) DR_ADDRESS);
}

/**
  * @brief  使能或失能选定的 ADC 在规则组转换之后
  *         自动进行注入组转换。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  NewState：选定 ADC 自动注入转换的新状态
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_AutoInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 ADC 自动注入组转换 */
    ADCx->CR1 |= CR1_JAUTO_Set;
  }
  else
  {
    /* 失能选定的 ADC 自动注入组转换 */
    ADCx->CR1 &= CR1_JAUTO_Reset;
  }
}

/**
  * @brief  为使能的 ADC 使能或失能注入组通道的间断模式
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  NewState：选定 ADC 注入组通道间断模式的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_InjectedDiscModeCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 ADC 注入组间断模式 */
    ADCx->CR1 |= CR1_JDISCEN_Set;
  }
  else
  {
    /* 失能选定的 ADC 注入组间断模式 */
    ADCx->CR1 &= CR1_JDISCEN_Reset;
  }
}

/**
  * @brief  配置 ADCx 注入通道转换的外部触发。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_ExternalTrigInjecConv：指定启动注入转换的 ADC 触发。
  *   该参数可以是以下值之一：
  *     @arg ADC_ExternalTrigInjecConv_T1_TRGO：选择定时器 1 的 TRGO 事件（用于 ADC1、ADC2 和 ADC3）
  *     @arg ADC_ExternalTrigInjecConv_T1_CC4：选择定时器 1 的捕获比较 4（用于 ADC1、ADC2 和 ADC3）
  *     @arg ADC_ExternalTrigInjecConv_T2_TRGO：选择定时器 2 的 TRGO 事件（用于 ADC1 和 ADC2）
  *     @arg ADC_ExternalTrigInjecConv_T2_CC1：选择定时器 2 的捕获比较 1（用于 ADC1 和 ADC2）
  *     @arg ADC_ExternalTrigInjecConv_T3_CC4：选择定时器 3 的捕获比较 4（用于 ADC1 和 ADC2）
  *     @arg ADC_ExternalTrigInjecConv_T4_TRGO：选择定时器 4 的 TRGO 事件（用于 ADC1 和 ADC2）
  *     @arg ADC_ExternalTrigInjecConv_Ext_IT15_TIM8_CC4：选择外部中断线 15 或定时器 8
  *                                                       的捕获比较 4 事件（用于 ADC1 和 ADC2）                       
  *     @arg ADC_ExternalTrigInjecConv_T4_CC3：选择定时器 4 的捕获比较 3（仅用于 ADC3）
  *     @arg ADC_ExternalTrigInjecConv_T8_CC2：选择定时器 8 的捕获比较 2（仅用于 ADC3）                         
  *     @arg ADC_ExternalTrigInjecConv_T8_CC4：选择定时器 8 的捕获比较 4（仅用于 ADC3）
  *     @arg ADC_ExternalTrigInjecConv_T5_TRGO：选择定时器 5 的 TRGO 事件（仅用于 ADC3）                         
  *     @arg ADC_ExternalTrigInjecConv_T5_CC4：选择定时器 5 的捕获比较 4（仅用于 ADC3）                        
  *     @arg ADC_ExternalTrigInjecConv_None：注入转换由软件启动而非
  *                                          外部触发（用于 ADC1、ADC2 和 ADC3）
  * @retval 无
  */
void ADC_ExternalTrigInjectedConvConfig(ADC_TypeDef* ADCx, uint32_t ADC_ExternalTrigInjecConv)
{
  uint32_t tmpreg = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_EXT_INJEC_TRIG(ADC_ExternalTrigInjecConv));
  /* 读取原寄存器值 */
  tmpreg = ADCx->CR2;
  /* 清除注入组原有的外部事件选择 */
  tmpreg &= CR2_JEXTSEL_Reset;
  /* 设置注入组的外部事件选择 */
  tmpreg |= ADC_ExternalTrigInjecConv;
  /* 保存新的寄存器值 */
  ADCx->CR2 = tmpreg;
}

/**
  * @brief  使能或失能 ADCx 注入通道通过外部触发
  *         进行转换
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  NewState：选定 ADC 外部触发启动注入转换的
  *         新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_ExternalTrigInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 ADC 注入组外部事件选择 */
    ADCx->CR2 |= CR2_JEXTTRIG_Set;
  }
  else
  {
    /* 失能选定的 ADC 注入组外部事件选择 */
    ADCx->CR2 &= CR2_JEXTTRIG_Reset;
  }
}

/**
  * @brief  使能或失能选定的 ADC 启动注入
  *         通道转换。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  NewState：选定 ADC 软件启动注入转换的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_SoftwareStartInjectedConvCmd(ADC_TypeDef* ADCx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定 ADC 注入组在外部事件上转换，并启动选定的 ADC 注入转换 */
    ADCx->CR2 |= CR2_JEXTTRIG_JSWSTART_Set;
  }
  else
  {
    /* 失能选定 ADC 注入组在外部事件上转换，并停止选定的 ADC 注入转换 */
    ADCx->CR2 &= CR2_JEXTTRIG_JSWSTART_Reset;
  }
}

/**
  * @brief  获取选定的 ADC 软件启动注入转换状态。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @retval ADC 软件启动注入转换的新状态（SET 或 RESET）。
  */
FlagStatus ADC_GetSoftwareStartInjectedConvCmdStatus(ADC_TypeDef* ADCx)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  /* 检查 JSWSTART 位的状态 */
  if ((ADCx->CR2 & CR2_JSWSTART_Set) != (uint32_t)RESET)
  {
    /* JSWSTART 位已置位 */
    bitstatus = SET;
  }
  else
  {
    /* JSWSTART 位已复位 */
    bitstatus = RESET;
  }
  /* 返回 JSWSTART 位的状态 */
  return  bitstatus;
}

/**
  * @brief  为选定的 ADC 注入通道配置其在序列器中的相应
  *         次序以及采样时间。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_Channel：要配置的 ADC 通道。
  *   该参数可以是以下值之一：
  *     @arg ADC_Channel_0：选择 ADC 通道 0
  *     @arg ADC_Channel_1：选择 ADC 通道 1
  *     @arg ADC_Channel_2：选择 ADC 通道 2
  *     @arg ADC_Channel_3：选择 ADC 通道 3
  *     @arg ADC_Channel_4：选择 ADC 通道 4
  *     @arg ADC_Channel_5：选择 ADC 通道 5
  *     @arg ADC_Channel_6：选择 ADC 通道 6
  *     @arg ADC_Channel_7：选择 ADC 通道 7
  *     @arg ADC_Channel_8：选择 ADC 通道 8
  *     @arg ADC_Channel_9：选择 ADC 通道 9
  *     @arg ADC_Channel_10：选择 ADC 通道 10
  *     @arg ADC_Channel_11：选择 ADC 通道 11
  *     @arg ADC_Channel_12：选择 ADC 通道 12
  *     @arg ADC_Channel_13：选择 ADC 通道 13
  *     @arg ADC_Channel_14：选择 ADC 通道 14
  *     @arg ADC_Channel_15：选择 ADC 通道 15
  *     @arg ADC_Channel_16：选择 ADC 通道 16
  *     @arg ADC_Channel_17：选择 ADC 通道 17
  * @param  Rank：注入组序列器中的次序。该参数必须在 1 到 4 之间。
  * @param  ADC_SampleTime：为选定通道设置的采样时间值。
  *   该参数可以是以下值之一：
  *     @arg ADC_SampleTime_1Cycles5：采样时间等于 1.5 个周期
  *     @arg ADC_SampleTime_7Cycles5：采样时间等于 7.5 个周期
  *     @arg ADC_SampleTime_13Cycles5：采样时间等于 13.5 个周期
  *     @arg ADC_SampleTime_28Cycles5：采样时间等于 28.5 个周期	
  *     @arg ADC_SampleTime_41Cycles5：采样时间等于 41.5 个周期	
  *     @arg ADC_SampleTime_55Cycles5：采样时间等于 55.5 个周期	
  *     @arg ADC_SampleTime_71Cycles5：采样时间等于 71.5 个周期	
  *     @arg ADC_SampleTime_239Cycles5：采样时间等于 239.5 个周期	
  * @retval 无
  */
void ADC_InjectedChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel, uint8_t Rank, uint8_t ADC_SampleTime)
{
  uint32_t tmpreg1 = 0, tmpreg2 = 0, tmpreg3 = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_CHANNEL(ADC_Channel));
  assert_param(IS_ADC_INJECTED_RANK(Rank));
  assert_param(IS_ADC_SAMPLE_TIME(ADC_SampleTime));
  /* 如果选择的是 ADC_Channel_10 ... ADC_Channel_17 */
  if (ADC_Channel > ADC_Channel_9)
  {
    /* 读取原寄存器值 */
    tmpreg1 = ADCx->SMPR1;
    /* 计算要清除的掩码 */
    tmpreg2 = SMPR1_SMP_Set << (3*(ADC_Channel - 10));
    /* 清除原有的通道采样时间 */
    tmpreg1 &= ~tmpreg2;
    /* 计算要设置的掩码 */
    tmpreg2 = (uint32_t)ADC_SampleTime << (3*(ADC_Channel - 10));
    /* 设置新的通道采样时间 */
    tmpreg1 |= tmpreg2;
    /* 保存新的寄存器值 */
    ADCx->SMPR1 = tmpreg1;
  }
  else /* ADC_Channel 属于 ADC_Channel_[0..9] */
  {
    /* 读取原寄存器值 */
    tmpreg1 = ADCx->SMPR2;
    /* 计算要清除的掩码 */
    tmpreg2 = SMPR2_SMP_Set << (3 * ADC_Channel);
    /* 清除原有的通道采样时间 */
    tmpreg1 &= ~tmpreg2;
    /* 计算要设置的掩码 */
    tmpreg2 = (uint32_t)ADC_SampleTime << (3 * ADC_Channel);
    /* 设置新的通道采样时间 */
    tmpreg1 |= tmpreg2;
    /* 保存新的寄存器值 */
    ADCx->SMPR2 = tmpreg1;
  }
  /* 次序配置 */
  /* 读取原寄存器值 */
  tmpreg1 = ADCx->JSQR;
  /* 读取 JL 值：Number = JL+1 */
  tmpreg3 =  (tmpreg1 & JSQR_JL_Set)>> 20;
  /* 计算要清除的掩码：((Rank-1)+(4-JL-1)) */
  tmpreg2 = JSQR_JSQ_Set << (5 * (uint8_t)((Rank + 3) - (tmpreg3 + 1)));
  /* 清除选定次序原有的 JSQx 位 */
  tmpreg1 &= ~tmpreg2;
  /* 计算要设置的掩码：((Rank-1)+(4-JL-1)) */
  tmpreg2 = (uint32_t)ADC_Channel << (5 * (uint8_t)((Rank + 3) - (tmpreg3 + 1)));
  /* 设置选定次序的 JSQx 位 */
  tmpreg1 |= tmpreg2;
  /* 保存新的寄存器值 */
  ADCx->JSQR = tmpreg1;
}

/**
  * @brief  配置注入通道的序列器长度
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  Length：序列器长度。
  *   该参数必须是 1 到 4 之间的数值。
  * @retval 无
  */
void ADC_InjectedSequencerLengthConfig(ADC_TypeDef* ADCx, uint8_t Length)
{
  uint32_t tmpreg1 = 0;
  uint32_t tmpreg2 = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_INJECTED_LENGTH(Length));
  
  /* 读取原寄存器值 */
  tmpreg1 = ADCx->JSQR;
  /* 清除原有的注入序列长度 JL 位 */
  tmpreg1 &= JSQR_JL_Reset;
  /* 设置注入序列长度 JL 位 */
  tmpreg2 = Length - 1; 
  tmpreg1 |= tmpreg2 << 20;
  /* 保存新的寄存器值 */
  ADCx->JSQR = tmpreg1;
}

/**
  * @brief  设置注入通道转换值的偏移
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_InjectedChannel：要设置偏移的 ADC 注入通道。
  *   该参数可以是以下值之一：
  *     @arg ADC_InjectedChannel_1：选择注入通道 1
  *     @arg ADC_InjectedChannel_2：选择注入通道 2
  *     @arg ADC_InjectedChannel_3：选择注入通道 3
  *     @arg ADC_InjectedChannel_4：选择注入通道 4
  * @param  Offset：选定 ADC 注入通道的偏移值
  *   该参数必须是 12 位的数值。
  * @retval 无
  */
void ADC_SetInjectedOffset(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel, uint16_t Offset)
{
  __IO uint32_t tmp = 0;
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_INJECTED_CHANNEL(ADC_InjectedChannel));
  assert_param(IS_ADC_OFFSET(Offset));  
  
  tmp = (uint32_t)ADCx;
  tmp += ADC_InjectedChannel;
  
  /* 设置选定注入通道的数据偏移 */
  *(__IO uint32_t *) tmp = (uint32_t)Offset;
}

/**
  * @brief  返回 ADC 注入通道转换结果
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_InjectedChannel：已转换的 ADC 注入通道。
  *   该参数可以是以下值之一：
  *     @arg ADC_InjectedChannel_1：选择注入通道 1
  *     @arg ADC_InjectedChannel_2：选择注入通道 2
  *     @arg ADC_InjectedChannel_3：选择注入通道 3
  *     @arg ADC_InjectedChannel_4：选择注入通道 4
  * @retval 数据转换值。
  */
uint16_t ADC_GetInjectedConversionValue(ADC_TypeDef* ADCx, uint8_t ADC_InjectedChannel)
{
  __IO uint32_t tmp = 0;
  
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_INJECTED_CHANNEL(ADC_InjectedChannel));

  tmp = (uint32_t)ADCx;
  tmp += ADC_InjectedChannel + JDR_Offset;
  
  /* 返回选定注入通道的转换数据值 */
  return (uint16_t) (*(__IO uint32_t*)  tmp);   
}

/**
  * @brief  使能或失能单个/全部规则通道
  *         或注入通道上的模拟看门狗
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_AnalogWatchdog：ADC 模拟看门狗配置。
  *   该参数可以是以下值之一：
  *     @arg ADC_AnalogWatchdog_SingleRegEnable：模拟看门狗监视单个规则通道
  *     @arg ADC_AnalogWatchdog_SingleInjecEnable：模拟看门狗监视单个注入通道
  *     @arg ADC_AnalogWatchdog_SingleRegOrInjecEnable：模拟看门狗监视单个规则或注入通道
  *     @arg ADC_AnalogWatchdog_AllRegEnable：模拟看门狗监视所有规则通道
  *     @arg ADC_AnalogWatchdog_AllInjecEnable：模拟看门狗监视所有注入通道
  *     @arg ADC_AnalogWatchdog_AllRegAllInjecEnable：模拟看门狗监视所有规则和注入通道
  *     @arg ADC_AnalogWatchdog_None：没有通道受模拟看门狗监视
  * @retval 无	  
  */
void ADC_AnalogWatchdogCmd(ADC_TypeDef* ADCx, uint32_t ADC_AnalogWatchdog)
{
  uint32_t tmpreg = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_ANALOG_WATCHDOG(ADC_AnalogWatchdog));
  /* 读取原寄存器值 */
  tmpreg = ADCx->CR1;
  /* 清除 AWDEN、AWDENJ 和 AWDSGL 位 */
  tmpreg &= CR1_AWDMode_Reset;
  /* 设置模拟看门狗使能模式 */
  tmpreg |= ADC_AnalogWatchdog;
  /* 保存新的寄存器值 */
  ADCx->CR1 = tmpreg;
}

/**
  * @brief  配置模拟看门狗的高、低阈值。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  HighThreshold：ADC 模拟看门狗高阈值。
  *   该参数必须是 12 位的数值。
  * @param  LowThreshold：ADC 模拟看门狗低阈值。
  *   该参数必须是 12 位的数值。
  * @retval 无
  */
void ADC_AnalogWatchdogThresholdsConfig(ADC_TypeDef* ADCx, uint16_t HighThreshold,
                                        uint16_t LowThreshold)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_THRESHOLD(HighThreshold));
  assert_param(IS_ADC_THRESHOLD(LowThreshold));
  /* 设置 ADCx 高阈值 */
  ADCx->HTR = HighThreshold;
  /* 设置 ADCx 低阈值 */
  ADCx->LTR = LowThreshold;
}

/**
  * @brief  配置模拟看门狗监视的单个通道
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_Channel：要为模拟看门狗配置的 ADC 通道。
  *   该参数可以是以下值之一：
  *     @arg ADC_Channel_0：选择 ADC 通道 0
  *     @arg ADC_Channel_1：选择 ADC 通道 1
  *     @arg ADC_Channel_2：选择 ADC 通道 2
  *     @arg ADC_Channel_3：选择 ADC 通道 3
  *     @arg ADC_Channel_4：选择 ADC 通道 4
  *     @arg ADC_Channel_5：选择 ADC 通道 5
  *     @arg ADC_Channel_6：选择 ADC 通道 6
  *     @arg ADC_Channel_7：选择 ADC 通道 7
  *     @arg ADC_Channel_8：选择 ADC 通道 8
  *     @arg ADC_Channel_9：选择 ADC 通道 9
  *     @arg ADC_Channel_10：选择 ADC 通道 10
  *     @arg ADC_Channel_11：选择 ADC 通道 11
  *     @arg ADC_Channel_12：选择 ADC 通道 12
  *     @arg ADC_Channel_13：选择 ADC 通道 13
  *     @arg ADC_Channel_14：选择 ADC 通道 14
  *     @arg ADC_Channel_15：选择 ADC 通道 15
  *     @arg ADC_Channel_16：选择 ADC 通道 16
  *     @arg ADC_Channel_17：选择 ADC 通道 17
  * @retval 无
  */
void ADC_AnalogWatchdogSingleChannelConfig(ADC_TypeDef* ADCx, uint8_t ADC_Channel)
{
  uint32_t tmpreg = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_CHANNEL(ADC_Channel));
  /* 读取原寄存器值 */
  tmpreg = ADCx->CR1;
  /* 清除模拟看门狗通道选择位 */
  tmpreg &= CR1_AWDCH_Reset;
  /* 设置模拟看门狗通道 */
  tmpreg |= ADC_Channel;
  /* 保存新的寄存器值 */
  ADCx->CR1 = tmpreg;
}

/**
  * @brief  使能或失能温度传感器和 Vrefint 通道。
  * @param  NewState：温度传感器的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void ADC_TempSensorVrefintCmd(FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能温度传感器和 Vrefint 通道 */
    ADC1->CR2 |= CR2_TSVREFE_Set;
  }
  else
  {
    /* 失能温度传感器和 Vrefint 通道 */
    ADC1->CR2 &= CR2_TSVREFE_Reset;
  }
}

/**
  * @brief  检查指定的 ADC 标志位置位与否。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_FLAG：指定要检查的标志位。
  *   该参数可以是以下值之一：
  *     @arg ADC_FLAG_AWD：模拟看门狗标志位
  *     @arg ADC_FLAG_EOC：转换结束标志位
  *     @arg ADC_FLAG_JEOC：注入组转换结束标志位
  *     @arg ADC_FLAG_JSTRT：注入组转换开始标志位
  *     @arg ADC_FLAG_STRT：规则组转换开始标志位
  * @retval ADC_FLAG 的新状态（SET 或 RESET）。
  */
FlagStatus ADC_GetFlagStatus(ADC_TypeDef* ADCx, uint8_t ADC_FLAG)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_GET_FLAG(ADC_FLAG));
  /* 检查指定 ADC 标志位的状态 */
  if ((ADCx->SR & ADC_FLAG) != (uint8_t)RESET)
  {
    /* ADC_FLAG 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* ADC_FLAG 已复位 */
    bitstatus = RESET;
  }
  /* 返回 ADC_FLAG 的状态 */
  return  bitstatus;
}

/**
  * @brief  清除 ADCx 的挂起标志位。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_FLAG：指定要清除的标志位。
  *   该参数可以是以下值的任意组合：
  *     @arg ADC_FLAG_AWD：模拟看门狗标志位
  *     @arg ADC_FLAG_EOC：转换结束标志位
  *     @arg ADC_FLAG_JEOC：注入组转换结束标志位
  *     @arg ADC_FLAG_JSTRT：注入组转换开始标志位
  *     @arg ADC_FLAG_STRT：规则组转换开始标志位
  * @retval 无
  */
void ADC_ClearFlag(ADC_TypeDef* ADCx, uint8_t ADC_FLAG)
{
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_CLEAR_FLAG(ADC_FLAG));
  /* 清除选定的 ADC 标志位 */
  ADCx->SR = ~(uint32_t)ADC_FLAG;
}

/**
  * @brief  检查指定的 ADC 中断是否发生。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_IT：指定要检查的 ADC 中断源。
  *   该参数可以是以下值之一：
  *     @arg ADC_IT_EOC：转换结束中断掩码
  *     @arg ADC_IT_AWD：模拟看门狗中断掩码
  *     @arg ADC_IT_JEOC：注入转换结束中断掩码
  * @retval ADC_IT 的新状态（SET 或 RESET）。
  */
ITStatus ADC_GetITStatus(ADC_TypeDef* ADCx, uint16_t ADC_IT)
{
  ITStatus bitstatus = RESET;
  uint32_t itmask = 0, enablestatus = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_GET_IT(ADC_IT));
  /* 获取 ADC 中断索引 */
  itmask = ADC_IT >> 8;
  /* 获取 ADC_IT 使能位的状态 */
  enablestatus = (ADCx->CR1 & (uint8_t)ADC_IT) ;
  /* 检查指定 ADC 中断的状态 */
  if (((ADCx->SR & itmask) != (uint32_t)RESET) && enablestatus)
  {
    /* ADC_IT 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* ADC_IT 已复位 */
    bitstatus = RESET;
  }
  /* 返回 ADC_IT 的状态 */
  return  bitstatus;
}

/**
  * @brief  清除 ADCx 的中断挂起位。
  * @param  ADCx：x 可以是 1、2 或 3，用于选择 ADC 外设。
  * @param  ADC_IT：指定要清除的 ADC 中断挂起位。
  *   该参数可以是以下值的任意组合：
  *     @arg ADC_IT_EOC：转换结束中断掩码
  *     @arg ADC_IT_AWD：模拟看门狗中断掩码
  *     @arg ADC_IT_JEOC：注入转换结束中断掩码
  * @retval 无
  */
void ADC_ClearITPendingBit(ADC_TypeDef* ADCx, uint16_t ADC_IT)
{
  uint8_t itmask = 0;
  /* 检查参数 */
  assert_param(IS_ADC_ALL_PERIPH(ADCx));
  assert_param(IS_ADC_IT(ADC_IT));
  /* 获取 ADC 中断索引 */
  itmask = (uint8_t)(ADC_IT >> 8);
  /* 清除选定的 ADC 中断挂起位 */
  ADCx->SR = ~(uint32_t)itmask;
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
