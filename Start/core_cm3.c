/**************************************************************************//**
 * @file     core_cm3.c
 * @brief CMSIS Cortex-M3 内核外设访问层源文件
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

#include <stdint.h>

/* 定义各编译器专用符号 */
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

/**
 * @brief 返回进程堆栈指针
 *
 * @return 进程堆栈指针
 *
 * 返回实际的进程堆栈指针
 */
__ASM uint32_t __get_PSP(void)
{
  mrs r0, psp
  bx lr
}

/**
 * @brief 设置进程堆栈指针
 *
 * @param topOfProcStack 进程堆栈指针
 *
 * 将 ProcessStackPointer 的值赋给 MSP 
 * （进程堆栈指针）Cortex 处理器寄存器
 */
__ASM void __set_PSP(uint32_t topOfProcStack)
{
  msr psp, r0
  bx lr
}

/**
 * @brief 返回主堆栈指针
 *
 * @return 主堆栈指针
 *
 * 返回 MSP（主堆栈指针）的当前值
 * Cortex 处理器寄存器
 */
__ASM uint32_t __get_MSP(void)
{
  mrs r0, msp
  bx lr
}

/**
 * @brief 设置主堆栈指针
 *
 * @param topOfMainStack 主堆栈指针
 *
 * 将 mainStackPointer 的值赋给 MSP 
 * （主堆栈指针）Cortex 处理器寄存器
 */
__ASM void __set_MSP(uint32_t mainStackPointer)
{
  msr msp, r0
  bx lr
}

/**
 * @brief 反转无符号短整型值的字节顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转无符号短整型值的字节顺序
 */
__ASM uint32_t __REV16(uint16_t value)
{
  rev16 r0, r0
  bx lr
}

/**
 * @brief 反转有符号短整型值的字节顺序，并符号扩展为整数
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转有符号短整型值的字节顺序，并符号扩展为整数
 */
__ASM int32_t __REVSH(int16_t value)
{
  revsh r0, r0
  bx lr
}


#if (__ARMCC_VERSION < 400000)

/**
 * @brief 清除由 ldrex 创建的独占锁
 *
 * 清除由 ldrex 创建的独占锁。
 */
__ASM void __CLREX(void)
{
  clrex
}

/**
 * @brief 返回基优先级值
 *
 * @return 基优先级
 *
 * 返回基优先级寄存器的内容
 */
__ASM uint32_t  __get_BASEPRI(void)
{
  mrs r0, basepri
  bx lr
}

/**
 * @brief 设置基优先级值
 *
 * @param basePri 基优先级
 *
 * 设置基优先级寄存器
 */
__ASM void __set_BASEPRI(uint32_t basePri)
{
  msr basepri, r0
  bx lr
}

/**
 * @brief 返回优先级屏蔽值
 *
 * @return 优先级屏蔽
 *
 * 返回优先级屏蔽寄存器中优先级屏蔽位的状态
 */
__ASM uint32_t __get_PRIMASK(void)
{
  mrs r0, primask
  bx lr
}

/**
 * @brief 设置优先级屏蔽值
 *
 * @param priMask 优先级屏蔽
 *
 * 设置优先级屏蔽寄存器中的优先级屏蔽位
 */
__ASM void __set_PRIMASK(uint32_t priMask)
{
  msr primask, r0
  bx lr
}

/**
 * @brief 返回故障屏蔽值
 *
 * @return 故障屏蔽
 *
 * 返回故障屏蔽寄存器的内容
 */
__ASM uint32_t  __get_FAULTMASK(void)
{
  mrs r0, faultmask
  bx lr
}

/**
 * @brief 设置故障屏蔽值
 *
 * @param faultMask 故障屏蔽值
 *
 * 设置故障屏蔽寄存器
 */
__ASM void __set_FAULTMASK(uint32_t faultMask)
{
  msr faultmask, r0
  bx lr
}

/**
 * @brief 返回控制寄存器的值
 * 
 * @return 控制值
 *
 * 返回控制寄存器的内容
 */
