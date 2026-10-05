/**************************************************************************//**
 * @file     core_cm3.h
 * @brief CMSIS Cortex-M3 内核外设访问层头文件
 * @version  V1.30
 * @date     30. October 2009
 *
 * @note
 * Copyright (C) 2009 ARM Limited. All rights reserved.
 *
 * @par
 * ARM Limited (ARM) is supplying this software for use with Cortex-M 
 * processor based microcontrollers.  This file can be freely distributed 
 * within development tools that are supporting such ARM based processors. 
 *
 * @par
 * THIS SOFTWARE IS PROVIDED "AS IS".  NO WARRANTIES, WHETHER EXPRESS, IMPLIED
 * OR STATUTORY, INCLUDING, BUT NOT LIMITED TO, IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE APPLY TO THIS SOFTWARE.
 * ARM SHALL NOT, IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL, OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 *
 ******************************************************************************/

#ifndef __CM3_CORE_H__
#define __CM3_CORE_H__

/** @addtogroup CMSIS_CM3_core_LintCinfiguration CMSIS CM3 内核 Lint 配置
 *
 * 将被抑制且不显示的 Lint 消息列表：
 *   - Error 10: \n
 *     register uint32_t __regBasePri         __asm("basepri"); \n
 *     Error 10: Expecting ';'
 * .
 *   - Error 530: \n
 *     return(__regBasePri); \n
 *     Warning 530: Symbol '__regBasePri' (line 264) not initialized
 * . 
 *   - Error 550: \n
 *     __regBasePri = (basePri & 0x1ff); \n
 *     Warning 550: Symbol '__regBasePri' (line 271) not accessed
 * .
 *   - Error 754: \n
 *     uint32_t RESERVED0[24]; \n
 *     Info 754: local structure member '<some, not used in the HAL>' (line 109, file ./cm3_core.h) not referenced
 * .
 *   - Error 750: \n
 *     #define __CM3_CORE_H__ \n
 *     Info 750: local macro '__CM3_CORE_H__' (line 43, file./cm3_core.h) not referenced
 * .
 *   - Error 528: \n
 *     static __INLINE void NVIC_DisableIRQ(uint32_t IRQn) \n
 *     Warning 528: Symbol 'NVIC_DisableIRQ(unsigned int)' (line 419, file ./cm3_core.h) not referenced
 * .
 *   - Error 751: \n
 *     } InterruptType_Type; \n
 *     Info 751: local typedef 'InterruptType_Type' (line 170, file ./cm3_core.h) not referenced
 * .
 * 注意：要重新启用某条消息，请在 'lint' 前插入一个空格 *
 *
 */

/*lint -save */
/*lint -e10  */
/*lint -e530 */
/*lint -e550 */
/*lint -e754 */
/*lint -e750 */
/*lint -e528 */
/*lint -e751 */


/** @addtogroup CMSIS_CM3_core_definitions CM3 内核定义
  本文件定义 CMSIS 内核的所有结构和符号：
    - CMSIS 版本号
    - Cortex-M 内核寄存器和位域
    - Cortex-M 内核外设基地址
  @{
 */

