//
// Created by kaiser on 19-4-16.
//

#include "register.h"

#include <QApplication>
#include <QHBoxLayout>
#include <QMessageBox>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QString>
#include <QVBoxLayout>

Register::Register(QWidget *parent)
    : QDialog{parent},
      username_label_{new QLabel{"用户名:     ", this}},
      password_label_{new QLabel{"密码:         ", this}},
      password_confirm_label_{new QLabel{"确认密码:     ", this}},
      username_{new QLineEdit{this}},
      password_{new QLineEdit{this}},
      password_confirm_{new QLineEdit{this}},
      register_{new QPushButton{"注册", this}} {
  setWindowTitle("注册");
  password_->setEchoMode(QLineEdit::Password);
  password_confirm_->setEchoMode(QLineEdit::Password);

  auto username_layout{new QHBoxLayout};
  username_layout->addWidget(username_label_);
  username_layout->addWidget(username_);

  auto password_layout{new QHBoxLayout};
  password_layout->addWidget(password_label_);
  password_layout->addWidget(password_);

  auto password_confirm_layout{new QHBoxLayout};
  password_confirm_layout->addWidget(password_confirm_label_);
  password_confirm_layout->addWidget(password_confirm_);

  auto button_layout{new QHBoxLayout};
  button_layout->addWidget(register_);

  auto main_layout{new QVBoxLayout};
  main_layout->addLayout(username_layout);
  main_layout->addLayout(password_layout);
  main_layout->addLayout(password_confirm_layout);
  main_layout->addLayout(button_layout);

  setLayout(main_layout);

  connect(register_, &QPushButton::clicked, this, &Register::OnClickRegister);
}

void Register::OnClickRegister() {
  auto username{username_->text()};
  auto password{password_->text()};
  auto password_confirm{password_confirm_->text()};

  if (username.isEmpty() || password.isEmpty() || password_confirm.isEmpty()) {
    QMessageBox::warning(this, "警告", "用户名或密码为空");
    return;
  } else if (password != password_confirm) {
    QMessageBox::warning(this, "警告", "两次输入的密码不一致");
    password.clear();
    password_confirm.clear();
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

  if (!query.exec(
          QString("select * from user where username='%1'").arg(username))) {
    QMessageBox::critical(this, "错误",
                          "数据库查询失败\n" + query.lastError().text());
    QApplication::exit(EXIT_FAILURE);
  } else {
    if (query.next()) {
      QMessageBox::critical(this, "错误", "该用户已存在");
      username_->clear();
      return;
    }
  }

  if (!query.exec(QString("insert into user values('%1','%2')")
                      .arg(username)
                      .arg(password))) {
    QMessageBox::critical(this, "错误",
                          "向数据库插入数据失败\n" + query.lastError().text());
    QApplication::exit(EXIT_FAILURE);
  } else {
    QMessageBox::information(this, "提示", "注册成功, 将自动登录");
    accept();
  }
}
