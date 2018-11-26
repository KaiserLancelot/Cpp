//
// Created by kaiser on 18-11-26.
//

#include <iostream>
#include <cstdint>
#include <string_view>

int main()
{
    std::int32_t grade;
    std::cin >> grade;

    //a
    std::string_view final_grade(
            (grade > 90) ? "high pass" :
            (grade > 75) ? "pass" :
            (grade > 60) ? "low pass" : "fail");

    //b
    if (grade > 90)
        final_grade = "high pass";
    else if (grade > 75)
        final_grade = "pass";
    else if (grade > 60)
        final_grade = "low pass";
    else
        final_grade = "fail";

    std::cout << final_grade << '\n';
}