file(GLOB SOURCES *.cc)

add_library(src_lib ${SOURCES})
set_target_properties(src_lib PROPERTIES LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINRY_DIR}/lib")
message("${PROJECT_BINRY_DIR}/lib")
