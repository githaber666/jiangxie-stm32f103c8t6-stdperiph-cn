/**
  ******************************************************************************
  * @file    stm32f10x_spi.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件提供所有 SPI 固件函数。
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
#include "stm32f10x_spi.h"
#include "stm32f10x_rcc.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @defgroup SPI 
  * @brief SPI 驱动模块
  * @{
  */ 

/** @defgroup SPI_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */ 


/** @defgroup SPI_Private_Defines
  * @{
  */

/* SPI SPE 掩码 */
#define CR1_SPE_Set          ((uint16_t)0x0040)
#define CR1_SPE_Reset        ((uint16_t)0xFFBF)

/* I2S I2SE 掩码 */
#define I2SCFGR_I2SE_Set     ((uint16_t)0x0400)
#define I2SCFGR_I2SE_Reset   ((uint16_t)0xFBFF)

/* SPI CRCNext 掩码 */
#define CR1_CRCNext_Set      ((uint16_t)0x1000)

/* SPI CRCEN 掩码 */
#define CR1_CRCEN_Set        ((uint16_t)0x2000)
#define CR1_CRCEN_Reset      ((uint16_t)0xDFFF)

/* SPI SSOE 掩码 */
#define CR2_SSOE_Set         ((uint16_t)0x0004)
#define CR2_SSOE_Reset       ((uint16_t)0xFFFB)

/* SPI 寄存器掩码 */
#define CR1_CLEAR_Mask       ((uint16_t)0x3040)
#define I2SCFGR_CLEAR_Mask   ((uint16_t)0xF040)

/* SPI 或 I2S 模式选择掩码 */
#define SPI_Mode_Select      ((uint16_t)0xF7FF)
#define I2S_Mode_Select      ((uint16_t)0x0800) 

/* I2S 时钟源选择掩码 */
#define I2S2_CLOCK_SRC       ((uint32_t)(0x00020000))
#define I2S3_CLOCK_SRC       ((uint32_t)(0x00040000))
#define I2S_MUL_MASK         ((uint32_t)(0x0000F000))
#define I2S_DIV_MASK         ((uint32_t)(0x000000F0))

/**
  * @}
  */

/** @defgroup SPI_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup SPI_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup SPI_Private_FunctionPrototypes
  * @{
  */

/**
  * @}
  */

/** @defgroup SPI_Private_Functions
  * @{
  */

/**
  * @brief  将 SPIx 外设寄存器复位为默认值
  *         （同时影响 I2S）。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @retval 无
  */
void SPI_I2S_DeInit(SPI_TypeDef* SPIx)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));

  if (SPIx == SPI1)
  {
    /* 使能 SPI1 复位状态 */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1, ENABLE);
    /* 释放 SPI1 复位状态 */
    RCC_APB2PeriphResetCmd(RCC_APB2Periph_SPI1, DISABLE);
  }
  else if (SPIx == SPI2)
  {
    /* 使能 SPI2 复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI2, ENABLE);
    /* 释放 SPI2 复位状态 */
    RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI2, DISABLE);
  }
  else
  {
    if (SPIx == SPI3)
    {
      /* 使能 SPI3 复位状态 */
      RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI3, ENABLE);
      /* 释放 SPI3 复位状态 */
      RCC_APB1PeriphResetCmd(RCC_APB1Periph_SPI3, DISABLE);
    }
  }
}

/**
  * @brief  根据指定的参数初始化 SPIx 外设， 
  *         这些参数位于 SPI_InitStruct 中。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @param  SPI_InitStruct: 指向 SPI_InitTypeDef 结构的指针，
  *         其中包含指定 SPI 外设的配置信息。
  * @retval 无
  */
void SPI_Init(SPI_TypeDef* SPIx, SPI_InitTypeDef* SPI_InitStruct)
{
  uint16_t tmpreg = 0;
  
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));   
  
  /* 检查 SPI 参数 */
  assert_param(IS_SPI_DIRECTION_MODE(SPI_InitStruct->SPI_Direction));
  assert_param(IS_SPI_MODE(SPI_InitStruct->SPI_Mode));
  assert_param(IS_SPI_DATASIZE(SPI_InitStruct->SPI_DataSize));
  assert_param(IS_SPI_CPOL(SPI_InitStruct->SPI_CPOL));
  assert_param(IS_SPI_CPHA(SPI_InitStruct->SPI_CPHA));
  assert_param(IS_SPI_NSS(SPI_InitStruct->SPI_NSS));
  assert_param(IS_SPI_BAUDRATE_PRESCALER(SPI_InitStruct->SPI_BaudRatePrescaler));
  assert_param(IS_SPI_FIRST_BIT(SPI_InitStruct->SPI_FirstBit));
  assert_param(IS_SPI_CRC_POLYNOMIAL(SPI_InitStruct->SPI_CRCPolynomial));

