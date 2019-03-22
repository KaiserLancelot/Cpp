set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)

add_executable(exercise main.cpp mainwindow.cpp mainwindow.h)

target_link_libraries(exercise
    Qt5::Core
    Qt5::Widgets)