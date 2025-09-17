#include <stdio.h>

double divide(double a, int divisor);

int main(void)
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	double n1 = n;
	if (n1 < 2)
	{
		printf("%.0lf is not an ugly number.\n", n1);
		return 0;
	}
	if (divide(divide(divide(n1, 2), 3), 5) == 1)
		printf("%.0lf is an ugly number.\n", n1);
	else
		printf("%.0lf is not an ugly number.\n", n1);
}

double divide(double a, int divisor)
{
	while ((int)a % divisor == 0)
		a /= divisor;
	return a;
}
