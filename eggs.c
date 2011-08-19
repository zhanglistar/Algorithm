#include<stdio.h>
#include<stdlib.h>

int m,n;
int ans[20];
int pow2[20];

void print()
{
    int i;

    for(i=1;i<=m;i++)
        printf("%d ",ans[i]);

    printf("\n");
}
/*

    i : 给第i个碗放鸡蛋

    j : 放碗第i个碗后，前i个碗中的总鸡蛋数为j

    k : 第i个碗中放了k个蛋 

*/
void dfs(int i, int j, int k)
{
    int tmp;
    ans[i] = k;

    if(i==m && j==n)

        print();
    else
    {
        if(i>=m || j>=n || k*(m-i)+j>n || pow2[m-i]*j+pow2[m-i]-1<n)
            return;

        for(tmp=k;tmp<=j+1;tmp++)
            dfs(i+1, j+tmp, tmp);
    }

}

int main()
{

    int i,j;
    pow2[0]=1;

    for(i=1;i<20;i++)
        pow2[i]=pow2[i-1]<<1;

    m=10;
    n=1000;

    dfs(1,1,1);

    return 0;

}
