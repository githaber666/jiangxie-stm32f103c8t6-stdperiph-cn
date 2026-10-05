/**
  ******************************************************************************
  * @file    stm32f10x_cec.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供 CEC 的所有固件函数。
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
#include "stm32f10x_cec.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup CEC 
  * @brief CEC 驱动模块
  * @{
  */

/** @defgroup CEC_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */


/** @defgroup CEC_Private_Defines
  * @{
  */ 

/* ------------ CEC 寄存器在别名区的位地址 ----------- */
#define CEC_OFFSET                (CEC_BASE - PERIPH_BASE)

/* --- CFGR 寄存器 ---*/

/* PE 位的别名地址（字） */
#define CFGR_OFFSET                 (CEC_OFFSET + 0x00)
#define PE_BitNumber                0x00
#define CFGR_PE_BB                  (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (PE_BitNumber * 4))

/* IE 位的别名地址（字） */
#define IE_BitNumber                0x01
#define CFGR_IE_BB                  (PERIPH_BB_BASE + (CFGR_OFFSET * 32) + (IE_BitNumber * 4))

/* --- CSR 寄存器 ---*/

/* TSOM 位的别名地址（字） */
#define CSR_OFFSET                  (CEC_OFFSET + 0x10)
#define TSOM_BitNumber              0x00
#define CSR_TSOM_BB                 (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TSOM_BitNumber * 4))

/* TEOM 位的别名地址（字） */
#define TEOM_BitNumber              0x01
#define CSR_TEOM_BB                 (PERIPH_BB_BASE + (CSR_OFFSET * 32) + (TEOM_BitNumber * 4))
  
#define CFGR_CLEAR_Mask            (uint8_t)(0xF3)        /* CFGR 寄存器掩码 */
#define FLAG_Mask                  ((uint32_t)0x00FFFFFF) /* CEC 标志位掩码 */
 
/**
  * @}
  */ 


/** @defgroup CEC_Private_Macros
  * @{
  */ 

/**
  * @}
  */ 


/** @defgroup CEC_Private_Variables
  * @{
  */ 

/**
  * @}
  */ 


/** @defgroup CEC_Private_FunctionPrototypes
  * @{
  */
 
/**
  * @}
  */ 


/** @defgroup CEC_Private_Functions
  * @{
  */ 

/**
  * @brief  将 CEC 外设寄存器复位 
  *         为默认值。
  * @param  无
  * @retval 无
  */
void CEC_DeInit(void)
{
  /* 使能 CEC 复位状态 */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_CEC, ENABLE);  
  /* 释放 CEC 的复位状态 */
  RCC_APB1PeriphResetCmd(RCC_APB1Periph_CEC, DISABLE); 
}


/**
  * @brief  根据 CEC_InitStruct 中指定的 
  *         参数初始化 CEC 外设。
  * @param  CEC_InitStruct：指向 CEC_InitTypeDef 结构的指针，
  *         该结构包含指定
  *         CEC 外设的配置信息。
  * @retval 无
  */
void CEC_Init(CEC_InitTypeDef* CEC_InitStruct)
{
  uint16_t tmpreg = 0;
 
  /* 检查参数 */
  assert_param(IS_CEC_BIT_TIMING_ERROR_MODE(CEC_InitStruct->CEC_BitTimingMode)); 
  assert_param(IS_CEC_BIT_PERIOD_ERROR_MODE(CEC_InitStruct->CEC_BitPeriodMode));
     
  /*---------------------------- CEC CFGR 配置 -----------------*/
  /* 获取 CEC CFGR 的值 */
  tmpreg = CEC->CFGR;
  
  /* 清除 BTEM 和 BPEM 位 */
  tmpreg &= CFGR_CLEAR_Mask;
  
  /* 配置 CEC：位定时错误和位周期错误 */
  tmpreg |= (uint16_t)(CEC_InitStruct->CEC_BitTimingMode | CEC_InitStruct->CEC_BitPeriodMode);

  /* 写入 CEC CFGR 寄存器 */
  CEC->CFGR = tmpreg;
  
}

