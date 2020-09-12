find_package(RocksDB REQUIRED)
add_executable(rocksdb_test main.cpp)
target_link_libraries(rocksdb_test RocksDB::rocksdb-shared)
