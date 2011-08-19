#include <iostream>
#include <cstdio>
#include <stdlib.h>
using namespace std;

const char *filename = "out.txt";
const int max_size = 10;
const int num = 4;
int number[max_size][max_size];

bool verify()
{
    int min;
    for (int i = 0; i < num; i++) {
        min = number[i][0];
        for (int j = 1; j < num; j++) {
            if (min > number[i][j]) 
                return false;
            else
                min = number[i][j];
        }
        min = number[0][i];
        for (int j = 1; j < num; j++) {
            if (min > number[j][i]) 
                return false;
            else
                min = number[j][i];
        }
    }

    return true;
}

int main(int argc, char *argv[])
{
    int fd;
    char buf[1024];
    FILE *file;
    if ((file = fopen(filename, "r")) == NULL) {
        cout << "fopen failed\n";
        exit(1);
    }

    int count = 0;

    while (feof(file) == 0) {
        for (int i = 0; i < num; i++) {
            fscanf(file, "%d %d %d %d", 
                    &number[i][0], &number[i][1], &number[i][2], &number[i][3]);
        }
        count++;
        fgets(buf, sizeof(buf), file);
        if (verify() == false) {
            cout << count << " line failed.\n";
            exit(1);
        }
    }
    cout << "Success!\n";
    
    return 0;
}
