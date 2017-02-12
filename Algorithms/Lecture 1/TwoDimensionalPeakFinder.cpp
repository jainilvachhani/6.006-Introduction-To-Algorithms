#include <iostream>
using namespace std;
const int n=3,m=3;
int TwoDimensionalPeakFinder(int a[][m], int low, int high)
{
	int mid = (high+low)/2;
	int i,j;
	int max = 0, index = 0;
	for(j = 0; j<=high; j++)
	{
		if(a[mid][j] > max)
		{
			max = a[mid][j];
			index = j;
		}
	}
	if(high==low)
	{
		return max;
	}
	if(a[mid-1][index] > max)
	{
		return TwoDimensionalPeakFinder(a,low,mid-1);
	}
	else if(a[mid+1][index] > max)
	{
		return TwoDimensionalPeakFinder(a,mid+1,high);
	}
	else
	{
		return max;
	}
}

int main() {
	
	int a[n][m],i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int high = n-1,low = 0;
	printf("%d",TwoDimensionalPeakFinder(a,0,n-1));
	return 0;
}

