LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)

add_executable(test_date test_date.cc)
target_link_libraries(test_date fmt)

add_executable(test_msg test_msg.cc)

add_executable(test_client test_client.cc)
target_link_libraries(test_client zmq)

add_executable(zmq_server zmq_server.cc)
target_link_libraries(zmq_server zmq)

add_executable(zmq_client zmq_client.cc)
target_link_libraries(zmq_client zmq)

add_executable(wu_server wu_server.cc)
target_link_libraries(wu_server zmq)

add_executable(wu_client wu_client.cc)
target_link_libraries(wu_client zmq)

add_executable(task_generator task_generator.cc)
target_link_libraries(task_generator zmq)
