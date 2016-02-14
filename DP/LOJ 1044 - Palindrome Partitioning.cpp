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
///************main code starts from below******************///
char str[1004];
int p[1004][1004],dp[1111];

//dp[i] saves the minimum number of palindromes from i to the end of the string

void pal(int len)
{
    for(int i=len-1; i>=0; i--)
        for(int j=len-1; j>=i; j--)
        {
                if(str[i]==str[j])
                {
                    if((j-i)<=1)// when the string is like "a" or "aa"
                        p[i][j]=true;
                    else if(p[i+1][j-1])//two ends are same, if the string in the middle is palindrome then i to j is palindrome
                        p[i][j]=true;
                    else
                        p[i][j]=false;//if the middle part isn't palindrome, i to j isn't palindrome
                }
                else
                    p[i][j]=false;
        }
}

int recur(int now, int lim)
{
    if(now>=lim)
        return 0;
    if(dp[now]!=-1)
        return dp[now];
    int temp,minM=2000;
    for(int i=now; i<lim; i++)
    {
        if(p[now][i])//if now to i is a palindrome then check how many substrings needed to for i+1 to lim
        {
            temp=1+recur(i+1, lim);
            minM=min(minM, temp);
        }
    }

    return dp[now]=minM;
}
int main()
{
    int testCase;
   scanf("%d", &testCase);
    Tcase(testCase)
    {
      mem(dp, -1);
        scanf("%s", str);
        int l=strlen(str);
        pal(l);
        int res=recur(0,l);
        printf("Case %d: %d\n", qq,res);

    }
    return 0;
}
