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

  auto spin_box{new QSpinBox{&window}};
  auto slider{new QSlider{Qt::Horizontal, &window}};
  spin_box->setRange(0, 130);
  slider->setRange(0, 130);

  QObject::connect(slider, &QSlider::valueChanged, spin_box,
                   &QSpinBox::setValue);
  void (QSpinBox::*spin_signal)(int){&QSpinBox::valueChanged};
  QObject::connect(spin_box, spin_signal, slider, &QSlider::setValue);
  spin_box->setValue(35);

  auto layout{new QHBoxLayout};
  layout->addWidget(spin_box);
  layout->addWidget(slider);
  window.setLayout(layout);

  window.show();

  QApplication::exec();
}