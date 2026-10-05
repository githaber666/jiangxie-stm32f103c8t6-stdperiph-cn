/**
  ******************************************************************************
  * @file    stm32f10x_usart.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供所有 USART 固件函数。
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
#include "stm32f10x_usart.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup USART 
  * @brief USART 驱动模块
  * @{
  */

/** @defgroup USART_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup USART_Private_Defines
  * @{
  */

#define CR1_UE_Set                ((uint16_t)0x2000)  /*!< USART 使能掩码 */
#define CR1_UE_Reset              ((uint16_t)0xDFFF)  /*!< USART 失能掩码 */

#define CR1_WAKE_Mask             ((uint16_t)0xF7FF)  /*!< USART 唤醒方式掩码 */

#define CR1_RWU_Set               ((uint16_t)0x0002)  /*!< USART 静默模式使能掩码 */
#define CR1_RWU_Reset             ((uint16_t)0xFFFD)  /*!< USART 静默模式使能掩码 */
#define CR1_SBK_Set               ((uint16_t)0x0001)  /*!< USART 断开帧发送掩码 */
#define CR1_CLEAR_Mask            ((uint16_t)0xE9F3)  /*!< USART CR1 掩码 */
#define CR2_Address_Mask          ((uint16_t)0xFFF0)  /*!< USART 地址掩码 */

#define CR2_LINEN_Set              ((uint16_t)0x4000)  /*!< USART LIN 使能掩码 */
#define CR2_LINEN_Reset            ((uint16_t)0xBFFF)  /*!< USART LIN 失能掩码 */

#define CR2_LBDL_Mask             ((uint16_t)0xFFDF)  /*!< USART LIN 断开检测掩码 */
#define CR2_STOP_CLEAR_Mask       ((uint16_t)0xCFFF)  /*!< USART CR2 停止位掩码 */
#define CR2_CLOCK_CLEAR_Mask      ((uint16_t)0xF0FF)  /*!< USART CR2 时钟掩码 */

#define CR3_SCEN_Set              ((uint16_t)0x0020)  /*!< USART SC 使能掩码 */
#define CR3_SCEN_Reset            ((uint16_t)0xFFDF)  /*!< USART SC 失能掩码 */

#define CR3_NACK_Set              ((uint16_t)0x0010)  /*!< USART SC NACK 使能掩码 */
#define CR3_NACK_Reset            ((uint16_t)0xFFEF)  /*!< USART SC NACK 失能掩码 */

#define CR3_HDSEL_Set             ((uint16_t)0x0008)  /*!< USART 半双工使能掩码 */
#define CR3_HDSEL_Reset           ((uint16_t)0xFFF7)  /*!< USART 半双工失能掩码 */

#define CR3_IRLP_Mask             ((uint16_t)0xFFFB)  /*!< USART IrDA 低功耗模式掩码 */
#define CR3_CLEAR_Mask            ((uint16_t)0xFCFF)  /*!< USART CR3 掩码 */

#define CR3_IREN_Set              ((uint16_t)0x0002)  /*!< USART IrDA 使能掩码 */
#define CR3_IREN_Reset            ((uint16_t)0xFFFD)  /*!< USART IrDA 失能掩码 */
#define GTPR_LSB_Mask             ((uint16_t)0x00FF)  /*!< 保护时间寄存器 LSB 掩码 */
#define GTPR_MSB_Mask             ((uint16_t)0xFF00)  /*!< 保护时间寄存器 MSB 掩码 */
#define IT_Mask                   ((uint16_t)0x001F)  /*!< USART 中断掩码 */

/* USART 8 倍过采样掩码 */
#define CR1_OVER8_Set             ((u16)0x8000)  /* USART OVER8 模式使能掩码 */
#define CR1_OVER8_Reset           ((u16)0x7FFF)  /* USART OVER8 模式失能掩码 */

/* USART 一位采样掩码 */
#define CR3_ONEBITE_Set           ((u16)0x0800)  /* USART ONEBITE 模式使能掩码 */
#define CR3_ONEBITE_Reset         ((u16)0xF7FF)  /* USART ONEBITE 模式失能掩码 */

/**
  * @}
  */

/** @defgroup USART_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup USART_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup USART_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup USART_Private_Functions
  * @{
  */

/**
  * @brief  将 USARTx 外设寄存器复位为默认值。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一： 
  *      USART1、USART2、USART3、UART4 或 UART5。
  * @retval 无
  */
