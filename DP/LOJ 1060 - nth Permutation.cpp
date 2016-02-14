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
#define read freopen("input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 1000000+5
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

bool seivePrime[MAX];
void seive(int range)
{
    mem(seivePrime,true);
    for(int i=4; i<=range; i+=2)
        seivePrime[i]=false;
    seivePrime[1]=false;
    seivePrime[2]=true;
    seivePrime[3]=true;
    int lim=sqrt(range);
    for(int i=3; i<=lim; i+=2)
    {
        if(seivePrime[i])
        {
            for(int j=i+i; j<=range; j+=i)
                seivePrime[j]=false;
        }
    }
}

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

    int res=bigPow(a,b/2,m);
    res=(res*res)%m;
    if(b%2)
        res=(res*a%m)%m;
    return res;

}

int MMI_Fermat(int a, int m)//finds modular inverse according to fermat's theorem
{
    return bigPow(a,m-2, m);//since a^(m-1) mod m =1 if m is prime
}
///************main code starts from below******************///

int coun[300],dSize;
vector<char> disti;
ll f[25];
ll calcPossible(int l)
{
    ll vaag=1;
    for(int i=0;i<dSize; i++)
    {
        int now=disti[i];
        vaag*=f[coun[now]];
    }
    return f[l]/vaag;
}

void dp(int len, int th)
{
    if(len<1)
        return;
    for(int i=0; i<dSize; i++)
    {
        char now=disti[i];
        if(coun[now]==0)
            continue;
        coun[now]--;
        ll temp=calcPossible(len-1);
        if(temp>=th)
        {
            cout<<disti[i];
            dp(len-1,th);
            return;
        }
        else
        {
            coun[now]++;
            th-=temp;
        }
    }

    cout<<"Impossible";

}

/*
    suppose the string is aabb 5
    prothome a rekhe baki 3 take nie 3 vabe perumte kora jai, so prothome a rekhe hobena
    then amake dekhte hobe prothome b rekhe ami 2nd permutation ber korte pari kina
*/
int main()
{
    int testCase,x,y,m,l,k,n,a,b,c,z;
    cin>>testCase;
    string inp;
    f[0]=1;
    for(int i=1; i<=21; i++)
        f[i]=f[i-1]*i;
    Tcase(testCase)
    {
        cin>>inp>>n;
        disti.clear();
        mem(coun,0);
        sort(inp.begin(), inp.end());
        for(int i=0; i<inp.size(); i++)
        {
            char now=inp[i];
            coun[now]++;
            if(coun[now]==1)
                disti.pb(now);
        }
        dSize=disti.size();
        printf("Case %d: ",qq);
        dp(inp.size(), n);
        cout<<endl;
    }

    return 0;
}
