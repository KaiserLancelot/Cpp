set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)

add_definitions(-DASIO_NO_DEPRECATED -DASIO_STANDALONE)

add_executable(asio main.cpp)
target_link_libraries(asio ${CMAKE_THREAD_LIBS_INIT})
