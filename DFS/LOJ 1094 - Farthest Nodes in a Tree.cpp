/*
Rashik Hasnat;
uva, a2oj:Rashik, codeforces, codechef, codemarshal:rashik004;
Khulna University of Engineering & Technology (KUET), Khulna
Bangladesh
*/
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
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 10000+5
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


struct line{//ax+by=c
    void values(double x, double y, double z){a=x,b=y,c=z;}
    double a,b,c;};

pair<double,double> sectionPoint(line l1, line l2)//ax+by=c
{
    double a1,b1,c1,a2,b2,c2,x,y,dx,dy,d;

    a1=l1.a,
    b1=l1.b;
    c1=l1.c;
    a2=l2.a;
    b2=l2.b;
    c2=l2.c;
    d=a1*b2-b1*a2;
    if(d==0)
        return mp(-1, -1);
    dx=c1*b2-c2*b1;
    dy=a1*c2-a2*c1;
    x=dx*1.0/d;
    y=dy*1.0/d;
    cout<<x<<endl<<y<<endl;
    return mp(x,y);
}

line equation(pair<double,double> point1, pair<double,double> point2)
{
    double x1,x2,y1,y2;
    x1=point1.first;
    y1=point1.second;
    x2=point2.first;
    y2=point2.second;
    double kx,ky;
    line ret;
    kx=x1-x2;
    ky=y1-y2;
    ret.a=ky;
    ret.b=kx;
    ret.c=x1*ky-y1*kx;
    if(ret.a<0)
    {
        ret.a*=-1;
        ret.b*=-1;
        ret.c*=-1;
    }
    cout<<ret.a<<"x+"<<ret.b<<"y="<<ret.c<<endl;
    return ret;
}

//bool seivePrime[MAX];
//void seive(int range)
//{
//    mem(seivePrime,true);
//    for(int i=4; i<=range; i+=2)
//        seivePrime[i]=false;
//    seivePrime[1]=false;
//    seivePrime[2]=true;
//    seivePrime[3]=true;
//    int lim=sqrt(range);
//    for(int i=3; i<=lim; i+=2)
//    {
//        if(seivePrime[i])
//        {
//            for(int j=i+i; j<=range; j+=i)
//                seivePrime[j]=false;
//        }
//    }
//}

double const eps = 1e-9;
ll manhattan(ll x1, ll y1, ll x2, ll y2)
{
    return abs(x1-x2)+abs(y1-y2);
}

int bigPow(int a, int b, int m)//(a^b)%m
{
    if(b==1)
        return a%m;
    if(b==0)
        return 1;

    ll res=bigPow(a,b/2,m);
    res=(res*res)%(ll)m;
    if(b%2)
        res=(res*a%m)%m;
    return res;

}

int MMI_Fermat(int a, int m)//finds modular inverse according to fermat's theorem
{
    return bigPow(a,m-2, m);//since a^(m-1) mod m =1 if m is prime
}
        void extEuclid(int a, int b, int &x, int &y, int &gcd) {
            x = 0; y = 1; gcd = b;
            int m, n, q, r;
            for (int u=1, v=0; a != 0; gcd=a, a=r) {
                q = gcd / a; r = gcd % a;
                m = x-u*q; n = y-v*q;
                x=u; y=v; u=m; v=n;
            }
        }

        // The result could be negative, if it's required to be positive, then add "m"
        int modInv(int n, int m) {
            int x, y, gcd;
            extEuclid(n, m, x, y, gcd);
            if (gcd == 1) return x % m;
            return 0;
        }

int nod(int n)//number of divisors (1 and the number itself is included)
{

    if(n==1)
        return 1;
//    if(seivePrime[n])
//        return 2;
    int lim=sqrt(n);
    int gun=1;
    for(int i=2; i<=lim; i++)
    {
//        if(seivePrime[n])
//        {
//            gun*=2;
//            break;
//        }
        if(n%i)
            continue;

        int c=0;
        while(n%i==0)
        {
            c++;
            n/=i;
        }
        gun*=(c+1);
    }
    if(n!=1)
        gun*=2;
    return gun;
}

