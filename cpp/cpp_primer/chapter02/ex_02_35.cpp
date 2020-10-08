#include <cstdint>

int main() {
  const std::int32_t k_i = 42;

  auto j = k_i;
  const auto& k = k_i;
  auto* p = &k_i;
  const auto k_j2 = k_i, &k2 = k_i;

  (void)j;
  (void)k;
  (void)p;
  (void)k_j2;
  (void)k2;
}
