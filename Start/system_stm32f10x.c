/**
  ******************************************************************************
  * @file    system_stm32f10x.c
  * @author  MCD Application Team
  * @version V3.5.0
  * @date    11-March-2011
  * @brief CMSIS Cortex-M3 设备外设访问层系统源文件。
  * 
  * 1. 本文件提供两个函数和一个全局变量，供用户在 
  *     应用程序中调用：
  *      - SystemInit()：配置系统时钟（系统时钟源、PLL 倍频
  *                      系数、AHB/APBx 分频系数和闪存设置）。 
  *                      该函数在启动时、复位之后立即被调用， 
  *                      位于跳转到主程序之前。该调用在
  *                      "startup_stm32f10x_xx.s" 文件中完成。
  *
  *      - SystemCoreClock 变量：保存内核时钟（HCLK），用户应用程序
  *                                  可用它来设置 SysTick 
  *                                  定时器或配置其他参数。
  *                                     
  *      - SystemCoreClockUpdate()：更新 SystemCoreClock 变量，
  *                                 必须在程序执行期间内核时钟发生
  *                                 变化时调用。
  *
  * 2. 每次器件复位后，都使用 HSI（8 MHz）作为系统时钟源。
  *    随后在 "startup_stm32f10x_xx.s" 文件中调用 SystemInit() 函数，
  *    以在跳转到主程序之前配置系统时钟。
  *
  * 3. 如果用户选择的系统时钟源启动失败，SystemInit()
  *    函数将不做任何处理，仍使用 HSI 作为系统时钟源。用户可以 
  *    在 SetSysClock() 函数中添加代码来处理该问题。
  *
  * 4. HSE 晶振的默认值设为 8 MHz（或 25 MHz，取决于
  *    所使用的产品），请参阅 "stm32f10x.h" 文件中的 "HSE_VALUE" 定义。 
  *    当直接或通过 PLL 使用 HSE 作为系统时钟源，而您
  *    使用的晶振不同时，必须将 HSE 值调整为符合您自己的
  *    配置。
  *        
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

/** @addtogroup CMSIS
  * @{
  */

/** @addtogroup stm32f10x_system
  * @{
  */  
  
/** @addtogroup STM32F10x_System_Private_Includes
  * @{
  */

