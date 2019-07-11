file(GLOB cppsrc *.h *.cpp)
add_executable(custom_line_edit ${cppsrc} resource.qrc)

target_link_libraries(custom_line_edit
    Qt5::Core
    Qt5::Widgets)
