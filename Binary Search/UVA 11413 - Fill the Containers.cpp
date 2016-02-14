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

int a[50000+23], n, k;
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

bool ok(ll high)
{
    ll mCount=1,still=0;
    if(high==7)
    {
        int ab=45;
        ab*=34;
    }
    for(int i=0;i<n;i++)
    {
        still+=a[i];
        if(a[i]>high)
            return false;
        if(still>high)
        {
            mCount++;
            still=a[i];
            if(mCount>k)
                return false;
        }
    }
    if(mCount>k)
        return false;
    else
        return true;
}

ll bSearch(ll high)
{
    ll low=0, mid=(high+low)/2, last=-1;
    while(high>=low)
    {
        if(ok(mid))
        {
            high=mid-1;
            last=mid;
        }
        else
            low=mid+1;

         mid=(high+low)/2;
    }
    return last;
}


int main()
{
    int testCase,x,y,m,q,h;
    while(cin>>n>>k)
    {

        ll cum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            cum+=a[i];
        }
        cout<<bSearch(cum)<<endl;

    }

    return 0;
}
