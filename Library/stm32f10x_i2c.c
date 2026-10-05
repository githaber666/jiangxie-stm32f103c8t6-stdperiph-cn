/**
  ******************************************************************************
  * @file    stm32f10x_i2c.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供所有 I2C 固件函数。
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

/* 包含文件 ---------------------------------------------------------------*/
#include "stm32f10x_i2c.h"
#include "stm32f10x_rcc.h"


/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup I2C 
  * @brief I2C 驱动模块
  * @{
  */ 

/** @defgroup I2C_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_Defines
  * @{
  */

/* I2C SPE 掩码 */
#define CR1_PE_Set              ((uint16_t)0x0001)
#define CR1_PE_Reset            ((uint16_t)0xFFFE)

/* I2C START 掩码 */
#define CR1_START_Set           ((uint16_t)0x0100)
#define CR1_START_Reset         ((uint16_t)0xFEFF)

/* I2C STOP 掩码 */
#define CR1_STOP_Set            ((uint16_t)0x0200)
#define CR1_STOP_Reset          ((uint16_t)0xFDFF)

/* I2C ACK 掩码 */
#define CR1_ACK_Set             ((uint16_t)0x0400)
#define CR1_ACK_Reset           ((uint16_t)0xFBFF)

/* I2C ENGC 掩码 */
#define CR1_ENGC_Set            ((uint16_t)0x0040)
#define CR1_ENGC_Reset          ((uint16_t)0xFFBF)

/* I2C SWRST 掩码 */
#define CR1_SWRST_Set           ((uint16_t)0x8000)
#define CR1_SWRST_Reset         ((uint16_t)0x7FFF)

/* I2C PEC 掩码 */
#define CR1_PEC_Set             ((uint16_t)0x1000)
#define CR1_PEC_Reset           ((uint16_t)0xEFFF)

/* I2C ENPEC 掩码 */
#define CR1_ENPEC_Set           ((uint16_t)0x0020)
#define CR1_ENPEC_Reset         ((uint16_t)0xFFDF)

/* I2C ENARP 掩码 */
#define CR1_ENARP_Set           ((uint16_t)0x0010)
#define CR1_ENARP_Reset         ((uint16_t)0xFFEF)

/* I2C NOSTRETCH 掩码 */
#define CR1_NOSTRETCH_Set       ((uint16_t)0x0080)
#define CR1_NOSTRETCH_Reset     ((uint16_t)0xFF7F)

/* I2C 寄存器掩码 */
#define CR1_CLEAR_Mask          ((uint16_t)0xFBF5)

/* I2C DMAEN 掩码 */
#define CR2_DMAEN_Set           ((uint16_t)0x0800)
#define CR2_DMAEN_Reset         ((uint16_t)0xF7FF)

/* I2C LAST 掩码 */
#define CR2_LAST_Set            ((uint16_t)0x1000)
#define CR2_LAST_Reset          ((uint16_t)0xEFFF)

/* I2C FREQ 掩码 */
#define CR2_FREQ_Reset          ((uint16_t)0xFFC0)

/* I2C ADD0 掩码 */
#define OAR1_ADD0_Set           ((uint16_t)0x0001)
#define OAR1_ADD0_Reset         ((uint16_t)0xFFFE)

/* I2C ENDUAL 掩码 */
#define OAR2_ENDUAL_Set         ((uint16_t)0x0001)
#define OAR2_ENDUAL_Reset       ((uint16_t)0xFFFE)

/* I2C ADD2 掩码 */
#define OAR2_ADD2_Reset         ((uint16_t)0xFF01)

/* I2C F/S 掩码 */
#define CCR_FS_Set              ((uint16_t)0x8000)

/* I2C CCR 掩码 */
#define CCR_CCR_Set             ((uint16_t)0x0FFF)

/* I2C FLAG 掩码 */
#define FLAG_Mask               ((uint32_t)0x00FFFFFF)

/* I2C 中断使能掩码 */
#define ITEN_Mask               ((uint32_t)0x07000000)

/**
  * @}
  */

/** @defgroup I2C_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup I2C_Private_Functions
  * @{
  */

/**
  * @brief  将 I2Cx 外设寄存器复位为默认值。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @retval 无
  */
void I2C_DeInit(I2C_TypeDef* I2Cx)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));

  if (I2Cx == I2C1)
  {
    /* 使 I2C1 进入复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, ENABLE);
    /* 释放 I2C1 复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C1, DISABLE);
  }
  else
  {
    /* 使 I2C2 进入复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, ENABLE);
    /* 释放 I2C2 复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2C2, DISABLE);
  }
}

/**
  * @brief  根据指定参数初始化 I2Cx 外设，参数由 
  *   I2C_InitStruct 指定。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_InitStruct: 指向 I2C_InitTypeDef 结构的指针，该结构
  *   包含指定 I2C 外设的配置信息。
  * @retval 无
  */
void I2C_Init(I2C_TypeDef* I2Cx, I2C_InitTypeDef* I2C_InitStruct)
{
  uint16_t tmpreg = 0, freqrange = 0;
  uint16_t result = 0x04;
  uint32_t pclk1 = 8000000;
  RCC_ClocksTypeDef  rcc_clocks;
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_CLOCK_SPEED(I2C_InitStruct->I2C_ClockSpeed));
  assert_param(IS_I2C_MODE(I2C_InitStruct->I2C_Mode));
  assert_param(IS_I2C_DUTY_CYCLE(I2C_InitStruct->I2C_DutyCycle));
  assert_param(IS_I2C_OWN_ADDRESS1(I2C_InitStruct->I2C_OwnAddress1));
  assert_param(IS_I2C_ACK_STATE(I2C_InitStruct->I2C_Ack));
  assert_param(IS_I2C_ACKNOWLEDGE_ADDRESS(I2C_InitStruct->I2C_AcknowledgedAddress));

/*---------------------------- I2Cx CR2 配置 ------------------------*/
  /* 读取 I2Cx CR2 的值 */
  tmpreg = I2Cx->CR2;
  /* 清除频率 FREQ[5:0] 位 */
  tmpreg &= CR2_FREQ_Reset;
  /* 获取 pclk1 频率值 */
  RCC_GetClocksFreq(&rcc_clocks);
  pclk1 = rcc_clocks.PCLK1_Frequency;
  /* 根据 pclk1 的值设置频率位 */
  freqrange = (uint16_t)(pclk1 / 1000000);
  tmpreg |= freqrange;
  /* 写入 I2Cx CR2 */
  I2Cx->CR2 = tmpreg;

/*---------------------------- I2Cx CCR 配置 ------------------------*/
  /* 失能所选 I2C 外设以配置 TRISE */
  I2Cx->CR1 &= CR1_PE_Reset;
  /* 复位 tmpreg 的值 */
  /* 清除 F/S、DUTY 和 CCR[11:0] 位 */
  tmpreg = 0;

  /* 配置标准模式下的速度 */
  if (I2C_InitStruct->I2C_ClockSpeed <= 100000)
  {
    /* 计算标准模式的速度 */
    result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed << 1));
    /* 判断 CCR 的值是否小于 0x4*/
    if (result < 0x04)
    {
      /* 设置允许的最小值 */
      result = 0x04;  
    }
    /* 设置标准模式的速度值 */
    tmpreg |= result;	  
    /* 设置标准模式的最大上升时间 */
    I2Cx->TRISE = freqrange + 1; 
  }
  /* 配置快速模式下的速度 */
  else /*(I2C_InitStruct->I2C_ClockSpeed <= 400000)*/
  {
    if (I2C_InitStruct->I2C_DutyCycle == I2C_DutyCycle_2)
    {
      /* 计算快速模式速度：Tlow/Thigh = 2 */
      result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed * 3));
    }
    else /*I2C_InitStruct->I2C_DutyCycle == I2C_DutyCycle_16_9*/
    {
      /* 计算快速模式速度：Tlow/Thigh = 16/9 */
      result = (uint16_t)(pclk1 / (I2C_InitStruct->I2C_ClockSpeed * 25));
      /* 设置 DUTY 位 */
      result |= I2C_DutyCycle_16_9;
    }

    /* 判断 CCR 的值是否小于 0x1*/
    if ((result & CCR_CCR_Set) == 0)
    {
      /* 设置允许的最小值 */
      result |= (uint16_t)0x0001;  
    }
    /* 设置速度值并置位 F/S 位以进入快速模式 */
    tmpreg |= (uint16_t)(result | CCR_FS_Set);
    /* 设置快速模式的最大上升时间 */
    I2Cx->TRISE = (uint16_t)(((freqrange * (uint16_t)300) / (uint16_t)1000) + (uint16_t)1);  
  }

  /* 写入 I2Cx CCR */
  I2Cx->CCR = tmpreg;
  /* 使能所选 I2C 外设 */
  I2Cx->CR1 |= CR1_PE_Set;

