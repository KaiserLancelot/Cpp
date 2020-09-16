//
// Created by kaiser on 18-12-21.
//

#include "ex_13_42.h"

#include <sstream>

TextQuery::TextQuery(std::ifstream& input) : text_{std::make_shared<StrVec>()} {
  std::string line;
  LineNo line_number{1};

  while (std::getline(input, line)) {
    text_->PushBack(line);
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

QueryResult TextQuery::Query(const std::string& s) {
  static auto nodata{std::make_shared<std::set<LineNo>>()};

  auto iter{words_and_line_number_.find(s)};
  if (iter == std::end(words_and_line_number_)) {
    return QueryResult{s, text_, nodata};
  } else {
    return QueryResult{s, text_, iter->second};
  }
}

QueryResult::QueryResult(const std::string& word,
                         const std::shared_ptr<StrVec>& text,
                         const std::shared_ptr<std::set<LineNo>>& line_number)
    : word_{word}, text_{text}, line_number_{line_number} {}

QueryResult::ResultIterator QueryResult::Begin() const {
  return std::begin(*line_number_);
}

QueryResult::ResultIterator QueryResult::End() const {
  return std::end(*line_number_);
}

std::shared_ptr<StrVec> QueryResult::GetFile() const { return text_; }

std::ostream& Print(std::ostream& os, QueryResult qr) {
  os << qr.word_ << " occurs " << std::size(*qr.line_number_)
     << (std::size(*qr.line_number_) > 1 ? " times" : " time") << '\n';

  for (auto i : *qr.line_number_) {
    os << "\t(line " << i << ") " << *(qr.text_->begin() + (i - 1)) << '\n';
  }

  return os;
}
