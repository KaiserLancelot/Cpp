//
// Created by kaiser on 19-3-22.
//

#include "mainwindow.h"
#include "../file-dialog/mainwindow.h"

#include <QDebug>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setMinimumSize(1200, 800);
  setWindowTitle("Main Window");

  open_action_ = new QAction{QIcon{":/images/doc-open.png"}, "Open", this};
  open_action_->setShortcut(QKeySequence::Open);
  open_action_->setStatusTip("Open an existing file");
  // triggered 触发
  QObject::connect(open_action_, &QAction::triggered, this, &MainWindow::Open);

  // menuBar 返回或创建一个菜单栏(只能有一个), addMenu 添加了一个菜单
  auto menu{menuBar()->addMenu("File")};
  menu->addAction(open_action_);

  // 添加一个工具栏
  auto tool_bar{addToolBar("File")};
  tool_bar->addAction(open_action_);

  // 同 menuBar
  statusBar();
}

void MainWindow::Open() {
  // 最后一个参数指定默认选择的按钮, 不指定默认为 YES
  //  if (QMessageBox::question(this, "Question", "Are you OK",
  //                            QMessageBox::Yes | QMessageBox::No,
  //                            QMessageBox::No) == QMessageBox::Yes) {
  //    QMessageBox::information(this, "Hmmm...", "I'm glad to hear that");
  //  } else {
  //    QMessageBox::information(this, "Hmmm...", "I'm sorry!");
  //  }

  auto msg_box{new QMessageBox{this}};
  // 主要文本信息
  msg_box->setText("The document has been modified");
  // 显示的简单说明文字
  msg_box->setInformativeText("Do you want to save your change");
  // 显示详细信息, 这会增加一个按钮
  msg_box->setDetailedText("Differences here...");
  msg_box->setStandardButtons(QMessageBox::Save | QMessageBox::Discard |
                              QMessageBox::Cancel);
  msg_box->setDefaultButton(QMessageBox::Save);

  auto ret{msg_box->exec()};

  switch (ret) {
    case QMessageBox::Save:
      qDebug() << "Save document!";
      break;
    case QMessageBox::Discard:
      qDebug() << "Discard changes!";
      break;
    case QMessageBox::Cancel:
      qDebug() << "Close document!";
      break;
    default: {}
  }
}