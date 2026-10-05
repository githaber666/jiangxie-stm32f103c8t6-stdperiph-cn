;******************** (C) COPYRIGHT 2011 STMicroelectronics ********************
;* File Name          : startup_stm32f10x_ld_vl.s
;* Author             : MCD Application Team
;* Version            : V3.5.0
;* Date               : 11-March-2011
;* Description        : STM32F10x 小容量值系列（Low Density Value Line）器件中断向量表  
;*                      用于 MDK-ARM 工具链。  
;*                      本模块完成以下工作：
;*                      - 设置初始 SP（堆栈指针）
;*                      - 设置初始 PC == Reset_Handler（复位处理程序）
;*                      - 用各异常的中断服务程序（ISR）地址填充向量表表项
;*                      - 配置时钟系统
;*                      - 跳转到 C 库的 __main（它最终会
;*                        调用 main()）。
;*                      复位后 Cortex-M3 处理器处于线程（Thread）模式，
;*                      优先级为特权（Privileged）级，堆栈设置为主堆栈（Main）。
;* <<< 可使用右键菜单中的配置向导（Configuration Wizard） >>>   
;*******************************************************************************
; THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
; WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE TIME.
; AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY DIRECT,
; INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING FROM THE
; CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE CODING
; INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
;*******************************************************************************

; 分配给栈（Stack）的内存大小（单位：字节）
; 请根据应用程序的实际需要修改该值
; <h> 栈（Stack）配置
;   <o> 栈大小（字节）<0x0-0xFFFFFFFF:8>
; </h>

Stack_Size      EQU     0x00000400

                AREA    STACK, NOINIT, READWRITE, ALIGN=3
Stack_Mem       SPACE   Stack_Size
__initial_sp


; <h> 堆（Heap）配置
;   <o> 堆大小（字节）<0x0-0xFFFFFFFF:8>
; </h>

Heap_Size       EQU     0x00000200

                AREA    HEAP, NOINIT, READWRITE, ALIGN=3
__heap_base
Heap_Mem        SPACE   Heap_Size
__heap_limit

                PRESERVE8
                THUMB


; 复位时映射到地址 0 的向量表
                AREA    RESET, DATA, READONLY
                EXPORT  __Vectors
                EXPORT  __Vectors_End
                EXPORT  __Vectors_Size

