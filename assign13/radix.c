#include <stdio.h>
#include <math.h>

int max_digit(int a[], int n);
int radix_sort(int a[], int n, int k);
void counting(int a[], int n, int pos);

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
	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", a[i]);
	}
	printf("\n");
}

int max_digit(int a[], int n)
{
	int max = a[0];
	for (int i = 1; i < n; i++)
		if (max < a[i])
			max = a[i];
	int digits = max == 0 ? 0 : floor(log10(max)) + 1;
	return digits;
}

int radix_sort(int a[], int n, int k)
{
	int pos = 1;

	for (int i = 0; i <= k; i++)
	{
		counting(a, n, pos);
		pos *= 10;
	}
}

void counting(int a[], int n, int pos)
{
	int c[10] = {0};
	int b[n];
	for (int i = 0; i < n; i++)
	{
		int digit = (a[i] / pos) % 10;
		c[digit]++;
	}
	for (int i = 1; i < 10; i++)
		c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--)
	{
		int digit = (a[i] / pos) % 10;	
		b[--c[digit]] = a[i];
	}
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}