#include "stm32f10x.h"

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Private_Defines
  * @{
  */

/*!< 取消注释与目标系统时钟（SYSCLK）
   频率相对应的那一行（复位后使用 HSI 作为 SYSCLK 源）
   
   重要说明：
   ============== 
   1. 每次器件复位后，都使用 HSI 作为系统时钟源。

   2. 请确保所选的系统时钟不超过您器件的
      最高频率。
      
   3. 如果下面没有任何一个宏定义被使能，则使用 HSI 作为系统时钟
    源。

   4. 本文件提供的系统时钟配置函数基于以下假设：
        - 对于低密度、中密度和高密度超值型器件，使用外部 8MHz 
          晶振驱动系统时钟。
        - 对于低密度、中密度和高密度器件，使用外部 8MHz 晶振
          驱动系统时钟。
        - 对于互联型器件，使用外部 25MHz 晶振驱动
          系统时钟。
     如果您使用的晶振不同，必须相应调整这些函数。
    */
    
#if defined (STM32F10X_LD_VL) || (defined STM32F10X_MD_VL) || (defined STM32F10X_HD_VL)
/* #define SYSCLK_FREQ_HSE    HSE_VALUE */
 #define SYSCLK_FREQ_24MHz  24000000
#else
/* #define SYSCLK_FREQ_HSE    HSE_VALUE */
/* #define SYSCLK_FREQ_24MHz  24000000 */ 
/* #define SYSCLK_FREQ_36MHz  36000000 */
/* #define SYSCLK_FREQ_48MHz  48000000 */
/* #define SYSCLK_FREQ_56MHz  56000000 */
#define SYSCLK_FREQ_72MHz  72000000
#endif

/*!< 如果您需要使用安装在
     STM3210E-EVAL 板（STM32 高密度和 XL 密度器件）或 
     STM32100E-EVAL 板（STM32 高密度超值型器件）上的外部 SRAM 作为数据存储器， */ 
#if defined (STM32F10X_HD) || (defined STM32F10X_XL) || (defined STM32F10X_HD_VL)
/* #define DATA_IN_ExtSRAM */
#endif

/*!< 如果您需要将向量表重定位到
     内部 SRAM，请取消注释下面这一行。 */ 
/* #define VECT_TAB_SRAM */
#define VECT_TAB_OFFSET  0x0 /*!< 向量表基地址偏移域。 
                                  该值必须是 0x200 的整数倍。 */


/**
  * @}
  */

/** @addtogroup STM32F10x_System_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Private_Variables
  * @{
  */

/*******************************************************************************
*  时钟定义
*******************************************************************************/
#ifdef SYSCLK_FREQ_HSE
  uint32_t SystemCoreClock         = SYSCLK_FREQ_HSE;        /*!< 系统时钟频率（内核时钟） */
#elif defined SYSCLK_FREQ_24MHz
  uint32_t SystemCoreClock         = SYSCLK_FREQ_24MHz;        /*!< 系统时钟频率（内核时钟） */
#elif defined SYSCLK_FREQ_36MHz
  uint32_t SystemCoreClock         = SYSCLK_FREQ_36MHz;        /*!< 系统时钟频率（内核时钟） */
#elif defined SYSCLK_FREQ_48MHz
  uint32_t SystemCoreClock         = SYSCLK_FREQ_48MHz;        /*!< 系统时钟频率（内核时钟） */
#elif defined SYSCLK_FREQ_56MHz
  uint32_t SystemCoreClock         = SYSCLK_FREQ_56MHz;        /*!< 系统时钟频率（内核时钟） */
#elif defined SYSCLK_FREQ_72MHz
  uint32_t SystemCoreClock         = SYSCLK_FREQ_72MHz;        /*!< 系统时钟频率（内核时钟） */
#else /*!< 选择 HSI 作为系统时钟源 */
  uint32_t SystemCoreClock         = HSI_VALUE;        /*!< 系统时钟频率（内核时钟） */
#endif

__I uint8_t AHBPrescTable[16] = {0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 6, 7, 8, 9};
/**
  * @}
  */

/** @addtogroup STM32F10x_System_Private_FunctionPrototypes
  * @{
  */

static void SetSysClock(void);

#ifdef SYSCLK_FREQ_HSE
  static void SetSysClockToHSE(void);
#elif defined SYSCLK_FREQ_24MHz
  static void SetSysClockTo24(void);
#elif defined SYSCLK_FREQ_36MHz
  static void SetSysClockTo36(void);
#elif defined SYSCLK_FREQ_48MHz
  static void SetSysClockTo48(void);
#elif defined SYSCLK_FREQ_56MHz
  static void SetSysClockTo56(void);  
#elif defined SYSCLK_FREQ_72MHz
  static void SetSysClockTo72(void);
#endif

#ifdef DATA_IN_ExtSRAM
  static void SystemInit_ExtMemCtl(void); 
#endif /* DATA_IN_ExtSRAM */

/**
  * @}
  */

/** @addtogroup STM32F10x_System_Private_Functions
  * @{
  */

/**
  * @brief 初始化微控制器系统
  *         初始化嵌入式闪存接口、PLL，并更新 
  *         SystemCoreClock 变量。
  * @note 该函数只应在复位之后使用。
  * @param 无
  * @retval 无
  */
void SystemInit (void)
{
  /* 将 RCC 时钟配置复位为默认的复位状态（用于调试目的） */
  /* 置位 HSION 位 */
  RCC->CR |= (uint32_t)0x00000001;

  /* 复位 SW、HPRE、PPRE1、PPRE2、ADCPRE 和 MCO 位 */
#ifndef STM32F10X_CL
  RCC->CFGR &= (uint32_t)0xF8FF0000;
#else
  RCC->CFGR &= (uint32_t)0xF0FF0000;
#endif /* STM32F10X_CL */   
  
  /* 复位 HSEON、CSSON 和 PLLON 位 */
  RCC->CR &= (uint32_t)0xFEF6FFFF;

  /* 复位 HSEBYP 位 */
  RCC->CR &= (uint32_t)0xFFFBFFFF;

  /* 复位 PLLSRC、PLLXTPRE、PLLMUL 和 USBPRE/OTGFSPRE 位 */
  RCC->CFGR &= (uint32_t)0xFF80FFFF;

#ifdef STM32F10X_CL
  /* 复位 PLL2ON 和 PLL3ON 位 */
  RCC->CR &= (uint32_t)0xEBFFFFFF;

  /* 失能所有中断并清除挂起位  */
  RCC->CIR = 0x00FF0000;

  /* 复位 CFGR2 寄存器 */
  RCC->CFGR2 = 0x00000000;
#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || (defined STM32F10X_HD_VL)
  /* 失能所有中断并清除挂起位  */
  RCC->CIR = 0x009F0000;

  /* 复位 CFGR2 寄存器 */
  RCC->CFGR2 = 0x00000000;      
#else
  /* 失能所有中断并清除挂起位  */
  RCC->CIR = 0x009F0000;
#endif /* STM32F10X_CL */
    
#if defined (STM32F10X_HD) || (defined STM32F10X_XL) || (defined STM32F10X_HD_VL)
  #ifdef DATA_IN_ExtSRAM
    SystemInit_ExtMemCtl(); 
  #endif /* DATA_IN_ExtSRAM */
#endif 

  /* 配置系统时钟频率、HCLK、PCLK2 和 PCLK1 分频系数 */
  /* 配置闪存延迟周期并使能预取缓冲区 */
  SetSysClock();

#ifdef VECT_TAB_SRAM
  SCB->VTOR = SRAM_BASE | VECT_TAB_OFFSET; /* 将向量表重定位到内部 SRAM。 */
#else
  SCB->VTOR = FLASH_BASE | VECT_TAB_OFFSET; /* 将向量表重定位到内部闪存。 */
#endif 
}

/**
  * @brief 根据时钟寄存器值更新 SystemCoreClock 变量。
  *         SystemCoreClock 变量保存内核时钟（HCLK），
  *         用户应用程序可用它来设置 SysTick 定时器或配置
  *         其他参数。
  *           
  * @note 每当内核时钟（HCLK）变化时，都必须调用该函数
  *         来更新 SystemCoreClock 变量的值。否则，任何基于该
  *         变量的配置都将是错误的。         
  *     
  * @note - 该函数计算出的系统频率并非芯片的 
  *           真实频率。它是根据预定义常量 
  *           和所选的时钟源计算得出的：
  *             
  *           - 如果 SYSCLK 源为 HSI，SystemCoreClock 将包含 HSI_VALUE(*)
  *                                              
  *           - 如果 SYSCLK 源为 HSE，SystemCoreClock 将包含 HSE_VALUE(**)
  *                          
  *           - 如果 SYSCLK 源为 PLL，SystemCoreClock 将包含 HSE_VALUE(**) 
  *             或 HSI_VALUE(*) 乘以 PLL 系数。
  *         
  *         (*) HSI_VALUE 是 stm32f1xx.h 文件中定义的常量（默认值
  *             8 MHz），但实际值可能会因电压和温度的
  *             变化而变化。   
  *    
  *         (**) HSE_VALUE 是 stm32f1xx.h 文件中定义的常量（默认值
  *              8 MHz 或 25 MHz，取决于所使用的产品），用户必须确保
  *              HSE_VALUE 与实际使用的晶振频率一致。
  *              否则，该函数可能得到错误的结果。
  *                
  *         - 当 HSE 晶振使用小数
  *           值时，该函数的结果可能不正确。
  * @param 无
  * @retval 无
  */
void SystemCoreClockUpdate (void)
{
  uint32_t tmp = 0, pllmull = 0, pllsource = 0;

#ifdef  STM32F10X_CL
  uint32_t prediv1source = 0, prediv1factor = 0, prediv2factor = 0, pll2mull = 0;
#endif /* STM32F10X_CL */

#if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || (defined STM32F10X_HD_VL)
  uint32_t prediv1factor = 0;
#endif /* STM32F10X_LD_VL or STM32F10X_MD_VL or STM32F10X_HD_VL */
    
  /* 获取 SYSCLK 源 -------------------------------------------------------*/
  tmp = RCC->CFGR & RCC_CFGR_SWS;
  
  switch (tmp)
  {
    case 0x00:  /* 使用 HSI 作为系统时钟 */
      SystemCoreClock = HSI_VALUE;
      break;
    case 0x04:  /* 使用 HSE 作为系统时钟 */
      SystemCoreClock = HSE_VALUE;
      break;
    case 0x08:  /* 使用 PLL 作为系统时钟 */

      /* 获取 PLL 时钟源和倍频系数 ----------------------------------------*/
      pllmull = RCC->CFGR & RCC_CFGR_PLLMULL;
      pllsource = RCC->CFGR & RCC_CFGR_PLLSRC;
      
#ifndef STM32F10X_CL      
      pllmull = ( pllmull >> 18) + 2;
      
      if (pllsource == 0x00)
      {
        /* 选择 HSI 振荡器时钟 2 分频作为 PLL 输入时钟 */
        SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
      }
      else
      {
 #if defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || (defined STM32F10X_HD_VL)
       prediv1factor = (RCC->CFGR2 & RCC_CFGR2_PREDIV1) + 1;
       /* 选择 HSE 振荡器时钟作为 PREDIV1 输入时钟 */
       SystemCoreClock = (HSE_VALUE / prediv1factor) * pllmull; 
 #else
        /* 选择 HSE 作为 PLL 输入时钟 */
        if ((RCC->CFGR & RCC_CFGR_PLLXTPRE) != (uint32_t)RESET)
        {/* HSE 振荡器时钟 2 分频 */
          SystemCoreClock = (HSE_VALUE >> 1) * pllmull;
        }
        else
        {
          SystemCoreClock = HSE_VALUE * pllmull;
        }
 #endif
      }
#else
      pllmull = pllmull >> 18;
      
      if (pllmull != 0x0D)
      {
         pllmull += 2;
      }
      else
      { /* PLL 倍频系数 = PLL 输入时钟 * 6.5 */
        pllmull = 13 / 2; 
      }
            
      if (pllsource == 0x00)
      {
        /* 选择 HSI 振荡器时钟 2 分频作为 PLL 输入时钟 */
        SystemCoreClock = (HSI_VALUE >> 1) * pllmull;
      }
      else
      {/* 选择 PREDIV1 作为 PLL 输入时钟 */
        
        /* 获取 PREDIV1 时钟源和分频系数 */
        prediv1source = RCC->CFGR2 & RCC_CFGR2_PREDIV1SRC;
        prediv1factor = (RCC->CFGR2 & RCC_CFGR2_PREDIV1) + 1;
        
        if (prediv1source == 0)
        { 
          /* 选择 HSE 振荡器时钟作为 PREDIV1 输入时钟 */
          SystemCoreClock = (HSE_VALUE / prediv1factor) * pllmull;          
        }
        else
        {/* 选择 PLL2 时钟作为 PREDIV1 输入时钟 */
          
          /* 获取 PREDIV2 分频系数和 PLL2 倍频系数 */
          prediv2factor = ((RCC->CFGR2 & RCC_CFGR2_PREDIV2) >> 4) + 1;
          pll2mull = ((RCC->CFGR2 & RCC_CFGR2_PLL2MUL) >> 8 ) + 2; 
          SystemCoreClock = (((HSE_VALUE / prediv2factor) * pll2mull) / prediv1factor) * pllmull;                         
        }
      }
#endif /* STM32F10X_CL */ 
      break;

    default:
      SystemCoreClock = HSI_VALUE;
      break;
  }
  
  /* 计算 HCLK 时钟频率 ----------------*/
  /* 获取 HCLK 分频系数 */
  tmp = AHBPrescTable[((RCC->CFGR & RCC_CFGR_HPRE) >> 4)];
  /* HCLK 时钟频率 */
  SystemCoreClock >>= tmp;  
}

/**
  * @brief 配置系统时钟频率、HCLK、PCLK2 和 PCLK1 分频系数。
  * @param 无
  * @retval 无
  */
static void SetSysClock(void)
{
#ifdef SYSCLK_FREQ_HSE
  SetSysClockToHSE();
#elif defined SYSCLK_FREQ_24MHz
  SetSysClockTo24();
#elif defined SYSCLK_FREQ_36MHz
  SetSysClockTo36();
#elif defined SYSCLK_FREQ_48MHz
  SetSysClockTo48();
#elif defined SYSCLK_FREQ_56MHz
  SetSysClockTo56();  
#elif defined SYSCLK_FREQ_72MHz
  SetSysClockTo72();
#endif
 
 /* 如果上面没有任何一个宏定义被使能，则使用 HSI 作为系统时钟
    源（复位后的默认值） */ 
}

/**
  * @brief 初始化外部存储器控制器。在 startup_stm32f10x.s 中调用， 
  *          位于跳转到 __main 之前
  * @param 无
  * @retval 无
  */ 
#ifdef DATA_IN_ExtSRAM
/**
  * @brief 初始化外部存储器控制器。 
  *         在 startup_stm32f10x_xx.s/.c 中调用，位于跳转到 main 之前。
  * 	      该函数配置安装在 STM3210E-EVAL 板（STM32 高密度器件）上的
  *         外部 SRAM。该 SRAM 将用作程序
  *         数据存储器（包括堆和栈）。
  * @param 无
  * @retval 无
  */ 
void SystemInit_ExtMemCtl(void) 
{
/*!< STM3210E-EVAL 使用 FSMC Bank1 NOR/SRAM3，如果需要其他 Bank， 
  则需调整寄存器地址 */

  /* 使能 FSMC 时钟 */
  RCC->AHBENR = 0x00000114;
  
  /* 使能 GPIOD、GPIOE、GPIOF 和 GPIOG 时钟 */  
  RCC->APB2ENR = 0x000001E0;
  
/* --------------- SRAM 数据线、NOE 和 NWE 配置 ---------------*/
/*---------------- SRAM 地址线配置 -------------------------*/
/*---------------- NOE 和 NWE 配置 --------------------------------*/  
/*---------------- NE3 配置 ----------------------------------------*/
/*---------------- NBL0、NBL1 配置 ---------------------------------*/
  
  GPIOD->CRL = 0x44BB44BB;  
  GPIOD->CRH = 0xBBBBBBBB;

  GPIOE->CRL = 0xB44444BB;  
  GPIOE->CRH = 0xBBBBBBBB;

  GPIOF->CRL = 0x44BBBBBB;  
  GPIOF->CRH = 0xBBBB4444;

  GPIOG->CRL = 0x44BBBBBB;  
  GPIOG->CRH = 0x44444B44;
   
/*---------------- FSMC 配置 ---------------------------------------*/  
/*---------------- 使能 FSMC Bank1_SRAM Bank ------------------------------*/
  
  FSMC_Bank1->BTCR[4] = 0x00001011;
  FSMC_Bank1->BTCR[5] = 0x00000200;
}
#endif /* DATA_IN_ExtSRAM */

#ifdef SYSCLK_FREQ_HSE
/**
  * @brief 选择 HSE 作为系统时钟源，并配置 HCLK、PCLK2
  *         和 PCLK1 分频系数。
  * @note 该函数只应在复位之后使用。
  * @param 无
  * @retval 无
  */
static void SetSysClockToHSE(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  
  /* SYSCLK、HCLK、PCLK2 和 PCLK1 配置 ---------------------------*/    
  /* 使能 HSE */    
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* 等待 HSE 就绪，若超时则退出 */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;  
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }  

  if (HSEStatus == (uint32_t)0x01)
  {

#if !defined STM32F10X_LD_VL && !defined STM32F10X_MD_VL && !defined STM32F10X_HD_VL
    /* 使能预取缓冲区 */
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    /* 闪存 0 等待周期 */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);

#ifndef STM32F10X_CL
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_0;
#else
    if (HSE_VALUE <= 24000000)
	{
      FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_0;
	}
	else
	{
      FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_1;
	}
#endif /* STM32F10X_CL */
#endif
 
    /* HCLK = SYSCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV1;
    
    /* 选择 HSE 作为系统时钟源 */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_HSE;    

    /* 等待 HSE 被用作系统时钟源 */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x04)
    {
    }
  }
  else
  { /* 如果 HSE 启动失败，应用程序将获得错误的时钟 
         配置。用户可以在此处添加代码来处理该错误 */
  }  
}
#elif defined SYSCLK_FREQ_24MHz
/**
  * @brief 将系统时钟频率设置为 24MHz，并配置 HCLK、PCLK2 
  *         和 PCLK1 分频系数。
  * @note 该函数只应在复位之后使用。
  * @param 无
  * @retval 无
  */
