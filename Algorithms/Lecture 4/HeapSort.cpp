#include <iostream>
using namespace std;

void heapify(int a[], int i, int n)
{
	int l = 2*i + 1;
	int r = l+1;
	int largest  = i;
	if(l<n && a[l]>a[i] && a[l]>=a[r])
	{
		largest = l; 
	}
	else if(r<n && a[r]>a[i] && a[r]>=a[l])
	{
		largest = r;
	}
	if(largest != i)
	{
		int temp = a[largest];
		a[largest] = a[i];
		a[i] = temp;
		heapify(a,largest,n);
	}
}

void BuildMaxHeap(int a[], int n)
{
	int i;
	for(i=n/2;i>=1;i--)
	{
		heapify(a,i,n);
	}
}

void heapsort(int a[], int n)
{
	BuildMaxHeap(a,n);
	int i;
	for(i=n/2;i>=1;i--)
	{
		int temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		heapify(a,0,n);
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int a[n],i;
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	heapsort(a,n);
	for(i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
