//
// Created by kaiser on 19-3-5.
//

#include <iostream>
#include <limits>
#include <type_traits>

template <typename T>
struct promote;

template <>
struct promote<short> {
  using type = unsigned int;
};

template <>
struct promote<unsigned short> {
  using type = unsigned int;
};

template <>
struct promote<int> {
  using type = unsigned long long;
};

template <>
struct promote<unsigned> {
  using type = unsigned long long;
};

template <>
struct promote<long> {
  using type = unsigned long long;
};

template <>
struct promote<unsigned long> {
  using type = unsigned long long;
};

template <>
struct promote<long long> {
  using type = unsigned long long;
};

template <>
struct promote<unsigned long long> {
  using type = unsigned long long;
};

template <>
struct promote<float> {
  using type = double;
};

template <>
struct promote<double> {
  using type = long double;
};

template <>
struct promote<long double> {
  using type = long double;
};

template <typename T>
using promote_t = typename promote<T>::type;

template <typename T1, typename T2>
auto sum(T1 lhs, T2 rhs) -> std::common_type_t<promote_t<T1>, promote_t<T2>> {
  return static_cast<std::common_type_t<promote_t<T1>, promote_t<T2>>>(lhs) +
         rhs;
}

int main() {
  std::cout << sum(std::numeric_limits<short>::max(),
                   std::numeric_limits<short>::max())
            << '\n';
  std::cout << sum(std::numeric_limits<unsigned short>::max(),
                   std::numeric_limits<unsigned short>::max())
            << '\n';
  std::cout << sum(std::numeric_limits<int>::max(),
                   std::numeric_limits<int>::max())
            << '\n';
  std::cout << sum(std::numeric_limits<unsigned>::max(),
                   std::numeric_limits<unsigned>::max())
            << '\n';
  std::cout << sum(std::numeric_limits<long>::max(),
                   std::numeric_limits<long>::max())
            << '\n';
  //溢出
  std::cout << sum(std::numeric_limits<unsigned long>::max(),
                   std::numeric_limits<unsigned long>::max())
            << '\n';
  std::cout << sum(std::numeric_limits<long long>::max(),
                   std::numeric_limits<long long>::max())
            << '\n';
  //溢出
  std::cout << sum(std::numeric_limits<unsigned long long>::max(),
                   std::numeric_limits<unsigned long long>::max())
            << '\n';
  std::cout << sum(std::numeric_limits<float>::max(),
                   std::numeric_limits<float>::max())
            << '\n';
  std::cout << sum(std::numeric_limits<double>::max(),
                   std::numeric_limits<double>::max())
            << '\n';
  std::cout << sum(std::numeric_limits<long double>::max(),
                   std::numeric_limits<long double>::max())
            << '\n';
}
