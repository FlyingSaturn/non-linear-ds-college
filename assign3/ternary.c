#include <stdio.h>

int ternary_search(int a[], int size, int key);

int main()
{
    int n;
    printf("n: ");
    scanf("%d", &n);
    int a[n];
    printf("Ascending array of %d numbers: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    int key;
    printf("Key: ");
    scanf("%d", &key);
    int result = ternary_search(a, n, key);
    if (result != -1)
        printf("Key %d found at index %d\n", key, result);
    else
        printf("Key %d not found.\n", key);
}


int ternary_search(int a[], int size, int key)
{
    int left = 0;
    int right = size - 1;
    while (left <= right)
    {
        int mid1 = left + (right - left) / 3;
        int mid2 = right - (right - left) / 3;

        if (a[mid1] == key)
            return mid1;
        if (a[mid2] == key)
            return mid2;

        if (key < a[mid1])
            right = mid1 - 1;
        else if (key > a[mid2])
            left = mid2 + 1;
        else
        {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1;
}
