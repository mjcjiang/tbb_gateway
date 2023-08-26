LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)

add_executable (hacking_tbb hacking_tbb.cc)
target_link_libraries(hacking_tbb tbb)
