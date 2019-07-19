//
// Created by kaiser on 19-3-13.
//

#include <iostream>

#include <fmt/core.h>
#include <fmt/format.h>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVariant>

int main() {
  // 创建一个数据库连接
  // 第二个参数指定一个连接的名字, 如果为空则为默认名字,
  // 如果名字重复则新的连接会替换掉旧的连接
  auto db{QSqlDatabase::addDatabase("QMYSQL")};
  db.setHostName("localhost");
  db.setUserName("root");
  db.setPassword("524321");
  // 如果使用 QSQLITE 只需要指定这个
  // 在 MySQL 中, 这个指定的是模式的名字
  db.setDatabaseName("example");
  if (db.open()) {
    std::cout << "open\n";
  } else {
    std::cerr << "not open\n";
  }

  // 如果使用默认构造函数则使用默认连接,
  QSqlQuery query{db};
  if (!query.exec("select *\n"
                  "from instructor;")) {
    std::cerr << "error\n";
    std::cerr << query.lastError().text().toStdString() << '\n';
  } else {
    std::cout << "ok\n";
  }

  while (query.next()) {
    auto id{query.value(0).toString().toStdString()};
    auto name{query.value(1).toString().toStdString()};
    auto dept_name{query.value(2).toString().toStdString()};
    auto salary{query.value(3).toDouble()};
    fmt::print(fmt("{:<15}{:<15}{:<15}{:<15}\n"), id, name, dept_name, salary);
  }

  // 对这条 SQL 语句进行预处理, 问号 ? 相当于占位符
  query.prepare("insert into instructor values(?,?,?,?)");
  QVariantList ids;
  ids << "111"
      << "222";
  // 将实际数据绑定到这个预处理的 SQL 语句上
  query.addBindValue(ids);
  QVariantList names;
  names << "Srinivasan"
        << "Srinivasan";
  query.addBindValue(names);
  QVariantList dept_name;
  dept_name << "Comp. Sci."
            << "Comp. Sci.";
  query.addBindValue(dept_name);
  QVariantList salary;
  salary << 20000 << 60000;
  query.addBindValue(salary);

  // 批量执行 SQL
  query.execBatch();
}