//
// Created by kaiser on 19-3-22.
//

#include <filesystem>
#include <iostream>

namespace fs = std::filesystem;

int main() {
  // 创建目录 Test
  // 如果已存在则不做任何事
  // 如果成功创建了则返回 true
  fs::create_directory("Test");

  // 创建目录 Test/a
  // fs::create_directory("Test/a"); error
  fs::create_directories("Test/a");

  // 删除文件或空目录
  // 若文件被删除则返回 true , 若文件不存在则返回 false
  // fs::remove("Test");

  // 删除文件或目录
  // 返回被删除的文件及目录数量(可以是零. 若用以起始的 path 不存在)
  fs::remove_all("Test");
}
