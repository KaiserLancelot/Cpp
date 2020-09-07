//
// Created by kaiser on 19-3-11.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
    std::string name;
    std::string phones;
};

bool valid(const std::regex& regex, const std::string& phone)
{
    std::smatch smatch;

    if (!std::regex_match(phone, smatch, regex)) {
        return false;
    }
    if (smatch[1].matched) {
        return smatch[3].matched && (!smatch[4].matched || smatch[4].str() == " ");
    }
    else {
        return !smatch[3].matched && smatch[4].str() == smatch[6].str();
    }
}

std::string format(const std::string& str)
{
    return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main()
{
    std::string line, word;
    std::vector<PersonInfo> people;
    std::istringstream record;
    std::ifstream ifs{"record2"};

    if (!ifs) {
        std::cerr << "can't open file\n";
        return EXIT_FAILURE;
    }

    while (std::getline(ifs, line)) {
        PersonInfo info;
        record.clear();
        record.str(line);
        record >> info.name;
        std::getline(record, info.phones);
        info.phones = info.phones.substr(1);
        people.push_back(info);
    }

    std::regex r{
            R"((\()?(\d{3})(\))?[ ]*([-. ])?[ ]*(\d{3})[ ]*([-. ])?[ ]*(\d{4}))"};
    for (const auto& entry : people) {
        if (!valid(r, entry.phones))
            std::cerr << "input error: " << entry.name << " invalid number(s) "
                      << entry.phones << '\n';
        else
            std::cout << entry.name << " " << format(entry.phones) << '\n';
    }
}
