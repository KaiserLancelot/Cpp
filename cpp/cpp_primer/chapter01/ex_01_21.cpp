#include <iostream>

#include "sales_item.h"

int main() {
  SalesItem item1;
  SalesItem item2;

  std::cin >> item1 >> item2;
  if (item1.isbn() == item2.isbn()) {
    std::cout << item1 + item2;
  } else {
    std::cerr << "Different ISBN\n";
  }
}
