#include <math.h>
#include <stdio.h>

int extremes(int n, int arr[]);
int mountain(int n, int a[]);

int main(void)
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	printf("Array: ");
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int hi = extremes(n, a);
	if (hi == -1)
	{
		printf("Not a mountain array.\n");
		return 0;
	}
	int res = mountain(n, a);
	if (res == -1)
		printf("Not a mountain array.\n");
	else if (res == 0)
		printf("An asymmetric mountain array, peak = %d\n", a[hi]);
	else if (res == 1)
		printf("A symmetric mountain array, peak = %d\n", a[hi]);
}

int extremes(int n, int arr[])
{
	int max = 0;
	for (int i = 0; i < n; i++)
		if (arr[max] < arr[i])
			max = i;
	if (max == 0 || max == n - 1)
		return -1;
	return max;
}

int mountain(int n, int a[])
{
	int start = 0; 
	int end = n - 1;
	while (a[start] < a[start + 1] || a[end - 1] > a[end])
	{
		if (a[start] < a[start + 1])
			start++;
		if (a[end - 1] > a[end])
			end--;
	}
	if (a[start] == a[start + 1] || a[end - 1] == a[end])
		return -1;
	if (start != end)
		return -1;
	if (start - 0 == (n - 1) - end)
		return 1;
	return 0;
}
