#include <stdio.h>

int main () {
    unsigned char IP[4];
    unsigned char mask[4];
    unsigned char answer[4];
    scanf ("%hhu.%hhu.%hhu.%hhu" , &IP[0], &IP[1], &IP[2], &IP[3]);
    scanf ("%hhu.%hhu.%hhu.%hhu" , &mask[0], &mask[1], &mask[2], &mask[3]);
    for (size_t i = 0; i < 4; i++) {
        answer[i] = IP[i] & mask[i];
        mask[i] = ~mask[i];
        answer[i] |= mask[i];
    }
    printf ("%hhu.%hhu.%hhu.%hhu\n", answer[0], answer[1], answer[2], answer[3]);
    
    return 0;
}