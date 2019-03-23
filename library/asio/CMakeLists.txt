set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(/home/kaiser/networking-ts-impl-master/include)

add_executable(asio asio.cpp)
target_link_libraries(asio pthread)