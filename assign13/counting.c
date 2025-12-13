#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter %d elements: ", n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int max = a[0];
	for (int i = 1; i < n; i++)
		if (max < a[i])
			max = a[i];
	int b[n];
	int* c = (int *) calloc(max + 1, sizeof(int));
	for (int i = 0; i < n; i++)
		c[a[i]]++;
	for (int i = 1; i < max + 1; i++)
		c[i] += c[i - 1];
	for (int i = n - 1; i >= 0; i--)
		b[--c[a[i]]] = a[i];
	
	printf("Sorted array: ");
	for (int i = 0; i < n; i++)
	{
		if (i != 0)
			printf(", "); 
		printf("%d", b[i]);
	}
	printf("\n"); 
	free(c);
}

