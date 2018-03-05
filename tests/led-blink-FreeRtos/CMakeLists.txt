cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain-sdcc.cmake")
project(led-blink)

set(PROJECT_PATH        ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_PATH 	        "${PROJECT_PATH}/src")
set(INC_PATH	        "${PROJECT_PATH}/include")

set(FREERTOS_PATH       "${PROJECT_PATH}/FreeRTOS")
set(FREERTOS_SRC_PATH   "${FREERTOS_PATH}/Source")
set(FREERTOS_INC_PATH   "${FREERTOS_SRC_PATH}/include")
set(FREERTOS_PORT_PATH  "${FREERTOS_SRC_PATH}/portable/SDCC/Cygnal")
set(FREERTOS_MM_PATH    "${FREERTOS_SRC_PATH}/portable/MemMang")

set(DEMO_PATH           "${FREERTOS_PATH}/Demo")
set(DEMO_SRC_PATH       "${DEMO_PATH}/Cygnal")

set(COMMON_PATH         "${DEMO_PATH}/Common")
set(COMMON_INC_PATH     "${COMMON_PATH}/include")


include_directories(${INC_PATH} 
                    ${FREERTOS_INC_PATH} 
                    ${FREERTOS_PORT_PATH}
                    ${FREERTOS_MM_PATH}
                    ${COMMON_INC_PATH})
file(GLOB SRCS 
    ${SRC_PATH}/*.c
	${SRC_PATH}/*.h
	
#	 ${COMMON_PATH}/Full/flash.c
#    ${COMMON_PATH}/Full/print.c 
#    ${COMMON_PATH}/Minimal/integer.c 
#    ${COMMON_PATH}/Minimal/PollQ.c 
#    ${COMMON_PATH}/Minimal/comtest.c 
#    ${COMMON_PATH}/Full/semtest.c
    
    ${DEMO_SRC_PATH}/serial/serial.c
    ${DEMO_SRC_PATH}/ParTest/ParTest.c
	)	

add_executable(${PROJECT_NAME} ${SRCS})

