file(GLOB cppsrc *.h *.cpp)
add_executable(push_button ${cppsrc} resource.qrc)

target_link_libraries(push_button
    Qt5::Core
    Qt5::Widgets)