__ASM uint32_t __get_CONTROL(void)
{
  mrs r0, control
  bx lr
}

/**
 * @brief 设置控制寄存器的值
 *
 * @param control 控制值
 *
 * 设置控制寄存器
 */
__ASM void __set_CONTROL(uint32_t control)
{
  msr control, r0
  bx lr
}

#endif /* __ARMCC_VERSION  */ 



#elif (defined (__ICCARM__)) /*------------------ ICC 编译器 -------------------*/
/* IAR iccarm 专用函数 */
#pragma diag_suppress=Pe940

/**
 * @brief 返回进程堆栈指针
 *
 * @return 进程堆栈指针
 *
 * 返回实际的进程堆栈指针
 */
uint32_t __get_PSP(void)
{
  __ASM("mrs r0, psp");
  __ASM("bx lr");
}

/**
 * @brief 设置进程堆栈指针
 *
 * @param topOfProcStack 进程堆栈指针
 *
 * 将 ProcessStackPointer 的值赋给 MSP 
 * （进程堆栈指针）Cortex 处理器寄存器
 */
void __set_PSP(uint32_t topOfProcStack)
{
  __ASM("msr psp, r0");
  __ASM("bx lr");
}

/**
 * @brief 返回主堆栈指针
 *
 * @return 主堆栈指针
 *
 * 返回 MSP（主堆栈指针）的当前值
 * Cortex 处理器寄存器
 */
uint32_t __get_MSP(void)
{
  __ASM("mrs r0, msp");
  __ASM("bx lr");
}

/**
 * @brief 设置主堆栈指针
 *
 * @param topOfMainStack 主堆栈指针
 *
 * 将 mainStackPointer 的值赋给 MSP 
 * （主堆栈指针）Cortex 处理器寄存器
 */
void __set_MSP(uint32_t topOfMainStack)
{
  __ASM("msr msp, r0");
  __ASM("bx lr");
}

/**
 * @brief 反转无符号短整型值的字节顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转无符号短整型值的字节顺序
 */
uint32_t __REV16(uint16_t value)
{
  __ASM("rev16 r0, r0");
  __ASM("bx lr");
}

/**
 * @brief 反转值的位顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转值的位顺序
 */
uint32_t __RBIT(uint32_t value)
{
  __ASM("rbit r0, r0");
  __ASM("bx lr");
}

/**
 * @brief 独占加载 LDR（8 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 8 位值的独占 LDR 指令）
 */
uint8_t __LDREXB(uint8_t *addr)
{
  __ASM("ldrexb r0, [r0]");
  __ASM("bx lr"); 
}

/**
 * @brief 独占加载 LDR（16 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 16 位值的独占 LDR 指令
 */
uint16_t __LDREXH(uint16_t *addr)
{
  __ASM("ldrexh r0, [r0]");
  __ASM("bx lr");
}

/**
 * @brief 独占加载 LDR（32 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 32 位值的独占 LDR 指令
 */
uint32_t __LDREXW(uint32_t *addr)
{
  __ASM("ldrex r0, [r0]");
  __ASM("bx lr");
}

/**
 * @brief 独占存储 STR（8 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 8 位值的独占 STR 指令
 */
uint32_t __STREXB(uint8_t value, uint8_t *addr)
{
  __ASM("strexb r0, r0, [r1]");
  __ASM("bx lr");
}

/**
 * @brief 独占存储 STR（16 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 16 位值的独占 STR 指令
 */
uint32_t __STREXH(uint16_t value, uint16_t *addr)
{
  __ASM("strexh r0, r0, [r1]");
  __ASM("bx lr");
}

/**
 * @brief 独占存储 STR（32 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 32 位值的独占 STR 指令
 */
uint32_t __STREXW(uint32_t value, uint32_t *addr)
{
  __ASM("strex r0, r0, [r1]");
  __ASM("bx lr");
}

#pragma diag_default=Pe940


#elif (defined (__GNUC__)) /*------------------ GNU 编译器 ---------------------*/
/* GNU gcc 专用函数 */