/*---------------------------- I2Cx CR1 配置 ------------------------*/
  /* 读取 I2Cx CR1 的值 */
  tmpreg = I2Cx->CR1;
  /* 清除 ACK、SMBTYPE 和 SMBUS 位 */
  tmpreg &= CR1_CLEAR_Mask;
  /* 配置 I2Cx：模式和应答 */
  /* 根据 I2C_Mode 的值设置 SMBTYPE 和 SMBUS 位 */
  /* 根据 I2C_Ack 的值设置 ACK 位 */
  tmpreg |= (uint16_t)((uint32_t)I2C_InitStruct->I2C_Mode | I2C_InitStruct->I2C_Ack);
  /* 写入 I2Cx CR1 */
  I2Cx->CR1 = tmpreg;

/*---------------------------- I2Cx OAR1 配置 -----------------------*/
  /* 设置 I2Cx 自身地址 1 和被应答的地址 */
  I2Cx->OAR1 = (I2C_InitStruct->I2C_AcknowledgedAddress | I2C_InitStruct->I2C_OwnAddress1);
}

/**
  * @brief  将 I2C_InitStruct 的每个成员填充为默认值。
  * @param  I2C_InitStruct: 指向待初始化的 I2C_InitTypeDef 结构的指针。
  * @retval 无
  */
void I2C_StructInit(I2C_InitTypeDef* I2C_InitStruct)
{
/*---------------- 复位 I2C 初始化结构体参数值 ----------------*/
  /* 初始化 I2C_ClockSpeed 成员 */
  I2C_InitStruct->I2C_ClockSpeed = 5000;
  /* 初始化 I2C_Mode 成员 */
  I2C_InitStruct->I2C_Mode = I2C_Mode_I2C;
  /* 初始化 I2C_DutyCycle 成员 */
  I2C_InitStruct->I2C_DutyCycle = I2C_DutyCycle_2;
  /* 初始化 I2C_OwnAddress1 成员 */
  I2C_InitStruct->I2C_OwnAddress1 = 0;
  /* 初始化 I2C_Ack 成员 */
  I2C_InitStruct->I2C_Ack = I2C_Ack_Disable;
  /* 初始化 I2C_AcknowledgedAddress 成员 */
  I2C_InitStruct->I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
}

