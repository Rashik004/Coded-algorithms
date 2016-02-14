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
//LIS
int numbers[MAX_ELE]={123,1,6,2,3,5}, dir[MAX_ELE],highLength[MAX_ELE],totalItem;//all of them are 1 indexed array

int lis(int index)
{
    if(highLength[index]!=-1)
        return highLength[index];
    int max=0,temp;
    for(int v=index+1;v<=totalItem;v++)
    {
        if(numbers[v]<numbers[index])
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
    printf("%d", numbers[start]);
//    start=dir[start];
    while(dir[start]!=-1)
    {
        start=dir[start];
        printf(" %d", numbers[start]);
    }
    printf("\n");
}


int main ()
{
    memset(dir,-1,sizeof dir);
    memset(highLength,-1,sizeof highLength);
    totalItem=5;
    int start,high=0,temp;
    for(int i=1;i<=totalItem;i++)
    {
        if(highLength[i]==-1)
        {
            temp=lis(i);
            if(temp>high)
            {
                high=temp;
                start=i;
            }
        }
    }
    
    printf("The length of longest increasing sub-sequence is %d\n", high);
    
    printSolution(start);
    return 0;
}