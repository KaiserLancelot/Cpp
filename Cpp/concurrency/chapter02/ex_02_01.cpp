//
// Created by kaiser on 19-4-11.
//

#include <cstdint>
#include <iostream>
#include <thread>

void DoSomething(std::int32_t i) { std::cout << i << '\n'; }

class Func {
 public:
  explicit Func(std::int32_t &i) : i_{i} {}
  void operator()() {
    for (std::int32_t i{0}; i < 1000000; ++i) {
      DoSomething(i_);
    }
  }

 private:
  std::int32_t &i_;
};

void Oops() {
  std::int32_t local{};
  std::thread thread{Func{local}};
  // 从 thread 对象分离执行的线程, 允许执行独立地持续.一旦线程退出
  // 则释放所有分配的资源.调用 detach 后, thread 不再占有任何线程
  // 并且也无法 join 了, 当 std::thread 对象使用 joinable()
  // 返回的是 true, 就可以使用 detach() / join()
  // 通常称分离线程为守护线程(daemon threads), UNIX 中守护线程是指
  // 没有任何显式的用户接口, 并在后台运行的线程
  thread.detach();
  // 线程可能仍在运行, 但是 local 已经销毁了
}

void F() {
  std::int32_t local{};
  std::thread thread{Func{local}};

  // 使用 try/catch 确保线程退出后, 函数才结束
  // 也可以使用 RAII
  try {
    // do something om current thread
  } catch (...) {
    thread.join();
    throw;
  }
  thread.join();
}

class ThreadGuard {
 public:
  explicit ThreadGuard(std::thread &thread) : thread_{thread} {}
  ThreadGuard(const ThreadGuard &) = delete;
  ThreadGuard &operator=(const ThreadGuard &) = delete;
  ~ThreadGuard() {
    if (thread_.joinable()) {
      thread_.join();
    }
  }

 private:
  std::thread &thread_;
};

void F2() {
  std::int32_t local{};
  std::thread thread{Func{local}};

  ThreadGuard thread_guard{thread};
  // do something om current thread
}

int main() { Oops(); }
