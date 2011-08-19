#include <iostream>
#include <cstdio>
using namespace std;

int setbit(int R, int x, int y) 
{ 
    y = y - 2; 
    R = (R & (0xFFFFFFFF - (7<<y) - (1<<x))) + (6<<y); 

    return R; 
}

int main(int argc, char *argv[])
{
    int n;
    cin >> n;

    int r, x, y;

    while (--n >= 0) {
        scanf("%x,%d,%d", &r, &x, &y);
        printf("%x\n", setbit(r, x, y));
    }

    return 0;
}
