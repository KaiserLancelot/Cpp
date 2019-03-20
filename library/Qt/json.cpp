//
// Created by kaiser on 19-3-20.
//

#include <fstream>
#include <iostream>

#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
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

  QJsonDocument document{root};
  std::ofstream ofs{"test.json"};
  ofs << document.toJson().toStdString();
  ofs.close();

  std::ifstream ifs{"test.json"};
  std::string json{std::istreambuf_iterator<char>{ifs}, {}};

  QJsonParseError error;
  QJsonDocument json_document{
      QJsonDocument::fromJson(QString::fromStdString(json).toUtf8(), &error)};
  if (error.error == QJsonParseError::NoError) {
    QVariantMap result{json_document.toVariant().toMap()};

    std::cout << "encoding: " << result["encoding"].toString().toStdString()
              << '\n';

    std::cout << "plugins:";
    for (const auto &plugin : result["plug-ins"].toList()) {
      std::cout << " " << plugin.toString().toStdString();
    }
    std::cout << '\n';

    QVariantMap nestedMap{result["indent"].toMap()};
    std::cout << "length: " << nestedMap["length"].toInt();
    std::cout << '\t';
    std::cout << "use_space: " << std::boolalpha
              << nestedMap["use_space"].toBool();
  }
}