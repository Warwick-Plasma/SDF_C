project(SDF C)
cmake_minimum_required(VERSION 2.8.8)

set(TOPLEVEL "${CMAKE_CURRENT_SOURCE_DIR}")
#file(GLOB SOURCE_ALL include/*inc CMakeLists.txt Makefile*)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")

include_directories(include)
add_subdirectory(src)
