/**
  ******************************************************************************
  * @file    stm32f10x_can.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供所有 CAN 固件函数。
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
#include "stm32f10x_can.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup CAN 
  * @brief CAN 驱动模块
  * @{
  */ 

/** @defgroup CAN_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup CAN_Private_Defines
  * @{
  */

/* CAN 主控制寄存器位 */

#define MCR_DBF      ((uint32_t)0x00010000) /* 软件主复位 */

/* CAN 邮箱发送请求 */
#define TMIDxR_TXRQ  ((uint32_t)0x00000001) /* 发送邮箱请求 */

/* CAN 过滤器主寄存器位 */
#define FMR_FINIT    ((uint32_t)0x00000001) /* 过滤器初始化模式 */

/* INAK 位的超时时间 */
#define INAK_TIMEOUT        ((uint32_t)0x0000FFFF)
/* SLAK 位的超时时间 */
#define SLAK_TIMEOUT        ((uint32_t)0x0000FFFF)



/* TSR 寄存器中的标志位 */
#define CAN_FLAGS_TSR              ((uint32_t)0x08000000) 
/* RF1R 寄存器中的标志位 */
#define CAN_FLAGS_RF1R             ((uint32_t)0x04000000) 
/* RF0R 寄存器中的标志位 */
#define CAN_FLAGS_RF0R             ((uint32_t)0x02000000) 
/* MSR 寄存器中的标志位 */
#define CAN_FLAGS_MSR              ((uint32_t)0x01000000) 
/* ESR 寄存器中的标志位 */
#define CAN_FLAGS_ESR              ((uint32_t)0x00F00000) 

/* 邮箱定义 */
#define CAN_TXMAILBOX_0                   ((uint8_t)0x00)
#define CAN_TXMAILBOX_1                   ((uint8_t)0x01)
#define CAN_TXMAILBOX_2                   ((uint8_t)0x02) 



#define CAN_MODE_MASK              ((uint32_t) 0x00000003)
/**
  * @}
  */

/** @defgroup CAN_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup CAN_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup CAN_Private_FunctionPrototypes
  * @{
  */

static ITStatus CheckITStatus(uint32_t CAN_Reg, uint32_t It_Bit);

/**
  * @}
  */

/** @defgroup CAN_Private_Functions
  * @{
  */

/**
  * @brief  将 CAN 外设寄存器复位为默认值。
  * @param  CANx: x 可为 1 或 2，用于选择 CAN 外设。
  * @retval 无。
  */
void CAN_DeInit(CAN_TypeDef* CANx)
{
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
 
  if (CANx == CAN1)
  {
    /* 使能 CAN1 复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_CAN1, ENABLE);
    /* 释放 CAN1 复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_CAN1, DISABLE);
  }
  else
  {  
    /* 使能 CAN2 复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_CAN2, ENABLE);
    /* 释放 CAN2 复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_CAN2, DISABLE);
  }
}

/**
  * @brief  根据指定的参数初始化 CAN 外设，
  *         这些参数位于 CAN_InitStruct 中。
  * @param  CANx:           x 可为 1 或 2，用于选择 CAN 
  *                         外设。
  * @param  CAN_InitStruct: 指向 CAN_InitTypeDef 结构的指针，
  *                         其中包含 
  *                         CAN 外设的配置信息。
  * @retval 返回值表示初始化成功，为 
  *         CAN_InitStatus_Failed 或 CAN_InitStatus_Success。
  */
uint8_t CAN_Init(CAN_TypeDef* CANx, CAN_InitTypeDef* CAN_InitStruct)
{
  uint8_t InitStatus = CAN_InitStatus_Failed;
  uint32_t wait_ack = 0x00000000;
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_TTCM));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_ABOM));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_AWUM));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_NART));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_RFLM));
  assert_param(IS_FUNCTIONAL_STATE(CAN_InitStruct->CAN_TXFP));
  assert_param(IS_CAN_MODE(CAN_InitStruct->CAN_Mode));
  assert_param(IS_CAN_SJW(CAN_InitStruct->CAN_SJW));
  assert_param(IS_CAN_BS1(CAN_InitStruct->CAN_BS1));
  assert_param(IS_CAN_BS2(CAN_InitStruct->CAN_BS2));
  assert_param(IS_CAN_PRESCALER(CAN_InitStruct->CAN_Prescaler));

  /* 退出睡眠模式 */
  CANx->MCR &= (~(uint32_t)CAN_MCR_SLEEP);

  /* 请求初始化 */
  CANx->MCR |= CAN_MCR_INRQ ;

  /* 等待应答 */
  while (((CANx->MSR & CAN_MSR_INAK) != CAN_MSR_INAK) && (wait_ack != INAK_TIMEOUT))
  {
    wait_ack++;
  }

  /* 检查应答 */
  if ((CANx->MSR & CAN_MSR_INAK) != CAN_MSR_INAK)
  {
    InitStatus = CAN_InitStatus_Failed;
  }
  else 
  {
    /* 设置时间触发通信模式 */
    if (CAN_InitStruct->CAN_TTCM == ENABLE)
    {
      CANx->MCR |= CAN_MCR_TTCM;
    }
    else
    {
      CANx->MCR &= ~(uint32_t)CAN_MCR_TTCM;
    }

    /* 设置自动总线关闭管理 */
    if (CAN_InitStruct->CAN_ABOM == ENABLE)
    {
      CANx->MCR |= CAN_MCR_ABOM;
    }
    else
    {
      CANx->MCR &= ~(uint32_t)CAN_MCR_ABOM;
    }

    /* 设置自动唤醒模式 */
    if (CAN_InitStruct->CAN_AWUM == ENABLE)
    {
      CANx->MCR |= CAN_MCR_AWUM;
    }
    else
    {
      CANx->MCR &= ~(uint32_t)CAN_MCR_AWUM;
    }

    /* 设置非自动重传 */
    if (CAN_InitStruct->CAN_NART == ENABLE)
    {
      CANx->MCR |= CAN_MCR_NART;
    }
    else
    {
      CANx->MCR &= ~(uint32_t)CAN_MCR_NART;
    }

    /* 设置接收 FIFO 锁定模式 */
    if (CAN_InitStruct->CAN_RFLM == ENABLE)
    {
      CANx->MCR |= CAN_MCR_RFLM;
    }
    else
    {
      CANx->MCR &= ~(uint32_t)CAN_MCR_RFLM;
    }

    /* 设置发送 FIFO 优先级 */
    if (CAN_InitStruct->CAN_TXFP == ENABLE)
    {
      CANx->MCR |= CAN_MCR_TXFP;
    }
    else
    {
      CANx->MCR &= ~(uint32_t)CAN_MCR_TXFP;
    }

    /* 设置位定时寄存器 */
    CANx->BTR = (uint32_t)((uint32_t)CAN_InitStruct->CAN_Mode << 30) | \
                ((uint32_t)CAN_InitStruct->CAN_SJW << 24) | \
                ((uint32_t)CAN_InitStruct->CAN_BS1 << 16) | \
                ((uint32_t)CAN_InitStruct->CAN_BS2 << 20) | \
               ((uint32_t)CAN_InitStruct->CAN_Prescaler - 1);

    /* 请求退出初始化 */
    CANx->MCR &= ~(uint32_t)CAN_MCR_INRQ;

   /* 等待应答 */
   wait_ack = 0;

   while (((CANx->MSR & CAN_MSR_INAK) == CAN_MSR_INAK) && (wait_ack != INAK_TIMEOUT))
   {
     wait_ack++;
   }

    /* ...并检查应答 */
    if ((CANx->MSR & CAN_MSR_INAK) == CAN_MSR_INAK)
    {
      InitStatus = CAN_InitStatus_Failed;
    }
    else
    {
      InitStatus = CAN_InitStatus_Success ;
    }
  }

  /* 此时返回初始化状态 */
  return InitStatus;
}

