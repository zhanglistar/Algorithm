/*
 * eight queee iteration solution.
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <sys/time.h>
#include <cstdio>
using namespace std;

const int boardsize= 8;

void init(vector<int> & s)
{
    for (int i = 0; i < s.size(); i++) 
        s[i] = i;
    
}

bool check(vector<int> & a)
{
    for (int i = 0; i < a.size(); i++) {
        for (int j = i+1; j < a.size(); j++) {
            if ((a[i] == a[j]) || (abs(a[i]-a[j]) == j-i)) {
                return false;
            }
        }
    }
    
    return true;
}

void show(const vector<int> & a)
{
    for (int i = 0; i < a.size(); i++) 
        printf("%d\t", a[i]);
        //cout << a[i] << "\t";
    
    printf("\n");
    //cout << endl;
}

int putqueen(vector<int> & a)
{
    int num = 0;
    while (next_permutation(a.begin(), a.end())) 
        if (check(a)) {
            //show(a);
            num++;
        }

    return num;
}

bool check(vector<int> a, int n)
{
    for (int i = 0; i < n; i++) 
        if (a[i] == a[n] || n-i == abs(a[i] - a[n])) 
            return false;
        
    return true;
}

int putqueen_recur(vector<int> & a, int n = 0)
{
    static int solu = 0;
    if (n == a.size()) { 
        //show(a);
        solu++;
    }
    else {
        for (int i = 0; i < a.size(); i++) {
            a[n] = i; 
            if (check(a, n)) 
                putqueen_recur(a, n+1);
        }
    }
    return solu;
}


int main(int argc, char *argv[])
{
    int re;
    struct timeval st, en;
    gettimeofday(&st, NULL);
    vector<int> board(boardsize);

#if 0
    init(board);
    re = putqueen(board);
#endif

#if 1
    re = putqueen_recur(board);
#endif
    cout << "There are totally " << re;
    cout << " solutions.\n";
    gettimeofday(&en, NULL);
    cout << "Total time is " << (en.tv_sec - st.tv_sec) * 1000.0 + 
        (en.tv_usec - st.tv_usec) / 1000.0 << "ms" << endl;

    return 0;
}
