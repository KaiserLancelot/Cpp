//
// Created by kaiser on 19-3-18.
//

#include <functional>
#include <iostream>

int main()
{
    std::cout << std::boolalpha << std::less<>{}(1, 2) << '\n';
    // C++17 std::not_fn
    // 返回其所保有的可调用对象的逻辑非
    std::cout << std::not_fn(std::less<>{})(1, 2) << '\n';
}
