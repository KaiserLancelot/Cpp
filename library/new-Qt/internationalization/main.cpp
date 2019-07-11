//
// Created by kaiser on 19-7-11.
//

#include <QApplication>
#include <QObject>
#include <QSettings>
#include <QTranslator>

#include "main_Widget.h"

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  QApplication::setAttribute(Qt::AA_UseHighDpiPixmaps);
  QApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
  // 设置组织名, 组织域名, 程序名, QSettings 会使用他们
  QApplication::setOrganizationName(QObject::tr("Kaiser"));
  QApplication::setOrganizationDomain("www");
  QApplication::setApplicationName(QObject::tr("Test"));

  QTranslator translator;
  QTranslator sys_translator;

  // QSettings::NativeFormat 使用平台最合适的存储格式设置
  // QSettings::IniFormat 存储在INI文件中的设置。
  // QSettings::InvalidFormat registerFormat()返回的值

  // QSettings::UserScope 在一个位置存储特定当前用户的设置(例如用户的主目录)
  // QSettings::SystemScope 在一个全局位置存储设置
  QSettings settings;
  // contains() 判断一个指定的键是否存在
  // remove()   删除相关的键
  // allKeys()  获取所有键
  // clear()    删除所有键
  settings.beginGroup("General");
  auto language{settings.value("language").toString()};

  if (language.isEmpty() || language == "chinese") {
    // 使用 linguist 编辑 .ts 文件
    translator.load(":zh-CN");
    QApplication::installTranslator(&translator);
    // 这个可以翻译 Qt 提供的标题, 右键菜单等
    sys_translator.load(":qt_zh_CN");
    QApplication::installTranslator(&sys_translator);
  } else {
    translator.load(":en-US");
    QApplication::installTranslator(&translator);
    sys_translator.load(":qt_en");
    QApplication::installTranslator(&sys_translator);
  }

  MainWidget main_widget;
  main_widget.SetTranslator(&translator);
  main_widget.SetSysTranslator(&sys_translator);

  if (language.isEmpty() || language == "chinese") {
    main_widget.SetLanguage(Language::kChinese);
  } else {
    main_widget.SetLanguage(Language::kEnglish);
  }

  main_widget.show();

  return QApplication::exec();
}
