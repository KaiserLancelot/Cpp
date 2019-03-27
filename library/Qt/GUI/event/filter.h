//
// Created by kaiser on 19-3-26.
//

#ifndef CPP_STUDY_FILTER_H
#define CPP_STUDY_FILTER_H

#include <QDebug>
#include <QKeyEvent>
#include <QMainWindow>
#include <QTextEdit>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  MainWindow() {
    text_edit_ = new QTextEdit{this};
    setCentralWidget(text_edit_);
    // 第一个安装的会第一个执行
    // 如果给 QApplication 安装, 则对程序中每一个对象都有效
    text_edit_->installEventFilter(this);
  }

  bool eventFilter(QObject *watched, QEvent *event) override {
    if (auto key_event{dynamic_cast<QKeyEvent *>(event)};
        watched == text_edit_ && key_event &&
        key_event->key() == Qt::Key::Key_Tab) {
      qDebug() << "You press tab";
      // 过滤掉了, 返回 true
      return true;
    } else {
      return QMainWindow::eventFilter(watched, event);
    }
  }

 private:
  QTextEdit *text_edit_;
};

#endif  // CPP_STUDY_FILTER_H
