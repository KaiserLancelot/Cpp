//
// Created by kaiser on 18-12-20.
//

#include "ex_13_31.h"

#include <algorithm>
#include <vector>

int main()
{
    // 注意,元素过少时使用插入排序,不会使用swap
    std::vector<HasPtr> vec(20, HasPtr{"a"});
    std::sort(std::begin(vec), std::end(vec));
}
