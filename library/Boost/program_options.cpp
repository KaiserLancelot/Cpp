//
// Created by kaiser on 19-3-20.
//

#include <cstdint>
#include <iostream>

#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/variables_map.hpp>

int main(int argc, char *argv[]) {
  try {
    std::int32_t val;

    boost::program_options::options_description desc{"Usage"};
    desc.add_options()("help,h", "Display Display help information");
    desc.add_options()("optimization,O",
                       boost::program_options::value<std::int32_t>(&val),
                       "Specify optimization level(O0,O1,O2,O3)");
    desc.add_options()(
        "files,f", boost::program_options::value<std::vector<std::string>>(),
        "input files");

    boost::program_options::positional_options_description p;
    p.add("files", -1);

    boost::program_options::variables_map vm;
    boost::program_options::store(
        boost::program_options::command_line_parser(argc, argv)
            .options(desc)
            .positional(p)
            .run(),
        vm);
    boost::program_options::notify(vm);

    if (vm.empty()) {
      std::cout << desc << '\n';
    }

    if (vm.count("optimization")) {
      std::cout << val << '\n';
    }

    if (vm.count("files")) {
      auto input_files = vm["files"].as<std::vector<std::string>>();
      for (const auto &item : input_files) {
        std::cout << item << ' ';
      }
      std::cout << '\n';
    }

  } catch (const boost::program_options::unknown_option &error) {
    std::cerr << error.what() << '\n';
  }
}