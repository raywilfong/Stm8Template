cmake_minimum_required(VERSION 3.25)
project(STM8_SPL C)

file(GLOB_RECURSE SPL_SOURCES "src/*.c")
file(GLOB_RECURSE SPL_EXCLUSIONS
        "src/*_adc2.c"
        "src/*_can.c"
        "src/*_tim[3,5,6].c"
        "src/*_uart[2,3,4].c"
)
list(REMOVE_ITEM SPL_SOURCES ${SPL_EXCLUSIONS})

message("* * * * * SPL_EXCLUSIONS:")
foreach(src ${SPL_EXCLUSIONS})
    message(${src})
endforeach()
message("* * * * * SPL_SOURCES: (Add to your project build as needed)")
foreach(src ${SPL_SOURCES})
    message(${src})
endforeach()
