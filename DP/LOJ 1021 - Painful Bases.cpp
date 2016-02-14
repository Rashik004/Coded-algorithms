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
#define MAX 1<<15+2
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
#define Tcase(t) for(int qq=1;qq<=t; qq++)
using namespace std;

/// ******************************** ///
int Set(int N, int pos){return N=N|(1<<pos);}
int reset(int N, int pos){return N=N& ~(1<<pos);}
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
///************main code starts from below******************///
int  k, base;
ll save[MAX][22];
bool  visited[MAX];
void dp(int mask)//mask e jsob bit set thakbe sei sob bit nie jsob combination hoi
//tader k dara vag korle koita sonkhar ki vagsesh thake seita save hobe save array te
{
    if(visited[mask])
        return;
    visited[mask]=true;
    int t;
    for(int i=0;i<base; i++)
    {
        if(check(mask,i)==0)
            continue;
        if((1<<i)==mask)//mask er sudhu 1ta digit on. like mask=256 or 128 or 512
        {
            save[mask][i%k]=1;
            return;
        }
        int temp=reset(mask, i);//mask er on thaka bit gular theke 1ta 1ta kore baad die dekhbo
        //seitake pichone rekhe baki gulake permute kore k die vaag dile ki ki mod result ase
        dp(temp);
        for(int j=0;j<k;j++)
        {
            t=(j*base+i)%k;
            save[mask][t]+=save[temp][j];

        }
    }
}
int main()
{

    int testCase;
    string str;
    cin>>testCase;
    Tcase(testCase)
    {
        mem(visited, false);
        mem(save, 0);
        cin>>base>>k;
        cin>>str;
        int mask=0;
        for(int i=0;i<str.size(); i++)
        {
            int t;
            if(str[i]>='0' && str[i]<='9')
                t=str[i]-'0';
            else
                t=str[i]-'A'+10;
            mask=Set(mask, t);

        }
        dp(mask);
        printf("Case %d: ", qq);
        cout<<save[mask][0]<<endl;
    }
    return 0;
}
