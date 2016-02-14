#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 100000+2
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
using namespace std;
int Set(int N, int pos){return N=N|(1<<pos);}
int check(int N, int pos){return N & (1<<pos);}
int n,w,k,points[102], dp[102][102];
int rec(int pos, int mLeft)
{
    if(pos>=n || mLeft<=0)
        return 0;

    if(dp[pos][mLeft]!=-1)
        return dp[pos][mLeft];

    int p=0,last=points[pos]+w;
    int i;
    for( i=pos; i<n && points[i]<=last; i++)
        p++;
    int temp=max(p+rec(i, mLeft-1), rec(pos+1, mLeft));
    return dp[pos][mLeft]=temp;

}
int main()
{
    int testCase,x;
    cin>>testCase;
    for(int qq=1;qq<=testCase; qq++)
    {
        cin>>n>>w>>k;
        for(int i=0;i<n; i++)
            cin>>x>>points[i];

        sort(points, points+n);
        mem(dp, -1);
        int res=rec(0, k);
        printf("Case %d: %d\n", qq, res);
    }
    return 0;
}
