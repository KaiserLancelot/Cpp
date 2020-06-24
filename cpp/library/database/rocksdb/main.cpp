/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-24 23:00:24
 * @ Modified time: 2020-05-25 04:24:02
 */

#include <cassert>
#include <cstdlib>
#include <iostream>
#include <memory>
#include <string>

#include <rocksdb/db.h>
#include <rocksdb/write_batch.h>

int main() {
  rocksdb::DB *p;
  rocksdb::Options options;
  options.create_if_missing = true;
  // options.error_if_exists = true;
  auto status{rocksdb::DB::Open(options, "testdb", &p)};
  // 不使用智能指针的话需要手动 delete
  std::unique_ptr<rocksdb::DB> db{p};

  if (!status.ok()) {
    std::cerr << status.ToString() << '\n';
    return EXIT_FAILURE;
  }

  rocksdb::WriteBatch batch;
  batch.Put("name", "kaiser");
  status = db->Write(rocksdb::WriteOptions(), &batch);
  if (!status.ok()) {
    std::cerr << status.ToString() << '\n';
    return EXIT_FAILURE;
  }

  std::string value;
  status = db->Get(rocksdb::ReadOptions(), "name", &value);
  if (!status.ok()) {
    std::cerr << status.ToString() << '\n';
    return EXIT_FAILURE;
  }

  assert(value == "kaiser");
  std::cout << value << '\n';
}
