#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define MAX 30100
using namespace std;
long long process [MAX];
long long countProcess(int am)
{
    int coin[]={1,5,10,25,50},coinNum=5;
    memset(process,0,sizeof process);
    process[0]=1;
    for(int i=0;i<5;i++)
        for(int j=0;j<=am;j++)
        {
            int temp=j+coin[i];
            if(temp>am)
                break;
            else if(process[j])
                process[j+coin[i]]+=process[j];
                
        }
        return process[am];
}
int main ()
{
    countProcess(MAX);
    int x;
    while(cin>>x)
    {
        if(process[x]==1)
            printf("There is only 1 way to produce %d cents change.\n", x);
        else
            printf("There are %lld ways to produce %d cents change.\n", process[x],x);
    }
    return 0;
}


