/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-22 17:19:36
 * @ Modified time: 2020-05-22 17:45:51
 */

#include <iostream>
#include <string>

#include <cmdline.h>

int main(int argc, char *argv[]) {
  // create a parser
  cmdline::parser a;

  // add specified type of variable.
  // 1st argument is long name
  // 2nd argument is short name (no short name if '\0' specified)
  // 3rd argument is description
  // 4th argument is mandatory (optional. default is false)
  // 5th argument is default value  (optional. it used when mandatory is false)
  a.add<std::string>("host", 'h', "host name", true, "");

  // 6th argument is extra constraint.
  // Here, port number must be 1 to 65535 by cmdline::range().
  a.add<int>("port", 'p', "port number", false, 80, cmdline::range(1, 65535));

  // cmdline::oneof() can restrict options.
  a.add<std::string>(
      "type", 't', "protocol type", false, "http",
      cmdline::oneof<std::string>("http", "https", "ssh", "ftp"));

  // Boolean flags also can be defined.
  // Call add method without a type parameter.
  a.add("gzip", '\0', "gzip when transfer");

  a.footer("filename ...");
  a.set_program_name("test");

  // Run parser.
  // It returns only if command line arguments are valid.
  // If arguments are invalid, a parser output error msgs then exit program.
  // If help flag ('--help' or '-?') is specified, a parser output usage message
  // then exit program.
  a.parse_check(argc, argv);

  // use flag values
  std::cout << a.get<std::string>("type") << "://" << a.get<std::string>("host")
            << ":" << a.get<int>("port") << '\n';

  // boolean flags are referred by calling exist() method.
  if (a.exist("gzip")) {
    std::cout << "gzip\n";
  }

  for (const auto &item : a.rest()) {
    std::cout << "- " << item << '\n';
  }
}
