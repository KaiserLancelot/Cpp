//
// Created by kaiser on 19-3-26.
//

#ifndef CPP_STUDY_PAINT_H
#define CPP_STUDY_PAINT_H

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>

// QPainter 用来执行绘制的操作; QPaintDevice 是
// 一个二维空间的抽象, 这个二维空间允许 QPainter 在上面进行绘制
// 它们之间使用 QPaintEngine 进行通讯
class Paint : public QWidget {
  Q_OBJECT
 public:
  explicit Paint(QWidget *parent = nullptr) : QWidget{parent} {
    resize(800, 600);
    setWindowTitle("Paint Demo");
  }

 protected:
  // 在需要重绘时由 Qt 自动调用
  // 比如组件刚刚创建出来的时候就需要重绘;组件最大化, 最小化
  // 的时候也需要重绘;组件由遮挡变成完全显示的时候也需要等等
  void paintEvent(QPaintEvent *) override {
    // 接收一个 QPaintDevice 指针作为参数
    // QPaintDevice 有很多子类, 比如 QImage,
    // 以及QWidget. QPaintDevice 可以理解成要在哪里去绘制,
    // 而现在我们希望画在这个组件,因此传入的是 this 指针
    QPainter painter{this};
    painter.drawLine(80, 100, 650, 500);
    // 当绘制轮廓线时使用
    // 该属性会一直保持, 除非再调用它来更新状态
    painter.setPen(Qt::GlobalColor::red);

    // 矩形
    painter.drawRect(10, 10, 100, 400);
    painter.setPen(QPen{Qt::GlobalColor::green, 5});
    // 设置画刷(填充)为蓝色
    painter.setBrush(Qt::GlobalColor::blue);
    // 椭圆
    painter.drawEllipse(50, 150, 400, 200);
    // 注意 painter 将按顺序绘制
  }
};

#endif  // CPP_STUDY_PAINT_H
