//
// Created by kaiser on 19-3-20.
//

#include <cstddef>
#include <iostream>
#include <list>
#include <map>
#include <string>

struct Billionaire {
  std::string name;
  double dollars;
  std::string country;
};

int main() {
  std::list<Billionaire> billionaires{{"Bill Gates", 86.0, "USA"},
                                      {"Warren Buffet", 75.6, "USA"},
                                      {"Jeff Bezos", 72.8, "USA"},
                                      {"Amancio Ortega", 71.3, "Spain"},
                                      {"Mark Zuckerberg", 56.0, "USA"},
                                      {"Carlos Slim", 54.5, "Mexico"},
                                      {"Bernard Arnault", 41.5, "France"},
                                      {"Liliane Bettencourt", 39.5, "France"},
                                      {"Wang Jianlin", 31.3, "China"},
                                      {"Li Ka-shing", 31.2, "Hong Kong"}};
  std::map<std::string, std::pair<const Billionaire, std::size_t>> m;

  for (const auto &b : billionaires) {
    // C++17 std::map::try_emplace
    // 若容器中已存在等价于 k 的关键, 则不做任何事.否则行为类似 emplace
    // 注意 emplace 即使容器中已有拥有该关键的元素,
    // 也可能构造元素, 该情况下新构造的元素将被立即销毁
    // 当相应对象的类型需要很大开销进行构造时, 这对于程序性能是帮助的
    // unordered_map 也可以使用
    auto [iter, success]{m.try_emplace(b.country, b, 1)};
    if (!success) {
      ++iter->second.second;
    }
  }
}