/**
  * @brief  根据指定的参数初始化 CAN 外设，
  *         这些参数位于 CAN_FilterInitStruct 中。
  * @param  CAN_FilterInitStruct: 指向 CAN_FilterInitTypeDef
  *                               结构的指针，其中包含配置 
  *                               信息。
  * @retval 无。
  */
void CAN_FilterInit(CAN_FilterInitTypeDef* CAN_FilterInitStruct)
{
  uint32_t filter_number_bit_pos = 0;
  /* 检查参数 */
  assert_param(IS_CAN_FILTER_NUMBER(CAN_FilterInitStruct->CAN_FilterNumber));
  assert_param(IS_CAN_FILTER_MODE(CAN_FilterInitStruct->CAN_FilterMode));
  assert_param(IS_CAN_FILTER_SCALE(CAN_FilterInitStruct->CAN_FilterScale));
  assert_param(IS_CAN_FILTER_FIFO(CAN_FilterInitStruct->CAN_FilterFIFOAssignment));
  assert_param(IS_FUNCTIONAL_STATE(CAN_FilterInitStruct->CAN_FilterActivation));

  filter_number_bit_pos = ((uint32_t)1) << CAN_FilterInitStruct->CAN_FilterNumber;

  /* 过滤器的初始化模式 */
  CAN1->FMR |= FMR_FINIT;

  /* 失能过滤器 */
  CAN1->FA1R &= ~(uint32_t)filter_number_bit_pos;

  /* 过滤器位宽 */
  if (CAN_FilterInitStruct->CAN_FilterScale == CAN_FilterScale_16bit)
  {
    /* 过滤器的 16 位位宽 */
    CAN1->FS1R &= ~(uint32_t)filter_number_bit_pos;

    /* 第一个 16 位标识符和第一个 16 位屏蔽值 */
    /* 或第一个 16 位标识符和第二个 16 位标识符 */
    CAN1->sFilterRegister[CAN_FilterInitStruct->CAN_FilterNumber].FR1 = 
    ((0x0000FFFF & (uint32_t)CAN_FilterInitStruct->CAN_FilterMaskIdLow) << 16) |
        (0x0000FFFF & (uint32_t)CAN_FilterInitStruct->CAN_FilterIdLow);

    /* 第二个 16 位标识符和第二个 16 位屏蔽值 */
    /* 或第三个 16 位标识符和第四个 16 位标识符 */
    CAN1->sFilterRegister[CAN_FilterInitStruct->CAN_FilterNumber].FR2 = 
    ((0x0000FFFF & (uint32_t)CAN_FilterInitStruct->CAN_FilterMaskIdHigh) << 16) |
        (0x0000FFFF & (uint32_t)CAN_FilterInitStruct->CAN_FilterIdHigh);
  }

  if (CAN_FilterInitStruct->CAN_FilterScale == CAN_FilterScale_32bit)
  {
    /* 过滤器的 32 位位宽 */
    CAN1->FS1R |= filter_number_bit_pos;
    /* 32 位标识符或第一个 32 位标识符 */
    CAN1->sFilterRegister[CAN_FilterInitStruct->CAN_FilterNumber].FR1 = 
    ((0x0000FFFF & (uint32_t)CAN_FilterInitStruct->CAN_FilterIdHigh) << 16) |
        (0x0000FFFF & (uint32_t)CAN_FilterInitStruct->CAN_FilterIdLow);
    /* 32 位屏蔽值或第二个 32 位标识符 */
    CAN1->sFilterRegister[CAN_FilterInitStruct->CAN_FilterNumber].FR2 = 
    ((0x0000FFFF & (uint32_t)CAN_FilterInitStruct->CAN_FilterMaskIdHigh) << 16) |
        (0x0000FFFF & (uint32_t)CAN_FilterInitStruct->CAN_FilterMaskIdLow);
  }

  /* 过滤器模式 */
  if (CAN_FilterInitStruct->CAN_FilterMode == CAN_FilterMode_IdMask)
  {
    /*过滤器的标识符/屏蔽位模式*/
    CAN1->FM1R &= ~(uint32_t)filter_number_bit_pos;
  }
  else /* CAN_FilterInitStruct->CAN_FilterMode == CAN_FilterMode_IdList */
  {
    /*过滤器的标识符列表模式*/
    CAN1->FM1R |= (uint32_t)filter_number_bit_pos;
  }

  /* 过滤器 FIFO 分配 */
  if (CAN_FilterInitStruct->CAN_FilterFIFOAssignment == CAN_Filter_FIFO0)
  {
    /* 将过滤器分配给 FIFO 0 */
    CAN1->FFA1R &= ~(uint32_t)filter_number_bit_pos;
  }

  if (CAN_FilterInitStruct->CAN_FilterFIFOAssignment == CAN_Filter_FIFO1)
  {
    /* 将过滤器分配给 FIFO 1 */
    CAN1->FFA1R |= (uint32_t)filter_number_bit_pos;
  }
  
  /* 使能过滤器 */
  if (CAN_FilterInitStruct->CAN_FilterActivation == ENABLE)
  {
    CAN1->FA1R |= filter_number_bit_pos;
  }

  /* 退出过滤器的初始化模式 */
  CAN1->FMR &= ~FMR_FINIT;
}

/**
  * @brief  将 CAN_InitStruct 的每个成员填充为默认值。
  * @param  CAN_InitStruct: 指向 CAN_InitTypeDef 结构的指针，
  *                         该结构将被初始化。
  * @retval 无。
  */