/*---------------------------- SPIx CR1 配置 ------------------------*/
  /* 获取 SPIx CR1 寄存器的值 */
  tmpreg = SPIx->CR1;
  /* 清零 BIDIMode、BIDIOE、RxONLY、SSM、SSI、LSBFirst、BR、MSTR、CPOL 和 CPHA 位 */
  tmpreg &= CR1_CLEAR_Mask;
  /* 配置 SPIx：方向、NSS 管理、首位、波特率预分频器
     主/从模式、CPOL 和 CPHA */
  /* 根据 SPI_Direction 的值设置 BIDIMode、BIDIOE 和 RxONLY 位 */
  /* 根据 SPI_Mode 和 SPI_NSS 的值设置 SSM、SSI 和 MSTR 位 */
  /* 根据 SPI_FirstBit 的值设置 LSBFirst 位 */
  /* 根据 SPI_BaudRatePrescaler 的值设置 BR 位 */
  /* 根据 SPI_CPOL 的值设置 CPOL 位 */
  /* 根据 SPI_CPHA 的值设置 CPHA 位 */
  tmpreg |= (uint16_t)((uint32_t)SPI_InitStruct->SPI_Direction | SPI_InitStruct->SPI_Mode |
                  SPI_InitStruct->SPI_DataSize | SPI_InitStruct->SPI_CPOL |  
                  SPI_InitStruct->SPI_CPHA | SPI_InitStruct->SPI_NSS |  
                  SPI_InitStruct->SPI_BaudRatePrescaler | SPI_InitStruct->SPI_FirstBit);
  /* 写入 SPIx CR1 寄存器 */
  SPIx->CR1 = tmpreg;
  
  /* 激活 SPI 模式（清零 I2SCFGR 寄存器中的 I2SMOD 位） */
  SPIx->I2SCFGR &= SPI_Mode_Select;		

/*---------------------------- SPIx CRCPOLY 配置 --------------------*/
  /* 写入 SPIx CRCPOLY 寄存器 */
  SPIx->CRCPR = SPI_InitStruct->SPI_CRCPolynomial;
}

/**
  * @brief  根据指定的参数初始化 SPIx 外设， 
  *         这些参数位于 I2S_InitStruct 中。
  * @param  SPIx: x 可为 2 或 3，用于选择 SPI 外设
  *         （配置为 I2S 模式）。
  * @param  I2S_InitStruct: 指向 I2S_InitTypeDef 结构的指针，
  *         其中包含指定 SPI 外设
  *         （配置为 I2S 模式）的配置信息。
  * @note
  *  本函数计算获得最高精度的音频频率所需的 
  *  最佳预分频器（取决于 I2S 时钟源、PLL 值 
  *  和产品配置）。但如果预分频器值 
  *  大于 511，则改为配置默认值（0x02）。  *   
  * @retval 无
  */
