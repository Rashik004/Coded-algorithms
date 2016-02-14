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
using namespace std;
int x[9],result=1,col[9];
bool place(int k,int i)
{
    for(int j=1;j<=i-1;j++)
    {
        if(col[j]==k)
            return false;
        
        if(abs(col[j]-k)==abs(j-i))
            return false;
    }
    return true;
}

void print()
{
    
//    if(!(x[2]==3))
//        return;
    printf("Serial no %d\n",result++);
    for(int i=1;i<=8; i++)
        cout<<col[i]<<" "<<i<<endl;
    cout<<"*****END OF OUTPUT*******"<<endl<<endl<<endl;
}
void NQueen(int k,int n)
{
    for(int i=1;i<=n;i++)
    {
        if(place(i,k))
        {
            col[k]=i;
            if(k==n)
                print();
            else
                NQueen(k+1,n);
        }
    }
}
int main ()
{
    freopen("newqueen.txt","w",stdout);
    NQueen(1,8);
    return 0;
}