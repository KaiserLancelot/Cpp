set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Test REQUIRED CONFIG)

add_executable(Test test.cpp test.h)
target_link_libraries(Test Qt5::Core Qt5::Test)

add_executable(benchmark benchmark.cpp benchmark.h)
target_link_libraries(benchmark Qt5::Core Qt5::Test)