/**
  ******************************************************************************
  * @file    stm32f10x_fsmc.h
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件包含 FSMC 固件库所有函数的原型声明。
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

/* 定义用于防止递归包含 ------------------------------------------------*/
#ifndef __STM32F10x_FSMC_H
#define __STM32F10x_FSMC_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f10x.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @addtogroup FSMC
  * @{
  */

/** @defgroup FSMC_Exported_Types
  * @{
  */

/** 
  * @brief  NOR/SRAM 存储块的时序参数  
  */

typedef struct
{
  uint32_t FSMC_AddressSetupTime;       /*!< 定义用于配置所需 HCLK 周期数，
                                             即地址建立时间。 
                                             该参数可以是 0 到 0xF 之间的值。
                                             @note：不与同步 NOR Flash 存储器一起使用。 */

  uint32_t FSMC_AddressHoldTime;        /*!< 定义用于配置所需 HCLK 周期数，
                                             即地址保持时间。
                                             该参数可以是 0 到 0xF 之间的值。 
                                             @note：不与同步 NOR Flash 存储器一起使用。*/

  uint32_t FSMC_DataSetupTime;          /*!< 定义用于配置所需 HCLK 周期数，
                                             即数据建立时间。
                                             该参数可以是 0 到 0xFF 之间的值。
                                             @note：用于 SRAM、ROM 和异步复用 NOR 闪存。 */

  uint32_t FSMC_BusTurnAroundDuration;  /*!< 定义用于配置所需 HCLK 周期数，
                                             即总线转换时间。
                                             该参数可以是 0 到 0xF 之间的值。
                                             @note：仅用于复用 NOR 闪存。 */

  uint32_t FSMC_CLKDivision;            /*!< 定义 CLK 时钟输出信号的周期，以 HCLK 周期数表示。
                                             该参数可以是 1 到 0xF 之间的值。
                                             @note：该参数不用于异步 NOR 闪存、SRAM 或 ROM 访问。 */

  uint32_t FSMC_DataLatency;            /*!< 定义在获取第一个数据之前向存储器
                                             发出的存储器时钟周期数。
                                             该参数值取决于存储器类型，如下所示：
                                              - 对于 CRAM，必须设置为 0
                                              - 在异步 NOR、SRAM 或 ROM 访问中该值无关紧要
                                              - 在使能同步突发模式的 NOR 闪存中
                                                可以是 0 到 0xF 之间的值 */

  uint32_t FSMC_AccessMode;             /*!< 指定异步访问模式。 
                                             该参数可以是 @ref FSMC_Access_Mode 的取值 */
}FSMC_NORSRAMTimingInitTypeDef;

/** 
  * @brief  FSMC NOR/SRAM 初始化结构体定义
  */

typedef struct
{
  uint32_t FSMC_Bank;                /*!< 指定要使用的 NOR/SRAM 存储块。
                                          该参数可以是 @ref FSMC_NORSRAM_Bank 的取值 */

  uint32_t FSMC_DataAddressMux;      /*!< 指定地址和数据值是否
                                          在数据总线上复用。 
                                          该参数可以是 @ref FSMC_Data_Address_Bus_Multiplexing 的取值 */

  uint32_t FSMC_MemoryType;          /*!< 指定连接到相应存储块的
                                          外部存储器类型。
                                          该参数可以是 @ref FSMC_Memory_Type 的取值 */

  uint32_t FSMC_MemoryDataWidth;     /*!< 指定外部存储器件的宽度。
                                          该参数可以是 @ref FSMC_Data_Width 的取值 */

  uint32_t FSMC_BurstAccessMode;     /*!< 使能或失能闪存的突发访问模式，
                                          仅对同步突发闪存有效。
                                          该参数可以是 @ref FSMC_Burst_Access_Mode 的取值 */
                                       
  uint32_t FSMC_AsynchronousWait;     /*!< 使能或失能异步传输期间的等待信号，
                                          仅对异步闪存有效。
                                          该参数可以是 @ref FSMC_AsynchronousWait 的取值 */

  uint32_t FSMC_WaitSignalPolarity;  /*!< 指定等待信号极性，仅在突发模式下访问
                                          闪存时有效。
                                          该参数可以是 @ref FSMC_Wait_Signal_Polarity 的取值 */

  uint32_t FSMC_WrapMode;            /*!< 使能或失能闪存的回绕突发访问模式，
                                          仅在突发模式下访问闪存时有效。
                                          该参数可以是 @ref FSMC_Wrap_Mode 的取值 */

  uint32_t FSMC_WaitSignalActive;    /*!< 指定存储器是在等待状态之前一个
                                          时钟周期还是在等待状态期间置位等待信号，
                                          仅在突发模式下访问存储器时有效。 
                                          该参数可以是 @ref FSMC_Wait_Timing 的取值 */

  uint32_t FSMC_WriteOperation;      /*!< 使能或失能 FSMC 对选定存储块的写操作。 
                                          该参数可以是 @ref FSMC_Write_Operation 的取值 */

  uint32_t FSMC_WaitSignal;          /*!< 使能或失能通过等待信号插入
                                          等待状态，仅对突发模式下的闪存访问有效。 
                                          该参数可以是 @ref FSMC_Wait_Signal 的取值 */

  uint32_t FSMC_ExtendedMode;        /*!< 使能或失能扩展模式。
                                          该参数可以是 @ref FSMC_Extended_Mode 的取值 */

  uint32_t FSMC_WriteBurst;          /*!< 使能或失能写入突发操作。
                                          该参数可以是 @ref FSMC_Write_Burst 的取值 */ 

  FSMC_NORSRAMTimingInitTypeDef* FSMC_ReadWriteTimingStruct; /*!< 不使用扩展模式时读、写访问的时序参数 */  

  FSMC_NORSRAMTimingInitTypeDef* FSMC_WriteTimingStruct;     /*!< 使用扩展模式时写访问的时序参数 */      
}FSMC_NORSRAMInitTypeDef;

/** 
  * @brief  FSMC NAND 和 PCCARD 存储块的时序参数
  */

typedef struct
{
  uint32_t FSMC_SetupTime;      /*!< 定义在命令置位之前用于建立地址的
                                     HCLK 周期数，适用于 NAND 闪存对
                                     公共/属性存储器或 I/O 存储器空间的读/写访问
                                     （取决于要配置的存储器空间时序）。
                                     该参数可以是 0 到 0xFF 之间的值。*/

  uint32_t FSMC_WaitSetupTime;  /*!< 定义置位命令所需的最少 HCLK 周期数，
                                     适用于 NAND 闪存对公共/属性存储器
                                     或 I/O 存储器空间的读/写访问
                                     （取决于要配置的存储器空间时序）。 
                                     该参数可以是 0x00 到 0xFF 之间的数 */

  uint32_t FSMC_HoldSetupTime;  /*!< 定义命令撤销之后保持地址（写访问时
                                     还包括数据）所需的 HCLK 时钟周期数，
                                     适用于 NAND 闪存读/写访问公共/属性
                                     存储器或 I/O 存储器空间
                                     （取决于要配置的存储器空间时序）。
                                     该参数可以是 0x00 到 0xFF 之间的数 */

  uint32_t FSMC_HiZSetupTime;   /*!< 定义对 NAND 闪存进行公共/属性存储器或
                                     I/O 存储器空间写访问开始之后，数据总线
                                     保持为高阻态期间的 HCLK 时钟周期数
                                     （取决于要配置的存储器空间时序）。
                                     该参数可以是 0x00 到 0xFF 之间的数 */
}FSMC_NAND_PCCARDTimingInitTypeDef;

/** 
  * @brief  FSMC NAND 初始化结构体定义
  */

typedef struct
{
  uint32_t FSMC_Bank;              /*!< 指定要使用的 NAND 存储块。
                                      该参数可以是 @ref FSMC_NAND_Bank 的取值 */

  uint32_t FSMC_Waitfeature;      /*!< 使能或失能 NAND 存储块的等待功能。
                                       该参数可以是 @ref FSMC_Wait_feature 的任意取值 */

  uint32_t FSMC_MemoryDataWidth;  /*!< 指定外部存储器件的宽度。
                                       该参数可以是 @ref FSMC_Data_Width 的任意取值 */

  uint32_t FSMC_ECC;              /*!< 使能或失能 ECC 计算。
                                       该参数可以是 @ref FSMC_ECC 的任意取值 */

  uint32_t FSMC_ECCPageSize;      /*!< 定义扩展 ECC 的页大小。
                                       该参数可以是 @ref FSMC_ECC_Page_Size 的任意取值 */

  uint32_t FSMC_TCLRSetupTime;    /*!< 定义用于配置
                                       CLE 为低与 RE 为低之间延迟所需的 HCLK 周期数。
                                       该参数可以是 0 到 0xFF 之间的值。 */

  uint32_t FSMC_TARSetupTime;     /*!< 定义用于配置
                                       ALE 为低与 RE 为低之间延迟所需的 HCLK 周期数。
                                       该参数可以是 0x0 到 0xFF 之间的数 */ 

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct;   /*!< FSMC 公共空间时序 */ 

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct; /*!< FSMC 属性空间时序 */
}FSMC_NANDInitTypeDef;

/** 
  * @brief  FSMC PCCARD 初始化结构体定义
  */

typedef struct
{
  uint32_t FSMC_Waitfeature;    /*!< 使能或失能存储块的等待功能。
                                    该参数可以是 @ref FSMC_Wait_feature 的任意取值 */

  uint32_t FSMC_TCLRSetupTime;  /*!< 定义用于配置
                                     CLE 为低与 RE 为低之间延迟所需的 HCLK 周期数。
                                     该参数可以是 0 到 0xFF 之间的值。 */

  uint32_t FSMC_TARSetupTime;   /*!< 定义用于配置
                                     ALE 为低与 RE 为低之间延迟所需的 HCLK 周期数。
                                     该参数可以是 0x0 到 0xFF 之间的数 */ 

  
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_CommonSpaceTimingStruct; /*!< FSMC 公共空间时序 */

  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_AttributeSpaceTimingStruct;  /*!< FSMC 属性空间时序 */ 
  
  FSMC_NAND_PCCARDTimingInitTypeDef*  FSMC_IOSpaceTimingStruct; /*!< FSMC IO 空间时序 */  
}FSMC_PCCARDInitTypeDef;

/**
  * @}
  */

/** @defgroup FSMC_Exported_Constants
  * @{
  */

/** @defgroup FSMC_NORSRAM_Bank 
  * @{
  */
#define FSMC_Bank1_NORSRAM1                             ((uint32_t)0x00000000)
#define FSMC_Bank1_NORSRAM2                             ((uint32_t)0x00000002)
#define FSMC_Bank1_NORSRAM3                             ((uint32_t)0x00000004)
#define FSMC_Bank1_NORSRAM4                             ((uint32_t)0x00000006)
/**
  * @}
  */

/** @defgroup FSMC_NAND_Bank 
  * @{
  */  
#define FSMC_Bank2_NAND                                 ((uint32_t)0x00000010)
#define FSMC_Bank3_NAND                                 ((uint32_t)0x00000100)
/**
  * @}
  */

/** @defgroup FSMC_PCCARD_Bank 
  * @{
  */    
#define FSMC_Bank4_PCCARD                               ((uint32_t)0x00001000)
/**
  * @}
  */

#define IS_FSMC_NORSRAM_BANK(BANK) (((BANK) == FSMC_Bank1_NORSRAM1) || \
                                    ((BANK) == FSMC_Bank1_NORSRAM2) || \
                                    ((BANK) == FSMC_Bank1_NORSRAM3) || \
                                    ((BANK) == FSMC_Bank1_NORSRAM4))

