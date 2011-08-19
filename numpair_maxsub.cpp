#include <iostream>
using namespace std;


int MaxDiff_Solution3(int numbers[], unsigned length);
int main(int argc, char *argv[])
{
    int num[] = {2, 4, 1, 16, 7, 5, 11, 9};
    cout << MaxDiff_Solution3(num, sizeof(num)/sizeof(num[0])) << endl;
}

int MaxDiff_Solution3(int numbers[], unsigned length)
{
    if(numbers == NULL && length < 2)
        return 0;
 
    int max = numbers[0];
    int maxDiff =  max - numbers[1];
 
    for(int i = 2; i < length; ++i)
    {
        if(numbers[i - 1] > max)
            max = numbers[i - 1];
 
        int currentDiff = max - numbers[i];
        if(currentDiff > maxDiff)
            maxDiff = currentDiff;
    }
 
    return maxDiff;
}