void USART_DeInit(USART_TypeDef* USARTx)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));

  if (USARTx == USART1)
  {
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_USART1, DISABLE);
  }
  else if (USARTx == USART2)
  {
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART2, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART2, DISABLE);
  }
  else if (USARTx == USART3)
  {
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART3, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_USART3, DISABLE);
  }    
  else if (USARTx == UART4)
  {
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART4, ENABLE);
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART4, DISABLE);
  }    
  else
  {
    if (USARTx == UART5)
    { 
      RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART5, ENABLE);
      RCC_APB1PeriphResetCmd(RCC_APB1Periph_UART5, DISABLE);
    }
  }
}

/**
  * @brief  根据 USART_InitStruct 中指定的参数初始化
  *         USARTx 外设。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_InitStruct: 指向 USART_InitTypeDef 结构的指针，
  *         该结构包含指定 USART 外设的 
  *         配置信息。
  * @retval 无
  */
void USART_Init(USART_TypeDef* USARTx, USART_InitTypeDef* USART_InitStruct)
{
  uint32_t tmpreg = 0x00, apbclock = 0x00;
  uint32_t integerdivider = 0x00;
  uint32_t fractionaldivider = 0x00;
  uint32_t usartxbase = 0;
  RCC_ClocksTypeDef RCC_ClocksStatus;
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_BAUDRATE(USART_InitStruct->USART_BaudRate));  
  assert_param(IS_USART_WORD_LENGTH(USART_InitStruct->USART_WordLength));
  assert_param(IS_USART_STOPBITS(USART_InitStruct->USART_StopBits));
  assert_param(IS_USART_PARITY(USART_InitStruct->USART_Parity));
  assert_param(IS_USART_MODE(USART_InitStruct->USART_Mode));
  assert_param(IS_USART_HARDWARE_FLOW_CONTROL(USART_InitStruct->USART_HardwareFlowControl));
  /* 硬件流控制仅适用于 USART1、USART2 和 USART3 */
  if (USART_InitStruct->USART_HardwareFlowControl != USART_HardwareFlowControl_None)
  {
    assert_param(IS_USART_123_PERIPH(USARTx));
  }

  usartxbase = (uint32_t)USARTx;

/*---------------------------- USART CR2 配置 -----------------------*/
  tmpreg = USARTx->CR2;
  /* 清除 STOP[13:12] 位 */
  tmpreg &= CR2_STOP_CLEAR_Mask;
  /* 配置 USART 停止位、时钟、CPOL、CPHA 和最后位 ------------*/
  /* 根据 USART_StopBits 的值设置 STOP[13:12] 位 */
  tmpreg |= (uint32_t)USART_InitStruct->USART_StopBits;
  
  /* 写入 USART CR2 */
  USARTx->CR2 = (uint16_t)tmpreg;

/*---------------------------- USART CR1 配置 -----------------------*/
  tmpreg = USARTx->CR1;
  /* 清除 M、PCE、PS、TE 和 RE 位 */
  tmpreg &= CR1_CLEAR_Mask;
  /* 配置 USART 字长、校验位和模式 ----------------------- */
  /* 根据 USART_WordLength 的值设置 M 位 */
  /* 根据 USART_Parity 的值设置 PCE 和 PS 位 */
  /* 根据 USART_Mode 的值设置 TE 和 RE 位 */
  tmpreg |= (uint32_t)USART_InitStruct->USART_WordLength | USART_InitStruct->USART_Parity |
            USART_InitStruct->USART_Mode;
  /* 写入 USART CR1 */
  USARTx->CR1 = (uint16_t)tmpreg;

/*---------------------------- USART CR3 配置 -----------------------*/  
  tmpreg = USARTx->CR3;
  /* 清除 CTSE 和 RTSE 位 */
  tmpreg &= CR3_CLEAR_Mask;
  /* 配置 USART 硬件流控制 -------------------------------------------------*/
  /* 根据 USART_HardwareFlowControl 的值设置 CTSE 和 RTSE 位 */
  tmpreg |= USART_InitStruct->USART_HardwareFlowControl;
  /* 写入 USART CR3 */
  USARTx->CR3 = (uint16_t)tmpreg;

