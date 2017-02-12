#include <iostream>
#include <string.h>
using namespace std;

int DocumentDistance(char a[], char b[])
{
	int length=0;
	int i;
	for(i=0;i<strlen(a);i++)
	{
		length += (a[i] - 'a' + 1) * (b[i] - 'a' + 1);
	}
	length = length/(strlen(a)*strlen(a));
	return length;
}

int main() {
	int n;
	scanf("%d",&n);
	char a[n],b[n];
	scanf("%s",a);
	scanf("%s",b);
	printf("%d",DocumentDistance(a,b));
	return 0;
}
