//
// Created by kaiser on 19-3-8.
//

#include <array>
#include <cstdint>
#include <tuple>
#include <utility>

// C++14 std::integer_sequence 定义于 utility, 表示一个编译时的整数序列
// std::array to std::tuple
template <typename Array, std::size_t... index>
auto a2t_impl(const Array& a, std::index_sequence<index...>) {
  return std::make_tuple(a[index]...);
}

template <typename T, std::size_t m>
auto a2t(const std::array<T, m>& a) {
  return a2t_impl(a, std::make_index_sequence<m>{});
}

int main() {
  std::array<std::int32_t, 4> array{1, 2, 3, 4};
  auto tuple{a2t(array)};
}