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
  void Meow() const { std::cout << name_ << " says Meow!\n"; }

 private:
  std::string name_;
};

class Dog {
 public:
  explicit Dog(const std::string &name) : name_{name} {}
  void Woof() const { std::cout << name_ << " says Woof!\n"; }

 private:
  std::string name_;
};

struct AnimalVoice {
  void operator()(const Cat &cat) const { cat.Meow(); }
  void operator()(const Dog &dog) const { dog.Woof(); }
};

// C++17 std::variant
// 类似与 union
int main() {
  std::vector<std::variant<Cat, Dog>> v{Cat{"Tuba"}, Dog{"Balou"},
                                        Cat{"Bobby"}};
  for (const auto &item : v) {
    switch (item.index()) {
      case 0:
        std::get<Cat>(item).Meow();
        break;
      case 1:
        std::get<Dog>(item).Woof();
        break;
      default: {}
    }
  }

  for (const auto &item : v) {
    // 不存在该类型则返回 nullptr
    if (auto d{std::get_if<Dog>(&item)}) {
      d->Woof();
    } else if (auto c{std::get_if<Cat>(&item)}) {
      c->Meow();
    }
  }

  for (const auto &item : v) {
    // 接受一个函数对象和一个 variant 实例.函数对象需要对 variant
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