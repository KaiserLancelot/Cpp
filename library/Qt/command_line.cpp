//
// Created by kaiser on 19-3-23.
//

#include <QCommandLineParser>
#include <QCoreApplication>
#include <cstdint>
#include <iostream>

int main(int argc, char *argv[]) {
  QCoreApplication app{argc, argv};
  QCoreApplication::setApplicationName("CommandLineTest");
  QCoreApplication::setApplicationVersion("1.0");

  QCommandLineParser parser;
  parser.setApplicationDescription("Test helper");
  parser.addHelpOption();
  parser.addVersionOption();
  parser.addPositionalArgument("files", "Source file to compile");
  parser.addOptions(
      {{"S", "Only run preprocess and compilation steps"},
       {"O", "Specify optimization level(O0,O1,O2,O3)", "level"}});

  parser.process(app);

  if (parser.isSet("S")) {
    std::cout << "-S is set\n";
  }

  std::cout << parser.value("O").toInt() << '\n';

  for (const auto &item : parser.positionalArguments()) {
    std::cout << item.toStdString() << '\n';
  }
}