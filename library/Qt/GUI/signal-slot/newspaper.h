//
// Created by kaiser on 19-3-23.
//

#ifndef CPP_NEWSPAPER_H
#define CPP_NEWSPAPER_H

#include <string>

#include <QObject>

// 只有继承了 QObject 的类才有信号槽的能力
// 凡是 QObject类, 都应该在第一行代码写上 Q_OBJECT
// moc 只处理头文件中的标记了 Q_OBJECT 的类
// 这个宏的展开将为我们的类提供信号槽机制, 国际化机制以及 Qt 提供的
// 不基于 C++RTTI 的反射能力
class Newspaper : public QObject {
  Q_OBJECT
 public:
  explicit Newspaper(const std::string &name) : name_{name} {}
  void Send() { emit New(name_); }
  // signals: 是必不可少的
  // 而且不应该有函数定义
 signals:
  void New(const std::string &);
  void New(const std::string &, const std::string &);

 private:
  std::string name_;
};

#endif  // CPP_NEWSPAPER_H