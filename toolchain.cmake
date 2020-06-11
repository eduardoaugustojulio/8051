# the name of the target operating system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR 8051)

set(CMAKE_C_FLAGS "--model-small -DSDCC_CYGNAL --less-pedantic --xram-size 8448 --stack-auto --no-peep --int-long-reent --float-reent")

set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)
# which compilers to use for C and C++
set(CMAKE_C_COMPILER sdcc)

# here is the target environment is located
SET(CMAKE_FIND_ROOT_PATH  /usr/share/sdcc)

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search 
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
