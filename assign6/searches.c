#include <math.h>
#include <stdio.h>

int binsearch(int a[], int min, int max, int s);
int expsearch(int a[], int n, int s);
int linsearch(int a[], int min, int max, int s);
int jumpsearch(int a[], int n, int s);;
int interpolate(int a[], int l, int h, int s);
void success_or_failure(int index, int c);


int comparisons;

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
	printf("\n==Jump Search==\n");
	comparisons = 0;
	int index = jumpsearch(a, n, s);
	success_or_failure(index, comparisons);
	printf("\n==Exponential Search==\n");
	comparisons = 0;
	index = expsearch(a, n, s);
	success_or_failure(index, comparisons);
	printf("\n==Interpolation Search==\n");
	comparisons = 0;
	index = interpolate(a, 0, n - 1, s);
	success_or_failure(index, comparisons);
	printf("\n\n");
}

void success_or_failure(int index, int c)
{
	if (index == -1)
	printf("Number not found.\n");
	else
	printf("Number found in index: %d\n", index);
	printf("No. of comparisons required: %d\n", c);
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

int interpolate(int a[], int l, int h, int s)
{
	comparisons++;
    if (l > h)
		return -1;
	comparisons++;
	if (s < a[l]) 
		return -1;
	comparisons++;
	if (s > a[h])
        return -1;
	comparisons++;
    if (a[l] == a[h])
    {
		comparisons++;
        if (a[l] == s) return l;
        return -1;
    }
    int p = l + (long long)((s - a[l]) * (h - l)) / (a[h] - a[l]);
    comparisons++;
	if (p < l) p = l;
	comparisons++;
    if (p > h) p = h;
	comparisons++;
    if (a[p] == s)
        return p;
	comparisons++;
    if (a[p] > s)
        return interpolate(a, l, p - 1, s);
    return interpolate(a, p + 1, h, s);
}
