//
// Created by kaiser on 18-12-19.
//

#include "ex_12_33.h"

#include <sstream>

TextQuery::TextQuery(std::ifstream& input) {
  std::string line;
  LineNo line_number{1};

  while (std::getline(input, line)) {
    text_.push_back(line);
    std::istringstream iss{line};
    std::string word;

    while (iss >> word) {
      if (!words_and_line_number_.contains(word)) {
        words_and_line_number_[word] = std::make_shared<std::set<LineNo>>();
      }
      words_and_line_number_[word]->insert(line_number);
    }
    ++line_number;
  }
}

QueryResult TextQuery::query(const std::string& s) const {
  static auto nodata{std::make_shared<std::set<LineNo>>()};

  auto iter{words_and_line_number_.find(s)};
  if (iter == std::end(words_and_line_number_)) {
    return QueryResult{s, text_, nodata};
  } else {
    return QueryResult{s, text_, iter->second};
  }
}

QueryResult::QueryResult(const std::string& word, const StrBlob& text,
                         const std::shared_ptr<std::set<LineNo>>& line_number)
    : word_{word}, text_{text}, line_number_{line_number} {}

QueryResult::ResultIterator QueryResult::begin() const {
  return std::begin(*line_number_);
}

QueryResult::ResultIterator QueryResult::end() const {
  return std::end(*line_number_);
}

StrBlob QueryResult::get_file() const { return text_; }

std::ostream& print(std::ostream& os, QueryResult qr) {
  os << qr.word_ << " occurs " << std::size(*qr.line_number_)
     << (std::size(*qr.line_number_) > 1 ? " times" : " time") << '\n';

  for (auto i : *qr.line_number_) {
    os << "\t(line " << i << ") " << qr.text_.at(i - 1) << '\n';
  }

  return os;
}

std::ostream& print(std::ostream& os, QueryResult qr, std::size_t begin,
                    std::size_t end) {
  auto size{std::size(*qr.line_number_)};

  os << qr.word_ << " occurs " << size << (size > 1 ? " times" : " time")
     << '\n';

  for (auto i : *qr.line_number_) {
    auto index{i - 1};
    if (index > begin && index < end) {
      os << "\t(line " << i << ") " << qr.text_.at(index) << '\n';
    }
  }

  return os;
}