static void SetSysClockTo24(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  
  /* SYSCLK、HCLK、PCLK2 和 PCLK1 配置 ---------------------------*/    
  /* 使能 HSE */    
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* 等待 HSE 就绪，若超时则退出 */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;  
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }  

  if (HSEStatus == (uint32_t)0x01)
  {
#if !defined STM32F10X_LD_VL && !defined STM32F10X_MD_VL && !defined STM32F10X_HD_VL 
    /* 使能预取缓冲区 */
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    /* 闪存 0 等待周期 */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_0;    
#endif
 
    /* HCLK = SYSCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV1;
    
#ifdef STM32F10X_CL
    /* 配置 PLL ------------------------------------------------------*/
    /* PLL 配置：PLLCLK = PREDIV1 * 6 = 24 MHz */ 
    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
                            RCC_CFGR_PLLMULL6); 

    /* PLL2 配置：PLL2CLK = (HSE / 5) * 8 = 40 MHz */
    /* PREDIV1 配置：PREDIV1CLK = PLL2 / 10 = 4 MHz */       
    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV10);
  
    /* 使能 PLL2 */
    RCC->CR |= RCC_CR_PLL2ON;
    /* 等待 PLL2 就绪 */
    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
    {
    }   
#elif defined (STM32F10X_LD_VL) || defined (STM32F10X_MD_VL) || defined (STM32F10X_HD_VL)
    /*  PLL 配置：= (HSE / 2) * 6 = 24 MHz */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_PREDIV1 | RCC_CFGR_PLLXTPRE_PREDIV1_Div2 | RCC_CFGR_PLLMULL6);
