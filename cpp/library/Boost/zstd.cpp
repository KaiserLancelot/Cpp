/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-24 23:44:21
 * @ Modified time: 2020-05-25 00:21:11
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>

#include <boost/iostreams/copy.hpp>
#include <boost/iostreams/filter/zstd.hpp>
#include <boost/iostreams/filtering_streambuf.hpp>

std::string compress(const std::string &data) {
  std::istringstream origin{data};

  boost::iostreams::filtering_streambuf<boost::iostreams::input> input;
  input.push(boost::iostreams::zstd_compressor(boost::iostreams::zstd_params(
      boost::iostreams::zstd::default_compression)));
  input.push(origin);

  std::ostringstream compressed;
  boost::iostreams::copy(input, compressed);

  return compressed.str();
}

std::string decompress(const std::string &data) {
  std::istringstream compressed{data};

  boost::iostreams::filtering_streambuf<boost::iostreams::input> input;
  input.push(boost::iostreams::zstd_decompressor(boost::iostreams::zstd_params(
      boost::iostreams::zstd::default_compression)));
  input.push(compressed);

  std::ostringstream origin;
  boost::iostreams::copy(input, origin);

  return origin.str();
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "no file\n";
    return EXIT_FAILURE;
  }

  std::string file_name{argv[1]};

  if (file_name.ends_with(".zst")) {
    std::ifstream ifs{file_name, std::ifstream::binary};
    std::string data{std::istreambuf_iterator<char>{ifs}, {}};

    file_name = file_name.substr(0, file_name.find_last_of('.'));

    std::ofstream ofs{file_name, std::ofstream::binary};
    ofs << decompress(data) << std::endl;
  } else {
    std::ifstream ifs{file_name, std::ifstream::binary};
    std::string data{std::istreambuf_iterator<char>{ifs}, {}};

    file_name += ".zst";

    std::ofstream ofs{file_name, std::ofstream::binary};
    ofs << compress(data) << std::endl;
  }
}
