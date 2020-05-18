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
#include <utility>
#include <vector>

#include <fmt/core.h>

namespace fs = std::filesystem;

// is_regular_file 检查给定文件状态或路径是否对应常规文件
// Linux 文件分为目录文件, 符号链接文件, 字符特殊文件, 块特殊文件
// 管道, IPC 接头, 常规文件, 其他文件
// file_size 返回文件大小
std::pair<fs::path, std::size_t> file_info(const fs::path &dir) {
  return {dir, fs::is_regular_file(dir) ? fs::file_size(dir) : 0};
}

char type_char(const fs::path &dir) {
  if (fs::is_directory(dir)) {
    return 'd';
  } else if (fs::is_symlink(dir)) {
    return 'l';
  } else if (fs::is_character_file(dir)) {
    return 'c';
  } else if (fs::is_block_file(dir)) {
    return 'b';
  } else if (fs::is_fifo(dir)) {
    return 'p';
  } else if (fs::is_socket(dir)) {
    return 's';
  } else if (fs::is_regular_file(dir)) {
    return '-';
  } else if (fs::is_other(dir)) {
    return 'o';
  } else {
    return '?';
  }
}

// std::filesystem::perms 是一个枚举类型
// 代表文件访问权限
// rwx 位, 有三个3位字段, 分别用于所有者,同组成员和其他人
std::string rwx(fs::perms p) {
  auto check{[p](fs::perms bit, char c) {
    return (p & bit) == fs::perms ::none ? '-' : c;
  }};

  return {
      check(fs::perms::owner_read, 'r'),  check(fs::perms::owner_write, 'w'),
      check(fs::perms::owner_exec, 'x'),  check(fs::perms::group_read, 'r'),
      check(fs::perms::group_write, 'w'), check(fs::perms::group_exec, 'x'),
      check(fs::perms::others_read, 'r'), check(fs::perms::others_write, 'w'),
      check(fs::perms::others_exec, 'x')};
}

std::string size_string(std::size_t size) {
  std::stringstream ss;

  if (size >= std::pow(2, 30)) {
    ss << (size / std::pow(2, 30)) << " GB";
  } else if (size >= std::pow(2, 20)) {
    ss << (size / std::pow(2, 20)) << " MB";
  } else if (size >= std::pow(2, 10)) {
    ss << (size / std::pow(2, 10)) << " KB";
  } else {
    ss << size << " Byte";
  }

  return ss.str();
}

int main(int argc, char *argv[]) {
  fs::path dir{argc > 1 ? argv[1] : "."};
  if (!fs::exists(dir)) {
    std::cerr << "Path " << dir << " does not exist\n";
    std::exit(EXIT_FAILURE);
  }

  std::vector<std::pair<fs::path, std::size_t>> items;

  // directory_iterator 是一个迭代于目录的输入迭代器(不造访子目录)
  // 迭代顺序是未指定的, 除了每个目录条目只被造访一次
  // 有 begin 和 end 成员
  // 解引用返回 directory_entry, 它表示目录条目, 存储一个 path 作为成员
  // 可以由 path 构造, 有一个非 explicit 的类型转换运算符可以转换为 path
  std::transform(fs::directory_iterator{dir}, {}, std::back_inserter(items),
                 file_info);

  for (const auto &[path, size] : items) {
    fmt::print("{}{:<20}{:<20}{:<20}\n", type_char(path),
               rwx(fs::status(path).permissions()), size_string(size),
               path.filename().c_str());
  }
}