#else    
    /*  PLL 配置：= (HSE / 2) * 6 = 24 MHz */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLXTPRE_HSE_Div2 | RCC_CFGR_PLLMULL6);
#endif /* STM32F10X_CL */

    /* 使能 PLL */
    RCC->CR |= RCC_CR_PLLON;

    /* 等待 PLL 就绪 */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }

    /* 选择 PLL 作为系统时钟源 */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

    /* 等待 PLL 被用作系统时钟源 */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
    {
    }
  }
  else
  { /* 如果 HSE 启动失败，应用程序将获得错误的时钟 
         配置。用户可以在此处添加代码来处理该错误 */
  } 
}
#elif defined SYSCLK_FREQ_36MHz
/**
  * @brief 将系统时钟频率设置为 36MHz，并配置 HCLK、PCLK2 
  *         和 PCLK1 分频系数。 
  * @note 该函数只应在复位之后使用。
  * @param 无
  * @retval 无
  */
static void SetSysClockTo36(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  
  /* SYSCLK、HCLK、PCLK2 和 PCLK1 配置 ---------------------------*/    
  /* 使能 HSE */    
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* 等待 HSE 就绪，若超时则退出 */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;  
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }  

  if (HSEStatus == (uint32_t)0x01)
  {
    /* 使能预取缓冲区 */
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    /* 闪存 1 等待周期 */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_1;    
 
    /* HCLK = SYSCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV1;
    
#ifdef STM32F10X_CL
    /* 配置 PLL ------------------------------------------------------*/
    
    /* PLL 配置：PLLCLK = PREDIV1 * 9 = 36 MHz */ 
    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
                            RCC_CFGR_PLLMULL9); 

	/*!< PLL2 配置：PLL2CLK = (HSE / 5) * 8 = 40 MHz */
    /* PREDIV1 配置：PREDIV1CLK = PLL2 / 10 = 4 MHz */
        
    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV10);
  
    /* 使能 PLL2 */
    RCC->CR |= RCC_CR_PLL2ON;
    /* 等待 PLL2 就绪 */
    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
    {
    }
    