/**
  * @brief  使能或失能指定的 I2C 外设。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2Cx 外设的新状态。 
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_Cmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能所选 I2C 外设 */
    I2Cx->CR1 |= CR1_PE_Set;
  }
  else
  {
    /* 失能所选 I2C 外设 */
    I2Cx->CR1 &= CR1_PE_Reset;
  }
}

/**
  * @brief  使能或失能指定的 I2C DMA 请求。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C DMA 传输的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_DMACmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能所选 I2C DMA 请求 */
    I2Cx->CR2 |= CR2_DMAEN_Set;
  }
  else
  {
    /* 失能所选 I2C DMA 请求 */
    I2Cx->CR2 &= CR2_DMAEN_Reset;
  }
}

/**
  * @brief  指定下一次 DMA 传输是否为最后一次。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C DMA 最后一次传输的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_DMALastTransferCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 下一次 DMA 传输为最后一次传输 */
    I2Cx->CR2 |= CR2_LAST_Set;
  }
  else
  {
    /* 下一次 DMA 传输不是最后一次传输 */
    I2Cx->CR2 &= CR2_LAST_Reset;
  }
}

/**
  * @brief  产生 I2Cx 通信起始条件。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C 起始条件产生的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无。
  */
void I2C_GenerateSTART(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 产生起始条件 */
    I2Cx->CR1 |= CR1_START_Set;
  }
  else
  {
    /* 禁止产生起始条件 */
    I2Cx->CR1 &= CR1_START_Reset;
  }
}

/**
  * @brief  产生 I2Cx 通信停止条件。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C 停止条件产生的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无。
  */
void I2C_GenerateSTOP(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 产生停止条件 */
    I2Cx->CR1 |= CR1_STOP_Set;
  }
  else
  {
    /* 禁止产生停止条件 */
    I2Cx->CR1 &= CR1_STOP_Reset;
  }
}

/**
  * @brief  使能或失能指定的 I2C 应答功能。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C 应答的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无。
  */
void I2C_AcknowledgeConfig(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能应答 */
    I2Cx->CR1 |= CR1_ACK_Set;
  }
  else
  {
    /* 失能应答 */
    I2Cx->CR1 &= CR1_ACK_Reset;
  }
}

/**
  * @brief  配置指定的 I2C 自身地址 2。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  Address: 指定 7 位 I2C 自身地址 2。
  * @retval 无。
  */
void I2C_OwnAddress2Config(I2C_TypeDef* I2Cx, uint8_t Address)
{
  uint16_t tmpreg = 0;

  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));

  /* 读取寄存器原值 */
  tmpreg = I2Cx->OAR2;

  /* 复位 I2Cx 自身地址 2 的位 [7:1] */
  tmpreg &= OAR2_ADD2_Reset;

  /* 设置 I2Cx 自身地址 2 */
  tmpreg |= (uint16_t)((uint16_t)Address & (uint16_t)0x00FE);

  /* 保存新的寄存器值 */
  I2Cx->OAR2 = tmpreg;
}

/**
  * @brief  使能或失能指定的 I2C 双地址模式。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C 双地址模式的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_DualAddressCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能双地址模式 */
    I2Cx->OAR2 |= OAR2_ENDUAL_Set;
  }
  else
  {
    /* 失能双地址模式 */
    I2Cx->OAR2 &= OAR2_ENDUAL_Reset;
  }
}

/**
  * @brief  使能或失能指定的 I2C 广播呼叫功能。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C 广播呼叫的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_GeneralCallCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能广播呼叫 */
    I2Cx->CR1 |= CR1_ENGC_Set;
  }
  else
  {
    /* 失能广播呼叫 */
    I2Cx->CR1 &= CR1_ENGC_Reset;
  }
}

/**
  * @brief  使能或失能指定的 I2C 中断。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_IT: 指定要使能或失能的 I2C 中断源。 
  *   该参数可为以下值的任意组合：
  *     @arg I2C_IT_BUF: 缓冲区中断掩码
  *     @arg I2C_IT_EVT: 事件中断掩码
  *     @arg I2C_IT_ERR: 错误中断掩码
  * @param  NewState: 指定 I2C 中断的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_ITConfig(I2C_TypeDef* I2Cx, uint16_t I2C_IT, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_I2C_CONFIG_IT(I2C_IT));
  
  if (NewState != DISABLE)
  {
    /* 使能所选 I2C 中断 */
    I2Cx->CR2 |= I2C_IT;
  }
  else
  {
    /* 失能所选 I2C 中断 */
    I2Cx->CR2 &= (uint16_t)~I2C_IT;
  }
}

/**
  * @brief  通过 I2Cx 外设发送一个数据字节。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  Data: 要发送的字节。
  * @retval 无
  */
void I2C_SendData(I2C_TypeDef* I2Cx, uint8_t Data)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  /* 将要发送的数据写入 DR 寄存器 */
  I2Cx->DR = Data;
}

/**
  * @brief  返回 I2Cx 外设最近接收到的数据。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @retval 接收到的数据的值。
  */
uint8_t I2C_ReceiveData(I2C_TypeDef* I2Cx)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  /* 返回 DR 寄存器中的数据 */
  return (uint8_t)I2Cx->DR;
}

/**
  * @brief  发送地址字节以选择从设备。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  Address: 指定将要发送的从机地址
  * @param  I2C_Direction: 指定 I2C 设备将作为
  *   发送器还是接收器。该参数可取以下值之一
  *     @arg I2C_Direction_Transmitter: 发送器模式
  *     @arg I2C_Direction_Receiver: 接收器模式
  * @retval 无。
  */
