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
int Set(int N,int pos){return N=N | (1<<pos);}
bool check(int N,int pos){return (bool)(N & (1<<pos));}

int cost[20][20];
int n;
int dp[(1<<15)+2];

int call(int mask)
{
	if(mask==(1<<n)-1) return 0;
	if(dp[mask]!=-1) return dp[mask];
	int mn=1<<28;
	for(int i=0;i<n;i++)
	{
		if(!check(mask,i))
		{
			int price=cost[i][i];
			
			for(int j=0;j<n;j++)
				if(i!=j and check(mask,j))
					price+=cost[i][j];
					
			int ret=price+call(Set(mask,i));
			mn=min(mn,ret);
			
		}
	}
	return dp[mask]=mn;
}
int main()
{
		int testCase;
		cin>>testCase;
		for(int qq=1;qq<=testCase;qq++)
		{
		    memset(dp,-1,sizeof dp);
            cin>>n;
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    cin>>cost[i][j];
            
            int ret=call(0);
            printf("Case %d: %d\n",qq,ret);
		}
		

	return 0;
}