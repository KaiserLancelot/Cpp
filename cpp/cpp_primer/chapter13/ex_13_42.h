//
// Created by kaiser on 18-12-21.
//

#ifndef CPP_PRIMER_EX_13_42_H
#define CPP_PRIMER_EX_13_42_H

#include "ex_13_40.h"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <string>

class QueryResult;

using LineNo = StrVec::SizeType;

class TextQuery {
public:
    explicit TextQuery(std::ifstream& input);
    QueryResult Query(const std::string& s);

private:
    std::shared_ptr<StrVec> text_;
    std::map<std::string, std::shared_ptr<std::set<LineNo>>>
            words_and_line_number_;
};

class QueryResult {
    friend std::ostream& Print(std::ostream& os, QueryResult qr);

public:
    using ResultIterator = std::set<LineNo>::iterator;
    QueryResult(const std::string& word, const std::shared_ptr<StrVec>& text,
                const std::shared_ptr<std::set<LineNo>>& line_number);
    ResultIterator Begin() const;
    ResultIterator End() const;
    std::shared_ptr<StrVec> GetFile() const;

private:
    std::string word_;
    std::shared_ptr<StrVec> text_;
    std::shared_ptr<std::set<LineNo>> line_number_;
};

std::ostream& Print(std::ostream& os, QueryResult qr);

#endif // CPP_PRIMER_EX_13_42_H
