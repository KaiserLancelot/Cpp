//
// Created by kaiser on 18-12-3.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::string> phones;
};

int main() {
  std::ifstream ifs{"person_info"};

  if (!ifs) {
    std::cerr << "can't open file\n";
    return EXIT_FAILURE;
  }

  std::vector<PersonInfo> people;

  std::string line;
  std::istringstream record;
  while (std::getline(ifs, line)) {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;

    std::string word;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }

  for (const auto& info : people) {
    std::cout << info.name << ' ';
    for (const auto& phone : info.phones) {
      std::cout << phone << ' ';
    }
    std::cout << '\n';
  }
}
