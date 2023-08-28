#include <iostream>
#include <string>

int main () {
    std::string str;
    int counter = 0;
    std::cin >> str;
    for (size_t i = 0; i < str.size(); ++i) {
        if (str[i] == '(') {
            ++counter;
        }
        if (str[i] == ')') {
            --counter;
            if (counter < 0) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
    }
    if (counter != 0) {
        std::cout << "NO" << std::endl;
        return 0;
    }
    std::cout << "YES" << std::endl;
    return 0;
}