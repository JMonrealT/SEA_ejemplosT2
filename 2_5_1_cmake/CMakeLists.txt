cmake_minimum_required(VERSION 3.16)
project(CMake Example)

# Configuración básica
set(CMAKE_C_FLAGS "-g -Wall")
include_directories(include)

# Crear bibliotecas estáticas
add_library(suma_lib STATIC src/suma.c)
add_library(multiplicacion_lib STATIC src/multiplicacion.c)

# Crear ejecutable
add_executable(example example.c)

# Enlazar bibliotecas con el ejecutable
target_link_libraries(example suma_lib multiplicacion_lib)