set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(fmt)

add_definitions(-DFMT_STRING_ALIAS=1)

add_executable(core core.cpp)
target_link_libraries(core fmt::fmt)

add_executable(format format.cpp)
target_link_libraries(format fmt::fmt)

add_executable(ostream ostream.cpp)
target_link_libraries(ostream fmt::fmt)

add_executable(syntax syntax.cpp)
target_link_libraries(syntax fmt::fmt)