void I2C_Send7bitAddress(I2C_TypeDef* I2Cx, uint8_t Address, uint8_t I2C_Direction)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_DIRECTION(I2C_Direction));
  /* 根据方向置位/复位读/写位 */
  if (I2C_Direction != I2C_Direction_Transmitter)
  {
    /* 将地址位 0 置位表示读 */
    Address |= OAR1_ADD0_Set;
  }
  else
  {
    /* 将地址位 0 复位表示写 */
    Address &= OAR1_ADD0_Reset;
  }
  /* 发送地址 */
  I2Cx->DR = Address;
}

/**
  * @brief  读取指定的 I2C 寄存器并返回其值。
  * @param  I2C_Register: 指定要读取的寄存器。
  *   该参数可取以下值之一：
  *     @arg I2C_Register_CR1:  CR1 寄存器。
  *     @arg I2C_Register_CR2:   CR2 寄存器。
  *     @arg I2C_Register_OAR1:  OAR1 寄存器。
  *     @arg I2C_Register_OAR2:  OAR2 寄存器。
  *     @arg I2C_Register_DR:    DR 寄存器。
  *     @arg I2C_Register_SR1:   SR1 寄存器。
  *     @arg I2C_Register_SR2:   SR2 寄存器。
  *     @arg I2C_Register_CCR:   CCR 寄存器。
  *     @arg I2C_Register_TRISE: TRISE 寄存器。
  * @retval 读取到的寄存器的值。
  */
uint16_t I2C_ReadRegister(I2C_TypeDef* I2Cx, uint8_t I2C_Register)
{
  __IO uint32_t tmp = 0;

  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_REGISTER(I2C_Register));

  tmp = (uint32_t) I2Cx;
  tmp += I2C_Register;

  /* 返回所选寄存器的值 */
  return (*(__IO uint16_t *) tmp);
}

/**
  * @brief  使能或失能指定的 I2C 软件复位。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C 软件复位的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_SoftwareResetCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 外设处于复位状态 */
    I2Cx->CR1 |= CR1_SWRST_Set;
  }
  else
  {
    /* 外设未处于复位状态 */
    I2Cx->CR1 &= CR1_SWRST_Reset;
  }
}

/**
  * @brief  在主接收器模式下选择指定的 I2C NACK 位置。
  *         当需要接收的数据个数等于 2 时，该函数在 I2C 主接收器模式下
  *         很有用。此时应在数据接收开始之前 
  *         调用该函数（参数为 I2C_NACKPosition_Next）， 
  *         如 2 字节接收流程所述，该流程在参考手册 
  *         的“主接收器”一节中推荐。                
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_NACKPosition: 指定 NACK 位置。 
  *   该参数可取以下值之一：
  *     @arg I2C_NACKPosition_Next: 表示下一个字节将是最后
  *          一个接收到的字节。  
  *     @arg I2C_NACKPosition_Current: 表示当前字节是最后 
  *          一个接收到的字节。
  *            
  * @note    该函数配置与 I2C_PECPositionConfig() 相同的位（POS）， 
  *          但它用于 I2C 模式，而 I2C_PECPositionConfig() 
  *          用于 SMBUS 模式。 
  *            
  * @retval 无
  */
void I2C_NACKPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_NACKPosition)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_NACK_POSITION(I2C_NACKPosition));
  
  /* 检查输入参数 */
  if (I2C_NACKPosition == I2C_NACKPosition_Next)
  {
    /* 移位寄存器中的下一个字节是最后接收到的字节 */
    I2Cx->CR1 |= I2C_NACKPosition_Next;
  }
  else
  {
    /* 移位寄存器中的当前字节是最后接收到的字节 */
    I2Cx->CR1 &= I2C_NACKPosition_Current;
  }
}

/**
  * @brief  为指定的 I2C 将 SMBusAlert 引脚驱动为高电平或低电平。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_SMBusAlert: 指定 SMBAlert 引脚电平。 
  *   该参数可取以下值之一：
  *     @arg I2C_SMBusAlert_Low: SMBAlert 引脚被驱动为低电平
  *     @arg I2C_SMBusAlert_High: SMBAlert 引脚被驱动为高电平
  * @retval 无
  */
void I2C_SMBusAlertConfig(I2C_TypeDef* I2Cx, uint16_t I2C_SMBusAlert)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_SMBUS_ALERT(I2C_SMBusAlert));
  if (I2C_SMBusAlert == I2C_SMBusAlert_Low)
  {
    /* 将 SMBusAlert 引脚驱动为低电平 */
    I2Cx->CR1 |= I2C_SMBusAlert_Low;
  }
  else
  {
    /* 将 SMBusAlert 引脚驱动为高电平  */
    I2Cx->CR1 &= I2C_SMBusAlert_High;
  }
}

/**
  * @brief  使能或失能指定的 I2C PEC 传输。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2C PEC 传输的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_TransmitPEC(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能所选 I2C PEC 传输 */
    I2Cx->CR1 |= CR1_PEC_Set;
  }
  else
  {
    /* 失能所选 I2C PEC 传输 */
    I2Cx->CR1 &= CR1_PEC_Reset;
  }
}

/**
  * @brief  选择指定的 I2C PEC 位置。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_PECPosition: 指定 PEC 位置。 
  *   该参数可取以下值之一：
  *     @arg I2C_PECPosition_Next: 表示下一个字节是 PEC
  *     @arg I2C_PECPosition_Current: 表示当前字节是 PEC
  *       
  * @note    该函数配置与 I2C_NACKPositionConfig() 相同的位（POS），
  *          但它用于 SMBUS 模式，而 I2C_NACKPositionConfig() 
  *          用于 I2C 模式。
  *               
  * @retval 无
  */
