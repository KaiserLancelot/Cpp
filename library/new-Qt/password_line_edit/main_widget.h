//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_PASSWORD_LINE_EDIT_MAIN_WIDGET_H_
#define CPP_STUDY_LIBRARY_NEW_QT_PASSWORD_LINE_EDIT_MAIN_WIDGET_H_

#include <QLineEdit>
#include <QWidget>

#include "password_line_edit.h"

class MainWidget : public QWidget {
  Q_OBJECT
 public:
  MainWidget();

 private:
  QLineEdit *normal_;
  PasswordLineEdit *custom_;
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_PASSWORD_LINE_EDIT_MAIN_WIDGET_H_
