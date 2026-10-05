/**
  ******************************************************************************
  * @file    stm32f10x_flash.h
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief   本文件包含 FLASH 固件库的全部函数原型。
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

/* 定义以防止递归包含 ----------------------------------------------------------*/
#ifndef __STM32F10x_FLASH_H
#define __STM32F10x_FLASH_H

#ifdef __cplusplus
 extern "C" {
#endif

/* 包含头文件 ----------------------------------------------------------------*/
#include "stm32f10x.h"

/** @addtogroup STM32F10x_StdPeriph_Driver
  * @{
  */

/** @addtogroup FLASH
  * @{
  */

/** @defgroup FLASH_Exported_Types
  * @{
  */

/** 
  * @brief  FLASH 状态  
  */

typedef enum
{ 
  FLASH_BUSY = 1,
  FLASH_ERROR_PG,
  FLASH_ERROR_WRP,
  FLASH_COMPLETE,
  FLASH_TIMEOUT
}FLASH_Status;

/**
  * @}
  */

/** @defgroup FLASH_Exported_Constants
  * @{
  */

/** @defgroup Flash_Latency 
  * @{
  */

#define FLASH_Latency_0                ((uint32_t)0x00000000)  /*!< FLASH 零延迟周期 */
#define FLASH_Latency_1                ((uint32_t)0x00000001)  /*!< FLASH 一个延迟周期 */
#define FLASH_Latency_2                ((uint32_t)0x00000002)  /*!< FLASH 两个延迟周期 */
#define IS_FLASH_LATENCY(LATENCY) (((LATENCY) == FLASH_Latency_0) || \
                                   ((LATENCY) == FLASH_Latency_1) || \
                                   ((LATENCY) == FLASH_Latency_2))
/**
  * @}
  */

/** @defgroup Half_Cycle_Enable_Disable 
  * @{
  */

#define FLASH_HalfCycleAccess_Enable   ((uint32_t)0x00000008)  /*!< FLASH 半周期访问使能 */
#define FLASH_HalfCycleAccess_Disable  ((uint32_t)0x00000000)  /*!< FLASH 半周期访问失能 */
#define IS_FLASH_HALFCYCLEACCESS_STATE(STATE) (((STATE) == FLASH_HalfCycleAccess_Enable) || \
                                               ((STATE) == FLASH_HalfCycleAccess_Disable)) 
/**
  * @}
  */

/** @defgroup Prefetch_Buffer_Enable_Disable 
  * @{
  */

#define FLASH_PrefetchBuffer_Enable    ((uint32_t)0x00000010)  /*!< FLASH 预取缓冲区使能 */
#define FLASH_PrefetchBuffer_Disable   ((uint32_t)0x00000000)  /*!< FLASH 预取缓冲区失能 */
#define IS_FLASH_PREFETCHBUFFER_STATE(STATE) (((STATE) == FLASH_PrefetchBuffer_Enable) || \
                                              ((STATE) == FLASH_PrefetchBuffer_Disable)) 
/**
  * @}
  */

/** @defgroup Option_Bytes_Write_Protection 
  * @{
  */

/* 用于 STM32 小容量和中容量器件的值 */
#define FLASH_WRProt_Pages0to3         ((uint32_t)0x00000001) /*!< STM32 小容量和中容量器件：页 0 至 3 */
#define FLASH_WRProt_Pages4to7         ((uint32_t)0x00000002) /*!< STM32 小容量和中容量器件：页 4 至 7 */
#define FLASH_WRProt_Pages8to11        ((uint32_t)0x00000004) /*!< STM32 小容量和中容量器件：页 8 至 11 */
#define FLASH_WRProt_Pages12to15       ((uint32_t)0x00000008) /*!< STM32 小容量和中容量器件：页 12 至 15 */
#define FLASH_WRProt_Pages16to19       ((uint32_t)0x00000010) /*!< STM32 小容量和中容量器件：页 16 至 19 */
#define FLASH_WRProt_Pages20to23       ((uint32_t)0x00000020) /*!< STM32 小容量和中容量器件：页 20 至 23 */
#define FLASH_WRProt_Pages24to27       ((uint32_t)0x00000040) /*!< STM32 小容量和中容量器件：页 24 至 27 */
#define FLASH_WRProt_Pages28to31       ((uint32_t)0x00000080) /*!< STM32 小容量和中容量器件：页 28 至 31 */

