/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-18 16:01:10
 * @ Modified time: 2020-05-19 04:23:32
 */

#include <cstddef>
#include <cstdint>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>

class A {
 public:
  const std::string &get_string() const { return s_; }

 private:
  std::string s_;
};

int main() {
  auto hasher{[](const A &item) {
    return std::hash<std::string>{}(item.get_string());
  }};
  auto equal_op{[](const A &lhs, const A &rhs) {
    return lhs.get_string() == rhs.get_string();
  }};

  std::unordered_map<A, std::string, decltype(hasher), decltype(equal_op)>
      a_map{42, hasher, equal_op};  // 42 是用于创建的最小桶数
  std::cout << a_map.bucket_count() << '\n';

  std::unordered_map<std::string, std::int32_t> map{
      {"a", 1}, {"b", 2}, {"c", 3}};

  // 容器中的桶数
  std::cout << map.bucket_count() << '\n';
  // 最大桶数
  std::cout << map.max_bucket_count() << '\n';
  // 桶 n 中的元素数
  std::cout << map.bucket_size(0) << '\n';
  // 关键 key 的桶编号
  std::cout << map.bucket("a") << '\n';
  // 返回指向下标为 n 的桶首元素的迭代器
  std::cout << map.begin(0)->first << '\n';
  // 返回每个桶元素的平均数
  std::cout << map.load_factor() << '\n';
  // 返回最大加载因子(每个桶的平均元素数)
  std::cout << map.max_load_factor() << '\n';
  // 设置最大加载因子为 n, 若加载因子超出此阈值, 则容器自动增加桶数
  map.max_load_factor(1);
  // 设置桶数为 count 并重哈希容器, 即考虑桶总数已改变, 再把元素放到适当的桶中
  // 若新的桶数使加载因子大于最大加载因子, 则新桶数至少为 size() /
  // max_load_factor()
  map.rehash(10);
  // 设置桶数为适应至少 count 个元素, 而不超出最大加载因子所需的数
  // 并重哈希容器
  map.reserve(10);

  // 下面这些其他关联容器也有

  // 检查容器中是否有 key 等价于给定的 key 的元素(C++20)
  std::cout << std::boolalpha << map.contains("a") << '\n';

  decltype(map) map2{{"a", 1}};
  // 试图释出 source 中每个元素, 并用 *this 的哈希函数和关键相等谓词插入到 *this
  // 若 *this 中有元素, 其 key 等价于来自 source 中元素的 key, 则不从 source
  // 释出该元素.不复制或移动元素, 只会重指向容器结点的内部指针(C++17)
  map2.merge(map);
  std::cout << std::size(map) << " vs " << std::size(map2) << '\n';  // 1 vs 3

  // 若容器拥有元素而其 key 等于 x
  // 则从容器解链该元素并返回占有它的结点把柄.否则, 返回空结点把柄
  // 任何情况下, 均不复制或移动元素, 只重指向容器结点的内部指针(C++17)
  auto node{map.extract("a")};
  std::cout << std::size(map) << '\n';  // 0
  // extract 是更换 map 的 key 而不重分配的唯一方式
  node.key() = "aa";
  map.insert(std::move(node));
  std::cout << std::size(map) << '\n';  // 1

  // 若等价于 k 的键已存在于容器中, 则赋值给对应于键 k 的
  // mapped_type.若键不存在, 则插入(C++17)
  map.insert_or_assign("aa", 42);

  // 若容器中已存在等价于 k 的关键, 则不做任何事.否则行为类似 emplace (C++17)
  map.try_emplace("b", 42);
  for (const auto &[key, value] : map) {
    std::cout << key << ": " << value << '\n';
  }
}
