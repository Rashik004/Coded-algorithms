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
#define MAX 10000
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;

long long process[MAX];

void coinChange(int am)
{
    memset(process,0,sizeof process);
    process[0]=1;
    int temp;
    int coins[21];
    for(int i=1;i<=21;i++)
        coins[i-1]=i*i*i;
    
    for(int i=0;i<21;i++)
    {
        for(int j=0;j<MAX;j++)
        {
            temp=j+coins[i];
            if(temp>MAX)
                break;
            
            process[temp]+=process[j];
        }
    }
}
int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    int testCase,x,y;
    coinChange(MAX);
    while(cin>>x)
    {
        cout<<process[x]<<endl;
    }
    return 0;
}