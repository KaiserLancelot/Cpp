//
// Created by kaiser on 18-12-17.
//

#include <algorithm>
#include <cstdint>
#include <fstream>
#include <iterator>
#include <string>
#include <vector>

void fun(const std::string &input_file, const std::string &out_file1,
         const std::string &out_file2) {
  std::ifstream ifs{input_file};
  std::vector<std::int32_t> vi{std::istream_iterator<std::int32_t>{ifs}, {}};

  std::ofstream ofs1{out_file1}, ofs2{out_file2};
  std::copy_if(std::begin(vi), std::end(vi),
               std::ostream_iterator<std::int32_t>{ofs1, " "},
               [](auto i) { return i % 2; });
  std::copy_if(std::begin(vi), std::end(vi),
               std::ostream_iterator<std::int32_t>{ofs2, "\n"},
               [](auto i) { return i % 2 == 0; });
}

int main() { fun("in", "out1", "out2"); }
