//
// Created by kaiser on 19-3-22.
//

#ifndef CPP_MAINWINDOW_H
#define CPP_MAINWINDOW_H

#include <QAction>
#include <QMainWindow>
#include <QTextEdit>
#include <QCloseEvent>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);

 protected:
  void closeEvent(QCloseEvent *event) override;

 private:
  void Open();
  void Save();

  QAction *open_action_;
  QAction *save_action_;
  QTextEdit *text_edit_;
};

#endif  // CPP_MAINWINDOW_H