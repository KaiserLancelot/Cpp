//
// Created by kaiser on 18-12-22.
//

#include "ex_13_50.h"

#include <vector>
#include <iostream>

void foo(String x) {
  std::cout << x.CStr() << '\n';
}

void bar(const String &x) {
  std::cout << x.CStr() << '\n';
}

String baz() {
  String ret("world");
  return ret;
}

int main() {
  char text[]{"world"};

  String s0;
  String s1("hello");
  String s2(s0);
  String s3(s1);
  String s4(text);
  s2 = s1;

  foo(s1);
  bar(s1);
  foo("temporary");
  bar("temporary");
  String s5 = baz();

  std::vector<String> svec;
  svec.reserve(8);
  svec.push_back(s0);
  svec.push_back(s1);
  svec.push_back(s2);
  svec.push_back(s3);
  svec.push_back(s4);
  svec.push_back(s5);
  svec.push_back(baz());
  svec.emplace_back("good job");
}