void I2S_Init(SPI_TypeDef* SPIx, I2S_InitTypeDef* I2S_InitStruct)
{
  uint16_t tmpreg = 0, i2sdiv = 2, i2sodd = 0, packetlength = 1;
  uint32_t tmp = 0;
  RCC_ClocksTypeDef RCC_Clocks;
  uint32_t sourceclock = 0;
  
  /* 检查 I2S 参数 */
  assert_param(IS_SPI_23_PERIPH(SPIx));
  assert_param(IS_I2S_MODE(I2S_InitStruct->I2S_Mode));
  assert_param(IS_I2S_STANDARD(I2S_InitStruct->I2S_Standard));
  assert_param(IS_I2S_DATA_FORMAT(I2S_InitStruct->I2S_DataFormat));
  assert_param(IS_I2S_MCLK_OUTPUT(I2S_InitStruct->I2S_MCLKOutput));
  assert_param(IS_I2S_AUDIO_FREQ(I2S_InitStruct->I2S_AudioFreq));
  assert_param(IS_I2S_CPOL(I2S_InitStruct->I2S_CPOL));  

/*----------------------- SPIx I2SCFGR & I2SPR 配置 -----------------*/
  /* 清零 I2SMOD、I2SE、I2SCFG、PCMSYNC、I2SSTD、CKPOL、DATLEN 和 CHLEN 位 */
  SPIx->I2SCFGR &= I2SCFGR_CLEAR_Mask; 
  SPIx->I2SPR = 0x0002;
  
  /* 获取 I2SCFGR 寄存器的值 */
  tmpreg = SPIx->I2SCFGR;
  
  /* 若需写入默认值，则重新初始化 i2sdiv 和 i2sodd*/
  if(I2S_InitStruct->I2S_AudioFreq == I2S_AudioFreq_Default)
  {
    i2sodd = (uint16_t)0;
    i2sdiv = (uint16_t)2;   
  }
  /* 若请求的音频频率不是默认值，则计算预分频器 */
  else
  {
    /* 检查帧长度（用于计算预分频器） */
    if(I2S_InitStruct->I2S_DataFormat == I2S_DataFormat_16b)
    {
      /* 数据包长度为 16 位 */
      packetlength = 1;
    }
    else
    {
      /* 数据包长度为 32 位 */
      packetlength = 2;
    }

    /* 根据外设编号获取 I2S 时钟源掩码 */
    if(((uint32_t)SPIx) == SPI2_BASE)
    {
      /* 该掩码对应于 I2S2 */
      tmp = I2S2_CLOCK_SRC;
    }
    else 
    {
      /* 该掩码对应于 I2S3 */      
      tmp = I2S3_CLOCK_SRC;
    }

    /* 根据器件检查 I2S 时钟源配置：
       只有互联型器件才有 PLL3 VCO 时钟 */
#ifdef STM32F10X_CL
    if((RCC->CFGR2 & tmp) != 0)
    {
      /* 获取 RCC PLL3 倍频器的配置位 */
      tmp = (uint32_t)((RCC->CFGR2 & I2S_MUL_MASK) >> 12);

      /* 获取 PLL3 倍频器的值 */      
      if((tmp > 5) && (tmp < 15))
      {
        /* 倍频系数在 8 与 14 之间（禁止使用值 15） */
        tmp += 2;
      }
      else
      {
        if (tmp == 15)
        {
          /* 倍频系数为 20 */
          tmp = 20;
        }
      }      
      /* 获取 PREDIV2 的值 */
      sourceclock = (uint32_t)(((RCC->CFGR2 & I2S_DIV_MASK) >> 4) + 1);
      
      /* 根据 PLL3 和 PREDIV2 的值计算源时钟频率 */
      sourceclock = (uint32_t) ((HSE_Value / sourceclock) * tmp * 2); 
    }
    else
    {
      /* I2S 时钟源为系统时钟：获取系统时钟频率 */
      RCC_GetClocksFreq(&RCC_Clocks);      
      
      /* 获取源时钟值：基于系统时钟的值 */
      sourceclock = RCC_Clocks.SYSCLK_Frequency;
    }        
#else /* STM32F10X_HD */
    /* I2S 时钟源为系统时钟：获取系统时钟频率 */
    RCC_GetClocksFreq(&RCC_Clocks);      
      
    /* 获取源时钟值：基于系统时钟的值 */
    sourceclock = RCC_Clocks.SYSCLK_Frequency;    
#endif /* STM32F10X_CL */    

    /* 根据 MCLK 输出状态以浮点方式计算实际分频值 */
    if(I2S_InitStruct->I2S_MCLKOutput == I2S_MCLKOutput_Enable)
    {
      /* MCLK 输出已使能 */
      tmp = (uint16_t)(((((sourceclock / 256) * 10) / I2S_InitStruct->I2S_AudioFreq)) + 5);
    }
    else
    {
      /* MCLK 输出已失能 */
      tmp = (uint16_t)(((((sourceclock / (32 * packetlength)) *10 ) / I2S_InitStruct->I2S_AudioFreq)) + 5);
    }
    
    /* 去掉浮点部分 */
    tmp = tmp / 10;  
      
    /* 检查分频值的奇偶性 */
    i2sodd = (uint16_t)(tmp & (uint16_t)0x0001);
   
    /* 计算 i2sdiv 预分频值 */
    i2sdiv = (uint16_t)((tmp - i2sodd) / 2);
   
    /* 获取奇分频位（SPI_I2SPR[8]）的掩码 */
    i2sodd = (uint16_t) (i2sodd << 8);
  }
  
  /* 判断分频值是否为 1 或 0，或大于 0xFF */
  if ((i2sdiv < 2) || (i2sdiv > 0xFF))
  {
    /* 设置默认值 */
    i2sdiv = 2;
    i2sodd = 0;
  }

  /* 将计算值写入 SPIx I2SPR 寄存器 */
  SPIx->I2SPR = (uint16_t)(i2sdiv | (uint16_t)(i2sodd | (uint16_t)I2S_InitStruct->I2S_MCLKOutput));  
 
  /* 使用 SPI_InitStruct 的值配置 I2S */
  tmpreg |= (uint16_t)(I2S_Mode_Select | (uint16_t)(I2S_InitStruct->I2S_Mode | \
                  (uint16_t)(I2S_InitStruct->I2S_Standard | (uint16_t)(I2S_InitStruct->I2S_DataFormat | \
                  (uint16_t)I2S_InitStruct->I2S_CPOL))));
 
  /* 写入 SPIx I2SCFGR 寄存器 */  
  SPIx->I2SCFGR = tmpreg;   
}

