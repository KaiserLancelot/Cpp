//
// Created by kaiser on 2020/4/29.
//

#include <memory.h>
#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <fmt/ranges.h>
#include <sqlpp11/mysql/mysql.h>
#include <sqlpp11/sqlpp11.h>

#include "data/table.h"

int main() {
  auto config{std::make_shared<sqlpp::mysql::connection_config>()};
  config->host = "localhost";
  config->user = "root";
  config->password = "524321";
  config->database = "test";
  // config->debug = true;

  try {
    sqlpp::mysql::connection db{config};

    table::Student table;
    std::vector<std::tuple<std::string, std::string, std::string, std::int32_t>>
        data;

    for (const auto& row : db.run(sqlpp::select(all_of(table))
                                      .from(table)
                                      .where(table.totCred < 60)
                                      .order_by(table.ID.asc()))) {
      data.push_back({row.ID, row.name, row.deptName, row.totCred});
    }

    for (const auto& item : data) {
      fmt::print("{}\n", item);
    }
  } catch (const sqlpp::exception& e) {
    std::cerr << "Can not connection" << std::endl;
    std::cerr << e.what() << std::endl;
    return EXIT_FAILURE;
  } catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << std::endl;
    return EXIT_FAILURE;
  }
}
