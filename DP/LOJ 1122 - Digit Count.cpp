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

/// ******************************** ///
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
///************main code starts from below******************///
int dp [12][12];
bool ache[12];
int f(int digit, int num)//'digit' k prothome rekhe 'num' onker kotogula number banano jai
{
    if(num==1)//jodi 1 onker sonkha banaite hoi digit die taile 1ta sonkhai banano jabe
        return 1;
    if(dp[digit][num]!=-1)
        return dp[digit][num];

    int tot=0;
    for(int i=1; i<=9; i++)
    {
        if(ache[i] && abs(digit-i)<=2)//jodi 'digit'-'i'<=2 hoi taile prothome 'i' rekhe 'num'-1 onker jotogula sonkha banano jai,
                                        //prothome digit ebong 2nd e i rekhe totogula sonkhai banano jai
            tot+=f(i, num-1);
    }

    return dp[digit][num]=tot;
}


int main()
{
    int testCase,n,m,x;
   scanf("%d", &testCase);
    Tcase(testCase)
    {
        mem(dp, -1);
        mem(ache, false);
        int res=0;
        scanf("%d %d", &m, &n);
        for(int i=1; i<=m; i++)
        {
            scanf("%d", &x);
            ache[x]=true;
        }
        for(int i=1; i<=9 ;i++)
            if(ache[i])
        {
            res+= f(i, n);
            //printf("%d ache\n", i);
        }
        printf("Case %d: %d\n", qq,res);

    }
    return 0;
}
