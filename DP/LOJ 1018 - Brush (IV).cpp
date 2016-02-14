/*
Rashik Hasnat;
uva, a2oj:Rashik, codeforces, codechef, codemarshal:rashik004;
Khulna University of Engineering & Technology (KUET), Khulna
Bangladesh
*/
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
#define Tcase(t) for(int qq=1;qq<=t; qq++)
using namespace std;
int dp[(1<<16)+2],n, x[20], y[20];
int Set(int N, int pos){return N=N|(1<<pos);}
int check(int N, int pos){return N & (1<<pos);}
bool isLinier(int a, int b, int m, int n, int x, int y)
{
    int t1,t2;
    t1=(n-b)*(x-m);
    t2=(y-n)*(m-a);
    if(t1==t2)
        return true;
    else
        return false;
}

int f(int mask)
{
   // cout<<"mask: "<<mask<<endl;
    if(mask==(1<<n)-1)
        return 0;
    if(dp[mask]!=-1)
        return dp[mask];

    int i, minM=22,r;
    for(i=0;i<n; i++)
        if(check(mask, i)==0)
            break;
    int tbt1=Set(mask, i);
    minM=1+f(tbt1);
    for(int j=i+1; j<n; j++)
    {
        if(check(mask, j)==0)
        {
            int tbt=tbt1|(1<<j);
            for(int k=0; k<n; k++)
            {
                if(k==i || k==j || check(mask, k))
                    continue;

                if(isLinier(x[i], y[i], x[j], y[j], x[k], y[k]))
                {
                    //cout<<"sda";
                    tbt=tbt|(1<<k);
                }
            }
            //printf("going from %d to %d\n", mask, tbt);
            r=1+f(tbt);
            minM=min(r, minM);
        }
    }
//    if(tbt==Set(mask, i));
//    {
//        printf("going alone from %d to %d\n", mask, tbt);
//        r=1+f(tbt);
//        minM=min(r, minM);
//    }
    return dp[mask]=minM;
}
int main()
{
    int testCase,m,k,h;

    cin>>testCase;
    Tcase(testCase)
    {
        cin>>n;
        mem(dp, -1);
        for(int i=0; i<n; i++)
        {
            cin>>x[i]>>y[i];
        }
        int res=f(0);
        printf("Case %d: %d\n", qq, res);
    }

    return 0;
}
