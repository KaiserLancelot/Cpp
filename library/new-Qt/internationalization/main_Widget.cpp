//
// Created by kaiser on 19-7-11.
//

#include "main_Widget.h"

#include <QGridLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include <QDebug>

MainWidget::MainWidget()
    : label_{new QLabel{"fuck you", this}},
      setting_{new QPushButton{this}},
      determine_{new QPushButton{this}},
      cancel_{new QPushButton{this}} {
  resize(1000, 600);

  auto button_layout{new QHBoxLayout};
  button_layout->addWidget(setting_);
  button_layout->addWidget(determine_);
  button_layout->addWidget(cancel_);

  label_->setStyleSheet("QLabel { background-color : red; color : blue; }");
  label_->setAlignment(Qt::AlignCenter);
  auto label_layout{new QVBoxLayout};
  auto verticalSpacer1 =
      new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
  auto verticalSpacer2 =
      new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);
  label_layout->addItem(verticalSpacer1);
  label_layout->addWidget(label_);
  label_layout->addItem(verticalSpacer2);

  auto main_layout{new QGridLayout{this}};
  main_layout->addLayout(label_layout, 2, 5);
  main_layout->addLayout(button_layout, 5, 6);
}
