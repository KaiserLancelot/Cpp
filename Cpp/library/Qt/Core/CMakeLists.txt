set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)
find_package(Qt5LinguistTools REQUIRED CONFIG)

add_executable(json json.cpp)
target_link_libraries(json Qt5::Core)

add_executable(enum enum.cpp enum.h)
target_link_libraries(enum Qt5::Core)

add_executable(command_line command_line.cpp)
target_link_libraries(command_line Qt5::Core)

add_executable(file file.cpp)
target_link_libraries(file Qt5::Core)

file(COPY data/in.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(text_stream text_stream.cpp)
target_link_libraries(text_stream Qt5::Core)

add_executable(string string.cpp)
target_link_libraries(string Qt5::Core)
