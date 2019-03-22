//
// Created by kaiser on 19-3-22.
//

#include "mainwindow.h"

#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setMinimumSize(1200, 800);
  setWindowTitle("Main Window");

  open_action_ = new QAction{QIcon{"images/doc-open.png"}, "Open", this};
  open_action_->setShortcut(QKeySequence::Open);
  open_action_->setStatusTip("Open an existing file");
  // triggered 触发
  QObject::connect(open_action_, &QAction::triggered, this, &MainWindow::Open);

  auto menu{menuBar()->addMenu("File")};
  menu->addAction(open_action_);

  auto tool_bar{addToolBar("File")};
  tool_bar->addAction(open_action_);

  statusBar();
}

void MainWindow::Open() {
  QMessageBox::information(this, "Information", "Open");
}