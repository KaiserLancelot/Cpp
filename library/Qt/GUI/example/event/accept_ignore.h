//
// Created by kaiser on 19-3-23.
//

#ifndef CPP_ACCEPT_IGNORE_H
#define CPP_ACCEPT_IGNORE_H

#include <QDebug>
#include <QMouseEvent>
#include <QObject>
#include <QPushButton>

class CustomButton : public QPushButton {
  Q_OBJECT
 public:
  explicit CustomButton(QWidget *parent = nullptr) : QPushButton{parent} {
    QObject::connect(this, &CustomButton::clicked, this,
                     &CustomButton::OnButtonClicked);
  }

 protected:
  void mousePressEvent(QMouseEvent *event) override {
    if (event->button() == Qt::LeftButton) {
      qDebug() << "left";
    } else {
      QPushButton::mousePressEvent(event);
    }
  }

 private:
  void OnButtonClicked() { qDebug() << "You clicked this!"; }
};

#endif  // CPP_ACCEPT_IGNORE_H