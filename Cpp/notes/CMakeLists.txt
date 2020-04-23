file(COPY ../cpp-primer/data/story DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
add_executable(copy_on_write copy_on_write.cpp)