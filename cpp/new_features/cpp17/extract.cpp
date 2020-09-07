//
// Created by kaiser on 19-3-20.
//

#include <algorithm>
#include <cstdint>
#include <iostream>
#include <map>
#include <string>
#include <utility>

template<typename M>
void print(const M& m)
{
    std::cout << "Race placement:\n";
    for (const auto& [placement, driver] : m) {
        std::cout << placement << ": " << driver << '\n';
    }
}

int main()
{
    std::map<std::int32_t, std::string> race_placement{
            {1, "Mario"},
            {2, "Luigi"},
            {3, "Bowser"},
            {4, "Peach"},
            {5, "Yoshi"},
            {6, "Koopa"},
            {7, "Toad"},
            {8, "Donkey Kong Jr."}};
    print(race_placement);
    std::cout << '\n';

    // C++17 std::map::extract
    // 若容器拥有元素而其关键等于 x
    // 则从容器解链该元素并返回占有它的结点把柄.否则, 返回空结点把柄
    // 还有一个接受迭代器的版本
    // 不复制,移动或分配
    // 是更换 map 的 key 而不重分配的唯一方式
    // 其他关联容器也有
    auto a(race_placement.extract(3));
    auto b(race_placement.extract(8));
    // 对一个空的实例调用 key() 产生未定义行为, 可以使用 empty() 判断
    std::swap(a.key(), b.key());
    // C++17 新增接受 node_type&& 的版本
    // 若 nh 是空的结点把柄, 则不做任何事.否则插入 nh
    // 所占有的元素到容器, 若容器尚未含有拥有等价于 nh.key() 的关键的元素
    race_placement.insert(std::move(a));
    race_placement.insert(std::move(b));

    print(race_placement);
}
