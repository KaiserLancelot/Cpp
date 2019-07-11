//
// Created by kaiser on 19-7-11.
//

#include <QApplication>
#include <QTranslator>

#include "main_Widget.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

  // 使用 linguist 编辑 .ts 文件
  QTranslator translator;
  translator.load(":zh-CN");
  QApplication::installTranslator(&translator);

  QTranslator sys_translator;
  // 这个可以翻译 Qt 提供的标题, 右键菜单等
  sys_translator.load(":qt_zh_CN");
  QApplication::installTranslator(&sys_translator);

  MainWidget main_widget;
  main_widget.SetTranslator(&translator);
  main_widget.SetSysTranslator(&sys_translator);
  main_widget.SetLanguage(Language::kChinese);
  main_widget.show();

  QApplication::exec();
}