__Vectors       DCD     __initial_sp                    ; 栈顶
                DCD     Reset_Handler                   ; 复位处理程序
                DCD     NMI_Handler                     ; NMI（不可屏蔽中断）处理程序
                DCD     HardFault_Handler               ; 硬件错误（Hard Fault）处理程序
                DCD     MemManage_Handler               ; MPU 错误（MemManage）处理程序
                DCD     BusFault_Handler                ; 总线错误（Bus Fault）处理程序
                DCD     UsageFault_Handler              ; 用法错误（Usage Fault）处理程序
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     SVC_Handler                     ; SVC（系统服务调用）处理程序
                DCD     DebugMon_Handler                ; 调试监视器（Debug Monitor）处理程序
                DCD     0                               ; 保留
                DCD     PendSV_Handler                  ; PendSV（可挂起系统服务）处理程序
                DCD     SysTick_Handler                 ; SysTick（系统滴答定时器）处理程序

                ; 外部中断
                DCD     WWDG_IRQHandler                 ; 窗口看门狗（WWDG）
                DCD     PVD_IRQHandler                  ; PVD（可编程电压监测器）经 EXTI 线检测
                DCD     TAMPER_IRQHandler               ; 侵入检测（TAMPER）
                DCD     RTC_IRQHandler                  ; RTC
                DCD     FLASH_IRQHandler                ; 闪存（FLASH）
                DCD     RCC_IRQHandler                  ; RCC
                DCD     EXTI0_IRQHandler                ; EXTI 线 0
                DCD     EXTI1_IRQHandler                ; EXTI 线 1
                DCD     EXTI2_IRQHandler                ; EXTI 线 2
                DCD     EXTI3_IRQHandler                ; EXTI 线 3
                DCD     EXTI4_IRQHandler                ; EXTI 线 4
                DCD     DMA1_Channel1_IRQHandler        ; DMA1 通道 1
                DCD     DMA1_Channel2_IRQHandler        ; DMA1 通道 2
                DCD     DMA1_Channel3_IRQHandler        ; DMA1 通道 3
                DCD     DMA1_Channel4_IRQHandler        ; DMA1 通道 4
                DCD     DMA1_Channel5_IRQHandler        ; DMA1 通道 5
                DCD     DMA1_Channel6_IRQHandler        ; DMA1 通道 6
                DCD     DMA1_Channel7_IRQHandler        ; DMA1 通道 7
                DCD     ADC1_IRQHandler                 ; ADC1
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     EXTI9_5_IRQHandler              ; EXTI 线 9..5
                DCD     TIM1_BRK_TIM15_IRQHandler       ; TIM1 Break and TIM15
                DCD     TIM1_UP_TIM16_IRQHandler        ; TIM1 Update and TIM16
                DCD     TIM1_TRG_COM_TIM17_IRQHandler   ; TIM1 Trigger and Commutation and TIM17
                DCD     TIM1_CC_IRQHandler              ; TIM1 输入捕获/输出比较
                DCD     TIM2_IRQHandler                 ; TIM2
                DCD     TIM3_IRQHandler                 ; TIM3
                DCD     0                               ; 保留
                DCD     I2C1_EV_IRQHandler              ; I2C1 事件
                DCD     I2C1_ER_IRQHandler              ; I2C1 错误
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     SPI1_IRQHandler                 ; SPI1
                DCD     0                               ; 保留
                DCD     USART1_IRQHandler               ; USART1
                DCD     USART2_IRQHandler               ; USART2
                DCD     0                               ; 保留
                DCD     EXTI15_10_IRQHandler            ; EXTI 线 15..10
                DCD     RTCAlarm_IRQHandler             ; RTC 闹钟经 EXTI 线
                DCD     CEC_IRQHandler                  ; HDMI-CEC
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     0                               ; 保留
                DCD     TIM6_DAC_IRQHandler             ; TIM6 and DAC underrun
                DCD     TIM7_IRQHandler                 ; TIM7
__Vectors_End

__Vectors_Size  EQU  __Vectors_End - __Vectors

                AREA    |.text|, CODE, READONLY

; 复位处理程序
Reset_Handler    PROC
                 EXPORT  Reset_Handler             [WEAK]
     IMPORT  __main
     IMPORT  SystemInit
                 LDR     R0, =SystemInit
                 BLX     R0
                 LDR     R0, =__main
                 BX      R0
                 ENDP

; 空的异常处理程序（死循环，可由用户自行修改）

NMI_Handler     PROC
                EXPORT  NMI_Handler                      [WEAK]
                B       .
                ENDP
HardFault_Handler\
                PROC
                EXPORT  HardFault_Handler                [WEAK]
                B       .
                ENDP
MemManage_Handler\
                PROC
                EXPORT  MemManage_Handler                [WEAK]
                B       .
                ENDP
BusFault_Handler\
                PROC
                EXPORT  BusFault_Handler                 [WEAK]
                B       .
                ENDP
UsageFault_Handler\
                PROC
                EXPORT  UsageFault_Handler               [WEAK]
                B       .
                ENDP
SVC_Handler     PROC
                EXPORT  SVC_Handler                      [WEAK]
                B       .
                ENDP
DebugMon_Handler\
                PROC
                EXPORT  DebugMon_Handler                 [WEAK]
                B       .
                ENDP
PendSV_Handler  PROC
                EXPORT  PendSV_Handler                   [WEAK]
                B       .
                ENDP
SysTick_Handler PROC
                EXPORT  SysTick_Handler                  [WEAK]
                B       .
                ENDP

