#include <stdio.h>
int main(void)
{
	double s;
	printf("Threshold sparsity s: ");
	scanf("%lf", &s);
	if (s >= 1)
	{
		printf("Threshold impossible to achieve.\n");
		return 0;
	}
    int m, n;
    printf("m: ");
    scanf("%d", &m);
    printf("n: ");
    scanf("%d", &n);
    int a[m][n];
    printf("Enter array of %dx%d elements:\n", m, n);
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    int k = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] == 0)
                k++;
    double sparsity = k * 1.0 / (m * n);
    if (sparsity > s)
        printf("It is a sparse matrix\n");
    else
        printf("It is not a sparse matrix.\n");
}
