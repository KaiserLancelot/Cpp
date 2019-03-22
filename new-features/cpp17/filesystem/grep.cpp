//
// Created by kaiser on 19-3-22.
//

#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

#include <fmt/core.h>

namespace fs = std::filesystem;

std::vector<std::pair<std::size_t, std::string>> Matches(const fs::path &path,
                                                         const std::regex &re) {
  std::vector<std::pair<std::size_t, std::string>> ret;
  if (fs::is_regular_file(path) && !path.extension().empty()) {
    std::ifstream in{path.c_str()};

    std::string line;
    for (std::size_t line_num{1}; std::getline(in, line); ++line_num) {
      if (std::regex_search(line, re)) {
        ret.emplace_back(line_num, std::move(line));
      }
    }
  }

  return ret;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " <pattern>\n";
    std::exit(EXIT_FAILURE);
  }

  std::regex pattern;
  try {
    pattern = argv[1];
  } catch (const std::regex_error &error) {
    std::cerr << error.what() << "\ncode: " << error.code() << '\n';
    std::exit(EXIT_FAILURE);
  }

  // recursive_directory_iterator 是在目录的 directory_entry
  // 元素上, 及递归地在所有子目录的目录条目上迭代的输入迭代器
  // 迭代顺序是未指定的, 除了只造访一次每个目录条目
  for (const auto &entry :
       fs::recursive_directory_iterator{fs::current_path()}) {
    auto match{Matches(entry, pattern)};

    for (const auto &[line_num, content] : match) {
      std::string filename{entry.path().filename().c_str()};
      fmt::print("{}:{:<{}}{}\n", filename, line_num, 40 - std::size(filename),
                 content);
    }
  }
}