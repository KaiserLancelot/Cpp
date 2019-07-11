//
// Created by kaiser on 19-7-11.
//

#include "main_window.h"

#include <QVBoxLayout>

MainWindow::MainWindow() : title_bar_{new TitleBar{this}} {
  setMinimumSize(2000, 1236);
  // 设置背景图片, 会自动拉伸
  setStyleSheet("border-image:url(:background);");
  // 生成无边框窗口, 无法通过窗口系统移动或调整无边框窗口的大小
  // Qt::WindowStaysOnTopHint 总在最前
  setWindowFlags(Qt::FramelessWindowHint | windowFlags());

  auto layout{new QVBoxLayout{this}};
  layout->addWidget(title_bar_);
  layout->addStretch();

  title_bar_->SetIcon(":logo");
}
