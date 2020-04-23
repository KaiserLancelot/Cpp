//
// Created by kaiser on 19-4-10.
//

#include <cstdlib>
#include <iostream>

#include <QSqlDatabase>
#include <QSqlRecord>
#include <QSqlTableModel>

int main() {
  auto db{QSqlDatabase::addDatabase("QMYSQL")};
  db.setHostName("localhost");
  db.setUserName("root");
  db.setPassword("524321");
  db.setDatabaseName("example");

  if (!db.open()) {
    std::cerr << "Can not connect this database\n";
    return EXIT_FAILURE;
  } else {
    // 查询
    {
      QSqlTableModel model;
      model.setTable("student");
      // 只能进行简单的查询
      model.setFilter("tot_cred>50");

      // 如果查询成功, 返回 true
      if (model.select()) {
        for (std::int32_t i{0}; i < model.rowCount(); ++i) {
          // 取出一行记录
          auto record{model.record(i)};
          auto name{record.value("name")};
          std::cout << name.toString().toStdString() << '\n';
        }
      }
    }

    // 插入
    {
      QSqlTableModel model;
      model.setTable("student");
      // 在第 0 行插入记录
      model.insertRow(0);
      model.setData(model.index(0, 0), "00000");
      model.setData(model.index(0, 1), "liu");
      model.setData(model.index(0, 2), "Comp. Sci.");
      model.setData(model.index(0, 3), "100");
      model.submit();
    }

    // 修改
    {
      QSqlTableModel model;
      model.setTable("student");
      model.setFilter("ID='00000'");

      if (model.select()) {
        auto record{model.record(0)};
        record.setValue("name", "liuliu");
        model.setRecord(0, record);
        model.submit();
      }
    }

    // 删除
    {
      QSqlTableModel model;
      model.setTable("student");
      model.setFilter("ID='00000'");

      if (model.select()) {
        model.removeRow(0);
        model.submit();
      }
    }
  }
}
