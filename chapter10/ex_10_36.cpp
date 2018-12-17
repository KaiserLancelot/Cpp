//
// Created by kaiser on 18-12-17.
//

#include <list>
#include <algorithm>
#include <iostream>

int main() {
    std::list<std::int32_t> li{1, 2, 3, 0, 4, 4, 0};
    std::find(std::crbegin(li), std::crend(li), 0);
}