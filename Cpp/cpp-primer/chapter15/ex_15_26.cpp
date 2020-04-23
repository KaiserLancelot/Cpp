//
// Created by kaiser on 18-12-25.
//

#include "ex_15_26.h"

int main() {
  BulkQuote bq1;
  BulkQuote bq2("ss", 2.05, 12, 0.3);
  bq2 = std::move(bq2);
}