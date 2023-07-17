LINK_DIRECTORIES(${CMAKE_BINARY_DIR}/lib)

#add_executable (cppzmq_example cppzmq_example.cc)
#target_link_libraries(cppzmq_example zmq)

add_executable (boost_test boost_test.cc)

add_executable (ice_publisher ice_publisher.cc)
target_link_libraries(ice_publisher iceoryx_posh iceoryx_dust iceoryx_hoofs iceoryx_platform rt)

add_executable (ice_subscriber ice_subscriber.cc)
target_link_libraries(ice_subscriber iceoryx_posh iceoryx_dust iceoryx_hoofs iceoryx_platform rt)

add_executable (test_name test_name.cc)
target_link_libraries(test_name src_lib)

#add_executable (onetbb_test onetbb_test.cc)
#target_link_libraries(onetbb_test tbb)

#add_executable (test_zmq test_zmq.cc)
#target_link_libraries(test_zmq zmq)
