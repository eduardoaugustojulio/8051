# the name of the target operating system
set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_VERSION 1)
set(CMAKE_SYSTEM_PROCESSOR 8051)

# which compilers to use for C and C++
set(CMAKE_C_COMPILER sdcc)
set(CMAKE_C_FLAGS_INIT "-mmcs51 --model-small -o --std-c99")

# here is the target environment is located
set(CMAKE_FIND_ROOT_PATH  /usr/share/sdcc)

# adjust the default behaviour of the FIND_XXX() commands:
# search headers and libraries in the target environment, search 
# programs in the host environment
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