/*---------------------------- USART BRR 配置 -----------------------*/
  /* 配置 USART 波特率 -------------------------------------------*/
  RCC_GetClocksFreq(&RCC_ClocksStatus);
  if (usartxbase == USART1_BASE)
  {
    apbclock = RCC_ClocksStatus.PCLK2_Frequency;
  }
  else
  {
    apbclock = RCC_ClocksStatus.PCLK1_Frequency;
  }
  
  /* 计算整数部分 */
  if ((USARTx->CR1 & CR1_OVER8_Set) != 0)
  {
    /* 过采样模式为 8 次采样时整数部分的计算方法 */
    integerdivider = ((25 * apbclock) / (2 * (USART_InitStruct->USART_BaudRate)));    
  }
  else /* if ((USARTx->CR1 & CR1_OVER8_Set) == 0) */
  {
    /* 过采样模式为 16 次采样时整数部分的计算方法 */
    integerdivider = ((25 * apbclock) / (4 * (USART_InitStruct->USART_BaudRate)));    
  }
  tmpreg = (integerdivider / 100) << 4;

  /* 计算小数部分 */
  fractionaldivider = integerdivider - (100 * (tmpreg >> 4));

  /* 将小数部分写入寄存器 */
  if ((USARTx->CR1 & CR1_OVER8_Set) != 0)
  {
    tmpreg |= ((((fractionaldivider * 8) + 50) / 100)) & ((uint8_t)0x07);
  }
  else /* if ((USARTx->CR1 & CR1_OVER8_Set) == 0) */
  {
    tmpreg |= ((((fractionaldivider * 16) + 50) / 100)) & ((uint8_t)0x0F);
  }
  
  /* 写入 USART BRR */
  USARTx->BRR = (uint16_t)tmpreg;
}

/**
  * @brief  将 USART_InitStruct 的每个成员填充为默认值。
  * @param  USART_InitStruct: 指向待初始化的 USART_InitTypeDef
  *         结构的指针。
  * @retval 无
  */
void USART_StructInit(USART_InitTypeDef* USART_InitStruct)
{
  /* USART_InitStruct 成员的默认值 */
  USART_InitStruct->USART_BaudRate = 9600;
  USART_InitStruct->USART_WordLength = USART_WordLength_8b;
  USART_InitStruct->USART_StopBits = USART_StopBits_1;
  USART_InitStruct->USART_Parity = USART_Parity_No ;
  USART_InitStruct->USART_Mode = USART_Mode_Rx | USART_Mode_Tx;
  USART_InitStruct->USART_HardwareFlowControl = USART_HardwareFlowControl_None;  
}

/**
  * @brief  根据 USART_ClockInitStruct 中指定的参数初始化 
  *          USARTx 外设时钟。
  * @param  USARTx: x 可为 1、2 或 3，用于选择 USART 外设。
  * @param  USART_ClockInitStruct: 指向 USART_ClockInitTypeDef
  *         结构的指针，该结构包含指定 USART 外设的 
  *         配置信息。  
  * @note 智能卡模式和同步模式不适用于 UART4 和 UART5。
  * @retval 无
  */
void USART_ClockInit(USART_TypeDef* USARTx, USART_ClockInitTypeDef* USART_ClockInitStruct)
{
  uint32_t tmpreg = 0x00;
  /* 检查参数 */
  assert_param(IS_USART_123_PERIPH(USARTx));
  assert_param(IS_USART_CLOCK(USART_ClockInitStruct->USART_Clock));
  assert_param(IS_USART_CPOL(USART_ClockInitStruct->USART_CPOL));
  assert_param(IS_USART_CPHA(USART_ClockInitStruct->USART_CPHA));
  assert_param(IS_USART_LASTBIT(USART_ClockInitStruct->USART_LastBit));
  
/*---------------------------- USART CR2 配置 -----------------------*/
  tmpreg = USARTx->CR2;
  /* 清除 CLKEN、CPOL、CPHA 和 LBCL 位 */
  tmpreg &= CR2_CLOCK_CLEAR_Mask;
  /* 配置 USART 时钟、CPOL、CPHA 和最后位 ------------*/
  /* 根据 USART_Clock 的值设置 CLKEN 位 */
  /* 根据 USART_CPOL 的值设置 CPOL 位 */
  /* 根据 USART_CPHA 的值设置 CPHA 位 */
  /* 根据 USART_LastBit 的值设置 LBCL 位 */
  tmpreg |= (uint32_t)USART_ClockInitStruct->USART_Clock | USART_ClockInitStruct->USART_CPOL | 
                 USART_ClockInitStruct->USART_CPHA | USART_ClockInitStruct->USART_LastBit;
  /* 写入 USART CR2 */
  USARTx->CR2 = (uint16_t)tmpreg;
}

