//
// Created by kaiser on 19-4-9.
//

#include <cstdlib>
#include <iostream>

#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QIODevice>

int main() {
  // file 析构时如果需要会关闭文件
  QFile file{"in.txt"};

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    std::cerr << "Open file failed\n";
    return EXIT_FAILURE;
  } else {
    while (!file.atEnd()) {
      std::cout << file.readLine().toStdString();
    }
  }

  std::cout << '\n';

  QFileInfo info{file};
  //  QFileInfo fi("/tmp/archive.tar.gz");
  //  QString base  = fi.baseName();  // base = "archive"
  //  QString cbase = fi.completeBaseName();  // cbase = "archive.tar"
  //  QString ext   = fi.suffix();  // ext = "gz"
  //  QString cext   = fi.completeSuffix();  //c ext = "tar.gz"
  std::cout << std::boolalpha << info.isDir() << '\n';
  std::cout << info.isExecutable() << '\n';
  std::cout << info.baseName().toStdString() << '\n';
  std::cout << info.completeBaseName().toStdString() << '\n';
  std::cout << info.suffix().toStdString() << '\n';
  std::cout << info.completeSuffix().toStdString() << '\n';

  // 程序工作目录
  std::cout << QDir::currentPath().toStdString() << '\n';
  // 返回该文件的路径, 不检查该文件是否存在
  std::cout << QDir::current().filePath("a.txt").toStdString() << '\n';
}
