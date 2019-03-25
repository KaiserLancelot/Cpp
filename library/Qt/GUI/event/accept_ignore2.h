//
// Created by kaiser on 19-3-25.
//

#ifndef CPP_STUDY_ACCEPT_IGNORE2_H
#define CPP_STUDY_ACCEPT_IGNORE2_H

#include <QDebug>
#include <QLayout>
#include <QMainWindow>
#include <QMouseEvent>
#include <QObject>
#include <QPushButton>

class CustomButton : public QPushButton {
  Q_OBJECT
 public:
  explicit CustomButton(QWidget *parent) : QPushButton(parent) {}

 protected:
  void mousePressEvent(QMouseEvent *) override { qDebug() << "CustomButton"; }
};

class CustomButtonEx : public CustomButton {
  Q_OBJECT
 public:
  explicit CustomButtonEx(QWidget *parent) : CustomButton(parent) {}

 protected:
  void mousePressEvent(QMouseEvent *event) override {
    event->ignore();
    qDebug() << "CustomButtonEx";
  }
};

class CustomWidget : public QWidget {
  Q_OBJECT
 public:
  explicit CustomWidget(QWidget *parent) : QWidget(parent) {}

 protected:
  void mousePressEvent(QMouseEvent *event) override {
    qDebug() << "CustomWidget";
    // 效果和 event->ignore() 相同
    // 它的实现会调用 event->ignore()
    QWidget::mousePressEvent(event);
  }
};

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
    auto widget{new CustomWidget{this}};

    auto cbex{new CustomButton{widget}};
    cbex->setText("CustomButton");

    auto cb{new CustomButtonEx{widget}};
    cb->setText("CustomButtonEx");

    auto widgetLayout{new QVBoxLayout{widget}};
    widgetLayout->addWidget(cbex);
    widgetLayout->addWidget(cb);

    this->setCentralWidget(widget);
  }

 protected:
  void mousePressEvent(QMouseEvent *) override { qDebug() << "MainWindow"; }
};

#endif  // CPP_STUDY_ACCEPT_IGNORE2_H