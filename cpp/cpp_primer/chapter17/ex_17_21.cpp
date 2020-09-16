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
  std::vector<std::string> phones;
};

bool valid(const std::regex& regex, const std::string& phone) {
  std::smatch smatch;

  if (!std::regex_match(phone, smatch, regex)) {
    return false;
  }
  if (smatch[1].matched) {
    return smatch[3].matched && (!smatch[4].matched || smatch[4].str() == " ");
  } else {
    return !smatch[3].matched && smatch[4].str() == smatch[6].str();
  }
}

std::string format(const std::string& str) {
  return str.substr(0, 3) + "-" + str.substr(3, 3) + "-" + str.substr(6);
}

int main() {
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;
  std::ifstream ifs{"record"};

  if (!ifs) {
    std::cerr << "can't open file\n";
    return EXIT_FAILURE;
  }

  while (std::getline(ifs, line)) {
    PersonInfo info;
    record.clear();
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }

  std::regex r{R"((\()?(\d{3})(\))?([-. ])?(\d{3})([-. ])?(\d{4}))"};
  for (const auto& entry : people) {
    std::ostringstream formatted, bad_nums;
    for (const auto& nums : entry.phones) {
      if (!valid(r, nums))
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
