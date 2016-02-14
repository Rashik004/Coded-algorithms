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
    int len_price, len_weight,price[100],w[100],profit[100][100];
    int input();
    vector<int>taken;
    void print();
    void set_default(int);
    void printTheTabel(int);
};


void knapsacking::printTheTabel(int cap)
{
    for(int i=0;i<=cap; i++)
        cout<<"\t"<<i;
    cout<<endl;
    for(int i=0;i<=cap; i++)
        cout<<"\t"<<"---";
    cout<<endl;
    
    for(int i=0;i<=len_price; i++)
    {
        cout<<i;
        for(int j=0; j<=cap; j++)
            cout<<'\t'<<profit[i][j];
        cout<<endl;
    }
}

int knapsacking::input()
{
    cout<<"Enter the number of things"<<endl;
    cin>>len_price;
    if(!len_price)
        return 0;
        
    len_weight=len_price;
    //set_default();
    for(int i=0; i<len_price;i++)
    cin>>price[i]>>w[i];
    
    return 1;
}


int knapsacking::knapsack(int item, int weight)
{
   
    if(profit[item][weight]!=-1)
        return profit[item][weight];
    if(item==0 || weight==0)
    {
        profit[item][weight]=0;
        return profit[item][weight];
    }
    
        int profit_with,profit_without;
        if(weight>=w[item-1])
            profit_with=price[item-1]+knapsack(item-1, weight-w[item-1]);
        else
            profit_with=0;//zodi ei item er weight bag er dharonkhomotar theke beshi hoi
            profit_without=knapsack(item-1, weight);
        if(profit_with>profit_without)
         {
             taken.push_back(item-1);
             profit[item][weight]=profit_with;
         }   
        else
            profit[item][weight]=profit_without;
           // printf("knapsack(%d,%d)= %d\n", item,weight,profit[item][weight]);
        return profit[item][weight];
    
}

int knapsacking:: maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}

void knapsacking::print()
{
    cout<<"weight\t"<<"price"<<endl;
    int si=taken.size();
    for(int i=0; i<si; i++)
        cout<<w[taken[i]]<<"\t"<<price[taken[i]]<<endl;
}

void knapsacking::set_default(int capacity)
{
    for(int i=0; i<=len_price; i++)
        for(int j=0; j<=capacity; j++)
            profit[i][j]=-1;
}


int main ()
{
  
  knapsacking test;
   test.input();
   cout<<"input the weight capacity of the bag"<<endl;
   freopen("Ok.txt","w",stdout);
   int cap;
   cin>>cap;
   test.set_default(cap);
   cout<<test.knapsack(test.len_price,cap)<<endl;
   //test.print();
   test.printTheTabel(cap);
    
    return 0;
}

