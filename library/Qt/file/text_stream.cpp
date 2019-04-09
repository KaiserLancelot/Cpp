//
// Created by kaiser on 19-4-9.
//

#include <iostream>

#include <QFile>
#include <QIODevice>
#include <QString>
#include <QTextStream>

int main() {
  QFile data{"file.txt"};

  if (!data.open(QIODevice::WriteOnly | QIODevice::Truncate)) {
    std::cerr << "Open file failed\n";
    return EXIT_FAILURE;
  }

  // QTextStream 会自动将 Unicode 编码同操作系统的编码进行转换
  // 它也会对换行符进行转换
  QTextStream out{&data};

  // 设置编码
  out.setCodec("UTF-8");

  out << "The answer is " << 42;

  QString str;
  QTextStream(&str) << "The answer is " << 42;
  std::cout << str.toStdString() << '\n';
}
