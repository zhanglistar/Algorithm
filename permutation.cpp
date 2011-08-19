#include <iostream>
#include <cstdio>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *array, int len, int cur)
{
    if (cur >= len-1) {
        for (int i = 0; i < len; i++) {
            cout << array[i] << ' ';
        }
        cout << endl;
    }

    for (int i = cur; i < len; i++) {
        swap(&array[i], &array[cur]);
        permutation(array, len, i+1);
        swap(&array[i], &array[cur]);
    }
    
}

int main(int argc, char *argv[])
{
    int arr[] = {3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 16, 15, 13, 15, 13};
    int len = sizeof(arr)/sizeof(arr[0]);
    permutation(arr, len, 0);

    return 0;
}
