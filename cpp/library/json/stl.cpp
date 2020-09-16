/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-25 05:12:47
 * @ Modified time: 2020-05-25 05:47:16
 */

#include <cstdint>
#include <iostream>
#include <unordered_map>
#include <vector>

#include <nlohmann/json.hpp>

int main() {
  std::vector<std::int32_t> vector{1, 2, 3, 4};
  // JSON array
  nlohmann::json json{vector};
  std::cout << json << '\n';  // [[1,2,3,4]]

  std::unordered_map<std::string, std::int32_t> map{
      {"one", 1}, {"two", 2}, {"three", 3}};
  // JSON array
  nlohmann::json json2{map};
  std::cout << json2 << '\n';  // [{"one":1,"three":3,"two":2}]
}
