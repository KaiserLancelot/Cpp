//
// Created by kaiser on 19-3-25.
//

#ifndef CPP_STUDY_EVENT_H
#define CPP_STUDY_EVENT_H

#include <QDebug>
#include <QEvent>
#include <QKeyEvent>
#include <QWidget>

class CustomWidget : public QWidget {
  Q_OBJECT
 public:
  explicit CustomWidget(QWidget *parent = nullptr) : QWidget{parent} {}

 protected:
  // 事件对象创建完毕后, Qt 将这个事件对象
  // 传递给 QObject 的 event() 函数. event() 函数
  // 并不直接处理事件, 而是将这些事件对象按照它们不同
  // 的类型, 分发给不同的事件处理器

  // event() 函数主要用于事件的分发.所以, 如果你希望在
  // 事件分发之前做一些操作, 就可以重写这个event()函数

  // 如果传入的事件已被识别并且处理, 则返回 true

  // 注意在 event() 函数中, 调用事件对象的 accept() 和 ignore()
  // 函数是没有作用的, 不会影响到事件的传播
  bool event(QEvent *event) override {
    if (auto key_event{dynamic_cast<QKeyEvent *>(event)};
        key_event->key() == Qt::Key::Key_Tab) {
      qDebug() << "You press tab";
      return true;
    } else {
      // 如果没有调用, 则只有处理上面的事件
      return QWidget::event(event);
    }
  }
};

#endif  // CPP_STUDY_EVENT_H