set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)
find_package(Boost REQUIRED COMPONENTS locale)

# TODO FIXIT BOOST_ASIO_DISABLE_CONCEPTS
add_definitions(-DBOOST_ASIO_NO_DEPRECATED -DBOOST_ASIO_DISABLE_CONCEPTS)

add_executable(pool pool.cpp)

add_executable(string_algo string_algo.cpp)

add_executable(local local.cpp)
target_link_libraries(local ${Boost_LIBRARIES})

add_executable(asio asio/main.cpp)
target_link_libraries(asio ${CMAKE_THREAD_LIBS_INIT})
