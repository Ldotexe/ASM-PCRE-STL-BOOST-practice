#include <iostream>
#include <set>

int main () {
    std::set<int> s;
    int n;
    int num;
    std::cin >> n;
    while (n--) {
        std::cin >> num;
        s.insert(num);
    }
    std::cout << s.size() << std::endl;
    return 0;
}