void CAN_StructInit(CAN_InitTypeDef* CAN_InitStruct)
{
  /* 复位 CAN 初始化结构体参数值 */
  
  /* 初始化时间触发通信模式 */
  CAN_InitStruct->CAN_TTCM = DISABLE;
  
  /* 初始化自动总线关闭管理 */
  CAN_InitStruct->CAN_ABOM = DISABLE;
  
  /* 初始化自动唤醒模式 */
  CAN_InitStruct->CAN_AWUM = DISABLE;
  
  /* 初始化非自动重传 */
  CAN_InitStruct->CAN_NART = DISABLE;
  
  /* 初始化接收 FIFO 锁定模式 */
  CAN_InitStruct->CAN_RFLM = DISABLE;
  
  /* 初始化发送 FIFO 优先级 */
  CAN_InitStruct->CAN_TXFP = DISABLE;
  
  /* 初始化 CAN_Mode 成员 */
  CAN_InitStruct->CAN_Mode = CAN_Mode_Normal;
  
  /* 初始化 CAN_SJW 成员 */
  CAN_InitStruct->CAN_SJW = CAN_SJW_1tq;
  
  /* 初始化 CAN_BS1 成员 */
  CAN_InitStruct->CAN_BS1 = CAN_BS1_4tq;
  
  /* 初始化 CAN_BS2 成员 */
  CAN_InitStruct->CAN_BS2 = CAN_BS2_3tq;
  
  /* 初始化 CAN_Prescaler 成员 */
  CAN_InitStruct->CAN_Prescaler = 1;
}

/**
  * @brief  选择从 CAN 的起始过滤组。
  * @note   本函数仅适用于 STM32 互联型器件。
  * @param  CAN_BankNumber: 选择从机起始过滤组，范围为 1..27。
  * @retval 无。
  */
void CAN_SlaveStartBank(uint8_t CAN_BankNumber) 
{
  /* 检查参数 */
  assert_param(IS_CAN_BANKNUMBER(CAN_BankNumber));
  
  /* 进入过滤器的初始化模式 */
  CAN1->FMR |= FMR_FINIT;
  
  /* 选择起始从机过滤组 */
  CAN1->FMR &= (uint32_t)0xFFFFC0F1 ;
  CAN1->FMR |= (uint32_t)(CAN_BankNumber)<<8;
  
  /* 退出过滤器的初始化模式 */
  CAN1->FMR &= ~FMR_FINIT;
}

/**
  * @brief  使能或失能 CAN 的调试冻结功能。
  * @param  CANx:     x 可为 1 或 2，用于选择 CAN 外设。
  * @param  NewState: CAN 外设的新状态。该参数可 
  *                   为：ENABLE 或 DISABLE。
  * @retval 无。
  */
void CAN_DBGFreeze(CAN_TypeDef* CANx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  
  if (NewState != DISABLE)
  {
    /* 使能调试冻结  */
    CANx->MCR |= MCR_DBF;
  }
  else
  {
    /* 失能调试冻结 */
    CANx->MCR &= ~MCR_DBF;
  }
}


/**
  * @brief  使能或失能 CAN 时间触发通信模式。
  * @param  CANx:      x 可为 1 或 2，用于选择 CAN 外设。
  * @param  NewState : 模式的新状态，可为 @ref FunctionalState 之一。
  * @note   使能后，时间戳（TIME[15:0]）的值将在 8 字节报文的最后 
  *         两个数据字节中发送：TIME[7:0] 位于数据字节 6， 
  *         TIME[15:8] 位于数据字节 7 
  * @note   DLC 必须编程为 8，时间戳（2 字节）才能 
  *         通过 CAN 总线发送。  
  * @retval 无
  */
void CAN_TTComModeCmd(CAN_TypeDef* CANx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能 TTCM 模式 */
    CANx->MCR |= CAN_MCR_TTCM;

    /* 设置 TGT 位 */
    CANx->sTxMailBox[0].TDTR |= ((uint32_t)CAN_TDT0R_TGT);
    CANx->sTxMailBox[1].TDTR |= ((uint32_t)CAN_TDT1R_TGT);
    CANx->sTxMailBox[2].TDTR |= ((uint32_t)CAN_TDT2R_TGT);
  }
  else
  {
    /* 失能 TTCM 模式 */
    CANx->MCR &= (uint32_t)(~(uint32_t)CAN_MCR_TTCM);

    /* 复位 TGT 位 */
    CANx->sTxMailBox[0].TDTR &= ((uint32_t)~CAN_TDT0R_TGT);
    CANx->sTxMailBox[1].TDTR &= ((uint32_t)~CAN_TDT1R_TGT);
    CANx->sTxMailBox[2].TDTR &= ((uint32_t)~CAN_TDT2R_TGT);
  }
}
/**
  * @brief  启动报文发送。
  * @param  CANx:      x 可为 1 或 2，用于选择 CAN 外设。
  * @param  TxMessage: 指向包含 CAN 标识符、CAN
  *                    DLC 和 CAN 数据的结构的指针。
  * @retval 用于发送的邮箱编号，
  *                    如果没有空邮箱则为 CAN_TxStatus_NoMailBox。
  */
uint8_t CAN_Transmit(CAN_TypeDef* CANx, CanTxMsg* TxMessage)
{
  uint8_t transmit_mailbox = 0;
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_IDTYPE(TxMessage->IDE));
  assert_param(IS_CAN_RTR(TxMessage->RTR));
  assert_param(IS_CAN_DLC(TxMessage->DLC));

  /* 选择一个空的发送邮箱 */
  if ((CANx->TSR&CAN_TSR_TME0) == CAN_TSR_TME0)
  {
    transmit_mailbox = 0;
  }
  else if ((CANx->TSR&CAN_TSR_TME1) == CAN_TSR_TME1)
  {
    transmit_mailbox = 1;
  }
  else if ((CANx->TSR&CAN_TSR_TME2) == CAN_TSR_TME2)
  {
    transmit_mailbox = 2;
  }
  else
  {
    transmit_mailbox = CAN_TxStatus_NoMailBox;
  }

  if (transmit_mailbox != CAN_TxStatus_NoMailBox)
  {
    /* 设置标识符 */
    CANx->sTxMailBox[transmit_mailbox].TIR &= TMIDxR_TXRQ;
    if (TxMessage->IDE == CAN_Id_Standard)
    {
      assert_param(IS_CAN_STDID(TxMessage->StdId));  
      CANx->sTxMailBox[transmit_mailbox].TIR |= ((TxMessage->StdId << 21) | \
                                                  TxMessage->RTR);
    }
    else
    {
      assert_param(IS_CAN_EXTID(TxMessage->ExtId));
      CANx->sTxMailBox[transmit_mailbox].TIR |= ((TxMessage->ExtId << 3) | \
                                                  TxMessage->IDE | \
                                                  TxMessage->RTR);
    }
    
    /* 设置 DLC */
    TxMessage->DLC &= (uint8_t)0x0000000F;
    CANx->sTxMailBox[transmit_mailbox].TDTR &= (uint32_t)0xFFFFFFF0;
    CANx->sTxMailBox[transmit_mailbox].TDTR |= TxMessage->DLC;

    /* 设置数据字段 */
    CANx->sTxMailBox[transmit_mailbox].TDLR = (((uint32_t)TxMessage->Data[3] << 24) | 
                                             ((uint32_t)TxMessage->Data[2] << 16) |
                                             ((uint32_t)TxMessage->Data[1] << 8) | 
                                             ((uint32_t)TxMessage->Data[0]));
    CANx->sTxMailBox[transmit_mailbox].TDHR = (((uint32_t)TxMessage->Data[7] << 24) | 
                                             ((uint32_t)TxMessage->Data[6] << 16) |
                                             ((uint32_t)TxMessage->Data[5] << 8) |
                                             ((uint32_t)TxMessage->Data[4]));
    /* 请求发送 */
    CANx->sTxMailBox[transmit_mailbox].TIR |= TMIDxR_TXRQ;
  }
  return transmit_mailbox;
}