void I2C_PECPositionConfig(I2C_TypeDef* I2Cx, uint16_t I2C_PECPosition)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_PEC_POSITION(I2C_PECPosition));
  if (I2C_PECPosition == I2C_PECPosition_Next)
  {
    /* 移位寄存器中的下一个字节是 PEC */
    I2Cx->CR1 |= I2C_PECPosition_Next;
  }
  else
  {
    /* 移位寄存器中的当前字节是 PEC */
    I2Cx->CR1 &= I2C_PECPosition_Current;
  }
}

/**
  * @brief  使能或失能已传输字节的 PEC 值计算。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2Cx PEC 值计算的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_CalculatePEC(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能所选 I2C PEC 计算 */
    I2Cx->CR1 |= CR1_ENPEC_Set;
  }
  else
  {
    /* 失能所选 I2C PEC 计算 */
    I2Cx->CR1 &= CR1_ENPEC_Reset;
  }
}

/**
  * @brief  返回指定 I2C 的 PEC 值。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @retval PEC 值。
  */
uint8_t I2C_GetPEC(I2C_TypeDef* I2Cx)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  /* 返回所选 I2C PEC 值 */
  return ((I2Cx->SR2) >> 8);
}

/**
  * @brief  使能或失能指定的 I2C ARP。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2Cx ARP 的新状态。 
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_ARPCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能所选 I2C ARP */
    I2Cx->CR1 |= CR1_ENARP_Set;
  }
  else
  {
    /* 失能所选 I2C ARP */
    I2Cx->CR1 &= CR1_ENARP_Reset;
  }
}

/**
  * @brief  使能或失能指定的 I2C 时钟延展。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  NewState: I2Cx 时钟延展的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2C_StretchClockCmd(I2C_TypeDef* I2Cx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState == DISABLE)
  {
    /* 使能所选 I2C 时钟延展 */
    I2Cx->CR1 |= CR1_NOSTRETCH_Set;
  }
  else
  {
    /* 失能所选 I2C 时钟延展 */
    I2Cx->CR1 &= CR1_NOSTRETCH_Reset;
  }
}

/**
  * @brief  选择指定的 I2C 快速模式占空比。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_DutyCycle: 指定快速模式占空比。
  *   该参数可取以下值之一：
  *     @arg I2C_DutyCycle_2: I2C 快速模式 Tlow/Thigh = 2
  *     @arg I2C_DutyCycle_16_9: I2C 快速模式 Tlow/Thigh = 16/9
  * @retval 无
  */
void I2C_FastModeDutyCycleConfig(I2C_TypeDef* I2Cx, uint16_t I2C_DutyCycle)
{
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_DUTY_CYCLE(I2C_DutyCycle));
  if (I2C_DutyCycle != I2C_DutyCycle_16_9)
  {
    /* I2C 快速模式 Tlow/Thigh=2 */
    I2Cx->CCR &= I2C_DutyCycle_2;
  }
  else
  {
    /* I2C 快速模式 Tlow/Thigh=16/9 */
    I2Cx->CCR |= I2C_DutyCycle_16_9;
  }
}



/**
 * @brief
 ****************************************************************************************
 *
 *                         I2C 状态监测函数
 *                       
 ****************************************************************************************   
 * 本 I2C 驱动提供三种不同的 I2C 状态监测方式，
 *  具体取决于应用需求和约束：
 *        
 *  
 * 1) 基本状态监测：
 *    使用 I2C_CheckEvent() 函数：
 *    它将状态寄存器（SR1 和 SR2）的内容与给定事件
 *    （可为一个或多个标志位的组合）进行比较。
 *    如果当前状态包含给定的标志位，则返回 SUCCESS； 
 *    如果当前状态缺少一个或多个标志位，则返回 ERROR。
 *    - 适用场合：
 *      - 该函数适用于大多数应用，也适用于启动 
 *      阶段，因为产品参考手册 
 *      (RM0008) 中完整描述了这些事件。
 *      - 它也适用于需要自定义事件的用户。
 *    - 局限性：
 *      - 如果发生错误（即除了被监测的标志位之外还置位了错误标志位），
 *        I2C_CheckEvent() 函数可能仍返回 SUCCESS，尽管通信
 *        实际处于保持或损坏状态。 
 *        此时建议使用错误中断来监测错误
 *        事件，并在中断 IRQ 处理函数中处理它们。
 *        
 *        @note 
 *        对于错误管理，建议使用以下函数：
 *          - I2C_ITConfig() 用于配置并使能错误中断（I2C_IT_ERR）。
 *          - I2Cx_ER_IRQHandler()，在发生错误中断时被调用。
 *            其中 x 为外设实例（I2C1、I2C2 ...）
 *          - 在 I2Cx_ER_IRQHandler() 中调用 I2C_GetFlagStatus() 或 I2C_GetITStatus() 
 *            以确定发生了哪种错误。
 *          - I2C_ClearFlag() 或 I2C_ClearITPendingBit() 和/或 I2C_SoftwareResetCmd()
 *            和/或 I2C_GenerateStop() 以清除错误标志位和错误源，
 *            并恢复到正确的通信状态。
 *            
 *
 *  2) 高级状态监测：
 *     使用 I2C_GetLastEvent() 函数，它在一个字（uint32_t）中返回 
 *     两个状态寄存器的映像（状态寄存器 2 的值左移 
 *     16 位后与状态寄存器 1 拼接）。
 *     - 适用场合：
 *       - 该函数适用于上述相同的应用，但它可以
 *         克服 I2C_GetFlagStatus() 函数上述的局限性。
 *         返回的值可与库中（stm32f10x_i2c.h）已定义的事件 
 *         或用户自定义的值进行比较。
 *       - 该函数适用于同时监测多个标志位的情况。
 *       - 与 I2C_CheckEvent() 函数相反，该函数允许用户
 *         选择何时接受事件（当所有事件标志位都已置位且没有 
 *         其他标志位置位时，或者像 I2C_CheckEvent() 函数那样 
 *         仅在所需标志位置位时）。
 *     - 局限性：
 *       - 用户可能需要自定义事件。
 *       - 如果用户决定仅检查常规通信标志位 
 *         （而忽略错误标志位），则有关错误管理的 
 *         相同说明同样适用于该函数。
 *     
 *
 *  3) 基于标志位的状态监测：
 *     使用 I2C_GetFlagStatus() 函数，它仅返回 
 *     单个标志位的状态（即 I2C_FLAG_RXNE ...）。 
 *     - 适用场合：
 *        - 该函数可用于特定应用或调试阶段。
 *        - 它适用于只需检查一个标志位的情况（大多数 I2C 事件 
 *          需要通过多个标志位来监测）。
 *     - 局限性： 
 *        - 调用该函数时会访问状态寄存器。某些标志位
 *          在访问状态寄存器时会被清除。因此检查一个
 *          标志位的状态可能会清除其他标志位。
 *        - 为了监测单个事件，可能需要调用该函数 
 *          两次或更多次。
 *
 *  有关事件的详细说明，请参阅 stm32f10x_i2c.h 文件中的 
 *  I2C_Events 一节。
 *  
 */

