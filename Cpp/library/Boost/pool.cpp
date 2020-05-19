//
// Created by kaiser on 2020/4/27.
//

#include <iostream>
#include <string>

#include <boost/pool/object_pool.hpp>

class Test {
 public:
  Test(const std::string& str) : str_{str} {}
  const std::string& get_string() const { return str_; }

 private:
  std::string str_;
};

int main() {
  boost::object_pool<Test> pool;
  // 返回的对象可以通过调用 destroy() 销毁, 也可以由 pool 析构时自动销毁
  // destroy() 相当与 p->~ElementType(); this->free(p);
  auto ptr{pool.construct("string")};

  if (ptr != nullptr) {
    std::cout << ptr->get_string() << '\n';
  }
}
