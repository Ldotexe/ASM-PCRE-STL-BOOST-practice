#include <iostream>
#include <vector>

int main () {
    size_t n;
    std::cin >> n;
    std::vector<size_t> weights(n);
    std::vector<size_t> num(n);
    for (size_t i = 0; i < n; ++i) {
        size_t v, w;
        std::cin >> v >> w >> w;
        weights[v] += w;
        ++num[v];
    }
    for (size_t i = 0; i < n; ++i) {
        if (num[i] > 0) {
            std::cout << i << " " << num[i] << " " << weights[i] << std::endl;
        }
    }
    return 0;
}