//
// Created by kaiser on 19-7-10.
//

#include <QApplication>
#include <QLabel>
#include <QObject>
#include <QTranslator>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  // 使用 linguist 编辑 .ts 文件
  QTranslator translator;
  translator.load(":zh-CN");
  QApplication::installTranslator(&translator);

  QLabel label{QObject::tr("Hello World")};
  label.resize(100, 100);
  label.show();

  QApplication::exec();
}
