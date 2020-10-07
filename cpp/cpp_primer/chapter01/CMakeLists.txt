file(COPY ${CMAKE_SOURCE_DIR}/cpp_primer/data/book.txt
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(ex-01-01 ex_01_01.cpp)
add_executable(ex-01-02 ex_01_02.cpp)
add_executable(ex-01-03 ex_01_03.cpp)
add_executable(ex-01-04 ex_01_04.cpp)
add_executable(ex-01-05 ex_01_05.cpp)
add_executable(ex-01-07 ex_01_07.cpp)
add_executable(ex-01-08 ex_01_08.cpp)
add_executable(ex-01-09 ex_01_09.cpp)
add_executable(ex-01-10 ex_01_10.cpp)
add_executable(ex-01-11 ex_01_11.cpp)
add_executable(ex-01-12 ex_01_12.cpp)
add_executable(ex-01-13 ex_01_13.cpp)
add_executable(ex-01-15 ex_01_15.cpp)
add_executable(ex-01-16 ex_01_16.cpp)
add_executable(ex-01-18 ex_01_18.cpp)
add_executable(ex-01-19 ex_01_19.cpp)

add_executable(ex-01-20 ex_01_20.cpp)
target_link_libraries(ex-01-20 tools)

add_executable(ex-01-21 ex_01_21.cpp)
target_link_libraries(ex-01-21 tools)

add_executable(ex-01-22 ex_01_22.cpp)
target_link_libraries(ex-01-22 tools)

add_executable(ex-01-23 ex_01_23.cpp)
target_link_libraries(ex-01-23 tools)

add_executable(ex-01-25 ex_01_25.cpp)
target_link_libraries(ex-01-25 tools)
