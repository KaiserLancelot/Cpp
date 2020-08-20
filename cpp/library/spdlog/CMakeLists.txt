find_package(spdlog REQUIRED)
add_executable(logging main.cpp)
# FIXME fmt-header-only
target_link_libraries(logging PRIVATE spdlog::spdlog_header_only)
