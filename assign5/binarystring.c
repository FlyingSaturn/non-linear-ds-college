#include <stdio.h>
#include <strings.h>

int binarysearch(int high, int low, char arr[][100], char* target);

int main(void)
{
	int n;
	printf("n: ");
	scanf("%d", &n);
	printf("Enter the words one by one: ");
	char arr[n][100];
	for (int i = 0; i < n; i++)
		scanf("%99s", arr[i]);
	char target[100];
        printf("Target: ");
        scanf("%99s", target);
	int index = binarysearch(n - 1, 0, arr, target);
	if (index == -1)
	{
		printf("Index not found.\n");
		return 0;
	}
	printf("Index: %d\n", index);
}



int binarysearch(int high, int low, char arr[][100], char* target)
{
	if (low > high)
		return -1;
	int p = (high + low) / 2;
	if (strcasecmp(target, arr[p]) == 0)
	        return p;
	if (strcasecmp(target, arr[p]) < 0)
	        return binarysearch(p - 1, low, arr, target);
	if (strcasecmp(target, arr[p]) > 0)
	        return binarysearch(high, p + 1, arr, target);	
}
