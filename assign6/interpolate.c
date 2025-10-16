#include <stdio.h>

int interpolate(int a[], int l, int h, int s);

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

    int abc = interpolate(a, 0, n - 1, s);
    if (abc == -1)
        printf("Number not found.\n");
    else
        printf("Index = %d", abc);
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
