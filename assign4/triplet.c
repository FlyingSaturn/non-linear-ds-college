#include <stdio.h>
int main(void)
{
	int m, n;
	int k1 = 1;
	int k = 0;
	printf("m: ");
	scanf("%d", &m);
	printf("n: ");
	scanf("%d", &n);
	int a[m][n];
	printf("Enter array of %dx%d elements:\n", m, n);
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%d", &a[i][j]);
			if (a[i][j] != 0)
				k++;
		}
	}
	
	int b[k + 1][3];
	b[0][0] = m;
	b[0][1] = n;
	b[0][2] = k;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
		       if (a[i][j] != 0)
		       {
			b[k1][0] = i;
	 		b[k1][1] = j;
			b[k1][2] = a[i][j];
			k1++;
		       }
		}
	}
	int actual = m * n;
	int sparsed = (k + 1) * 3;
	printf("%d, %d", actual, sparsed);
	float efficiency = ((float)(actual - sparsed) / actual) * 100 ;
	printf("Triplet List Representation:\n");
	for (int i = 0; i < k + 1; i++)
		printf("%d %d %d\n", b[i][0], b[i][1], b[i][2]);
	printf("Storage efficiency: %.2f%\n", efficiency);
}

