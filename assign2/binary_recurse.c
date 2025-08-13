#include <stdio.h>

int binary_recurse(int a[], int s, int low, int high);

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    printf("The array of %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int s;
    printf("No. to search: ");
    scanf("%d", &s);

    int d, op = -1;
    while (!(op >= 1 && op <= 3))
    {
        printf("How do you want your results?\n1. Recursion\n2. Iteration\n3. Both\nEnter your choice: ");
        scanf("%d", &op);
        d = binary_recurse(a, s, 0, n - 1);
        if (d == -1)
            printf("Number not found.\n");
        else
            printf("Number found! Position: %d\n", d);
    }
}


int binary_recurse(int a[], int s, int low, int high)
{
    if (low > high)
        return -1;
    int p = (low + high) / 2;
    if (a[p] < s)
        return binary_recurse(a, s, p + 1, high);
    if (a[p] > s)
        return binary_recurse(a, s, low, p - 1);
    if (a[p] == s)
        return p;
}