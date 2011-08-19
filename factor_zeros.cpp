/*
 *计算一个数的阶乘结果末尾有多少个零 
 */
#include <iostream>
#include <cstdio>
using namespace std;

int count_zero(int n);

int main(int argc, char *argv[])
{
    int n;
    while (cin >> n && n > 0) {
        cout << "There are " << count_zero(n) << " zeros\n";
    }

    return 0;
}

int count_zero(int n)
{
    int ret = 0;
    while (n > 0) {
        ret += n/5;
        n /= 5;
    }

    return ret;
}
