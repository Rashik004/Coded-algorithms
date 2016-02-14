//Longest Increasing Subsequence LIS n log n complexity
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define CLEAR(a) memset(a,0,sizeof(a))
#define MAXELE 62600
using namespace std;

//const int neg_infinite=-1047483648;

int tailTable[MAXELE],numbers[MAXELE];

void binary_search(int start, int end, int key)
{
	int mid;
	while(start<=end)
	{
		mid=(start+end)/2;

		if(tailTable[mid] == key)
			return;
		else if(tailTable[mid] > key)
			end=mid-1;
		else
			start=mid+1;
	}
	if(tailTable[start]<key)  // no need;  just for safety!!
		start++;
	tailTable[start]=key;
}


int lis(int elements)
{
    int i,n,cur,num,set=1;
    
    cur=1;
    tailTable[0]=numbers[0];
    for(int i=1;i<elements;i++)
    {
        num=numbers[i];
        if(num>tailTable[cur-1])
            tailTable[cur++]=num;
        else if(num<tailTable[cur-1])
            binary_search(0,cur-1,num);
    }
    return cur;
}


int main ()
{
    int testCase,lenX,lenY,a,b,index,x[62600];
    scanf("%d", &testCase);
    for(int qq=1;qq<=testCase;qq++)
    {
        scanf("%*d %d %d", &lenX,&lenY);
        lenX++;
        lenY++;
        memset(x,-1,sizeof x);
        
        for(int i=0;i<lenX;i++)
        {
            scanf("%d", &a);
            x[a]=i;
        }
        for(int i=0;i<lenY;i++)
        {
            scanf("%d", &a);
            numbers[i]=x[a];
        }
        
      
        printf("Case %d: %d\n",qq, lis(lenY));
    }
    return 0;
}