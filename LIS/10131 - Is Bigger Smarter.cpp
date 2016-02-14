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
#define max(a,b)a>b?a:b
#define min(a,b)a<b?a:b
#define MAX_ELE 10000+10
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
bool func(pair<int,pair<int,int> > x, pair<int,pair<int,int> > y)
{
    if(x.first>y.first)
        return true;
    else if(x.first==y.first && x.second.second<y.second.second)
        return true;
    else
        return false;
}
vector<pair<int,pair<int,int> > >details;
vii numbers;
int dir[MAX_ELE],highLength[MAX_ELE],totalItem;//all of them are 1 indexed array

int lis(int index)
{
    if(highLength[index]!=-1)
        return highLength[index];
    int max=0,temp;
    for(int v=index+1;v<totalItem;v++)
    {
        if(numbers[v].first>numbers[index].first && numbers[v].second!=numbers[index].second)
        {
            temp=lis(v);
            if(temp>max)
            {
                max=temp;
                dir[index]=v;
            }
        }
    }
    return highLength[index]=max+1;
}

void printSolution(int start)
{
    cout<<details[start].second.first<<endl;
    while(dir[start]!=-1)
    {
        start=dir[start];
        cout<<details[start].second.first<<endl;
    };
}

int main ()
{
    //freopen("out.txt","w",stdout);
    //freopen("in.txt","r",stdin);
    memset(dir,-1,sizeof dir);
    memset(highLength,-1,sizeof highLength);
    int testCase,x,y;
    
    int element=0,weight,iq;
    while(cin>>weight>>iq)
    {
        element++;
        details.pb(mp(iq,mp(element,weight)));
    }

    sort(details.begin(),details.end(),func);
    for(int i=0;i<details.size();i++)
    {
        numbers.pb(mp(details[i].second.second,details[i].first));
    }
    totalItem=element;
    int high=0,temp=0,start;
    for(int i=0;i<element;i++)
    {
        if(highLength[i]!=-1)
            continue;
        temp=lis(i);
        if(high<temp)
        {
            high=temp;
            start=i;
        }
    }
    cout<<high<<endl;
    printSolution(start);
    return 0;
}




