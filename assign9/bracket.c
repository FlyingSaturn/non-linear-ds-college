#include <stdio.h>
#include <string.h>

#define MAX 10

int main(void)
{
	char abc[MAX], stack[MAX];
	int top = -1, is_palindrome = 0;
	printf("Enter a string: ");
	if (fgets(abc, sizeof(abc), stdin) == NULL)
	{
		printf("Error reading input.\n");
		return 0;
	}
	if (abc[strlen(abc) - 1] == '\n')
		abc[strlen(abc) - 1] = '\0';
	int len = strlen(abc);

	for (int i = 0; i < len; i++)
	{
		if (top >= MAX - 1)
		{
			printf("Stack Overflow\n");
			return 1;
		}
		stack[++top] = abc[i];
	}
	for (int i = 0; i < len; i++)
	{
		char popped = stack[top--];
		if (popped != abc[i])
		{
			printf("Not a palindrome.\n");
			return 0;
		}
	}

	printf("Is a palindrome.\n");
}

