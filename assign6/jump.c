#include <math.h>
#include <stdio.h>

int linsearch(int a[], int min, int max, int s);

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
	int prev = 0;
	int step = (int) floor(sqrt(n));
	int i = 0;
	for (i = 0; i < n && a[i] < s; prev = step, i += step);
	int abc = -1;
	if (a[i] == s)
		abc = i;
	else if (i >= n)
		abc = linsearch(a, prev, n, s);
	else if (a[i] > s)
		abc = linsearch(a, prev, i + 1, s);
	if (abc < 0)
		printf("Number not found.\n");
	else
		printf("Index: %d\n", abc);
}

int linsearch(int a[], int min, int max, int s)
{
	for (int j = min; j < max; j++)
		if (a[j] == s)
			return j;
	return -1;
}
