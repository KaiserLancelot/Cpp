#include <cstddef>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

#include <zstd.h>

std::string read_file(const std::string& filename) {
  std::ifstream ifs{filename, std::ifstream::binary};
  std::string data;
  data.resize(ifs.seekg(0, std::ifstream::end).tellg());
  ifs.seekg(0, std::ifstream::beg).read(data.data(), std::size(data));
  return data;
}

void write_file(const std::string& filename, const std::string& data) {
  std::ofstream ofs{filename, std::ofstream::binary};
  ofs << data << std::flush;
}

void check_zstd(std::size_t error) {
  if (ZSTD_isError(error)) {
    std::cerr << "error: " << ZSTD_getErrorName(error) << '\n';
    std::exit(EXIT_FAILURE);
  }
}

void compress(const std::string& filename) {
  auto data{read_file(filename)};
  auto size{std::size(data)};

  auto compress_size{ZSTD_compressBound(size)};
  std::string compress_data;
  compress_data.resize(compress_size);

  compress_size =
      ZSTD_compress(compress_data.data(), compress_size, data.data(), size, 1);
  check_zstd(compress_size);
  compress_data.resize(compress_size);

  write_file(filename + ".zst", compress_data);
}

void decompress(const std::string& filename) {
  auto data{read_file(filename)};
  auto size{std::size(data)};

  auto decompress_size{ZSTD_getFrameContentSize(data.data(), size)};
  if (decompress_size == ZSTD_CONTENTSIZE_ERROR) {
    std::cerr << filename << ": not compressed by zstd!\n";
    std::exit(EXIT_FAILURE);
  } else if (decompress_size == ZSTD_CONTENTSIZE_UNKNOWN) {
    std::cerr << filename << ": original size unknown!\n";
    std::exit(EXIT_FAILURE);
  }

  std::string decompress_data;
  decompress_data.resize(decompress_size);
  auto decompress_size_new{ZSTD_decompress(decompress_data.data(),
                                           decompress_size, data.data(), size)};
  check_zstd(decompress_size_new);

  if (decompress_size != decompress_size_new) {
    std::cerr << "Impossible because zstd will check this condition!\n";
    std::exit(EXIT_FAILURE);
  }

  write_file(filename.substr(0, std::size(filename) - 4), decompress_data);
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << "need filename\n";
    std::exit(EXIT_FAILURE);
  }

  std::string filename{argv[1]};
  if (filename.ends_with(".zst")) {
    decompress(filename);
  } else {
    compress(filename);
  }
}
