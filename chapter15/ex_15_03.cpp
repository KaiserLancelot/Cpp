//
// Created by kaiser on 18-12-24.
//

#include "ex_15_03.h"

double PrintTotal(std::ostream &os, const Quote &item, std::size_t n) {
  double ret{item.NetPrice(n)};
  os << "ISBN: " << item.Isbn()
     << " # sold: " << n << " total due: " << ret << '\n';
  return ret;
}
