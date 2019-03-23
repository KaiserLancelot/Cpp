set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)

add_executable(action-dialog action-dialog/main.cpp action-dialog/mainwindow.cpp action-dialog/mainwindow.h)
target_link_libraries(action-dialog
    Qt5::Core
    Qt5::Widgets)

add_executable(layout layout.cpp)
target_link_libraries(layout
    Qt5::Core
    Qt5::Widgets)

add_executable(message-box message-box/mainwindow.h message-box/mainwindow.cpp message-box/main.cpp)
target_link_libraries(message-box
    Qt5::Core
    Qt5::Widgets)

add_executable(file-dialog file-dialog/mainwindow.h file-dialog/mainwindow.cpp file-dialog/main.cpp)
target_link_libraries(file-dialog
    Qt5::Core
    Qt5::Widgets)

add_executable(base event/base.cpp)
target_link_libraries(base
    Qt5::Core
    Qt5::Widgets)

add_executable(accept_ignore event/accept_ignore.cpp)
target_link_libraries(accept_ignore
    Qt5::Core
    Qt5::Widgets)