#include "stm8s.h"
#include "stm8s_it.h"    /* SDCC patch: required by SDCC for interrupts */

#define LED_GPIO_PORT  (GPIOB)
#define LED_GPIO_PINS  (GPIO_PIN_5)

void Delay(uint16_t nCount);

void set_hsi_divider(uint8_t prescaler);

void toggle_leds(const int flashCount);

void main(void) {
    const int flashCount = 3; // how many flashes before pause?

    /* Initialize I/Os in Output Mode */
    LED_GPIO_PORT->ODR &= (uint8_t) (~(LED_GPIO_PINS));
    LED_GPIO_PORT->DDR |= (uint8_t) LED_GPIO_PINS;

    uint8_t prescaler;
    while (1) {
        prescaler = CLK_PRESCALER_HSIDIV8;
        set_hsi_divider(prescaler);
        toggle_leds(flashCount * 1);

        prescaler = CLK_PRESCALER_HSIDIV4;
        set_hsi_divider(prescaler);
        toggle_leds(flashCount * 2);

        prescaler = CLK_PRESCALER_HSIDIV2;
        set_hsi_divider(prescaler);
        toggle_leds(flashCount * 4);

        prescaler = CLK_PRESCALER_HSIDIV1;
        set_hsi_divider(prescaler);
        toggle_leds(flashCount * 8);
    }
}

void Delay(uint16_t nCount) {
    /* Decrement nCount value */
    while (nCount != 0) {
        nCount--;
    }
}

void set_hsi_divider(uint8_t prescaler) {
    CLK->CKDIVR = (uint8_t) ((CLK->CKDIVR & (uint8_t) (~CLK_CKDIVR_HSIDIV) | (
                                  (uint8_t) prescaler & (uint8_t) CLK_CKDIVR_HSIDIV)));
}

void toggle_leds(const int flashCount) {
    /* Toggles LEDs */
    for (int i = 0; i < 2 * flashCount; ++i) {
        LED_GPIO_PORT->ODR ^= (uint8_t) LED_GPIO_PINS;
        Delay(0xFFFF);
    }
    Delay(0xFFFF);
    Delay(0xFFFF);
}

