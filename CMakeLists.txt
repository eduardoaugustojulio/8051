cmake_minimum_required(VERSION 3.16)
set(CMAKE_TOOLCHAIN_FILE "toolchain.cmake")
project("8051")

function(ihx_to_hex bin)
    add_custom_command(TARGET ${bin} POST_BUILD COMMAND  packihx ${bin}.ihx > ${bin}.hex)
endfunction(ihx_to_hex)

include_directories("include")

add_subdirectory("ledBlink")
#add_subdirectory("ledBlinkFreeRTOS") 
add_subdirectory("spi")
