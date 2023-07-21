LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)

add_executable(test_date test_date.cc)
target_link_libraries(test_date fmt)

add_executable(test_msg test_msg.cc)
