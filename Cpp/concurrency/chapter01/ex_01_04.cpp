//
// Created by kaiser on 19-4-11.
//

#include <iostream>
// 提供管理线程的函数和类
#include <thread>

void Hello() { std::cout << "Hello World\n"; }

int main() {
  // template< class Function, class... Args >
  // explicit thread( Function&& f, Args&&... args );
  // 每一个线程都必须具有一个初始函数, 可以有可选的传递给函数的参数
  // 新线程的执行从这里开始
  std::thread t{Hello};
  // 阻塞当前线程, 直至 t 所标识的线程完成其执行
  // t 所标识的线程的完成同步于从 join() 的成功返回
  t.join();
  // 启动了线程则需要明确要等待线程结束(join), 还是让其自主运行(detached)
  // 如果 std::thread 对象销毁之前还没有做出决定, 程序就会终止
  // (std::thread 的析构函数会调用 std::terminate())

  // 只能对一个线程使用一次 join() ;一旦已经使用过 join()
  // std::thread 对象就不能再次加入了,当对其使用 joinable() 时
  // 将返回false
}
