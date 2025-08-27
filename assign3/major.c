#include <stdio.h>

int main(void)
{
    int m, n;
    printf("m: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    int a[m][n];
    printf("Enter the matrix of order %dx%d:\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    printf("Indexes\tRow Major\t\tColumn Major\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int *raddr = &a[0][0] + (i * n + j);
            int *coladdr = &a[0][0] + (i + j * m);
            printf("a[%d][%d]\t%p\t\t%p\n", i, j, raddr, coladdr);
        }
    }
    if (&a[0][1] == &a[0][0] + (0 * n + 1))
        printf("Follows Row Major addressing.\n");
    else
        printf("Follows Column Major addressing.\n");
}