#ifdef __cplusplus
 extern "C" {
#endif 

#define __CM3_CMSIS_VERSION_MAIN  (0x01)                                                       /*!< [31:16] CMSIS HAL 主版本号 */
#define __CM3_CMSIS_VERSION_SUB   (0x30)                                                       /*!< [15:0] CMSIS HAL 子版本号  */
#define __CM3_CMSIS_VERSION       ((__CM3_CMSIS_VERSION_MAIN << 16) | __CM3_CMSIS_VERSION_SUB) /*!< CMSIS HAL 版本号       */

#define __CORTEX_M                (0x03)                                                       /*!< Cortex 内核                    */

#include <stdint.h>                           /* 包含标准类型 */

#if defined (__ICCARM__)
  #include <intrinsics.h>                     /* IAR 内建函数   */
#endif


#ifndef __NVIC_PRIO_BITS
  #define __NVIC_PRIO_BITS    4               /*!< NVIC 优先级位数的标准定义 */
#endif




/**
 * IO 定义
 *
 * 定义外设寄存器的访问限制
 */

#ifdef __cplusplus
  #define     __I     volatile                /*!< 定义“只读”权限      */
#else
  #define     __I     volatile const          /*!< 定义“只读”权限      */
#endif
#define     __O     volatile                  /*!< 定义“只写”权限     */
#define     __IO    volatile                  /*!< 定义“读 / 写”权限   */



/*******************************************************************************
 *                 寄存器抽象
 ******************************************************************************/
/** @addtogroup CMSIS_CM3_core_register CMSIS CM3 内核寄存器
 @{
*/


/** @addtogroup CMSIS_CM3_NVIC CMSIS CM3 NVIC
  嵌套向量中断控制器（NVIC）的存储器映射结构
  @{
 */
typedef struct
{
  __IO uint32_t ISER[8];                      /*!< 偏移：0x000 中断置能寄存器           */
       uint32_t RESERVED0[24];                                   
  __IO uint32_t ICER[8];                      /*!< 偏移：0x080 中断清能寄存器         */
       uint32_t RSERVED1[24];                                    
  __IO uint32_t ISPR[8];                      /*!< 偏移：0x100 中断置挂起寄存器          */
       uint32_t RESERVED2[24];                                   
  __IO uint32_t ICPR[8];                      /*!< 偏移：0x180 中断清挂起寄存器        */
       uint32_t RESERVED3[24];                                   
  __IO uint32_t IABR[8];                      /*!< 偏移：0x200 中断激活位寄存器           */
       uint32_t RESERVED4[56];                                   
  __IO uint8_t  IP[240];                      /*!< 偏移：0x300 中断优先级寄存器（8 位宽） */
       uint32_t RESERVED5[644];                                  
  __O  uint32_t STIR;                         /*!< 偏移：0xE00 软件触发中断寄存器     */
}  NVIC_Type;                                               
/*@}*/ /* CMSIS_CM3_NVIC 组结束 */


/** @addtogroup CMSIS_CM3_SCB CMSIS CM3 SCB
  系统控制块（SCB）的存储器映射结构
  @{
 */
typedef struct
{
  __I  uint32_t CPUID;                        /*!< 偏移：0x00 CPU ID 基地址寄存器                                  */
  __IO uint32_t ICSR;                         /*!< 偏移：0x04 中断控制状态寄存器                      */
  __IO uint32_t VTOR;                         /*!< 偏移：0x08 向量表偏移寄存器                          */
  __IO uint32_t AIRCR;                        /*!< 偏移：0x0C 应用中断 / 复位控制寄存器        */
  __IO uint32_t SCR;                          /*!< 偏移：0x10 系统控制寄存器                               */
  __IO uint32_t CCR;                          /*!< 偏移：0x14 配置控制寄存器                        */
  __IO uint8_t  SHP[12];                      /*!< 偏移：0x18 系统异常优先级寄存器（4-7、8-11、12-15） */
  __IO uint32_t SHCSR;                        /*!< 偏移：0x24 系统异常控制与状态寄存器             */
  __IO uint32_t CFSR;                         /*!< 偏移：0x28 可配置故障状态寄存器                    */
  __IO uint32_t HFSR;                         /*!< 偏移：0x2C 硬故障状态寄存器                            */
  __IO uint32_t DFSR;                         /*!< 偏移：0x30 调试故障状态寄存器                           */
  __IO uint32_t MMFAR;                        /*!< 偏移：0x34 存储器管理地址寄存器                           */
  __IO uint32_t BFAR;                         /*!< 偏移：0x38 总线故障地址寄存器                            */
  __IO uint32_t AFSR;                         /*!< 偏移：0x3C 辅助故障状态寄存器                       */
  __I  uint32_t PFR[2];                       /*!< 偏移：0x40 处理器特性寄存器                            */
  __I  uint32_t DFR;                          /*!< 偏移：0x48 调试特性寄存器                                */
  __I  uint32_t ADR;                          /*!< 偏移：0x4C 辅助特性寄存器                            */
  __I  uint32_t MMFR[4];                      /*!< 偏移：0x50 存储器模型特性寄存器                         */
  __I  uint32_t ISAR[5];                      /*!< 偏移：0x60 ISA 特性寄存器                                  */
} SCB_Type;                                                

/* SCB CPUID 寄存器定义 */
#define SCB_CPUID_IMPLEMENTER_Pos          24                                             /*!< SCB CPUID: IMPLEMENTER 位置 */
#define SCB_CPUID_IMPLEMENTER_Msk          (0xFFul << SCB_CPUID_IMPLEMENTER_Pos)          /*!< SCB CPUID: IMPLEMENTER 屏蔽 */

#define SCB_CPUID_VARIANT_Pos              20                                             /*!< SCB CPUID: VARIANT 位置 */
#define SCB_CPUID_VARIANT_Msk              (0xFul << SCB_CPUID_VARIANT_Pos)               /*!< SCB CPUID: VARIANT 屏蔽 */

#define SCB_CPUID_PARTNO_Pos                4                                             /*!< SCB CPUID: PARTNO 位置 */
#define SCB_CPUID_PARTNO_Msk               (0xFFFul << SCB_CPUID_PARTNO_Pos)              /*!< SCB CPUID: PARTNO 屏蔽 */

#define SCB_CPUID_REVISION_Pos              0                                             /*!< SCB CPUID: REVISION 位置 */
#define SCB_CPUID_REVISION_Msk             (0xFul << SCB_CPUID_REVISION_Pos)              /*!< SCB CPUID: REVISION 屏蔽 */

/* SCB 中断控制状态寄存器定义 */
#define SCB_ICSR_NMIPENDSET_Pos            31                                             /*!< SCB ICSR: NMIPENDSET 位置 */
#define SCB_ICSR_NMIPENDSET_Msk            (1ul << SCB_ICSR_NMIPENDSET_Pos)               /*!< SCB ICSR: NMIPENDSET 屏蔽 */

#define SCB_ICSR_PENDSVSET_Pos             28                                             /*!< SCB ICSR: PENDSVSET 位置 */
#define SCB_ICSR_PENDSVSET_Msk             (1ul << SCB_ICSR_PENDSVSET_Pos)                /*!< SCB ICSR: PENDSVSET 屏蔽 */

#define SCB_ICSR_PENDSVCLR_Pos             27                                             /*!< SCB ICSR: PENDSVCLR 位置 */
#define SCB_ICSR_PENDSVCLR_Msk             (1ul << SCB_ICSR_PENDSVCLR_Pos)                /*!< SCB ICSR: PENDSVCLR 屏蔽 */

#define SCB_ICSR_PENDSTSET_Pos             26                                             /*!< SCB ICSR: PENDSTSET 位置 */
#define SCB_ICSR_PENDSTSET_Msk             (1ul << SCB_ICSR_PENDSTSET_Pos)                /*!< SCB ICSR: PENDSTSET 屏蔽 */

#define SCB_ICSR_PENDSTCLR_Pos             25                                             /*!< SCB ICSR: PENDSTCLR 位置 */
#define SCB_ICSR_PENDSTCLR_Msk             (1ul << SCB_ICSR_PENDSTCLR_Pos)                /*!< SCB ICSR: PENDSTCLR 屏蔽 */

#define SCB_ICSR_ISRPREEMPT_Pos            23                                             /*!< SCB ICSR: ISRPREEMPT 位置 */
#define SCB_ICSR_ISRPREEMPT_Msk            (1ul << SCB_ICSR_ISRPREEMPT_Pos)               /*!< SCB ICSR: ISRPREEMPT 屏蔽 */

#define SCB_ICSR_ISRPENDING_Pos            22                                             /*!< SCB ICSR: ISRPENDING 位置 */
#define SCB_ICSR_ISRPENDING_Msk            (1ul << SCB_ICSR_ISRPENDING_Pos)               /*!< SCB ICSR: ISRPENDING 屏蔽 */

#define SCB_ICSR_VECTPENDING_Pos           12                                             /*!< SCB ICSR: VECTPENDING 位置 */
#define SCB_ICSR_VECTPENDING_Msk           (0x1FFul << SCB_ICSR_VECTPENDING_Pos)          /*!< SCB ICSR: VECTPENDING 屏蔽 */

#define SCB_ICSR_RETTOBASE_Pos             11                                             /*!< SCB ICSR: RETTOBASE 位置 */
#define SCB_ICSR_RETTOBASE_Msk             (1ul << SCB_ICSR_RETTOBASE_Pos)                /*!< SCB ICSR: RETTOBASE 屏蔽 */

#define SCB_ICSR_VECTACTIVE_Pos             0                                             /*!< SCB ICSR: VECTACTIVE 位置 */
#define SCB_ICSR_VECTACTIVE_Msk            (0x1FFul << SCB_ICSR_VECTACTIVE_Pos)           /*!< SCB ICSR: VECTACTIVE 屏蔽 */

/* SCB 中断控制状态寄存器定义 */
#define SCB_VTOR_TBLBASE_Pos               29                                             /*!< SCB VTOR: TBLBASE 位置 */
#define SCB_VTOR_TBLBASE_Msk               (0x1FFul << SCB_VTOR_TBLBASE_Pos)              /*!< SCB VTOR: TBLBASE 屏蔽 */

#define SCB_VTOR_TBLOFF_Pos                 7                                             /*!< SCB VTOR: TBLOFF 位置 */
#define SCB_VTOR_TBLOFF_Msk                (0x3FFFFFul << SCB_VTOR_TBLOFF_Pos)            /*!< SCB VTOR: TBLOFF 屏蔽 */

/* SCB 应用中断与复位控制寄存器定义 */
#define SCB_AIRCR_VECTKEY_Pos              16                                             /*!< SCB AIRCR: VECTKEY 位置 */
#define SCB_AIRCR_VECTKEY_Msk              (0xFFFFul << SCB_AIRCR_VECTKEY_Pos)            /*!< SCB AIRCR: VECTKEY 屏蔽 */

#define SCB_AIRCR_VECTKEYSTAT_Pos          16                                             /*!< SCB AIRCR: VECTKEYSTAT 位置 */
#define SCB_AIRCR_VECTKEYSTAT_Msk          (0xFFFFul << SCB_AIRCR_VECTKEYSTAT_Pos)        /*!< SCB AIRCR: VECTKEYSTAT 屏蔽 */

#define SCB_AIRCR_ENDIANESS_Pos            15                                             /*!< SCB AIRCR: ENDIANESS 位置 */
#define SCB_AIRCR_ENDIANESS_Msk            (1ul << SCB_AIRCR_ENDIANESS_Pos)               /*!< SCB AIRCR: ENDIANESS 屏蔽 */

#define SCB_AIRCR_PRIGROUP_Pos              8                                             /*!< SCB AIRCR: PRIGROUP 位置 */
#define SCB_AIRCR_PRIGROUP_Msk             (7ul << SCB_AIRCR_PRIGROUP_Pos)                /*!< SCB AIRCR: PRIGROUP 屏蔽 */

#define SCB_AIRCR_SYSRESETREQ_Pos           2                                             /*!< SCB AIRCR: SYSRESETREQ 位置 */
#define SCB_AIRCR_SYSRESETREQ_Msk          (1ul << SCB_AIRCR_SYSRESETREQ_Pos)             /*!< SCB AIRCR: SYSRESETREQ 屏蔽 */

#define SCB_AIRCR_VECTCLRACTIVE_Pos         1                                             /*!< SCB AIRCR: VECTCLRACTIVE 位置 */
#define SCB_AIRCR_VECTCLRACTIVE_Msk        (1ul << SCB_AIRCR_VECTCLRACTIVE_Pos)           /*!< SCB AIRCR: VECTCLRACTIVE 屏蔽 */

#define SCB_AIRCR_VECTRESET_Pos             0                                             /*!< SCB AIRCR: VECTRESET 位置 */
#define SCB_AIRCR_VECTRESET_Msk            (1ul << SCB_AIRCR_VECTRESET_Pos)               /*!< SCB AIRCR: VECTRESET 屏蔽 */

/* SCB 系统控制寄存器定义 */
#define SCB_SCR_SEVONPEND_Pos               4                                             /*!< SCB SCR: SEVONPEND 位置 */
#define SCB_SCR_SEVONPEND_Msk              (1ul << SCB_SCR_SEVONPEND_Pos)                 /*!< SCB SCR: SEVONPEND 屏蔽 */

#define SCB_SCR_SLEEPDEEP_Pos               2                                             /*!< SCB SCR: SLEEPDEEP 位置 */
#define SCB_SCR_SLEEPDEEP_Msk              (1ul << SCB_SCR_SLEEPDEEP_Pos)                 /*!< SCB SCR: SLEEPDEEP 屏蔽 */

#define SCB_SCR_SLEEPONEXIT_Pos             1                                             /*!< SCB SCR: SLEEPONEXIT 位置 */
#define SCB_SCR_SLEEPONEXIT_Msk            (1ul << SCB_SCR_SLEEPONEXIT_Pos)               /*!< SCB SCR: SLEEPONEXIT 屏蔽 */

/* SCB 配置控制寄存器定义 */
#define SCB_CCR_STKALIGN_Pos                9                                             /*!< SCB CCR: STKALIGN 位置 */
#define SCB_CCR_STKALIGN_Msk               (1ul << SCB_CCR_STKALIGN_Pos)                  /*!< SCB CCR: STKALIGN 屏蔽 */

#define SCB_CCR_BFHFNMIGN_Pos               8                                             /*!< SCB CCR: BFHFNMIGN 位置 */
#define SCB_CCR_BFHFNMIGN_Msk              (1ul << SCB_CCR_BFHFNMIGN_Pos)                 /*!< SCB CCR: BFHFNMIGN 屏蔽 */

#define SCB_CCR_DIV_0_TRP_Pos               4                                             /*!< SCB CCR: DIV_0_TRP 位置 */
#define SCB_CCR_DIV_0_TRP_Msk              (1ul << SCB_CCR_DIV_0_TRP_Pos)                 /*!< SCB CCR: DIV_0_TRP 屏蔽 */

#define SCB_CCR_UNALIGN_TRP_Pos             3                                             /*!< SCB CCR: UNALIGN_TRP 位置 */
#define SCB_CCR_UNALIGN_TRP_Msk            (1ul << SCB_CCR_UNALIGN_TRP_Pos)               /*!< SCB CCR: UNALIGN_TRP 屏蔽 */

#define SCB_CCR_USERSETMPEND_Pos            1                                             /*!< SCB CCR: USERSETMPEND 位置 */
#define SCB_CCR_USERSETMPEND_Msk           (1ul << SCB_CCR_USERSETMPEND_Pos)              /*!< SCB CCR: USERSETMPEND 屏蔽 */

#define SCB_CCR_NONBASETHRDENA_Pos          0                                             /*!< SCB CCR: NONBASETHRDENA 位置 */
#define SCB_CCR_NONBASETHRDENA_Msk         (1ul << SCB_CCR_NONBASETHRDENA_Pos)            /*!< SCB CCR: NONBASETHRDENA 屏蔽 */

/* SCB 系统异常控制与状态寄存器定义 */
#define SCB_SHCSR_USGFAULTENA_Pos          18                                             /*!< SCB SHCSR: USGFAULTENA 位置 */
#define SCB_SHCSR_USGFAULTENA_Msk          (1ul << SCB_SHCSR_USGFAULTENA_Pos)             /*!< SCB SHCSR: USGFAULTENA 屏蔽 */

#define SCB_SHCSR_BUSFAULTENA_Pos          17                                             /*!< SCB SHCSR: BUSFAULTENA 位置 */
#define SCB_SHCSR_BUSFAULTENA_Msk          (1ul << SCB_SHCSR_BUSFAULTENA_Pos)             /*!< SCB SHCSR: BUSFAULTENA 屏蔽 */

#define SCB_SHCSR_MEMFAULTENA_Pos          16                                             /*!< SCB SHCSR: MEMFAULTENA 位置 */
#define SCB_SHCSR_MEMFAULTENA_Msk          (1ul << SCB_SHCSR_MEMFAULTENA_Pos)             /*!< SCB SHCSR: MEMFAULTENA 屏蔽 */

#define SCB_SHCSR_SVCALLPENDED_Pos         15                                             /*!< SCB SHCSR: SVCALLPENDED 位置 */
#define SCB_SHCSR_SVCALLPENDED_Msk         (1ul << SCB_SHCSR_SVCALLPENDED_Pos)            /*!< SCB SHCSR: SVCALLPENDED 屏蔽 */

#define SCB_SHCSR_BUSFAULTPENDED_Pos       14                                             /*!< SCB SHCSR: BUSFAULTPENDED 位置 */
#define SCB_SHCSR_BUSFAULTPENDED_Msk       (1ul << SCB_SHCSR_BUSFAULTPENDED_Pos)          /*!< SCB SHCSR: BUSFAULTPENDED 屏蔽 */

#define SCB_SHCSR_MEMFAULTPENDED_Pos       13                                             /*!< SCB SHCSR: MEMFAULTPENDED 位置 */
#define SCB_SHCSR_MEMFAULTPENDED_Msk       (1ul << SCB_SHCSR_MEMFAULTPENDED_Pos)          /*!< SCB SHCSR: MEMFAULTPENDED 屏蔽 */

#define SCB_SHCSR_USGFAULTPENDED_Pos       12                                             /*!< SCB SHCSR: USGFAULTPENDED 位置 */
#define SCB_SHCSR_USGFAULTPENDED_Msk       (1ul << SCB_SHCSR_USGFAULTPENDED_Pos)          /*!< SCB SHCSR: USGFAULTPENDED 屏蔽 */

#define SCB_SHCSR_SYSTICKACT_Pos           11                                             /*!< SCB SHCSR: SYSTICKACT 位置 */
#define SCB_SHCSR_SYSTICKACT_Msk           (1ul << SCB_SHCSR_SYSTICKACT_Pos)              /*!< SCB SHCSR: SYSTICKACT 屏蔽 */

#define SCB_SHCSR_PENDSVACT_Pos            10                                             /*!< SCB SHCSR: PENDSVACT 位置 */
#define SCB_SHCSR_PENDSVACT_Msk            (1ul << SCB_SHCSR_PENDSVACT_Pos)               /*!< SCB SHCSR: PENDSVACT 屏蔽 */

#define SCB_SHCSR_MONITORACT_Pos            8                                             /*!< SCB SHCSR: MONITORACT 位置 */
#define SCB_SHCSR_MONITORACT_Msk           (1ul << SCB_SHCSR_MONITORACT_Pos)              /*!< SCB SHCSR: MONITORACT 屏蔽 */

#define SCB_SHCSR_SVCALLACT_Pos             7                                             /*!< SCB SHCSR: SVCALLACT 位置 */
#define SCB_SHCSR_SVCALLACT_Msk            (1ul << SCB_SHCSR_SVCALLACT_Pos)               /*!< SCB SHCSR: SVCALLACT 屏蔽 */
                                     
#define SCB_SHCSR_USGFAULTACT_Pos           3                                             /*!< SCB SHCSR: USGFAULTACT 位置 */
#define SCB_SHCSR_USGFAULTACT_Msk          (1ul << SCB_SHCSR_USGFAULTACT_Pos)             /*!< SCB SHCSR: USGFAULTACT 屏蔽 */

#define SCB_SHCSR_BUSFAULTACT_Pos           1                                             /*!< SCB SHCSR: BUSFAULTACT 位置 */
#define SCB_SHCSR_BUSFAULTACT_Msk          (1ul << SCB_SHCSR_BUSFAULTACT_Pos)             /*!< SCB SHCSR: BUSFAULTACT 屏蔽 */

#define SCB_SHCSR_MEMFAULTACT_Pos           0                                             /*!< SCB SHCSR: MEMFAULTACT 位置 */
#define SCB_SHCSR_MEMFAULTACT_Msk          (1ul << SCB_SHCSR_MEMFAULTACT_Pos)             /*!< SCB SHCSR: MEMFAULTACT 屏蔽 */

/* SCB 可配置故障状态寄存器定义 */
#define SCB_CFSR_USGFAULTSR_Pos            16                                             /*!< SCB CFSR: 用法故障状态寄存器 位置 */
#define SCB_CFSR_USGFAULTSR_Msk            (0xFFFFul << SCB_CFSR_USGFAULTSR_Pos)          /*!< SCB CFSR: 用法故障状态寄存器 屏蔽 */

#define SCB_CFSR_BUSFAULTSR_Pos             8                                             /*!< SCB CFSR: 总线故障状态寄存器 位置 */
#define SCB_CFSR_BUSFAULTSR_Msk            (0xFFul << SCB_CFSR_BUSFAULTSR_Pos)            /*!< SCB CFSR: 总线故障状态寄存器 屏蔽 */

#define SCB_CFSR_MEMFAULTSR_Pos             0                                             /*!< SCB CFSR: 存储器管理故障状态寄存器 位置 */
#define SCB_CFSR_MEMFAULTSR_Msk            (0xFFul << SCB_CFSR_MEMFAULTSR_Pos)            /*!< SCB CFSR: 存储器管理故障状态寄存器 屏蔽 */

/* SCB 硬故障状态寄存器定义 */
#define SCB_HFSR_DEBUGEVT_Pos              31                                             /*!< SCB HFSR: DEBUGEVT 位置 */
#define SCB_HFSR_DEBUGEVT_Msk              (1ul << SCB_HFSR_DEBUGEVT_Pos)                 /*!< SCB HFSR: DEBUGEVT 屏蔽 */

#define SCB_HFSR_FORCED_Pos                30                                             /*!< SCB HFSR: FORCED 位置 */
#define SCB_HFSR_FORCED_Msk                (1ul << SCB_HFSR_FORCED_Pos)                   /*!< SCB HFSR: FORCED 屏蔽 */

#define SCB_HFSR_VECTTBL_Pos                1                                             /*!< SCB HFSR: VECTTBL 位置 */
#define SCB_HFSR_VECTTBL_Msk               (1ul << SCB_HFSR_VECTTBL_Pos)                  /*!< SCB HFSR: VECTTBL 屏蔽 */

/* SCB 调试故障状态寄存器定义 */
#define SCB_DFSR_EXTERNAL_Pos               4                                             /*!< SCB DFSR: EXTERNAL 位置 */
#define SCB_DFSR_EXTERNAL_Msk              (1ul << SCB_DFSR_EXTERNAL_Pos)                 /*!< SCB DFSR: EXTERNAL 屏蔽 */

#define SCB_DFSR_VCATCH_Pos                 3                                             /*!< SCB DFSR: VCATCH 位置 */
#define SCB_DFSR_VCATCH_Msk                (1ul << SCB_DFSR_VCATCH_Pos)                   /*!< SCB DFSR: VCATCH 屏蔽 */

#define SCB_DFSR_DWTTRAP_Pos                2                                             /*!< SCB DFSR: DWTTRAP 位置 */
#define SCB_DFSR_DWTTRAP_Msk               (1ul << SCB_DFSR_DWTTRAP_Pos)                  /*!< SCB DFSR: DWTTRAP 屏蔽 */

#define SCB_DFSR_BKPT_Pos                   1                                             /*!< SCB DFSR: BKPT 位置 */
#define SCB_DFSR_BKPT_Msk                  (1ul << SCB_DFSR_BKPT_Pos)                     /*!< SCB DFSR: BKPT 屏蔽 */

#define SCB_DFSR_HALTED_Pos                 0                                             /*!< SCB DFSR: HALTED 位置 */
#define SCB_DFSR_HALTED_Msk                (1ul << SCB_DFSR_HALTED_Pos)                   /*!< SCB DFSR: HALTED 屏蔽 */
/*@}*/ /* CMSIS_CM3_SCB 组结束 */


/** @addtogroup CMSIS_CM3_SysTick CMSIS CM3 SysTick
  SysTick 的存储器映射结构
  @{
 */
typedef struct
{
  __IO uint32_t CTRL;                         /*!< 偏移：0x00 SysTick 控制与状态寄存器 */
  __IO uint32_t LOAD;                         /*!< 偏移：0x04 SysTick 重装载值寄存器       */
  __IO uint32_t VAL;                          /*!< 偏移：0x08 SysTick 当前值寄存器      */
  __I  uint32_t CALIB;                        /*!< 偏移：0x0C SysTick 校准寄存器        */
} SysTick_Type;

/* SysTick 控制 / 状态寄存器定义 */
#define SysTick_CTRL_COUNTFLAG_Pos         16                                             /*!< SysTick CTRL: COUNTFLAG 位置 */
#define SysTick_CTRL_COUNTFLAG_Msk         (1ul << SysTick_CTRL_COUNTFLAG_Pos)            /*!< SysTick CTRL: COUNTFLAG 屏蔽 */

#define SysTick_CTRL_CLKSOURCE_Pos          2                                             /*!< SysTick CTRL: CLKSOURCE 位置 */
#define SysTick_CTRL_CLKSOURCE_Msk         (1ul << SysTick_CTRL_CLKSOURCE_Pos)            /*!< SysTick CTRL: CLKSOURCE 屏蔽 */

#define SysTick_CTRL_TICKINT_Pos            1                                             /*!< SysTick CTRL: TICKINT 位置 */
#define SysTick_CTRL_TICKINT_Msk           (1ul << SysTick_CTRL_TICKINT_Pos)              /*!< SysTick CTRL: TICKINT 屏蔽 */

#define SysTick_CTRL_ENABLE_Pos             0                                             /*!< SysTick CTRL: ENABLE 位置 */
#define SysTick_CTRL_ENABLE_Msk            (1ul << SysTick_CTRL_ENABLE_Pos)               /*!< SysTick CTRL: ENABLE 屏蔽 */

/* SysTick 重装载寄存器定义 */
#define SysTick_LOAD_RELOAD_Pos             0                                             /*!< SysTick LOAD: RELOAD 位置 */
#define SysTick_LOAD_RELOAD_Msk            (0xFFFFFFul << SysTick_LOAD_RELOAD_Pos)        /*!< SysTick LOAD: RELOAD 屏蔽 */

/* SysTick 当前值寄存器定义 */
#define SysTick_VAL_CURRENT_Pos             0                                             /*!< SysTick VAL: CURRENT 位置 */
#define SysTick_VAL_CURRENT_Msk            (0xFFFFFFul << SysTick_VAL_CURRENT_Pos)        /*!< SysTick VAL: CURRENT 屏蔽 */

/* SysTick 校准寄存器定义 */
#define SysTick_CALIB_NOREF_Pos            31                                             /*!< SysTick CALIB: NOREF 位置 */
#define SysTick_CALIB_NOREF_Msk            (1ul << SysTick_CALIB_NOREF_Pos)               /*!< SysTick CALIB: NOREF 屏蔽 */

#define SysTick_CALIB_SKEW_Pos             30                                             /*!< SysTick CALIB: SKEW 位置 */
#define SysTick_CALIB_SKEW_Msk             (1ul << SysTick_CALIB_SKEW_Pos)                /*!< SysTick CALIB: SKEW 屏蔽 */

#define SysTick_CALIB_TENMS_Pos             0                                             /*!< SysTick CALIB: TENMS 位置 */
#define SysTick_CALIB_TENMS_Msk            (0xFFFFFFul << SysTick_VAL_CURRENT_Pos)        /*!< SysTick CALIB: TENMS 屏蔽 */
/*@}*/ /* CMSIS_CM3_SysTick 组结束 */


/** @addtogroup CMSIS_CM3_ITM CMSIS CM3 ITM
  仪器化跟踪宏单元（ITM）的存储器映射结构
  @{
 */
typedef struct
{
  __O  union  
  {
    __O  uint8_t    u8;                       /*!< 偏移：ITM 激励端口 8 位                   */
    __O  uint16_t   u16;                      /*!< 偏移：ITM 激励端口 16 位                  */
    __O  uint32_t   u32;                      /*!< 偏移：ITM 激励端口 32 位                  */
  }  PORT [32];                               /*!< 偏移：0x00 ITM 激励端口寄存器               */
       uint32_t RESERVED0[864];                                 
  __IO uint32_t TER;                          /*!< 偏移：ITM 跟踪使能寄存器                 */
       uint32_t RESERVED1[15];                                  
  __IO uint32_t TPR;                          /*!< 偏移：ITM 跟踪特权寄存器              */
       uint32_t RESERVED2[15];                                  
  __IO uint32_t TCR;                          /*!< 偏移：ITM 跟踪控制寄存器                */
       uint32_t RESERVED3[29];                                  
  __IO uint32_t IWR;                          /*!< 偏移：ITM 集成写寄存器            */
  __IO uint32_t IRR;                          /*!< 偏移：ITM 集成读寄存器             */
  __IO uint32_t IMCR;                         /*!< 偏移：ITM 集成模式控制寄存器     */
       uint32_t RESERVED4[43];                                  
  __IO uint32_t LAR;                          /*!< 偏移：ITM 锁定访问寄存器                  */
  __IO uint32_t LSR;                          /*!< 偏移：ITM 锁定状态寄存器                  */
       uint32_t RESERVED5[6];                                   
  __I  uint32_t PID4;                         /*!< 偏移：ITM 外设标识寄存器 #4 */
  __I  uint32_t PID5;                         /*!< 偏移：ITM 外设标识寄存器 #5 */
  __I  uint32_t PID6;                         /*!< 偏移：ITM 外设标识寄存器 #6 */
  __I  uint32_t PID7;                         /*!< 偏移：ITM 外设标识寄存器 #7 */
  __I  uint32_t PID0;                         /*!< 偏移：ITM 外设标识寄存器 #0 */
  __I  uint32_t PID1;                         /*!< 偏移：ITM 外设标识寄存器 #1 */
  __I  uint32_t PID2;                         /*!< 偏移：ITM 外设标识寄存器 #2 */
  __I  uint32_t PID3;                         /*!< 偏移：ITM 外设标识寄存器 #3 */
  __I  uint32_t CID0;                         /*!< 偏移：ITM 组件标识寄存器 #0 */
  __I  uint32_t CID1;                         /*!< 偏移：ITM 组件标识寄存器 #1 */
  __I  uint32_t CID2;                         /*!< 偏移：ITM 组件标识寄存器 #2 */
  __I  uint32_t CID3;                         /*!< 偏移：ITM 组件标识寄存器 #3 */
} ITM_Type;                                                

/* ITM 跟踪特权寄存器定义 */
#define ITM_TPR_PRIVMASK_Pos                0                                             /*!< ITM TPR: PRIVMASK 位置 */
#define ITM_TPR_PRIVMASK_Msk               (0xFul << ITM_TPR_PRIVMASK_Pos)                /*!< ITM TPR: PRIVMASK 屏蔽 */

/* ITM 跟踪控制寄存器定义 */
#define ITM_TCR_BUSY_Pos                   23                                             /*!< ITM TCR: BUSY 位置 */
#define ITM_TCR_BUSY_Msk                   (1ul << ITM_TCR_BUSY_Pos)                      /*!< ITM TCR: BUSY 屏蔽 */

#define ITM_TCR_ATBID_Pos                  16                                             /*!< ITM TCR: ATBID 位置 */
#define ITM_TCR_ATBID_Msk                  (0x7Ful << ITM_TCR_ATBID_Pos)                  /*!< ITM TCR: ATBID 屏蔽 */

#define ITM_TCR_TSPrescale_Pos              8                                             /*!< ITM TCR: TSPrescale 位置 */
#define ITM_TCR_TSPrescale_Msk             (3ul << ITM_TCR_TSPrescale_Pos)                /*!< ITM TCR: TSPrescale 屏蔽 */

#define ITM_TCR_SWOENA_Pos                  4                                             /*!< ITM TCR: SWOENA 位置 */
#define ITM_TCR_SWOENA_Msk                 (1ul << ITM_TCR_SWOENA_Pos)                    /*!< ITM TCR: SWOENA 屏蔽 */

#define ITM_TCR_DWTENA_Pos                  3                                             /*!< ITM TCR: DWTENA 位置 */
#define ITM_TCR_DWTENA_Msk                 (1ul << ITM_TCR_DWTENA_Pos)                    /*!< ITM TCR: DWTENA 屏蔽 */

#define ITM_TCR_SYNCENA_Pos                 2                                             /*!< ITM TCR: SYNCENA 位置 */
#define ITM_TCR_SYNCENA_Msk                (1ul << ITM_TCR_SYNCENA_Pos)                   /*!< ITM TCR: SYNCENA 屏蔽 */

#define ITM_TCR_TSENA_Pos                   1                                             /*!< ITM TCR: TSENA 位置 */
#define ITM_TCR_TSENA_Msk                  (1ul << ITM_TCR_TSENA_Pos)                     /*!< ITM TCR: TSENA 屏蔽 */

#define ITM_TCR_ITMENA_Pos                  0                                             /*!< ITM TCR: ITM 使能位 位置 */
#define ITM_TCR_ITMENA_Msk                 (1ul << ITM_TCR_ITMENA_Pos)                    /*!< ITM TCR: ITM 使能位 屏蔽 */

/* ITM 集成写寄存器定义 */
#define ITM_IWR_ATVALIDM_Pos                0                                             /*!< ITM IWR: ATVALIDM 位置 */
#define ITM_IWR_ATVALIDM_Msk               (1ul << ITM_IWR_ATVALIDM_Pos)                  /*!< ITM IWR: ATVALIDM 屏蔽 */

/* ITM 集成读寄存器定义 */
#define ITM_IRR_ATREADYM_Pos                0                                             /*!< ITM IRR: ATREADYM 位置 */
#define ITM_IRR_ATREADYM_Msk               (1ul << ITM_IRR_ATREADYM_Pos)                  /*!< ITM IRR: ATREADYM 屏蔽 */

/* ITM 集成模式控制寄存器定义 */
#define ITM_IMCR_INTEGRATION_Pos            0                                             /*!< ITM IMCR: INTEGRATION 位置 */
#define ITM_IMCR_INTEGRATION_Msk           (1ul << ITM_IMCR_INTEGRATION_Pos)              /*!< ITM IMCR: INTEGRATION 屏蔽 */

/* ITM 锁定状态寄存器定义 */
#define ITM_LSR_ByteAcc_Pos                 2                                             /*!< ITM LSR: ByteAcc 位置 */
#define ITM_LSR_ByteAcc_Msk                (1ul << ITM_LSR_ByteAcc_Pos)                   /*!< ITM LSR: ByteAcc 屏蔽 */

#define ITM_LSR_Access_Pos                  1                                             /*!< ITM LSR: Access 位置 */
#define ITM_LSR_Access_Msk                 (1ul << ITM_LSR_Access_Pos)                    /*!< ITM LSR: Access 屏蔽 */

#define ITM_LSR_Present_Pos                 0                                             /*!< ITM LSR: Present 位置 */
#define ITM_LSR_Present_Msk                (1ul << ITM_LSR_Present_Pos)                   /*!< ITM LSR: Present 屏蔽 */
/*@}*/ /* CMSIS_CM3_ITM 组结束 */


/** @addtogroup CMSIS_CM3_InterruptType CMSIS CM3 中断类型
  中断类型的存储器映射结构
  @{
 */
typedef struct
{
       uint32_t RESERVED0;
  __I  uint32_t ICTR;                         /*!< 偏移：0x04 中断控制类型寄存器 */
#if ((defined __CM3_REV) && (__CM3_REV >= 0x200))
  __IO uint32_t ACTLR;                        /*!< 偏移：0x08 辅助控制寄存器      */
#else
       uint32_t RESERVED1;
#endif
} InterruptType_Type;

/* 中断控制器类型寄存器定义 */
#define InterruptType_ICTR_INTLINESNUM_Pos  0                                             /*!< InterruptType ICTR: INTLINESNUM 位置 */
#define InterruptType_ICTR_INTLINESNUM_Msk (0x1Ful << InterruptType_ICTR_INTLINESNUM_Pos) /*!< InterruptType ICTR: INTLINESNUM 屏蔽 */

/* 辅助控制寄存器定义 */
#define InterruptType_ACTLR_DISFOLD_Pos     2                                             /*!< InterruptType ACTLR: DISFOLD 位置 */
#define InterruptType_ACTLR_DISFOLD_Msk    (1ul << InterruptType_ACTLR_DISFOLD_Pos)       /*!< InterruptType ACTLR: DISFOLD 屏蔽 */

#define InterruptType_ACTLR_DISDEFWBUF_Pos  1                                             /*!< InterruptType ACTLR: DISDEFWBUF 位置 */
#define InterruptType_ACTLR_DISDEFWBUF_Msk (1ul << InterruptType_ACTLR_DISDEFWBUF_Pos)    /*!< InterruptType ACTLR: DISDEFWBUF 屏蔽 */

#define InterruptType_ACTLR_DISMCYCINT_Pos  0                                             /*!< InterruptType ACTLR: DISMCYCINT 位置 */
#define InterruptType_ACTLR_DISMCYCINT_Msk (1ul << InterruptType_ACTLR_DISMCYCINT_Pos)    /*!< InterruptType ACTLR: DISMCYCINT 屏蔽 */
/*@}*/ /* CMSIS_CM3_InterruptType 组结束 */


#if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1)
/** @addtogroup CMSIS_CM3_MPU CMSIS CM3 MPU
  存储器保护单元（MPU）的存储器映射结构
  @{
 */
typedef struct
{
  __I  uint32_t TYPE;                         /*!< 偏移：0x00 MPU 类型寄存器                              */
  __IO uint32_t CTRL;                         /*!< 偏移：0x04 MPU 控制寄存器                           */
  __IO uint32_t RNR;                          /*!< 偏移：0x08 MPU 区域编号寄存器                     */
  __IO uint32_t RBAR;                         /*!< 偏移：0x0C MPU 区域基地址寄存器               */
  __IO uint32_t RASR;                         /*!< 偏移：0x10 MPU 区域属性与大小寄存器         */
  __IO uint32_t RBAR_A1;                      /*!< 偏移：0x14 MPU 别名 1 区域基地址寄存器       */
  __IO uint32_t RASR_A1;                      /*!< 偏移：0x18 MPU 别名 1 区域属性与大小寄存器 */
  __IO uint32_t RBAR_A2;                      /*!< 偏移：0x1C MPU 别名 2 区域基地址寄存器       */
  __IO uint32_t RASR_A2;                      /*!< 偏移：0x20 MPU 别名 2 区域属性与大小寄存器 */
  __IO uint32_t RBAR_A3;                      /*!< 偏移：0x24 MPU 别名 3 区域基地址寄存器       */
  __IO uint32_t RASR_A3;                      /*!< 偏移：0x28 MPU 别名 3 区域属性与大小寄存器 */
} MPU_Type;                                                

/* MPU 类型寄存器 */
#define MPU_TYPE_IREGION_Pos               16                                             /*!< MPU TYPE: IREGION 位置 */
#define MPU_TYPE_IREGION_Msk               (0xFFul << MPU_TYPE_IREGION_Pos)               /*!< MPU TYPE: IREGION 屏蔽 */

#define MPU_TYPE_DREGION_Pos                8                                             /*!< MPU TYPE: DREGION 位置 */
#define MPU_TYPE_DREGION_Msk               (0xFFul << MPU_TYPE_DREGION_Pos)               /*!< MPU TYPE: DREGION 屏蔽 */

#define MPU_TYPE_SEPARATE_Pos               0                                             /*!< MPU TYPE: SEPARATE 位置 */
#define MPU_TYPE_SEPARATE_Msk              (1ul << MPU_TYPE_SEPARATE_Pos)                 /*!< MPU TYPE: SEPARATE 屏蔽 */

/* MPU 控制寄存器 */
#define MPU_CTRL_PRIVDEFENA_Pos             2                                             /*!< MPU CTRL: PRIVDEFENA 位置 */
#define MPU_CTRL_PRIVDEFENA_Msk            (1ul << MPU_CTRL_PRIVDEFENA_Pos)               /*!< MPU CTRL: PRIVDEFENA 屏蔽 */

#define MPU_CTRL_HFNMIENA_Pos               1                                             /*!< MPU CTRL: HFNMIENA 位置 */
#define MPU_CTRL_HFNMIENA_Msk              (1ul << MPU_CTRL_HFNMIENA_Pos)                 /*!< MPU CTRL: HFNMIENA 屏蔽 */

#define MPU_CTRL_ENABLE_Pos                 0                                             /*!< MPU CTRL: ENABLE 位置 */
#define MPU_CTRL_ENABLE_Msk                (1ul << MPU_CTRL_ENABLE_Pos)                   /*!< MPU CTRL: ENABLE 屏蔽 */

/* MPU 区域编号寄存器 */
#define MPU_RNR_REGION_Pos                  0                                             /*!< MPU RNR: REGION 位置 */
#define MPU_RNR_REGION_Msk                 (0xFFul << MPU_RNR_REGION_Pos)                 /*!< MPU RNR: REGION 屏蔽 */

/* MPU 区域基地址寄存器 */
#define MPU_RBAR_ADDR_Pos                   5                                             /*!< MPU RBAR: ADDR 位置 */
#define MPU_RBAR_ADDR_Msk                  (0x7FFFFFFul << MPU_RBAR_ADDR_Pos)             /*!< MPU RBAR: ADDR 屏蔽 */

#define MPU_RBAR_VALID_Pos                  4                                             /*!< MPU RBAR: VALID 位置 */
#define MPU_RBAR_VALID_Msk                 (1ul << MPU_RBAR_VALID_Pos)                    /*!< MPU RBAR: VALID 屏蔽 */

#define MPU_RBAR_REGION_Pos                 0                                             /*!< MPU RBAR: REGION 位置 */
#define MPU_RBAR_REGION_Msk                (0xFul << MPU_RBAR_REGION_Pos)                 /*!< MPU RBAR: REGION 屏蔽 */

/* MPU 区域属性与大小寄存器 */
#define MPU_RASR_XN_Pos                    28                                             /*!< MPU RASR: XN 位置 */
#define MPU_RASR_XN_Msk                    (1ul << MPU_RASR_XN_Pos)                       /*!< MPU RASR: XN 屏蔽 */

#define MPU_RASR_AP_Pos                    24                                             /*!< MPU RASR: AP 位置 */
#define MPU_RASR_AP_Msk                    (7ul << MPU_RASR_AP_Pos)                       /*!< MPU RASR: AP 屏蔽 */

#define MPU_RASR_TEX_Pos                   19                                             /*!< MPU RASR: TEX 位置 */
#define MPU_RASR_TEX_Msk                   (7ul << MPU_RASR_TEX_Pos)                      /*!< MPU RASR: TEX 屏蔽 */

#define MPU_RASR_S_Pos                     18                                             /*!< MPU RASR: 可共享位 位置 */
#define MPU_RASR_S_Msk                     (1ul << MPU_RASR_S_Pos)                        /*!< MPU RASR: 可共享位 屏蔽 */

#define MPU_RASR_C_Pos                     17                                             /*!< MPU RASR: 可缓存位 位置 */
#define MPU_RASR_C_Msk                     (1ul << MPU_RASR_C_Pos)                        /*!< MPU RASR: 可缓存位 屏蔽 */

#define MPU_RASR_B_Pos                     16                                             /*!< MPU RASR: 可缓冲位 位置 */
#define MPU_RASR_B_Msk                     (1ul << MPU_RASR_B_Pos)                        /*!< MPU RASR: 可缓冲位 屏蔽 */

#define MPU_RASR_SRD_Pos                    8                                             /*!< MPU RASR: 子区域禁用 位置 */
#define MPU_RASR_SRD_Msk                   (0xFFul << MPU_RASR_SRD_Pos)                   /*!< MPU RASR: 子区域禁用 屏蔽 */

#define MPU_RASR_SIZE_Pos                   1                                             /*!< MPU RASR: 区域大小域 位置 */
#define MPU_RASR_SIZE_Msk                  (0x1Ful << MPU_RASR_SIZE_Pos)                  /*!< MPU RASR: 区域大小域 屏蔽 */

#define MPU_RASR_ENA_Pos                     0                                            /*!< MPU RASR: 区域使能位 位置 */
#define MPU_RASR_ENA_Msk                    (0x1Ful << MPU_RASR_ENA_Pos)                  /*!< MPU RASR: 区域使能位 屏蔽 */

/*@}*/ /* CMSIS_CM3_MPU 组结束 */
#endif


/** @addtogroup CMSIS_CM3_CoreDebug CMSIS CM3 内核调试
  内核调试寄存器的存储器映射结构
  @{
 */
typedef struct
{
  __IO uint32_t DHCSR;                        /*!< 偏移：0x00 调试停机控制与状态寄存器    */
  __O  uint32_t DCRSR;                        /*!< 偏移：0x04 调试内核寄存器选择寄存器        */
  __IO uint32_t DCRDR;                        /*!< 偏移：0x08 调试内核寄存器数据寄存器            */
  __IO uint32_t DEMCR;                        /*!< 偏移：0x0C 调试异常与监控控制寄存器 */
} CoreDebug_Type;

/* 调试停机控制与状态寄存器 */
#define CoreDebug_DHCSR_DBGKEY_Pos         16                                             /*!< CoreDebug DHCSR: DBGKEY 位置 */
#define CoreDebug_DHCSR_DBGKEY_Msk         (0xFFFFul << CoreDebug_DHCSR_DBGKEY_Pos)       /*!< CoreDebug DHCSR: DBGKEY 屏蔽 */

#define CoreDebug_DHCSR_S_RESET_ST_Pos     25                                             /*!< CoreDebug DHCSR: S_RESET_ST 位置 */
#define CoreDebug_DHCSR_S_RESET_ST_Msk     (1ul << CoreDebug_DHCSR_S_RESET_ST_Pos)        /*!< CoreDebug DHCSR: S_RESET_ST 屏蔽 */

#define CoreDebug_DHCSR_S_RETIRE_ST_Pos    24                                             /*!< CoreDebug DHCSR: S_RETIRE_ST 位置 */
#define CoreDebug_DHCSR_S_RETIRE_ST_Msk    (1ul << CoreDebug_DHCSR_S_RETIRE_ST_Pos)       /*!< CoreDebug DHCSR: S_RETIRE_ST 屏蔽 */

#define CoreDebug_DHCSR_S_LOCKUP_Pos       19                                             /*!< CoreDebug DHCSR: S_LOCKUP 位置 */
#define CoreDebug_DHCSR_S_LOCKUP_Msk       (1ul << CoreDebug_DHCSR_S_LOCKUP_Pos)          /*!< CoreDebug DHCSR: S_LOCKUP 屏蔽 */

#define CoreDebug_DHCSR_S_SLEEP_Pos        18                                             /*!< CoreDebug DHCSR: S_SLEEP 位置 */
#define CoreDebug_DHCSR_S_SLEEP_Msk        (1ul << CoreDebug_DHCSR_S_SLEEP_Pos)           /*!< CoreDebug DHCSR: S_SLEEP 屏蔽 */

#define CoreDebug_DHCSR_S_HALT_Pos         17                                             /*!< CoreDebug DHCSR: S_HALT 位置 */
#define CoreDebug_DHCSR_S_HALT_Msk         (1ul << CoreDebug_DHCSR_S_HALT_Pos)            /*!< CoreDebug DHCSR: S_HALT 屏蔽 */

#define CoreDebug_DHCSR_S_REGRDY_Pos       16                                             /*!< CoreDebug DHCSR: S_REGRDY 位置 */
#define CoreDebug_DHCSR_S_REGRDY_Msk       (1ul << CoreDebug_DHCSR_S_REGRDY_Pos)          /*!< CoreDebug DHCSR: S_REGRDY 屏蔽 */

#define CoreDebug_DHCSR_C_SNAPSTALL_Pos     5                                             /*!< CoreDebug DHCSR: C_SNAPSTALL 位置 */
#define CoreDebug_DHCSR_C_SNAPSTALL_Msk    (1ul << CoreDebug_DHCSR_C_SNAPSTALL_Pos)       /*!< CoreDebug DHCSR: C_SNAPSTALL 屏蔽 */

#define CoreDebug_DHCSR_C_MASKINTS_Pos      3                                             /*!< CoreDebug DHCSR: C_MASKINTS 位置 */
#define CoreDebug_DHCSR_C_MASKINTS_Msk     (1ul << CoreDebug_DHCSR_C_MASKINTS_Pos)        /*!< CoreDebug DHCSR: C_MASKINTS 屏蔽 */

#define CoreDebug_DHCSR_C_STEP_Pos          2                                             /*!< CoreDebug DHCSR: C_STEP 位置 */
#define CoreDebug_DHCSR_C_STEP_Msk         (1ul << CoreDebug_DHCSR_C_STEP_Pos)            /*!< CoreDebug DHCSR: C_STEP 屏蔽 */

#define CoreDebug_DHCSR_C_HALT_Pos          1                                             /*!< CoreDebug DHCSR: C_HALT 位置 */
#define CoreDebug_DHCSR_C_HALT_Msk         (1ul << CoreDebug_DHCSR_C_HALT_Pos)            /*!< CoreDebug DHCSR: C_HALT 屏蔽 */

#define CoreDebug_DHCSR_C_DEBUGEN_Pos       0                                             /*!< CoreDebug DHCSR: C_DEBUGEN 位置 */
#define CoreDebug_DHCSR_C_DEBUGEN_Msk      (1ul << CoreDebug_DHCSR_C_DEBUGEN_Pos)         /*!< CoreDebug DHCSR: C_DEBUGEN 屏蔽 */

/* 调试内核寄存器选择寄存器 */
#define CoreDebug_DCRSR_REGWnR_Pos         16                                             /*!< CoreDebug DCRSR: REGWnR 位置 */
#define CoreDebug_DCRSR_REGWnR_Msk         (1ul << CoreDebug_DCRSR_REGWnR_Pos)            /*!< CoreDebug DCRSR: REGWnR 屏蔽 */

#define CoreDebug_DCRSR_REGSEL_Pos          0                                             /*!< CoreDebug DCRSR: REGSEL 位置 */
#define CoreDebug_DCRSR_REGSEL_Msk         (0x1Ful << CoreDebug_DCRSR_REGSEL_Pos)         /*!< CoreDebug DCRSR: REGSEL 屏蔽 */

/* 调试异常与监控控制寄存器 */
#define CoreDebug_DEMCR_TRCENA_Pos         24                                             /*!< CoreDebug DEMCR: TRCENA 位置 */
#define CoreDebug_DEMCR_TRCENA_Msk         (1ul << CoreDebug_DEMCR_TRCENA_Pos)            /*!< CoreDebug DEMCR: TRCENA 屏蔽 */

#define CoreDebug_DEMCR_MON_REQ_Pos        19                                             /*!< CoreDebug DEMCR: MON_REQ 位置 */
#define CoreDebug_DEMCR_MON_REQ_Msk        (1ul << CoreDebug_DEMCR_MON_REQ_Pos)           /*!< CoreDebug DEMCR: MON_REQ 屏蔽 */

#define CoreDebug_DEMCR_MON_STEP_Pos       18                                             /*!< CoreDebug DEMCR: MON_STEP 位置 */
#define CoreDebug_DEMCR_MON_STEP_Msk       (1ul << CoreDebug_DEMCR_MON_STEP_Pos)          /*!< CoreDebug DEMCR: MON_STEP 屏蔽 */

#define CoreDebug_DEMCR_MON_PEND_Pos       17                                             /*!< CoreDebug DEMCR: MON_PEND 位置 */
#define CoreDebug_DEMCR_MON_PEND_Msk       (1ul << CoreDebug_DEMCR_MON_PEND_Pos)          /*!< CoreDebug DEMCR: MON_PEND 屏蔽 */

#define CoreDebug_DEMCR_MON_EN_Pos         16                                             /*!< CoreDebug DEMCR: MON_EN 位置 */
#define CoreDebug_DEMCR_MON_EN_Msk         (1ul << CoreDebug_DEMCR_MON_EN_Pos)            /*!< CoreDebug DEMCR: MON_EN 屏蔽 */

#define CoreDebug_DEMCR_VC_HARDERR_Pos     10                                             /*!< CoreDebug DEMCR: VC_HARDERR 位置 */
#define CoreDebug_DEMCR_VC_HARDERR_Msk     (1ul << CoreDebug_DEMCR_VC_HARDERR_Pos)        /*!< CoreDebug DEMCR: VC_HARDERR 屏蔽 */

#define CoreDebug_DEMCR_VC_INTERR_Pos       9                                             /*!< CoreDebug DEMCR: VC_INTERR 位置 */
#define CoreDebug_DEMCR_VC_INTERR_Msk      (1ul << CoreDebug_DEMCR_VC_INTERR_Pos)         /*!< CoreDebug DEMCR: VC_INTERR 屏蔽 */

#define CoreDebug_DEMCR_VC_BUSERR_Pos       8                                             /*!< CoreDebug DEMCR: VC_BUSERR 位置 */
#define CoreDebug_DEMCR_VC_BUSERR_Msk      (1ul << CoreDebug_DEMCR_VC_BUSERR_Pos)         /*!< CoreDebug DEMCR: VC_BUSERR 屏蔽 */

#define CoreDebug_DEMCR_VC_STATERR_Pos      7                                             /*!< CoreDebug DEMCR: VC_STATERR 位置 */
#define CoreDebug_DEMCR_VC_STATERR_Msk     (1ul << CoreDebug_DEMCR_VC_STATERR_Pos)        /*!< CoreDebug DEMCR: VC_STATERR 屏蔽 */

#define CoreDebug_DEMCR_VC_CHKERR_Pos       6                                             /*!< CoreDebug DEMCR: VC_CHKERR 位置 */
#define CoreDebug_DEMCR_VC_CHKERR_Msk      (1ul << CoreDebug_DEMCR_VC_CHKERR_Pos)         /*!< CoreDebug DEMCR: VC_CHKERR 屏蔽 */

#define CoreDebug_DEMCR_VC_NOCPERR_Pos      5                                             /*!< CoreDebug DEMCR: VC_NOCPERR 位置 */
#define CoreDebug_DEMCR_VC_NOCPERR_Msk     (1ul << CoreDebug_DEMCR_VC_NOCPERR_Pos)        /*!< CoreDebug DEMCR: VC_NOCPERR 屏蔽 */

#define CoreDebug_DEMCR_VC_MMERR_Pos        4                                             /*!< CoreDebug DEMCR: VC_MMERR 位置 */
#define CoreDebug_DEMCR_VC_MMERR_Msk       (1ul << CoreDebug_DEMCR_VC_MMERR_Pos)          /*!< CoreDebug DEMCR: VC_MMERR 屏蔽 */

#define CoreDebug_DEMCR_VC_CORERESET_Pos    0                                             /*!< CoreDebug DEMCR: VC_CORERESET 位置 */
#define CoreDebug_DEMCR_VC_CORERESET_Msk   (1ul << CoreDebug_DEMCR_VC_CORERESET_Pos)      /*!< CoreDebug DEMCR: VC_CORERESET 屏蔽 */
/*@}*/ /* CMSIS_CM3_CoreDebug 组结束 */


/* Cortex-M3 硬件的存储器映射 */
#define SCS_BASE            (0xE000E000)                              /*!< 系统控制空间基地址 */
#define ITM_BASE            (0xE0000000)                              /*!< ITM 基地址                  */
#define CoreDebug_BASE      (0xE000EDF0)                              /*!< 内核调试基地址           */
#define SysTick_BASE        (SCS_BASE +  0x0010)                      /*!< SysTick 基地址              */
#define NVIC_BASE           (SCS_BASE +  0x0100)                      /*!< NVIC 基地址                 */
#define SCB_BASE            (SCS_BASE +  0x0D00)                      /*!< 系统控制块基地址 */

#define InterruptType       ((InterruptType_Type *) SCS_BASE)         /*!< 中断类型寄存器           */
#define SCB                 ((SCB_Type *)           SCB_BASE)         /*!< SCB 配置结构体          */
#define SysTick             ((SysTick_Type *)       SysTick_BASE)     /*!< SysTick 配置结构体      */
#define NVIC                ((NVIC_Type *)          NVIC_BASE)        /*!< NVIC 配置结构体         */
#define ITM                 ((ITM_Type *)           ITM_BASE)         /*!< ITM 配置结构体          */
#define CoreDebug           ((CoreDebug_Type *)     CoreDebug_BASE)   /*!< 内核调试配置结构体   */

#if defined (__MPU_PRESENT) && (__MPU_PRESENT == 1)
  #define MPU_BASE          (SCS_BASE +  0x0D90)                      /*!< 存储器保护单元            */
  #define MPU               ((MPU_Type*)            MPU_BASE)         /*!< 存储器保护单元            */
#endif

/*@}*/ /* CMSIS_CM3_core_register 组结束 */


/*******************************************************************************
 *                硬件抽象层
 ******************************************************************************/

#if defined ( __CC_ARM   )
  #define __ASM            __asm                                      /*!< ARM 编译器的 asm 关键字          */
  #define __INLINE         __inline                                   /*!< ARM 编译器的 inline 关键字       */

#elif defined ( __ICCARM__ )
  #define __ASM           __asm                                       /*!< IAR 编译器的 asm 关键字          */
  #define __INLINE        inline                                      /*!< IAR 编译器的 inline 关键字，仅在高优化模式下可用 */

#elif defined   (  __GNUC__  )
  #define __ASM            __asm                                      /*!< GNU 编译器的 asm 关键字          */
  #define __INLINE         inline                                     /*!< GNU 编译器的 inline 关键字       */

#elif defined   (  __TASKING__  )
  #define __ASM            __asm                                      /*!< TASKING 编译器的 asm 关键字      */
  #define __INLINE         inline                                     /*!< TASKING 编译器的 inline 关键字   */

#endif


/* ################### 编译器专用内建函数 ########################### */

#if defined ( __CC_ARM   ) /*------------------RealView 编译器 -----------------*/
/* ARM armcc 专用函数 */

#define __enable_fault_irq                __enable_fiq
#define __disable_fault_irq               __disable_fiq

#define __NOP                             __nop
#define __WFI                             __wfi
#define __WFE                             __wfe
#define __SEV                             __sev
#define __ISB()                           __isb(0)
#define __DSB()                           __dsb(0)
#define __DMB()                           __dmb(0)
#define __REV                             __rev
#define __RBIT                            __rbit
#define __LDREXB(ptr)                     ((unsigned char ) __ldrex(ptr))
#define __LDREXH(ptr)                     ((unsigned short) __ldrex(ptr))
#define __LDREXW(ptr)                     ((unsigned int  ) __ldrex(ptr))
#define __STREXB(value, ptr)              __strex(value, ptr)
#define __STREXH(value, ptr)              __strex(value, ptr)
#define __STREXW(value, ptr)              __strex(value, ptr)


/* intrinsic unsigned long long __ldrexd(volatile void *ptr) */
/* intrinsic int __strexd(unsigned long long val, volatile void *ptr) */
/* intrinsic void __enable_irq();     */
/* intrinsic void __disable_irq();    */


/**
 * @brief 返回进程堆栈指针
 *
 * @return 进程堆栈指针
 *
 * 返回实际的进程堆栈指针
 */
extern uint32_t __get_PSP(void);

/**
 * @brief 设置进程堆栈指针
 *
 * @param topOfProcStack 进程堆栈指针
 *
 * 将 ProcessStackPointer 的值赋给 MSP 
 * （进程堆栈指针）Cortex 处理器寄存器
 */
extern void __set_PSP(uint32_t topOfProcStack);

/**
 * @brief 返回主堆栈指针
 *
 * @return 主堆栈指针
 *
 * 返回 MSP（主堆栈指针）的当前值
 * Cortex 处理器寄存器
 */
extern uint32_t __get_MSP(void);

/**
 * @brief 设置主堆栈指针
 *
 * @param topOfMainStack 主堆栈指针
 *
 * 将 mainStackPointer 的值赋给 MSP 
 * （主堆栈指针）Cortex 处理器寄存器
 */
extern void __set_MSP(uint32_t topOfMainStack);

/**
 * @brief 反转无符号短整型值的字节顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转无符号短整型值的字节顺序
 */
extern uint32_t __REV16(uint16_t value);

/**
 * @brief 反转有符号短整型值的字节顺序，并符号扩展为整数
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转有符号短整型值的字节顺序，并符号扩展为整数
 */
extern int32_t __REVSH(int16_t value);


#if (__ARMCC_VERSION < 400000)

/**
 * @brief 清除由 ldrex 创建的独占锁
 *
 * 清除由 ldrex 创建的独占锁。
 */
extern void __CLREX(void);

/**
 * @brief 返回基优先级值
 *
 * @return 基优先级
 *
 * 返回基优先级寄存器的内容
 */
extern uint32_t __get_BASEPRI(void);

/**
 * @brief 设置基优先级值
 *
 * @param basePri 基优先级
 *
 * 设置基优先级寄存器
 */
extern void __set_BASEPRI(uint32_t basePri);

/**
 * @brief 返回优先级屏蔽值
 *
 * @return 优先级屏蔽
 *
 * 返回优先级屏蔽寄存器中优先级屏蔽位的状态
 */
extern uint32_t __get_PRIMASK(void);

/**
 * @brief 设置优先级屏蔽值
 *
 * @param priMask 优先级屏蔽
 *
 * 设置优先级屏蔽寄存器中的优先级屏蔽位
 */
extern void __set_PRIMASK(uint32_t priMask);

/**
 * @brief 返回故障屏蔽值
 *
 * @return 故障屏蔽
 *
 * 返回故障屏蔽寄存器的内容
 */
extern uint32_t __get_FAULTMASK(void);

/**
 * @brief 设置故障屏蔽值
 *
 * @param faultMask 故障屏蔽值
 *
 * 设置故障屏蔽寄存器
 */
extern void __set_FAULTMASK(uint32_t faultMask);

/**
 * @brief 返回控制寄存器的值
 * 
 * @return 控制值
 *
 * 返回控制寄存器的内容
 */
extern uint32_t __get_CONTROL(void);

/**
 * @brief 设置控制寄存器的值
 *
 * @param control 控制值
 *
 * 设置控制寄存器
 */
extern void __set_CONTROL(uint32_t control);

#else  /* (__ARMCC_VERSION >= 400000)  */

/**
 * @brief 清除由 ldrex 创建的独占锁
 *
 * 清除由 ldrex 创建的独占锁。
 */
#define __CLREX                           __clrex

/**
 * @brief 返回基优先级值
 *
 * @return 基优先级
 *
 * 返回基优先级寄存器的内容
 */
static __INLINE uint32_t  __get_BASEPRI(void)
{
  register uint32_t __regBasePri         __ASM("basepri");
  return(__regBasePri);
}

/**
 * @brief 设置基优先级值
 *
 * @param basePri 基优先级
 *
 * 设置基优先级寄存器
 */
static __INLINE void __set_BASEPRI(uint32_t basePri)
{
  register uint32_t __regBasePri         __ASM("basepri");
  __regBasePri = (basePri & 0xff);
}

/**
 * @brief 返回优先级屏蔽值
 *
 * @return 优先级屏蔽
 *
 * 返回优先级屏蔽寄存器中优先级屏蔽位的状态
 */
static __INLINE uint32_t __get_PRIMASK(void)
{
  register uint32_t __regPriMask         __ASM("primask");
  return(__regPriMask);
}

/**
 * @brief 设置优先级屏蔽值
 *
 * @param priMask 优先级屏蔽
 *
 * 设置优先级屏蔽寄存器中的优先级屏蔽位
 */
static __INLINE void __set_PRIMASK(uint32_t priMask)
{
  register uint32_t __regPriMask         __ASM("primask");
  __regPriMask = (priMask);
}

/**
 * @brief 返回故障屏蔽值
 *
 * @return 故障屏蔽
 *
 * 返回故障屏蔽寄存器的内容
 */
static __INLINE uint32_t __get_FAULTMASK(void)
{
  register uint32_t __regFaultMask       __ASM("faultmask");
  return(__regFaultMask);
}

/**
 * @brief 设置故障屏蔽值
 *
 * @param faultMask 故障屏蔽值
 *
 * 设置故障屏蔽寄存器
 */
static __INLINE void __set_FAULTMASK(uint32_t faultMask)
{
  register uint32_t __regFaultMask       __ASM("faultmask");
  __regFaultMask = (faultMask & 1);
}

/**
 * @brief 返回控制寄存器的值
 * 
 * @return 控制值
 *
 * 返回控制寄存器的内容
 */
static __INLINE uint32_t __get_CONTROL(void)
{
  register uint32_t __regControl         __ASM("control");
  return(__regControl);
}

/**
 * @brief 设置控制寄存器的值
 *
 * @param control 控制值
 *
 * 设置控制寄存器
 */
static __INLINE void __set_CONTROL(uint32_t control)
{
  register uint32_t __regControl         __ASM("control");
  __regControl = control;
}

#endif /* __ARMCC_VERSION  */ 



#elif (defined (__ICCARM__)) /*------------------ ICC 编译器 -------------------*/
/* IAR iccarm 专用函数 */

#define __enable_irq                              __enable_interrupt        /*!< 全局中断使能 */
#define __disable_irq                             __disable_interrupt       /*!< 全局中断失能 */

static __INLINE void __enable_fault_irq()         { __ASM ("cpsie f"); }
static __INLINE void __disable_fault_irq()        { __ASM ("cpsid f"); }

#define __NOP                                     __no_operation            /*!< IAR 编译器中的空操作内建函数 */ 
static __INLINE  void __WFI()                     { __ASM ("wfi"); }
static __INLINE  void __WFE()                     { __ASM ("wfe"); }
static __INLINE  void __SEV()                     { __ASM ("sev"); }
static __INLINE  void __CLREX()                   { __ASM ("clrex"); }

/* intrinsic void __ISB(void)                                     */
/* intrinsic void __DSB(void)                                     */
/* intrinsic void __DMB(void)                                     */
/* intrinsic void __set_PRIMASK();                                */
/* intrinsic void __get_PRIMASK();                                */
/* intrinsic void __set_FAULTMASK();                              */
/* intrinsic void __get_FAULTMASK();                              */
/* intrinsic uint32_t __REV(uint32_t value);                      */
/* intrinsic uint32_t __REVSH(uint32_t value);                    */
/* intrinsic unsigned long __STREX(unsigned long, unsigned long); */
/* intrinsic unsigned long __LDREX(unsigned long *);              */


/**
 * @brief 返回进程堆栈指针
 *
 * @return 进程堆栈指针
 *
 * 返回实际的进程堆栈指针
 */
extern uint32_t __get_PSP(void);

/**
 * @brief 设置进程堆栈指针
 *
 * @param topOfProcStack 进程堆栈指针
 *
 * 将 ProcessStackPointer 的值赋给 MSP 
 * （进程堆栈指针）Cortex 处理器寄存器
 */
extern void __set_PSP(uint32_t topOfProcStack);

/**
 * @brief 返回主堆栈指针
 *
 * @return 主堆栈指针
 *
 * 返回 MSP（主堆栈指针）的当前值
 * Cortex 处理器寄存器
 */
extern uint32_t __get_MSP(void);

/**
 * @brief 设置主堆栈指针
 *
 * @param topOfMainStack 主堆栈指针
 *
 * 将 mainStackPointer 的值赋给 MSP 
 * （主堆栈指针）Cortex 处理器寄存器
 */
extern void __set_MSP(uint32_t topOfMainStack);

/**
 * @brief 反转无符号短整型值的字节顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转无符号短整型值的字节顺序
 */
extern uint32_t __REV16(uint16_t value);

/**
 * @brief 反转值的位顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转值的位顺序
 */
extern uint32_t __RBIT(uint32_t value);

/**
 * @brief 独占加载 LDR（8 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 8 位值的独占 LDR 指令）
 */
extern uint8_t __LDREXB(uint8_t *addr);

/**
 * @brief 独占加载 LDR（16 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 16 位值的独占 LDR 指令
 */
extern uint16_t __LDREXH(uint16_t *addr);

/**
 * @brief 独占加载 LDR（32 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 32 位值的独占 LDR 指令
 */
extern uint32_t __LDREXW(uint32_t *addr);

/**
 * @brief 独占存储 STR（8 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 8 位值的独占 STR 指令
 */
extern uint32_t __STREXB(uint8_t value, uint8_t *addr);

/**
 * @brief 独占存储 STR（16 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 16 位值的独占 STR 指令
 */
extern uint32_t __STREXH(uint16_t value, uint16_t *addr);

/**
 * @brief 独占存储 STR（32 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 32 位值的独占 STR 指令
 */
extern uint32_t __STREXW(uint32_t value, uint32_t *addr);



#elif (defined (__GNUC__)) /*------------------ GNU 编译器 ---------------------*/
/* GNU gcc 专用函数 */

static __INLINE void __enable_irq()               { __ASM volatile ("cpsie i"); }
static __INLINE void __disable_irq()              { __ASM volatile ("cpsid i"); }

static __INLINE void __enable_fault_irq()         { __ASM volatile ("cpsie f"); }
static __INLINE void __disable_fault_irq()        { __ASM volatile ("cpsid f"); }

static __INLINE void __NOP()                      { __ASM volatile ("nop"); }
static __INLINE void __WFI()                      { __ASM volatile ("wfi"); }
static __INLINE void __WFE()                      { __ASM volatile ("wfe"); }
static __INLINE void __SEV()                      { __ASM volatile ("sev"); }
static __INLINE void __ISB()                      { __ASM volatile ("isb"); }
static __INLINE void __DSB()                      { __ASM volatile ("dsb"); }
static __INLINE void __DMB()                      { __ASM volatile ("dmb"); }
static __INLINE void __CLREX()                    { __ASM volatile ("clrex"); }


/**
 * @brief 返回进程堆栈指针
 *
 * @return 进程堆栈指针
 *
 * 返回实际的进程堆栈指针
 */
extern uint32_t __get_PSP(void);

/**
 * @brief 设置进程堆栈指针
 *
 * @param topOfProcStack 进程堆栈指针
 *
 * 将 ProcessStackPointer 的值赋给 MSP 
 * （进程堆栈指针）Cortex 处理器寄存器
 */
extern void __set_PSP(uint32_t topOfProcStack);

/**
 * @brief 返回主堆栈指针
 *
 * @return 主堆栈指针
 *
 * 返回 MSP（主堆栈指针）的当前值
 * Cortex 处理器寄存器
 */
extern uint32_t __get_MSP(void);

/**
 * @brief 设置主堆栈指针
 *
 * @param topOfMainStack 主堆栈指针
 *
 * 将 mainStackPointer 的值赋给 MSP 
 * （主堆栈指针）Cortex 处理器寄存器
 */
extern void __set_MSP(uint32_t topOfMainStack);

/**
 * @brief 返回基优先级值
 *
 * @return 基优先级
 *
 * 返回基优先级寄存器的内容
 */
extern uint32_t __get_BASEPRI(void);

/**
 * @brief 设置基优先级值
 *
 * @param basePri 基优先级
 *
 * 设置基优先级寄存器
 */
extern void __set_BASEPRI(uint32_t basePri);

/**
 * @brief 返回优先级屏蔽值
 *
 * @return 优先级屏蔽
 *
 * 返回优先级屏蔽寄存器中优先级屏蔽位的状态
 */
extern uint32_t  __get_PRIMASK(void);

/**
 * @brief 设置优先级屏蔽值
 *
 * @param priMask 优先级屏蔽
 *
 * 设置优先级屏蔽寄存器中的优先级屏蔽位
 */
extern void __set_PRIMASK(uint32_t priMask);

/**
 * @brief 返回故障屏蔽值
 *
 * @return 故障屏蔽
 *
 * 返回故障屏蔽寄存器的内容
 */
extern uint32_t __get_FAULTMASK(void);

/**
 * @brief 设置故障屏蔽值
 *
 * @param faultMask 故障屏蔽值
 *
 * 设置故障屏蔽寄存器
 */
extern void __set_FAULTMASK(uint32_t faultMask);

/**
 * @brief 返回控制寄存器的值
* 
*  @return 控制值
 *
 * 返回控制寄存器的内容
 */
extern uint32_t __get_CONTROL(void);

/**
 * @brief 设置控制寄存器的值
 *
 * @param control 控制值
 *
 * 设置控制寄存器
 */
extern void __set_CONTROL(uint32_t control);

/**
 * @brief 反转整型值的字节顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转整型值的字节顺序
 */
extern uint32_t __REV(uint32_t value);

/**
 * @brief 反转无符号短整型值的字节顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转无符号短整型值的字节顺序
 */
extern uint32_t __REV16(uint16_t value);

/**
 * @brief 反转有符号短整型值的字节顺序，并符号扩展为整数
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转有符号短整型值的字节顺序，并符号扩展为整数
 */
extern int32_t __REVSH(int16_t value);

/**
 * @brief 反转值的位顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转值的位顺序
 */
extern uint32_t __RBIT(uint32_t value);

/**
 * @brief 独占加载 LDR（8 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 8 位值的独占 LDR 指令
 */
extern uint8_t __LDREXB(uint8_t *addr);

/**
 * @brief 独占加载 LDR（16 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 16 位值的独占 LDR 指令
 */
extern uint16_t __LDREXH(uint16_t *addr);

/**
 * @brief 独占加载 LDR（32 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 32 位值的独占 LDR 指令
 */
extern uint32_t __LDREXW(uint32_t *addr);

/**
 * @brief 独占存储 STR（8 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 8 位值的独占 STR 指令
 */
extern uint32_t __STREXB(uint8_t value, uint8_t *addr);

/**
 * @brief 独占存储 STR（16 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 16 位值的独占 STR 指令
 */
extern uint32_t __STREXH(uint16_t value, uint16_t *addr);

/**
 * @brief 独占存储 STR（32 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 32 位值的独占 STR 指令
 */
extern uint32_t __STREXW(uint32_t value, uint32_t *addr);


#elif (defined (__TASKING__)) /*------------------ TASKING 编译器 ---------------------*/
/* TASKING carm 专用函数 */

/*
 * CMSIS 函数已在编译器中以 intrinsic（内建函数）的形式实现。
 * 请使用 "carm -?i" 获取所有 intrinsic 的最新列表，
 * 其中包括 CMSIS 的 intrinsic。
 */

#endif


/** @addtogroup CMSIS_CM3_Core_FunctionInterface CMSIS CM3 内核函数接口
  内核函数接口包含：
  - 内核 NVIC 函数
  - 内核 SysTick 函数
  - 内核复位函数
*/
/*@{*/

/* ########################## NVIC 函数 #################################### */

/**
 * @brief 设置 NVIC 中断控制器中的优先级分组
 *
 * @param PriorityGroup 为优先级分组域
 *
 * 使用所需的解锁序列设置优先级分组域。
 * 参数 priority_grouping 被赋给域 
 * SCB->AIRCR [10:8] PRIGROUP 域。仅使用 0..7 的取值。
 * 当优先级分组与可用的
 * 优先级位数（__NVIC_PRIO_BITS）冲突时，设置尽可能小的优先级分组。
 */
static __INLINE void NVIC_SetPriorityGrouping(uint32_t PriorityGroup)
{
  uint32_t reg_value;
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);                         /* 仅使用 0..7 的取值          */
  
  reg_value  =  SCB->AIRCR;                                                   /* 读取旧的寄存器配置    */
  reg_value &= ~(SCB_AIRCR_VECTKEY_Msk | SCB_AIRCR_PRIGROUP_Msk);             /* 清除要修改的位               */
  reg_value  =  (reg_value                       |
                (0x5FA << SCB_AIRCR_VECTKEY_Pos) | 
                (PriorityGroupTmp << 8));                                     /* 写入关键字和优先级分组 */
  SCB->AIRCR =  reg_value;
}

