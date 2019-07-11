set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Test REQUIRED CONFIG)
find_package(Qt5Sql REQUIRED CONFIG)
find_package(Qt5Network REQUIRED CONFIG)
find_package(Qt5Gui REQUIRED CONFIG)
find_package(Qt5Widgets REQUIRED CONFIG)
find_package(Qt5Multimedia REQUIRED CONFIG)
find_package(Qt5LinguistTools REQUIRED CONFIG)

add_definitions(-DAPP_VERSION="${PROJECT_VERSION}")

add_subdirectory(internationalization)