/**
  * @brief  将 USART_ClockInitStruct 的每个成员填充为默认值。
  * @param  USART_ClockInitStruct: 指向待初始化的 USART_ClockInitTypeDef
  *         结构的指针。
  * @retval 无
  */
void USART_ClockStructInit(USART_ClockInitTypeDef* USART_ClockInitStruct)
{
  /* USART_ClockInitStruct 成员的默认值 */
  USART_ClockInitStruct->USART_Clock = USART_Clock_Disable;
  USART_ClockInitStruct->USART_CPOL = USART_CPOL_Low;
  USART_ClockInitStruct->USART_CPHA = USART_CPHA_1Edge;
  USART_ClockInitStruct->USART_LastBit = USART_LastBit_Disable;
}

/**
  * @brief  使能或失能指定的 USART 外设。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *         该参数可取以下值之一：
  *           USART1、USART2、USART3、UART4 或 UART5。
  * @param  NewState: USARTx 外设的新状态。
  *         该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void USART_Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* 通过置位 CR1 寄存器中的 UE 位使能所选 USART */
    USARTx->CR1 |= CR1_UE_Set;
  }
  else
  {
    /* 通过清除 CR1 寄存器中的 UE 位失能所选 USART */
    USARTx->CR1 &= CR1_UE_Reset;
  }
}

/**
  * @brief  使能或失能指定的 USART 中断。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_IT: 指定要使能或失能的 USART 中断源。
  *   该参数可取以下值之一：
  *     @arg USART_IT_CTS:  CTS 变化中断（不适用于 UART4 和 UART5）
  *     @arg USART_IT_LBD:  LIN 断开检测中断
  *     @arg USART_IT_TXE:  发送数据寄存器空中断
  *     @arg USART_IT_TC:   发送完成中断
  *     @arg USART_IT_RXNE: 读数据寄存器非空中断
  *     @arg USART_IT_IDLE: 空闲线路检测中断
  *     @arg USART_IT_PE:   校验错误中断
  *     @arg USART_IT_ERR:  错误中断（帧错误、噪声错误、溢出错误）
  * @param  NewState: 指定 USARTx 中断的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void USART_ITConfig(USART_TypeDef* USARTx, uint16_t USART_IT, FunctionalState NewState)
{
  uint32_t usartreg = 0x00, itpos = 0x00, itmask = 0x00;
  uint32_t usartxbase = 0x00;
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_CONFIG_IT(USART_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  /* CTS 中断不适用于 UART4 和 UART5 */
  if (USART_IT == USART_IT_CTS)
  {
    assert_param(IS_USART_123_PERIPH(USARTx));
  }   
  
  usartxbase = (uint32_t)USARTx;

  /* 获取 USART 寄存器索引 */
  usartreg = (((uint8_t)USART_IT) >> 0x05);

  /* 获取中断位置 */
  itpos = USART_IT & IT_Mask;
  itmask = (((uint32_t)0x01) << itpos);
    
  if (usartreg == 0x01) /* 该中断位于 CR1 寄存器中 */
  {
    usartxbase += 0x0C;
  }
  else if (usartreg == 0x02) /* 该中断位于 CR2 寄存器中 */
  {
    usartxbase += 0x10;
  }
  else /* 该中断位于 CR3 寄存器中 */
  {
    usartxbase += 0x14; 
  }
  if (NewState != DISABLE)
  {
    *(__IO uint32_t*)usartxbase  |= itmask;
  }
  else
  {
    *(__IO uint32_t*)usartxbase &= ~itmask;
  }
}

/**
  * @brief  使能或失能 USART 的 DMA 接口。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_DMAReq: 指定 DMA 请求。
  *   该参数可为以下值的任意组合：
  *     @arg USART_DMAReq_Tx: USART DMA 发送请求
  *     @arg USART_DMAReq_Rx: USART DMA 接收请求
  * @param  NewState: DMA 请求源的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @note 除 STM32 高密度型器件（STM32F10X_HD_VL）外，
  *       UART5 不支持 DMA 模式。  
  * @retval 无
  */
void USART_DMACmd(USART_TypeDef* USARTx, uint16_t USART_DMAReq, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_DMAREQ(USART_DMAReq));  
  assert_param(IS_FUNCTIONAL_STATE(NewState)); 
  if (NewState != DISABLE)
  {
    /* 通过置位 USART CR3 寄存器中的 DMAT 和/或
       DMAR 位来使能所选请求的 DMA 传输 */
    USARTx->CR3 |= USART_DMAReq;
  }
  else
  {
    /* 通过清除 USART CR3 寄存器中的 DMAT 和/或
       DMAR 位来使能所选请求的 DMA 传输 */
    USARTx->CR3 &= (uint16_t)~USART_DMAReq;
  }
}

