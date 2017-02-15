#include <iostream>
#include <string.h>
using namespace std;

int DocumentDistance(int a[], int b[],int n)
{
	int i,sum=0;
	for(i=0;i<26;i++)
	{
		sum += a[i]*b[i];
	}
	sum = sum/(n);
	return sum;
}

int main() {
	int n;
	scanf("%d",&n);
	char a[n],b[n];
	scanf("%s",a);
	scanf("%s",b);
	int s1[26],s2[26];
	int i;
	for(i=0;i<26;i++)
	{
		s1[i] = 0;
		s2[i] = 0;
	}
	for(i=0;i<strlen(a);i++)
	{
		s1[a[i]-'a']++;
	}
	for(i=0;i<strlen(b);i++)
	{
		s2[b[i]-'a']++;
	}
	printf("%d",DocumentDistance(s1,s2,n));
	return 0;
}
