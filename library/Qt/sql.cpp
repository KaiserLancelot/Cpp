//
// Created by kaiser on 19-3-13.
//

#include <QCoreApplication>
#include <QSqlDatabase>
#include <iostream>

int main(int argc, char *argv[]) {
  QCoreApplication app{argc, argv};
  auto db{QSqlDatabase::addDatabase("QMYSQL")};
  db.setHostName("localhost");
  db.setUserName("root");
  db.setPassword("524321");
  db.setDatabaseName("fuck");
  if (db.open()) {
    std::cout << "open\n";
  } else {
    std::cerr << "not open\n";
  }
}