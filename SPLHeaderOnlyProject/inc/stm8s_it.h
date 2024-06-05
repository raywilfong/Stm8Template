/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8S_IT_H
#define __STM8S_IT_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */

INTERRUPT_HANDLER_TRAP(TRAP_IRQHandler);                 /* TRAP */

INTERRUPT_HANDLER(TLI_IRQHandler, 0);                    /* TLI */

INTERRUPT_HANDLER(AWU_IRQHandler, 1);                    /* AWU */

INTERRUPT_HANDLER(CLK_IRQHandler, 2);                    /* CLOCK */

INTERRUPT_HANDLER(EXTI_PORTA_IRQHandler, 3);             /* EXTI PORTA */
INTERRUPT_HANDLER(EXTI_PORTB_IRQHandler, 4);             /* EXTI PORTB */
INTERRUPT_HANDLER(EXTI_PORTC_IRQHandler, 5);             /* EXTI PORTC */
INTERRUPT_HANDLER(EXTI_PORTD_IRQHandler, 6);             /* EXTI PORTD */
INTERRUPT_HANDLER(EXTI_PORTE_IRQHandler, 7);             /* EXTI PORTE */

// interrupt 8 and 9 are reserved on stm8s103

INTERRUPT_HANDLER(SPI_IRQHandler, 10);                   /* SPI */

INTERRUPT_HANDLER(TIM1_UPD_OVF_TRG_BRK_IRQHandler, 11);  /* TIM1 UPD/OVF/TRG/BRK */
INTERRUPT_HANDLER(TIM1_CAP_COM_IRQHandler, 12);          /* TIM1 CAP/COM */

INTERRUPT_HANDLER(TIM2_UPD_OVF_BRK_IRQHandler, 13);      /* TIM2 UPD/OVF/BRK */
INTERRUPT_HANDLER(TIM2_CAP_COM_IRQHandler, 14);          /* TIM2 CAP/COM */

// interrupt 15 and 16 are reserved on stm8s103

INTERRUPT_HANDLER(UART1_TX_IRQHandler, 17);              /* UART1 TX */
INTERRUPT_HANDLER(UART1_RX_IRQHandler, 18);              /* UART1 RX */

INTERRUPT_HANDLER(I2C_IRQHandler, 19);                   /* I2C */

// interrupt 20 and 21 are reserved on stm8s103

INTERRUPT_HANDLER(ADC1_IRQHandler, 22);                  /* ADC1 */

INTERRUPT_HANDLER(TIM4_UPD_OVF_IRQHandler, 23);          /* TIM4 UPD/OVF */

INTERRUPT_HANDLER(EEPROM_EEC_IRQHandler, 24);            /* EEPROM ECC CORRECTION */

#endif /* __STM8S_IT_H */
