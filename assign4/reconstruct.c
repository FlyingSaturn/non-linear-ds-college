#include <stdio.h>
int main(void)
{
	int n;
	printf("No. of elements in sparse matrix: ");
	scanf("%d", &n);
	int a[n + 1][3];
	printf("Enter array of (%d + 1) x %d elements:\n", n, 3);
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	int k = 1;
	int b[a[0][0]][a[0][1]];
	for (int i = 0; i < a[0][0]; i++)
	{
		for (int j = 0; j < a[0][1]; j++)
		{
			if (i == a[k][0] && j == a[k][1])
			{b[i][j] = a[k][2]; k++;}
			else
				b[i][j] = 0;
		}
	}
	printf("Final matrix:\n");

	for (int i = 0; i < a[0][0]; i++)
	{
		for (int j = 0; j < a[0][1]; j++)
		{
			printf("%d ", b[i][j]);
		}
		printf("\n");
	}
}

