//
// Created by kaiser on 19-3-17.
//

#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

#include "ex_14_22.h"

int main()
{
    std::vector<SalesData> v{SalesData{"aa1", 20, 256},
                             SalesData{"aa2", 10, 56},
                             SalesData{"aa3", 50, 296},
                             SalesData{"aa4", 80, 256},
                             SalesData{"aa5", 40, 856},
                             SalesData{"aa6", 20, 26}

    };

    std::cout << std::find_if(
                         std::begin(v), std::end(v),
                         [](const SalesData& item) { return item.AvgPrice() > 5; })
                         ->Isbn()
              << '\n';
}