/**
  * @brief  设置 USART 节点地址。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_Address: 指定 USART 节点的地址。
  * @retval 无
  */
void USART_SetAddress(USART_TypeDef* USARTx, uint8_t USART_Address)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_ADDRESS(USART_Address)); 
    
  /* 清除 USART 地址 */
  USARTx->CR2 &= CR2_Address_Mask;
  /* 设置 USART 节点地址 */
  USARTx->CR2 |= USART_Address;
}

/**
  * @brief  选择 USART 唤醒方式。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_WakeUp: 指定 USART 唤醒方式。
  *   该参数可取以下值之一：
  *     @arg USART_WakeUp_IdleLine: 通过空闲线路检测唤醒
  *     @arg USART_WakeUp_AddressMark: 通过地址标记唤醒
  * @retval 无
  */
void USART_WakeUpConfig(USART_TypeDef* USARTx, uint16_t USART_WakeUp)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_WAKEUP(USART_WakeUp));
  
  USARTx->CR1 &= CR1_WAKE_Mask;
  USARTx->CR1 |= USART_WakeUp;
}

/**
  * @brief  判断 USART 是否处于静默模式。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  NewState: USART 静默模式的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void USART_ReceiverWakeUpCmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState)); 
  
  if (NewState != DISABLE)
  {
    /* 通过置位 CR1 寄存器中的 RWU 位使能 USART 静默模式 */
    USARTx->CR1 |= CR1_RWU_Set;
  }
  else
  {
    /* 通过清除 CR1 寄存器中的 RWU 位失能 USART 静默模式 */
    USARTx->CR1 &= CR1_RWU_Reset;
  }
}

/**
  * @brief  设置 USART LIN 断开检测长度。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_LINBreakDetectLength: 指定 LIN 断开检测长度。
  *   该参数可取以下值之一：
  *     @arg USART_LINBreakDetectLength_10b: 10 位断开检测
  *     @arg USART_LINBreakDetectLength_11b: 11 位断开检测
  * @retval 无
  */
void USART_LINBreakDetectLengthConfig(USART_TypeDef* USARTx, uint16_t USART_LINBreakDetectLength)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_LIN_BREAK_DETECT_LENGTH(USART_LINBreakDetectLength));
  
  USARTx->CR2 &= CR2_LBDL_Mask;
  USARTx->CR2 |= USART_LINBreakDetectLength;  
}

/**
  * @brief  使能或失能 USART 的 LIN 模式。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  NewState: USART LIN 模式的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void USART_LINCmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* 通过置位 CR2 寄存器中的 LINEN 位使能 LIN 模式 */
    USARTx->CR2 |= CR2_LINEN_Set;
  }
  else
  {
    /* 通过清除 CR2 寄存器中的 LINEN 位失能 LIN 模式 */
    USARTx->CR2 &= CR2_LINEN_Reset;
  }
}

/**
  * @brief  通过 USARTx 外设发送单个数据。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  Data: 要发送的数据。
  * @retval 无
  */
void USART_SendData(USART_TypeDef* USARTx, uint16_t Data)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_DATA(Data)); 
    
  /* 发送数据 */
  USARTx->DR = (Data & (uint16_t)0x01FF);
}

/**
  * @brief  返回 USARTx 外设最近接收到的数据。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @retval 接收到的数据。
  */
uint16_t USART_ReceiveData(USART_TypeDef* USARTx)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  
  /* 接收数据 */
  return (uint16_t)(USARTx->DR & (uint16_t)0x01FF);
}

/**
  * @brief  发送断开帧。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @retval 无
  */
void USART_SendBreak(USART_TypeDef* USARTx)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  
  /* 发送断开帧 */
  USARTx->CR1 |= CR1_SBK_Set;
}

/**
  * @brief  设置指定的 USART 保护时间。
  * @param  USARTx: x 可为 1、2 或 3，用于选择 USART 外设。
  * @param  USART_GuardTime: 指定保护时间。
  * @note 保护时间位不适用于 UART4 和 UART5。   
  * @retval 无
  */
