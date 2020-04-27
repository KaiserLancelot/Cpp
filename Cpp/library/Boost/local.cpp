//
// Created by kaiser on 2020/4/27.
//

#include <cstdint>
#include <iostream>
#include <string>

#include <boost/locale/encoding.hpp>
#include <boost/locale/encoding_utf.hpp>

void AppendUCN(std::string& s, std::int32_t val) {
  std::u32string str;
  str.push_back(static_cast<char32_t>(val));
  s += boost::locale::conv::utf_to_utf<char>(str);
}

void ConvertToUtf16(std::string& s) {
  s = boost::locale::conv::between(s, "UTF-16LE", "UTF-8");
}

int main() {
  std::string s;
  AppendUCN(s, U'你');

  std::cout << std::size(s) << '\n';
  std::cout << s << '\n';

  ConvertToUtf16(s);
  std::cout << std::size(s) << '\n';
}
