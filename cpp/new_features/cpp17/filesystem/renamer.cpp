//
// Created by kaiser on 19-3-22.
//

#include <cstdlib>
#include <filesystem>
#include <iostream>
#include <regex>
#include <string>
#include <utility>
#include <vector>

namespace fs = std::filesystem;

std::string
replace(std::string s,
        const std::vector<std::pair<std::regex, std::string>>& replacements)
{
    for (const auto& [pattern, replace] : replacements) {
        s = std::regex_replace(s, pattern, replace);
    }
    return s;
}

int main(int argc, char* argv[])
{
    if (argc < 3 || argc % 2 != 1) {
        std::cerr << "Usage: " << argv[0] << " <pattern> <replacement> ...\n";
        std::exit(EXIT_FAILURE);
    }

    std::vector<std::pair<std::regex, std::string>> patterns;

    for (std::int32_t i{1}; i + 1 < argc; i += 2) {
        patterns.emplace_back(argv[i], argv[i + 1]);
    }

    for (const auto& entry :
         fs::recursive_directory_iterator{fs::current_path()}) {
        const auto& old_path{entry.path()};
        std::string new_name{replace(old_path.filename().string(), patterns)};
        auto new_path{old_path};
        // 替换文件名
        new_path.replace_filename(new_name);

        if (old_path != new_path) {
            std::cout << old_path.c_str() << " --> " << new_path.filename().c_str()
                      << '\n';
            // 如果存在该文件会被删除
            if (fs::exists(new_path)) {
                std::cout << "Error: Can't rename. Destination file exists.\n";
            }
            else {
                fs::rename(old_path, new_path);
            }
        }
    }
}
