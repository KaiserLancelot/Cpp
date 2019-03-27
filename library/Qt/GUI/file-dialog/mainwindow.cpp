//
// Created by kaiser on 19-3-22.
//

#include "mainwindow.h"

#include <QDebug>
#include <QFileDialog>
#include <QIODevice>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QString>
#include <QTextStream>
#include <QToolBar>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent) {
  setMinimumSize(1200, 800);

  open_action_ = new QAction{QIcon{":/images/file-open.png"}, "Open", this};
  open_action_->setShortcut(QKeySequence::Open);
  open_action_->setStatusTip("Open an existing file");

  save_action_ = new QAction{QIcon{":/images/file-save.png"}, "Save", this};
  save_action_->setShortcut(QKeySequence::Save);
  save_action_->setStatusTip("Save a new file");

  // triggered 触发
  QObject::connect(open_action_, &QAction::triggered, this, &MainWindow::Open);
  QObject::connect(save_action_, &QAction::triggered, this, &MainWindow::Save);

  // menuBar 返回或创建一个菜单栏(只能有一个), addMenu 添加了一个菜单
  auto menu{menuBar()->addMenu("File")};
  menu->addAction(open_action_);
  menu->addAction(save_action_);

  // 添加一个工具栏
  auto tool_bar{addToolBar("File")};
  tool_bar->addAction(open_action_);
  tool_bar->addAction(save_action_);

  // 同 menuBar
  statusBar();

  // QTextEdit 不仅仅用于显示文本, 还可以显示图片, 表格等
  text_edit_ = new QTextEdit{this};
  text_edit_->setFontPointSize(18);
  // 将一个组件作为窗口的中心组件, 放在窗口中央显示区
  setCentralWidget(text_edit_);

  QObject::connect(text_edit_, &QTextEdit::textChanged, this,
                   [this] { setWindowModified(true); });
  // 使用 [] 这种语法来表明, 在窗口内容发生
  // 改变时(由 setWindowModified 函数通知)
  // Qt 会自动在标题上面的 [] 位置替换成 * 号
  // 注意设置了 setWindowModified 则 Title 中必须有 []
  setWindowTitle("TextPad [*]");
}

void MainWindow::Open() {
  /*
   * static QString getOpenFileName(QWidget *parent = nullptr,
   *                                const QString &caption = QString(),
   *                                const QString &dir = QString(),
   *                                const QString &filter = QString(),
   *                                QString *selectedFilter = nullptr,
   *                                Options options = Options());
   */

  // parent 父窗口, caption 对话框标题, dir 默认目录
  // filter 过滤器, 用于过滤特定的后缀名, 如果有多个则使用 ;; 分割
  // selectedFilter 默认的过滤器, options 参数设定，比如只显示文件夹等
  // 具体见 QFileDialog::Option
  // 返回选择的文件路径

  //  QString default_filter{"Image(*.jpg)"};
  //  auto path{QFileDialog::getOpenFileName(this, "Open file", ".",
  //                                         "Text Files(*.txt);;Image(*.jpg)",
  //                                         &default_filter)};

  auto path{
      QFileDialog::getOpenFileName(this, "Open file", ".", "All Files(*)")};
  if (!path.isEmpty()) {
    QFile file{path};
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
      QMessageBox::warning(this, "Read File",
                           tr("Cannot open file:\n%1").arg(path));
      return;
    }
    QTextStream in{&file};
    text_edit_->setText(in.readAll());
    file.close();
  }
}

void MainWindow::Save() {
  auto path{QFileDialog::getSaveFileName(this, "Open file", ".",
                                         "Text Files(*.txt)")};

  if (!path.isEmpty()) {
    QFile file{path};
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QMessageBox::warning(this, "Write File",
                           tr("Cannot open file:\n%1").arg(path));
      return;
    }
    QTextStream out{&file};
    out << text_edit_->toPlainText();
    file.close();
  } else {
    QMessageBox::warning(this, "Path", "You did not select any file.");
  }
}

void MainWindow::closeEvent(QCloseEvent *event) {
  if (isWindowModified()) {
    auto exit{QMessageBox::question(
        this, "Quit", "Are you sur to quit this application",
        QMessageBox::Yes | QMessageBox::No, QMessageBox::No)};
    // 对于窗口关闭 QCloseEvent 事件, 调用 accept() 意味
    // 着会停止事件的传播, 窗口关闭;调用 ignore() 则意味着
    // 事件继续传播, 即阻止窗口关闭
    if (exit) {
      event->accept();
    } else {
      event->ignore();
    }
  } else {
    event->accept();
  }
}