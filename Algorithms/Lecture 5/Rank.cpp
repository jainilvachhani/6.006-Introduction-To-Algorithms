#include <iostream>
#include <math.h>
using namespace std;

int Rank(int a[], int rank[], int pos, int time)
{
	if(a[pos] >= time)
	{
		int temp = 2*pos + 1;
		return 1 + rank[temp];
	}
	else if(a[pos]<time)
	{
		int temp = 2*pos + 1;
		return rank[temp] + 1 + Rank(a,rank,temp+1,time); 
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int size = pow(2,n);
	int a[size],i;
	int rank[size];
	for(i=0;i<size;i++)
	{
		a[i] = 0;
	}
	for(i=0;i<size;i++)
	{
		rank[i] = 0;
	}
	int elements;
	scanf("%d",&elements);
	for(i=0;i<elements;i++)
	{
		int pos;
		scanf("%d",&pos);
		int val;
		scanf("%d",&val);
		a[pos] = val;
	}
	for(i=0;i<elements;i++)
	{
		int pos;
		scanf("%d",&pos);
		int val;
		scanf("%d",&val);
		rank[pos] = val;
	}
	int time;
	scanf("%d",&time);
	printf("%d",Rank(a,rank,0,time));
	return 0;
}
