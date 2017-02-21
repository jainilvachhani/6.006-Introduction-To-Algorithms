#include <iostream>
#include <cstdlib>
using namespace std;

int getmax(int a[], int n)
{
	int max = a[0];
	for(int i=0;i<n;i++)
	{
		if(a[i]>max)
		{
			max = a[i];
		}
	}
	return max;
}

void countsort(int a[], int n, int exp)
{
	int out[n];
	int i, count[10] = {0};
	for(i=0;i<n;i++)
	{
		count[(a[i]/exp)%10]++;
	}
	for(i=1;i<10;i++)
	{
		count[i] += count[i-1];
	}
	for(i=n-1;i>=0;i--)
	{
		out[count[(a[i]/exp)%10]-1] = a[i];
		count[(a[i]/exp)%10]--;
	}
	for(i=0;i<n;i++)
	{
		a[i] = out[i];
	}
}

void radixsort(int a[],int n)
{
	int m = getmax(a,n);
	for(int exp = 1; m/exp>0;exp*=10)
	{
		countsort(a,n,exp);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++)
	{
		int temp;
		scanf("%d",&temp);
		a[i] = temp;
	}
	radixsort(a,n);
	for(i=0;i<n;i++)
	{	
		printf("%d ",a[i]);
	}
	return 0;
}
