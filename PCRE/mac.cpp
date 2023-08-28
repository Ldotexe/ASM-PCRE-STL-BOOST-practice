#include <iostream>
#include <string>
#include <regex>

int main () {
    std::string str;
    std::cmatch result;
    std::regex regular("([A-Za-z0-9]{2})(:)([A-Za-z0-9]{2})(:)([A-Za-z0-9]{2})(:)([A-Za-z0-9]{2})(:)([A-Za-z0-9]{2})(:)([A-Za-z0-9]{2})");
    while (std::cin >> str) {
        if (std::regex_search(str.c_str(), result, regular)) {
            std::cout << result[0] << std::endl;
        }
    }

    return 0;
}