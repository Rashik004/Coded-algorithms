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
using namespace std;
int process[7500],coinNum;
int processCount(int amount)
{
    int coins[]={1,5,10,25,50};
    coinNum=5;
    memset(process,0, sizeof process);
    process[0]=1;
    
    for(int i=0;i<coinNum;i++)
    {
        for(int j=0;j<=amount;j++)
        {
            if(j+coins[i]>amount)
                break;
            if(process[j]!=0)    //once it has been made
                process[j+coins[i]]+=process[j];
        }
    }
    
    return process[amount];
}
int main ()
{
    int a;
    processCount(7490);
    while(scanf("%d", &a)!=EOF)
    {
        printf("%d\n", process[a]);
    }
    return 0;
} 