set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Network REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)

add_executable(weather main.cpp net_worker.cpp net_worker.h
    main_window.cpp main_window.h
    weather_info.cpp weather_info.h)
target_link_libraries(weather Qt5::Core Qt5::Network Qt5::Widgets)