#define IS_FSMC_NAND_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
                                 ((BANK) == FSMC_Bank3_NAND))

#define IS_FSMC_GETFLAG_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
                                    ((BANK) == FSMC_Bank3_NAND) || \
                                    ((BANK) == FSMC_Bank4_PCCARD))

#define IS_FSMC_IT_BANK(BANK) (((BANK) == FSMC_Bank2_NAND) || \
                               ((BANK) == FSMC_Bank3_NAND) || \
                               ((BANK) == FSMC_Bank4_PCCARD))

/** @defgroup NOR_SRAM_Controller 
  * @{
  */

/** @defgroup FSMC_Data_Address_Bus_Multiplexing 
  * @{
  */

#define FSMC_DataAddressMux_Disable                       ((uint32_t)0x00000000)
#define FSMC_DataAddressMux_Enable                        ((uint32_t)0x00000002)
#define IS_FSMC_MUX(MUX) (((MUX) == FSMC_DataAddressMux_Disable) || \
                          ((MUX) == FSMC_DataAddressMux_Enable))

/**
  * @}
  */

/** @defgroup FSMC_Memory_Type 
  * @{
  */

#define FSMC_MemoryType_SRAM                            ((uint32_t)0x00000000)
#define FSMC_MemoryType_PSRAM                           ((uint32_t)0x00000004)
#define FSMC_MemoryType_NOR                             ((uint32_t)0x00000008)
#define IS_FSMC_MEMORY(MEMORY) (((MEMORY) == FSMC_MemoryType_SRAM) || \
                                ((MEMORY) == FSMC_MemoryType_PSRAM)|| \
                                ((MEMORY) == FSMC_MemoryType_NOR))

