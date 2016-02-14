#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define MAX 705
using namespace std;
int needed[MAX],coin[]={5,10,20,50,100,200},coinNum=6,lim[6],shopkeeper[MAX];

void shop(int am)//যেহেতু দোকানদারের কাছে অসংখ্য কয়েন আছে তাই তার হিসাব আলাদা
{
    memset(shopkeeper,0,sizeof shopkeeper);
    for(int i=0;i<=am;i+=5)
        shopkeeper[i]=i/5;
    
    int temp;
    for(int i=1;i<coinNum;i++)
        for(int j=0;j<=am;j+=5)
        {
            temp=j+coin[i];
            if(j>am)
                break;
            shopkeeper[temp]=min(shopkeeper[j]+1, shopkeeper[temp]);
        }
}

int check(int x,int y)
{
    if(x==-1)
        return y;
    return min(x,y);
}

int coinChange(int am)// সীমিত সংখ্যক কয়েন দিয়ে কত কম কয়েনে অ্যামাউন্টটা বানানো যায়
{
    memset(needed,-1,sizeof needed);
    
    needed[0]=0;
    int temp;
    for(int i=1;i<=lim[0];i++)
    {
        temp=i*coin[0];
        if(temp>am)
            break;
        needed[temp]=i;
    }
    
    for(int i=1;i<coinNum;i++)
        for(int j=am;j>=0;j-=5)
            for(int k=1;k<=lim[i];k++)
            {
                temp=j-coin[i]*k;
                if(temp<0)
                    break;
                if(needed[temp]==-1)// যদি temp আগে বানানো না যেয়ে থাকে তাইলে এখনো বানানো যাবেনা
                    continue;
                int temp2=needed[temp]+k;
                
                needed[j]=check(needed[j],temp2);
            }
}
int main ()
{
    int testCase,x,y,priceInCent,minM;
    double price;
    shop(MAX);
    bool cholbe=false;
    while(2)
    {
        bool cholbe=false;
        for(int i=0;i<coinNum;i++)
        {
            cin>>lim[i];
            if(lim[i])
                cholbe=true;
        }
        if(!cholbe)
            break;
        cin>>price;
        minM=5000;
        priceInCent=price*100;
        
        if(priceInCent%5==4)
            priceInCent++;
        else if(priceInCent%5==1)
            priceInCent--;
            
            
        int temp=priceInCent+200,dif;
        coinChange(temp);// মোট মুল্যের থেকে ২০০ সেন্ট পর্যন্ত বেশিতে হিসাব করছি
        
        for(int i=priceInCent;i<=temp;i+=5)
        {
            if(needed[i]==-1)
                continue;
            dif=i-priceInCent;// দোকানদার dif পরিমান টাকা ফেরত দিবে 
            minM=min(minM, shopkeeper[dif]+needed[i]);
        }
        
        printf("%3d\n", minM);
    }
    return 0;
}

