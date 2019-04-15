//
// Created by kaiser on 19-4-15.
//

#include "login.h"

#include <cstdlib>

#include <QApplication>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVBoxLayout>

Login::Login(QWidget *parent)
    : QDialog{parent},
      username_label_{new QLabel{"用户名: ", this}},
      password_label_{new QLabel{"密码:     ", this}},
      username_{new QLineEdit{this}},
      password_{new QLineEdit{this}},
      login_{new QPushButton{"登录", this}},
      register_{new QPushButton{"注册", this}} {
  setWindowTitle("登录");

  auto username_layout{new QHBoxLayout};
  username_layout->addWidget(username_label_);
  username_layout->addWidget(username_);

  auto password_layout{new QHBoxLayout};
  password_layout->addWidget(password_label_);
  password_layout->addWidget(password_);

  auto button_layout{new QHBoxLayout};
  button_layout->addWidget(login_);
  button_layout->addWidget(register_);

  auto main_layout{new QVBoxLayout};
  main_layout->addLayout(username_layout);
  main_layout->addLayout(password_layout);
  main_layout->addLayout(button_layout);

  setLayout(main_layout);

  connect(login_, &QPushButton::clicked, this, &Login::OnClickLogin);
  connect(register_, &QPushButton::clicked, this, &Login::OnClickRegister);
}

void Login::OnClickLogin() {
  username_str_ = username_->text();
  password_str_ = password_->text();

  if (username_str_.isEmpty() || password_str_.isEmpty()) {
    QMessageBox::warning(this, "警告", "用户名或密码为空");
  }

  auto db{QSqlDatabase::addDatabase("QMYSQL")};
  db.setHostName("localhost");
  db.setUserName("root");
  db.setPassword("524321");
  db.setDatabaseName("lottery");

  if (!db.open()) {
    QMessageBox::critical(this, "错误", "无法连接用户数据库");
    QApplication::exit(EXIT_FAILURE);
  }

  QSqlQuery query;
  if (!query.exec("select password from user where username='" + username_str_ +
                  "'")) {
    QMessageBox::critical(this, "错误",
                          "查询用户数据库失败\n" + query.lastError().text());
    QApplication::exit(EXIT_FAILURE);
  }

  if (query.next()) {
    if (query.value("password").toString() != password_str_) {
      QMessageBox::critical(this, "错误", "密码错误");
      password_->clear();
    } else {
      QMessageBox::information(this, "提示", "登录成功");
      accept();
    }
  } else {
    QMessageBox::critical(this, "错误", "该用户不存在");
    username_->clear();
    password_->clear();
  }
}

void Login::OnClickRegister() {
  QMessageBox::warning(this, "警告", "暂时不支持注册功能");
}
