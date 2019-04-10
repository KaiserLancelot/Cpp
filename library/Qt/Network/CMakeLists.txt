set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Network REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)

add_executable(main main.cpp)
target_link_libraries(main Qt5::Core Qt5::Network Qt5::Widgets)
