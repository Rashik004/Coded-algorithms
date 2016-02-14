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
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
int dp[5000];

int Set(int N,int pos){return N=N | (1<<pos);}
int reset(int N,int pos){return N= N & ~(1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

bool valid(int mask,int x,int y)//to check if a move is possible from x to y
{
    if(x>=0 && x<12 && y>=0 && y<12)
    {
        if(check(mask,x) && check(mask,(x+y)/2) && !check(mask,y))
            return true;
        else
            return false;
        
    }
    else
        return false;
}

int moving(int mask,int x,int y)//to move a pebble from x to y
{
    int temp;
    temp=Set(mask,y);
    temp=reset(temp,x);
    temp=reset(temp, (x+y)/2);
    return temp;
}


int calls(int mask)
{
    if(dp[mask]!=-1)
        return dp[mask];
    int temp,call,minM,nowT;
    minM=1<<30;
    bool moved=false;
    for(int i=0;i<12;i++)
    {
        if(valid(mask,i,i+2))
        {
            temp=moving(mask, i,i+2);
            nowT=calls(temp);
            minM=min(nowT, minM);
            moved=true;
        }
        
        if(valid(mask, i,i-2))
        {
            temp=moving(mask,i,i-2);
            nowT=calls(temp);
            minM=min(nowT,minM);
            moved=true;
        }
    }
    
    if(moved)
        dp[mask]=minM;
    else
    {
        int counting=0;
        for(int i=0;i<12;i++)
            if(check(mask,i))
                counting++;
        
        dp[mask]=counting;
    }
    
    return dp[mask];
}


int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    
    int testCase;
    cin>>testCase;
    char inp[20];
    
    while(testCase--)
    {
        cin>>inp;
        int mask=0;
        memset(dp,-1,sizeof dp);
        for(int i=0;i<12;i++)
            if(inp[i]=='o')
                    mask=Set(mask,i);
                    
        cout<<calls(mask)<<endl;
    }
  
    return 0;
}







