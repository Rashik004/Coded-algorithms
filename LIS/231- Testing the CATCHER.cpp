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
//LIS
vector<int> numbers,highLength;//all of them are 1 indexed array
int totalItem;
int lis(int index)
{
    if(highLength[index]!=-1)
        return highLength[index];
    int max=0,temp;
//    totalItem=numbers.size()-1;
    
    for(int v=index+1;v<=totalItem;v++)
    {
        if(numbers[v]<numbers[index])
        {
            temp=lis(v);
            if(temp>max)
                max=temp;
        }
    }
    return highLength[index]=max+1;
}


int main ()
{
    int high,height,test=1,temp;
    bool firstCase;
    while(2)
    {
        numbers.clear();
        highLength.clear();
        firstCase=true;
        numbers.push_back(-2000);
        highLength.push_back(-1);
        high=-1;
        while(scanf("%d", &height))
        {
            if(height==-1)
                break;
            else
                firstCase=false;
            numbers.push_back(height);
            highLength.push_back(-1);
        }
        if(firstCase)
            return 0;
        totalItem=numbers.size()-1;
        for(int i=1;i<=totalItem;i++)
        {
            if(highLength[i]==-1)
            {
                temp=lis(i);
                if(temp>high)
                    high=temp;
            }
        }
        if(test!=1)
            printf("\n");
        printf("Test #%d:\n", test++);
        printf("  maximum possible interceptions: %d\n", high);
    }
    return 0;
}


