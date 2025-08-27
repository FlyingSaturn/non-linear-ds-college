#include <stdio.h>
#include <string.h>

int main(void)
{
    long a;
    const int MAX = 200;
    char n[MAX];
    printf("Enter a number: ");
    scanf("%ld", &a);
    sprintf(n, "%ld", a);
    char d;
    printf("Digit to remove: ");
    scanf(" %c", &d);
    int index = -1, l = strlen(n);
    for (int i = 0; i < l; i++)
    {
        if (n[i] == d)
        {
            index = i;
            // C compiler short-circuits it to false
            // if it sees a "false and ..."
            if (i < l - 1 && n[i] < n[i + 1])
                break;
        }
    }
    for (int i = index; i < l && i >= 0; i++)
        n[i] = n[i + 1]; // '\0' also shifts to the left
    printf("Result: %s\n", n);
}
