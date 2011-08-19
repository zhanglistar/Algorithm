/*
 *大数阶乘算法
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

#define  MAX 10000

int fac[MAX]={1,};
int add[MAX]={0,};

int top=1;//计算结果位数

void calculate(int n);

void print();

int main(int argc, char * argv[])
{  
    int n;
    cout<<"please input the number:";
    while (cin >> n && n > 0) {
        calculate(n);
        cout<<n<<"!=";
        print();
        cout<<"总共"<<top<<"位"<<endl;
        cout<<"please input the number:";
    }

    return 0;
}

//计算N的阶乘
void calculate(int n)
{
    memset(fac, 0, sizeof(fac));
    memset(add, 0, sizeof(add));
    fac[0] = 1;
    top = 1;

    if (n<=0)
    {
        exit(1);
    }
    for (int i=1;i<=n;i++)
    {
        int m=top;
        for (int j=0;j<m;j++)
        { 
            int tmp=fac[j]*i;
            if (j==0)
            {
                fac[0]=tmp%10;
                add[0]=tmp/10;
            }
            else 
            {
                fac[j]=(tmp+add[j-1])%10;
                add[j]=(tmp+add[j-1])/10;
            }
            /**最高位有进位
             **连续进位的问题
             */
            while (add[top-1]>0){ 
                top++;
                int tmp=fac[top-1];
                fac[top-1]=(tmp+add[top-2])%10;
                add[top-1]=(tmp+add[top-2])/10;  
            }
        }
    }
}

//打印输出结果
void print()
{
    int j=0;
    for(int i=top-1;i>=0;i--)
    {
        if ((j++)%20==0)
        {
            cout<<endl;
        }
        cout<<fac[i];
    }
    cout<<endl;
}
