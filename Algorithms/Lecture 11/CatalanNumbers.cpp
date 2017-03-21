#include <iostream>
using namespace std;

int catalan(int n)
{
	if(n==1)
	{
		return 1;
	}
	else if(n==0)
	{
		return 1;
	}
	else
	{
		int temp = n-1;
		int i,ans=0;
		for(i=0;i<=temp;i++)
		{
			ans += catalan(i)*catalan(temp-i);
		}
		return ans;
	}
}

int main() {
	int n;
	scanf("%d",&n);
	int ans = catalan(n);
	printf("%d",ans);
	return 0;
}
