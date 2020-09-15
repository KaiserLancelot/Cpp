#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

#include <curl/curl.h>

std::size_t callback_func_std_string(void* contents, std::size_t size,
                                     std::size_t nmemb, std::vector<std::string>* s)
{
    s->emplace_back(static_cast<char*>(contents), static_cast<char*>(contents) + size * nmemb);
    return size * nmemb;
}

int main()
{
    std::vector<std::string> result;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    if (auto curl{curl_easy_init()}; curl) {
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.esjzone.cc/forum/1599125532/91871.html");
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 2);

        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, callback_func_std_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);

        auto res{curl_easy_perform(curl)};
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << '\n';
        }

        curl_easy_cleanup(curl);
    }
    curl_global_cleanup();

    for (const auto& s : result) {
        std::cout << s;
    }
}
