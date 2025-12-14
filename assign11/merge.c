#include <stdio.h>
#include <stdlib.h>

void mergesort(int A[], int low, int high);
void merge(int A[], int low, int high);

int main(void)
{
        int n;
        printf("n: ");
        scanf("%d", &n);
        int* A = malloc(sizeof(int) * n);
        if (A == NULL)
        {
                printf("Memory allocation failed.\n");
                exit(1);
        }
        printf("Enter the %d numbers: ", n);
        for (int i = 0; i < n; i++)
                scanf("%d", &A[i]);
        mergesort(A, 0, n - 1);
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

void mergesort(int A[], int low, int high)
{
        if (low >= high)
                return;
        int mid = (low + high) / 2;
        printf("left = %d-%d, right = %d-%d\n", low, mid, mid+1,high);
        mergesort(A, low, mid);
        mergesort(A, mid+1, high);
        merge(A, low, high);
}

void merge(int A[], int low, int high)
{
        int p = (low + high) / 2;
        int* copy = malloc(sizeof(int) * (high - low + 1));
        if (copy == NULL)
        {
                printf("Memory allocation failed.\n");
                exit(1);
        }
        int firstindex = low, secondindex = p + 1, k = 0;
        while (firstindex <= p && secondindex <= high)
        {
                if (A[firstindex] <= A[secondindex])
                {
                        copy[k++] = A[firstindex++];
                }
                else if (A[firstindex] >= A[secondindex])
                {
                        copy[k++] = A[secondindex++];
                }
        }
        while (secondindex <= high)
                copy[k++] = A[secondindex++];
        while (firstindex <= p)
                copy[k++] = A[firstindex++];
        for (int i = low, k = 0; i <= high; i++, k++)
                A[i] = copy[k];
        free(copy);
}
