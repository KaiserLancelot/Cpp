//
// Created by kaiser on 19-3-21.
//

#include <algorithm>
#include <iostream>
#include <string>
#include <variant>
#include <vector>

class Cat {
 public:
  explicit Cat(const std::string &name) : name_{name} {}
  void meow() const { std::cout << name_ << " says Meow!\n"; }

 private:
  std::string name_;
};

class Dog {
 public:
  explicit Dog(const std::string &name) : name_{name} {}
  void woof() const { std::cout << name_ << " says Woof!\n"; }

 private:
  std::string name_;
};

struct AnimalVoice {
  void operator()(const Cat &cat) const { cat.meow(); }
  void operator()(const Dog &dog) const { dog.woof(); }
};

// C++17 std::variant
// 表示一个类型安全的联合体
// 没有默认构造函数
int main() {
  std::vector<std::variant<Cat, Dog>> v{Cat{"Tuba"}, Dog{"Balou"},
                                        Cat{"Bobby"}};
  for (const auto &item : v) {
    // 返回 variant 所保有可选项的零基下标
    switch (item.index()) {
      case 0:
        std::get<Cat>(item).meow();
        break;
      case 1:
        std::get<1>(item).woof();
        break;
      default: {
      }
    }
  }

  for (const auto &item : v) {
    // 不存在该类型则返回 nullptr
    if (auto d{std::get_if<Dog>(&item)}) {
      d->woof();
    } else if (auto c{std::get_if<Cat>(&item)}) {
      c->meow();
    }
  }

  for (const auto &item : v) {
    // 接受一个函数对象和一个 variant 实例, 函数对象需要对 variant
    // 中所有类型进行重载
    std::visit(AnimalVoice{}, item);
  }

  std::cout << std::count_if(std::begin(v), std::end(v),
                             std::holds_alternative<Cat, Cat, Dog>)
            << '\n';
  std::cout << std::count_if(std::begin(v), std::end(v),
                             std::holds_alternative<Dog, Cat, Dog>)
            << '\n';
}
