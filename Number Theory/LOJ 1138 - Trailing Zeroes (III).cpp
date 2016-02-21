///Rashik Hasnat;
///uva, a2oj:Rashik, codeforces, codechef, codemarshal:rashik004;
///git: https://github.com/Rashik004/Coded-algorithms
///LinkedIn:bd.linkedin.com/in/rashikhasnat
///Khulna University of Engineering & Technology (KUET), Khulna
///Bangladesh
#include <bits/stdc++.h>
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

#define MAXELE 1000000+5
///************main code starts from below******************///
///multiplication of 2 and 5 makes a zero at the end. so for any number we first
///have to calculate the prime factor of it and how many powers are in there
///say n=2^a*5^b*p1^c*p2^d...., number of zero=min(a,b)
///and always b<a, that means if we can make x power of 5 then we can make excatly x zeros
///so first we did a binary search in range[0,2^63] to find out the minimum number
///yielding at least 10^8 power of 5. the number is h=400000025+5
///so now for any number of zero x, we do a BS in range of [0,h] where can we make x 5s

const ll h=400000025+5;
ll zero(ll x)
{
    ll ret=0;
    while(x)
    {
        x/=5;
        ret+=x;
    }
    return ret;
}

ll checking(int x)
{
    ll mid,ans=-1,st=0,en=h;
    while(st<=en)
    {
        mid=(st+en)/2;
        ll res=zero(mid);

        if(res==x)
            ans=mid;

        if(zero(mid)>=x)
        {
//            ans=mid;
            en=mid-1;
        }
        else
            st=mid+1;
    }
    return ans;
}
int main()
{

    int testCase,x,y,m,l,k,b,c,z,n,r,p,q;
//    cout<<zero(25);
//    write;
//        cout<<checking()<<endl;
//    return 0;
    cin>>testCase;
    Tcase(testCase)
    {
        cin>>q;
        ll res=checking(q);
        printf("Case %d: ",qq);
        if(res==-1)
            printf("impossible\n");
        else
            printf("%lld\n", res);


    }
    return 0;
}
