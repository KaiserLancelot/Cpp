find_package(CURL REQUIRED)

add_executable(libcurl main.cpp)
target_link_libraries(libcurl CURL::libcurl)
