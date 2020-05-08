//
// Created by kaiser on 2020/4/29.
//

#include <iostream>

#include <mysql++/mysql++.h>

int main() {
  mysqlpp::Connection conn;
  if (conn.connect("test", "localhost:3306", "root", "524321")) {
    std::cout << "Database connection succeeded!\n";
  } else {
    std::cerr << "Database connection failed" << std::endl;
  }

  auto query{conn.query("select * from student")};
  if (auto res{query.store()}) {
    for (const auto &row : res) {
      std::cout << row[0] << "\t" << row["name"] << "\t" << row["dept_name"]
                << "\t" << row["tot_cred"] << '\n';
    }
  } else {
    std::cerr << "failed" << std::endl;
  }
}
