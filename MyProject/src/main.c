/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "stm8s_conf.h" // select components needed for build - included here to find it quickly
#include "stm8s_it.h" // interrupt vector map

// private includes
#include "clock.h" // clock configuration functions


void main(void)
{
    clock_config();
    while (1)
    {
    }
}

