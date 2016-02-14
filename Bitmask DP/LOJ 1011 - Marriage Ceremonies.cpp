#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 1<<16
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
using namespace std;
int pr[18][18], dp[18][MAX+2],n;

int Set(int N, int pos){return N=N|(1<<pos);}
int check(int N, int pos){return N & (1<<pos);}

int din(int person, int mask)
{
    if(person==n) return 0;

    if(dp[person][mask]!=-1)
        return dp[person][mask];
    int maxM=-1;
    for(int i=0;i<n; i++)
        if(check(mask, i)==false)
        {
            int temp=Set(mask, i);
            temp=pr[person][i]+din(person+1, temp);
            maxM=max(maxM, temp);
        }

    return dp[person][mask]=maxM;
}
int main()
{
    int testCase,x=0,y=0,m,k,h;
    cin>>testCase;
    for(int qq=1; qq<=testCase; qq++)
    {
        cin>>n;
        mem(dp,-1);
        for(int i=0; i<n; i++)
            for(int j=0 ;j<n; j++)
                cin>>pr[i][j];

        int res=din(0, 0);
        printf("Case %d: %d\n", qq, res);
    }
    return 0;
}
