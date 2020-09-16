//
// Created by kaiser on 19-3-10.
//

#ifndef CPP_PRIMER_EX_17_03_H
#define CPP_PRIMER_EX_17_03_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <tuple>
#include <vector>

using LineNo = std::vector<std::string>::size_type;
using QueryResult =
    std::tuple<std::string, std::shared_ptr<std::vector<std::string>>,
               std::shared_ptr<std::set<LineNo>>>;

class TextQuery {
 public:
  explicit TextQuery(std::ifstream& input);
  QueryResult Query(const std::string& s);

 private:
  std::shared_ptr<std::vector<std::string>> text_;
  std::map<std::string, std::shared_ptr<std::set<LineNo>>>
      words_and_line_number_;
};

std::ostream& Print(std::ostream& os, QueryResult qr);

#endif  // CPP_PRIMER_EX_17_03_H
