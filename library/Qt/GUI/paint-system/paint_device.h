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
    //    // QPixmap 继承了 QPaintDevice , 专门为图像在屏幕上的显示做了优化
    //    // QBitmap 是 QPixmap 的一个子类, 它的色深限定为 1 (黑白),
    //    占用的空间比较小
    //    // 适合做光标文件和笔刷
    //    // QPixmap 内置了隐式数据共享
    //    QPixmap pixmap(":/images/icon.png");
    //    QBitmap bitmap(":/images/icon.png");
    //    // 绘制这个图像
    //    painter.drawPixmap(10, 10, 250, 125, pixmap);
    //    painter.drawPixmap(270, 10, 250, 125, bitmap);

    //    // QPixmap 使用底层平台的绘制系统进行绘制, 无法提供像素级别的操作
    //    // 而 QImage 是使用独立于硬件的绘制系统, 提供了像素级别的操作
    //    // 并且能够在不同系统之上提供一个一致的显示形式
    //    // 这时 image 包含未初始化的数据, 使用32位RGB格式
    //    QImage image{3, 3, QImage::Format_RGB32};
    //    QRgb value{qRgb(189, 49, 9)};
    //    image.setPixel(1, 1, value);
    //
    //    value = qRgb(122, 63, 9);
    //    image.setPixel(0, 1, value);
    //    image.setPixel(1, 0, value);
    //
    //    value = qRgb(237, 187, 51);
    //    image.setPixel(2, 1, value);
    //
    //    // 设定窗口坐标, 窗口大小不变, 相当于等比例的放大/缩小
    //    painter.setWindow(0, 0, 6, 6);
    //    painter.drawImage(1, 1, image);

    // QPicture 可以记录和重现 QPainter 的各条命令
    // QPicture 是平台无关的, 可以使用在多种设备上, 使用系统分辨率
    QPicture picture;
    // 在 picture 进行绘制
    painter.begin(&picture);
    painter.drawEllipse(10, 20, 80, 70);
    // 绘制完成
    painter.end();
    // 保存 picture (以文件形式)
    picture.save("drawing.pic");

    // 如果要重现命令, 首先要使用 QPicture::load() 函数进行装载
  }
};

#endif  // CPP_STUDY_PAINT_DEVICE_H
