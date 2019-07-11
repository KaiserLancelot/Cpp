//
// Created by kaiser on 19-7-11.
//

#include "main_window.h"

#include <QMenu>
#include <QVBoxLayout>

MainWindow::MainWindow()
    : button_{new QPushButton{this}}, tool_button_{new QToolButton{this}} {
  setMinimumSize(1000, 800);
  auto layout{new QVBoxLayout{this}};
  layout->addWidget(button_);
  layout->addWidget(tool_button_);

  button_->setText("fuck");

  auto menu{new QMenu{this}};
  menu->addAction("you");
  menu->addSeparator();
  menu->addAction("me");

  button_->setMenu(menu);

  // Qt::ToolButtonIconOnly 只显示图标
  // Qt::ToolButtonTextOnly 只显示文本
  // Qt::ToolButtonTextBesideIcon 文本显示在图标旁边
  // Qt::ToolButtonTextUnderIcon 文本显示在图标下边
  // Qt::ToolButtonFollowStyle 遵循QStyle::StyleHint
  tool_button_->setToolButtonStyle(Qt::ToolButtonTextBesideIcon);
  tool_button_->setText("fuck");
  tool_button_->setIcon(QIcon{":search_normal"});

  // 设置按钮是否显示一个箭头, 而不是一个正常的图标.这将显示一个箭头作为
  // QToolButton 的图标 默认情况下, 这个属性被设置为Qt::NoArrow。
  tool_button_->setArrowType(Qt::UpArrow);

  // 设置默认的QAction, 该 action 会定义 QToolButton 的文本 图标
  // TooTip等按钮的属性
  // tool_button_->setDefaultAction()
}
