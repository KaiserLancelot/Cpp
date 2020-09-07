//
// Created by kaiser on 2020/4/27.
//

#include <cstdint>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/variables_map.hpp>

int main(int argc, char* argv[])
{
    try {
        std::int32_t opt;

        boost::program_options::options_description generic("Generic options");
        generic.add_options()("version,v", "print version string")(
                "help,h", "produce help message");

        boost::program_options::options_description config("Configuration");
        config.add_options()(
                "optimization,O",
                boost::program_options::value<std::int32_t>(&opt)->default_value(0),
                "optimization level")(
                "include-path,I",
                // composing() 告诉库将来自不同位置的值合并到一起
                boost::program_options::value<std::vector<std::string>>()->composing(),
                "include path");

        boost::program_options::options_description hidden("Hidden options");
        hidden.add_options()(
                "input-file", boost::program_options::value<std::vector<std::string>>(),
                "input file");

        boost::program_options::options_description cmdline_options;
        cmdline_options.add(generic).add(config).add(hidden);

        boost::program_options::options_description visible("Allowed options");
        visible.add(generic).add(config);

        boost::program_options::positional_options_description p;
        p.add("input-file", -1);

        boost::program_options::variables_map vm;
        store(boost::program_options::command_line_parser(argc, argv)
                      .options(cmdline_options)
                      .positional(p)
                      .run(),
              vm);
        notify(vm);

        if (vm.contains("help")) {
            std::cout << visible << "\n";
            return EXIT_SUCCESS;
        }

        if (opt != 0) {
            std::cout << "optimization: " << opt << '\n';
        }

        if (vm.contains("include-path")) {
            std::cout << "include-path: " << '\n';
            for (const auto& item :
                 vm["include-path"].as<std::vector<std::string>>()) {
                std::cout << item << '\n';
            }
        }

        if (vm.contains("input-file")) {
            std::cout << "input-file: " << '\n';
            for (const auto& item : vm["input-file"].as<std::vector<std::string>>()) {
                std::cout << item << '\n';
            }
        }
    }
    catch (const std::exception& err) {
        std::cerr << err.what() << "\n";
        return EXIT_FAILURE;
    }
}