/**
  * @brief  检查报文的发送情况。
  * @param  CANx:            x 可为 1 或 2，用于选择 
  *                          CAN 外设。
  * @param  TransmitMailbox: 用于发送的邮箱编号，即 
  *                          传输所使用的邮箱。
  * @retval 如果 CAN 驱动成功发送报文则返回 CAN_TxStatus_Ok， 
  *         否则返回 CAN_TxStatus_Failed。
  */
uint8_t CAN_TransmitStatus(CAN_TypeDef* CANx, uint8_t TransmitMailbox)
{
  uint32_t state = 0;

  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_TRANSMITMAILBOX(TransmitMailbox));
 
  switch (TransmitMailbox)
  {
    case (CAN_TXMAILBOX_0): 
      state =   CANx->TSR &  (CAN_TSR_RQCP0 | CAN_TSR_TXOK0 | CAN_TSR_TME0);
      break;
    case (CAN_TXMAILBOX_1): 
      state =   CANx->TSR &  (CAN_TSR_RQCP1 | CAN_TSR_TXOK1 | CAN_TSR_TME1);
      break;
    case (CAN_TXMAILBOX_2): 
      state =   CANx->TSR &  (CAN_TSR_RQCP2 | CAN_TSR_TXOK2 | CAN_TSR_TME2);
      break;
    default:
      state = CAN_TxStatus_Failed;
      break;
  }
  switch (state)
  {
      /* 发送挂起  */
    case (0x0): state = CAN_TxStatus_Pending;
      break;
      /* 发送失败  */
     case (CAN_TSR_RQCP0 | CAN_TSR_TME0): state = CAN_TxStatus_Failed;
      break;
     case (CAN_TSR_RQCP1 | CAN_TSR_TME1): state = CAN_TxStatus_Failed;
      break;
     case (CAN_TSR_RQCP2 | CAN_TSR_TME2): state = CAN_TxStatus_Failed;
      break;
      /* 发送成功  */
    case (CAN_TSR_RQCP0 | CAN_TSR_TXOK0 | CAN_TSR_TME0):state = CAN_TxStatus_Ok;
      break;
    case (CAN_TSR_RQCP1 | CAN_TSR_TXOK1 | CAN_TSR_TME1):state = CAN_TxStatus_Ok;
      break;
    case (CAN_TSR_RQCP2 | CAN_TSR_TXOK2 | CAN_TSR_TME2):state = CAN_TxStatus_Ok;
      break;
    default: state = CAN_TxStatus_Failed;
      break;
  }
  return (uint8_t) state;
}

/**
  * @brief  取消发送请求。
  * @param  CANx:     x 可为 1 或 2，用于选择 CAN 外设。 
  * @param  Mailbox:  邮箱编号。
  * @retval 无。
  */
void CAN_CancelTransmit(CAN_TypeDef* CANx, uint8_t Mailbox)
{
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_TRANSMITMAILBOX(Mailbox));
  /* 中止发送 */
  switch (Mailbox)
  {
    case (CAN_TXMAILBOX_0): CANx->TSR |= CAN_TSR_ABRQ0;
      break;
    case (CAN_TXMAILBOX_1): CANx->TSR |= CAN_TSR_ABRQ1;
      break;
    case (CAN_TXMAILBOX_2): CANx->TSR |= CAN_TSR_ABRQ2;
      break;
    default:
      break;
  }
}


/**
  * @brief  接收报文。
  * @param  CANx:       x 可为 1 或 2，用于选择 CAN 外设。
  * @param  FIFONumber: 接收 FIFO 编号，CAN_FIFO0 或 CAN_FIFO1。
  * @param  RxMessage:  指向接收报文结构的指针，其中包含 
  *                     CAN 标识符、CAN DLC、CAN 数据和 FMI 编号。
  * @retval 无。
  */
void CAN_Receive(CAN_TypeDef* CANx, uint8_t FIFONumber, CanRxMsg* RxMessage)
{
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_FIFO(FIFONumber));
  /* 获取标识符 */
  RxMessage->IDE = (uint8_t)0x04 & CANx->sFIFOMailBox[FIFONumber].RIR;
  if (RxMessage->IDE == CAN_Id_Standard)
  {
    RxMessage->StdId = (uint32_t)0x000007FF & (CANx->sFIFOMailBox[FIFONumber].RIR >> 21);
  }
  else
  {
    RxMessage->ExtId = (uint32_t)0x1FFFFFFF & (CANx->sFIFOMailBox[FIFONumber].RIR >> 3);
  }
  
  RxMessage->RTR = (uint8_t)0x02 & CANx->sFIFOMailBox[FIFONumber].RIR;
  /* 获取 DLC */
  RxMessage->DLC = (uint8_t)0x0F & CANx->sFIFOMailBox[FIFONumber].RDTR;
  /* 获取 FMI */
  RxMessage->FMI = (uint8_t)0xFF & (CANx->sFIFOMailBox[FIFONumber].RDTR >> 8);
  /* 获取数据字段 */
  RxMessage->Data[0] = (uint8_t)0xFF & CANx->sFIFOMailBox[FIFONumber].RDLR;
  RxMessage->Data[1] = (uint8_t)0xFF & (CANx->sFIFOMailBox[FIFONumber].RDLR >> 8);
  RxMessage->Data[2] = (uint8_t)0xFF & (CANx->sFIFOMailBox[FIFONumber].RDLR >> 16);
  RxMessage->Data[3] = (uint8_t)0xFF & (CANx->sFIFOMailBox[FIFONumber].RDLR >> 24);
  RxMessage->Data[4] = (uint8_t)0xFF & CANx->sFIFOMailBox[FIFONumber].RDHR;
  RxMessage->Data[5] = (uint8_t)0xFF & (CANx->sFIFOMailBox[FIFONumber].RDHR >> 8);
  RxMessage->Data[6] = (uint8_t)0xFF & (CANx->sFIFOMailBox[FIFONumber].RDHR >> 16);
  RxMessage->Data[7] = (uint8_t)0xFF & (CANx->sFIFOMailBox[FIFONumber].RDHR >> 24);
  /* 释放 FIFO */
  /* 释放 FIFO0 */
  if (FIFONumber == CAN_FIFO0)
  {
    CANx->RF0R |= CAN_RF0R_RFOM0;
  }
  /* 释放 FIFO1 */
  else /* FIFONumber == CAN_FIFO1 */
  {
    CANx->RF1R |= CAN_RF1R_RFOM1;
  }
}

