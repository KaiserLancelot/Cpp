//
// Created by kaiser on 18-12-3.
//

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cctype>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

bool valid(const std::string &str) {
  return std::isdigit(str[0]);
}

std::string format(const std::string &str) {
  return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main() {
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;
  std::ifstream ifs{"person_info"};

  if (!ifs) {
    std::cerr << "can't open file\n";
    return EXIT_FAILURE;
  }

  while (std::getline(ifs, line)) {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while (record >> word)
      info.phones.push_back(word);
    people.push_back(info);
  }

  for (const auto &entry:people) {
    std::ostringstream formatted, bad_nums;
    for (const auto &nums:entry.phones) {
      if (!valid(nums))
        bad_nums << " " << nums;
      else
        formatted << " " << format(nums);
    }
    if (bad_nums.str().empty()) {
      std::cout << entry.name << " " << formatted.str() << '\n';
    } else {
      std::cerr << "input error: " << entry.name << " invalid number(s) "
                << bad_nums.str() << '\n';
    }
  }
}