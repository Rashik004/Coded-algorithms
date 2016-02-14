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
#define MAXELE 64
int x[MAXELE+1],result=1;
int n;
bool place(int row,int col)
{

    for(int j=1;j<=row-1;j++)
    {
        if(x[j]==col)
            return false;

        if(abs(x[j]-col)==abs(j-row))//diagonal check
            return false;
        //superqueen modification
//        if(x[row-1]==col-2 || x[row-1]==col+2)
//            return false;
//        if(row>2 && x[row-2]==col-1 || x[row-2]==col+1)
//            return false;
        
    }
    return true;
}

void print()
{
    printf("Serial no %d\n",result++);
    for(int i=1;i<=n; i++)
        cout<<i<<" "<<x[i]<<endl;
    cout<<"\n\n";
}


void NQueen(int row)
{
    for(int col=1;col<=n;col++)
    {
        if(place(row,col))
        {
            x[row]=col;
            if(row==n)
                print();
            else
                NQueen(row+1);
        }
        if(row==1 && col==n/2)//TO PREVENT MIRROR
            return;
    }
}
int main ()
{
    cout<<"Enter the dimension of the board\n";
    //freopen ("output.txt","w",stdout);
    while(cin>>n)
    {
            result=1;
            printf("For %d*%d board:\n",n,n);
            NQueen(1);
            cout<<"Enter the dimension of the board\n";
    }
    return 0;
}
