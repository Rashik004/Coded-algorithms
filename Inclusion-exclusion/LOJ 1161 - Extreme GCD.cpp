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
#define write freopen("out.txt","w",stdout)
#define vi vector<int>
#define MAX 10000+5
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
#define Tcase(t) for(int qq=1;qq<=t; qq++)
using namespace std;
/*
    my critical input:
    1
    14
    6 12 30 60 10 2 4 3 27 15 5 20 1 45
    output=829
    highest number of possible combination is nc4. this is the initial result
    1.numbers having the same prime factors can't have gcd=1 ie (2,4,8,10,12)
    2.So we find out how many numbers with same factors:
        p(2)=8,p(3)=8,p(5)=7,... p(15)=4
    3. now with the exclusion-inclusion principal we:-
        a.exclude p(x) if x is made up with odd number of prime factors ie: x=2,3,5,30(30=2*3*5)
        b.include p(x) if x is made up with even number of prime factors ie: x=6, 10, 15, 210(210=2*3*5*7)

*/
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



ll ncrDp[MAX][6];
ll ncr(int n, int r)
{
    if(r>n)
        return 0;
    if(r==n)
        return ncrDp[n][r]=1;
    if(r==1)
        return ncrDp[n][r]=n;
    if(ncrDp[n][r]!=-1)
        return ncrDp[n][r];
    return ncrDp[n][r]=ncr(n-1,r)+ncr(n-1,r-1);
}

vi divList;//holds the numbers we've to check
vi pList;//prime numbers from 2-10000
int nod[MAX];//number of prime factors of a number, if a number has a prime factor more than twice then it is not used like(2*2=4,5*5*2=50 etc)
int divisable[MAX];//divisable[x] holds how many numbers in the given list are divisable by x
int main()
{

    ll testCase,x,y,m,l,k,n,a,b,c,z;
    int num[MAX];
    cin>>testCase;
    seive(MAX);
    for(int i=2;i<=MAX; i++)
        if(seivePrime[i])
        {
            pList.pb(i);
        }
    mem(ncrDp,-1);
    mem(nod,0);
    for(int i=2; i<=MAX; i++)
    {
        if(seivePrime[i])
        {
            divList.pb(i);
            nod[i]=1;
        }
        else
        {
            int c=0;
            int lim=sqrt(i);
            int num=i;
            for(int j=0;pList[j]<=lim; j++)
            {
                if(i%pList[j])
                    continue;

                if(num%(pList[j]*pList[j])==0)//if i has same prime factor twice then we don't need to calculate it
                {
                    nod[i]=-1;
                    break;
                }
                nod[i]++;
                num/=pList[j];
            }

            if(nod[i]>0)
                divList.pb(i);
            if(num!=1)
                nod[i]++;

        }
    }

    Tcase(testCase)
    {
        cin>>n;
        mem(divisable,0);
        ll res=ncr(n,4);
        int mx=-1;
        for(int i=0;i<n; i++)
        {
            cin>>num[i];
            mx=max(num[i],mx);
        }
        for(int i=0;i<n; i++)
        {
            if(num[i]==1)
                continue;
            if(seivePrime[num[i]])
            {
                divisable[num[i]]++;
                continue;
            }

            int lim=sqrt(num[i]),temp=num[i];
            if(nod[temp])
                divisable[temp]++;
            for(int j=2;j<=lim; j++)
            {
                if(temp%j)
                    continue;
                if(nod[j]>0)
                    divisable[j]++;
                int t=temp/j;

                if(nod[t]>0 && j!=t)
                    divisable[t]++;
            }
        }

        for(int i=0;i<divList.size() && divList[i]<=mx  ; i++)
        {
            if(divisable[divList[i]]>3)
            {
//                cout<<divList[i]<<' '<<divisable[divList[i]]<<' '<<ncr(divisable[divList[i]],4)<<endl;
                if(nod[divList[i]]%2)
                {
                    res-=ncr(divisable[divList[i]],4);

//                    cout<<divList[i]<<' '<<"p "<<divisable[divList[i]]<<' '<<res<<' '<<ncr(divisable[divList[i]],4)<<endl;
                }
                else
                {
                    res+=ncr(divisable[divList[i]],4);
//                    cout<<divList[i]<<' '<<"n "<<divisable[divList[i]]<<' '<<res<<' '<<ncr(divisable[divList[i]],4)<<endl;
                }
            }
        }


        printf("Case %d: %lld\n",qq,res);


    }
    return 0;
}