ll sod(int n)//sum of divisors including the number itself and 1
{
    ///call the seive(n) before it
    if(n==1)
        return 1;
//    if(seivePrime[n])
//        return n+1;
    int lim=sqrt(n);
    ll gun=1;
    for(int i=2; i<=lim; i++)
    {

//        if(seivePrime[n])
//        {
//            gun*=n+1;
//            break;
//        }
        if(n%i)
            continue;
        ll temp=i;
        while(n%temp==0)
        {
            temp*=i;
        }
        n/=(temp/i);
        gun*=(temp-1)/(i-1);
    }
    if(n!=1)
        gun*=n+1;
    return gun;
}

//ll ncrDp[MAX][6];
//ll ncr(int n, int r)
//{
//    if(r>n)
//        return 0;
//    if(r==n)
//        return ncrDp[n][r]=1;
//    if(r==1)
//        return ncrDp[n][r]=n;
//    if(ncrDp[n][r]!=-1)
//        return ncrDp[n][r];
//    return ncrDp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
//}
//ll ncrMod(ll n, ll r, ll mod)
//{
//    ll low=(f[n-r]*f[r])%mod;
//    low=MMI_Fermat(low,mod);
//    ll res=(low*f[n])%mod;
//    return res;
//}
//int mobiusVal[MAX+5];
//int deMobius(int range)//if a number has same prime factor twice, thne mobval=0,
////else if it has odd number of prime factor, mobVal=1, else mobVal=-1
//{
//
//    vi pList;
//    seive(range);
//    for(int i=2; i<=range; i++)
//        if(seivePrime[i])
//            pList.pb(i);
//    for(int i=2; i<=range; i++)
//    {
//        if(seivePrime[i])
//        {
//            mobiusVal[i]=1;
//            divList.pb(i);
//            continue;
//        }
//        int c=0;
//        int num=i;
//        int lim=sqrt(i);
//        bool zero=false;
//        for(int j=0; pList[j]<=lim; j++)
//        {
//            if(i%pList[j])
//                continue;
//            if(num%(pList[j]*pList[j])==0)
//            {
//                mobiusVal[i]=0;
//                zero=true;
//                break;
//            }
//            c++;
//            num/=pList[j];
//        }
//        if(zero)
//            continue;
//        if(num!=1)
//            c++;
//        if(c%2)
//            mobiusVal[i]=1;
//        else
//            mobiusVal[i]=-1;
//        divList.pb(i);
//
//    }
//
//}
///************main code starts from below******************///

///find out the furthest node from 0 using dfs, then perform another dfs from the furthest node
vi relation [30000+23];
vi dist[30000+23];
bool vis[30000+2];
int mDis,fNode;
int dfs(int node, int dis)
{
    vis[node]=true;
    if(dis>mDis)
    {
        fNode=node;
        mDis=dis;
    }
    for(int i=0;i<relation[node].size(); i++)
    {
        int now=relation[node][i];
        if(vis[now]==false)
            dfs(now,dist[node][i]+dis);
    }
}
int main()
{
    int testCase,x,y,m,l,k,n,a,b,c,z;
    cin>>testCase;
    Tcase(testCase)
    {
        scanf("%d", &n);
        for(int i=0;i<n; i++)
        {
            dist[i].clear();
            relation[i].clear();
            vis[i]=false;
        }
        mDis=-1;
        for(int i=1;i<n;i++)
        {
            scanf("%d %d %d", &x, &y, &z);
            relation[x].pb(y);
            relation[y].pb(x);
            dist[x].pb(z);
            dist[y].pb(z);
        }
        dfs(0,0);
//        cout<<mDis<<' '<<fNode<<endl;
        mem(vis,false);
        dfs(fNode,0);
        printf("Case %d: %d\n", qq, mDis);
    }
    return 0;
}
