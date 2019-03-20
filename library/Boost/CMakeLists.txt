set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

find_package(Boost 1.69 REQUIRED COMPONENTS program_options unit_test_framework)

add_definitions(-DBOOST_TEST_DYN_LINK)

add_executable(program_options program_options.cpp)
target_link_libraries(program_options ${Boost_LIBRARIES})

add_executable(my_test test.cpp test_run.cpp)
target_link_libraries(my_test ${Boost_LIBRARIES})