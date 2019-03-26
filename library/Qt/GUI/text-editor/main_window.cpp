//
// Created by kaiser on 19-3-26.
//

#include "main_window.h"

#include <QApplication>
#include <QCloseEvent>
#include <QFileDialog>
#include <QFileInfo>
#include <QIcon>
#include <QMenuBar>
#include <QMessageBox>
#include <QStatusBar>
#include <QTextStream>
#include <QToolBar>

MainWindow::MainWindow() : text_edit_{new QPlainTextEdit{this}} {
  setWindowTitle("untitled.txt");
  resize(800, 600);

  setCentralWidget(text_edit_);

  CreateAction();
  CreateConnect();

  CreateMenu();
  CreateToolBar();
  statusBar()->showMessage(tr("Ready"));
}

void MainWindow::CreateAction() {
  // tr 可以返回翻译后的字符串, 用于国际化
  // & 使下一个字符对象的按键为快捷键(ALT + ...)
  auto new_icon{QIcon::fromTheme("document-new", QIcon{":/images/new.png"})};
  new_action_ = new QAction{new_icon, tr("&New"), this};
  new_action_->setShortcut(QKeySequence::New);
  new_action_->setStatusTip(tr("Create a new file"));

  auto open_icon{QIcon::fromTheme("document-open", QIcon{":/images/open.png"})};
  open_action_ = new QAction{open_icon, tr("&Open..."), this};
  open_action_->setShortcut(QKeySequence::Open);
  open_action_->setStatusTip(tr("Open an existing file"));

  auto save_icon{QIcon::fromTheme("document-save", QIcon{":/images/save.png"})};
  save_action_ = new QAction{save_icon, tr("&Save"), this};
  save_action_->setShortcut(QKeySequence::Save);
  save_action_->setStatusTip(tr("Save the document to disk"));

  save_as_action_ = new QAction{QIcon::fromTheme("document-save-as"),
                                tr("Save &As..."), this};
  save_as_action_->setShortcut(QKeySequence::SaveAs);
  save_as_action_->setStatusTip(tr("Save the document under a new name"));

  auto copy_icon{QIcon::fromTheme("edit-copy", QIcon{":/images/copy.png"})};
  copy_action_ = new QAction{copy_icon, tr("&Copy"), this};
  copy_action_->setShortcut(QKeySequence::Copy);
  copy_action_->setStatusTip(
      tr("Copy the current selection's contents to the clipboard"));

  auto cut_icon{QIcon::fromTheme("edit-cut", QIcon{":/images/cut.png"})};
  cut_action_ = new QAction{cut_icon, tr("Cu&t"), this};
  cut_action_->setShortcut(QKeySequence::Cut);
  cut_action_->setStatusTip(
      tr("Cut the current selection's contents to the clipboard"));

  auto paste_icon{QIcon::fromTheme("edit-paste", QIcon{":/images/paste.png"})};
  paste_action_ = new QAction{paste_icon, tr("&Paste"), this};
  paste_action_->setShortcut(QKeySequence::Paste);
  paste_action_->setStatusTip(
      tr("Paste the current selection's contents to the clipboard"));

  exit_action_ =
      new QAction{QIcon::fromTheme("application-exit"), tr("E&xit"), this};
  exit_action_->setShortcut(QKeySequence::Quit);
  exit_action_->setStatusTip(tr("Exit the application"));

  about_action_ = new QAction{tr("&About"), this};
  about_action_->setStatusTip(tr("Show the application's About box"));

  about_qt_action_ = new QAction{tr("About &Qt"), this};
  about_qt_action_->setStatusTip(tr("Show the Qt library's About box"));
}

void MainWindow::CreateMenu() {
  auto file_menu{menuBar()->addMenu(tr("&File"))};
  file_menu->addAction(new_action_);
  file_menu->addAction(open_action_);
  file_menu->addAction(save_action_);
  file_menu->addSeparator();
  file_menu->addAction(exit_action_);

  auto edit_menu{menuBar()->addMenu(tr("&Edit"))};
  edit_menu->addAction(cut_action_);
  edit_menu->addAction(copy_action_);
  edit_menu->addAction(paste_action_);

  auto help_menu{menuBar()->addMenu(tr("&Help"))};
  help_menu->addAction(about_action_);
  help_menu->addAction(about_qt_action_);
}

