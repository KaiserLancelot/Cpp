//
// Created by kaiser on 18-12-26.
//

#include "ex_15_42_query.h"

#include "ex_15_42.h"

Query::Query(const std::string &s)
    : q_{new WordQuery{s}} {}

QueryResult Query::Eval(const TextQuery &text) const {
  return q_->Eval(text);
}

std::string Query::Rep() const {
  return q_->Rep();
}

Query operator~(const Query &item) {
  return std::shared_ptr<QueryBase>(new NotQuery{item});
}

Query operator|(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<QueryBase>(new OrQuery{lhs, rhs});
}

Query operator&(const Query &lhs, const Query &rhs) {
  return std::shared_ptr<QueryBase>(new AndQuery{lhs, rhs});
}

std::ostream &operator<<(std::ostream &os, const Query &query) {
  os << query.Rep();
  return os;
}
