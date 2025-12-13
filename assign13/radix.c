#include <stdio.h>

int main(void)
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	int a[n];	
	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int dig = max_digit(a, n);
	radix_sort(a, n, dig);
}

int max_digit(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (max < a[i])
			max = a[i];
	int digits = 0;
	while (max != 0)
	{
		digits++;
		max = (int) max / 10;
	}
	return digits;
}

int radix_sort(int a[], int n, int k)
{
	for (int i = 0; i <= k; i++)
	{

}
