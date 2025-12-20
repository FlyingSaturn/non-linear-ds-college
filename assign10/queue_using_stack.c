#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

void enqueue(int d);
int dequeue();
void push(int d);
int pop();
int peek();
void display();
bool overflow();
bool underflow();

int arr1[MAX], arr2[MAX];
int front = -1, rear = -1;
int top1 = -1, top2 = -1;

int main(void)
{
	int op, d;
	while (true)
	{
		printf("Enter the options:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nChoice: ");
		scanf("%d", &op);
		switch (op)
		{
			case 1:
				printf("Enter the number: ");
				scanf("%d", &d);
				if (!overflow())
				{
					enqueue(d);
					printf("%d enqueued.\n", d);
				}
				else
					printf("Queue overflow.\n");
				break;
			case 2:
				
				if (!underflow())
				{
					d = dequeue();
					printf("Popped value: %d\n", d);
				}
				else
					printf("Queue underflow.\n");
				break;
			case 3:
				if (!underflow())
					printf("Peeked value: %d\n", peek());
				else
					printf("Queue is empty.\n");
				break;
			case 4:
				printf("Terminating...\n");
				exit(0);
			default:
				printf("Please try again.\n");
		}
	}
}


void enqueue(int d)
{
	arr1[++top1] = d;
}

int dequeue()
{
	int d;
	if (top2 == -1)
	{
		while (top1 > -1)
			arr2[++top2] = arr1[top1--];
		d = arr2[top2--];
	}
	return d;
}

int peek()
{	
	while (top1 > -1)
		arr2[++top2] = arr1[top1--];
	return arr2[top2];
}

bool overflow()
{
	if (top2 == MAX - 1)
		return true;
	return false;
}

bool underflow()
{
	if (top2 == -1 && top1 == -1)
		return true;
	return false;
}