/* 用于 STM32 中容量器件的值 */
#define FLASH_WRProt_Pages32to35       ((uint32_t)0x00000100) /*!< STM32 中容量器件：页 32 至 35 */
#define FLASH_WRProt_Pages36to39       ((uint32_t)0x00000200) /*!< STM32 中容量器件：页 36 至 39 */
#define FLASH_WRProt_Pages40to43       ((uint32_t)0x00000400) /*!< STM32 中容量器件：页 40 至 43 */
#define FLASH_WRProt_Pages44to47       ((uint32_t)0x00000800) /*!< STM32 中容量器件：页 44 至 47 */
#define FLASH_WRProt_Pages48to51       ((uint32_t)0x00001000) /*!< STM32 中容量器件：页 48 至 51 */
#define FLASH_WRProt_Pages52to55       ((uint32_t)0x00002000) /*!< STM32 中容量器件：页 52 至 55 */
#define FLASH_WRProt_Pages56to59       ((uint32_t)0x00004000) /*!< STM32 中容量器件：页 56 至 59 */
#define FLASH_WRProt_Pages60to63       ((uint32_t)0x00008000) /*!< STM32 中容量器件：页 60 至 63 */
#define FLASH_WRProt_Pages64to67       ((uint32_t)0x00010000) /*!< STM32 中容量器件：页 64 至 67 */
#define FLASH_WRProt_Pages68to71       ((uint32_t)0x00020000) /*!< STM32 中容量器件：页 68 至 71 */
#define FLASH_WRProt_Pages72to75       ((uint32_t)0x00040000) /*!< STM32 中容量器件：页 72 至 75 */
#define FLASH_WRProt_Pages76to79       ((uint32_t)0x00080000) /*!< STM32 中容量器件：页 76 至 79 */
#define FLASH_WRProt_Pages80to83       ((uint32_t)0x00100000) /*!< STM32 中容量器件：页 80 至 83 */
#define FLASH_WRProt_Pages84to87       ((uint32_t)0x00200000) /*!< STM32 中容量器件：页 84 至 87 */
#define FLASH_WRProt_Pages88to91       ((uint32_t)0x00400000) /*!< STM32 中容量器件：页 88 至 91 */
#define FLASH_WRProt_Pages92to95       ((uint32_t)0x00800000) /*!< STM32 中容量器件：页 92 至 95 */
#define FLASH_WRProt_Pages96to99       ((uint32_t)0x01000000) /*!< STM32 中容量器件：页 96 至 99 */
#define FLASH_WRProt_Pages100to103     ((uint32_t)0x02000000) /*!< STM32 中容量器件：页 100 至 103 */
#define FLASH_WRProt_Pages104to107     ((uint32_t)0x04000000) /*!< STM32 中容量器件：页 104 至 107 */
#define FLASH_WRProt_Pages108to111     ((uint32_t)0x08000000) /*!< STM32 中容量器件：页 108 至 111 */
#define FLASH_WRProt_Pages112to115     ((uint32_t)0x10000000) /*!< STM32 中容量器件：页 112 至 115 */
#define FLASH_WRProt_Pages116to119     ((uint32_t)0x20000000) /*!< STM32 中容量器件：页 115 至 119 */
#define FLASH_WRProt_Pages120to123     ((uint32_t)0x40000000) /*!< STM32 中容量器件：页 120 至 123 */
#define FLASH_WRProt_Pages124to127     ((uint32_t)0x80000000) /*!< STM32 中容量器件：页 124 至 127 */

