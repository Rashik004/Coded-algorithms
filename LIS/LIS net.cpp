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
using namespace std;

const int neg_infinite=-1047483648;

int input[1000000];

void binary_search(int start, int end, int key)
{
	int mid;
	while(start<=end)
	{
		mid=(start+end)/2;

		if(input[mid] == key)
			return;
		else if(input[mid] > key)
			end=mid-1;
		else
			start=mid+1;
	}
	if(input[start]<key)  // no need;  just for safety!!
		start++;
	input[start]=key;
}


main()
{
//    freopen("input.txt","rt",stdin);
//    freopen("out.txt","wt",stdout);

	int i,n,cur,num,set=1;

	while(scanf("%d",&n)==1 && n!=0)
	{
		cur=0;
		input[0]=neg_infinite;
		for(i=1;i<=n;i++)
		{
			scanf("%d",&num);
			if(num > input[cur])
			{
				cur++;
				input[cur]=num;
			}
			else if(num < input[cur])
			{
				binary_search(0,cur,num);
			}
		}
		printf("Set %d: %d\n",set++,cur);
	}



return 0;
}