#else    
    /*  PLL 配置：PLLCLK = (HSE / 2) * 9 = 36 MHz */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLXTPRE_HSE_Div2 | RCC_CFGR_PLLMULL9);
#endif /* STM32F10X_CL */

    /* 使能 PLL */
    RCC->CR |= RCC_CR_PLLON;

    /* 等待 PLL 就绪 */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }

    /* 选择 PLL 作为系统时钟源 */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

    /* 等待 PLL 被用作系统时钟源 */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
    {
    }
  }
  else
  { /* 如果 HSE 启动失败，应用程序将获得错误的时钟 
         配置。用户可以在此处添加代码来处理该错误 */
  } 
}
#elif defined SYSCLK_FREQ_48MHz
/**
  * @brief 将系统时钟频率设置为 48MHz，并配置 HCLK、PCLK2 
  *         和 PCLK1 分频系数。 
  * @note 该函数只应在复位之后使用。
  * @param 无
  * @retval 无
  */
static void SetSysClockTo48(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  
  /* SYSCLK、HCLK、PCLK2 和 PCLK1 配置 ---------------------------*/    
  /* 使能 HSE */    
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* 等待 HSE 就绪，若超时则退出 */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;  
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }  

  if (HSEStatus == (uint32_t)0x01)
  {
    /* 使能预取缓冲区 */
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    /* 闪存 1 等待周期 */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_1;    
 
    /* HCLK = SYSCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;
    
#ifdef STM32F10X_CL
    /* 配置 PLL ------------------------------------------------------*/
    /* PLL2 配置：PLL2CLK = (HSE / 5) * 8 = 40 MHz */
    /* PREDIV1 配置：PREDIV1CLK = PLL2 / 5 = 8 MHz */
        
    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV5);
  
    /* 使能 PLL2 */
    RCC->CR |= RCC_CR_PLL2ON;
    /* 等待 PLL2 就绪 */
    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
    {
    }
    
   
    /* PLL 配置：PLLCLK = PREDIV1 * 6 = 48 MHz */ 
    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
                            RCC_CFGR_PLLMULL6); 
