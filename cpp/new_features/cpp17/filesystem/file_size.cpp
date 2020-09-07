//
// Created by kaiser on 19-3-22.
//

#include <cmath>
#include <cstddef>
#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <numeric>
#include <sstream>
#include <string>

#include <fmt/core.h>

namespace fs = std::filesystem;

std::string size_string(std::size_t size)
{
    std::stringstream ss;

    if (size >= std::pow(2, 30)) {
        ss << (size / std::pow(2, 30)) << " GB";
    }
    else if (size >= std::pow(2, 20)) {
        ss << (size / std::pow(2, 20)) << " MB";
    }
    else if (size >= std::pow(2, 10)) {
        ss << (size / std::pow(2, 10)) << " KB";
    }
    else {
        ss << size << " Byte";
    }

    return ss.str();
}

std::size_t entry_size(const fs::path& path)
{
    if (!fs::is_directory(path)) {
        // file_size只能对普通文件和符号链接有效, 否则, 会抛出异常
        // file_size对符号链接有效, 如果链接失效, 函数还是会抛出异常
        return fs::file_size(path);
    }
    else {
        return std::accumulate(
                fs::directory_iterator{path}, {}, std::size_t{},
                [](std::size_t accum, const fs::directory_entry& entry) {
                    return accum + entry_size(entry);
                });
    }
}

int main(int argc, char* argv[])
{
    fs::path dir{argc > 1 ? argv[1] : "."};
    if (!fs::exists(dir)) {
        std::cout << "Path " << dir << " does not exist.\n";
        std::exit(EXIT_FAILURE);
    }

    for (const auto& entry : fs::directory_iterator{dir}) {
        fmt::print("{:<30}", entry.path().filename().c_str());
        fmt::print("{}\n", size_string(entry_size(entry)));
    }
}