/**
  * @brief  将 SPI_InitStruct 的每个成员填充为默认值。
  * @param  SPI_InitStruct : 指向将被初始化的 SPI_InitTypeDef 结构的指针。
  * @retval 无
  */
void SPI_StructInit(SPI_InitTypeDef* SPI_InitStruct)
{
/*--------------- 复位 SPI 初始化结构体参数值 -----------------*/
  /* 初始化 SPI_Direction 成员 */
  SPI_InitStruct->SPI_Direction = SPI_Direction_2Lines_FullDuplex;
  /* 初始化 SPI_Mode 成员 */
  SPI_InitStruct->SPI_Mode = SPI_Mode_Slave;
  /* 初始化 SPI_DataSize 成员 */
  SPI_InitStruct->SPI_DataSize = SPI_DataSize_8b;
  /* 初始化 SPI_CPOL 成员 */
  SPI_InitStruct->SPI_CPOL = SPI_CPOL_Low;
  /* 初始化 SPI_CPHA 成员 */
  SPI_InitStruct->SPI_CPHA = SPI_CPHA_1Edge;
  /* 初始化 SPI_NSS 成员 */
  SPI_InitStruct->SPI_NSS = SPI_NSS_Hard;
  /* 初始化 SPI_BaudRatePrescaler 成员 */
  SPI_InitStruct->SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
  /* 初始化 SPI_FirstBit 成员 */
  SPI_InitStruct->SPI_FirstBit = SPI_FirstBit_MSB;
  /* 初始化 SPI_CRCPolynomial 成员 */
  SPI_InitStruct->SPI_CRCPolynomial = 7;
}

/**
  * @brief  将 I2S_InitStruct 的每个成员填充为默认值。
  * @param  I2S_InitStruct : 指向将被初始化的 I2S_InitTypeDef 结构的指针。
  * @retval 无
  */
void I2S_StructInit(I2S_InitTypeDef* I2S_InitStruct)
{
/*--------------- 复位 I2S 初始化结构体参数值 -----------------*/
  /* 初始化 I2S_Mode 成员 */
  I2S_InitStruct->I2S_Mode = I2S_Mode_SlaveTx;
  
  /* 初始化 I2S_Standard 成员 */
  I2S_InitStruct->I2S_Standard = I2S_Standard_Phillips;
  
  /* 初始化 I2S_DataFormat 成员 */
  I2S_InitStruct->I2S_DataFormat = I2S_DataFormat_16b;
  
  /* 初始化 I2S_MCLKOutput 成员 */
  I2S_InitStruct->I2S_MCLKOutput = I2S_MCLKOutput_Disable;
  
  /* 初始化 I2S_AudioFreq 成员 */
  I2S_InitStruct->I2S_AudioFreq = I2S_AudioFreq_Default;
  
  /* 初始化 I2S_CPOL 成员 */
  I2S_InitStruct->I2S_CPOL = I2S_CPOL_Low;
}

/**
  * @brief  使能或失能指定的 SPI 外设。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @param  NewState: SPIx 外设的新状态。 
  *   该参数可为：ENABLE 或 DISABLE。
  * @retval 无
  */
