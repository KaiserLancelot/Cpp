//
// Created by kaiser on 19-3-17.
//

#ifndef CPP_PRIMER_EX_19_20_H
#define CPP_PRIMER_EX_19_20_H

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

using LineNo = std::vector<std::string>::size_type;

class TextQuery {
 public:
  class QueryResult {
    friend std::ostream& Print(std::ostream& os, QueryResult qr);

   public:
    QueryResult(const std::string& word,
                const std::shared_ptr<std::vector<std::string>>& text,
                const std::shared_ptr<std::set<LineNo>>& line_number);

   private:
    std::string word_;
    std::shared_ptr<std::vector<std::string>> text_;
    std::shared_ptr<std::set<LineNo>> line_number_;
  };

  explicit TextQuery(std::ifstream& input);
  QueryResult Query(const std::string& s);

 private:
  std::shared_ptr<std::vector<std::string>> text_;
  std::map<std::string, std::shared_ptr<std::set<LineNo>>>
      words_and_line_number_;
};

std::ostream& Print(std::ostream& os, TextQuery::QueryResult qr);

#endif  // CPP_PRIMER_EX_19_20_H
