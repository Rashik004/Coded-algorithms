#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("out.txt","w",stdout)
#define vi vector<int>
#define MAX 200005
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define sf scanf
using namespace std;
bool verdict;
struct node{
    bool endPoint;
    node *next[10];
    node()
    {
        endPoint=false;
        for(int i=0;i<=9;i++)
            next[i]=NULL;
    }
}*root;

void ins(char *str)
{
    node *current=root;
    int len=strlen(str);
    int sub=0;
    for(int i=0;i<len;i++)
    {
        int now=str[i]-'0';

        if(current->next[now]==NULL)
            current->next[now]= new node;
        else if(current->next[now]->endPoint==true)//node existed before and it was a endpoint
            verdict=false;
        else if(i==len-1)//node existed before and now it is being modified as endpoint
            verdict=false;


        current=current->next[now];



    }
    current->endPoint=true;
}

void deletion(node *point)
{
    for(int i=0; i<=9; i++)
        if(point->next[i]!=NULL)
            deletion(point->next[i]);
    delete(point);
}

int main()
{
    int testCase,x,y,m,n,k;
    //write;
    //cout<<strlen("97625999");
    char number[12];
    cin>>testCase;
    for(int qq=1;qq<=testCase;qq++)
    {
        cin>>n;
        verdict =true;
        root=new node;
        for(int i=1;i<=n;i++)
        {
            cin>>number;
            ins(number);
        }
        deletion(root);

        if(verdict)
            cout<<"YES\n";
        else
            cout<<"NO\n";

    }
    return 0;
}