void SPI_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 SPI 外设 */
    SPIx->CR1 |= CR1_SPE_Set;
  }
  else
  {
    /* 失能选定的 SPI 外设 */
    SPIx->CR1 &= CR1_SPE_Reset;
  }
}

/**
  * @brief  使能或失能指定的 SPI 外设（I2S 模式）。
  * @param  SPIx: x 可为 2 或 3，用于选择 SPI 外设。
  * @param  NewState: SPIx 外设的新状态。 
  *   该参数可为：ENABLE 或 DISABLE。
  * @retval 无
  */
void I2S_Cmd(SPI_TypeDef* SPIx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_SPI_23_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 SPI 外设（I2S 模式） */
    SPIx->I2SCFGR |= I2SCFGR_I2SE_Set;
  }
  else
  {
    /* 失能选定的 SPI 外设（I2S 模式） */
    SPIx->I2SCFGR &= I2SCFGR_I2SE_Reset;
  }
}

/**
  * @brief  使能或失能指定的 SPI/I2S 中断。
  * @param  SPIx: x 可为
  *   - SPI 模式下为 1、2 或 3 
  *   - I2S 模式下为 2 或 3
  * @param  SPI_I2S_IT: 指定要使能或失能的 SPI/I2S 中断源。 
  *   该参数可为以下值之一：
  *     @arg SPI_I2S_IT_TXE: 发送缓冲区空中断掩码
  *     @arg SPI_I2S_IT_RXNE: 接收缓冲区非空中断掩码
  *     @arg SPI_I2S_IT_ERR: 错误中断掩码
  * @param  NewState: 指定 SPI/I2S 中断的新状态。
  *   该参数可为：ENABLE 或 DISABLE。
  * @retval 无
  */
void SPI_I2S_ITConfig(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT, FunctionalState NewState)
{
  uint16_t itpos = 0, itmask = 0 ;
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_SPI_I2S_CONFIG_IT(SPI_I2S_IT));

  /* 获取 SPI/I2S 中断索引 */
  itpos = SPI_I2S_IT >> 4;

  /* 设置中断掩码 */
  itmask = (uint16_t)1 << (uint16_t)itpos;

  if (NewState != DISABLE)
  {
    /* 使能选定的 SPI/I2S 中断 */
    SPIx->CR2 |= itmask;
  }
  else
  {
    /* 失能选定的 SPI/I2S 中断 */
    SPIx->CR2 &= (uint16_t)~itmask;
  }
}

/**
  * @brief  使能或失能 SPIx/I2Sx 的 DMA 接口。
  * @param  SPIx: x 可为
  *   - SPI 模式下为 1、2 或 3 
  *   - I2S 模式下为 2 或 3
  * @param  SPI_I2S_DMAReq: 指定要使能或失能的 SPI/I2S DMA 传输请求。 
  *   该参数可为以下值的任意组合：
  *     @arg SPI_I2S_DMAReq_Tx: 发送缓冲区 DMA 传输请求
  *     @arg SPI_I2S_DMAReq_Rx: 接收缓冲区 DMA 传输请求
  * @param  NewState: 选定 SPI/I2S DMA 传输请求的新状态。
  *   该参数可为：ENABLE 或 DISABLE。
  * @retval 无
  */
void SPI_I2S_DMACmd(SPI_TypeDef* SPIx, uint16_t SPI_I2S_DMAReq, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  assert_param(IS_SPI_I2S_DMAREQ(SPI_I2S_DMAReq));
  if (NewState != DISABLE)
  {
    /* 使能选定的 SPI/I2S DMA 请求 */
    SPIx->CR2 |= SPI_I2S_DMAReq;
  }
  else
  {
    /* 失能选定的 SPI/I2S DMA 请求 */
    SPIx->CR2 &= (uint16_t)~SPI_I2S_DMAReq;
  }
}

/**
  * @brief  通过 SPIx/I2Sx 外设发送一个数据。
  * @param  SPIx: x 可为
  *   - SPI 模式下为 1、2 或 3 
  *   - I2S 模式下为 2 或 3
  * @param  Data : 要发送的数据。
  * @retval 无
  */
void SPI_I2S_SendData(SPI_TypeDef* SPIx, uint16_t Data)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  
  /* 将待发送的数据写入 DR 寄存器 */
  SPIx->DR = Data;
}

