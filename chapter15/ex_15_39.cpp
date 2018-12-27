//
// Created by kaiser on 18-12-26.
//

#include "ex_15_39.h"

#include <algorithm>
#include <set>

QueryResult NotQuery::Eval(const TextQuery &text) const {
  auto result{query_.Eval(text)};
  auto ret_lines{std::make_shared<std::set<LineNo>>()};

  auto beg{std::begin(result)}, end{std::end(result)};
  auto sz{std::size(result.GetFile())};
  for (std::size_t n{1}; n <= sz; ++n) {
    if (*beg != n) {
      ret_lines->insert(n);
    } else if (beg != end) {
      ++beg;
    }
  }
  return QueryResult{Rep(), result.GetFile(), ret_lines};
}

QueryResult AndQuery::Eval(const TextQuery &text) const {
  auto lhs{lhs_.Eval(text)}, rhs{rhs_.Eval(text)};
  auto ret_lines{std::make_shared<std::set<LineNo>>()};

  std::set_intersection(std::begin(lhs), std::end(lhs), std::begin(rhs),
                        std::end(rhs),
                        std::inserter(*ret_lines, std::begin(*ret_lines)));

  return QueryResult{Rep(), lhs.GetFile(), ret_lines};
}

QueryResult OrQuery::Eval(const TextQuery &text) const {
  auto lhs{lhs_.Eval(text)}, rhs{rhs_.Eval(text)};

  auto ret_lines{
      std::make_shared<std::set<LineNo>>(std::begin(lhs), std::end(lhs))};
  ret_lines->insert(std::begin(rhs), std::end(rhs));
  return QueryResult{Rep(), lhs.GetFile(), ret_lines};
}
