#include <iostream>
#include <math.h>
using namespace std;

int RunwayResearvation(int a[], int n, int k, int insert, int key)
{
	int i = key;
	int size = pow(2,n);
	while(1)
	{
		if(a[i]>insert)
		{
			if(abs(a[i] - k) <= insert)
			{
				return 0;
			}
			else if(key >= (size/2) + 1)
			{
				key = (key/2)*2 + 1;
				printf("key in insert is %d\n",key);
				a[key] = insert;
				return 1;
			}
			else
			{
				key = 2*i + 1;
				return RunwayResearvation(a,n,k,insert,key);
			}
 		}
 		else if(a[i]<=insert)
 		{
 			if(abs(a[i] + k) >= insert)
			{
				return 0;
			}
			else if(key >= (size/2) + 1)
			{
				key = (key/2)*2 + 2;
				a[key] = insert;
				return 1;
			}
			else
			{
				key = 2*i + 2;
				return RunwayResearvation(a,n,k,insert,key);
			}
 		}
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int k;
	scanf("%d",&k);
	int size = pow(2,n);
	int a[size];
	int i;
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
	int insert;
	scanf("%d",&insert);
	if(RunwayResearvation(a,n,k,insert,0))
	{
		printf("True\n");
	}
	else
	{
		printf("False\n");
	}
	return 0;
}
