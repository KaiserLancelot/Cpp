//
// Created by kaiser on 19-3-26.
//

#ifndef CPP_STUDY_SUMMARY_H
#define CPP_STUDY_SUMMARY_H

#include <QDebug>
#include <QEvent>
#include <QLabel>
#include <QObject>
#include <QWidget>

// 点击后会输出
// QApplication::eventFilter
// eventFilter
// event
// mousePressEvent

class Label : public QWidget {
  Q_OBJECT
 public:
  Label() { installEventFilter(this); }

  bool eventFilter(QObject *watched, QEvent *event) override {
    if (watched == this && event->type() == QEvent::MouseButtonPress) {
      qDebug() << "eventFilter";
      // 只输出但不过滤
      // return true;
    }
    return QWidget::eventFilter(watched, event);
  }

 protected:
  void mousePressEvent(QMouseEvent *) override {
    qDebug() << "mousePressEvent";
  }

  bool event(QEvent *event) override {
    if (event->type() == QEvent::MouseButtonPress) {
      qDebug() << "event";
      // 输出并继续分发
      // return true;
    }
    return QWidget::event(event);
  }
};

class EventFilter : public QObject {
  Q_OBJECT
 public:
  explicit EventFilter(QObject *watched, QObject *parent = nullptr)
      : QObject{parent}, watched_{watched} {}

  bool eventFilter(QObject *watched, QEvent *event) override {
    if (watched == watched_ && event->type() == QEvent::MouseButtonPress) {
      qDebug() << "QApplication::eventFilter";
      // 只输出但不过滤
      // return true;
    }
    return QObject::eventFilter(watched, event);
  }

 private:
  QObject *watched_;
};

#endif  // CPP_STUDY_SUMMARY_H