/**
 * @brief 从 NVIC 中断控制器获取优先级分组
 *
 * @return 优先级分组域 
 *
 * 从 NVIC 中断控制器获取优先级分组。
 * 优先级分组为 SCB->AIRCR [10:8] PRIGROUP 域。
 */
static __INLINE uint32_t NVIC_GetPriorityGrouping(void)
{
  return ((SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) >> SCB_AIRCR_PRIGROUP_Pos);   /* 读取优先级分组域 */
}

/**
 * @brief 在 NVIC 中断控制器中使能中断
 *
 * @param IRQn 要使能的外部中断的正编号
 *
 * 在 NVIC 中断控制器中使能指定的设备中断。
 * 中断编号不能为负值。
 */
static __INLINE void NVIC_EnableIRQ(IRQn_Type IRQn)
{
  NVIC->ISER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* 使能中断 */
}

/**
 * @brief 失能指定的外部中断线
 * 
 * @param IRQn 要失能的外部中断的正编号
 * 
 * 在 NVIC 中断控制器中失能指定的设备中断。
 * 中断编号不能为负值。
 */
static __INLINE void NVIC_DisableIRQ(IRQn_Type IRQn)
{
  NVIC->ICER[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* 失能中断 */
}

/**
 * @brief 读取指定设备中断源的中断挂起位
 * 
 * @param IRQn 设备中断的编号
 * @return 1 = 中断挂起，0 = 中断未挂起
 *
 * 读取 NVIC 中的挂起寄存器，若状态为挂起则返回 1， 
 * 否则返回 0
 */
static __INLINE uint32_t NVIC_GetPendingIRQ(IRQn_Type IRQn)
{
  return((uint32_t) ((NVIC->ISPR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0)); /* 挂起则返回 1，否则返回 0 */
}

/**
 * @brief 置位外部中断的挂起位
 * 
 * @param IRQn 要置挂起的中断编号
 *
 * 置位指定中断的挂起位。
 * 中断编号不能为负值。
 */
static __INLINE void NVIC_SetPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ISPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* 置位中断挂起 */
}

/**
 * @brief 清除外部中断的挂起位
 *
 * @param IRQn 要清挂起的中断编号
 *
 * 清除指定中断的挂起位。 
 * 中断编号不能为负值。
 */
static __INLINE void NVIC_ClearPendingIRQ(IRQn_Type IRQn)
{
  NVIC->ICPR[((uint32_t)(IRQn) >> 5)] = (1 << ((uint32_t)(IRQn) & 0x1F)); /* 清除中断挂起 */
}

/**
 * @brief 读取外部中断的激活位
 *
 * @param IRQn 要读取激活位的中断编号
 * @return 1 = 中断激活，0 = 中断未激活
 *
 * 读取 NVIC 中的激活寄存器，若状态为激活则返回 1， 
 * 否则返回 0。
 */
static __INLINE uint32_t NVIC_GetActive(IRQn_Type IRQn)
{
  return((uint32_t)((NVIC->IABR[(uint32_t)(IRQn) >> 5] & (1 << ((uint32_t)(IRQn) & 0x1F)))?1:0)); /* 激活则返回 1，否则返回 0 */
}

/**
 * @brief 设置中断的优先级
 *
 * @param IRQn 要设置优先级的中断编号
 * @param priority 要设置的优先级
 *
 * 设置指定中断的优先级。该中断 
 * 编号为正表示外部（设备特定） 
 * 中断，为负表示内部（内核）中断。
 *
 * 注意：并非每个内核中断都能设置优先级。
 */
static __INLINE void NVIC_SetPriority(IRQn_Type IRQn, uint32_t priority)
{
  if(IRQn < 0) {
    SCB->SHP[((uint32_t)(IRQn) & 0xF)-4] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff); } /* 设置 Cortex-M3 系统中断的优先级 */
  else {
    NVIC->IP[(uint32_t)(IRQn)] = ((priority << (8 - __NVIC_PRIO_BITS)) & 0xff);    }        /* 设置设备特定中断的优先级  */
}