/**
  * @}
  */

/** @defgroup FSMC_Data_Width 
  * @{
  */

#define FSMC_MemoryDataWidth_8b                         ((uint32_t)0x00000000)
#define FSMC_MemoryDataWidth_16b                        ((uint32_t)0x00000010)
#define IS_FSMC_MEMORY_WIDTH(WIDTH) (((WIDTH) == FSMC_MemoryDataWidth_8b) || \
                                     ((WIDTH) == FSMC_MemoryDataWidth_16b))

/**
  * @}
  */

/** @defgroup FSMC_Burst_Access_Mode 
  * @{
  */

#define FSMC_BurstAccessMode_Disable                    ((uint32_t)0x00000000) 
#define FSMC_BurstAccessMode_Enable                     ((uint32_t)0x00000100)
#define IS_FSMC_BURSTMODE(STATE) (((STATE) == FSMC_BurstAccessMode_Disable) || \
                                  ((STATE) == FSMC_BurstAccessMode_Enable))
/**
  * @}
  */
  
/** @defgroup FSMC_AsynchronousWait 
  * @{
  */
#define FSMC_AsynchronousWait_Disable                   ((uint32_t)0x00000000)
#define FSMC_AsynchronousWait_Enable                    ((uint32_t)0x00008000)
#define IS_FSMC_ASYNWAIT(STATE) (((STATE) == FSMC_AsynchronousWait_Disable) || \
                                 ((STATE) == FSMC_AsynchronousWait_Enable))

