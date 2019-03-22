//
// Created by kaiser on 19-3-21.
//

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>

#include <fmt/core.h>

namespace sf = std::filesystem;

std::tuple<sf::path, sf::file_status, std::size_t> FileInfo(
    const sf::directory_entry &entry) {
  auto file_status{sf::status(entry)};
  return {entry.path(), file_status,
          sf::is_regular_file(file_status) ? sf::file_size(entry.path()) : 0};
}

char TypeChar(sf::file_status file_status) {
  if (sf::is_directory(file_status)) {
    return 'd';
  } else if (sf::is_symlink(file_status)) {
    return 'l';
  } else if (sf::is_character_file(file_status)) {
    return 'c';
  } else if (sf::is_block_file(file_status)) {
    return 'b';
  } else if (sf::is_fifo(file_status)) {
    return 'p';
  } else if (sf::is_socket(file_status)) {
    return 's';
  } else if (sf::is_other(file_status)) {
    return 'o';
  } else if (sf::is_regular_file(file_status)) {
    return 'f';
  } else {
    return '?';
  }
}

std::string Rwx(sf::perms p) {
  auto check{[p](sf::perms bit, char c) {
    return (p & bit) == sf::perms ::none ? '-' : c;
  }};

  return {
      check(sf::perms::owner_read, 'r'),  check(sf::perms::owner_write, 'w'),
      check(sf::perms::owner_exec, 'x'),  check(sf::perms::group_read, 'r'),
      check(sf::perms::group_write, 'w'), check(sf::perms::group_exec, 'x'),
      check(sf::perms::others_read, 'r'), check(sf::perms::others_write, 'w'),
      check(sf::perms::others_exec, 'x')};
}

std::string SizeString(std::size_t size) {
  std::stringstream ss;

  if (size >= static_cast<std::size_t>(std::pow(2, 30))) {
    ss << (size / static_cast<std::size_t>(std::pow(2, 30))) << " GB";
  } else if (size >= static_cast<std::size_t>(std::pow(2, 20))) {
    ss << (size / static_cast<std::size_t>(std::pow(2, 20))) << " MB";
  } else if (size >= static_cast<std::size_t>(std::pow(2, 10))) {
    ss << (size / static_cast<std::size_t>(std::pow(2, 10))) << " KB";
  } else {
    ss << size << " Byte";
  }

  return ss.str();
}

int main(int argc, char *argv[]) {
  sf::path dir{argc > 1 ? argv[1] : "."};

  if (!sf::exists(dir)) {
    std::cerr << "Path " << dir << " does not exist\n";
    std::exit(EXIT_FAILURE);
  }

  std::vector<std::tuple<sf::path, sf::file_status, std::size_t>> items;

  std::transform(sf::directory_iterator{dir}, {}, std::back_inserter(items),
                 FileInfo);

  for (const auto &[path, status, size] : items) {
    fmt::print("{}{:<20}{:<20}{:<20}\n", TypeChar(status),
               Rwx(status.permissions()), SizeString(size),
               path.filename().c_str());
  }
}