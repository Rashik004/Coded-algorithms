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
///************main code starts from below******************///
/*
suppose we want to find out highest number that a player can gain from a rage [start..fin]
he can do 4 things:
1. take the left one and continue going left
2. take the left one, stop and let the other player play
3. take the right one and continue
4. take the right one, stop and let the other player play
max of 1,2,3,4 will be returned.

when the player is going on a specific direction (i.e dir!=0)
    he can thake the current num and continue(dp(start+1, fin, sum-num[start], 1))
    or else he can stop dp(start, fin, sum, 0)
    max of continue and stop will be returned.
*/
int  save[102][102][3],num[102];
int dp(int start, int fin, int sum, int dir)
{
    if(save[start][fin][dir]!=-1)
        return save[start][fin][dir];
    if(start>fin)
        return save[start][fin][dir]=0;

    if(start==2 && fin==4 && dir==0)
    {
        int as=34;
    }
    if(dir==0)
    {
        int s1,s2,s3,s4;
        if(start==fin)
            return save[start][fin][dir]=num[start];

        s1=num[start]+dp(start+1,fin,sum-num[start],1);
        s2=num[fin]+dp(start, fin-1, sum-num[fin], 2);

        return save[start][fin][dir]=max(s1,s2);
    }
    else
    {
        if(start==fin)
        {
            if(num[start]>0)
                return save[start][fin][dir]=num[start];
            else
                return save[start][fin][dir]=0;
        }
        int cont, stop;
        if(dir==1)
            cont=num[start]+dp(start+1, fin, sum-num[start], 1);
        else
            cont=num[fin]+dp(start, fin-1, sum-num[fin], 2);

            stop=sum-dp(start, fin, sum, 0);
        return save[start][fin][dir]=max(cont, stop);
    }


}

int main()
{
    int x,y,n,m,l,d,k,a,b,c, testCase;
    cin>>testCase;
    Tcase(testCase)
    {
        int sum=0;
        mem(save, -1);
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            cin>>num[i];
            sum+=num[i];
        }
        printf("Case %d: ", qq);
        cout<<2*dp(1,n,sum,0)-sum<<endl;
    }
    return 0;
}
