//
// Created by kaiser on 18-12-5.
//

#include <vector>
#include <list>
#include <cstdint>
#include <iostream>

int main() {
  std::int32_t ia[]{0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::list<std::int32_t> li(std::begin(ia), std::end(ia));
  std::vector<std::int32_t> vi(std::begin(ia), std::end(ia));

  auto it1{std::begin(li)};
  while (it1 != std::end(li)) {
    if (*it1 % 2) {
      it1 = li.erase(it1);
    } else {
      ++it1;
    }
  }

  auto it2{std::begin(vi)};
  while (it2 != std::end(vi)) {
    if (*it2 % 2) {
      ++it2;
    } else {
      it2 = vi.erase(it2);
    }
  }

  for (auto ele:li) {
    std::cout << ele << ' ';
  }
  std::cout << '\n';
  for (auto ele:vi) {
    std::cout << ele << ' ';
  }
  std::cout << '\n';
}