/**
  * @}
  */
  
/** @defgroup FSMC_Wait_Signal_Polarity 
  * @{
  */

#define FSMC_WaitSignalPolarity_Low                     ((uint32_t)0x00000000)
#define FSMC_WaitSignalPolarity_High                    ((uint32_t)0x00000200)
#define IS_FSMC_WAIT_POLARITY(POLARITY) (((POLARITY) == FSMC_WaitSignalPolarity_Low) || \
                                         ((POLARITY) == FSMC_WaitSignalPolarity_High)) 

/**
  * @}
  */

/** @defgroup FSMC_Wrap_Mode 
  * @{
  */

#define FSMC_WrapMode_Disable                           ((uint32_t)0x00000000)
#define FSMC_WrapMode_Enable                            ((uint32_t)0x00000400) 
#define IS_FSMC_WRAP_MODE(MODE) (((MODE) == FSMC_WrapMode_Disable) || \
                                 ((MODE) == FSMC_WrapMode_Enable))

/**
  * @}
  */

/** @defgroup FSMC_Wait_Timing 
  * @{
  */

#define FSMC_WaitSignalActive_BeforeWaitState           ((uint32_t)0x00000000)
#define FSMC_WaitSignalActive_DuringWaitState           ((uint32_t)0x00000800) 
#define IS_FSMC_WAIT_SIGNAL_ACTIVE(ACTIVE) (((ACTIVE) == FSMC_WaitSignalActive_BeforeWaitState) || \
                                            ((ACTIVE) == FSMC_WaitSignalActive_DuringWaitState))