/**
 * @brief 读取中断的优先级
 *
 * @param IRQn 要获取优先级的中断编号
 * @return 该中断的优先级
 *
 * 读取指定中断的优先级。该中断 
 * 编号为正表示外部（设备特定） 
 * 中断，为负表示内部（内核）中断。
 *
 * 返回的优先级值会自动对齐到所实现的
 * 微控制器的优先级位数。
 *
 * 注意：并非每个内核中断都能设置优先级。
 */
static __INLINE uint32_t NVIC_GetPriority(IRQn_Type IRQn)
{

  if(IRQn < 0) {
    return((uint32_t)(SCB->SHP[((uint32_t)(IRQn) & 0xF)-4] >> (8 - __NVIC_PRIO_BITS)));  } /* 获取 Cortex-M3 系统中断的优先级 */
  else {
    return((uint32_t)(NVIC->IP[(uint32_t)(IRQn)]           >> (8 - __NVIC_PRIO_BITS)));  } /* 获取设备特定中断的优先级  */
}


/**
 * @brief 编码中断的优先级
 *
 * @param PriorityGroup 所使用的优先级分组
 * @param PreemptPriority 抢占优先级值（从 0 开始）
 * @param SubPriority 子优先级值（从 0 开始）
 * @return 编码后的中断优先级
 *
 * 使用给定的优先级分组、
 * 抢占优先级值和子优先级值编码中断的优先级。
 * 当优先级分组与可用的
 * 优先级位数（__NVIC_PRIO_BITS）冲突时，设置尽可能小的优先级分组。
 *
 * 返回的优先级值可用于 NVIC_SetPriority(...) 函数
 */
