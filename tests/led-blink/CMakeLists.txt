cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain-sdcc.cmake")
project(led-blink)

set(PROJECT_PATH  ${CMAKE_CURRENT_SOURCE_DIR})
set(SRC_PATH 	 "${PROJECT_PATH}/src")
set(INC_PATH	 "${PROJECT_PATH}/include")

include_directories(${INC_PATH} ${SRC_PATH})

file(GLOB SRCS 
        ${SRC_PATH}/*.c
	${SRC_PATH}/*.h
)	

add_executable(${PROJECT_NAME} ${SRCS})

add_custom_command(TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND  echo "RUNNING BINARY FORMATER\n"
    COMMAND  packihx ${PROJECT_NAME}.ihx > ${PROJECT_NAME}.hex
)
