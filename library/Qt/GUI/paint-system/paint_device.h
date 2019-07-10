//
// Created by kaiser on 19-3-27.
//

#ifndef CPP_STUDY_PAINT_DEVICE_H
#define CPP_STUDY_PAINT_DEVICE_H

#include <QBitmap>
#include <QImage>
#include <QPainter>
#include <QPicture>
#include <QPixmap>
#include <QWidget>

class PaintDevice : public QWidget {
 public:
  explicit PaintDevice(QWidget* parent = nullptr) : QWidget{parent} {}

 protected:
  void paintEvent(QPaintEvent*) override {
    QPainter painter(this);
    // QPixmap 继承了 QPaintDevice , 专门为图像在屏幕上的显示做了优化
    // QBitmap 是 QPixmap 的一个子类, 它的色深限定为 1 (黑白),
    // 占用的空间比较小
    // 适合做光标文件和笔刷
    // QPixmap 内置了隐式数据共享
    QPixmap pixmap(":icon");
    QBitmap bitmap(":icon");
    // 绘制这个图像
    painter.drawPixmap(10, 10, 250, 125, pixmap);
    painter.drawPixmap(270, 10, 250, 125, bitmap);

    // QPixmap 使用底层平台的绘制系统进行绘制, 无法提供像素级别的操作
  }
};

#endif  // CPP_STUDY_PAINT_DEVICE_H
