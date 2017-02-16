#include <iostream>
#include <math.h>
using namespace std;

void InorderTraversal(int a[], int i)
{
	if(a[i]!=0)
	{
		InorderTraversal(a, 2*i + 1);
		printf("%d ",a[i]);
		InorderTraversal(a, 2*i + 2);
	}
}


int main() {
	int n;
	scanf("%d",&n);
	int size = pow(2,n);
	int a[size],i;
	for(i=0;i<size;i++)
	{
		a[i] = 0;
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
	InorderTraversal(a,0);
	return 0;
}
