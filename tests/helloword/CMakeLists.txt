cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain-sdcc.cmake")
project(helloword)

file(GLOB SRCS src/*.c)	


add_custom_target(run ALL
    COMMAND echo "RUNNING BINARY FORMATER\n"
    COMMAND packihx *.ihx
    )

add_executable(${PROJECT_NAME} ${SRCS})