/**
  * @brief  释放指定的 FIFO。
  * @param  CANx:       x 可为 1 或 2，用于选择 CAN 外设。 
  * @param  FIFONumber: 要释放的 FIFO，CAN_FIFO0 或 CAN_FIFO1。
  * @retval 无。
  */
void CAN_FIFORelease(CAN_TypeDef* CANx, uint8_t FIFONumber)
{
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_FIFO(FIFONumber));
  /* 释放 FIFO0 */
  if (FIFONumber == CAN_FIFO0)
  {
    CANx->RF0R |= CAN_RF0R_RFOM0;
  }
  /* 释放 FIFO1 */
  else /* FIFONumber == CAN_FIFO1 */
  {
    CANx->RF1R |= CAN_RF1R_RFOM1;
  }
}

/**
  * @brief  返回挂起报文的数量。
  * @param  CANx:       x 可为 1 或 2，用于选择 CAN 外设。
  * @param  FIFONumber: 接收 FIFO 编号，CAN_FIFO0 或 CAN_FIFO1。
  * @retval NbMessage : 挂起报文的数量。
  */
uint8_t CAN_MessagePending(CAN_TypeDef* CANx, uint8_t FIFONumber)
{
  uint8_t message_pending=0;
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_FIFO(FIFONumber));
  if (FIFONumber == CAN_FIFO0)
  {
    message_pending = (uint8_t)(CANx->RF0R&(uint32_t)0x03);
  }
  else if (FIFONumber == CAN_FIFO1)
  {
    message_pending = (uint8_t)(CANx->RF1R&(uint32_t)0x03);
  }
  else
  {
    message_pending = 0;
  }
  return message_pending;
}


/**
  * @brief   选择 CAN 工作模式。
  * @param CAN_OperatingMode : CAN 工作模式。该参数可为 
  *                            @ref CAN_OperatingMode_TypeDef 枚举中的值之一。
  * @retval 所请求模式的状态，可为 
  *         - CAN_ModeStatus_Failed    CAN 进入指定模式失败 
  *         - CAN_ModeStatus_Success   CAN 进入指定模式成功 

  */
uint8_t CAN_OperatingModeRequest(CAN_TypeDef* CANx, uint8_t CAN_OperatingMode)
{
  uint8_t status = CAN_ModeStatus_Failed;
  
  /* INAK 或 SLAK 位的超时时间*/
  uint32_t timeout = INAK_TIMEOUT; 

  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_OPERATING_MODE(CAN_OperatingMode));

  if (CAN_OperatingMode == CAN_OperatingMode_Initialization)
  {
    /* 请求初始化 */
    CANx->MCR = (uint32_t)((CANx->MCR & (uint32_t)(~(uint32_t)CAN_MCR_SLEEP)) | CAN_MCR_INRQ);

    /* 等待应答 */
    while (((CANx->MSR & CAN_MODE_MASK) != CAN_MSR_INAK) && (timeout != 0))
    {
      timeout--;
    }
    if ((CANx->MSR & CAN_MODE_MASK) != CAN_MSR_INAK)
    {
      status = CAN_ModeStatus_Failed;
    }
    else
    {
      status = CAN_ModeStatus_Success;
    }
  }
  else  if (CAN_OperatingMode == CAN_OperatingMode_Normal)
  {
    /* 请求退出初始化和睡眠模式，并进入正常模式 */
    CANx->MCR &= (uint32_t)(~(CAN_MCR_SLEEP|CAN_MCR_INRQ));

    /* 等待应答 */
    while (((CANx->MSR & CAN_MODE_MASK) != 0) && (timeout!=0))
    {
      timeout--;
    }
    if ((CANx->MSR & CAN_MODE_MASK) != 0)
    {
      status = CAN_ModeStatus_Failed;
    }
    else
    {
      status = CAN_ModeStatus_Success;
    }
  }
  else  if (CAN_OperatingMode == CAN_OperatingMode_Sleep)
  {
    /* 请求睡眠模式 */
    CANx->MCR = (uint32_t)((CANx->MCR & (uint32_t)(~(uint32_t)CAN_MCR_INRQ)) | CAN_MCR_SLEEP);

    /* 等待应答 */
    while (((CANx->MSR & CAN_MODE_MASK) != CAN_MSR_SLAK) && (timeout!=0))
    {
      timeout--;
    }
    if ((CANx->MSR & CAN_MODE_MASK) != CAN_MSR_SLAK)
    {
      status = CAN_ModeStatus_Failed;
    }
    else
    {
      status = CAN_ModeStatus_Success;
    }
  }
  else
  {
    status = CAN_ModeStatus_Failed;
  }

  return  (uint8_t) status;
}

/**
  * @brief  进入低功耗模式。
  * @param  CANx:   x 可为 1 或 2，用于选择 CAN 外设。
  * @retval 状态: 如果进入睡眠模式则返回 CAN_Sleep_Ok， 
  *                 否则返回失败状态。
  */
uint8_t CAN_Sleep(CAN_TypeDef* CANx)
{
  uint8_t sleepstatus = CAN_Sleep_Failed;
  
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
    
  /* 请求睡眠模式 */
   CANx->MCR = (((CANx->MCR) & (uint32_t)(~(uint32_t)CAN_MCR_INRQ)) | CAN_MCR_SLEEP);
   
  /* 睡眠模式状态 */
  if ((CANx->MSR & (CAN_MSR_SLAK|CAN_MSR_INAK)) == CAN_MSR_SLAK)
  {
    /* 未进入睡眠模式 */
    sleepstatus =  CAN_Sleep_Ok;
  }
  /* 返回睡眠模式状态 */
   return (uint8_t)sleepstatus;
}

/**
  * @brief  唤醒 CAN。
  * @param  CANx:    x 可为 1 或 2，用于选择 CAN 外设。
  * @retval 状态:  如果退出睡眠模式则返回 CAN_WakeUp_Ok， 
  *                  否则返回失败状态。
  */
