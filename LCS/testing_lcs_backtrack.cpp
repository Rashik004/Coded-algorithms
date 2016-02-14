//Rashik Hasnat KUET_DOUR rashikhasnat@ymail.com
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

class lcs_bottom_up{
public:
    int bottom_up();
    string X,Y;
    int lcs[200][200];
    int lenx,leny;
    void find_len();
    void print_em_all();
    int maxi(int, int);
    void traceback(int i, int j);
};

void lcs_bottom_up:: find_len()
{
    lenx=X.size();
    leny=Y.size();
}

int lcs_bottom_up::bottom_up()
{
    find_len();
    for(int i=0; i<=lenx; i++)
        lcs[i][0]=0;
    for(int i=0; i<=leny; i++)
        lcs[0][i]=0;
    for(int i=1; i<=lenx; i++)
        for(int j=1; j<=leny; j++)
        {
            if(X[i-1]==Y[j-1])//i is the ith character of X which means i-1 index same goes for j with Y
                lcs[i][j]=1+lcs[i-1][j-1];
            else
                lcs[i][j]=maxi(lcs[i-1][j], lcs[i][j-1]);
//                cout<<"lcs("<<i<<","<<j<<")= "<<lcs[i][j]<<endl;
        }
        return lcs[lenx][leny];
}

int lcs_bottom_up::maxi(int a, int b)
{
    if(a>b)
        return a;
    else
        return b;
}


void lcs_bottom_up::print_em_all()
{
    cout<<"\t";
    for(int i=0; i<=Y.size(); i++)
        cout<<i<<"\t";
        cout<<endl;
    for(int i=0; i<=Y.size()+1; i++)
        cout<<"---"<<"\t";
        cout<<endl;        
    for(int i=0; i<=X.size();i++)
    {
        cout<<i<<"|\t";
        for(int j=0; j<=Y.size(); j++)
            cout<<lcs[i][j]<<"\t";
        cout<<endl;
    }
}


void lcs_bottom_up::traceback(int i, int j){

 cout<<i<<'\t'<<j<<endl;
 if(i == 0|| j == 0)return;

 if(X[i-1] == Y[j-1]) {
     traceback(i-1, j-1);
     cout << X[i-1];
 }
 else if(lcs[i-1][j] > lcs[i][j-1])
     traceback(i-1, j);
 else traceback(i, j-1);
}

int main ()
{
    freopen("Output.txt","w",stdout);
    lcs_bottom_up test;
    while(cin>>test.X>>test.Y)
    {
//        getline(cin,test.X);
//        if(test.X.size()==0)
//            break;
//        cin>>test.Y;
        cout<<test.X<<endl<<test.Y<<endl;
        cout<<test.bottom_up()<<endl;
        cout<<endl<<endl<<endl;
        test.print_em_all();
    test.traceback(test.X.size(),test.Y.size());
    }
    return 0;
}