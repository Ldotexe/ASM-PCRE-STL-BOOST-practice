#include <algorithm>
#include <cstdio>
#include <cinttypes>
#include <vector>

int main () {
    int n = 0;
    scanf("%d", &n);
    std::vector<int> times;
    times.resize(n);
    int h, m, t;
    for (int i = 0; i < n; ++i) {
        scanf("%d:%d %d", &h, &m, &t);
        times[i] = (h * 60 + m + t) % (24 * 60);
    }
    std::sort(times.begin(), times.end());
    for (int i = 0; i < n; ++i) {
        h = times[i] / 60;
        m = times[i] % 60;
        if (h < 10) {
            printf("0");
        }
        printf("%d:", h);
        if (m < 10) {
            printf ("0");
        }
        printf ("%d\n", m);
    }

    return 0;
}