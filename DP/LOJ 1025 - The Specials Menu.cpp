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
char str[62];
ll dp[62][62];

ll recur(int i, int j)
{


      if(j<i)
         return 0;
   if(dp[i][j]!=-1)
      return dp[i][j];
   if(i==j)
      return 1;
   ll a,b,c,d;
   if(str[i]==str[j])
      a=1+recur(i+1, j-1);
   else
      a=0;
   return dp[i][j]=a+recur(i,j-1)+recur(i+1, j)-recur(i+1, j-1);

}
int main()
{
    int testCase;
   scanf("%d", &testCase);
   Tcase(testCase)
   {
      mem(dp, -1);
      scanf("%s", str);
      ll temp=recur(0, strlen(str)-1);
      printf("Case %d: %ld\n", qq, temp);
   }
    return 0;
}
