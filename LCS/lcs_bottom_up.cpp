//Rashik Hasnat KUET_DOUR rashikhasnat@ymail.com
#include<iostream>
#include<cstring>
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
    for(int i=0; i<=X.size();i++)
    {
        cout<<i<<"\t";
        for(int j=0; j<=Y.size(); j++)
            cout<<lcs[i][j]<<"\t";
        cout<<endl;
    }
}

int main ()
{
    lcs_bottom_up test;
    while(cin>>test.X>>test.Y)
    {
//        getline(cin,test.X);
//        if(test.X.size()==0)
//            break;
//        cin>>test.Y;
        cout<<test.bottom_up()<<endl;
        cout<<endl<<endl<<endl;
        test.print_em_all();
    }
    return 0;
}