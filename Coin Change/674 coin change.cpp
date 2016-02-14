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




vector<int>coins;
int coinNum,saving[8000];



int totalProcess(int amount)
{
    int processAmount[8000][7];
    for(int i=0;i<coinNum; i++)
        processAmount[0][i]=1;
        
    if(amount==0)//if there no amount needed then no coins needed!!
        return 1;
    
//    if(coinIndex<0)// no coins left but still amount to be filled
//        return 0;
    
    for(int i=1;i<=amount;i++)
        {
            int j;
            for(j=0;j<coinNum;j++)
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
            saving[i]=processAmount[i][coinNum-1];
        }
        return processAmount[amount][coinNum-1];
}


int main ()
{
    
    coins.push_back(1);
    coins.push_back(5);
    coins.push_back(10);
    coins.push_back(25);
    coins.push_back(50);
    coinNum=coins.size();
    saving[0]=1;
    totalProcess(7499);
    int am;
    while(cin>>am)
        cout<<saving[am]<<endl;
    return 0;
}