/* 用于 STM32 大容量和 STM32F10X 互联型器件的值 */
#define FLASH_WRProt_Pages0to1         ((uint32_t)0x00000001) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 0 至 1 */
#define FLASH_WRProt_Pages2to3         ((uint32_t)0x00000002) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 2 至 3 */
#define FLASH_WRProt_Pages4to5         ((uint32_t)0x00000004) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 4 至 5 */
#define FLASH_WRProt_Pages6to7         ((uint32_t)0x00000008) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 6 至 7 */
#define FLASH_WRProt_Pages8to9         ((uint32_t)0x00000010) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 8 至 9 */
#define FLASH_WRProt_Pages10to11       ((uint32_t)0x00000020) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 10 至 11 */
#define FLASH_WRProt_Pages12to13       ((uint32_t)0x00000040) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 12 至 13 */
#define FLASH_WRProt_Pages14to15       ((uint32_t)0x00000080) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 14 至 15 */
#define FLASH_WRProt_Pages16to17       ((uint32_t)0x00000100) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 16 至 17 */
#define FLASH_WRProt_Pages18to19       ((uint32_t)0x00000200) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 18 至 19 */
#define FLASH_WRProt_Pages20to21       ((uint32_t)0x00000400) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 20 至 21 */
#define FLASH_WRProt_Pages22to23       ((uint32_t)0x00000800) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 22 至 23 */
#define FLASH_WRProt_Pages24to25       ((uint32_t)0x00001000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 24 至 25 */
#define FLASH_WRProt_Pages26to27       ((uint32_t)0x00002000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 26 至 27 */
#define FLASH_WRProt_Pages28to29       ((uint32_t)0x00004000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 28 至 29 */
#define FLASH_WRProt_Pages30to31       ((uint32_t)0x00008000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 30 至 31 */
#define FLASH_WRProt_Pages32to33       ((uint32_t)0x00010000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 32 至 33 */
#define FLASH_WRProt_Pages34to35       ((uint32_t)0x00020000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 34 至 35 */
#define FLASH_WRProt_Pages36to37       ((uint32_t)0x00040000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 36 至 37 */
#define FLASH_WRProt_Pages38to39       ((uint32_t)0x00080000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 38 至 39 */
#define FLASH_WRProt_Pages40to41       ((uint32_t)0x00100000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 40 至 41 */
#define FLASH_WRProt_Pages42to43       ((uint32_t)0x00200000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 42 至 43 */
#define FLASH_WRProt_Pages44to45       ((uint32_t)0x00400000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 44 至 45 */
#define FLASH_WRProt_Pages46to47       ((uint32_t)0x00800000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 46 至 47 */
#define FLASH_WRProt_Pages48to49       ((uint32_t)0x01000000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 48 至 49 */
#define FLASH_WRProt_Pages50to51       ((uint32_t)0x02000000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 50 至 51 */
#define FLASH_WRProt_Pages52to53       ((uint32_t)0x04000000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 52 至 53 */
#define FLASH_WRProt_Pages54to55       ((uint32_t)0x08000000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 54 至 55 */
#define FLASH_WRProt_Pages56to57       ((uint32_t)0x10000000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 56 至 57 */
#define FLASH_WRProt_Pages58to59       ((uint32_t)0x20000000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 58 至 59 */
#define FLASH_WRProt_Pages60to61       ((uint32_t)0x40000000) /*!< STM32 大容量、XL-density 和互联型器件：
                                                                   页 60 至 61 */
#define FLASH_WRProt_Pages62to127      ((uint32_t)0x80000000) /*!< STM32 互联型器件：页 62 至 127 */
#define FLASH_WRProt_Pages62to255      ((uint32_t)0x80000000) /*!< STM32 中容量器件：页 62 至 255 */
#define FLASH_WRProt_Pages62to511      ((uint32_t)0x80000000) /*!< STM32 XL-density 器件：页 62 至 511 */

#define FLASH_WRProt_AllPages          ((uint32_t)0xFFFFFFFF) /*!< 所有页写保护 */

#define IS_FLASH_WRPROT_PAGE(PAGE) (((PAGE) != 0x00000000))

#define IS_FLASH_ADDRESS(ADDRESS) (((ADDRESS) >= 0x08000000) && ((ADDRESS) < 0x080FFFFF))

#define IS_OB_DATA_ADDRESS(ADDRESS) (((ADDRESS) == 0x1FFFF804) || ((ADDRESS) == 0x1FFFF806))

/**
  * @}
  */

/** @defgroup Option_Bytes_IWatchdog 
  * @{
  */

