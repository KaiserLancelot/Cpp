//
// Created by kaiser on 19-3-16.
//

#include <iostream>
#include <typeinfo>

#include "query_base.h"

int main()
{
    Query query{"kaiser"};
    AndQuery and_query{query, query};
    QueryBase& base{and_query};

    if (typeid(and_query) == typeid(base)) {
        std::cout << "yes\n";
    }

    if (typeid(base) == typeid(AndQuery)) {
        std::cout << "yes\n";
    }
}
