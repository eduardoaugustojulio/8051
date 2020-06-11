project(ledBlinkFreeRTOS)

set(FREERTOS_DIR "FreeRTOS/Source")

set(FREERTOS_HEADERS 
        "${FREERTOS_DIR}/include" 
        "${FREERTOS_DIR}/portable/SDCC/Cygnal"
        "${FREERTOS_SRC_PATH}/portable/MemMang"
)

file(GLOB FREERTOS_SOURCES
        "${FREERTOS_DIR}/*.c"
        "${FREERTOS_DIR}/portable/SDCC/*.c"
        "${FREERTOS_DIR}/portable/MemMang/heap_1.c"
)

include_directories(${FREERTOS_HEADERS})

add_executable(${PROJECT_NAME} main.c ${FREERTOS_SOURCES})
ihx_to_hex(${PROJECT_NAME})
