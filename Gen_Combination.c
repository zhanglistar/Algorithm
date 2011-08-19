/*
 *组合算法  
 *本程序的思路是开一个数组，其下标表示1到m个数，数组元素的值为1表示其下标  
 *代表的数被选中，为0则没选中。   
 *首先初始化，将数组前n个元素置1，表示第一个组合为前n个数。   
 *然后从左到右扫描数组元素值的“10”组合，找到第一个“10”组合后将其变为  
 *“01”组合，同时将其左边的所有“1”全部移动到数组的最左端。   
 *当第一个“1”移动到数组的m-n的位置，即n个“1”全部移动到最右端时，就得  
 *到了最后一个组合。   
 *例如求5中选3的组合：   
 *1 1 1 0 0 //1,2,3   
 *1 1 0 1 0 //1,2,4   
 *1 0 1 1 0 //1,3,4   
 *0 1 1 1 0 //2,3,4   
 *1 1 0 0 1 //1,2,5 请访问：http://www.cnnic-qd.cn/it/index.html  
 *1 0 1 0 1 //1,3,5   
 *0 1 1 0 1 //2,3,5   
 *1 0 0 1 1 //1,4,5   
 *0 1 0 1 1 //2,4,5   
 *0 0 1 1 1 //3,4,5   
 */

#include <stdio.h>
#include <time.h>   

typedef int bool;
#define false 0
#define true 1

unsigned char number[100]; //最多求100个数的组合。   
unsigned int m,n;// 2<=m<=100,n<m   

char tmpbuf[128];   
time_t ltime;   
struct tm *today;   

void printtime(void) //打印当前时间的函数   
{   
    time(&ltime);   
    today = localtime(&ltime );   
    strftime(tmpbuf,128,"%Y-%m-%d %H:%M:%S",today);   
    printf("%s\n",tmpbuf);   
}   

void inition() //初始化   
{       //http://www.cnnic-qd.cn/it/index.html  
    unsigned int i;   
    for(i=0;i<n;i++)   
        number[i]=1;   
}   

void output() //输出组合结果   
{   
    unsigned int i;   
    for(i=0;i<m;i++)   
        if(number[i])   
            printf("%02d ",i+1);   
    printf("\n");   
}   

int main()   
{   
    unsigned long count; //计数组合个数   
    unsigned int i,j,k,l;   
    bool findfirst,end,swap;   
    end=false;   
    printf("please input m:");   
    scanf("%d",&m); //输入m   
    printf("please input n:");   
    scanf("%d",&n); //输入n   
    printtime(); //打印开始时间   
    inition(); //初始化   
    //output(); //屏蔽掉结果输出以节约时间   
    count=1;   
    j=m;   
    while(!end)   
    {   
        findfirst=false;   

        swap=false; //标志复位   
        for(i=0;i<j;i++)   
        {   
            if(!findfirst && number[i])   
            {   
                k=i; //k记录下扫描到的第一个数   
                findfirst=true; //设置标志   
            }   
            if(number[i] && !number[i+1]) //从左到右扫描第一个“10”组合   
            {   
                number[i]=0;   
                number[i+1]=1;   
                swap=true; //设置交换标志   
                for(l=0;l<i-k;l++)   
                    number[l]=number[k+l];   
                for(l=i-k;l<i;l++)   
                    number[l]=0; //交换后将之前的“1”全部移动到最左端   
                if(k==i && i+1==m-n) //如果第一个“1”已经移动到了m-n的位置，说明
                                     //这是最后一个组合了。   
                        end=true;   
            }   
            if(swap) //交换一次后就不用继续找“10”组合了   
                break;   
        }
        output(); //屏蔽掉结果输出以节约时间   
        count++; //组合数计数器递增1   
    }
    printtime(); //打印结束时间   

    printf("total number of combination is: %d\n",count); //打印总的组合数  

    return 0;
}
