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
  using const_iterator = std::set<std::string>::const_iterator;

  explicit Lexicon(const std::string& filename);

  bool ContainsWord(const std::string& word) const;
  bool ContainsPrefix(const std::string& prefix) const;

  void AddWord(const std::string& word) {
    EnsureUnique();
    all_words_->insert(word);
  }

  const_iterator begin() const { return all_words_->begin(); }
  const_iterator end() const { return all_words_->end(); }

 private:
  std::shared_ptr<std::set<std::string>> all_words_{
      std::make_shared<std::set<std::string>>()};

  void EnsureUnique() {
    if (!all_words_.unique())
      all_words_ = std::make_shared<std::set<std::string>>(*all_words_);
  }
};

std::string ConvertToLowerCase(const std::string& str) {
  std::string result(str);
  transform(result.begin(), result.end(), result.begin(), ::tolower);
  return result;
}

Lexicon::Lexicon(const std::string& filename) {
  std::ifstream input{filename};
  all_words_->insert(std::istream_iterator<std::string>{input}, {});
}

bool Lexicon::ContainsWord(const std::string& word) const {
  return all_words_->find(ConvertToLowerCase(word)) != all_words_->end();
}

bool Lexicon::ContainsPrefix(const std::string& prefix) const {
  const std::string lower_prefix(ConvertToLowerCase(prefix));

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
