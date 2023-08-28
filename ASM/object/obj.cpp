#include <iostream>
#include <string.h>

int main () {
    long long size = 10000;
    char* buf = (char*) malloc(size * sizeof(char));
    long long file_size = fread(buf, sizeof(char), size, stdin);
    char* crack = (char*)memmem(buf, size, "\xd9\x45\x08", 3);
    crack[4] = '\xeb';
    crack[5] = '\x90';
    crack[6] = '\xde';
    crack[7] = '\xc9';
    fwrite (buf, sizeof(char), file_size, stdout);
    free(buf);
}