cmake_minimum_required(VERSION 3.0)
project(dmpCoreLib)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_library(dmpCoreLib
  src/impl.c
  src/Allocator.c)

target_include_directories(dmpCoreLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
