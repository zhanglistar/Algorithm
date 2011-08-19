#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WORDMAX 100

int char_comp(const void *a, const void *b)
{
    return *(char *)a - *(char *)b;
}

int main(int argc, char *argv[])
{
    char word[WORDMAX], sig[WORDMAX];

    while (scanf("%s", word) != EOF) {
        strcpy(sig, word);
        qsort(sig, strlen(sig), sizeof(char), char_comp);
        printf("%s %s\n", sig, word);
    }

    return 0;
}
