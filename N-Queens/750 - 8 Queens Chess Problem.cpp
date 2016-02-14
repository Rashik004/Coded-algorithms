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
class queen{
    public:
    int fixedRow,fixedCol,n,col[9],soln;;
    bool fixed_place(int k,int i);
    void print();
    void fixed_NQueen(int k);
    void fixing(int a,int b);
    queen(int x){n=x;soln=1;};
};

void queen::print()
{
    printf("%2d      ",soln++);
    cout<<col[1];
    for(int i=2;i<=8;i++)
        cout<<" "<<col[i];
    cout<<endl;
    
}



bool queen::fixed_place(int k,int i)
{
    if(k==fixedRow)
        return false;
    if(abs(k-fixedRow)==abs(i-fixedCol))
        return false;
    for(int j=1;j<=i-1;j++)
    {
        if(col[j]==k)
            return false;
        
        if(abs(col[j]-k)==abs(j-i))
            return false;  
    }
    return true;
}




void queen::fixed_NQueen(int k)
{
    if(k==fixedCol)
    {
        if(k==n)
            print();
        else
            fixed_NQueen(k+1);
        return;
    }    
    for(int i=1;i<=n;i++)
    {
        if(fixed_place(i,k))
        {
            col[k]=i;
            if(k==n)
                print();
            else
                fixed_NQueen(k+1);
        }
    }
}

void queen::fixing(int a,int b)
{
    fixedRow=a;
    fixedCol=b;
    col[fixedCol]=a;
}

int main()
{
    int test,fix1,fix2;
//    freopen("newqueen.txt","w",stdout);
    cin>>test;
    for(int i=1;i<=test;i++)
    {
        if(i!=1)
            cout<<endl;
        cin>>fix1>>fix2;
        queen obj(8);
        obj.fixing(fix1,fix2);
        cout<<"SOLN       COLUMN"<<endl<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        obj.fixed_NQueen(1);
    }
}