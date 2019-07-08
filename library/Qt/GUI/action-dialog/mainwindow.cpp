//
// Created by kaiser on 19-3-22.
//

#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QDialog>
#include <QMenuBar>
#include <QScreen>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  // 获取主屏幕的可用几何(也就是获取了分辨率)
  auto rect{QApplication::primaryScreen()->availableGeometry()};
  // 设置最小大小
  setMinimumSize(rect.width() / 2, rect.height() / 2);
  // 设置主窗口的标题
  setWindowTitle("Main Window");

  // 以:开始意味着从资源文件中查找资源
  // tr() 是一个用于 Qt 国际化的函数, 可以使用 Qt 提供的国际化工具
  // 将 tr() 函数的字符串提取出来, 进行国际化.
  // tr() 函数里面一般是英文文本
  // 某符号前有一个 &, 这意味着该符号成为一个快捷键
  open_action_ = new QAction{QIcon{":doc-open"}, tr("&Open"), this};
  open_action_->setShortcut(QKeySequence::Open);
  open_action_->setStatusTip("Open an existing file");
  // triggered 触发
  QObject::connect(open_action_, &QAction::triggered, this, &MainWindow::Open);

  // menuBar 返回或创建一个菜单栏(只能有一个), addMenu 添加了一个菜单
  auto menu{menuBar()->addMenu("&File")};
  menu->addAction(open_action_);

  // 添加一个工具栏
  auto tool_bar{addToolBar("File")};
  tool_bar->addAction(open_action_);

  // 同 menuBar
  statusBar();
}

void MainWindow::Open() {
  // 对话框分为模态对话框和非模态对话框.所谓模态对话框,
  // 就是会阻塞同一应用程序中其它窗口的输入,
  // 不能对除此对话框之外的窗口部分进行操作
  // 非模态对话框与之相反

  // Qt 有两种级别的模态对话框:应用程序级别的模态和窗口级别的模态
  // 应用程序级别的模态是指, 当该种模态的对话框出现时, 用户必须首先
  // 对对话框进行交互, 直到关闭对话框, 然后才能访问程序中其他的窗口.
  // 窗口级别的模态是指, 该模态仅仅阻塞与对话框关联的窗口, 但是依然允许
  // 用户与程序中其它窗口交互.窗口级别的模态尤其适用于多窗口模式

  // 设置为子对话框, 默认出现在父窗口的中心
  QDialog dialog{this};

  dialog.setMinimumSize(500, 400);
  dialog.setWindowTitle("Hello dialog");

  // Qt 使用 QDialog::exec() 实现应用程序级别的模态对话框,
  // 使用 QDialog::open() 实现窗口级别的模态对话框,
  // 使用 QDialog::show() 实现非模态对话框, 不会阻塞当前线程
  dialog.exec();
  // 如果使用 QDialog::show() 并且 dialog 分配在栈上, 窗口会一闪而过
  // 该函数立即返回, dialog 之后就析构了

  // 直到对话框关闭, exec() 函数返回, 我们才可以取得对话框的数据
  qDebug() << dialog.result();
}