/**
  * @}
  */

/** @defgroup FSMC_Write_Operation 
  * @{
  */

#define FSMC_WriteOperation_Disable                     ((uint32_t)0x00000000)
#define FSMC_WriteOperation_Enable                      ((uint32_t)0x00001000)
#define IS_FSMC_WRITE_OPERATION(OPERATION) (((OPERATION) == FSMC_WriteOperation_Disable) || \
                                            ((OPERATION) == FSMC_WriteOperation_Enable))
                              
/**
  * @}
  */

/** @defgroup FSMC_Wait_Signal 
  * @{
  */

#define FSMC_WaitSignal_Disable                         ((uint32_t)0x00000000)
#define FSMC_WaitSignal_Enable                          ((uint32_t)0x00002000) 
#define IS_FSMC_WAITE_SIGNAL(SIGNAL) (((SIGNAL) == FSMC_WaitSignal_Disable) || \
                                      ((SIGNAL) == FSMC_WaitSignal_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Extended_Mode 
  * @{
  */

#define FSMC_ExtendedMode_Disable                       ((uint32_t)0x00000000)
#define FSMC_ExtendedMode_Enable                        ((uint32_t)0x00004000)

#define IS_FSMC_EXTENDED_MODE(MODE) (((MODE) == FSMC_ExtendedMode_Disable) || \
                                     ((MODE) == FSMC_ExtendedMode_Enable)) 

/**
  * @}
  */

/** @defgroup FSMC_Write_Burst 
  * @{
  */

#define FSMC_WriteBurst_Disable                         ((uint32_t)0x00000000)
#define FSMC_WriteBurst_Enable                          ((uint32_t)0x00080000) 
#define IS_FSMC_WRITE_BURST(BURST) (((BURST) == FSMC_WriteBurst_Disable) || \
                                    ((BURST) == FSMC_WriteBurst_Enable))
/**
  * @}
  */

/** @defgroup FSMC_Address_Setup_Time 
  * @{
  */

#define IS_FSMC_ADDRESS_SETUP_TIME(TIME) ((TIME) <= 0xF)

/**
  * @}
  */

/** @defgroup FSMC_Address_Hold_Time 
  * @{
  */

#define IS_FSMC_ADDRESS_HOLD_TIME(TIME) ((TIME) <= 0xF)

/**
  * @}
  */

/** @defgroup FSMC_Data_Setup_Time 
  * @{
  */

#define IS_FSMC_DATASETUP_TIME(TIME) (((TIME) > 0) && ((TIME) <= 0xFF))

/**
  * @}
  */

/** @defgroup FSMC_Bus_Turn_around_Duration 
  * @{
  */

#define IS_FSMC_TURNAROUND_TIME(TIME) ((TIME) <= 0xF)

/**
  * @}
  */