void USART_SetGuardTime(USART_TypeDef* USARTx, uint8_t USART_GuardTime)
{    
  /* 检查参数 */
  assert_param(IS_USART_123_PERIPH(USARTx));
  
  /* 清除 USART 保护时间 */
  USARTx->GTPR &= GTPR_LSB_Mask;
  /* 设置 USART 保护时间 */
  USARTx->GTPR |= (uint16_t)((uint16_t)USART_GuardTime << 0x08);
}

/**
  * @brief  设置系统时钟预分频系数。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_Prescaler: 指定预分频时钟。  
  * @note   该函数用于 UART4 和 UART5 的 IrDA 模式。
  * @retval 无
  */
void USART_SetPrescaler(USART_TypeDef* USARTx, uint8_t USART_Prescaler)
{ 
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  
  /* 清除 USART 预分频系数 */
  USARTx->GTPR &= GTPR_MSB_Mask;
  /* 设置 USART 预分频系数 */
  USARTx->GTPR |= USART_Prescaler;
}

/**
  * @brief  使能或失能 USART 的智能卡模式。
  * @param  USARTx: x 可为 1、2 或 3，用于选择 USART 外设。
  * @param  NewState: 智能卡模式的新状态。
  *   该参数可取：ENABLE 或 DISABLE。     
  * @note 智能卡模式不适用于 UART4 和 UART5。 
  * @retval 无
  */
void USART_SmartCardCmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_123_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 通过置位 CR3 寄存器中的 SCEN 位使能 SC 模式 */
    USARTx->CR3 |= CR3_SCEN_Set;
  }
  else
  {
    /* 通过清除 CR3 寄存器中的 SCEN 位失能 SC 模式 */
    USARTx->CR3 &= CR3_SCEN_Reset;
  }
}

/**
  * @brief  使能或失能 NACK 发送。
  * @param  USARTx: x 可为 1、2 或 3，用于选择 USART 外设。 
  * @param  NewState: NACK 发送的新状态。
  *   该参数可取：ENABLE 或 DISABLE。  
  * @note 智能卡模式不适用于 UART4 和 UART5。
  * @retval 无
  */
void USART_SmartCardNACKCmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_123_PERIPH(USARTx));  
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 通过置位 CR3 寄存器中的 NACK 位使能 NACK 发送 */
    USARTx->CR3 |= CR3_NACK_Set;
  }
  else
  {
    /* 通过清除 CR3 寄存器中的 NACK 位失能 NACK 发送 */
    USARTx->CR3 &= CR3_NACK_Reset;
  }
}

/**
  * @brief  使能或失能 USART 的半双工通信。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  NewState: USART 通信的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void USART_HalfDuplexCmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* 通过置位 CR3 寄存器中的 HDSEL 位使能半双工模式 */
    USARTx->CR3 |= CR3_HDSEL_Set;
  }
  else
  {
    /* 通过清除 CR3 寄存器中的 HDSEL 位失能半双工模式 */
    USARTx->CR3 &= CR3_HDSEL_Reset;
  }
}


/**
  * @brief  使能或失能 USART 的 8 倍过采样模式。
  * @param  USARTx: 选择 USART 或 UART 外设。
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  NewState: USART 一位采样方式的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @note
  *     为使波特率分频值正确，必须在调用 USART_Init()
  *     函数之前调用该函数。   
  * @retval 无
  */
void USART_OverSampling8Cmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* 通过置位 CR1 寄存器中的 OVER8 位使能 8 倍过采样模式 */
    USARTx->CR1 |= CR1_OVER8_Set;
  }
  else
  {
    /* 通过清除 CR1 寄存器中的 OVER8 位失能 8 倍过采样模式 */
    USARTx->CR1 &= CR1_OVER8_Reset;
  }
}

/**
  * @brief  使能或失能 USART 的一位采样方式。
  * @param  USARTx: 选择 USART 或 UART 外设。
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  NewState: USART 一位采样方式的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void USART_OneBitMethodCmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* 通过置位 CR3 寄存器中的 ONEBITE 位使能一位采样方式 */
    USARTx->CR3 |= CR3_ONEBITE_Set;
  }
  else
  {
    /* 通过清除 CR3 寄存器中的 ONEBITE 位失能一位采样方式 */
    USARTx->CR3 &= CR3_ONEBITE_Reset;
  }
}

/**
  * @brief  配置 USART 的 IrDA 接口。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_IrDAMode: 指定 IrDA 模式。
  *   该参数可取以下值之一：
  *     @arg USART_IrDAMode_LowPower
  *     @arg USART_IrDAMode_Normal
  * @retval 无
  */
