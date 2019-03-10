set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

add_executable(variable_template variable_template.cpp)
add_executable(exchange exchange.cpp)
add_executable(integer_sequence integer_sequence.cpp)
add_executable(make_from_tuple make_from_tuple.cpp)
add_executable(apply apply.cpp)