#else    
    /*  PLL 配置：PLLCLK = HSE * 6 = 48 MHz */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL6);
#endif /* STM32F10X_CL */

    /* 使能 PLL */
    RCC->CR |= RCC_CR_PLLON;

    /* 等待 PLL 就绪 */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }

    /* 选择 PLL 作为系统时钟源 */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

    /* 等待 PLL 被用作系统时钟源 */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
    {
    }
  }
  else
  { /* 如果 HSE 启动失败，应用程序将获得错误的时钟 
         配置。用户可以在此处添加代码来处理该错误 */
  } 
}

#elif defined SYSCLK_FREQ_56MHz
/**
  * @brief 将系统时钟频率设置为 56MHz，并配置 HCLK、PCLK2 
  *         和 PCLK1 分频系数。 
  * @note 该函数只应在复位之后使用。
  * @param 无
  * @retval 无
  */
static void SetSysClockTo56(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  
  /* SYSCLK、HCLK、PCLK2 和 PCLK1 配置 ---------------------------*/   
  /* 使能 HSE */    
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* 等待 HSE 就绪，若超时则退出 */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;  
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }  

  if (HSEStatus == (uint32_t)0x01)
  {
    /* 使能预取缓冲区 */
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    /* 闪存 2 等待周期 */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    
 
    /* HCLK = SYSCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;

#ifdef STM32F10X_CL
    /* 配置 PLL ------------------------------------------------------*/
    /* PLL2 配置：PLL2CLK = (HSE / 5) * 8 = 40 MHz */
    /* PREDIV1 配置：PREDIV1CLK = PLL2 / 5 = 8 MHz */
        
    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV5);
  
    /* 使能 PLL2 */
    RCC->CR |= RCC_CR_PLL2ON;
    /* 等待 PLL2 就绪 */
    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
    {
    }
    
   
    /* PLL 配置：PLLCLK = PREDIV1 * 7 = 56 MHz */ 
    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
                            RCC_CFGR_PLLMULL7); 
