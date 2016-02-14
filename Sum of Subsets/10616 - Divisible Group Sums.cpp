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
int numbers[210];
int dp[210][15][25];
int n,q,m,d,setNo=1;
//tag: sum of subset , dp , mod , number theory
int mod(int num,int div)
{
    if(num<0)
        return div+num%div;
    else
        return num%div;
}
    
int subset(int index,int numsLeft, int div)
{
    if(index<numsLeft)//not enough numbers to fill up
        return dp[index][numsLeft][div]=0;
        
    else if(dp[index][numsLeft][div]!=-1)
        return dp[index][numsLeft][div];
        
    else if(!numsLeft)
        return dp[index][numsLeft][div]=(div==0);
        
    else
    return dp[index][numsLeft][div]=subset(index-1,numsLeft-1,mod(div+mod(numbers[index],d),d))+subset(index-1,numsLeft,div);
    //(a+b)%m=(a%m +b%m)%m... here div=a%m number[index]=b
}
int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y;
    
    while(cin>>n>>q && (n&&q))
    {
        for(int i=1;i<=n;i++)
            cin>>numbers[i];
        
        printf("SET %d:\n", setNo++);
        for(int i=1;i<=q;i++)
        {
            cin>>d>>m;
            memset(dp,-1,sizeof dp);
            int res=subset(n,m,0);
            printf("QUERY %d: %d\n", i, res);
        }
    }
    return 0;
}




