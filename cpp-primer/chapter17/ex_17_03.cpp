//
// Created by kaiser on 19-3-10.
//

#include "ex_17_03.h"

#include <sstream>

TextQuery::TextQuery(std::ifstream &input)
    : text_{std::make_shared<std::vector<std::string>>()} {
  std::string line;
  LineNo line_number{1};

  while (std::getline(input, line)) {
    text_->push_back(line);
    std::istringstream iss{line};
    std::string word;

    while (iss >> word) {
      if (!words_and_line_number_[word]) {
        words_and_line_number_[word] = std::make_shared<std::set<LineNo>>();
      }
      words_and_line_number_[word]->insert(line_number);
    }
    ++line_number;
  }
}

QueryResult TextQuery::Query(const std::string &s) {
  static auto nodata{std::make_shared<std::set<LineNo>>()};

  auto iter{words_and_line_number_.find(s)};
  if (iter == std::end(words_and_line_number_)) {
    return {s, text_, nodata};
  } else {
    return {s, text_, iter->second};
  }
}

std::ostream &Print(std::ostream &os, QueryResult qr) {
  os << std::get<0>(qr) << " occurs " << std::size(*std::get<2>(qr))
     << (std::size(*std::get<2>(qr)) > 1 ? " times" : " time") << '\n';

  for (auto i : *std::get<2>(qr)) {
    os << "\t(line " << i << ") " << (*std::get<1>(qr))[i - 1] << '\n';
  }

  return os;
}