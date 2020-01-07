//
// Created by kaiser on 2020/1/7.
//

#include <cstdint>
#include <iostream>
#include <vector>

#include <range/v3/action.hpp>
#include <range/v3/view.hpp>

int main() {
  std::vector<std::int32_t> v{9, 4, 5, 2, 9, 1, 0, 2, 6, 7, 4, 5, 6, 5, 9, 2, 7,
                              1, 4, 5, 3, 8, 5, 0, 2, 9, 3, 7, 5, 7, 5, 5, 6, 1,
                              4, 3, 1, 8, 4, 0, 7, 8, 8, 2, 6, 5, 3, 4, 5};

  v |= ranges::actions::sort | ranges::actions::unique;
  std::cout << ranges::views::all(v) << '\n';
}
