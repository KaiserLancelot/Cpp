file(GLOB cppsrc *.h *.cpp)
add_executable(custom_main_window ${cppsrc} resource.qrc)

target_link_libraries(custom_main_window
    Qt5::Core
    Qt5::Widgets)