static __INLINE uint32_t NVIC_EncodePriority (uint32_t PriorityGroup, uint32_t PreemptPriority, uint32_t SubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);          /* 仅使用 0..7 的取值          */
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > __NVIC_PRIO_BITS) ? __NVIC_PRIO_BITS : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + __NVIC_PRIO_BITS) < 7) ? 0 : PriorityGroupTmp - 7 + __NVIC_PRIO_BITS;
 
  return (
           ((PreemptPriority & ((1 << (PreemptPriorityBits)) - 1)) << SubPriorityBits) |
           ((SubPriority     & ((1 << (SubPriorityBits    )) - 1)))
         );
}


/**
 * @brief 解码中断的优先级
 *
 * @param Priority 该中断的优先级
 * @param PriorityGroup 所使用的优先级分组
 * @param pPreemptPriority 抢占优先级值（从 0 开始）
 * @param pSubPriority 子优先级值（从 0 开始）
 *
 * 使用给定的优先级分组，将中断优先级值解码为 
 * 抢占优先级值和子优先级值编码中断的优先级。
 * 当优先级分组与可用的
 * 优先级位数（__NVIC_PRIO_BITS）冲突时，设置尽可能小的优先级分组。
 *
 * 优先级值可通过 NVIC_GetPriority(...) 函数获取
 */
