#include <stdio.h>
#include <stdlib.h>

#define MAX 10

void push(int data);
int pop();
int peek();
void display();
int underflow();

int n[MAX];
int top = -1;

int main()
{
	int op, d;
	while (1)
	{
		printf("Enter an option: \n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nChoice: ");
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				printf("Enter value to push: ");
				scanf("%d", &d);
				push(d);	
				break;
			case 2:
				if (underflow())
					printf("Stack underflow.\n");
				else
					pop();
				break;
			case 3:
				if (!underflow())
					printf("Top Element: %d\n", peek());
				else
					printf("Stack underflow.\n");
				break;
			case 4:
				if (underflow())
					printf("Nothing.\n");
				else
					display();
				break;
			case 5:
				printf("Exitting...\n");
				exit(0);
			default:
				printf("Invalid case.\n");
		}
	}
}


void push(int data)
{
	if (top == MAX - 1)
	{
		printf("Stack overflow.\n");
		return;
	}
	n[++top] = data;
	printf("Pushed %d.\n", data);
}

int underflow()
{
	if (top == -1)
		return 1;
	return 0;
}

int pop()
{
	int d = n[top--];
	printf("Popped %d.\n", d);
	return d;
}

int peek()
{
	return n[top];
}

void display()
{
	printf("The values are: \n");
	for (int i = top; i >= 0; i--)
		printf("%d\n", n[i]);
}
