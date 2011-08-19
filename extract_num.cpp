#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

const int MAX = 1024;

int main(int argc, char *argv[])
{
    freopen("str.in", "r", stdin);
    freopen("str.out", "w", stdout);

    char buf[MAX];
    int num[MAX];
    int i = 0;
    char *token;
    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        token = strtok(buf, " ");
        while (token != NULL) {
            num[i++] = atoi(token);
            token = strtok(NULL, " ");
        }
    }

    for (int j = 0; j < i; j++) {
        cout << num[j] << " ";
    }

    return 0;
}
