LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)

add_executable (config_read config_read.cc)
target_link_libraries(config_read src_lib)

