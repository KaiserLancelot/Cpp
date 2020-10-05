find_package(zstd REQUIRED)

add_executable(zstd-test main.cpp)
target_link_libraries(zstd-test zstd::libzstd_shared)
