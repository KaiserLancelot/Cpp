set(THREADS_PREFER_PTHREAD_FLAG TRUE)

find_package(Threads REQUIRED)

add_definitions(-DBOOST_ASIO_NO_DEPRECATED -DBOOST_ASIO_STANDALONE)

add_executable(asio main.cpp)
target_link_libraries(asio ${CMAKE_THREAD_LIBS_INIT})