static __INLINE void NVIC_DecodePriority (uint32_t Priority, uint32_t PriorityGroup, uint32_t* pPreemptPriority, uint32_t* pSubPriority)
{
  uint32_t PriorityGroupTmp = (PriorityGroup & 0x07);          /* 仅使用 0..7 的取值          */
  uint32_t PreemptPriorityBits;
  uint32_t SubPriorityBits;

  PreemptPriorityBits = ((7 - PriorityGroupTmp) > __NVIC_PRIO_BITS) ? __NVIC_PRIO_BITS : 7 - PriorityGroupTmp;
  SubPriorityBits     = ((PriorityGroupTmp + __NVIC_PRIO_BITS) < 7) ? 0 : PriorityGroupTmp - 7 + __NVIC_PRIO_BITS;
  
  *pPreemptPriority = (Priority >> SubPriorityBits) & ((1 << (PreemptPriorityBits)) - 1);
  *pSubPriority     = (Priority                   ) & ((1 << (SubPriorityBits    )) - 1);
}



/* ################################## SysTick 函数 ############################################ */

#if (!defined (__Vendor_SysTickConfig)) || (__Vendor_SysTickConfig == 0)

/**
 * @brief 初始化并启动 SysTick 计数器及其中断。
 *
 * @param ticks 两次中断之间的节拍数
 * @return 1 = 失败，0 = 成功
 *
 * 初始化系统节拍定时器及其中断，并以自由运行模式
 * 启动系统节拍定时器 / 计数器，以产生 
 * 周期性中断。
 */
