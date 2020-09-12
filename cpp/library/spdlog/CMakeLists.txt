find_package(spdlog REQUIRED)

add_executable(logging main.cpp)
target_link_libraries(logging spdlog::spdlog)
