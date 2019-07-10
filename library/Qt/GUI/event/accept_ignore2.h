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
    qDebug() << "CustomButtonEx";
    event->ignore();
  }
};

class CustomWidget : public QWidget {
  Q_OBJECT
 public:
  explicit CustomWidget(QWidget *parent) : QWidget(parent) {}

 protected:
  void mousePressEvent(QMouseEvent *event) override {
    qDebug() << "CustomWidget";
    event->ignore();
  }
};

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr) : QMainWindow(parent) {
    auto widget{new CustomWidget{this}};

    auto cb{new CustomButton{widget}};
    cb->setText("CustomButton");

    auto cb_ex{new CustomButtonEx{widget}};
    cb_ex->setText("CustomButtonEx");

    auto widgetLayout{new QVBoxLayout{widget}};
    widgetLayout->addWidget(cb);
    widgetLayout->addWidget(cb_ex);

    setCentralWidget(widget);
  }

 protected:
  void mousePressEvent(QMouseEvent *) override { qDebug() << "MainWindow"; }
};

#endif  // CPP_STUDY_ACCEPT_IGNORE2_H