#define OB_IWDG_SW                     ((uint16_t)0x0001)  /*!< 选择软件 IWDG */
#define OB_IWDG_HW                     ((uint16_t)0x0000)  /*!< 选择硬件 IWDG */
#define IS_OB_IWDG_SOURCE(SOURCE) (((SOURCE) == OB_IWDG_SW) || ((SOURCE) == OB_IWDG_HW))

/**
  * @}
  */

/** @defgroup Option_Bytes_nRST_STOP 
  * @{
  */

#define OB_STOP_NoRST                  ((uint16_t)0x0002) /*!< 进入 STOP 模式时不产生复位 */
#define OB_STOP_RST                    ((uint16_t)0x0000) /*!< 进入 STOP 模式时产生复位 */
#define IS_OB_STOP_SOURCE(SOURCE) (((SOURCE) == OB_STOP_NoRST) || ((SOURCE) == OB_STOP_RST))

/**
  * @}
  */

/** @defgroup Option_Bytes_nRST_STDBY 
  * @{
  */

#define OB_STDBY_NoRST                 ((uint16_t)0x0004) /*!< 进入 STANDBY 模式时不产生复位 */
#define OB_STDBY_RST                   ((uint16_t)0x0000) /*!< 进入 STANDBY 模式时产生复位 */
#define IS_OB_STDBY_SOURCE(SOURCE) (((SOURCE) == OB_STDBY_NoRST) || ((SOURCE) == OB_STDBY_RST))

#ifdef STM32F10X_XL
/**
  * @}
  */
/** @defgroup FLASH_Boot
  * @{
  */
#define FLASH_BOOT_Bank1  ((uint16_t)0x0000) /*!< 启动时，若启动引脚设置为从用户 Flash 启动位置，
                                                  且选择此参数，则器件将从 Bank1 启动（默认） */
#define FLASH_BOOT_Bank2  ((uint16_t)0x0001) /*!< 启动时，若启动引脚设置为从用户 Flash 启动位置，
                                                  且选择此参数，则器件将从 Bank 2 或 Bank 1 启动，
                                                  具体取决于该存储块的激活情况 */
#define IS_FLASH_BOOT(BOOT) (((BOOT) == FLASH_BOOT_Bank1) || ((BOOT) == FLASH_BOOT_Bank2))
#endif
/**
  * @}
  */
/** @defgroup FLASH_Interrupts 
  * @{
  */
#ifdef STM32F10X_XL
#define FLASH_IT_BANK2_ERROR                 ((uint32_t)0x80000400)  /*!< FPEC BANK2 错误中断源 */
#define FLASH_IT_BANK2_EOP                   ((uint32_t)0x80001000)  /*!< FLASH BANK2 操作结束中断源 */

#define FLASH_IT_BANK1_ERROR                 FLASH_IT_ERROR          /*!< FPEC BANK1 错误中断源 */
#define FLASH_IT_BANK1_EOP                   FLASH_IT_EOP            /*!< FLASH BANK1 操作结束中断源 */

#define FLASH_IT_ERROR                 ((uint32_t)0x00000400)  /*!< FPEC BANK1 错误中断源 */
#define FLASH_IT_EOP                   ((uint32_t)0x00001000)  /*!< FLASH BANK1 操作结束中断源 */
#define IS_FLASH_IT(IT) ((((IT) & (uint32_t)0x7FFFEBFF) == 0x00000000) && (((IT) != 0x00000000)))
#else
#define FLASH_IT_ERROR                 ((uint32_t)0x00000400)  /*!< FPEC 错误中断源 */
#define FLASH_IT_EOP                   ((uint32_t)0x00001000)  /*!< FLASH 操作结束中断源 */
#define FLASH_IT_BANK1_ERROR           FLASH_IT_ERROR          /*!< FPEC BANK1 错误中断源 */
#define FLASH_IT_BANK1_EOP             FLASH_IT_EOP            /*!< FLASH BANK1 操作结束中断源 */

#define IS_FLASH_IT(IT) ((((IT) & (uint32_t)0xFFFFEBFF) == 0x00000000) && (((IT) != 0x00000000)))
#endif

/**
  * @}
  */

/** @defgroup FLASH_Flags 
  * @{
  */
