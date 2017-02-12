#include <iostream>
using namespace std;

int OneDimensionalPeakFinder(int a[], int low, int high)
{
	int mid = (high+low+1)/2;
	if(high == low)
	{
		return a[high];
	}
	if(a[mid] < a[mid+1])
	{
		return OneDimensionalPeakFinder(a,mid+1,high);
	}
	else if(a[mid] < a[mid-1])
	{
		return OneDimensionalPeakFinder(a,low,mid-1);
	}
	else
	{
		return a[mid];
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
	printf("%d",OneDimensionalPeakFinder(a,0,n-1));
	return 0;
}
