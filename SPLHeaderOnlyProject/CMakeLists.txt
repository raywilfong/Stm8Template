cmake_minimum_required(VERSION 3.25)

project(SPLHeaderOnlyProject C)

add_executable(${PROJECT_NAME}
        src/assert_fail.c

        ###################################################################################################
        #        HINT: use the C files below to prototype. Then copy the functions that you need into this
        #        project and turn off the rest of the functions by commenting out the C file.
        #
        #        Only add the code that you need. You only have 8K of flash and these get big, fast.
        ###################################################################################################
#        ../lib/STM8_SPL/src/stm8s_adc1.c
#        ../lib/STM8_SPL/src/stm8s_awu.c
#        ../lib/STM8_SPL/src/stm8s_beep.c
#        ../lib/STM8_SPL/src/stm8s_clk.c
#        ../lib/STM8_SPL/src/stm8s_exti.c
#        ../lib/STM8_SPL/src/stm8s_flash.c
#        ../lib/STM8_SPL/src/stm8s_gpio.c
#        ../lib/STM8_SPL/src/stm8s_i2c.c
#        ../lib/STM8_SPL/src/stm8s_itc.c
#        ../lib/STM8_SPL/src/stm8s_iwdg.c
#        ../lib/STM8_SPL/src/stm8s_rst.c
#        ../lib/STM8_SPL/src/stm8s_spi.c
#        ../lib/STM8_SPL/src/stm8s_tim1.c
#        ../lib/STM8_SPL/src/stm8s_tim2.c
#        ../lib/STM8_SPL/src/stm8s_tim4.c
#        ../lib/STM8_SPL/src/stm8s_uart1.c
#        ../lib/STM8_SPL/src/stm8s_wwdg.c
        ###################################################################################################

        src/stm8s_it.c
        src/main.c
)
target_include_directories(${PROJECT_NAME} BEFORE PRIVATE inc ../lib/STM8_SPL/inc)
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX ".elf")

set(HEX_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.hex)
set(BIN_FILE ${PROJECT_BINARY_DIR}/${PROJECT_NAME}.bin)
add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND stm8-objcopy -Oihex --remove-section=".debug*" --remove-section=SSEG --remove-section=INITIALIZED --remove-section=DATA $<TARGET_FILE:${PROJECT_NAME}> ${HEX_FILE}
        COMMAND stm8-objcopy -Obinary --remove-section=".debug*" --remove-section=SSEG --remove-section=INITIALIZED --remove-section=DATA $<TARGET_FILE:${PROJECT_NAME}> ${BIN_FILE}
        COMMENT "Building ${HEX_FILE} \nBuilding ${BIN_FILE}")