#ifdef STM32F10X_XL
#define FLASH_FLAG_BANK2_BSY                 ((uint32_t)0x80000001)  /*!< FLASH BANK2 忙标志位 */
#define FLASH_FLAG_BANK2_EOP                 ((uint32_t)0x80000020)  /*!< FLASH BANK2 操作结束标志位 */
#define FLASH_FLAG_BANK2_PGERR               ((uint32_t)0x80000004)  /*!< FLASH BANK2 编程错误标志位 */
#define FLASH_FLAG_BANK2_WRPRTERR            ((uint32_t)0x80000010)  /*!< FLASH BANK2 写保护错误标志位 */

#define FLASH_FLAG_BANK1_BSY                 FLASH_FLAG_BSY       /*!< FLASH BANK1 忙标志位 */
#define FLASH_FLAG_BANK1_EOP                 FLASH_FLAG_EOP       /*!< FLASH BANK1 操作结束标志位 */
#define FLASH_FLAG_BANK1_PGERR               FLASH_FLAG_PGERR     /*!< FLASH BANK1 编程错误标志位 */
#define FLASH_FLAG_BANK1_WRPRTERR            FLASH_FLAG_WRPRTERR  /*!< FLASH BANK1 写保护错误标志位 */

#define FLASH_FLAG_BSY                 ((uint32_t)0x00000001)  /*!< FLASH 忙标志位 */
#define FLASH_FLAG_EOP                 ((uint32_t)0x00000020)  /*!< FLASH 操作结束标志位 */
#define FLASH_FLAG_PGERR               ((uint32_t)0x00000004)  /*!< FLASH 编程错误标志位 */
#define FLASH_FLAG_WRPRTERR            ((uint32_t)0x00000010)  /*!< FLASH 写保护错误标志位 */
#define FLASH_FLAG_OPTERR              ((uint32_t)0x00000001)  /*!< FLASH 选项字节错误标志位 */
 
#define IS_FLASH_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0x7FFFFFCA) == 0x00000000) && ((FLAG) != 0x00000000))
#define IS_FLASH_GET_FLAG(FLAG)  (((FLAG) == FLASH_FLAG_BSY) || ((FLAG) == FLASH_FLAG_EOP) || \
                                  ((FLAG) == FLASH_FLAG_PGERR) || ((FLAG) == FLASH_FLAG_WRPRTERR) || \
                                  ((FLAG) == FLASH_FLAG_OPTERR)|| \
                                  ((FLAG) == FLASH_FLAG_BANK1_BSY) || ((FLAG) == FLASH_FLAG_BANK1_EOP) || \
                                  ((FLAG) == FLASH_FLAG_BANK1_PGERR) || ((FLAG) == FLASH_FLAG_BANK1_WRPRTERR) || \
                                  ((FLAG) == FLASH_FLAG_BANK2_BSY) || ((FLAG) == FLASH_FLAG_BANK2_EOP) || \
                                  ((FLAG) == FLASH_FLAG_BANK2_PGERR) || ((FLAG) == FLASH_FLAG_BANK2_WRPRTERR))
#else
#define FLASH_FLAG_BSY                 ((uint32_t)0x00000001)  /*!< FLASH 忙标志位 */
#define FLASH_FLAG_EOP                 ((uint32_t)0x00000020)  /*!< FLASH 操作结束标志位 */
#define FLASH_FLAG_PGERR               ((uint32_t)0x00000004)  /*!< FLASH 编程错误标志位 */
#define FLASH_FLAG_WRPRTERR            ((uint32_t)0x00000010)  /*!< FLASH 写保护错误标志位 */
#define FLASH_FLAG_OPTERR              ((uint32_t)0x00000001)  /*!< FLASH 选项字节错误标志位 */

#define FLASH_FLAG_BANK1_BSY                 FLASH_FLAG_BSY       /*!< FLASH BANK1 忙标志位 */
#define FLASH_FLAG_BANK1_EOP                 FLASH_FLAG_EOP       /*!< FLASH BANK1 操作结束标志位 */
#define FLASH_FLAG_BANK1_PGERR               FLASH_FLAG_PGERR     /*!< FLASH BANK1 编程错误标志位 */
#define FLASH_FLAG_BANK1_WRPRTERR            FLASH_FLAG_WRPRTERR  /*!< FLASH BANK1 写保护错误标志位 */
 
