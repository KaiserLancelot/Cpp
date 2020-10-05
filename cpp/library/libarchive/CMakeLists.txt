find_package(LibArchive)

add_executable(libarchive main.cpp)
target_link_libraries(libarchive ${LibArchive_LIBRARIES})
