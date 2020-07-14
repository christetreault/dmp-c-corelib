cmake_minimum_required(VERSION 3.8.2)
project(dmpCoreLib)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

file(GLOB_RECURSE sources src/*.c)
file(GLOB_RECURSE headers include/*.h)

add_library(dmpCoreLib
  ${sources}
  ${headers}
  )

source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}
  FILES ${sources} ${headers})

target_include_directories(dmpCoreLib
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
  )

set_target_properties(dmpCoreLib
  PROPERTIES FOLDER "libraries")
