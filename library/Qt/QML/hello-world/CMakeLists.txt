add_executable(hello-world main.cpp qml.qrc)

target_link_libraries(hello-world
    Qt5::Core
    Qt5::Quick)