void USART_IrDAConfig(USART_TypeDef* USARTx, uint16_t USART_IrDAMode)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_IRDA_MODE(USART_IrDAMode));
    
  USARTx->CR3 &= CR3_IRLP_Mask;
  USARTx->CR3 |= USART_IrDAMode;
}

/**
  * @brief  使能或失能 USART 的 IrDA 接口。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  NewState: IrDA 模式的新状态。
  *   该参数可取：ENABLE 或 DISABLE。
  * @retval 无
  */
void USART_IrDACmd(USART_TypeDef* USARTx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
    
  if (NewState != DISABLE)
  {
    /* 通过置位 CR3 寄存器中的 IREN 位使能 IrDA 模式 */
    USARTx->CR3 |= CR3_IREN_Set;
  }
  else
  {
    /* 通过清除 CR3 寄存器中的 IREN 位失能 IrDA 模式 */
    USARTx->CR3 &= CR3_IREN_Reset;
  }
}

/**
  * @brief  检查指定的 USART 标志位是否置位。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_FLAG: 指定要检查的标志位。
  *   该参数可取以下值之一：
  *     @arg USART_FLAG_CTS:  CTS 变化标志位（不适用于 UART4 和 UART5）
  *     @arg USART_FLAG_LBD:  LIN 断开检测标志位
  *     @arg USART_FLAG_TXE:  发送数据寄存器空标志位
  *     @arg USART_FLAG_TC:   发送完成标志位
  *     @arg USART_FLAG_RXNE: 读数据寄存器非空标志位
  *     @arg USART_FLAG_IDLE: 空闲线路检测标志位
  *     @arg USART_FLAG_ORE:  溢出错误标志位
  *     @arg USART_FLAG_NE:   噪声错误标志位
  *     @arg USART_FLAG_FE:   帧错误标志位
  *     @arg USART_FLAG_PE:   校验错误标志位
  * @retval USART_FLAG 的新状态（SET 或 RESET）。
  */
FlagStatus USART_GetFlagStatus(USART_TypeDef* USARTx, uint16_t USART_FLAG)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_FLAG(USART_FLAG));
  /* CTS 标志位不适用于 UART4 和 UART5 */
  if (USART_FLAG == USART_FLAG_CTS)
  {
    assert_param(IS_USART_123_PERIPH(USARTx));
  }  
  
  if ((USARTx->SR & USART_FLAG) != (uint16_t)RESET)
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
  * @brief  清除 USARTx 的挂起标志位。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_FLAG: 指定要清除的标志位。
  *   该参数可为以下值的任意组合：
  *     @arg USART_FLAG_CTS:  CTS 变化标志位（不适用于 UART4 和 UART5）。
  *     @arg USART_FLAG_LBD:  LIN 断开检测标志位。
  *     @arg USART_FLAG_TC:   发送完成标志位。
  *     @arg USART_FLAG_RXNE: 读数据寄存器非空标志位。
  *   
  * @note
  *   - PE（校验错误）、FE（帧错误）、NE（噪声错误）、ORE（溢出 
  *     错误）和 IDLE（检测到空闲线路）标志位通过软件序列清除： 
  *     读 USART_SR 寄存器（USART_GetFlagStatus()）， 
  *     然后读 USART_DR 寄存器（USART_ReceiveData()）。
  *   - RXNE 标志位也可通过读 USART_DR 寄存器 
  *     （USART_ReceiveData()）清除。
  *   - TC 标志位也可通过软件序列清除：读 
  *     USART_SR 寄存器（USART_GetFlagStatus()），然后写
  *     USART_DR 寄存器（USART_SendData()）。
  *   - TXE 标志位只能通过写 USART_DR 寄存器 
  *     （USART_SendData()）清除。
  * @retval 无
  */
void USART_ClearFlag(USART_TypeDef* USARTx, uint16_t USART_FLAG)
{
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_CLEAR_FLAG(USART_FLAG));
  /* CTS 标志位不适用于 UART4 和 UART5 */
  if ((USART_FLAG & USART_FLAG_CTS) == USART_FLAG_CTS)
  {
    assert_param(IS_USART_123_PERIPH(USARTx));
  } 
   
  USARTx->SR = (uint16_t)~USART_FLAG;
}

