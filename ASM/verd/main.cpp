#include <iostream>

int change (int x) {
    return x ^ 0x756E6547 ^ 0x49656E69 ^ 0x6C65746E ^ 0x68747541 ^ 0x69746E65 ^ 0x444D4163;
}

int main () {
    int x;
    std::cin >> x;
    std::cout << change(x);
    return 0;
}