LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)

add_executable (config_read config_read.cc)
target_link_libraries(config_read src_lib)

add_executable (market_server market_server.cc)
target_link_libraries(market_server src_lib thostmduserapi_se zmq tbb)

