//
// Created by kaiser on 19-4-15.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_LOGIN_H_
#define CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_LOGIN_H_

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QString>

class Login : public QDialog {
 public:
  explicit Login(QWidget *parent = nullptr);
  QString GetUsername() const { return username_str_; }

 private:
  QLabel *username_label_;
  QLabel *password_label_;
  QLineEdit *username_;
  QLineEdit *password_;
  QPushButton *login_;
  QPushButton *register_;

  QString username_str_;
  QString password_str_;

 private slots:
  void OnClickLogin();
  void OnClickRegister();
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_LOGIN_H_
