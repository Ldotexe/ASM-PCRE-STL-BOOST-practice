#include <stdio.h>

int main () {
    int h1, m1, h2, m2;
    scanf("%d:%d", &h1, &m1);
    scanf("%d:%d", &h2, &m2);
    h1 = (h1 + h2 + (m1 + m2) / 60) % 24;
    m1 = (m1 + m2) % 60;
    if (h1 < 10) {
        printf("0");
    }
    printf("%d:", h1);
    if (m1 < 10) {
        printf ("0");
    }
    printf ("%d\n", m1);
    return 0;
}