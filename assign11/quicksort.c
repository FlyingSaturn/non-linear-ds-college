#include <stdio.h>
#include <stdlib.h>

void quicksort(int* A, int low, int high);
int partition (int A[], int low, int high);

int main(void)
{
        int n;
        printf("n: ");
        scanf("%d", &n);
        int* A = malloc(sizeof(int) * n);
        printf("Enter the %d numbers: ", n);
        for (int i = 0; i < n; i++)
                scanf("%d", &A[i]);
        quicksort(A, 0, n - 1);
        printf("\nSorted array: ");
        for (int i = 0; i < n; i++)
        {
                if (i != 0)
                        printf(", ");
                printf("%d", A[i]);
        }
        printf("\n");
        free(A);
}

void quicksort(int* A, int low, int high)
{
        printf("low = %d, high = %d\n", low, high);
        if (low >= high)
                return;
        int pi = partition(A, low, high);
        quicksort(A, low, pi - 1);
        quicksort(A, pi + 1, high);
}

int partition (int A[], int low, int high)
{
        int pivot = A[high];
        int i = low - 1;
        for (int j = low; j < high; j++)
        {
                if (A[j] <= pivot)
                {
                        i++;
                        int t = A[j];
                        A[j] = A[i];
                        A[i] = t;
                }
        }
        int t = A[i + 1];
        A[i + 1] = A[high];
        A[high] = t;
        return i + 1;
}
