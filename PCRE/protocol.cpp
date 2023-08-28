#include <iostream>
#include <string>
#include <regex>

int main () {
    std::string str, res;
    std::cmatch result;
    std::regex regular("(\\w+)([^:]+)");
    std::cin >> str;
    if (std::regex_search(str.c_str(), result, regular)) {
        res = result[0].str();
        for (size_t i = 0; i < res.size(); ++i) {
            res[i] = std::tolower(res[i]);
        }
        std::cout << res << std::endl;
    }

    return 0;
}