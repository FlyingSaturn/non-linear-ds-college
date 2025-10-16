#include <stdio.h>

int binsearch(int a[], int min, int max, int s);
int expsearch(int a[], int n, int s);

int comparisons = 0;

int main(void)
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter %d numbers: ", n);
	for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
	int s;
	printf("Searchable: ");
	scanf("%d", &s);
	int abc = expsearch(a, n, s);
	if (abc == -1)
		printf("Number not found.\n");
	else
		printf("Index = %d\n", abc);
}

int expsearch(int a[], int n, int s)
{
	comparisons++;
	if (a[0] == s)
		return 0;
	int i = 1, prev = 1;
	while (i < n && a[i] <= s)
	{
		comparisons++;
		prev = i;
		i *= 2;
	}
	comparisons++; // for an extra comparision on non-execution of while loop
	int min = i <= n - 1 ? i : n - 1;
	printf("Range found. It's probably between the indexes %d & %d, both inclusive.\n", prev, min);
	return binsearch(a, prev, min, s);
}

int binsearch(int a[], int min, int max, int s)
{
	comparisons++;
	if (max < min)
		return -1;
	int p = min + (max - min) / 2;
	comparisons++;
	if (a[p] == s)
		return p;
	comparisons++;
	if (s > a[p])
		return binsearch(a, p + 1, max, s);
	return binsearch(a, min, p - 1, s);
}


