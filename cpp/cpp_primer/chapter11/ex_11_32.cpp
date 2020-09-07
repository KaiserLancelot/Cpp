//
// Created by kaiser on 18-12-18.
//

#include <iostream>
#include <map>
#include <set>
#include <string>

int main()
{
    std::multimap<std::string, std::string> authors{
            {"a", "DMA"},
            {"p", "LeetCode"},
            {"p", "CLRS"},
            {"w", "FTP"},
            {"p", "CP5"},
            {"w", "CPP-Concurrency"}};

    std::map<std::string, std::set<std::string>> order;
    for (const auto& [author, work] : authors) {
        order[author].insert(work);
    }

    for (const auto& [author, works] : order) {
        std::cout << author << ": ";
        for (const auto& work : works) {
            std::cout << work << ' ';
        }
        std::cout << '\n';
    }
}
