#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<ctime>
#include<cstring>
#include<cstdlib>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#define MAX_ELE 1005
using namespace std;
//ACed
int numbers[MAX_ELE], dir[MAX_ELE],highLength[MAX_ELE],totalItem;//all of them are 1 indexed array

int lis(int index)
{
    if(highLength[index]!=-1)
        return highLength[index];
    int max=0,temp;
    for(int v=index+1;v<=totalItem;v++)
    {
        if(numbers[v]>numbers[index])
        {
            temp=lis(v);
            if(temp>max)
            {
                max=temp;
                dir[index]=v;
            }
        }
    }
    return highLength[index]=max+1;
}

void printSolution(int start)
{
    printf("%d\n", numbers[start]);
//    start=dir[start];
    while(dir[start]!=-1)
    {
        start=dir[start];
        printf("%d\n", numbers[start]);
    }
//    printf("\n");
}


int main ()
{
    int testCase,index=1,n,temp,max=-1,start;
    char st[15];
    scanf("%d", &testCase);
    getchar();
    getchar();
    for(int qq=1;qq<=testCase;qq++,index=1,max=-1)
    {
        memset(dir,-1,sizeof dir);
        memset(highLength,-1,sizeof highLength);
        while(gets(st))
        {
            if(st[0]=='\0')
                break;
            numbers[index++]=atoi(st);
        }
        totalItem=index-1;
        for(int i=1;i<=totalItem;i++)
        {
            if(highLength[i]==-1)
            {
                temp=lis(i);
                if(temp>max)
                {
                    max=temp;
                    start=i;
                }
            }
        }
        
        if(qq!=1)
            printf("\n");
        printf("Max hits: %d\n", max);
        printSolution(start);
        
    }

    return 0;
}