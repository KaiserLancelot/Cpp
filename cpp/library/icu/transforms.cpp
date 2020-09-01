#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include <unicode/translit.h>
#include <unicode/unistr.h>
#include <unicode/ustream.h>
#include <unicode/utypes.h>

int main() {
  std::ifstream ifs{"data.txt"};
  if (!ifs) {
    std::cerr << "can not open this file\n";
    std::exit(EXIT_FAILURE);
  }

  std::string data;
  data.resize(ifs.seekg(0, std::ifstream::end).tellg());
  ifs.seekg(0, std::ifstream::beg).read(data.data(), std::size(data));

  icu::UnicodeString str{data.c_str()};

  UErrorCode status{U_ZERO_ERROR};
  auto trans{
      icu::Transliterator::createInstance("Hans-Hant", UTRANS_FORWARD, status)};
  if (U_FAILURE(status)) {
    std::cerr << "error: " << u_errorName(status) << '\n';
    std::exit(EXIT_FAILURE);
  }

  trans->transliterate(str);

  std::cout << str << '\n';

  delete trans;
}
