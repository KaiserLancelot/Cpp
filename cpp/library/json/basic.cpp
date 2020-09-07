/**
 * @ Author: KaiserLancelot
 * @ Create Time: 2020-05-25 04:55:28
 * @ Modified time: 2020-05-25 05:47:54
 */

#include <fstream>
#include <iostream>

#include <nlohmann/json.hpp>

int main()
{
    nlohmann::json json;

    json["pi"] = 3.141;
    json["happy"] = true;
    json["name"] = "Niels";
    json["nothing"] = nullptr;
    // "answer": {"everything" : 42}
    json["answer"]["everything"] = 42;
    json["list"] = {1, 0, 2};
    // "object": {"currency" : "USD", "value" : 42.99}
    json["object"] = {{"currency", "USD"}, {"value", 42.99}};
    // "array": [["currency","USD"],["value",42.99]]
    json["array"] =
            nlohmann::json::array({{"currency", "USD"}, {"value", 42.99}});

    std::ofstream ofs{"test.json"};
    ofs << json.dump(2);

    std::ifstream ifs{"in.json"};
    nlohmann::json json2;
    ifs >> json2;
    std::cout << json2["pi"] << '\n';
}
