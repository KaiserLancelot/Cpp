file(COPY ${CMAKE_SOURCE_DIR}/cpp-primer/data/story
     DESTINATION ${CMAKE_BINARY_DIR})

set(THREADS_PREFER_PTHREAD_FLAG ON)

find_package(Threads REQUIRED)

# FIXME BOOST_ASIO_DISABLE_CONCEPTS
add_definitions(-DBOOST_ASIO_NO_DEPRECATED -DBOOST_ASIO_DISABLE_CONCEPTS)
find_package(Boost REQUIRED COMPONENTS locale program_options iostreams)

add_executable(pool pool.cpp)

add_executable(string_algo string_algo.cpp)

add_executable(local local.cpp)
target_link_libraries(local ${Boost_LIBRARIES})

add_executable(program_options program_options.cpp)
target_link_libraries(program_options ${Boost_LIBRARIES})

add_executable(zstd zstd.cpp)
target_link_libraries(zstd ${Boost_LIBRARIES})

add_executable(asio asio/main.cpp)
target_link_libraries(asio ${CMAKE_THREAD_LIBS_INIT})