uint8_t CAN_WakeUp(CAN_TypeDef* CANx)
{
  uint32_t wait_slak = SLAK_TIMEOUT;
  uint8_t wakeupstatus = CAN_WakeUp_Failed;
  
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
    
  /* 唤醒请求 */
  CANx->MCR &= ~(uint32_t)CAN_MCR_SLEEP;
    
  /* 睡眠模式状态 */
  while(((CANx->MSR & CAN_MSR_SLAK) == CAN_MSR_SLAK)&&(wait_slak!=0x00))
  {
   wait_slak--;
  }
  if((CANx->MSR & CAN_MSR_SLAK) != CAN_MSR_SLAK)
  {
   /* 唤醒完成：已退出睡眠模式 */
    wakeupstatus = CAN_WakeUp_Ok;
  }
  /* 返回唤醒状态 */
  return (uint8_t)wakeupstatus;
}


/**
  * @brief  返回 CANx 的最后错误代码（LEC）。
  * @param  CANx:          x 可为 1 或 2，用于选择 CAN 外设。  
  * @retval CAN_ErrorCode: 指定错误代码： 
  *                        - CAN_ERRORCODE_NoErr            无错误  
  *                        - CAN_ERRORCODE_StuffErr         填充错误
  *                        - CAN_ERRORCODE_FormErr          格式错误
  *                        - CAN_ERRORCODE_ACKErr           应答错误
  *                        - CAN_ERRORCODE_BitRecessiveErr  隐性位错误
  *                        - CAN_ERRORCODE_BitDominantErr   显性位错误
  *                        - CAN_ERRORCODE_CRCErr           CRC 错误
  *                        - CAN_ERRORCODE_SoftwareSetErr   软件设置错误  
  */
 
uint8_t CAN_GetLastErrorCode(CAN_TypeDef* CANx)
{
  uint8_t errorcode=0;
  
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  
  /* 获取错误代码*/
  errorcode = (((uint8_t)CANx->ESR) & (uint8_t)CAN_ESR_LEC);
  
  /* 返回错误代码*/
  return errorcode;
}
/**
  * @brief  返回 CANx 的接收错误计数器（REC）。
  * @note   如果在接收过程中发生错误，该计数器将 
  *         根据 CAN 标准定义的错误情况加 1 或加 8。 
  *         每次成功接收后，该计数器将 
  *         减 1；如果其值大于 128，则复位为 120。 
  *         当计数器值超过 127 时，CAN 控制器进入 
  *         错误被动状态。  
  * @param  CANx: x 可为 1 或 2，用于选择 CAN 外设。  
  * @retval CAN 接收错误计数器。 
  */
uint8_t CAN_GetReceiveErrorCounter(CAN_TypeDef* CANx)
{
  uint8_t counter=0;
  
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  
  /* 获取接收错误计数器*/
  counter = (uint8_t)((CANx->ESR & CAN_ESR_REC)>> 24);
  
  /* 返回接收错误计数器*/
  return counter;
}


/**
  * @brief  返回 9 位 CANx 发送错误计数器（TEC）的 LSB。
  * @param  CANx:   x 可为 1 或 2，用于选择 CAN 外设。  
  * @retval 9 位 CAN 发送错误计数器的 LSB。 
  */
uint8_t CAN_GetLSBTransmitErrorCounter(CAN_TypeDef* CANx)
{
  uint8_t counter=0;
  
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  
  /* 获取 9 位 CANx 发送错误计数器（TEC）的 LSB */
  counter = (uint8_t)((CANx->ESR & CAN_ESR_TEC)>> 16);
  
  /* 返回 9 位 CANx 发送错误计数器（TEC）的 LSB */
  return counter;
}


/**
  * @brief  使能或失能指定的 CANx 中断。
  * @param  CANx:   x 可为 1 或 2，用于选择 CAN 外设。
  * @param  CAN_IT: 指定要使能或失能的 CAN 中断源。
  *                 该参数可为： 
  *                 - CAN_IT_TME, 
  *                 - CAN_IT_FMP0, 
  *                 - CAN_IT_FF0,
  *                 - CAN_IT_FOV0, 
  *                 - CAN_IT_FMP1, 
  *                 - CAN_IT_FF1,
  *                 - CAN_IT_FOV1, 
  *                 - CAN_IT_EWG, 
  *                 - CAN_IT_EPV,
  *                 - CAN_IT_LEC, 
  *                 - CAN_IT_ERR, 
  *                 - CAN_IT_WKU or 
  *                 - CAN_IT_SLK.
  * @param  NewState: CAN 中断的新状态。
  *                   该参数可为：ENABLE 或 DISABLE。
  * @retval 无。
  */
void CAN_ITConfig(CAN_TypeDef* CANx, uint32_t CAN_IT, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_IT(CAN_IT));
  assert_param(IS_FUNCTIONAL_STATE(NewState));

  if (NewState != DISABLE)
  {
    /* 使能选定的 CANx 中断 */
    CANx->IER |= CAN_IT;
  }
  else
  {
    /* 失能选定的 CANx 中断 */
    CANx->IER &= ~CAN_IT;
  }
}
/**
  * @brief  检查指定的 CAN 标志位是否置位。
  * @param  CANx:     x 可为 1 或 2，用于选择 CAN 外设。
  * @param  CAN_FLAG: 指定要检查的标志位。
  *                   该参数可为以下标志位之一： 
  *                  - CAN_FLAG_EWG
  *                  - CAN_FLAG_EPV 
  *                  - CAN_FLAG_BOF
  *                  - CAN_FLAG_RQCP0
  *                  - CAN_FLAG_RQCP1
  *                  - CAN_FLAG_RQCP2
  *                  - CAN_FLAG_FMP1   
  *                  - CAN_FLAG_FF1       
  *                  - CAN_FLAG_FOV1   
  *                  - CAN_FLAG_FMP0   
  *                  - CAN_FLAG_FF0       
  *                  - CAN_FLAG_FOV0   
  *                  - CAN_FLAG_WKU 
  *                  - CAN_FLAG_SLAK  
  *                  - CAN_FLAG_LEC       
  * @retval CAN_FLAG 的新状态（SET 或 RESET）。
  */
