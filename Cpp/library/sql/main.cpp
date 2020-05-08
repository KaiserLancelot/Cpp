//
// Created by kaiser on 2020/4/29.
//

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include <mysqlx/xdevapi.h>

int main() try {
  // 要访问数据必须先创建一个 Session
  mysqlx::Session session{33060, "root", "524321"};
  session.startTransaction();

  auto schema{session.getSchema("test")};
  auto table{schema.getTable("student")};

  // table.insert("ID", "name", "dept_name", "tot_cred")
  //     .values("66666", "kaiser", "Comp. Sci.", 666)
  //     .execute();

  table.update()
      .set("tot_cred", 99)
      .where("ID > :id")
      .bind("id", "33333")
      .execute();

  table.remove().where("tot_cred > 100").execute();

  auto result{
      table.select("*").where("ID < :id").bind("id", "33333").execute()};

  for (const auto &row : result) {
    std::cout << row[0] << '\t' << row[1] << '\t' << row[2] << '\t' << row[3]
              << '\n';
  }

  session.commit();
} catch (const mysqlx::Error &err) {
  std::cerr << "error: " << err << std::endl;
  return EXIT_FAILURE;
} catch (std::exception &ex) {
  std::cerr << "std exception: " << ex.what() << std::endl;
  return EXIT_FAILURE;
} catch (const char *ex) {
  std::cerr << "exception: " << ex << std::endl;
  return EXIT_FAILURE;
}