/**
  * @brief  返回 SPIx/I2Sx 外设最近一次接收到的数据。 
  * @param  SPIx: x 可为
  *   - SPI 模式下为 1、2 或 3 
  *   - I2S 模式下为 2 或 3
  * @retval 接收到的数据值。
  */
uint16_t SPI_I2S_ReceiveData(SPI_TypeDef* SPIx)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  
  /* 返回 DR 寄存器中的数据 */
  return SPIx->DR;
}

/**
  * @brief  通过软件在内部配置选定 SPI 的 NSS 引脚。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @param  SPI_NSSInternalSoft: 指定 SPI NSS 的内部状态。
  *   该参数可为以下值之一：
  *     @arg SPI_NSSInternalSoft_Set: 在内部置位 NSS 引脚
  *     @arg SPI_NSSInternalSoft_Reset: 在内部复位 NSS 引脚
  * @retval 无
  */
void SPI_NSSInternalSoftwareConfig(SPI_TypeDef* SPIx, uint16_t SPI_NSSInternalSoft)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_NSS_INTERNAL(SPI_NSSInternalSoft));
  if (SPI_NSSInternalSoft != SPI_NSSInternalSoft_Reset)
  {
    /* 通过软件在内部置位 NSS 引脚 */
    SPIx->CR1 |= SPI_NSSInternalSoft_Set;
  }
  else
  {
    /* 通过软件在内部复位 NSS 引脚 */
    SPIx->CR1 &= SPI_NSSInternalSoft_Reset;
  }
}

/**
  * @brief  使能或失能选定 SPI 的 SS 输出。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @param  NewState: SPIx SS 输出的新状态。 
  *   该参数可为：ENABLE 或 DISABLE。
  * @retval 无
  */
void SPI_SSOutputCmd(SPI_TypeDef* SPIx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定的 SPI SS 输出 */
    SPIx->CR2 |= CR2_SSOE_Set;
  }
  else
  {
    /* 失能选定的 SPI SS 输出 */
    SPIx->CR2 &= CR2_SSOE_Reset;
  }
}

/**
  * @brief  配置选定 SPI 的数据长度。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @param  SPI_DataSize: 指定 SPI 数据长度。
  *   该参数可为以下值之一：
  *     @arg SPI_DataSize_16b: 将数据帧格式设为 16 位
  *     @arg SPI_DataSize_8b: 将数据帧格式设为 8 位
  * @retval 无
  */
void SPI_DataSizeConfig(SPI_TypeDef* SPIx, uint16_t SPI_DataSize)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_DATASIZE(SPI_DataSize));
  /* 清零 DFF 位 */
  SPIx->CR1 &= (uint16_t)~SPI_DataSize_16b;
  /* 设置 DFF 位的新值 */
  SPIx->CR1 |= SPI_DataSize;
}

/**
  * @brief  发送 SPIx 的 CRC 值。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @retval 无
  */
void SPI_TransmitCRC(SPI_TypeDef* SPIx)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  
  /* 使能选定 SPI 的 CRC 发送 */
  SPIx->CR1 |= CR1_CRCNext_Set;
}

/**
  * @brief  使能或失能对所传输字节的 CRC 值计算。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @param  NewState: SPIx CRC 值计算的新状态。
  *   该参数可为：ENABLE 或 DISABLE。
  * @retval 无
  */
void SPI_CalculateCRC(SPI_TypeDef* SPIx, FunctionalState NewState)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_FUNCTIONAL_STATE(NewState));
  if (NewState != DISABLE)
  {
    /* 使能选定 SPI 的 CRC 计算 */
    SPIx->CR1 |= CR1_CRCEN_Set;
  }
  else
  {
    /* 失能选定 SPI 的 CRC 计算 */
    SPIx->CR1 &= CR1_CRCEN_Reset;
  }
}

/**
  * @brief  返回指定 SPI 的发送或接收 CRC 寄存器的值。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @param  SPI_CRC: 指定要读取的 CRC 寄存器。
  *   该参数可为以下值之一：
  *     @arg SPI_CRC_Tx: 选择发送 CRC 寄存器
  *     @arg SPI_CRC_Rx: 选择接收 CRC 寄存器
  * @retval 选定的 CRC 寄存器值。
  */
