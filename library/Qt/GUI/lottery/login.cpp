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

#include "register.h"

Login::Login(QWidget *parent)
    : QDialog{parent},
      username_label_{new QLabel{"用户名: ", this}},
      password_label_{new QLabel{"密码:     ", this}},
      username_{new QLineEdit{this}},
      password_{new QLineEdit{this}},
      login_{new QPushButton{"登录", this}},
      register_{new QPushButton{"注册", this}},
      try_out_{new QPushButton{"试用", this}} {
  setWindowTitle("登录");
  password_->setEchoMode(QLineEdit::Password);

  auto username_layout{new QHBoxLayout};
  username_layout->addWidget(username_label_);
  username_layout->addWidget(username_);

  auto password_layout{new QHBoxLayout};
  password_layout->addWidget(password_label_);
  password_layout->addWidget(password_);

  auto button_layout{new QHBoxLayout};
  button_layout->addWidget(login_);
  button_layout->addWidget(register_);
  button_layout->addWidget(try_out_);

  auto main_layout{new QVBoxLayout};
  main_layout->addLayout(username_layout);
  main_layout->addLayout(password_layout);
  main_layout->addLayout(button_layout);

  setLayout(main_layout);

  connect(login_, &QPushButton::clicked, this, &Login::OnClickLogin);
  connect(register_, &QPushButton::clicked, this, &Login::OnClickRegister);
  connect(try_out_, &QPushButton::clicked, this, &Login::OnClickTryOut);
}

void Login::OnClickLogin() {
  auto username{username_->text()};
  auto password{password_->text()};

  if (username.isEmpty() || password.isEmpty()) {
    QMessageBox::warning(this, "警告", "用户名或密码为空");
    return;
  }

  QSqlDatabase db;
  if (!QSqlDatabase::contains(QSqlDatabase::defaultConnection)) {
    db = QSqlDatabase::addDatabase("QMYSQL");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("524321");
    db.setDatabaseName("lottery");

    if (!db.open()) {
      QMessageBox::critical(this, "错误", "无法连接数据库");
      QApplication::exit(EXIT_FAILURE);
    }
  } else {
    db = QSqlDatabase::database();
  }

  if (!db.isOpen()) {
    QMessageBox::critical(this, "错误", "无法连接数据库");
    QApplication::exit(EXIT_FAILURE);
  }

  QSqlQuery query;
  if (!query.exec("select password from user where username='" + username +
                  "'")) {
    QMessageBox::critical(this, "错误",
                          "查询用户数据库失败\n" + query.lastError().text());
    QApplication::exit(EXIT_FAILURE);
  }

  if (query.next()) {
    if (query.value("password").toString() != password) {
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
  Register a_register;
  if (a_register.exec() == QDialog::Accepted) {
    accept();
  }
}

void Login::OnClickTryOut() { accept(); }
