#include <iostream>
#include <string>
#include <regex>

int main () {
    std::string str;
    std::cmatch result;
    std::regex regular("(\\d+)(\\.)(\\d+)(\\.)(\\d+)(\\.)(\\d+)");
    while (std::cin >> str) {
        if (std::regex_search(str.c_str(), result, regular)) {
            std::cout << result[0] << std::endl;
        }
    }

    return 0;
}