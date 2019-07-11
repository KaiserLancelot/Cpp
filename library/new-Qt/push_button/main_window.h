//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_PUSH_BUTTON_MAIN_WINDOW_H_
#define CPP_STUDY_LIBRARY_NEW_QT_PUSH_BUTTON_MAIN_WINDOW_H_

#include <QPushButton>
#include <QToolButton>
#include <QWidget>

class MainWindow : public QWidget {
  Q_OBJECT
 public:
  MainWindow();

 private:
  QPushButton *button_;
  QToolButton *tool_button_;
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_PUSH_BUTTON_MAIN_WINDOW_H_
