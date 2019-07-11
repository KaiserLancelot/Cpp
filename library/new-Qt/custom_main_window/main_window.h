//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_MAIN_WINDOW_MAIN_WINDOW_H_
#define CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_MAIN_WINDOW_MAIN_WINDOW_H_

#include <QWidget>

#include "title_bar.h"

class MainWindow : public QWidget {
  Q_OBJECT
 public:
  MainWindow();

 private:
  TitleBar *title_bar_;
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_CUSTOM_MAIN_WINDOW_MAIN_WINDOW_H_
