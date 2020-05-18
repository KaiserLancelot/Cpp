/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-18 15:10:25
 * @ Modified time: 2020-05-18 15:13:09
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> exclude = {"aa", "bb", "cc", "dd", "ee", "ff"};

  std::string str;
  std::cin >> str;

  std::cout << (std::binary_search(std::begin(exclude), std::end(exclude), str)
                    ? "exclude"
                    : "not exclude")
            << '\n';
}