/**
 * @brief 返回进程堆栈指针
 *
 * @return 进程堆栈指针
 *
 * 返回实际的进程堆栈指针
 */
uint32_t __get_PSP(void) __attribute__( ( naked ) );
uint32_t __get_PSP(void)
{
  uint32_t result=0;

  __ASM volatile ("MRS %0, psp\n\t" 
                  "MOV r0, %0 \n\t"
                  "BX  lr     \n\t"  : "=r" (result) );
  return(result);
}

/**
 * @brief 设置进程堆栈指针
 *
 * @param topOfProcStack 进程堆栈指针
 *
 * 将 ProcessStackPointer 的值赋给 MSP 
 * （进程堆栈指针）Cortex 处理器寄存器
 */
void __set_PSP(uint32_t topOfProcStack) __attribute__( ( naked ) );
void __set_PSP(uint32_t topOfProcStack)
{
  __ASM volatile ("MSR psp, %0\n\t"
                  "BX  lr     \n\t" : : "r" (topOfProcStack) );
}

/**
 * @brief 返回主堆栈指针
 *
 * @return 主堆栈指针
 *
 * 返回 MSP（主堆栈指针）的当前值
 * Cortex 处理器寄存器
 */
uint32_t __get_MSP(void) __attribute__( ( naked ) );
uint32_t __get_MSP(void)
{
  uint32_t result=0;

  __ASM volatile ("MRS %0, msp\n\t" 
                  "MOV r0, %0 \n\t"
                  "BX  lr     \n\t"  : "=r" (result) );
  return(result);
}

/**
 * @brief 设置主堆栈指针
 *
 * @param topOfMainStack 主堆栈指针
 *
 * 将 mainStackPointer 的值赋给 MSP 
 * （主堆栈指针）Cortex 处理器寄存器
 */
void __set_MSP(uint32_t topOfMainStack) __attribute__( ( naked ) );
void __set_MSP(uint32_t topOfMainStack)
{
  __ASM volatile ("MSR msp, %0\n\t"
                  "BX  lr     \n\t" : : "r" (topOfMainStack) );
}

/**
 * @brief 返回基优先级值
 *
 * @return 基优先级
 *
 * 返回基优先级寄存器的内容
 */
uint32_t __get_BASEPRI(void)
{
  uint32_t result=0;
  
  __ASM volatile ("MRS %0, basepri_max" : "=r" (result) );
  return(result);
}

/**
 * @brief 设置基优先级值
 *
 * @param basePri 基优先级
 *
 * 设置基优先级寄存器
 */
void __set_BASEPRI(uint32_t value)
{
  __ASM volatile ("MSR basepri, %0" : : "r" (value) );
}

/**
 * @brief 返回优先级屏蔽值
 *
 * @return 优先级屏蔽
 *
 * 返回优先级屏蔽寄存器中优先级屏蔽位的状态
 */
uint32_t __get_PRIMASK(void)
{
  uint32_t result=0;

  __ASM volatile ("MRS %0, primask" : "=r" (result) );
  return(result);
}

/**
 * @brief 设置优先级屏蔽值
 *
 * @param priMask 优先级屏蔽
 *
 * 设置优先级屏蔽寄存器中的优先级屏蔽位
 */
void __set_PRIMASK(uint32_t priMask)
{
  __ASM volatile ("MSR primask, %0" : : "r" (priMask) );
}

/**
 * @brief 返回故障屏蔽值
 *
 * @return 故障屏蔽
 *
 * 返回故障屏蔽寄存器的内容
 */
uint32_t __get_FAULTMASK(void)
{
  uint32_t result=0;
  
  __ASM volatile ("MRS %0, faultmask" : "=r" (result) );
  return(result);
}

/**
 * @brief 设置故障屏蔽值
 *
 * @param faultMask 故障屏蔽值
 *
 * 设置故障屏蔽寄存器
 */
void __set_FAULTMASK(uint32_t faultMask)
{
  __ASM volatile ("MSR faultmask, %0" : : "r" (faultMask) );
}

