//
// Created by kaiser on 19-3-16.
//

#include <iostream>
#include <typeinfo>

#include "query_base.h"

int main() {
  Query query{"kaiser"};
  // QueryBase *base{new AndQuery{query, query}};
  QueryBase* base{new OrQuery{query, query}};
  if (AndQuery * and_query{dynamic_cast<AndQuery*>(base)}; !and_query) {
    std::cerr << "can't cast to AndQuery*\n";
  }
}