Default_Handler PROC

                EXPORT  WWDG_IRQHandler                  [WEAK]
                EXPORT  PVD_IRQHandler                   [WEAK]
                EXPORT  TAMPER_IRQHandler                [WEAK]
                EXPORT  RTC_IRQHandler                   [WEAK]
                EXPORT  FLASH_IRQHandler                 [WEAK]
                EXPORT  RCC_IRQHandler                   [WEAK]
                EXPORT  EXTI0_IRQHandler                 [WEAK]
                EXPORT  EXTI1_IRQHandler                 [WEAK]
                EXPORT  EXTI2_IRQHandler                 [WEAK]
                EXPORT  EXTI3_IRQHandler                 [WEAK]
                EXPORT  EXTI4_IRQHandler                 [WEAK]
                EXPORT  DMA1_Channel1_IRQHandler         [WEAK]
                EXPORT  DMA1_Channel2_IRQHandler         [WEAK]
                EXPORT  DMA1_Channel3_IRQHandler         [WEAK]
                EXPORT  DMA1_Channel4_IRQHandler         [WEAK]
                EXPORT  DMA1_Channel5_IRQHandler         [WEAK]
                EXPORT  DMA1_Channel6_IRQHandler         [WEAK]
                EXPORT  DMA1_Channel7_IRQHandler         [WEAK]
                EXPORT  ADC1_IRQHandler                  [WEAK]
                EXPORT  EXTI9_5_IRQHandler               [WEAK]
                EXPORT  TIM1_BRK_TIM15_IRQHandler        [WEAK]
                EXPORT  TIM1_UP_TIM16_IRQHandler         [WEAK]
                EXPORT  TIM1_TRG_COM_TIM17_IRQHandler    [WEAK]
                EXPORT  TIM1_CC_IRQHandler               [WEAK]
                EXPORT  TIM2_IRQHandler                  [WEAK]
                EXPORT  TIM3_IRQHandler                  [WEAK]
                EXPORT  I2C1_EV_IRQHandler               [WEAK]
                EXPORT  I2C1_ER_IRQHandler               [WEAK]
                EXPORT  SPI1_IRQHandler                  [WEAK]
                EXPORT  USART1_IRQHandler                [WEAK]
                EXPORT  USART2_IRQHandler                [WEAK]
                EXPORT  EXTI15_10_IRQHandler             [WEAK]
                EXPORT  RTCAlarm_IRQHandler              [WEAK]
                EXPORT  CEC_IRQHandler                   [WEAK]
                EXPORT  TIM6_DAC_IRQHandler              [WEAK]
                EXPORT  TIM7_IRQHandler                  [WEAK]
WWDG_IRQHandler
PVD_IRQHandler
TAMPER_IRQHandler
RTC_IRQHandler
FLASH_IRQHandler
RCC_IRQHandler
EXTI0_IRQHandler
EXTI1_IRQHandler
EXTI2_IRQHandler
EXTI3_IRQHandler
EXTI4_IRQHandler
DMA1_Channel1_IRQHandler
DMA1_Channel2_IRQHandler
DMA1_Channel3_IRQHandler
DMA1_Channel4_IRQHandler
DMA1_Channel5_IRQHandler
DMA1_Channel6_IRQHandler
DMA1_Channel7_IRQHandler
ADC1_IRQHandler
EXTI9_5_IRQHandler
TIM1_BRK_TIM15_IRQHandler
TIM1_UP_TIM16_IRQHandler
TIM1_TRG_COM_TIM17_IRQHandler
TIM1_CC_IRQHandler
TIM2_IRQHandler
TIM3_IRQHandler
I2C1_EV_IRQHandler
I2C1_ER_IRQHandler
SPI1_IRQHandler
USART1_IRQHandler
USART2_IRQHandler
EXTI15_10_IRQHandler
RTCAlarm_IRQHandler
CEC_IRQHandler
TIM6_DAC_IRQHandler
TIM7_IRQHandler
                B       .

                ENDP

                ALIGN

;*******************************************************************************
; 用户栈与堆的初始化
;*******************************************************************************
                 IF      :DEF:__MICROLIB           
                
                 EXPORT  __initial_sp
                 EXPORT  __heap_base
                 EXPORT  __heap_limit
                
                 ELSE
                
                 IMPORT  __use_two_region_memory
                 EXPORT  __user_initial_stackheap
                 
__user_initial_stackheap

                 LDR     R0, =  Heap_Mem
                 LDR     R1, =(Stack_Mem + Stack_Size)
                 LDR     R2, = (Heap_Mem +  Heap_Size)
                 LDR     R3, = Stack_Mem
                 BX      LR

                 ALIGN

                 ENDIF

                 END

;******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE*****
