//
// Created by kaiser on 2020/4/27.
//

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <iostream>
#include <random>
#include <vector>

#include <gtest/gtest.h>

#include "insertion_sort.h"

class SortTest : public testing::Test {
 protected:
  // 下面四个函数都可以删掉
  // 执行完一个测试, SortTest 就会析构

  SortTest() {
    std::cout << "SortTest()\n";

    std::default_random_engine e{std::random_device{}()};
    constexpr std::size_t size{10000};
    arr_.reserve(size);
    std::generate_n(std::back_inserter(arr_), size, e);
  }

  ~SortTest() override { std::cout << "~SortTest()\n"; }

  // 在构造函数之后, 开始测试之前调用
  void SetUp() override { std::cout << "SetUp()\n"; }
  // 在测试结束后, 析构函数调用之前调用
  void TearDown() override { std::cout << "TearDown()\n"; }

  // 可以被测试使用
  std::vector<std::int32_t> arr_;
};

// ASSERT 系列是 Fatal assertion, 从当前函数中返回
// EXPECT 系列是 Nonfatal assertion, 该函数继续运行

TEST_F(SortTest, InsertionSortTest) {
  insertion_sort(arr_);
  ASSERT_TRUE(std::is_sorted(std::begin(arr_), std::end(arr_)));
}

TEST_F(SortTest, StdSortTest) {
  std::sort(std::begin(arr_), std::end(arr_));
  ASSERT_TRUE(std::is_sorted(std::begin(arr_), std::end(arr_)));
}

TEST(Test, Test1) { ASSERT_EQ(1, 1); }

TEST(Test, Test2) { ASSERT_STREQ("abc", "abc"); }

TEST(Test, Test3) {
  // 忽略大小写
  ASSERT_STRCASEEQ("ABC", "abc");
}
