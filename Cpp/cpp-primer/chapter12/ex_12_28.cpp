//
// Created by kaiser on 18-12-19.
//

#include <cstdint>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using LineNo = std::vector<std::string>::size_type;

std::ostream &print(std::ostream &os, const std::string &word,
                    const std::vector<std::string> &text,
                    const std::set<LineNo> &line_number) {
  os << word << " occurs " << std::size(line_number)
     << (std::size(line_number) > 1 ? " times" : " time") << '\n';

  for (auto i : line_number) {
    os << "\t(line " << i << ") " << text[i - 1] << '\n';
  }

  return os;
}

int main(int argc, char *argv[]) {
  if (argc == 1) {
    std::cerr << "no input file\n";
    return EXIT_FAILURE;
  }

  std::ifstream ifs{argv[1]};
  if (!ifs) {
    std::cerr << "can not open file\n";
    return EXIT_FAILURE;
  }

  std::vector<std::string> text;
  std::map<std::string, std::set<LineNo>> words_and_line_number;

  std::string line;
  LineNo line_number{1};

  while (std::getline(ifs, line)) {
    text.push_back(line);
    std::istringstream iss{line};
    std::string word;

    while (iss >> word) {
      words_and_line_number[word].insert(line_number);
    }
    ++line_number;
  }

  while (true) {
    std::cout << "enter word to look for, or q to quit: ";
    std::string s;
    if (!(std::cin >> s) || s == "q") {
      break;
    }

    if (auto iter{words_and_line_number.find(s)};
        iter != std::end(words_and_line_number)) {
      print(std::cout, s, text, words_and_line_number[s]);
    } else {
      print(std::cout, s, text, std::set<LineNo>{});
    }
  }
}
