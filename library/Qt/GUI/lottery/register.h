//
// Created by kaiser on 19-4-16.
//

#ifndef CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_REGISTER_H_
#define CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_REGISTER_H_

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class Register : public QDialog {
 public:
  explicit Register(QWidget *parent = nullptr);

 private:
  QLabel *username_label_;
  QLabel *password_label_;
  QLabel *password_confirm_label_;
  QLineEdit *username_;
  QLineEdit *password_;
  QLineEdit *password_confirm_;
  QPushButton *register_;

 private slots:
  void OnClickRegister();
};

#endif  // CPP_STUDY_LIBRARY_QT_GUI_LOTTERY_REGISTER_H_
