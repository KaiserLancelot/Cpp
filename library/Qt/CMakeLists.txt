set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Sql REQUIRED CONFIG)
find_package(Qt5Test REQUIRED CONFIG)
find_package(fmt)

add_definitions(-DFMT_STRING_ALIAS=1)

add_executable(sql SQL/sql.cpp)
target_link_libraries(sql Qt5::Core Qt5::Sql fmt::fmt)

add_executable(json Core/json.cpp)
target_link_libraries(json Qt5::Core)

add_executable(enum Core/enum.cpp Core/enum.h)
target_link_libraries(enum Qt5::Core)

add_executable(command_line Core/command_line.cpp)
target_link_libraries(command_line Qt5::Core)

add_executable(Test Test/test.cpp Test/test.h)
target_link_libraries(Test Qt5::Test)

add_executable(benchmark Test/benchmark.cpp Test/benchmark.h)
target_link_libraries(benchmark Qt5::Test)

add_executable(file Core/file.cpp)
target_link_libraries(file Qt5::Core)

file(COPY Core/data/in.txt DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(text_stream Core/text_stream.cpp)
target_link_libraries(text_stream Qt5::Core)

add_executable(containers Core/containers.cpp)
target_link_libraries(containers Qt5::Core)