/** @defgroup FSMC_CLK_Division 
  * @{
  */

#define IS_FSMC_CLK_DIV(DIV) ((DIV) <= 0xF)

/**
  * @}
  */

/** @defgroup FSMC_Data_Latency 
  * @{
  */

#define IS_FSMC_DATA_LATENCY(LATENCY) ((LATENCY) <= 0xF)

/**
  * @}
  */

/** @defgroup FSMC_Access_Mode 
  * @{
  */

#define FSMC_AccessMode_A                               ((uint32_t)0x00000000)
#define FSMC_AccessMode_B                               ((uint32_t)0x10000000) 
#define FSMC_AccessMode_C                               ((uint32_t)0x20000000)
#define FSMC_AccessMode_D                               ((uint32_t)0x30000000)
#define IS_FSMC_ACCESS_MODE(MODE) (((MODE) == FSMC_AccessMode_A) || \
                                   ((MODE) == FSMC_AccessMode_B) || \
                                   ((MODE) == FSMC_AccessMode_C) || \
                                   ((MODE) == FSMC_AccessMode_D)) 

/**
  * @}
  */

/**
  * @}
  */
  
/** @defgroup NAND_PCCARD_Controller 
  * @{
  */

/** @defgroup FSMC_Wait_feature 
  * @{
  */

#define FSMC_Waitfeature_Disable                        ((uint32_t)0x00000000)
#define FSMC_Waitfeature_Enable                         ((uint32_t)0x00000002)
#define IS_FSMC_WAIT_FEATURE(FEATURE) (((FEATURE) == FSMC_Waitfeature_Disable) || \
                                       ((FEATURE) == FSMC_Waitfeature_Enable))

/**
  * @}
  */


/** @defgroup FSMC_ECC 
  * @{
  */

#define FSMC_ECC_Disable                                ((uint32_t)0x00000000)
#define FSMC_ECC_Enable                                 ((uint32_t)0x00000040)
#define IS_FSMC_ECC_STATE(STATE) (((STATE) == FSMC_ECC_Disable) || \
                                  ((STATE) == FSMC_ECC_Enable))

/**
  * @}
  */

/** @defgroup FSMC_ECC_Page_Size 
  * @{
  */

#define FSMC_ECCPageSize_256Bytes                       ((uint32_t)0x00000000)
#define FSMC_ECCPageSize_512Bytes                       ((uint32_t)0x00020000)
#define FSMC_ECCPageSize_1024Bytes                      ((uint32_t)0x00040000)
#define FSMC_ECCPageSize_2048Bytes                      ((uint32_t)0x00060000)
#define FSMC_ECCPageSize_4096Bytes                      ((uint32_t)0x00080000)
#define FSMC_ECCPageSize_8192Bytes                      ((uint32_t)0x000A0000)
#define IS_FSMC_ECCPAGE_SIZE(SIZE) (((SIZE) == FSMC_ECCPageSize_256Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_512Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_1024Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_2048Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_4096Bytes) || \
                                    ((SIZE) == FSMC_ECCPageSize_8192Bytes))

/**
  * @}
  */

/** @defgroup FSMC_TCLR_Setup_Time 
  * @{
  */

#define IS_FSMC_TCLR_TIME(TIME) ((TIME) <= 0xFF)

/**
  * @}
  */

/** @defgroup FSMC_TAR_Setup_Time 
  * @{
  */

#define IS_FSMC_TAR_TIME(TIME) ((TIME) <= 0xFF)

/**
  * @}
  */

/** @defgroup FSMC_Setup_Time 
  * @{
  */

#define IS_FSMC_SETUP_TIME(TIME) ((TIME) <= 0xFF)

/**
  * @}
  */

/** @defgroup FSMC_Wait_Setup_Time 
  * @{
  */

#define IS_FSMC_WAIT_TIME(TIME) ((TIME) <= 0xFF)

/**
  * @}
  */

