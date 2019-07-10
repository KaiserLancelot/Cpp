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
  file.close();

  if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
    std::cerr << "Open file failed\n";
    return EXIT_FAILURE;
  }

  QTextStream in{&file};
  QString json{in.readAll()};

  QJsonParseError error;
  auto json_document{QJsonDocument::fromJson(json.toUtf8(), &error)};
  if (error.error == QJsonParseError::NoError) {
    auto result{json_document.toVariant().toMap()};

    std::cout << "encoding: " << result["encoding"].toString().toStdString()
              << '\n';

    std::cout << "plugins:";
    for (const auto &plugin : result["plug-ins"].toList()) {
      std::cout << " " << plugin.toString().toStdString();
    }
    std::cout << '\n';

    auto nested_map{result["indent"].toMap()};
    std::cout << "length: " << nested_map["length"].toInt();
    std::cout << '\t';
    std::cout << "use_space: " << std::boolalpha
              << nested_map["use_space"].toBool();
  }
}
