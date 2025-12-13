#include <stdio.h>
#include <stdlib.h>

void sort (int* a, int* b, int n);

int main(void)
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	int* a = malloc(sizeof(int) * n);
	int* b = malloc(sizeof(int) * n);
	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, b, n);
	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			printf(", "); 
		printf("%d", b[i]);
	}
	printf("\n"); 
	free(a);
	free(b);
}

void sort (int* a, int* b, int n)
{
	int max = a[0];
	int min = a[0]; // will be considered as the lowest integer to be placed
	for (int i = 1; i < n; i++)
	{
		if (max < a[i])
			max = a[i];
		if (min > a[i])
			min = a[i];
	}
	int* c = calloc(max - min + 1, sizeof(int));
	for (int i = 0; i < n; i++)
		c[a[i] - min]++;
	for (int i = 1; i < max - min + 1; i++)
		c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--)
		b[--c[a[i] - min]] = a[i];
	free(c);
}
