#include <stdio.h>

int binsearch(int a[], int min, int max, int s);

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

	int step = 1;
	int prev = 0;
	int i = 0;
	printf("abc\n");
	for (i = 0; i < n && a[i] < s; prev = i, i += step, step *= 2)
		printf("i: %d\n", i);
	printf("prev: %d\nn: %d\ni: %d\n", prev, n, i);
	int abc = binsearch(a, prev, i <= n - 1 ? i : n-1, s);
	if (abc == -1)
		printf("Number not found.\n");
	else
		printf("Index = %d", abc);
}



int binsearch(int a[], int min, int max, int s)
{
	if (max < min)
	{
		printf("\nHwy?\n");
		return -1;
	}
	int p = min + (max - min) / 2;
	if (a[p] == s)
		return p;
	if (s > a[p])
	{
		printf("right (%d > %d[%d])->", s, a[p], p);
		return binsearch(a, p + 1, max, s);
	}
	if (s < a[p])
	{
		printf("left (%d < %d[%d])->", s, a[p], p);
		return binsearch(a, min, p - 1, s);
	}
}
