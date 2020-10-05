find_package(benchmark REQUIRED)

add_executable(benchmark main.cpp)
target_link_libraries(benchmark benchmark::benchmark)