/**
 * @brief 返回控制寄存器的值
* 
*  @return 控制值
 *
 * 返回控制寄存器的内容
 */
uint32_t __get_CONTROL(void)
{
  uint32_t result=0;

  __ASM volatile ("MRS %0, control" : "=r" (result) );
  return(result);
}

/**
 * @brief 设置控制寄存器的值
 *
 * @param control 控制值
 *
 * 设置控制寄存器
 */
void __set_CONTROL(uint32_t control)
{
  __ASM volatile ("MSR control, %0" : : "r" (control) );
}


/**
 * @brief 反转整型值的字节顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转整型值的字节顺序
 */
uint32_t __REV(uint32_t value)
{
  uint32_t result=0;
  
  __ASM volatile ("rev %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}

/**
 * @brief 反转无符号短整型值的字节顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转无符号短整型值的字节顺序
 */
uint32_t __REV16(uint16_t value)
{
  uint32_t result=0;
  
  __ASM volatile ("rev16 %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}

/**
 * @brief 反转有符号短整型值的字节顺序，并符号扩展为整数
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转有符号短整型值的字节顺序，并符号扩展为整数
 */
int32_t __REVSH(int16_t value)
{
  uint32_t result=0;
  
  __ASM volatile ("revsh %0, %1" : "=r" (result) : "r" (value) );
  return(result);
}

/**
 * @brief 反转值的位顺序
 *
 * @param value 要反转的值
 * @return 反转后的值
 *
 * 反转值的位顺序
 */
uint32_t __RBIT(uint32_t value)
{
  uint32_t result=0;
  
   __ASM volatile ("rbit %0, %1" : "=r" (result) : "r" (value) );
   return(result);
}

/**
 * @brief 独占加载 LDR（8 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 8 位值的独占 LDR 指令
 */
uint8_t __LDREXB(uint8_t *addr)
{
    uint8_t result=0;
  
   __ASM volatile ("ldrexb %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}

/**
 * @brief 独占加载 LDR（16 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 16 位值的独占 LDR 指令
 */
uint16_t __LDREXH(uint16_t *addr)
{
    uint16_t result=0;
  
   __ASM volatile ("ldrexh %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}

/**
 * @brief 独占加载 LDR（32 位）
 *
 * @param *addr 地址指针
 * @return (*address) 的值
 *
 * 用于 32 位值的独占 LDR 指令
 */
uint32_t __LDREXW(uint32_t *addr)
{
    uint32_t result=0;
  
   __ASM volatile ("ldrex %0, [%1]" : "=r" (result) : "r" (addr) );
   return(result);
}

/**
 * @brief 独占存储 STR（8 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 8 位值的独占 STR 指令
 */
uint32_t __STREXB(uint8_t value, uint8_t *addr)
{
   uint32_t result=0;
  
   __ASM volatile ("strexb %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}

/**
 * @brief 独占存储 STR（16 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 16 位值的独占 STR 指令
 */
uint32_t __STREXH(uint16_t value, uint16_t *addr)
{
   uint32_t result=0;
  
   __ASM volatile ("strexh %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}

/**
 * @brief 独占存储 STR（32 位）
 *
 * @param value 要存储的值
 * @param *addr 地址指针
 * @return 成功 / 失败
 *
 * 用于 32 位值的独占 STR 指令
 */
uint32_t __STREXW(uint32_t value, uint32_t *addr)
{
   uint32_t result=0;
  
   __ASM volatile ("strex %0, %2, [%1]" : "=r" (result) : "r" (addr), "r" (value) );
   return(result);
}


#elif (defined (__TASKING__)) /*------------------ TASKING 编译器 ---------------------*/
/* TASKING carm 专用函数 */

/*
 * CMSIS 函数已在编译器中以 intrinsic（内建函数）的形式实现。
 * 请使用 "carm -?i" 获取所有 intrinsic 的最新列表，
 * 其中包括 CMSIS 的 intrinsic。
 */

#endif
