cmake_minimum_required(VERSION 3.17)
project(kickstart)

set(CMAKE_CXX_STANDARD 17)

add_executable(kickstart main.cpp)
target_compile_definitions(kickstart PRIVATE -DPLAYGROUND_LOCAL)
