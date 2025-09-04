#include <math.h>
#include <stdio.h>

int highest(int n, int arr[]);
int mountain(int n, int a[], int highest);

int main(void)
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	printf("Array: ");
	int a[n];
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	int hi = highest(n, a);
	if (mountain(n, a, hi) == -1)
		printf("Not a mountain array.\n");
	else if (mountain(n, a, hi) == 0)
		printf("An asymmetric mountain array, peak = %d\n", a[hi]);
	else if (mountain(n, a, hi) == 1)
		printf("A symmetric mountain array, peak = %d\n", a[hi]);
}

int highest (int n, int arr[])
{
        int max = 0;
        for (int i = 0; i < n; i++)
                if (arr[max] < arr[i])
                        max = i;
        return max;
}


int mountain(int n, int a[], int highest)
{
	if (highest == 0 || highest == n - 1)
		return -1;
	int start = 0; 
	int end = n - 1;
	while (a[start] < a[start + 1] || a[end - 1] > a[end])
	{
	        printf("%d %d\n", start, end);
		if (a[start] < a[start + 1])
			start++;
		if (a[end - 1] > a[end])
			end--;
                printf("%d %d\n", start, end);
	}
	if (a[start] == a[start + 1] || a[end - 1] == a[end])
		return -1;
	if (start != end)
		return -1;
	if (start - 0 == (n - 1) - end)
	        return 1;
	return 0;
}
