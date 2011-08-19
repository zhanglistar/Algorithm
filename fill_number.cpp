#include <iostream>
#include <cstdio>
#include <assert.h>
#include <string.h>
#include <sys/time.h>
using namespace std;

int n = 0;
const int MAX = 16+1;
int number[MAX][MAX];

bool check(int num, int row, int col, int len)
{
    assert(row >= 0 && col >= 0);
    for (int i = 0; i < col; i++)
        if (number[row][i] > num)
            return false;
    for (int i = 0; i < row; i++)
        if (number[i][col] > num)
            return false;
    return true;       
}

void fill_number(int num, bool *visit, int cur)
{
    if (cur >= num*num-1)
    {
        number[0][0] = 1;
        number[num-1][num-1] = num*num;
        visit[1] = visit[num*num] = true;
        for (int i = 0; i < num; i++)
        {
            for (int j = 0; j < num; j++)
                cout << number[i][j] << ' ';
            cout << endl;
        }
        cout << endl;
        n++;
        return;
    }
    
    for (int i = 2; i < num*num; i++)
    {
        if (cur < num*num && visit[i] == false && check(i, cur/num, cur%num, num)) 
        {
            number[cur/num][cur%num] = i;
            visit[i] = true;
            fill_number(num, visit, cur+1);
            visit[i] = false;
        }
    }
}

int main(int argc, char *argv[])
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    int count;
    freopen("out.txt", "w", stdout);
    cin >> count;
    bool visited[MAX*MAX];
    int number[MAX][MAX];
    
    memset(visited, 0, sizeof(visited));
    number[0][0] = 1;
    number[count-1][count-1] = count * count;
    visited[1] = visited[count*count] = true;
    fill_number(count, visited, 1);
    cout << n << endl;
    gettimeofday(&end, NULL);
    cout << (end.tv_sec-start.tv_sec + (end.tv_usec-start.tv_usec)/1000000) << endl;
    fclose(stdout);
    return 0;
}