static __INLINE uint32_t SysTick_Config(uint32_t ticks)
{ 
  if (ticks > SysTick_LOAD_RELOAD_Msk)  return (1);            /* 重装载值不可用 */
                                                               
  SysTick->LOAD  = (ticks & SysTick_LOAD_RELOAD_Msk) - 1;      /* 设置重装载寄存器 */
  NVIC_SetPriority (SysTick_IRQn, (1<<__NVIC_PRIO_BITS) - 1);  /* 设置 Cortex-M0 系统中断的优先级 */
  SysTick->VAL   = 0;                                          /* 装载 SysTick 计数器值 */
  SysTick->CTRL  = SysTick_CTRL_CLKSOURCE_Msk | 
                   SysTick_CTRL_TICKINT_Msk   | 
                   SysTick_CTRL_ENABLE_Msk;                    /* 使能 SysTick 中断和 SysTick 定时器 */
  return (0);                                                  /* 函数执行成功 */
}

#endif




/* ################################## 复位函数 ############################################ */

/**
 * @brief 发起系统复位请求。
 *
 * 发起系统复位请求以复位 MCU
 */
static __INLINE void NVIC_SystemReset(void)
{
  SCB->AIRCR  = ((0x5FA << SCB_AIRCR_VECTKEY_Pos)      | 
                 (SCB->AIRCR & SCB_AIRCR_PRIGROUP_Msk) | 
                 SCB_AIRCR_SYSRESETREQ_Msk);                   /* 保持优先级分组不变 */
  __DSB();                                                     /* 确保存储器访问完成 */              
  while(1);                                                    /* 等待复位完成 */
}

