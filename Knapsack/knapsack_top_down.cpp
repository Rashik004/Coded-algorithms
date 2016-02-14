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
    int len_price, len_weight,price[100],w[100],profit[25][3300];
    vector<vector <int> > prof;;
    int input();
    void printTheTabel(int);
    void backTrack(int,int);
    int setDefault(int ,int);
   // knapsacking();
};

//vector<vector<int> > prof(25,vector<int>(4400));
//knapsacking()
//{
//     prof(25,vector<int>(4400));
////    prof=t;
//}

int knapsacking::input()
{
    //t(44,0);
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
   int remainingWeight=weight;
   
    if(profit[item][weight]!=-1)
        return profit[item][weight];
    
    if(w[item-1]>weight)
        profit[item][weight]=knapsack(item-1,weight);
    else
        profit[item][weight]=maxi(knapsack(item-1,weight),knapsack(item-1,weight-w[item-1])+price[item-1]);
   return profit[item][weight];
}



void knapsacking::backTrack(int item, int weight)
{
    if(item==0 || weight==0)
        return;
    if(profit[item][weight]-price[item-1]==profit[item-1][weight-w[item-1]])
    {
        cout<<price[item-1]<<'\t'<<w[item-1]<<endl;
        backTrack(item-1, weight-w[item-1]);
    }
    else if(profit[item-1][weight]>profit[item][weight-1])
    backTrack(item-1, weight);
    else
        backTrack(item,weight-1);
}

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

int knapsacking:: maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}


int knapsacking::setDefault(int item,int maxWeight)
{
    for(int i=0; i<=item; i++)
        for(int j=0; j<=maxWeight; j++)
    {
        if(!i||!j)
            profit[i][j]=0;
        else
            profit[i][j]=-1;
    }
}


int main ()
{
   
   knapsacking test;
   test.input();
   cout<<"input the weight capacity of the bag"<<endl;
   //freopen("Bottom_up.txt","w",stdout);
   int cap;
   cin>>cap;
   test.setDefault(test.len_price,cap);
//   test.set_default(cap);
   cout<<test.knapsack(test.len_price,cap)<<endl;
   //test.print();
   test.printTheTabel(cap);
    cout<<endl<<endl<<endl;
    test.backTrack(test.len_price,cap);
    return 0;
}

