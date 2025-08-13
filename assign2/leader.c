#include <stdio.h>

int main(void)
{
char n[MAX];
printf("Enter a number: ");
scanf("%s", n);
char d;
printf("Digit to remove: ");
scanf("%c", &d);
for (int i = 0; i < n; i++)
if (n[i] == d)
