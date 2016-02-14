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
unsigned long long int process[31000];
int coinNum;
unsigned long long int processCount(int amount)
{
    int coins[]={5,10,20,50,100,200,500,1000,2000,5000,10000};
    coinNum=11;
    memset(process,0, sizeof process);
    process[0]=1;
    
    for(int i=0;i<coinNum;i++)
    {
        for(int j=0;j<=amount;j+=1)
        {
            if(j+coins[i]>amount)
                break;
            if(process[j])
                process[j+coins[i]]+=process[j];
        }
    }
    
    return process[amount];
}
int main ()
{
    int i,j,inp;
    processCount(30005);
    
    while(scanf("%d.%d",&i,&j))
    {
        inp = i*100 + j;
        if(!inp)
            break;
        printf("%3d.%.2d%17llu\n",i,j,process[inp]);
//        scanf("%d.%d",&i,&j);
    }
    return 0;
} 