uint16_t SPI_GetCRC(SPI_TypeDef* SPIx, uint8_t SPI_CRC)
{
  uint16_t crcreg = 0;
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_CRC(SPI_CRC));
  if (SPI_CRC != SPI_CRC_Rx)
  {
    /* 获取发送 CRC 寄存器 */
    crcreg = SPIx->TXCRCR;
  }
  else
  {
    /* 获取接收 CRC 寄存器 */
    crcreg = SPIx->RXCRCR;
  }
  /* 返回选定的 CRC 寄存器 */
  return crcreg;
}

/**
  * @brief  返回指定 SPI 的 CRC 多项式寄存器的值。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @retval CRC 多项式寄存器的值。
  */
uint16_t SPI_GetCRCPolynomial(SPI_TypeDef* SPIx)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  
  /* 返回 CRC 多项式寄存器 */
  return SPIx->CRCPR;
}

/**
  * @brief  选择指定 SPI 在双向模式下的数据传输方向。
  * @param  SPIx: x 可为 1、2 或 3，用于选择 SPI 外设。
  * @param  SPI_Direction: 指定双向模式下的数据传输方向。 
  *   该参数可为以下值之一：
  *     @arg SPI_Direction_Tx: 选择发送方向
  *     @arg SPI_Direction_Rx: 选择接收方向
  * @retval 无
  */
void SPI_BiDirectionalLineConfig(SPI_TypeDef* SPIx, uint16_t SPI_Direction)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_DIRECTION(SPI_Direction));
  if (SPI_Direction == SPI_Direction_Tx)
  {
    /* 设置为只发送模式 */
    SPIx->CR1 |= SPI_Direction_Tx;
  }
  else
  {
    /* 设置为只接收模式 */
    SPIx->CR1 &= SPI_Direction_Rx;
  }
}

/**
  * @brief  检查指定的 SPI/I2S 标志位是否置位。
  * @param  SPIx: x 可为
  *   - SPI 模式下为 1、2 或 3 
  *   - I2S 模式下为 2 或 3
  * @param  SPI_I2S_FLAG: 指定要检查的 SPI/I2S 标志位。 
  *   该参数可为以下值之一：
  *     @arg SPI_I2S_FLAG_TXE: 发送缓冲区空标志位。
  *     @arg SPI_I2S_FLAG_RXNE: 接收缓冲区非空标志位。
  *     @arg SPI_I2S_FLAG_BSY: 忙标志位。
  *     @arg SPI_I2S_FLAG_OVR: 溢出标志位。
  *     @arg SPI_FLAG_MODF: 模式错误标志位。
  *     @arg SPI_FLAG_CRCERR: CRC 错误标志位。
  *     @arg I2S_FLAG_UDR: 下溢错误标志位。
  *     @arg I2S_FLAG_CHSIDE: 通道侧标志位。
  * @retval SPI_I2S_FLAG 的新状态（SET 或 RESET）。
  */
FlagStatus SPI_I2S_GetFlagStatus(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
{
  FlagStatus bitstatus = RESET;
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_I2S_GET_FLAG(SPI_I2S_FLAG));
  /* 检查指定 SPI/I2S 标志位的状态 */
  if ((SPIx->SR & SPI_I2S_FLAG) != (uint16_t)RESET)
  {
    /* SPI_I2S_FLAG 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* SPI_I2S_FLAG 已复位 */
    bitstatus = RESET;
  }
  /* 返回 SPI_I2S_FLAG 的状态 */
  return  bitstatus;
}

/**
  * @brief  清除 SPIx 的 CRC 错误（CRCERR）标志位。
  * @param  SPIx: x 可为
  *   - SPI 模式下为 1、2 或 3 
  * @param  SPI_I2S_FLAG: 指定要清除的 SPI 标志位。 
  *   本函数仅清除 CRCERR 标志位。
  * @note
  *   - OVR（溢出错误）标志位通过软件序列清除：先执行一次 
  *     对 SPI_DR 寄存器的读操作（SPI_I2S_ReceiveData()），再执行一次 
  *     对 SPI_SR 寄存器的读操作（SPI_I2S_GetFlagStatus()）。
  *   - UDR（下溢错误）标志位通过对 SPI_SR 寄存器 
  *     执行一次读操作（SPI_I2S_GetFlagStatus()）来清除。
  *   - MODF（模式错误）标志位通过软件序列清除：先执行一次 
  *     对 SPI_SR 寄存器的读/写操作（SPI_I2S_GetFlagStatus()），再执行一次 
  *     对 SPI_CR1 寄存器的写操作（调用 SPI_Cmd() 使能 SPI）。
  * @retval 无
  */
