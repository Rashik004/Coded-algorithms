#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 200005
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
using namespace std;
int dp[10];
int primes[5]={2,3,5,7,9};
int factors[4];
int nums[10][4]={{0,0,0,0}, {0,0,0,0}, {1,0,0,0}, {1,1,0,0}, {3,1,0,0}, {3,1,1,0}, {4,2,1,0}, {4,2,1,1}, {7,2,1,1}, {7,4,1,1}};
ll F(int x)
{
    ll ret=1;
    mem(factors, 0);
    while(x)
    {
        int temp=x%10;
        for(int i=0;i<4; i++)
            factors[i]+=nums[temp][i];
        x/=10;
    }
    return ret;
}

void factorization(ll num)
{


    int i=0;
    while(num!=1)
    {
        if(num%primes[i]==0)
            {
                factors[i]++;
                num/=primes[i];
            }
        else
            i++;
    }
}
int main()
{
    int testCase,x,y,m,n,k,b,g,z;
    dp[0]=1;
    for(int i=1; i<=9; i++)
    {
        dp[i]=dp[i-1]*i;
    }

    cin>>y;
    cin>>x;
    F(x);
     int fin[10]={0};
    for(int i=4; i>=0; i--)
    {
        bool hobe=true;
        for(int j=0;j<4; j++)
        {
            if(nums[primes[i]][j]>factors[j])
            {
                hobe=false;
                break;
            }
        }
        if(hobe)
        {
            fin[primes[i]]++;
            for(int k=0;k<4; k++)
                factors[k]-=nums[primes[i]][k];
            i++;
        }
    }

    for(int i=9; i>=2; i--)
    {
        for(int j=1; j<=fin[i]; j++)
            cout<<i;
    }
    cout<<endl;
    return 0;
}
