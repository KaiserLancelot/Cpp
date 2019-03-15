set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(Boost 1.69 REQUIRED COMPONENTS system)

add_executable(main main.cpp)

target_link_libraries(main ${Boost_LIBRARIES})