#include <iostream>
#include <string.h>

int main () {
    FILE *file = fopen("source", "rb");
    FILE *out = fopen ("cracked", "wb");
    fseek(file, 0, SEEK_END);
    long long size = ftell(file);
    rewind(file);
    char* buf = (char*) malloc(size * sizeof(char));
    fread(buf, sizeof(char), size, file);
    char* crack = (char*)memmem(buf, size, "\x00\xca\x9a\x3b", 2);
    crack[3] = '\x77';

    fwrite(buf, sizeof(char), size, out);
    free(buf);
    fclose(file);
    fclose(out);
}