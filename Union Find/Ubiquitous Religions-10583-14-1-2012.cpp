#include<stdio.h>
#include<vector>
using namespace std;
vector<long int>v;
long int find(long int n)
{
   if(v[n]!=n)
     v[n]=find(v[n]);
   return v[n];
}
int link(long int x,long int y)
{
   v[find(x)]=find(y);
   return 0;
}
int main()
{
   //freopen("E:/Input.txt","r",stdin);
   long int i,j,k=1,l,m,n,x,y,p,q,count;
   vector<long int>a;
   for(i=0;i<50002;i++)
     a.push_back(i);
   while(scanf("%ld %ld",&n,&m)&&(n+m))
   {
      v=a;
      for(i=0;i<m;i++)
      {
         scanf("%ld %ld",&x,&y);
         link(x,y);
      }
      count=0;
      for(i=1;i<=n;i++)
      {
         if(v[i]==i)
           count++;
      }
      printf("Case %ld: %ld\n",k++,count);
   }
return 0;
}
