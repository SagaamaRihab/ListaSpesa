cmake_minimum_required(VERSION 3.20)
project(ListaSpesa)

set(CMAKE_CXX_STANDARD 17)

include_directories(src)

add_executable(ListaSpesa
        main.cpp
        src/item.cpp
)