void SPI_I2S_ClearFlag(SPI_TypeDef* SPIx, uint16_t SPI_I2S_FLAG)
{
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_I2S_CLEAR_FLAG(SPI_I2S_FLAG));
    
    /* 清除选定的 SPI CRC 错误（CRCERR）标志位 */
    SPIx->SR = (uint16_t)~SPI_I2S_FLAG;
}

/**
  * @brief  检查指定的 SPI/I2S 中断是否发生。
  * @param  SPIx: x 可为
  *   - SPI 模式下为 1、2 或 3 
  *   - I2S 模式下为 2 或 3
  * @param  SPI_I2S_IT: 指定要检查的 SPI/I2S 中断源。 
  *   该参数可为以下值之一：
  *     @arg SPI_I2S_IT_TXE: 发送缓冲区空中断。
  *     @arg SPI_I2S_IT_RXNE: 接收缓冲区非空中断。
  *     @arg SPI_I2S_IT_OVR: 溢出中断。
  *     @arg SPI_IT_MODF: 模式错误中断。
  *     @arg SPI_IT_CRCERR: CRC 错误中断。
  *     @arg I2S_IT_UDR: 下溢错误中断。
  * @retval SPI_I2S_IT 的新状态（SET 或 RESET）。
  */
ITStatus SPI_I2S_GetITStatus(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT)
{
  ITStatus bitstatus = RESET;
  uint16_t itpos = 0, itmask = 0, enablestatus = 0;

  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_I2S_GET_IT(SPI_I2S_IT));

  /* 获取 SPI/I2S 中断索引 */
  itpos = 0x01 << (SPI_I2S_IT & 0x0F);

  /* 获取 SPI/I2S 中断掩码 */
  itmask = SPI_I2S_IT >> 4;

  /* 设置中断掩码 */
  itmask = 0x01 << itmask;

  /* 获取 SPI_I2S_IT 使能位的状态 */
  enablestatus = (SPIx->CR2 & itmask) ;

  /* 检查指定 SPI/I2S 中断的状态 */
  if (((SPIx->SR & itpos) != (uint16_t)RESET) && enablestatus)
  {
    /* SPI_I2S_IT 已置位 */
    bitstatus = SET;
  }
  else
  {
    /* SPI_I2S_IT 已复位 */
    bitstatus = RESET;
  }
  /* 返回 SPI_I2S_IT 的状态 */
  return bitstatus;
}

/**
  * @brief  清除 SPIx 的 CRC 错误（CRCERR）中断挂起位。
  * @param  SPIx: x 可为
  *   - SPI 模式下为 1、2 或 3 
  * @param  SPI_I2S_IT: 指定要清除的 SPI 中断挂起位。
  *   本函数仅清除 CRCERR 中断挂起位。   
  * @note
  *   - OVR（溢出错误）中断挂起位通过软件 
  *     序列清除：先对 SPI_DR 寄存器执行一次读操作 
  *     （SPI_I2S_ReceiveData()），再对 SPI_SR 寄存器执行一次读操作（SPI_I2S_GetITStatus()）。
  *   - UDR（下溢错误）中断挂起位通过对 SPI_SR 寄存器 
  *     执行一次读操作（SPI_I2S_GetITStatus()）来清除。
  *   - MODF（模式错误）中断挂起位通过软件序列清除：先对
  *     SPI_SR 寄存器执行一次读/写操作（SPI_I2S_GetITStatus()）， 
  *     再对 SPI_CR1 寄存器执行一次写操作（调用 SPI_Cmd() 使能 
  *     SPI）。
  * @retval 无
  */
void SPI_I2S_ClearITPendingBit(SPI_TypeDef* SPIx, uint8_t SPI_I2S_IT)
{
  uint16_t itpos = 0;
  /* 检查参数 */
  assert_param(IS_SPI_ALL_PERIPH(SPIx));
  assert_param(IS_SPI_I2S_CLEAR_IT(SPI_I2S_IT));

  /* 获取 SPI 中断索引 */
  itpos = 0x01 << (SPI_I2S_IT & 0x0F);

  /* 清除选定的 SPI CRC 错误（CRCERR）中断挂起位 */
  SPIx->SR = (uint16_t)~itpos;
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
