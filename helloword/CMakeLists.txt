cmake_minimum_required(VERSION 2.8)
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/toolchain-sdcc.cmake")
project(helloword)

set(BINARY_HEX "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}.hex")

file(GLOB SRCS src/*.c)
	
add_executable(${PROJECT_NAME} ${SRCS})
