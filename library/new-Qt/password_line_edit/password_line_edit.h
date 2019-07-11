//
// Created by kaiser on 19-7-11.
//

#ifndef CPP_STUDY_LIBRARY_NEW_QT_PASSWORD_LINE_EDIT_PASSWORD_LINE_EDIT_H_
#define CPP_STUDY_LIBRARY_NEW_QT_PASSWORD_LINE_EDIT_PASSWORD_LINE_EDIT_H_

#include <QLineEdit>
#include <QWidget>

class PasswordLineEdit : public QLineEdit {
  Q_OBJECT
 public:
  explicit PasswordLineEdit(QWidget *parent = nullptr);

 private:
};

#endif  // CPP_STUDY_LIBRARY_NEW_QT_PASSWORD_LINE_EDIT_PASSWORD_LINE_EDIT_H_
