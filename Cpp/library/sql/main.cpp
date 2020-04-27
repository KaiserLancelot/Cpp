//
// Created by kaiser on 2020/4/27.
//

#include <cstdlib>
#include <iostream>
#include <stdexcept>

#include <mysqlx/xdevapi.h>

int main() try {
  // 要访问数据必须先创建一个 Session
  mysqlx::SessionSettings settings{"localhost", "root", "524321"};
  mysqlx::Session session{settings};

  auto schema{session.getSchema("test")};
  // 创建一个 collection , 第二个参数为 true 的话, 如果已经存在同名的 collection
  // 则返回, 如果是 false 的话, 则报错
  auto coll{schema.createCollection("test_collection", true)};
  // 清空
  coll.remove("true").execute();

  mysqlx::DbDoc temp{R"({ "name": "foo", "age": 1 })"};
  auto add_result{
      coll.add(temp)
          .add(R"({ "name": "bar", "age": 2, "toys": [ "car", "ball" ] })")
          .add(R"({
                 "name": "baz",
                  "age": 3,
                 "date": { "day": 20, "month": "Apr" }
              })")
          .add(R"({ "_id": "myuuid-1", "name": "foo", "age": 7 })")
          .execute()};

  for (const auto &id : add_result.getGeneratedIds()) {
    std::cout << "added doc with id: " << id << '\n';
  }

  for (auto doc : coll.find("age > 1 and name like 'ba%'").execute()) {
    for (const auto &fld : doc) {
      std::cout << " field `" << fld << "`: " << doc[fld] << std::endl;
    }

    std::cout << " name: " << doc["name"] << '\n';

    if (doc.hasField("date") &&
        doc.fieldType("date") == mysqlx::Value::DOCUMENT) {
      std::cout << "date field\n";

      mysqlx::DbDoc date{doc["date"]};
      for (const auto &fld : date) {
        std::cout << "  date `" << fld << "`: " << date[fld] << std::endl;
      }

      std::cout << "  month: " << doc["date"]["month"] << '\n';
    }

    if (doc.hasField("toys") && doc.fieldType("toys") == mysqlx::Value::ARRAY) {
      std::cout << "toys:\n";
      for (const auto &toy : doc["toys"]) {
        std::cout << "  " << toy << '\n';
      }
    }
  }

  auto result{coll.find("name like :param").bind("param", "f%").execute()};
  std::cout << result.fetchOne() << '\n';

  coll.modify("name = :param")
      .set("age", 1000000)
      .bind("param", "foo")
      .execute();
  auto modify_result{
      coll.find("name like :param").bind("param", "f%").execute()};
  std::cout << modify_result.fetchOne() << '\n';

  coll.remove("name like :param").bind("param", "f%").execute();
  std::cout
      << coll.find("name like :param").bind("param", "f%").execute().count()
      << '\n';
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