/**
  * @brief  使能或失能指定的 CEC 外设。
  * @param  NewState：CEC 外设的新状态。 
  *     该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void CEC_Cmd(FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  *(__IO uint32_t *) CFGR_PE_BB = (uint32_t)NewState;

  if(NewState == DISABLE)
  {
    /* 等待硬件清除 PE 位（检测到空闲线路） */
    while((CEC->CFGR & CEC_CFGR_PE) != (uint32_t)RESET)
    {
    }  
  }  
}

/**
  * @brief  使能或失能 CEC 中断。
  * @param  NewState：CEC 中断的新状态。
  *   该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void CEC_ITConfig(FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  *(__IO uint32_t *) CFGR_IE_BB = (uint32_t)NewState;
}

/**
  * @brief  定义 CEC 设备的自身地址。
  * @param  CEC_OwnAddress：CEC 自身地址
  * @retval 无
  */
void CEC_OwnAddressConfig(uint8_t CEC_OwnAddress)
{
  /* 检查参数 */
  assert_param(IS_CEC_ADDRESS(CEC_OwnAddress));

  /* 设置 CEC 自身地址 */
  CEC->OAR = CEC_OwnAddress;
}

/**
  * @brief  设置 CEC 预分频值。
  * @param  CEC_Prescaler：CEC 预分频器的新值
  * @retval 无
  */
void CEC_SetPrescaler(uint16_t CEC_Prescaler)
{
  /* 检查参数 */
  assert_param(IS_CEC_PRESCALER(CEC_Prescaler));

  /* 设置预分频器值 */
  CEC->PRES = CEC_Prescaler;
}

/**
  * @brief  通过 CEC 外设发送单个数据。
  * @param  Data：要发送的数据。
  * @retval 无
  */
void CEC_SendDataByte(uint8_t Data)
{  
  /* 发送数据 */
  CEC->TXD = Data ;
}


/**
  * @brief  返回 CEC 外设最近接收到的数据。
  * @param  无
  * @retval 接收到的数据。
  */
uint8_t CEC_ReceiveDataByte(void)
{
  /* 接收数据 */
  return (uint8_t)(CEC->RXD);
}

/**
  * @brief  开始一条新消息。
  * @param  无
  * @retval 无
  */
void CEC_StartOfMessage(void)
{  
  /* 开始新消息 */
  *(__IO uint32_t *) CSR_TSOM_BB = (uint32_t)0x1;
}

/**
  * @brief  发送带或不带 EOM 位的消息。
  * @param  NewState：CEC 发送结束消息（EOM）的新状态。 
  *     该参数可以是：ENABLE 或 DISABLE。
  * @retval 无
  */
void CEC_EndOfMessageCmd(FunctionalState NewState)
{   
  /* 检查参数 */
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  /* 数据字节将带或不带 EOM 位发送 */
  *(__IO uint32_t *) CSR_TEOM_BB = (uint32_t)NewState;
}

/**
  * @brief  获取 CEC 标志位状态
  * @param  CEC_FLAG：指定要检查的 CEC 标志位。 
  *   该参数可以是以下值之一：
  *     @arg CEC_FLAG_BTE：位定时错误
  *     @arg CEC_FLAG_BPE：位周期错误
  *     @arg CEC_FLAG_RBTFE：接收块传输完成错误
  *     @arg CEC_FLAG_SBE：起始位错误
  *     @arg CEC_FLAG_ACKE：块应答错误
  *     @arg CEC_FLAG_LINE：线路错误
  *     @arg CEC_FLAG_TBTFE：发送块传输完成错误
  *     @arg CEC_FLAG_TEOM：发送结束消息 
  *     @arg CEC_FLAG_TERR：发送错误
  *     @arg CEC_FLAG_TBTRF：发送字节传输请求或块传输完成
  *     @arg CEC_FLAG_RSOM：接收开始消息
  *     @arg CEC_FLAG_REOM：接收结束消息
  *     @arg CEC_FLAG_RERR：接收错误
  *     @arg CEC_FLAG_RBTF：接收字节/块传输完成
  * @retval CEC_FLAG 的新状态（SET 或 RESET）
  */
