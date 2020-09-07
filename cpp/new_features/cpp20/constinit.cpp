//
// Created by kaiser on 2020/5/5.
//

const char* g() { return "dynamic initialization"; }
constexpr const char* f(bool p) { return p ? "constant initializer" : g(); }

// TODO 需要时再看

// constinit 断言变量拥有静态初始化, 即零初始化与常量初始化, 否则程序非良构。

// constinit 说明符声明拥有静态或线程存储期的变量.若变量以 constinit 声明,
// 若在初始化声明点无可达的 constinit 声明, 则程序非良构, 不需要诊断

// constinit 不能和 constexpr 或 consteval 一同使用.声明的变量为引用时
// constinit 等价于 constexpr.声明的变量为对象时, constexpr
// 强制对象必须拥有静态初始化和常量析构 并使对象有 const 限定, 然而 constinit
// 不强制常量析构和 const 限定.结果是拥有 constexpr 构造函数且 无 constexpr
// 析构函数的类型(例如 std::shared_ptr<T>)的对象可能可以用 constinit, 但不能用
// constexpr 声明
constinit const char* c{f(true)}; // OK
// constinit const char *d{F(false)};  // 错误

// constinit 亦能用于非初始化声明, 以告知编译器 thread_local 变量已被初始化
// extern thread_local constinit int X;
// int Fun() { return X; }  // 无需检查防卫变量

int main() {}
