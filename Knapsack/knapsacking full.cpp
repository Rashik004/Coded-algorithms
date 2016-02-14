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
class knapsacking{
public:
    int knapsack(int, int);
    int maxi(int a, int b);
    int totalItem, solution,price[100],w[100],profit[32][1002],result_i,result_j,maxWeight,taken,sp;
    int input();
    void printTheTabel(int);
    void backTrack(int,int);
    knapsacking(){solution=0;taken=0;}
    stack<int>itemSerial;
    void printResult();
    void firstResult();
    void lastResult();
};
 
 
 
int knapsacking::input()
{
    cout<<"Enter the number of things"<<endl;
    cin>>totalItem;
    if(!totalItem)
        return 0;
    for(int i=0; i<totalItem;i++)
    cin>>price[i]>>w[i];
 
    return 1;
}
 
//5 4 6 3 1
int knapsacking::knapsack(int item, int weight)
{
   //int remainingWeight=weight;
   maxWeight=weight;
   for(int i=0; i<=totalItem; i++)
    profit[i][0]=0;
   for(int i=0; i<=weight; i++)
    profit[0][i]=0;
   for(int i=1; i<=totalItem; i++)
   {
        for(int j=1; j<=weight; j++)
        {
            if(j<w[i-1])
            {
                profit[i][j]=profit[i-1][j];//if weight of the current index is greater than the capacity then it can't be taken
                continue;
            }
            else profit[i][j]=maxi(profit[i-1][j],price[i-1]+profit[i-1][j-w[i-1]]);//maxi of profit taking the item & not taking the item
            if(profit[i][j]>solution)
            {
                 solution=profit[i][j];
                 result_i=i;
                 result_j=j;
            }
        }
   }
   return profit[item][weight];
}
 
 
 
void knapsacking::backTrack(int item, int weight)
{
    if(item==0 || weight==0)
        return;
    if(profit[item][weight]-price[item-1]==profit[item-1][weight-w[item-1]])
    {
        //cout<<price[item-1]<<'\t'<<w[item-1]<<endl;
        taken++;
        itemSerial.push(item);
        backTrack(item-1, weight-w[item-1]);
    }
    else if(profit[item-1][weight]>profit[item][weight-1])
    backTrack(item-1, weight);
    else
        backTrack(item,weight-1);
}
 
 
void knapsacking::firstResult()
{
    backTrack(result_i,result_j);
    printResult();
}
 
void knapsacking::lastResult()
{
    backTrack(totalItem,maxWeight);
    printResult();
}
 
void knapsacking:: printResult()
{
    cout<<taken<<endl;
    while(!itemSerial.empty())
    {
        int item=itemSerial.top();
       // taken++;
        cout<<w[item-1]/(3*sp)<<ends<<price[item-1]<<endl;
        itemSerial.pop();
    }
}
 
void knapsacking::printTheTabel(int cap)
{
    for(int i=0;i<=cap; i++)
        cout<<"\t"<<i;
    cout<<endl;
    for(int i=0;i<=cap; i++)
        cout<<"\t"<<"---";
    cout<<endl;
 
    for(int i=0;i<=totalItem; i++)
    {
        cout<<i;
        for(int j=0; j<=cap; j++)
            cout<<'\t'<<profit[i][j];
        cout<<endl;
    }
}
 
int knapsacking:: maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}
 