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

//Ref: http://www.geeksforgeeks.org/dynamic-programming-set-7-coin-change/?fb_comment_id=fbc_150594061754938_839762_222301667917510#f9c7e7465abffa


int minCoin[100000],process[10000],maxM;
vector<int>coins;
int coinNum;

int minCoinChange(int amount)
{
//    cout<<amount<<endl;
    if(minCoin[amount]!=-1)
        return minCoin[amount];
    
    if(amount==0)
        return minCoin[amount]=0;
    int temp,low=maxM;
    for(int i=0;i<coinNum;i++)
    {
        if(coins[i]>amount)
            break;
        temp=minCoinChange(amount-coins[i]);
        
        if(temp<low)
            low=temp;
    }
    
    minCoin[amount]=low+1;
    
    return minCoin[amount];
}
//int a=printf("E");

int totalProcess(int amount)
{
    int processAmount[10000][10];
    for(int i=0;i<coinNum; i++)
        processAmount[0][i]=1;
        
    if(amount==0)//if there no amount needed then no coins needed!!
        return 1;
    
//    if(coinIndex<0)// no coins left but still amount to be filled
//        return 0;
    
    for(int i=1;i<=amount;i++)
        for(int j=0;j<coinNum;j++)
        {
            int x,y;
            int temp=i-coins[j];
            if(temp<0)//coins[i] is bigger than amount needed
                x=0;
            else
                x=processAmount[temp][j];//number of process after taking coins[i]
            if(j<1)//no more coins left after this
                y=0;
            else
                y=processAmount[i][j-1];//number of process without taking coins[i]
            
            processAmount[i][j]=x+y;
        }
        
        return processAmount[amount][coinNum-1];
}

//Following is a simplified version of method 2. The auxiliary space required here is O(n) only.  
int count( int S[], int m, int n ) 
{ 
    // table[i] will be storing the number of solutions for 
    // value i. We need n+1 rows as the table is consturcted 
    // in bottom up manner using the base case (n = 0) 
    int table[n+1]; 
  
    // Initialize all table values as 0 
    memset(table, 0, sizeof(table)); 
  
    // Base case (If given value is 0) 
    table[0] = 1; 
  
    // Pick all coins one by one and update the table[] values 
    // after the index greater than or equal to the value of the 
    // picked coin 
    for(int i=0; i<m; i++) 
        for(int j=S[i]; j<=n; j++) 
            table[j] += table[j-S[i]]; 
  
    return table[n]; 
} 

int processCount(int amount)
{
    int coins[]={1,5,10,25,50};
    coinNum=5;
    memset(process,0, sizeof process);
    process[0]=1;
    
    for(int i=0;i<coinNum;i++)
    {
        for(int j=1;j<=amount;j++)
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
    memset(minCoin, -1, sizeof minCoin);
    maxM=1<<22;
    coins.push_back(1);
    coins.push_back(5);
    coins.push_back(10);
    coins.push_back(25);
    coins.push_back(50);
    coinNum=coins.size();
    int am;
    while(cin>>am)
    {
//        memset(minCoin, -1, sizeof minCoin);
//        cout<<minCoinChange(am)<<endl;
        cout<<totalProcess(am)<<endl;
    }
    return 0;
}
