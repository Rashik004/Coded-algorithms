#include<iostream>
#include<vector>
using namespace std;
class knapsacking{
public:
    int knapsack(int, int);
    int len_price,price[1002],w[1002],profit[1002][32];
};


int maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}


int knapsacking::knapsack(int item, int weight)
{
   int remainingWeight=weight;
   
   for(int i=0; i<=len_price; i++)
    profit[i][0]=0;
   for(int i=0; i<=weight; i++) 
    profit[0][i]=0;
   for(int i=1; i<=len_price; i++)
   {
        for(int j=1; j<=weight; j++)
        {
            if(j<w[i-1])
            {
                profit[i][j]=profit[i-1][j];//if weight of the current index is greater than the capacity then it can't be taken
                continue;
            }
            else profit[i][j]=maxi(profit[i-1][j],price[i-1]+profit[i-1][j-w[i-1]]);//maxi of profit taking the item & not taking the item
        }
   }
   return profit[item][weight];
}



int main ()
{
   
    int test;
    cin>>test;
    while(test--)
    {
        int total_prof=0;
        knapsacking test;
        int item;
        cin>>item;
        test.len_price=item;
        for(int i=0; i<item; i++)            
            cin>>test.price[i]>>test.w[i];
        int people,high=0;
        cin>>people;
        vector<int>p(people);
        for(int i=0; i<people; i++)
        {
            cin>>p[i];
            high=maxi(high,p[i]);
        }
        
        test.knapsack(item,high);
        
        for(int i=0; i<people; i++)
        total_prof+=test.profit[item][p[i]];
        cout<<total_prof<<endl;
    }
    return 0;
}

