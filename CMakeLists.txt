# CMake entry point
cmake_minimum_required (VERSION 3.5)
project (raytracer)

file(GLOB SOURCES
    "src/*.h"
    "src/*.cpp"
)




add_compile_options(
  -std=c++11
) 


# main.cpp
add_executable(main ${SOURCES})
target_link_libraries(main)