/**
 * 
 *  1) 基本状态监测
 *******************************************************************************
 */

/**
  * @brief  检查最后一个 I2Cx 事件是否等于作为参数
  *   传入的事件。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_EVENT: 指定要检查的事件。 
  *   该参数可取以下值之一：
  *     @arg I2C_EVENT_SLAVE_TRANSMITTER_ADDRESS_MATCHED           : EV1
  *     @arg I2C_EVENT_SLAVE_RECEIVER_ADDRESS_MATCHED              : EV1
  *     @arg I2C_EVENT_SLAVE_TRANSMITTER_SECONDADDRESS_MATCHED     : EV1
  *     @arg I2C_EVENT_SLAVE_RECEIVER_SECONDADDRESS_MATCHED        : EV1
  *     @arg I2C_EVENT_SLAVE_GENERALCALLADDRESS_MATCHED            : EV1
  *     @arg I2C_EVENT_SLAVE_BYTE_RECEIVED                         : EV2
  *     @arg (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_DUALF)      : EV2
  *     @arg (I2C_EVENT_SLAVE_BYTE_RECEIVED | I2C_FLAG_GENCALL)    : EV2
  *     @arg I2C_EVENT_SLAVE_BYTE_TRANSMITTED                      : EV3
  *     @arg (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_DUALF)   : EV3
  *     @arg (I2C_EVENT_SLAVE_BYTE_TRANSMITTED | I2C_FLAG_GENCALL) : EV3
  *     @arg I2C_EVENT_SLAVE_ACK_FAILURE                           : EV3_2
  *     @arg I2C_EVENT_SLAVE_STOP_DETECTED                         : EV4
  *     @arg I2C_EVENT_MASTER_MODE_SELECT                          : EV5
  *     @arg I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED            : EV6     
  *     @arg I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED               : EV6
  *     @arg I2C_EVENT_MASTER_BYTE_RECEIVED                        : EV7
  *     @arg I2C_EVENT_MASTER_BYTE_TRANSMITTING                    : EV8
  *     @arg I2C_EVENT_MASTER_BYTE_TRANSMITTED                     : EV8_2
  *     @arg I2C_EVENT_MASTER_MODE_ADDRESS10                       : EV9
  *     
  * @note: 有关事件的详细说明，请参阅 
  *    stm32f10x_i2c.h 文件中的 I2C_Events 一节。
  *    
  * @retval ErrorStatus 枚举值：
  * - SUCCESS: 最后一个事件等于 I2C_EVENT
  * - ERROR: 最后一个事件不同于 I2C_EVENT
  */
ErrorStatus I2C_CheckEvent(I2C_TypeDef* I2Cx, uint32_t I2C_EVENT)
{
  uint32_t lastevent = 0;
  uint32_t flag1 = 0, flag2 = 0;
  ErrorStatus status = ERROR;

  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_EVENT(I2C_EVENT));

  /* 读取 I2Cx 状态寄存器 */
  flag1 = I2Cx->SR1;
  flag2 = I2Cx->SR2;
  flag2 = flag2 << 16;

  /* 从 I2C 状态寄存器获取最后一个事件的值 */
  lastevent = (flag1 | flag2) & FLAG_Mask;

  /* 检查最后一个事件是否包含 I2C_EVENT */
  if ((lastevent & I2C_EVENT) == I2C_EVENT)
  {
    /* SUCCESS：最后一个事件等于 I2C_EVENT */
    status = SUCCESS;
  }
  else
  {
    /* ERROR：最后一个事件不同于 I2C_EVENT */
    status = ERROR;
  }
  /* 返回状态 */
  return status;
}

/**
 * 
 *  2) 高级状态监测
 *******************************************************************************
 */

/**
  * @brief  返回最后一个 I2Cx 事件。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  *     
  * @note: 有关事件的详细说明，请参阅 
  *    stm32f10x_i2c.h 文件中的 I2C_Events 一节。
  *    
  * @retval 最后一个事件
  */
