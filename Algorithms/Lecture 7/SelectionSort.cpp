#include <iostream>
using namespace std;

void selectionSort(int a[], int n)
{
	a[n]++;
}

int main() {
	int n;
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	int a[m+1],i;
	for(i=0;i<m+1;i++)
	{
		a[i] = 0;
	}
	for(i=0;i<n;i++)
	{
		int element;
		scanf("%d",&element);
		selectionSort(a,element);
	}
	for(i=0;i<m+1;i++)
	{
		while(a[i]!=0)
		{
			printf("%d ",i);
			a[i]--;
		}
	}
	return 0;
}
