//
// Created by kaiser on 19-3-22.
//

#ifndef CPP_MAINWINDOW_H
#define CPP_MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
  Q_OBJECT
 public:
  explicit MainWindow(QWidget *parent = nullptr);
};

#endif  // CPP_MAINWINDOW_H