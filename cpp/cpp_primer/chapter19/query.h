//
// Created by kaiser on 19-3-16.
//

#ifndef CPP_PRIMER_QUERY_H
#define CPP_PRIMER_QUERY_H

#include <memory>
#include <string>
#include <utility>

#include "ex_12_33.h"

class QueryBase;

class Query {
    friend Query operator~(const Query& item);
    friend Query operator|(const Query& lhs, const Query& rhs);
    friend Query operator&(const Query& lhs, const Query& rhs);

public:
    explicit Query(const std::string& s);
    QueryResult Eval(const TextQuery& text) const;
    std::string Rep() const;

private:
    Query(std::shared_ptr<QueryBase> query) : q_{std::move(query)} {}
    std::shared_ptr<QueryBase> q_;
};

std::ostream& operator<<(std::ostream& os, const Query& query);
Query operator~(const Query& item);
Query operator|(const Query& lhs, const Query& rhs);
Query operator&(const Query& lhs, const Query& rhs);

#endif // CPP_PRIMER_QUERY_H
