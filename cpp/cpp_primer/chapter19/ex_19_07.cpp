//
// Created by kaiser on 19-3-16.
//

#include <iostream>
#include <typeinfo>

#include "query_base.h"

int main() {
  Query query{"kaiser"};
  OrQuery other_query{query, query};
  // AndQuery other_query{query, query};
  QueryBase& base{other_query};
  try {
    AndQuery& and_query{dynamic_cast<AndQuery&>(base)};
  } catch (const std::bad_cast& err) {
    std::cerr << "error\n";
  }
}
