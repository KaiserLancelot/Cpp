//
// Created by kaiser on 2020/4/27.
//

#pragma once

#include <cstddef>
#include <iterator>

template <typename Container>
void insertion_sort(Container& arr) {
  for (std::size_t i{1}; i < std::size(arr); ++i) {
    auto key{arr[i]};
    auto j{i};
    while (j-- > 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
    }
    arr[j + 1] = key;
  }
}
