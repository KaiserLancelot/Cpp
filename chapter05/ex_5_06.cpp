//
// Created by kaiser on 18-11-27.
//

#include <cstdint>
#include <iostream>
#include <vector>
#include <string>

int main() {
    const std::vector<std::string> kScores{
            "F", "D", "C", "B", "A", "A++"};
    std::string letter_grade;

    std::int32_t grade;
    std::cin >> grade;

    if (grade < 60)
        letter_grade = kScores[0];
    else if (grade <= 100) {
        letter_grade = kScores[(grade - 50) / 10];
        if (grade != 100) {
            (grade % 10 > 7) ? letter_grade += '+' :
            (grade % 10 < 3) ? letter_grade += '-' : "";
        }
    } else {
        std::cerr << "wrong grade\n";
        return -1;
    }
    std::cout << letter_grade << '\n';
}