FlagStatus CEC_GetFlagStatus(uint32_t CEC_FLAG) 
{
  FlagStatus bitstatus = RESET;
  uint32_t cecreg = 0, cecbase = 0;
  
  /* 检查参数 */
  assert_param(IS_CEC_GET_FLAG(CEC_FLAG));
 
  /* 获取 CEC 外设基地址 */
  cecbase = (uint32_t)(CEC_BASE);
  
  /* 读取标志位寄存器索引 */
  cecreg = CEC_FLAG >> 28;
  
  /* 获取标志位的 bit[23:0] */
  CEC_FLAG &= FLAG_Mask;
  
  if(cecreg != 0)
  {
    /* 标志位位于 CEC ESR 寄存器中 */
    CEC_FLAG = (uint32_t)(CEC_FLAG >> 16);
    
    /* 获取 CEC ESR 寄存器地址 */
    cecbase += 0xC;
  }
  else
  {
    /* 获取 CEC CSR 寄存器地址 */
    cecbase += 0x10;
  }
  
  if(((*(__IO uint32_t *)cecbase) & CEC_FLAG) != (uint32_t)RESET)
  {
    /* CEC_FLAG 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* CEC_FLAG 已复位 */
    bitstatus = RESET;
  }
  
  /* 返回 CEC_FLAG 状态 */
  return  bitstatus;
}

/**
  * @brief  清除 CEC 的挂起标志位。
  * @param  CEC_FLAG：指定要清除的标志位。 
  *   该参数可以是以下值的任意组合：
  *     @arg CEC_FLAG_TERR：发送错误
  *     @arg CEC_FLAG_TBTRF：发送字节传输请求或块传输完成
  *     @arg CEC_FLAG_RSOM：接收开始消息
  *     @arg CEC_FLAG_REOM：接收结束消息
  *     @arg CEC_FLAG_RERR：接收错误
  *     @arg CEC_FLAG_RBTF：接收字节/块传输完成
  * @retval 无
  */
void CEC_ClearFlag(uint32_t CEC_FLAG)
{ 
  uint32_t tmp = 0x0;
  
  /* 检查参数 */
  assert_param(IS_CEC_CLEAR_FLAG(CEC_FLAG));

  tmp = CEC->CSR & 0x2;
       
  /* 清除选定的 CEC 标志位 */
  CEC->CSR &= (uint32_t)(((~(uint32_t)CEC_FLAG) & 0xFFFFFFFC) | tmp);
}

/**
  * @brief  检查指定的 CEC 中断是否发生。
  * @param  CEC_IT：指定要检查的 CEC 中断源。 
  *   该参数可以是以下值之一：
  *     @arg CEC_IT_TERR：发送错误
  *     @arg CEC_IT_TBTF：发送块传输完成
  *     @arg CEC_IT_RERR：接收错误
  *     @arg CEC_IT_RBTF：接收块传输完成
  * @retval CEC_IT 的新状态（SET 或 RESET）。
  */
ITStatus CEC_GetITStatus(uint8_t CEC_IT)
{
  ITStatus bitstatus = RESET;
  uint32_t enablestatus = 0;
  
  /* 检查参数 */
   assert_param(IS_CEC_GET_IT(CEC_IT));
   
  /* 获取 CEC 中断使能位状态 */
  enablestatus = (CEC->CFGR & (uint8_t)CEC_CFGR_IE) ;
  
  /* 检查指定 CEC 中断的状态 */
  if (((CEC->CSR & CEC_IT) != (uint32_t)RESET) && enablestatus)
  {
    /* CEC_IT 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* CEC_IT 已复位 */
    bitstatus = RESET;
  }
  /* 返回 CEC_IT 状态 */
  return  bitstatus;
}

/**
  * @brief  清除 CEC 的中断挂起位。
  * @param  CEC_IT：指定要清除的 CEC 中断挂起位。
  *   该参数可以是以下值的任意组合：
  *     @arg CEC_IT_TERR：发送错误
  *     @arg CEC_IT_TBTF：发送块传输完成
  *     @arg CEC_IT_RERR：接收错误
  *     @arg CEC_IT_RBTF：接收块传输完成
  * @retval 无
  */
void CEC_ClearITPendingBit(uint16_t CEC_IT)
{
  uint32_t tmp = 0x0;
  
  /* 检查参数 */
  assert_param(IS_CEC_GET_IT(CEC_IT));
  
  tmp = CEC->CSR & 0x2;
  
  /* 清除选定的 CEC 中断挂起位 */
  CEC->CSR &= (uint32_t)(((~(uint32_t)CEC_IT) & 0xFFFFFFFC) | tmp);
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
