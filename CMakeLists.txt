CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
PROJECT(hacking_tbb)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXE_LINKER_FLAGS "-Wl,-copy-dt-needed-entries")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_BUILD_TYPE Debug)

############################################################
include_directories(deps/onetbb-1.0.0/include)
include_directories(include)

execute_process( COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/deps/onetbb-1.0.0/lib lib)
set(LIBRARY_OUTPUT_PATH "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(deps)
add_subdirectory(src)
add_subdirectory(apps)