/*@}*/ /* CMSIS_CM3_Core_FunctionInterface 组结束 */



/* ##################################### 调试输入 / 输出函数 ########################################### */

/** @addtogroup CMSIS_CM3_CoreDebugInterface CMSIS CM3 内核调试接口
  内核调试接口包含：
  - 内核调试接收 / 发送函数
  - 内核调试定义
  - 内核调试变量
*/
/*@{*/

extern volatile int ITM_RxBuffer;                    /*!< 用于接收字符的变量                             */
#define             ITM_RXBUFFER_EMPTY    0x5AA55AA5 /*!< 标识 ITM_RxBuffer 已准备好接收下一个字符的值 */


/**
 * @brief 通过 ITM 通道 0 输出一个字符
 *
 * @param ch 要输出的字符
 * @return 要输出的字符
 *
 * 该函数通过 ITM 通道 0 输出一个字符。 
 * 当没有已预订该输出的调试器连接时，该函数立即返回。  
 * 当连接了调试器、但上一个字符尚未发送完成时，该函数会阻塞。 
 */
static __INLINE uint32_t ITM_SendChar (uint32_t ch)
{
  if ((CoreDebug->DEMCR & CoreDebug_DEMCR_TRCENA_Msk)  &&      /* 跟踪已使能 */
      (ITM->TCR & ITM_TCR_ITMENA_Msk)                  &&      /* ITM 已使能 */
      (ITM->TER & (1ul << 0)        )                    )     /* ITM 端口 #0 已使能 */
  {
    while (ITM->PORT[0].u32 == 0);
    ITM->PORT[0].u8 = (uint8_t) ch;
  }  
  return (ch);
}


/**
 * @brief 通过变量 ITM_RxBuffer 输入一个字符
 *
 * @return 接收到的字符，-1 = 未收到字符
 *
 * 该函数通过变量 ITM_RxBuffer 输入一个字符。 
 * 当没有已预订该输出的调试器连接时，该函数立即返回。  
 * 当连接了调试器、但上一个字符尚未发送完成时，该函数会阻塞。 
 */
static __INLINE int ITM_ReceiveChar (void) {
  int ch = -1;                               /* 无可用字符 */

  if (ITM_RxBuffer != ITM_RXBUFFER_EMPTY) {
    ch = ITM_RxBuffer;
    ITM_RxBuffer = ITM_RXBUFFER_EMPTY;       /* 已准备好接收下一个字符 */
  }
  
  return (ch); 
}


/**
 * @brief 检查变量 ITM_RxBuffer 中是否有可用字符
 *
 * @return 1 = 有可用字符，0 = 无可用字符
 *
 * 该函数检查变量 ITM_RxBuffer 中是否有可用字符。 
 * 若有可用字符则返回 '1'，无可用字符则返回 '0'。 
 */
static __INLINE int ITM_CheckChar (void) {

  if (ITM_RxBuffer == ITM_RXBUFFER_EMPTY) {
    return (0);                                 /* 无可用字符 */
  } else {
    return (1);                                 /*    有可用字符 */
  }
}

/*@}*/ /* CMSIS_CM3_core_DebugInterface 组结束 */


#ifdef __cplusplus
}
#endif

/*@}*/ /* CMSIS_CM3_core_definitions 组结束 */

#endif /* __CM3_CORE_H__ */

/*lint -restore */
