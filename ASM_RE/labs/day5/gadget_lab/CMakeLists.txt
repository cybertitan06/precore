cmake_minimum_required(VERSION 3.0)
project(pwn1_prod)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wl,-z,norelro -fno-stack-protector -no-pie -O0 -masm=intel")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

add_executable(pwn1 ../src/pwn1.c)
add_executable(pwn1_prod ../src/pwn1_prod.c)