uint32_t I2C_GetLastEvent(I2C_TypeDef* I2Cx)
{
  uint32_t lastevent = 0;
  uint32_t flag1 = 0, flag2 = 0;

  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));

  /* 读取 I2Cx 状态寄存器 */
  flag1 = I2Cx->SR1;
  flag2 = I2Cx->SR2;
  flag2 = flag2 << 16;

  /* 从 I2C 状态寄存器获取最后一个事件的值 */
  lastevent = (flag1 | flag2) & FLAG_Mask;

  /* 返回状态 */
  return lastevent;
}

/**
 * 
 *  3) 基于标志位的状态监测
 *******************************************************************************
 */

/**
  * @brief  检查指定的 I2C 标志位是否置位。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_FLAG: 指定要检查的标志位。 
  *   该参数可取以下值之一：
  *     @arg I2C_FLAG_DUALF: 双标志位（从模式）
  *     @arg I2C_FLAG_SMBHOST: SMBus 主机头（从模式）
  *     @arg I2C_FLAG_SMBDEFAULT: SMBus 默认头（从模式）
  *     @arg I2C_FLAG_GENCALL: 广播呼叫头标志位（从模式）
  *     @arg I2C_FLAG_TRA: 发送器/接收器标志位
  *     @arg I2C_FLAG_BUSY: 总线忙标志位
  *     @arg I2C_FLAG_MSL: 主/从标志位
  *     @arg I2C_FLAG_SMBALERT: SMBus 报警标志位
  *     @arg I2C_FLAG_TIMEOUT: 超时或 Tlow 错误标志位
  *     @arg I2C_FLAG_PECERR: 接收时的 PEC 错误标志位
  *     @arg I2C_FLAG_OVR: 溢出/下溢标志位（从模式）
  *     @arg I2C_FLAG_AF: 应答失败标志位
  *     @arg I2C_FLAG_ARLO: 仲裁丢失标志位（主模式）
  *     @arg I2C_FLAG_BERR: 总线错误标志位
  *     @arg I2C_FLAG_TXE: 数据寄存器空标志位（发送器）
  *     @arg I2C_FLAG_RXNE: 数据寄存器非空标志位（接收器）
  *     @arg I2C_FLAG_STOPF: 停止检测标志位（从模式）
  *     @arg I2C_FLAG_ADD10: 已发送 10 位头标志位（主模式）
  *     @arg I2C_FLAG_BTF: 字节传输完成标志位
  *     @arg I2C_FLAG_ADDR: 地址已发送标志位（主模式）"ADSL"
  *   地址匹配标志位（从模式）"ENDA"
  *     @arg I2C_FLAG_SB: 起始位标志位（主模式）
  * @retval I2C_FLAG 的新状态（SET 或 RESET）。
  */
FlagStatus I2C_GetFlagStatus(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG)
{
  FlagStatus bitstatus = RESET;
  __IO uint32_t i2creg = 0, i2cxbase = 0;

  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_GET_FLAG(I2C_FLAG));

  /* 获取 I2Cx 外设基地址 */
  i2cxbase = (uint32_t)I2Cx;
  
  /* 读取标志位寄存器索引 */
  i2creg = I2C_FLAG >> 28;
  
  /* 获取标志位的位 [23:0] */
  I2C_FLAG &= FLAG_Mask;
  
  if(i2creg != 0)
  {
    /* 获取 I2Cx SR1 寄存器地址 */
    i2cxbase += 0x14;
  }
  else
  {
    /* 标志位位于 I2Cx SR2 寄存器中 */
    I2C_FLAG = (uint32_t)(I2C_FLAG >> 16);
    /* 获取 I2Cx SR2 寄存器地址 */
    i2cxbase += 0x18;
  }
  
  if(((*(__IO uint32_t *)i2cxbase) & I2C_FLAG) != (uint32_t)RESET)
  {
    /* I2C_FLAG 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* I2C_FLAG 已复位 */
    bitstatus = RESET;
  }
  
  /* 返回 I2C_FLAG 状态 */
  return  bitstatus;
}



/**
  * @brief  清除 I2Cx 的挂起标志位。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_FLAG: 指定要清除的标志位。 
  *   该参数可为以下值的任意组合：
  *     @arg I2C_FLAG_SMBALERT: SMBus 报警标志位
  *     @arg I2C_FLAG_TIMEOUT: 超时或 Tlow 错误标志位
  *     @arg I2C_FLAG_PECERR: 接收时的 PEC 错误标志位
  *     @arg I2C_FLAG_OVR: 溢出/下溢标志位（从模式）
  *     @arg I2C_FLAG_AF: 应答失败标志位
  *     @arg I2C_FLAG_ARLO: 仲裁丢失标志位（主模式）
  *     @arg I2C_FLAG_BERR: 总线错误标志位
  *   
  * @note
  *   - STOPF（停止检测）通过软件序列清除：读 
  *     I2C_SR1 寄存器（I2C_GetFlagStatus()），然后写 
  *     I2C_CR1 寄存器（I2C_Cmd() 重新使能 I2C 外设）。
  *   - ADD10（已发送 10 位头）通过软件序列清除：读 
  *     I2C_SR1（I2C_GetFlagStatus()），然后将地址的 
  *     第二个字节写入 DR 寄存器。
  *   - BTF（字节传输完成）通过软件序列清除：读 
  *     I2C_SR1 寄存器（I2C_GetFlagStatus()），然后 
  *     读/写 I2C_DR 寄存器（I2C_SendData()）。
  *   - ADDR（地址已发送）通过软件序列清除：读 
  *     I2C_SR1 寄存器（I2C_GetFlagStatus()），然后读 
  *     I2C_SR2 寄存器（(void)(I2Cx->SR2)）。
  *   - SB（起始位）通过软件序列清除：读 I2C_SR1
  *     寄存器（I2C_GetFlagStatus()），然后写 I2C_DR
  *     寄存器（I2C_SendData()）。
  * @retval 无
  */
