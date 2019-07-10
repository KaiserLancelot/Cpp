//
// Created by kaiser on 19-3-23.
//

#ifndef CPP_ACCEPT_IGNORE_H
#define CPP_ACCEPT_IGNORE_H

#include <QDebug>
#include <QMouseEvent>
#include <QObject>
#include <QPushButton>
#include <QWidget>

class CustomButton : public QPushButton {
  Q_OBJECT
 public:
  explicit CustomButton(QWidget *parent = nullptr) : QPushButton{parent} {
    QObject::connect(this, &CustomButton::clicked, this,
                     &CustomButton::OnButtonClicked);
  }

 protected:
  // 事件默认是 accept 的
  // ignore 说明想让事件继续传播(给父组件而不是父类)
  // 事件的传播是在组件层次上面的, 而不是依靠类继承机制
  void mousePressEvent(QMouseEvent *event) override {
    if (event->button() == Qt::MouseButton::LeftButton) {
      qDebug() << "left";
    } else if (event->button() == Qt::MouseButton::RightButton) {
      qDebug() << "right";
    } else {
      // 注意只有左键才算 clicked
      event->ignore();
    }
  }

 private:
  static void OnButtonClicked() { qDebug() << "You clicked this!"; }
};

#endif  // CPP_ACCEPT_IGNORE_H
