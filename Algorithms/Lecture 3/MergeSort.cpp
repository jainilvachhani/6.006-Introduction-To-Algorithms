#include <iostream>
#include <limits.h>
using namespace std;

void merge(int a[], int p, int q, int r)
{
	int n1 = q - p + 1;
	int n2 = r - q;
	int L[n1+1],R[n2+1];
	int i;
	for(i=0;i<n1;i++)
	{
		L[i] = a[p+i];
	}
	for(i=0;i<n2;i++)
	{
		R[i] = a[q+i+1];
	}
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	int k,j;
	j = 0;
	i = 0;
	for(k=p;k<=r;k++)
	{
		if(L[i]<=R[j])
		{
			a[k] = L[i];
			i++;
		}
		else
		{
			a[k] = R[j];
			j++;
		}
	}
}

void sort(int a[], int p, int r)
{
	int q = (p+r)/2;
	if(p < r)
	{
		sort(a,p,q);
		sort(a,q+1,r);
		merge(a,p,q,r);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int i,a[n];
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,0,n-1);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
