#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 10

void enqueue(int d);
int dequeue();
int peek();
void display();
bool overflow();
bool underflow();

int arr[MAX];
int front = -1, rear = -1;

int main(void)
{
	int op, d;
	while (true)
	{
		printf("Enter the options:\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Display\n5. Exit\nChoice: ");
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
				if (!underflow())
				{
					printf("Value to be displayed:\n");
					display();
				}
				else
					printf("Queue is empty.\n");
				break;
			case 5:
				printf("Terminating...\n");
				exit(0);
			default:
				printf("Please try again.\n");
		}
	}
}


void enqueue(int d)
{
	if (rear == -1)
		front = 0;
	arr[++rear] = d;
}

int dequeue()
{
	int d = arr[front++];
	if (front == rear)
		front = rear = -1;
	return d;
}

int peek()
{
	return arr[front];
}

void display()
{
	for (int i = front; i <= rear; i++)
		printf("%d\n", arr[i]);
}

bool overflow()
{
	if (rear == MAX - 1)
		return true;
	return false;
}

bool underflow()
{
	if (front == -1)
		return true;
	return false;
}
