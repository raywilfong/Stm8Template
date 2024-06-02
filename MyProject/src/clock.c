//
// Created by ray on 6/2/24.
//

#include "clock.h"

void clock_config(void)
{
    CLK_DeInit();

    /* Configure the Fcpu to DIV1*/
    CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);

    /* Configure the HSI prescaler to the optimal value */
    CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);

    /* Output Fcpu on CLK_CCO pin */
    // CLK_CCOConfig(CLK_OUTPUT_CPU);

    /* Configure the system clock to use HSI clock source and to run at 16Mhz */
    CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}
