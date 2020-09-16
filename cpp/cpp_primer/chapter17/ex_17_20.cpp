//
// Created by kaiser on 19-3-11.
//

#include <fstream>
#include <iostream>
#include <regex>
#include <string>

bool Valid(const std::smatch& smatch) {
  if (smatch[1].matched) {
    return smatch[3].matched && (!smatch[4].matched || smatch[4].str() == " ");
  } else {
    return !smatch[3].matched && smatch[4].str() == smatch[6].str();
  }
}

int main() {
  std::regex r{R"((\()?(\d{3})(\))?([-. ])?(\d{3})([-. ])?(\d{4}))"};
  std::string phone;

  std::ifstream ifs{"phone"};
  while (std::getline(ifs, phone)) {
    for (std::sregex_iterator iter{std::begin(phone), std::end(phone), r}, end;
         iter != end; ++iter) {
      if (Valid(*iter)) {
        std::cout << "valid: " << iter->str() << '\n';
      } else {
        std::cout << "not valid: " << iter->str() << '\n';
      }
    }
  }
}
