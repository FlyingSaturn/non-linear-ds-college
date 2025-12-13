#include <stdio.h>
#include <math.h>
#include <limits.h>

int main()
{
	int h;
	printf("Height: ");
	scanf("%d", &h);
	int n = pow(2, h + 1) - 1;
	int tree[n];
	printf("Enter the binary tree: \n");
	for (int i = 0; i < n; i++)
	{
		int op;
		printf("NULL or possesses value(enter 0, then enter the value)?");
		scanf("%d", &op);
		if (op == 0)
			scanf("%d", &tree[i]);
		else
			tree[i] = INT_MAX;
	}
	for (int i = 0; i < n; i++)
	{
		int l = 2 * i + 1;
		int r = 2 * i + 2;
		if (l < n && r < n)
		{
			if(tree[l] != INT_MAX && tree[r] == INT_MAX || tree[l] == INT_MAX && tree[r] != INT_MAX)
			{
				printf("Not a full binary tree.\n");
				return 0;
			}	
		}
	}
	printf("It is a full binary tree.\n");
}
