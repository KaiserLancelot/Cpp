//
// Created by kaiser on 19-3-20.
//

#include <cstdlib>
#include <iostream>

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QTextStream>
#include <QVariant>

int main() {
  // {}
  QJsonObject root;
  root["encoding"] = "UTF-8";

  // []
  QJsonArray plug_ins;
  plug_ins.append("python");
  plug_ins.append("C++");
  plug_ins.append("ruby");
  root["plug-ins"] = plug_ins;

  QJsonObject indent;
  indent["length"] = 3;
  indent["use_space"] = true;
  root["indent"] = indent;

  QFile file{"test.json"};
  if (!file.open(QIODevice::WriteOnly)) {
    std::cerr << "Open file failed\n";
    return EXIT_FAILURE;
  }
  QTextStream out{&file};

  QJsonDocument document{root};
  out << document.toJson();
}
