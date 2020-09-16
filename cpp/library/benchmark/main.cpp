#include <algorithm>
#include <cstdint>
#include <random>
#include <vector>

#include <benchmark/benchmark.h>

void dense_range(benchmark::State& state) {
  for (auto _ : state) {
    std::vector<int> v(state.range(0), state.range(0));
    // 下面两个防止优化
    benchmark::DoNotOptimize(v.data());
    // TODO ClobberMemory ???
    benchmark::ClobberMemory();
  }
}
// 从范围中挑选几个数运行 benchmark, 默认为 8 的倍数(8, 64, 512)
// 可以用 RangeMultiplier 修改默认倍数
BENCHMARK(dense_range)->Range(8, 512);
// 对范围中每一个数运行 benchmark
BENCHMARK(dense_range)->DenseRange(0, 256, 128);

void sort_vector(benchmark::State& state) {
  std::default_random_engine e{std::random_device{}()};
  for (auto _ : state) {
    state.PauseTiming();

    std::vector<std::int32_t> v;
    v.reserve(state.range(0));

    for (std::int32_t i{0}; i < state.range(0); ++i) {
      v.push_back(e());
    }

    state.ResumeTiming();
    std::sort(std::begin(v), std::end(v));
  }
  state.SetComplexityN(state.range(0));
}

BENCHMARK(sort_vector)
    ->RangeMultiplier(2)
    ->Range(1 << 10, 1 << 18)
    // 计算时间复杂度
    ->Complexity();

// --benchmark_format=<console|json|csv>
// --benchmark_out=<filename>

// 禁用/启用 CPU频率缩放
// sudo cpupower frequency-set --governor performance
// sudo cpupower frequency-set --governor powersave
BENCHMARK_MAIN();
