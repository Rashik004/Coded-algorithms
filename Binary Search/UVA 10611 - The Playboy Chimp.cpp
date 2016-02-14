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

int a[50000+23], n;
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
int bSLow(int x)
{
    int low=0, high=n-1;
    int mid=(low+high)/2;
    int last=-1;
    while(low<=high)
    {
        if(a[mid]>=x)
            high=mid-1;
        else //if(a[mid]<x)
        {
            last=mid;
            low=mid+1;
        }
        mid=(low+high)/2;
    }
    return last;
}

int bSHigh(int x)
{
    int low=0, high=n-1;
    int mid=(low+high)/2;
    int last=-1;
    while(low<=high)
    {
        if(a[mid]<=x)
            low=mid+1;
        else //if(a[mid]<x)
        {
            last=mid;
            high=mid-1;
        }
        mid=(low+high)/2;
    }
    return last;
}
int main()
{
    int testCase,x,y,m,k,q,h;

//    cin>>testCase;
//    Tcase(testCase)
//    {
        cin>>n;
        for(int i=0;i<n; i++)
            cin>>a[i];
        cin>>q;
        for(int i=1; i<=q; i++)
        {
            cin>>x;
            int l=bSLow(x);
            if(l==-1)
                cout<<'X';
            else
                cout<<a[l];

            cout<<" ";
            l=bSHigh(x);
            if(l==-1)
                cout<<'X';
            else
                cout<<a[l];

            cout<<endl;
        }
//    }

    return 0;
}
