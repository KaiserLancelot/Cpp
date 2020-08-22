find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)
add_executable(logging main.cpp)
target_link_libraries(logging spdlog::spdlog_header_only)
