find_package(leveldb REQUIRED)
add_executable(leveldb_test main.cpp)
target_link_libraries(leveldb_test leveldb)
