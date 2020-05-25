//
// Created by kaiser on 2020/4/27.
//

#include <iostream>
#include <string>

#include <boost/locale/encoding.hpp>
#include <boost/locale/encoding_utf.hpp>

int main() {
  std::string utf8{"你好世界"};
  std::cout << std::size(utf8) << '\n';

  auto utf16{boost::locale::conv::utf_to_utf<char16_t>(utf8)};
  std::cout << std::size(utf16) << '\n';

  auto utf32{boost::locale::conv::utf_to_utf<char32_t>(utf16)};
  std::cout << std::size(utf32) << '\n';

  auto s{boost::locale::conv::between(utf8, "UTF-16LE", "UTF-8")};
  std::cout << std::size(s) << '\n';
}
