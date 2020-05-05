//
// Created by kaiser on 2020/4/27.
//

// TODO learn json

#include <cstdint>
#include <deque>
#include <forward_list>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#include <nlohmann/json.hpp>

int main() {
  {
    // create an empty structure (null)
    nlohmann::json j;

    // add a number that is stored as double (note the implicit conversion of j
    // to an object)
    j["pi"] = 3.141;

    // add a Boolean that is stored as bool
    j["happy"] = true;

    // add a string that is stored as std::string
    j["name"] = "Niels";

    // add another null object by passing nullptr
    j["nothing"] = nullptr;

    // add an object inside the object
    j["answer"]["everything"] = 42;

    // add an array that is stored as std::vector (using an initializer list)
    j["list"] = {1, 0, 2};

    // add another object (using an initializer list of pairs)
    j["object"] = {{"currency", "USD"}, {"value", 42.99}};

    // instead, you could also write (which looks very similar to the JSON
    // above)
    nlohmann::json j2 = {{"pi", 3.141},
                         {"happy", true},
                         {"name", "Niels"},
                         {"nothing", nullptr},
                         {"answer", {{"everything", 42}}},
                         {"list", {1, 0, 2}},
                         {"object", {{"currency", "USD"}, {"value", 42.99}}}};
  }

  {
    // a way to express the empty array []
    nlohmann::json empty_array_explicit = nlohmann::json::array();
    // ways to express the empty object {}
    nlohmann::json empty_object_explicit = nlohmann::json::object();

    auto j3 = R"(
  {
    "happy": true,
    "pi": 3.141
  }
)"_json;
  }

  {
    // store a string in a JSON value
    nlohmann::json j_string = "this is a string";

    // retrieve the string value
    auto cpp_string = j_string.get<std::string>();
    // retrieve the string value (alternative when an variable already exists)
    std::string cpp_string2;
    j_string.get_to(cpp_string2);

    // retrieve the serialized value (explicit JSON serialization)
    std::string serialized_string = j_string.dump();

    // output of original string
    std::cout << cpp_string << " == " << cpp_string2
              << " == " << j_string.get<std::string>() << '\n';
    // output of serialized value
    std::cout << j_string << " == " << serialized_string << std::endl;
  }

  {
    std::vector<std::uint8_t> v{'t', 'r', 'u', 'e'};
    auto json{nlohmann::json::parse(v)};
  }

  {
    // create an array using push_back
    nlohmann::json j;
    j.push_back("foo");
    j.push_back(1);
    j.push_back(true);

    // also use emplace_back
    j.emplace_back(1.78);

    // iterate the array
    for (nlohmann::json::iterator it = j.begin(); it != j.end(); ++it) {
      std::cout << *it << '\n';
    }

    // range-based for
    for (auto& element : j) {
      std::cout << element << '\n';
    }

    //   // getter/setter
    //   const auto tmp = j[0].get<std::string>();
    //   j[1] = 42;
    //   bool foo = j.at(2);

    //   // comparison
    //   j == "[\"foo\", 42, true]"_json;  // true

    //   // other stuff
    //   j.size();   // 3 entries
    //   j.empty();  // false
    //   j.type();   // json::value_t::array
    //   j.clear();  // the array is empty again

    //   // convenience type checkers
    //   j.is_null();
    //   j.is_boolean();
    //   j.is_number();
    //   j.is_object();
    //   j.is_array();
    //   j.is_string();

    //   // create an object
    //   nlohmann::json o;
    //   o["foo"] = 23;
    //   o["bar"] = false;
    //   o["baz"] = 3.141;

    //   // also use emplace
    //   o.emplace("weather", "sunny");

    //   // special iterator member functions for objects
    //   for (nlohmann::json::iterator it = o.begin(); it != o.end(); ++it) {
    //     std::cout << it.key() << " : " << it.value() << "\n";
    //   }

    //   // the same code as range for
    //   for (auto& el : o.items()) {
    //     std::cout << el.key() << " : " << el.value() << "\n";
    //   }

    //   // even easier with structured bindings (C++17)
    //   for (auto& [key, value] : o.items()) {
    //     std::cout << key << " : " << value << "\n";
    //   }

    //   // find an entry
    //   if (o.find("foo") != o.end()) {
    //     // there is an entry with key "foo"
    //   }

    //   // or simpler using count()
    //   int foo_present = o.count("foo");  // 1
    //   int fob_present = o.count("fob");  // 0

    //   // delete an entry
    //   o.erase("foo");
    // }

    // {
    //   std::vector<int> c_vector{1, 2, 3, 4};
    //   nlohmann::json j_vec(c_vector);
    //   // [1, 2, 3, 4]

    //   std::deque<double> c_deque{1.2, 2.3, 3.4, 5.6};
    //   nlohmann::json j_deque(c_deque);
    //   // [1.2, 2.3, 3.4, 5.6]

    //   std::list<bool> c_list{true, true, false, true};
    //   nlohmann::json j_list(c_list);
    //   // [true, true, false, true]

    //   std::forward_list<int64_t> c_flist{12345678909876, 23456789098765,
    //                                      34567890987654, 45678909876543};
    //   nlohmann::json j_flist(c_flist);
    //   // [12345678909876, 23456789098765, 34567890987654, 45678909876543]

    //   std::array<unsigned long, 4> c_array{{1, 2, 3, 4}};
    //   nlohmann::json j_array(c_array);
    //   // [1, 2, 3, 4]

    //   std::set<std::string> c_set{"one", "two", "three", "four", "one"};
    //   nlohmann::json j_set(c_set);  // only one entry for "one" is used
    //                                 // ["four", "one", "three", "two"]

    //   std::unordered_set<std::string> c_uset{"one", "two", "three", "four",
    //                                          "one"};
    //   nlohmann::json j_uset(c_uset);  // only one entry for "one" is used
    //                                   // maybe ["two", "three", "four",
    //                                   "one"]

    //   std::multiset<std::string> c_mset{"one", "two", "one", "four"};
    //   nlohmann::json j_mset(c_mset);  // both entries for "one" are used
    //                                   // maybe ["one", "two", "one", "four"]

    //   std::unordered_multiset<std::string> c_umset{"one", "two", "one",
    //   "four"}; nlohmann::json j_umset(c_umset);  // both entries for "one"
    //   are used
    //                                     // maybe ["one", "two", "one",
    //                                     "four"]

    //   std::map<std::string, int> c_map{{"one", 1}, {"two", 2}, {"three", 3}};
    //   nlohmann::json j_map(c_map);
    //   // {"one": 1, "three": 3, "two": 2 }

    //   std::unordered_map<const char*, double> c_umap{
    //       {"one", 1.2}, {"two", 2.3}, {"three", 3.4}};
    //   nlohmann::json j_umap(c_umap);
    //   // {"one": 1.2, "two": 2.3, "three": 3.4}

    //   std::multimap<std::string, bool> c_mmap{
    //       {"one", true}, {"two", true}, {"three", false}, {"three", true}};
    //   nlohmann::json j_mmap(c_mmap);  // only one entry for key "three" is
    //   used
    //   // maybe {"one": true, "two": true, "three": true}

    //   std::unordered_multimap<std::string, bool> c_ummap{
    //       {"one", true}, {"two", true}, {"three", false}, {"three", true}};
    //   nlohmann::json j_ummap(c_ummap);  // only one entry for key "three" is
    //   used
    //   // maybe {"one": true, "two": true, "three": true}
    // }

    // // example enum type declaration
    // enum TaskState {
    //   kTsStopped,
    //   kTsRunning,
    //   kTsCompleted,
    //   kTsInvalid = -1,
    // };

    // // map TaskState values to JSON as strings
    // NLOHMANN_JSON_SERIALIZE_ENUM(TaskState, {
    //                                             {TS_INVALID, nullptr},
    //                                             {TS_STOPPED, "stopped"},
    //                                             {TS_RUNNING, "running"},
    //                                             {TS_COMPLETED, "completed"},
    //                                         });
    // // enum to JSON as string
    // nlohmann::json j = kTsStopped;
    // assert(j == "stopped");

    // // json string to enum
    // nlohmann::json j3 = "running";
    // assert(j3.get<TaskState>() == kTsRunning);

    // // undefined json value to enum (where the first map entry above is the
    // // default)
    // nlohmann::json jPi = 3.14;
    // assert(jPi.get<TaskState>() == kTsInvalid);

    // // 尽管JSON是一种无处不在的数据格式,
    // 但它不是一种适合通过网络进行数据交换的
    // // 非常紧凑的格式
    // // https://en.wikipedia.org/wiki/CBOR
    // {
    //   auto json{R"({"compact": true, "schema": 0})"_json};
    //   // 序列化为 CBOR
    //   auto v_cbor{nlohmann::json::to_cbor(json)};
    //   // 反序列化
    //   auto j_from_cbor{nlohmann::json::from_cbor(v_cbor)};
    // }
  }
}