#else     
    /* PLL 配置：PLLCLK = HSE * 7 = 56 MHz */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL7);

#endif /* STM32F10X_CL */

    /* 使能 PLL */
    RCC->CR |= RCC_CR_PLLON;

    /* 等待 PLL 就绪 */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }

    /* 选择 PLL 作为系统时钟源 */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

    /* 等待 PLL 被用作系统时钟源 */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
    {
    }
  }
  else
  { /* 如果 HSE 启动失败，应用程序将获得错误的时钟 
         配置。用户可以在此处添加代码来处理该错误 */
  } 
}

#elif defined SYSCLK_FREQ_72MHz
/**
  * @brief 将系统时钟频率设置为 72MHz，并配置 HCLK、PCLK2 
  *         和 PCLK1 分频系数。 
  * @note 该函数只应在复位之后使用。
  * @param 无
  * @retval 无
  */
static void SetSysClockTo72(void)
{
  __IO uint32_t StartUpCounter = 0, HSEStatus = 0;
  
  /* SYSCLK、HCLK、PCLK2 和 PCLK1 配置 ---------------------------*/    
  /* 使能 HSE */    
  RCC->CR |= ((uint32_t)RCC_CR_HSEON);
 
  /* 等待 HSE 就绪，若超时则退出 */
  do
  {
    HSEStatus = RCC->CR & RCC_CR_HSERDY;
    StartUpCounter++;  
  } while((HSEStatus == 0) && (StartUpCounter != HSE_STARTUP_TIMEOUT));

  if ((RCC->CR & RCC_CR_HSERDY) != RESET)
  {
    HSEStatus = (uint32_t)0x01;
  }
  else
  {
    HSEStatus = (uint32_t)0x00;
  }  

  if (HSEStatus == (uint32_t)0x01)
  {
    /* 使能预取缓冲区 */
    FLASH->ACR |= FLASH_ACR_PRFTBE;

    /* 闪存 2 等待周期 */
    FLASH->ACR &= (uint32_t)((uint32_t)~FLASH_ACR_LATENCY);
    FLASH->ACR |= (uint32_t)FLASH_ACR_LATENCY_2;    

 
    /* HCLK = SYSCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
    /* PCLK2 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE2_DIV1;
    
    /* PCLK1 = HCLK */
    RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE1_DIV2;

#ifdef STM32F10X_CL
    /* 配置 PLL ------------------------------------------------------*/
    /* PLL2 配置：PLL2CLK = (HSE / 5) * 8 = 40 MHz */
    /* PREDIV1 配置：PREDIV1CLK = PLL2 / 5 = 8 MHz */
        
    RCC->CFGR2 &= (uint32_t)~(RCC_CFGR2_PREDIV2 | RCC_CFGR2_PLL2MUL |
                              RCC_CFGR2_PREDIV1 | RCC_CFGR2_PREDIV1SRC);
    RCC->CFGR2 |= (uint32_t)(RCC_CFGR2_PREDIV2_DIV5 | RCC_CFGR2_PLL2MUL8 |
                             RCC_CFGR2_PREDIV1SRC_PLL2 | RCC_CFGR2_PREDIV1_DIV5);
  
    /* 使能 PLL2 */
    RCC->CR |= RCC_CR_PLL2ON;
    /* 等待 PLL2 就绪 */
    while((RCC->CR & RCC_CR_PLL2RDY) == 0)
    {
    }
    
   
    /* PLL 配置：PLLCLK = PREDIV1 * 9 = 72 MHz */ 
    RCC->CFGR &= (uint32_t)~(RCC_CFGR_PLLXTPRE | RCC_CFGR_PLLSRC | RCC_CFGR_PLLMULL);
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLXTPRE_PREDIV1 | RCC_CFGR_PLLSRC_PREDIV1 | 
                            RCC_CFGR_PLLMULL9); 
#else    
    /*  PLL 配置：PLLCLK = HSE * 9 = 72 MHz */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLXTPRE |
                                        RCC_CFGR_PLLMULL));
    RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSE | RCC_CFGR_PLLMULL9);
#endif /* STM32F10X_CL */

    /* 使能 PLL */
    RCC->CR |= RCC_CR_PLLON;

    /* 等待 PLL 就绪 */
    while((RCC->CR & RCC_CR_PLLRDY) == 0)
    {
    }
    
    /* 选择 PLL 作为系统时钟源 */
    RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
    RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

    /* 等待 PLL 被用作系统时钟源 */
    while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)0x08)
    {
    }
  }
  else
  { /* 如果 HSE 启动失败，应用程序将获得错误的时钟 
         配置。用户可以在此处添加代码来处理该错误 */
  }
}
#endif

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