/**
  * @brief  检查指定的 USART 中断是否发生。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_IT: 指定要检查的 USART 中断源。
  *   该参数可取以下值之一：
  *     @arg USART_IT_CTS:  CTS 变化中断（不适用于 UART4 和 UART5）
  *     @arg USART_IT_LBD:  LIN 断开检测中断
  *     @arg USART_IT_TXE:  发送数据寄存器空中断
  *     @arg USART_IT_TC:   发送完成中断
  *     @arg USART_IT_RXNE: 读数据寄存器非空中断
  *     @arg USART_IT_IDLE: 空闲线路检测中断
  *     @arg USART_IT_ORE:  溢出错误中断
  *     @arg USART_IT_NE:   噪声错误中断
  *     @arg USART_IT_FE:   帧错误中断
  *     @arg USART_IT_PE:   校验错误中断
  * @retval USART_IT 的新状态（SET 或 RESET）。
  */
ITStatus USART_GetITStatus(USART_TypeDef* USARTx, uint16_t USART_IT)
{
  uint32_t bitpos = 0x00, itmask = 0x00, usartreg = 0x00;
  ITStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_GET_IT(USART_IT));
  /* CTS 中断不适用于 UART4 和 UART5 */ 
  if (USART_IT == USART_IT_CTS)
  {
    assert_param(IS_USART_123_PERIPH(USARTx));
  }   
  
  /* 获取 USART 寄存器索引 */
  usartreg = (((uint8_t)USART_IT) >> 0x05);
  /* 获取中断位置 */
  itmask = USART_IT & IT_Mask;
  itmask = (uint32_t)0x01 << itmask;
  
  if (usartreg == 0x01) /* 该中断位于 CR1 寄存器中 */
  {
    itmask &= USARTx->CR1;
  }
  else if (usartreg == 0x02) /* 该中断位于 CR2 寄存器中 */
  {
    itmask &= USARTx->CR2;
  }
  else /* 该中断位于 CR3 寄存器中 */
  {
    itmask &= USARTx->CR3;
  }
  
  bitpos = USART_IT >> 0x08;
  bitpos = (uint32_t)0x01 << bitpos;
  bitpos &= USARTx->SR;
  if ((itmask != (uint16_t)RESET)&&(bitpos != (uint16_t)RESET))
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
  * @brief  清除 USARTx 的中断挂起标志位。
  * @param  USARTx: 选择 USART 或 UART 外设。 
  *   该参数可取以下值之一：
  *   USART1、USART2、USART3、UART4 或 UART5。
  * @param  USART_IT: 指定要清除的中断挂起标志位。
  *   该参数可取以下值之一：
  *     @arg USART_IT_CTS:  CTS 变化中断（不适用于 UART4 和 UART5）
  *     @arg USART_IT_LBD:  LIN 断开检测中断
  *     @arg USART_IT_TC:   发送完成中断。 
  *     @arg USART_IT_RXNE: 读数据寄存器非空中断。
  *   
  * @note
  *   - PE（校验错误）、FE（帧错误）、NE（噪声错误）、ORE（溢出 
  *     错误）和 IDLE（检测到空闲线路）挂起标志位通过软件 
  *     序列清除：读 USART_SR 寄存器 
  *     （USART_GetITStatus()），然后读 USART_DR 寄存器 
  *     （USART_ReceiveData()）清除。
  *   - RXNE 挂起标志位也可通过读 USART_DR 寄存器 
  *     （USART_ReceiveData()）清除。
  *   - TC 挂起标志位也可通过软件序列清除：读 
  *     USART_SR 寄存器（USART_GetITStatus()），然后写 
  *     USART_DR 寄存器（USART_SendData()）。
  *   - TXE 挂起标志位只能通过写 USART_DR 寄存器 
  *     （USART_SendData()）清除。
  * @retval 无
  */
void USART_ClearITPendingBit(USART_TypeDef* USARTx, uint16_t USART_IT)
{
  uint16_t bitpos = 0x00, itmask = 0x00;
  /* 检查参数 */
  assert_param(IS_USART_ALL_PERIPH(USARTx));
  assert_param(IS_USART_CLEAR_IT(USART_IT));
  /* CTS 中断不适用于 UART4 和 UART5 */
  if (USART_IT == USART_IT_CTS)
  {
    assert_param(IS_USART_123_PERIPH(USARTx));
  }   
  
  bitpos = USART_IT >> 0x08;
  itmask = ((uint16_t)0x01 << (uint16_t)bitpos);
  USARTx->SR = (uint16_t)~itmask;
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
