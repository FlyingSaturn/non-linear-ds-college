#include <math.h>
#include <stdio.h>

int linsearch(int a[], int min, int max, int s);
int jumpsearch(int a[], int n, int s);

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
	int abc = jumpsearch(a, n, s);
	if (abc < 0)
		printf("Number not found.\n");
	else
		printf("Index: %d\n", abc);
}

int jumpsearch(int a[], int n, int s)
{
	int prev = 0;
	int step = (int) floor(sqrt(n));
	int i = 0;
	comparisons++; // only one data comparison in for loop
	for (i = 0; i < n && a[i] < s; prev = i, i += step, comparisons++);
	if (i >= n)
		return linsearch(a, prev, n, s);
	else 
	{
		comparisons++;
		if (a[i] == s)
		{
			return i;
		}
		else // (a[i] > s)
		{
			return linsearch(a, prev, i + 1, s);
		}
	}
}


int linsearch(int a[], int min, int max, int s)
{
	for (int j = min; j < max; j++)
	{
		comparisons++;
		if (a[j] == s)
			return j;
	}
	return -1;
}
