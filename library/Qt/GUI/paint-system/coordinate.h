//
// Created by kaiser on 19-3-27.
//

#ifndef CPP_STUDY_COORDINATE_H
#define CPP_STUDY_COORDINATE_H

#include <QPainter>
#include <QWidget>

class Coordinate : public QWidget {
  Q_OBJECT
 public:
  explicit Coordinate(QWidget *parent = nullptr) : QWidget{parent} {
    resize(800, 600);
  }

 protected:
  void paintEvent(QPaintEvent *) override {
    QPainter painter(this);

    // 传给 QPainter 都是逻辑坐标
    // 使用给定的颜色以给定的宽度和高度填充从 (x, y) 开始的矩形
    painter.fillRect(10, 10, 50, 100, Qt::red);
    // 保存当前的状态, 和 restore 必须成对出现, 使用的是栈
    painter.save();
    // 坐标系向右平移 100px
    painter.translate(100, 0);
    painter.fillRect(10, 10, 50, 100, Qt::yellow);
    painter.restore();
    painter.save();
    painter.translate(300, 0);
    // 顺时针旋转 30 度
    painter.rotate(30);
    painter.fillRect(10, 10, 50, 100, Qt::green);
    painter.restore();
    painter.save();
    painter.translate(400, 0);
    // 横坐标单位放大 2 倍，纵坐标放大 3 倍
    painter.scale(2, 3);
    painter.fillRect(10, 10, 50, 100, Qt::blue);
    painter.restore();
    painter.save();
    painter.translate(600, 0);
    // 横向不变，纵向扭曲 1 倍
    painter.shear(0, 1);
    // cyan 青色
    painter.fillRect(10, 10, 50, 100, Qt::cyan);
    painter.restore();
  }
};

#endif  // CPP_STUDY_COORDINATE_H