/** @defgroup FSMC_Hold_Setup_Time 
  * @{
  */

#define IS_FSMC_HOLD_TIME(TIME) ((TIME) <= 0xFF)

/**
  * @}
  */

/** @defgroup FSMC_HiZ_Setup_Time 
  * @{
  */

#define IS_FSMC_HIZ_TIME(TIME) ((TIME) <= 0xFF)

/**
  * @}
  */

/** @defgroup FSMC_Interrupt_sources 
  * @{
  */

#define FSMC_IT_RisingEdge                              ((uint32_t)0x00000008)
#define FSMC_IT_Level                                   ((uint32_t)0x00000010)
#define FSMC_IT_FallingEdge                             ((uint32_t)0x00000020)
#define IS_FSMC_IT(IT) ((((IT) & (uint32_t)0xFFFFFFC7) == 0x00000000) && ((IT) != 0x00000000))
#define IS_FSMC_GET_IT(IT) (((IT) == FSMC_IT_RisingEdge) || \
                            ((IT) == FSMC_IT_Level) || \
                            ((IT) == FSMC_IT_FallingEdge)) 
/**
  * @}
  */

/** @defgroup FSMC_Flags 
  * @{
  */

#define FSMC_FLAG_RisingEdge                            ((uint32_t)0x00000001)
#define FSMC_FLAG_Level                                 ((uint32_t)0x00000002)
#define FSMC_FLAG_FallingEdge                           ((uint32_t)0x00000004)
#define FSMC_FLAG_FEMPT                                 ((uint32_t)0x00000040)
#define IS_FSMC_GET_FLAG(FLAG) (((FLAG) == FSMC_FLAG_RisingEdge) || \
                                ((FLAG) == FSMC_FLAG_Level) || \
                                ((FLAG) == FSMC_FLAG_FallingEdge) || \
                                ((FLAG) == FSMC_FLAG_FEMPT))

#define IS_FSMC_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFFF8) == 0x00000000) && ((FLAG) != 0x00000000))

/**
  * @}
  */

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup FSMC_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup FSMC_Exported_Functions
  * @{
  */

void FSMC_NORSRAMDeInit(uint32_t FSMC_Bank);
void FSMC_NANDDeInit(uint32_t FSMC_Bank);
void FSMC_PCCARDDeInit(void);
void FSMC_NORSRAMInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
void FSMC_NANDInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
void FSMC_PCCARDInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
void FSMC_NORSRAMStructInit(FSMC_NORSRAMInitTypeDef* FSMC_NORSRAMInitStruct);
void FSMC_NANDStructInit(FSMC_NANDInitTypeDef* FSMC_NANDInitStruct);
void FSMC_PCCARDStructInit(FSMC_PCCARDInitTypeDef* FSMC_PCCARDInitStruct);
void FSMC_NORSRAMCmd(uint32_t FSMC_Bank, FunctionalState NewState);
void FSMC_NANDCmd(uint32_t FSMC_Bank, FunctionalState NewState);
void FSMC_PCCARDCmd(FunctionalState NewState);
void FSMC_NANDECCCmd(uint32_t FSMC_Bank, FunctionalState NewState);
uint32_t FSMC_GetECC(uint32_t FSMC_Bank);
void FSMC_ITConfig(uint32_t FSMC_Bank, uint32_t FSMC_IT, FunctionalState NewState);
FlagStatus FSMC_GetFlagStatus(uint32_t FSMC_Bank, uint32_t FSMC_FLAG);
void FSMC_ClearFlag(uint32_t FSMC_Bank, uint32_t FSMC_FLAG);
ITStatus FSMC_GetITStatus(uint32_t FSMC_Bank, uint32_t FSMC_IT);
void FSMC_ClearITPendingBit(uint32_t FSMC_Bank, uint32_t FSMC_IT);

#ifdef __cplusplus
}
#endif

#endif /*__STM32F10x_FSMC_H */
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