void MainWindow::CreateToolBar() {
  auto file_tool_bar{addToolBar(tr("File"))};
  file_tool_bar->addAction(new_action_);
  file_tool_bar->addAction(open_action_);
  file_tool_bar->addAction(save_action_);

  auto edit_tool_bar{addToolBar(tr("Edit"))};
  edit_tool_bar->addAction(cut_action_);
  edit_tool_bar->addAction(copy_action_);
  edit_tool_bar->addAction(paste_action_);
}

void MainWindow::CreateConnect() {
  connect(new_action_, &QAction::triggered, this, &MainWindow::New);
  connect(open_action_, &QAction::triggered, this, &MainWindow::Open);
  connect(save_action_, &QAction::triggered, this, &MainWindow::Save);
  connect(save_as_action_, &QAction::triggered, this, &MainWindow::SaveAs);

  connect(paste_action_, &QAction::triggered, text_edit_,
          &QPlainTextEdit::paste);
  connect(copy_action_, &QAction::triggered, text_edit_, &QPlainTextEdit::copy);
  connect(cut_action_, &QAction::triggered, text_edit_, &QPlainTextEdit::cut);

  connect(exit_action_, &QAction::triggered, this, &MainWindow::close);
  connect(about_action_, &QAction::triggered, this, &MainWindow::About);
  connect(about_qt_action_, &QAction::triggered, qApp, &QApplication::aboutQt);

  connect(text_edit_->document(), &QTextDocument::contentsChanged, this,
          &MainWindow::DocumentWasModified);
}

void MainWindow::New() {
  text_edit_->clear();
  file_path_.clear();
}

void MainWindow::Open() {
  if (IsSaved()) {
    file_path_ = QFileDialog::getOpenFileName(this);
    if (!file_path_.isEmpty()) {
      LoadFile();
    }
  }
}

void MainWindow::Save() {
  if (file_path_.isEmpty()) {
    SaveAs();
  } else {
    SaveFile();
  }
}

void MainWindow::SaveAs() {
  auto path{QFileDialog::getSaveFileName(this)};
  if (!path.isEmpty()) {
    QFile file{path};
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
      QMessageBox::warning(
          this, tr("Application"),
          tr("Cannot read file %1:\n%2.")
              .arg(QDir::toNativeSeparators(path), file.errorString()));
      return;
    }
    QTextStream stream{&file};
    stream << text_edit_->toPlainText();

    statusBar()->showMessage("File saved");
  }
}

void MainWindow::About() {
  QMessageBox::about(
      this, tr("About Application"),
      tr("The <b>Application</b> example demonstrates how to "
         "write modern GUI applications using Qt, with a menu bar, "
         "toolbars, and a status bar."));
}

void MainWindow::closeEvent(QCloseEvent *event) {
  if (IsSaved()) {
    event->accept();
  } else {
    event->ignore();
  }
}

bool MainWindow::IsSaved() {
  if (!text_edit_->document()->isModified()) {
    return true;
  } else {
    auto ret{QMessageBox::warning(
        this, tr("Application"),
        tr("The document has been modified.\n"
           "Do you want to save your changes?"),
        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel)};

    switch (ret) {
      case QMessageBox::Save:
        Save();
        break;
      case QMessageBox::Cancel:
        return false;
      default:
        break;
    }
  }
  return true;
}

void MainWindow::LoadFile() {
  QFile file{file_path_};
  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    QMessageBox::warning(
        this, tr("Application"),
        tr("Cannot read file %1:\n%2.")
            .arg(QDir::toNativeSeparators(file_path_), file.errorString()));
    return;
  }
  QTextStream stream{&file};
  text_edit_->setPlainText(stream.readAll());

  statusBar()->showMessage(tr("File loaded"), 2000);
}

void MainWindow::SaveFile() {
  QFile file{file_path_};
  if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
    QMessageBox::warning(
        this, tr("Application"),
        tr("Cannot read file %1:\n%2.")
            .arg(QDir::toNativeSeparators(file_path_), file.errorString()));
    return;
  }
  QTextStream stream{&file};
  stream << text_edit_->toPlainText();

  statusBar()->showMessage("File saved");
}

void MainWindow::DocumentWasModified() {
  setWindowModified(text_edit_->document()->isModified());
}
