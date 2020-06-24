//
// Created by kaiser on 18-12-5.
//

#include <cstdint>
#include <deque>
#include <list>

int main() {
  std::list<std::int32_t> li{1, 2, 3, 4, 5};
  std::deque<std::int32_t> d1, d2;

  for (auto ele : li) {
    if (ele % 2) {
      d1.push_back(ele);
    } else {
      d2.push_back(ele);
    }
  }
}
