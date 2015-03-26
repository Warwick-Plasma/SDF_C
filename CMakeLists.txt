project(SDFC C)
cmake_minimum_required(VERSION 2.8.8)

set(TOPLEVEL "${CMAKE_CURRENT_SOURCE_DIR}")
#file(GLOB SOURCE_ALL include/*inc CMakeLists.txt Makefile*)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fpic")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -gdwarf-2")

set(SDFC_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/include" CACHE PATH
    "Path to include files for SDF C library")
set(SDFC_LIB_DIR "${CMAKE_CURRENT_BINARY_DIR}/src" CACHE PATH
    "Path to build directory for SDF C library")

include_directories(include)
add_subdirectory(src)
