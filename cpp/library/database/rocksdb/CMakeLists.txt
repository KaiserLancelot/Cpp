# FIXME find_package(RocksDB REQUIRED)
add_executable(rocksdb_test main.cpp)
# ${ROCKSDB_LIB}
target_link_libraries(rocksdb_test rocksdb)
