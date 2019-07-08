set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Quick REQUIRED CONFIG)

add_subdirectory(hello-world)
add_subdirectory(syntax)