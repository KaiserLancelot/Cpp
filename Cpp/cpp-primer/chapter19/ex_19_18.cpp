//
// Created by kaiser on 19-3-17.
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

int main() {
  std::vector<std::string> svec{"a", "", "c", "d", ""};
  std::cout << std::count_if(std::begin(svec), std::end(svec),
                             std::mem_fn(&std::string::empty))
            << '\n';
}