#define IS_FLASH_CLEAR_FLAG(FLAG) ((((FLAG) & (uint32_t)0xFFFFFFCA) == 0x00000000) && ((FLAG) != 0x00000000))
#define IS_FLASH_GET_FLAG(FLAG)  (((FLAG) == FLASH_FLAG_BSY) || ((FLAG) == FLASH_FLAG_EOP) || \
                                  ((FLAG) == FLASH_FLAG_PGERR) || ((FLAG) == FLASH_FLAG_WRPRTERR) || \
								  ((FLAG) == FLASH_FLAG_BANK1_BSY) || ((FLAG) == FLASH_FLAG_BANK1_EOP) || \
                                  ((FLAG) == FLASH_FLAG_BANK1_PGERR) || ((FLAG) == FLASH_FLAG_BANK1_WRPRTERR) || \
                                  ((FLAG) == FLASH_FLAG_OPTERR))
#endif

/**
  * @}
  */

/**
  * @}
  */

/** @defgroup FLASH_Exported_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup FLASH_Exported_Functions
  * @{
  */

/*------------ 用于所有 STM32F10x 器件的函数 -----*/
void FLASH_SetLatency(uint32_t FLASH_Latency);
void FLASH_HalfCycleAccessCmd(uint32_t FLASH_HalfCycleAccess);
void FLASH_PrefetchBufferCmd(uint32_t FLASH_PrefetchBuffer);
void FLASH_Unlock(void);
void FLASH_Lock(void);
FLASH_Status FLASH_ErasePage(uint32_t Page_Address);
FLASH_Status FLASH_EraseAllPages(void);
FLASH_Status FLASH_EraseOptionBytes(void);
FLASH_Status FLASH_ProgramWord(uint32_t Address, uint32_t Data);
FLASH_Status FLASH_ProgramHalfWord(uint32_t Address, uint16_t Data);
FLASH_Status FLASH_ProgramOptionByteData(uint32_t Address, uint8_t Data);
FLASH_Status FLASH_EnableWriteProtection(uint32_t FLASH_Pages);
FLASH_Status FLASH_ReadOutProtection(FunctionalState NewState);
FLASH_Status FLASH_UserOptionByteConfig(uint16_t OB_IWDG, uint16_t OB_STOP, uint16_t OB_STDBY);
uint32_t FLASH_GetUserOptionByte(void);
uint32_t FLASH_GetWriteProtectionOptionByte(void);
FlagStatus FLASH_GetReadOutProtectionStatus(void);
FlagStatus FLASH_GetPrefetchBufferStatus(void);
void FLASH_ITConfig(uint32_t FLASH_IT, FunctionalState NewState);
FlagStatus FLASH_GetFlagStatus(uint32_t FLASH_FLAG);
void FLASH_ClearFlag(uint32_t FLASH_FLAG);
FLASH_Status FLASH_GetStatus(void);
FLASH_Status FLASH_WaitForLastOperation(uint32_t Timeout);

/*------------ 用于所有 STM32F10x 器件的新函数 -----*/
void FLASH_UnlockBank1(void);
void FLASH_LockBank1(void);
FLASH_Status FLASH_EraseAllBank1Pages(void);
FLASH_Status FLASH_GetBank1Status(void);
FLASH_Status FLASH_WaitForLastBank1Operation(uint32_t Timeout);

#ifdef STM32F10X_XL
/*---- 仅用于 STM32F10x_XL 大容量器件的新函数 -----*/
void FLASH_UnlockBank2(void);
void FLASH_LockBank2(void);
FLASH_Status FLASH_EraseAllBank2Pages(void);
FLASH_Status FLASH_GetBank2Status(void);
FLASH_Status FLASH_WaitForLastBank2Operation(uint32_t Timeout);
FLASH_Status FLASH_BootConfig(uint16_t FLASH_BOOT);
#endif

#ifdef __cplusplus
}
#endif

#endif /* __STM32F10x_FLASH_H */
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
