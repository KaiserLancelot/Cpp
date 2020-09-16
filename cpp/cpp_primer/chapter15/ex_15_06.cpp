//
// Created by kaiser on 18-12-24.
//

#include <iostream>

#include "ex_15_03.h"
#include "ex_15_05.h"

int main() {
  Quote quote{"fuck", 6.6};
  BulkQuote bulk_quote{"fuck", 6.6, 10, 0.2};

  PrintTotal(std::cout, quote, 20);
  PrintTotal(std::cout, bulk_quote, 20);
}
