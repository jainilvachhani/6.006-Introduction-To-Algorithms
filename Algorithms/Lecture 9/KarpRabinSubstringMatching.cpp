#include <iostream>
#include <string.h>
#include <math.h>
#define d 256
using namespace std;

int search(char pattern[], char text[], int prime)
{
	int m = strlen(pattern);
	int n = strlen(text);
	int i,j,p=0,t=0,h=1;
	h = pow(d,m-1);
	h = h%prime;
	
	for(i=0;i<m;i++)
	{
		p = (d*p + pattern[i])%prime;
		t = (d*t + text[i])%prime;
	}
	for(i=0;i<=n-m;i++)
	{
		if(p==t)
		{
			for(j=0;j<m;j++)
			{
				if(text[i+j]!=pattern[j])
				{
					break;
				}
			}
			if(j==m)
			{
				return 1;
			}
		}
		if(i<n-m)
		{
			t = (d*(t-text[i]*h) + text[i+m])%prime;
		}
		if(t<0)
		{
			t = t + prime;
		}
	}
	return 0;
}

int main() {
	char text[100];
	char pattern[100];
	int prime = 101;
	scanf("%s",text);
	scanf("%s",pattern);
	if(search(pattern,text,prime))
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
