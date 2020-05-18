//
// Created by kaiser on 18-12-18.
//

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

std::unordered_map<std::string, std::string> build_map(
    std::ifstream &map_file) {
  std::unordered_map<std::string, std::string> trans_map;
  std::string key, value;

  while (map_file >> key && std::getline(map_file, value)) {
    if (std::size(value) > 1) {
      trans_map[key] = value.substr(1);
    } else {
      throw std::runtime_error{"no rule for " + key};
    }
  }
  return trans_map;
}

const std::string translation(
    const std::string &s,
    const std::unordered_map<std::string, std::string> &trans_map) {
  auto map_iter{trans_map.find(s)};
  if (map_iter != std::end(trans_map)) {
    return map_iter->second;
  } else {
    return s;
  }
}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
  auto trans_map{build_map(map_file)};
  std::string text;

  while (std::getline(input, text)) {
    std::istringstream stream{text};
    std::string word;
    bool first_word{true};
    while (stream >> word) {
      if (first_word) {
        first_word = false;
      } else {
        std::cout << ' ';
      }
      std::cout << translation(word, trans_map);
    }
    std::cout << '\n';
  }
}

int main() {
  std::ifstream map_file{"word_transformation"};
  std::ifstream input{"given_to_transform"};

  if (!map_file || !input) {
    std::cerr << "can not open file\n";
    std::exit(EXIT_FAILURE);
  }

  word_transform(map_file, input);
}
