//
// Created by kaiser on 19-4-15.
//

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iostream>
#include <iterator>
#include <memory>
#include <set>
#include <string>

class Lexicon {
 public:
  using ConstIterator = std::set<std::string>::const_iterator;

  explicit Lexicon(const std::string& filename);

  bool contains_word(const std::string& word) const;
  bool contains_prefix(const std::string& prefix) const;

  void add_word(const std::string& word) {
    ensure_unique();
    all_words_->insert(word);
  }

  ConstIterator begin() const { return all_words_->begin(); }
  ConstIterator end() const { return all_words_->end(); }

 private:
  std::shared_ptr<std::set<std::string>> all_words_{
      std::make_shared<std::set<std::string>>()};

  void ensure_unique() {
    if (!all_words_.unique())
      all_words_ = std::make_shared<std::set<std::string>>(*all_words_);
  }
};

std::string convert_to_lower_case(const std::string& str) {
  std::string result(str);
  transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

Lexicon::Lexicon(const std::string& filename) {
  std::ifstream input{filename};
  all_words_->insert(std::istream_iterator<std::string>{input}, {});
}

bool Lexicon::contains_word(const std::string& word) const {
  return all_words_->find(convert_to_lower_case(word)) != all_words_->end();
}

bool Lexicon::contains_prefix(const std::string& prefix) const {
  const std::string lower_prefix(convert_to_lower_case(prefix));

  auto itr = all_words_->lower_bound(lower_prefix);

  if (itr == all_words_->end()) {
    return false;
  } else {
    return itr->compare(0, lower_prefix.size(), lower_prefix) == 0;
  }
}

int main() {
  Lexicon lexicon{"story"};
  for (const auto& item : lexicon) {
    std::cout << item << '\n';
  }
}
