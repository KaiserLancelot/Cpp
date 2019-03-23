//
// Created by kaiser on 19-3-23.
//

#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QWidget>

int main(int argc, char *argv[]) {
  QApplication app{argc, argv};

  QWidget window;
  window.setWindowTitle("Enter your age");
  window.setMinimumSize(1200, 800);

  // QSpinBox 只能输入数字的输入框, 并且带有上下箭头的步进按钮
  auto spin_box{new QSpinBox{&window}};
  // QSlider 带有滑块的滑竿, Orientation取向, Horizontal横, Vertical竖
  auto slider{new QSlider{Qt::Orientation::Horizontal, &window}};
  // 设置范围
  spin_box->setRange(0, 130);
  slider->setRange(0, 130);

  QObject::connect(slider, &QSlider::valueChanged, spin_box,
                   &QSpinBox::setValue);
  // QSpinBox::valueChanged 还有一个接受 const QString & 的重载,
  // 所以不能直接使用
  void (QSpinBox::*spin_box_signal)(int){&QSpinBox::valueChanged};
  QObject::connect(spin_box, spin_box_signal, slider, &QSlider::setValue);
  // 设置默认值
  spin_box->setValue(35);

  // 一个布局管理器, 按照水平方向从左到右布局
  // 保持 QSpinBox 宽度不变, 自动拉伸 QSlider 的宽度
  auto layout{new QHBoxLayout};
  // 添加到这个布局管理器
  layout->addWidget(spin_box);
  layout->addWidget(slider);
  // 把该布局管理器设置为窗口的布局管理器
  window.setLayout(layout);

  window.show();

  QApplication::exec();
}