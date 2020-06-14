cmake_minimum_required(VERSION 3.12.0)
project(lox)

set(CMAKE_CXX_STANDARD 20)
add_subdirectory(dependency)
add_subdirectory(lox)
add_executable(lox main.cpp)
target_include_directories(lox PRIVATE ${CMAKE_SOURCE_DIR}/lox/include/)
