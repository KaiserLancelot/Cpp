//
// Created by kaiser on 18-12-19.
//

#ifndef CPP_PRIMER_EX_12_32_H
#define CPP_PRIMER_EX_12_32_H

#include "ex_12_22.h"

#include <fstream>
#include <iostream>
#include <string>
#include <memory>
#include <map>
#include <set>
#include <cstdint>

class QueryResult;

using LineNo=std::vector<std::string>::size_type;

class TextQuery {
public:
    explicit TextQuery(std::ifstream &input);
    QueryResult Query(const std::string &s);
private:
    StrBlob text_;
    std::map<std::string, std::shared_ptr<std::set<LineNo>>> words_and_line_number_;
};

class QueryResult {
    friend std::ostream &Print(std::ostream &os, QueryResult qr);
public:
    QueryResult(const std::string &word,
                const StrBlob &text,
                const std::shared_ptr<std::set<LineNo>> &line_number);
private:
    std::string word_;
    StrBlob text_;
    std::shared_ptr<std::set<LineNo>> line_number_;
};

std::ostream &Print(std::ostream &os, QueryResult qr);

#endif //CPP_PRIMER_EX_12_32_H
