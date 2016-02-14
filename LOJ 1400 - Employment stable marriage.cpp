//Stable Marriage Problem, AC
//Algo Reference: http://www.geeksforgeeks.org/stable-marriage-problem/
#include<bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define ll long long
#define ull unisgned long long
#define read freopen("Input.txt","r",stdin)
#define write freopen("output.txt","w",stdout)
#define vi vector<int>
#define MAX 105
using namespace std;

int prefer[2*MAX][MAX],company[2*MAX];
bool personFree[MAX];

bool check(int man, int comp, int n)//check whether current man has higher priority than the man company was previously hiring
{
    for(int i=1;i<=n; i++)
    {
        if(prefer[comp][i]==company[comp])
            return false;
        if(prefer[comp][i]==man)
            return true;
    }
}
void stableMarriage(int n)
{
    memset(company, -1, sizeof company);
    memset(personFree, false, sizeof personFree);
    int freeMen=n;
    while(freeMen)
    {
        int man;
        //finds out the man without any company
        for(man=1; man<=n; man++)
            if(!personFree[man])
                break;

        for(int i=1;i<=n; i++)
        {
            int c=prefer[man][i];
            if(company[c]==-1)//if the company hasnt hired any employee yet then just assign the current man with this company
            {
                company[c]=man;
                personFree[man]=true;
                freeMen--;
                break;
            }
            //if the company has already hired an employee, then check if the current man holds higher priority than the man company has already hired
            if(check(man, c,n))
            {
                personFree[company[c]]=false;//if the current man has higher priority then the previous man will be jobless
                personFree[man]=true;
                company[c]=man;
                break;
            }
        }
    }
}

void print(int n)
{
    for(int i=n+1;i<=n*2; i++)
        printf(" (%d %d)", company[i], i);
    cout<<endl;
}
int main()
{
    int testCase,x,y,m,n,k;
    cin>>testCase;
    for(int qq=1;qq<=testCase;qq++)
    {
        cin>>n;
        for(int i=1;i<=2*n; i++)
        {
            for(int j=1;j<=n; j++)
            {
                cin>>prefer[i][j];
            }
        }
        printf("Case %d:", qq);
        stableMarriage(n);
        print(n);



    }
    return 0;
}

