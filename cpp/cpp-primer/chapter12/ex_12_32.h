//
// Created by kaiser on 18-12-19.
//

#pragma once

#include "ex_12_22.h"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>

class QueryResult;

using LineNo = std::vector<std::string>::size_type;

class TextQuery {
 public:
  explicit TextQuery(std::ifstream &input);
  QueryResult query(const std::string &s);

 private:
  StrBlob text_;
  std::map<std::string, std::shared_ptr<std::set<LineNo>>>
      words_and_line_number_;
};

class QueryResult {
  friend std::ostream &print(std::ostream &os, QueryResult qr);

 public:
  QueryResult(const std::string &word, const StrBlob &text,
              const std::shared_ptr<std::set<LineNo>> &line_number);

 private:
  std::string word_;
  StrBlob text_;
  std::shared_ptr<std::set<LineNo>> line_number_;
};

std::ostream &print(std::ostream &os, QueryResult qr);