FlagStatus CAN_GetFlagStatus(CAN_TypeDef* CANx, uint32_t CAN_FLAG)
{
  FlagStatus bitstatus = RESET;
  
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_GET_FLAG(CAN_FLAG));
  

  if((CAN_FLAG & CAN_FLAGS_ESR) != (uint32_t)RESET)
  { 
    /* 检查指定 CAN 标志位的状态 */
    if ((CANx->ESR & (CAN_FLAG & 0x000FFFFF)) != (uint32_t)RESET)
    { 
      /* CAN_FLAG 已置位 */
      bitstatus = SET;
    }
    else
    { 
      /* CAN_FLAG 已复位 */
      bitstatus = RESET;
    }
  }
  else if((CAN_FLAG & CAN_FLAGS_MSR) != (uint32_t)RESET)
  { 
    /* 检查指定 CAN 标志位的状态 */
    if ((CANx->MSR & (CAN_FLAG & 0x000FFFFF)) != (uint32_t)RESET)
    { 
      /* CAN_FLAG 已置位 */
      bitstatus = SET;
    }
    else
    { 
      /* CAN_FLAG 已复位 */
      bitstatus = RESET;
    }
  }
  else if((CAN_FLAG & CAN_FLAGS_TSR) != (uint32_t)RESET)
  { 
    /* 检查指定 CAN 标志位的状态 */
    if ((CANx->TSR & (CAN_FLAG & 0x000FFFFF)) != (uint32_t)RESET)
    { 
      /* CAN_FLAG 已置位 */
      bitstatus = SET;
    }
    else
    { 
      /* CAN_FLAG 已复位 */
      bitstatus = RESET;
    }
  }
  else if((CAN_FLAG & CAN_FLAGS_RF0R) != (uint32_t)RESET)
  { 
    /* 检查指定 CAN 标志位的状态 */
    if ((CANx->RF0R & (CAN_FLAG & 0x000FFFFF)) != (uint32_t)RESET)
    { 
      /* CAN_FLAG 已置位 */
      bitstatus = SET;
    }
    else
    { 
      /* CAN_FLAG 已复位 */
      bitstatus = RESET;
    }
  }
  else /* If(CAN_FLAG & CAN_FLAGS_RF1R != (uint32_t)RESET) */
  { 
    /* 检查指定 CAN 标志位的状态 */
    if ((uint32_t)(CANx->RF1R & (CAN_FLAG & 0x000FFFFF)) != (uint32_t)RESET)
    { 
      /* CAN_FLAG 已置位 */
      bitstatus = SET;
    }
    else
    { 
      /* CAN_FLAG 已复位 */
      bitstatus = RESET;
    }
  }
  /* 返回 CAN_FLAG 的状态 */
  return  bitstatus;
}

/**
  * @brief  清除 CAN 的挂起标志位。
  * @param  CANx:     x 可为 1 或 2，用于选择 CAN 外设。
  * @param  CAN_FLAG: 指定要清除的标志位。
  *                   该参数可为以下标志位之一： 
  *                    - CAN_FLAG_RQCP0
  *                    - CAN_FLAG_RQCP1
  *                    - CAN_FLAG_RQCP2
  *                    - CAN_FLAG_FF1       
  *                    - CAN_FLAG_FOV1   
  *                    - CAN_FLAG_FF0       
  *                    - CAN_FLAG_FOV0   
  *                    - CAN_FLAG_WKU   
  *                    - CAN_FLAG_SLAK    
  *                    - CAN_FLAG_LEC       
  * @retval 无。
  */
void CAN_ClearFlag(CAN_TypeDef* CANx, uint32_t CAN_FLAG)
{
  uint32_t flagtmp=0;
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_CLEAR_FLAG(CAN_FLAG));
  
  if (CAN_FLAG == CAN_FLAG_LEC) /* ESR 寄存器 */
  {
    /* 清除选定的 CAN 标志位 */
    CANx->ESR = (uint32_t)RESET;
  }
  else /* MSR or TSR or RF0R or RF1R */
  {
    flagtmp = CAN_FLAG & 0x000FFFFF;

    if ((CAN_FLAG & CAN_FLAGS_RF0R)!=(uint32_t)RESET)
    {
      /* 接收标志位 */
      CANx->RF0R = (uint32_t)(flagtmp);
    }
    else if ((CAN_FLAG & CAN_FLAGS_RF1R)!=(uint32_t)RESET)
    {
      /* 接收标志位 */
      CANx->RF1R = (uint32_t)(flagtmp);
    }
    else if ((CAN_FLAG & CAN_FLAGS_TSR)!=(uint32_t)RESET)
    {
      /* 发送标志位 */
      CANx->TSR = (uint32_t)(flagtmp);
    }
    else /* If((CAN_FLAG & CAN_FLAGS_MSR)!=(uint32_t)RESET) */
    {
      /* 工作模式标志位 */
      CANx->MSR = (uint32_t)(flagtmp);
    }
  }
}

/**
  * @brief  检查指定的 CANx 中断是否发生。
  * @param  CANx:    x 可为 1 或 2，用于选择 CAN 外设。
  * @param  CAN_IT:  指定要检查的 CAN 中断源。
  *                  该参数可为以下标志位之一： 
  *                 -  CAN_IT_TME               
  *                 -  CAN_IT_FMP0              
  *                 -  CAN_IT_FF0               
  *                 -  CAN_IT_FOV0              
  *                 -  CAN_IT_FMP1              
  *                 -  CAN_IT_FF1               
  *                 -  CAN_IT_FOV1              
  *                 -  CAN_IT_WKU  
  *                 -  CAN_IT_SLK  
  *                 -  CAN_IT_EWG    
  *                 -  CAN_IT_EPV    
  *                 -  CAN_IT_BOF    
  *                 -  CAN_IT_LEC    
  *                 -  CAN_IT_ERR 
  * @retval CAN_IT 的当前状态（SET 或 RESET）。
  */
