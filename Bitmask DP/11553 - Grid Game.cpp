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
#define mp make_pair
#define pb push_back
#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
using namespace std;
/* 1.When turn%2==0 that means its alice's turn. So now he'll work about maximising the progit.
    2.When turn%2==1 its opponents turn, so he'll try to minimize it.
*/
bool check(int N,int pos){return (bool)(N & (1<<pos));}
int Set(int N,int pos){return N=N|(1<<pos);}

int n,box[10][10],dp[266][266][10];

int candy(int rowMask,int colMask,int turn,int last)
{
    if(dp[rowMask][colMask][last]!=-1)
        return dp[rowMask][colMask][last];
    if(rowMask==((1<<n)-1) && colMask==((1<<n)-1))
        return 0;
    int ret;
    if(turn%2==0)
    {
        ret=-1<<25;
        for(int i=1;i<=n;i++)
            if(!check(rowMask,i-1))
                ret=max(candy(Set(rowMask,i-1),colMask,turn+1, i),ret);
        
        return dp[rowMask][colMask][last]=ret;
    }
      
    else
    {
        ret=1<<25;
        for(int i=1;i<=n;i++)
            if(!check(colMask,i-1))
                ret=min(ret, box[last][i]+candy(rowMask,Set(colMask,i-1),turn+1,0));
        //^^ the next turn is Alice's.so it doesn't matter what the last move was. thats why last=0;
        
        return dp[rowMask][colMask][last]=ret;
    }
    
}

int main ()
{
    int testCase;
    cin>>testCase;
    while(testCase--)
    {
        cin>>n;
        memset(dp,-1,sizeof dp);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                cin>>box[i][j];
        cout<<candy(0,0,0,0)<<endl;
    }
    return 0;
}



