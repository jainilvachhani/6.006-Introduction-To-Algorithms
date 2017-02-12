#include <iostream>
using namespace std;

void InsertionSort(int a[], int n)
{
	int i;
	int j;
	for(i=1;i<n;i++)
	{
		j = i;
		while(a[j]<a[j-1] && j>0)
		{
			int temp;
			temp = a[j];
			a[j] = a[j-1];
			a[j-1] = temp;
			j--;
		}
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
	InsertionSort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}

