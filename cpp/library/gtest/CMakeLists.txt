enable_testing()

find_package(GTest REQUIRED)

add_executable(test main.cpp test.cpp)
target_link_libraries(test ${GTEST_LIBRARIES})

gtest_discover_tests(test)