ITStatus CAN_GetITStatus(CAN_TypeDef* CANx, uint32_t CAN_IT)
{
  ITStatus itstatus = RESET;
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_IT(CAN_IT));
  
  /* 检查中断使能位 */
 if((CANx->IER & CAN_IT) != RESET)
 {
   /* 如果中断已使能，…… */
    switch (CAN_IT)
    {
      case CAN_IT_TME:
               /* 检查 CAN_TSR_RQCPx 位 */
	             itstatus = CheckITStatus(CANx->TSR, CAN_TSR_RQCP0|CAN_TSR_RQCP1|CAN_TSR_RQCP2);  
	      break;
      case CAN_IT_FMP0:
               /* 检查 CAN_RF0R_FMP0 位 */
	             itstatus = CheckITStatus(CANx->RF0R, CAN_RF0R_FMP0);  
	      break;
      case CAN_IT_FF0:
               /* 检查 CAN_RF0R_FULL0 位 */
               itstatus = CheckITStatus(CANx->RF0R, CAN_RF0R_FULL0);  
	      break;
      case CAN_IT_FOV0:
               /* 检查 CAN_RF0R_FOVR0 位 */
               itstatus = CheckITStatus(CANx->RF0R, CAN_RF0R_FOVR0);  
	      break;
      case CAN_IT_FMP1:
               /* 检查 CAN_RF1R_FMP1 位 */
               itstatus = CheckITStatus(CANx->RF1R, CAN_RF1R_FMP1);  
	      break;
      case CAN_IT_FF1:
               /* 检查 CAN_RF1R_FULL1 位 */
	             itstatus = CheckITStatus(CANx->RF1R, CAN_RF1R_FULL1);  
	      break;
      case CAN_IT_FOV1:
               /* 检查 CAN_RF1R_FOVR1 位 */
	             itstatus = CheckITStatus(CANx->RF1R, CAN_RF1R_FOVR1);  
	      break;
      case CAN_IT_WKU:
               /* 检查 CAN_MSR_WKUI 位 */
               itstatus = CheckITStatus(CANx->MSR, CAN_MSR_WKUI);  
	      break;
      case CAN_IT_SLK:
               /* 检查 CAN_MSR_SLAKI 位 */
	             itstatus = CheckITStatus(CANx->MSR, CAN_MSR_SLAKI);  
	      break;
      case CAN_IT_EWG:
               /* 检查 CAN_ESR_EWGF 位 */
	             itstatus = CheckITStatus(CANx->ESR, CAN_ESR_EWGF);  
	      break;
      case CAN_IT_EPV:
               /* 检查 CAN_ESR_EPVF 位 */
	             itstatus = CheckITStatus(CANx->ESR, CAN_ESR_EPVF);  
	      break;
      case CAN_IT_BOF:
               /* 检查 CAN_ESR_BOFF 位 */
	             itstatus = CheckITStatus(CANx->ESR, CAN_ESR_BOFF);  
	      break;
      case CAN_IT_LEC:
               /* 检查 CAN_ESR_LEC 位 */
	             itstatus = CheckITStatus(CANx->ESR, CAN_ESR_LEC);  
	      break;
      case CAN_IT_ERR:
               /* 检查 CAN_MSR_ERRI 位 */ 
               itstatus = CheckITStatus(CANx->MSR, CAN_MSR_ERRI); 
	      break;
      default :
               /* 如果出错，返回 RESET */
              itstatus = RESET;
              break;
    }
  }
  else
  {
   /* 如果中断未使能，返回 RESET */
    itstatus  = RESET;
  }
  
  /* 返回 CAN_IT 的状态 */
  return  itstatus;
}

/**
  * @brief  清除 CANx 的中断挂起位。
  * @param  CANx:    x 可为 1 或 2，用于选择 CAN 外设。
  * @param  CAN_IT: 指定要清除的中断挂起位。
  *                  -  CAN_IT_TME                     
  *                  -  CAN_IT_FF0               
  *                  -  CAN_IT_FOV0                     
  *                  -  CAN_IT_FF1               
  *                  -  CAN_IT_FOV1              
  *                  -  CAN_IT_WKU  
  *                  -  CAN_IT_SLK  
  *                  -  CAN_IT_EWG    
  *                  -  CAN_IT_EPV    
  *                  -  CAN_IT_BOF    
  *                  -  CAN_IT_LEC    
  *                  -  CAN_IT_ERR 
  * @retval 无。
  */
void CAN_ClearITPendingBit(CAN_TypeDef* CANx, uint32_t CAN_IT)
{
  /* 检查参数 */
  assert_param(IS_CAN_ALL_PERIPH(CANx));
  assert_param(IS_CAN_CLEAR_IT(CAN_IT));

  switch (CAN_IT)
  {
      case CAN_IT_TME:
              /* 清除 CAN_TSR_RQCPx（rc_w1）*/
	      CANx->TSR = CAN_TSR_RQCP0|CAN_TSR_RQCP1|CAN_TSR_RQCP2;  
	      break;
      case CAN_IT_FF0:
              /* 清除 CAN_RF0R_FULL0（rc_w1）*/
	      CANx->RF0R = CAN_RF0R_FULL0; 
	      break;
      case CAN_IT_FOV0:
              /* 清除 CAN_RF0R_FOVR0（rc_w1）*/
	      CANx->RF0R = CAN_RF0R_FOVR0; 
	      break;
      case CAN_IT_FF1:
              /* 清除 CAN_RF1R_FULL1（rc_w1）*/
	      CANx->RF1R = CAN_RF1R_FULL1;  
	      break;
      case CAN_IT_FOV1:
              /* 清除 CAN_RF1R_FOVR1（rc_w1）*/
	      CANx->RF1R = CAN_RF1R_FOVR1; 
	      break;
      case CAN_IT_WKU:
              /* 清除 CAN_MSR_WKUI（rc_w1）*/
	      CANx->MSR = CAN_MSR_WKUI;  
	      break;
      case CAN_IT_SLK:
              /* 清除 CAN_MSR_SLAKI（rc_w1）*/ 
	      CANx->MSR = CAN_MSR_SLAKI;   
	      break;
      case CAN_IT_EWG:
              /* 清除 CAN_MSR_ERRI（rc_w1） */
	      CANx->MSR = CAN_MSR_ERRI;
              /* 注意：相应的标志位由硬件清除，具体取决于 
                        CAN 总线状态*/ 
	      break;
      case CAN_IT_EPV:
              /* 清除 CAN_MSR_ERRI（rc_w1） */
	      CANx->MSR = CAN_MSR_ERRI; 
              /* 注意：相应的标志位由硬件清除，具体取决于 
                        CAN 总线状态*/
	      break;
      case CAN_IT_BOF:
              /* 清除 CAN_MSR_ERRI（rc_w1） */ 
	      CANx->MSR = CAN_MSR_ERRI; 
              /* 注意：相应的标志位由硬件清除，具体取决于 
                        CAN 总线状态*/
	      break;
      case CAN_IT_LEC:
              /*  清除 LEC 位 */
	      CANx->ESR = RESET; 
              /* 清除 CAN_MSR_ERRI（rc_w1） */
	      CANx->MSR = CAN_MSR_ERRI; 
	      break;
      case CAN_IT_ERR:
              /*清除 LEC 位 */
	      CANx->ESR = RESET; 
              /* 清除 CAN_MSR_ERRI（rc_w1） */
	      CANx->MSR = CAN_MSR_ERRI; 
	      /* 注意：BOFF、EPVF 和 EWGF 标志位由硬件清除，具体取决于 
                  CAN 总线状态*/
	      break;
      default :
	      break;
   }
}

/**
  * @brief  检查 CAN 中断是否发生。
  * @param  CAN_Reg: 指定要检查的 CAN 中断寄存器。
  * @param  It_Bit:  指定要检查的中断源位。
  * @retval CAN 中断的新状态（SET 或 RESET）。
  */
static ITStatus CheckITStatus(uint32_t CAN_Reg, uint32_t It_Bit)
{
  ITStatus pendingbitstatus = RESET;
  
  if ((CAN_Reg & It_Bit) != (uint32_t)RESET)
  {
    /* CAN_IT 已置位 */
    pendingbitstatus = SET;
  }
  else
  {
    /* CAN_IT 已复位 */
    pendingbitstatus = RESET;
  }
  return pendingbitstatus;
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
