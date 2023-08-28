#include <algorithm>
#include <iostream>
#include <map>

int main () {
    std::map<std::string, std::int64_t> map;
    size_t n;
    std::cin >> n;
    for (size_t i = 0; i < n; ++i) {
        std::string str;
        std::cin >> str;
        for (size_t j = 0; j < str.size(); ++j) {
            str[j] = std::tolower(str[j]);
        }
        ++map[str];
    }
    auto popular = *std::max_element(map.begin(), map.end(), [](const auto& lhs, const auto& rhs) { return lhs.second < rhs.second; });
    std::cout << popular.first << " " << popular.second << std::endl;
    return 0;
}