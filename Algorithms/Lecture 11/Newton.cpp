#include <stdio.h>
#include <math.h>
float newton(float x)
{
	float guess = 1;
	while  (abs((guess * guess) / x  - 1.0) >= 0.0001 )
	{
		guess = ((x/guess)+guess)/2;
	}
	return guess;
}

int main()
{
	float n;
	scanf("%f",&n);
	float ans = newton(n);
	printf("%f\n",ans);
}
