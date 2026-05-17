#include <nlohmann/json.hpp>
#include <curl/curl.h>
#include <string>
#include <iostream>

static size_t write_cb(char* ptr, size_t size, size_t nmemb, std::string* data) {
    data->append(ptr, size * nmemb);
    return size * nmemb;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <language-code>\n";
        std::cerr << "Example: " << argv[0] << " fr\n";
        return 1;
    }

    std::string url =
        "https://translate.googleapis.com/translate_a/single"
        "?client=gtx&sl=en&dt=t&q=Hello+World&tl=";
    url += argv[1];

    CURL* curl = curl_easy_init();
    if (!curl) {
        std::cerr << "Failed to initialize curl\n";
        return 1;
    }

    std::string response;
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_cb);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        std::cerr << "curl error: " << curl_easy_strerror(res) << "\n";
        return 1;
    }

    // Response format: [[[translated, original, ...],...], ...]
    auto json = nlohmann::json::parse(response);
    std::cout << json[0][0][0].get<std::string>() << "\n";
}
