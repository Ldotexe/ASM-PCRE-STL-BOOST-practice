#include <iostream>
#include <algorithm>
#include <set>

int main () {
    size_t n;
    std::cin >> n;
    std::set<std::string> strs;
    for (size_t i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        for (size_t j = 0; j < str.size(); ++j) {
            str[j] = std::tolower(str[j]);
        }
        strs.insert(str);
    }
    for (auto i = strs.rbegin(); i != strs.rend(); i++) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}