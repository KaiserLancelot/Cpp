set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

file(COPY ${PROJECT_SOURCE_DIR}/data/story DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(ex_17_03 ex_17_03.cpp ex_17_03.h ex_17_03_test.cpp)
add_executable(ex_17_04 ex_17_04.cpp sales_data.cpp sales_data.h)
add_executable(ex_17_05 ex_17_05.cpp sales_data.cpp sales_data.h)
add_executable(ex_17_06 ex_17_06.cpp sales_data.cpp sales_data.h)
add_executable(ex_17_14 ex_17_14.cpp)