//
// Created by kaiser on 19-3-22.
//

#ifndef CPP_MAINWINDOW_H
#define CPP_MAINWINDOW_H

#include <QAction>
#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);

 private:
  void Open();
  QAction *open_action_;
};

#endif  // CPP_MAINWINDOW_H