#include <iostream>
#include <string>
#include <regex>

int main () {
    std::string str;
    std::regex regular ("(\\(\\))?");
    std::cmatch result;
    std::cin >> str;
    for (size_t size = str.size(); size != 0; size = str.size()) {
        str = std::regex_replace(str.c_str(), regular, "");
        if (size == str.size()) {
            std::cout << "NO" << std::endl;
            return 0;
        }
    }
    std::cout << "YES" << std::endl;
    return 0; 
}