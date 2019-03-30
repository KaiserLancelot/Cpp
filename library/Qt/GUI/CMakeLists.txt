# 指示CMake在需要时自动运行moc
set(CMAKE_AUTOMOC ON)
# 处理 .qrc 文件
set(CMAKE_AUTORCC ON)
# 查找包含在相应的构建目录中
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)

add_executable(signal-slot signal-slot/main.cpp
    signal-slot/newspaper.h
    signal-slot/reader.h)
target_link_libraries(signal-slot
    Qt5::Core)

add_executable(action-dialog action-dialog/main.cpp
    action-dialog/mainwindow.cpp
    action-dialog/mainwindow.h
    resource.qrc)
target_link_libraries(action-dialog
    Qt5::Core
    Qt5::Widgets)

add_executable(layout layout.cpp)
target_link_libraries(layout
    Qt5::Core
    Qt5::Widgets)

add_executable(message-box message-box/mainwindow.cpp
    message-box/mainwindow.h
    message-box/main.cpp
    resource.qrc)
target_link_libraries(message-box
    Qt5::Core
    Qt5::Widgets)

add_executable(file-dialog file-dialog/mainwindow.cpp
    file-dialog/mainwindow.h
    file-dialog/main.cpp
    resource.qrc)
target_link_libraries(file-dialog
    Qt5::Core
    Qt5::Widgets)

add_executable(base event/base.cpp)
target_link_libraries(base
    Qt5::Core
    Qt5::Widgets)

add_executable(accept_ignore event/accept_ignore.cpp
    event/accept_ignore.h)
target_link_libraries(accept_ignore
    Qt5::Core
    Qt5::Widgets)

add_executable(accept_ignore2 event/accept_ignore2.cpp event/accept_ignore2.h)
target_link_libraries(accept_ignore2
    Qt5::Core
    Qt5::Widgets)

add_executable(event event/event.cpp event/event.h)
target_link_libraries(event
    Qt5::Core
    Qt5::Widgets)

add_executable(filter event/filter.cpp event/filter.h)
target_link_libraries(filter
    Qt5::Core
    Qt5::Widgets)

add_executable(summary event/summary.cpp event/summary.h)
target_link_libraries(summary
    Qt5::Core
    Qt5::Widgets)

add_executable(paint paint-system/paint.cpp paint-system/paint.h)
target_link_libraries(paint
    Qt5::Core
    Qt5::Widgets)

add_executable(text-editor text-editor/main.cpp
    text-editor/main_window.cpp text-editor/main_window.h resource.qrc)
target_link_libraries(text-editor
    Qt5::Core
    Qt5::Widgets)

add_executable(coordinate paint-system/coordinate.cpp
    paint-system/coordinate.cpp)
target_link_libraries(coordinate
    Qt5::Core
    Qt5::Widgets)

add_executable(paint_device paint-system/paint_device.cpp
    paint-system/paint_device.h resource.qrc)
target_link_libraries(paint_device
    Qt5::Core
    Qt5::Widgets)

add_executable(gvf paint-system/gvf.cpp)
target_link_libraries(gvf
    Qt5::Core
    Qt5::Widgets)

add_executable(snake snake/main.cpp snake/main_window.h
    snake/main_window.cpp snake/game_controller.cpp
    snake/game_controller.h snake/food.cpp snake/food.h
    snake/snake.cpp snake/snake.h snake/consts.h
    resource.qrc)
target_link_libraries(snake
    Qt5::Core
    Qt5::Widgets)