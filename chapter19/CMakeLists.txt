set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

file(COPY ${PROJECT_SOURCE_DIR}/data/story DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

include_directories(${PROJECT_SOURCE_DIR}/chapter12)
include_directories(${PROJECT_SOURCE_DIR}/chapter14)

add_executable(ex_19_01 ex_19_01.cpp)
add_executable(ex_19_02 ex_19_02.cpp ex_19_02.h ex_19_02_test.cpp)
add_executable(ex_19_03 ex_19_03.cpp)
add_executable(ex_19_04 ex_19_04.cpp)
add_executable(ex_19_06 ex_19_06.cpp query.cpp query.h query_base.cpp query_base.h
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_33.cpp
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_33.h
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_22.cpp
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_22.h)
add_executable(ex_19_07 ex_19_07.cpp query.cpp query.h query_base.cpp query_base.h
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_33.cpp
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_33.h
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_22.cpp
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_22.h)
add_executable(ex_19_08 ex_19_08.cpp query.cpp query.h query_base.cpp query_base.h
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_33.cpp
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_33.h
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_22.cpp
    ${PROJECT_SOURCE_DIR}/chapter12/ex_12_22.h)
add_executable(ex_19_09 ex_19_09.cpp)
add_executable(ex_19_10 ex_19_10.cpp)
add_executable(ex_19_12 ex_19_12.cpp)
add_executable(ex_19_17 ex_19_17.cpp)
add_executable(ex_19_18 ex_19_18.cpp)
add_executable(ex_19_19 ex_19_19.cpp ${PROJECT_SOURCE_DIR}/chapter14/ex_14_22.h
    ${PROJECT_SOURCE_DIR}/chapter14/ex_14_22.cpp)
add_executable(ex_19_20 ex_19_20.cpp ex_19_20.h ex_19_20_test.cpp)