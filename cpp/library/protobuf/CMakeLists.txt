set(CMAKE_INCLUDE_CURRENT_DIR TRUE)

find_package(Protobuf REQUIRED)

add_executable(protobuf main.cpp addressbook.proto)
target_link_libraries(protobuf protobuf::libprotobuf)
protobuf_generate(TARGET protobuf)
