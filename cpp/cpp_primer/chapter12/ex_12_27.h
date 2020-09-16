//
// Created by kaiser on 18-12-19.
//

#pragma once

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <vector>

class QueryResult;

using LineNo = std::vector<std::string>::size_type;

class TextQuery {
 public:
  explicit TextQuery(std::ifstream& input);
  QueryResult query(const std::string& s);

 private:
  std::shared_ptr<std::vector<std::string>> text_;
  std::map<std::string, std::shared_ptr<std::set<LineNo>>>
      words_and_line_number_;
};

class QueryResult {
  friend std::ostream& print(std::ostream& os, const QueryResult& qr);

 public:
  QueryResult(const std::string& word,
              const std::shared_ptr<std::vector<std::string>>& text,
              const std::shared_ptr<std::set<LineNo>>& line_number);

 private:
  std::string word_;
  std::shared_ptr<std::vector<std::string>> text_;
  std::shared_ptr<std::set<LineNo>> line_number_;
};

std::ostream& print(std::ostream& os, const QueryResult& qr);
