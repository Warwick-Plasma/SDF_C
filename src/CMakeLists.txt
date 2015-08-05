if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_definitions(-DHASH_DEBUG)
endif()
set(VALGRIND OFF CACHE BOOL "Compile with valgrind support")
if(VALGRIND)
    add_definitions(-DVALGRIND)
endif()

set(SOURCES
   sdf_control.c sdf_derived.c sdf_extension_util.c sdf_helper.c
   sdf_input.c sdf_input_cartesian.c sdf_input_point.c sdf_input_station.c
   sdf_modify.c sdf_output.c sdf_util.c stack_allocator.c commit_info.h
   )

if(NOT TARGET sdfc)
   add_library(sdfc STATIC ${SOURCES})
endif()

execute_process(COMMAND sh gen_commit_string.sh
                WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
