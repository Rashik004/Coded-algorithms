// C++ Code for LIS - Longest increasing subsequence
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define CLEAR(a) memset(a,0,sizeof(a))
#define MAXELE 100000
using namespace std;

//const int neg_infinite=-1047483648;

int tailTable[MAXELE],numbers[MAXELE]={4,25,3,15,11,24,3,9,12,29,15};

void binary_search(int start, int end, int key)
{
	int mid;
	while(start<=end)
	{
		mid=(start+end)/2;

		if(tailTable[mid] == key)
			return;
		else if(tailTable[mid] < key)
			end=mid-1;
		else
			start=mid+1;
	}
	if(tailTable[start]>key)  // no need;  just for safety!!
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
        if(num<tailTable[cur-1])
            tailTable[cur++]=num;
        else if(num>tailTable[cur-1])
            binary_search(0,cur-1,num);
    }
    return cur;
}
main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

	int i=0,n,cur,num,set=1;


    while(scanf("%d", &numbers[i++])!=EOF);
    
    cout<<lis(i-1)<<endl;


return 0;
}
