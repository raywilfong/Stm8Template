#include "stm8s.h"
#include "stm8s_it.h"    /* SDCC patch: required by SDCC for interrupts */

#define LED_GPIO_PORT  (GPIOB)
#define LED_GPIO_PINS  (GPIO_PIN_5)	

void Delay (uint16_t nCount);

void main(void)
{
  const int flashCount = 2; // how many flashes before pause?

  /* Initialize I/Os in Output Mode */
  GPIO_Init(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS, GPIO_MODE_OUT_PP_LOW_FAST);


  while (1)
  {
    /* Toggles LEDs */
    for (int i = 0; i < 2 * flashCount; ++i) {
      GPIO_WriteReverse(LED_GPIO_PORT, (GPIO_Pin_TypeDef)LED_GPIO_PINS);
      Delay(0xFFFF);
    }
    Delay(0xFFFF);
    Delay(0xFFFF);
  }

}

void Delay(uint16_t nCount)
{
  /* Decrement nCount value */
  while (nCount != 0)
  {
    nCount--;
  }
}



/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
