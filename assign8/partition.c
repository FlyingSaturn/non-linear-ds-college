#include <stdio.h>

void swap(int *a, int *b);
int partition(int arr[], int low, int high);
int findMedianUtil(int arr[], int low, int high, int k);

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Input Array: ");
    for(int i=0; i<n; i++) printf("%d ", arr[i]);
    printf("\n");
    int median = findMedianUtil(arr, 0, n - 1, n / 2);
    printf("Median = %d\n", median);
    return 0;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
	int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
	{
        if (arr[j] <= pivot) 
		{
            i++;
			swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

int findMedianUtil(int arr[], int low, int high, int k)
{
    if (low <= high)
	{
        int pos = partition(arr, low, high);
        if (pos == k)
            return arr[pos];
        if (pos > k)
            return findMedianUtil(arr, low, pos - 1, k);
        return findMedianUtil(arr, pos + 1, high, k);
    }
    return -1;
}

