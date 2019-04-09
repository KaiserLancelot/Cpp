set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Sql REQUIRED CONFIG)
find_package(Qt5Test REQUIRED CONFIG)
find_package(fmt)

add_definitions(-DFMT_STRING_ALIAS=1)

add_executable(sql sql.cpp)
target_link_libraries(sql Qt5::Core Qt5::Sql fmt::fmt)

add_executable(json json.cpp)
target_link_libraries(json Qt5::Core)

add_executable(enum enum.cpp enum.h)
target_link_libraries(enum Qt5::Core)

add_executable(command_line command_line.cpp)
target_link_libraries(command_line Qt5::Core)

add_executable(test test/test.cpp test/test.h)
target_link_libraries(test Qt5::Test)

add_executable(benchmark test/benchmark.cpp test/benchmark.h)
target_link_libraries(benchmark Qt5::Test)

add_executable(file file/file.cpp)
target_link_libraries(file Qt5::Core)

file(COPY data/in.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(text_stream file/text_stream.cpp)
target_link_libraries(text_stream Qt5::Core)

add_executable(containers containers.cpp)
target_link_libraries(containers Qt5::Core)
