#include <stdio.h>

int main(void)
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter the numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Leader elements: ");
    int max = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= max)
        {
            printf("%d ", a[i]);
            max = a[i];
        }
    }
    printf("\n");
}

