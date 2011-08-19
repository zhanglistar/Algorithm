/*
 *����㷨  
 *�������˼·�ǿ�һ�����飬���±��ʾ1��m����������Ԫ�ص�ֵΪ1��ʾ���±�  
 *���������ѡ�У�Ϊ0��ûѡ�С�   
 *���ȳ�ʼ����������ǰn��Ԫ����1����ʾ��һ�����Ϊǰn������   
 *Ȼ�������ɨ������Ԫ��ֵ�ġ�10����ϣ��ҵ���һ����10����Ϻ����Ϊ  
 *��01����ϣ�ͬʱ������ߵ����С�1��ȫ���ƶ������������ˡ�   
 *����һ����1���ƶ��������m-n��λ�ã���n����1��ȫ���ƶ������Ҷ�ʱ���͵�  
 *�������һ����ϡ�   
 *������5��ѡ3����ϣ�   
 *1 1 1 0 0 //1,2,3   
 *1 1 0 1 0 //1,2,4   
 *1 0 1 1 0 //1,3,4   
 *0 1 1 1 0 //2,3,4   
 *1 1 0 0 1 //1,2,5 ����ʣ�http://www.cnnic-qd.cn/it/index.html  
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

unsigned char number[100]; //�����100��������ϡ�   
unsigned int m,n;// 2<=m<=100,n<m   

char tmpbuf[128];   
time_t ltime;   
struct tm *today;   

void printtime(void) //��ӡ��ǰʱ��ĺ���   
{   
    time(&ltime);   
    today = localtime(&ltime );   
    strftime(tmpbuf,128,"%Y-%m-%d %H:%M:%S",today);   
    printf("%s\n",tmpbuf);   
}   

void inition() //��ʼ��   
{       //http://www.cnnic-qd.cn/it/index.html  
    unsigned int i;   
    for(i=0;i<n;i++)   
        number[i]=1;   
}   

void output() //�����Ͻ��   
{   
    unsigned int i;   
    for(i=0;i<m;i++)   
        if(number[i])   
            printf("%02d ",i+1);   
    printf("\n");   
}   

int main()   
{   
    unsigned long count; //������ϸ���   
    unsigned int i,j,k,l;   
    bool findfirst,end,swap;   
    end=false;   
    printf("please input m:");   
    scanf("%d",&m); //����m   
    printf("please input n:");   
    scanf("%d",&n); //����n   
    printtime(); //��ӡ��ʼʱ��   
    inition(); //��ʼ��   
    //output(); //���ε��������Խ�Լʱ��   
    count=1;   
    j=m;   
    while(!end)   
    {   
        findfirst=false;   

        swap=false; //��־��λ   
        for(i=0;i<j;i++)   
        {   
            if(!findfirst && number[i])   
            {   
                k=i; //k��¼��ɨ�赽�ĵ�һ����   
                findfirst=true; //���ñ�־   
            }   
            if(number[i] && !number[i+1]) //������ɨ���һ����10�����   
            {   
                number[i]=0;   
                number[i+1]=1;   
                swap=true; //���ý�����־   
                for(l=0;l<i-k;l++)   
                    number[l]=number[k+l];   
                for(l=i-k;l<i;l++)   
                    number[l]=0; //������֮ǰ�ġ�1��ȫ���ƶ��������   
                if(k==i && i+1==m-n) //�����һ����1���Ѿ��ƶ�����m-n��λ�ã�˵��
                                     //�������һ������ˡ�   
                        end=true;   
            }   
            if(swap) //����һ�κ�Ͳ��ü����ҡ�10�������   
                break;   
        }
        output(); //���ε��������Խ�Լʱ��   
        count++; //���������������1   
    }
    printtime(); //��ӡ����ʱ��   

    printf("total number of combination is: %d\n",count); //��ӡ�ܵ������  

    return 0;
}
