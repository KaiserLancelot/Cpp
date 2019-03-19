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