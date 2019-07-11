file(GLOB cppsrc *.h *.cpp)
add_executable(password_line_edit ${cppsrc})

target_link_libraries(password_line_edit
    Qt5::Core
    Qt5::Widgets)