void I2C_ClearFlag(I2C_TypeDef* I2Cx, uint32_t I2C_FLAG)
{
  uint32_t flagpos = 0;
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_CLEAR_FLAG(I2C_FLAG));
  /* 获取 I2C 标志位的位置 */
  flagpos = I2C_FLAG & FLAG_Mask;
  /* 清除所选的 I2C 标志位 */
  I2Cx->SR1 = (uint16_t)~flagpos;
}

/**
  * @brief  检查指定的 I2C 中断是否发生。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_IT: 指定要检查的中断源。 
  *   该参数可取以下值之一：
  *     @arg I2C_IT_SMBALERT: SMBus 报警标志位
  *     @arg I2C_IT_TIMEOUT: 超时或 Tlow 错误标志位
  *     @arg I2C_IT_PECERR: 接收时的 PEC 错误标志位
  *     @arg I2C_IT_OVR: 溢出/下溢标志位（从模式）
  *     @arg I2C_IT_AF: 应答失败标志位
  *     @arg I2C_IT_ARLO: 仲裁丢失标志位（主模式）
  *     @arg I2C_IT_BERR: 总线错误标志位
  *     @arg I2C_IT_TXE: 数据寄存器空标志位（发送器）
  *     @arg I2C_IT_RXNE: 数据寄存器非空标志位（接收器）
  *     @arg I2C_IT_STOPF: 停止检测标志位（从模式）
  *     @arg I2C_IT_ADD10: 已发送 10 位头标志位（主模式）
  *     @arg I2C_IT_BTF: 字节传输完成标志位
  *     @arg I2C_IT_ADDR: 地址已发送标志位（主模式）"ADSL"
  *                       地址匹配标志位（从模式）"ENDAD"
  *     @arg I2C_IT_SB: 起始位标志位（主模式）
  * @retval I2C_IT 的新状态（SET 或 RESET）。
  */
ITStatus I2C_GetITStatus(I2C_TypeDef* I2Cx, uint32_t I2C_IT)
{
  ITStatus bitstatus = RESET;
  uint32_t enablestatus = 0;

  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_GET_IT(I2C_IT));

  /* 检查中断源是否已使能 */
  enablestatus = (uint32_t)(((I2C_IT & ITEN_Mask) >> 16) & (I2Cx->CR2)) ;
  
  /* 获取标志位的位 [23:0] */
  I2C_IT &= FLAG_Mask;

  /* 检查指定 I2C 标志位的状态 */
  if (((I2Cx->SR1 & I2C_IT) != (uint32_t)RESET) && enablestatus)
  {
    /* I2C_IT 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* I2C_IT 已复位 */
    bitstatus = RESET;
  }
  /* 返回 I2C_IT 状态 */
  return  bitstatus;
}

/**
  * @brief  清除 I2Cx 的中断挂起标志位。
  * @param  I2Cx: x 可为 1 或 2，用于选择 I2C 外设。
  * @param  I2C_IT: 指定要清除的中断挂起标志位。 
  *   该参数可为以下值的任意组合：
  *     @arg I2C_IT_SMBALERT: SMBus 报警中断
  *     @arg I2C_IT_TIMEOUT: 超时或 Tlow 错误中断
  *     @arg I2C_IT_PECERR: 接收时的 PEC 错误中断
  *     @arg I2C_IT_OVR: 溢出/下溢中断（从模式）
  *     @arg I2C_IT_AF: 应答失败中断
  *     @arg I2C_IT_ARLO: 仲裁丢失中断（主模式）
  *     @arg I2C_IT_BERR: 总线错误中断
  *   
  * @note
  *   - STOPF（停止检测）通过软件序列清除：读 
  *     I2C_SR1 寄存器（I2C_GetITStatus()），然后写 
  *     I2C_CR1 寄存器（I2C_Cmd() 重新使能 I2C 外设）。
  *   - ADD10（已发送 10 位头）通过软件序列清除：读 
  *     I2C_SR1（I2C_GetITStatus()），然后将地址的第二个 
  *     字节写入 I2C_DR 寄存器。
  *   - BTF（字节传输完成）通过软件序列清除：读 
  *     I2C_SR1 寄存器（I2C_GetITStatus()），然后 
  *     读/写 I2C_DR 寄存器（I2C_SendData()）。
  *   - ADDR（地址已发送）通过软件序列清除：读 
  *     I2C_SR1 寄存器（I2C_GetITStatus()），然后读 
  *     I2C_SR2 寄存器（(void)(I2Cx->SR2)）。
  *   - SB（起始位）通过软件序列清除：读 
  *     I2C_SR1 寄存器（I2C_GetITStatus()），然后写 
  *     I2C_DR 寄存器（I2C_SendData()）。
  * @retval 无
  */
void I2C_ClearITPendingBit(I2C_TypeDef* I2Cx, uint32_t I2C_IT)
{
  uint32_t flagpos = 0;
  /* 检查参数 */
  assert_param(IS_I2C_ALL_PERIPH(I2Cx));
  assert_param(IS_I2C_CLEAR_IT(I2C_IT));
  /* 获取 I2C 标志位的位置 */
  flagpos = I2C_IT & FLAG_Mask;
  /* 清除所选的 I2C 标志位 */
  I2Cx->SR1 = (uint16_t)~flagpos;
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
