include_directories("${CMAKE_SOURCE_DIR}/cpp_primer/tools")

add_executable(ex-02-04 ex_02_04.cpp)
target_compile_options(ex-02-04 PRIVATE "-Wno-sign-conversion")

add_executable(ex-02-08 ex_02_08.cpp)
add_executable(ex-02-18 ex_02_18.cpp)
add_executable(ex-02-34 ex_02_34.cpp)
add_executable(ex-02-35 ex_02_35.cpp)
add_executable(ex-02-39 ex_02_39.cpp)
add_executable(ex-02-41-1 ex_02_41_1.cpp)
add_executable(ex-02-41-2 ex_02_41_2.cpp)
add_executable(ex-02-41-3 ex_02_41_3.cpp)
