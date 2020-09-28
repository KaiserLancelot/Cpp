include_directories(../chapter12)
file(COPY ../data/story DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(ex_15_03 ex_15_03.cpp ex_15_03.h)
add_executable(ex_15_05 ex_15_05.h ex_15_03.cpp ex_15_03.h)
add_executable(ex_15_06 ex_15_06.cpp ex_15_05.h ex_15_03.cpp ex_15_03.h)
add_executable(ex_15_07 ex_15_07.h ex_15_03.cpp ex_15_03.h)
add_executable(ex_15_16 ex_15_16.cpp ex_15_16.h)
add_executable(ex_15_17 ex_15_17.cpp ex_15_16.cpp ex_15_16.h)
add_executable(ex_15_26 ex_15_26.h ex_15_26.cpp)
add_executable(ex_15_27 ex_15_27.h ex_15_27.cpp)
add_executable(ex_15_28 ex_15_28.h ex_15_28.cpp)
add_executable(ex_15_29 ex_15_28.h ex_15_29.cpp)
add_executable(ex_15_30 ex_15_30_quote.h ex_15_30_quote.cpp ex_15_30.cpp
                        ex_15_30.h ex_15_30_test.cpp)
add_executable(
  ex_15_39
  ex_15_39.cpp
  ex_15_39.h
  ../chapter12/ex_12_33.cpp
  ../chapter12/ex_12_33.h
  ex_15_39_query.cpp
  ex_15_39_query.h
  ../chapter12/ex_12_22.cpp
  ../chapter12/ex_12_22.h
  ex_15_39_test.cpp)
add_executable(
  ex_15_42
  ex_15_42.cpp
  ex_15_42.h
  ../chapter12/ex_12_33.cpp
  ../chapter12/ex_12_33.h
  ex_15_42_query.cpp
  ex_15_42_query.h
  ../chapter12/ex_12_22.cpp
  ../chapter12/ex_12_22.h
  ex_15_42_test.cpp)
