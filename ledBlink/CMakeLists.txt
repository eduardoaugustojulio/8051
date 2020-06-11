project(ledBlink)
add_executable(${PROJECT_NAME} main.c)
ihx_to_hex(${PROJECT_NAME})
