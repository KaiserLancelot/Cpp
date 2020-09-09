enable_testing()

set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)
find_package(GTest REQUIRED)

add_executable(test main.cpp test.cpp)
target_link_libraries(test ${GTEST_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT})

gtest_discover_tests(test)
