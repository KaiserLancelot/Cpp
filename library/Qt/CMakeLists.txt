set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

set(CMAKE_AUTOMOC ON)

find_package(Qt5Core REQUIRED CONFIG)
find_package(Qt5Sql REQUIRED CONFIG)
find_package(fmt)

add_definitions(-DFMT_STRING_ALIAS=1)

add_executable(sql sql.cpp)
target_link_libraries(sql Qt5::Core Qt5::Sql fmt::fmt)

add_executable(enum enum.cpp enum.h)
target_link_libraries(enum Qt5::Core)

add_executable(json json.cpp)
target_link_libraries(json Qt5::Core)