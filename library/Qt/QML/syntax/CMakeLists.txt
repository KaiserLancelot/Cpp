add_executable(syntax main.cpp qml.qrc)
target_link_libraries(syntax
    Qt5::Core
    Qt5::Quick)