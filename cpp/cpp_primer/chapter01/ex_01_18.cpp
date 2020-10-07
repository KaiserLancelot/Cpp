#include <cstdint>
#include <iostream>

int main() {
  std::int32_t curr_val{}, val{};

  if (std::cin >> curr_val) {
    std::int32_t cnt{1};
    while (std::cin >> val) {
      if (val == curr_val)
        ++cnt;
      else {
        std::cout << curr_val << " occurs " << cnt << " times\n";
        cnt = 1;
        curr_val = val;
      }
    }
    std::cout << curr_val << " occurs " << cnt << " times\n";
  }
}
