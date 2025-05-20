cmake_minimum_required(VERSION 3.0)
project(gogogadget)

set(CMAKE_C_STANDARD 11)

# Define an option for selecting the target architecture (32 or 64 bit)
option(TARGET_ARCH "Target architecture (32 or 64 bit)" "64")

# Set the architecture-specific flags
if(TARGET_ARCH STREQUAL "32")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
elseif(TARGET_ARCH STREQUAL "64")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
    add_definitions(-DARCH_64)
endif()

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wl,-z,norelro -fno-stack-protector -no-pie -O0 -masm=intel -g")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# Custom target to clean bin directory
add_custom_target(clean_bin ALL
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
    COMMENT "Cleaning and recreating bin directory"
)

add_executable(gogogadget ../src/gogogadget.c)

# Make sure my_executable depends on clean_bin
add_dependencies(gogogadget clean_bin)

