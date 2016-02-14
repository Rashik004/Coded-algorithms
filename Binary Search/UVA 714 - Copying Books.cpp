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

int a[50000+23], dp[600][600], n, k;
ll habi;
bool save[600];



bool ok(ll high)// ok function returns if it is possible to a give a person maximum 'high' pages
{
    ll mCount=1,still=0;

    for(int i=0;i<n;i++)
    {
        if(a[i]>high)
            return false;
        still+=a[i];
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

ll bSearch(ll high)//searches the minimum possible max page for one person
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

int part(int index, int pLeft)//this functions diveds so that the dividation is according to the question
//is it possible to divide books from 'index' to the last among 'pLeft' persons so that no one has to write more than 'habi' pages
{
    ll nT=0;

    if(pLeft==1)//jod 1jon player baki thake, tar maane eke sobgula page likhte hobe
    {
        for(int i=index; i<n; i++)
        {
            nT+=a[i];
            if(nT>habi)//eka sob page likhte parbena
                return 0;
        }
        return 1;
    }

    if(dp[index][pLeft]!=-1)
        return dp[index][pLeft];

    for(int i=index;  ; i++)
    {
        nT+=a[i];
        if(nT>habi)
            return dp[index][pLeft]=0;

        if(part(i+1, pLeft-1))//protibar check kore dekhchi j ei index e divide korle hoi kina
            //first jei index e divide korle kaaj hobe, seitatei division korbo
        {
            save[i]=true;//i tomo index er por notun partion suru
            return dp[index][pLeft]=1;
        }
    }
}

int main()
{
    int testCase,x,y,m,q,h;
    cin>>testCase;
    Tcase(testCase)
    {
        cin>>n>>k;
        mem(save, false);
        mem(dp, -1);
        ll cum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            cum+=a[i];
        }
        habi=bSearch(cum);
        part(0,k);
        for(int i=0;i<n;i++)
        {
            if(i)
                cout<<" ";
            printf("%d", a[i]);
            if(save[i])
                printf(" /");
        }
        cout<<endl;
    }

    return 0;
}
