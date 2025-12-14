#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* create_ll_node(int d);
void free_ll(node* head);
node* insert_begin(node* head, int d);
node* insert_end(node* head, int d);
node* insert_pos(node* head, int d, int pos);
node* delete_begin(node* head);
node* delete_end(node* head);
node* delete_pos(node* head, int pos);
int search(node* head, int key);
void update(node* head, int prev, int now);
int count(node* head);
void display(node* head);
node* reverse(node* head);

int main(void)
{
    node* ll = NULL;
    int choice, sub, d, pos, old_d;

    while (1)
    {
        printf("\n=== Linked List Operations ===\n");
        printf("1. Insertion\n2. Deletion\n3. Search\n4. Update\n5. Count\n6. Display\n7. Reverse\n8. Delete entire list (Exit)\nYour choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("  1. Beginning\n  2. End\n  3. Specific Position\n  Choice: ");
                scanf("%d", &sub);
                printf("Enter data: ");
                scanf("%d", &d);
                if (sub == 1) ll = insert_begin(ll, d);
                else if (sub == 2) ll = insert_end(ll, d);
                else if (sub == 3)
                {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    ll = insert_pos(ll, d, pos);
                }
                break;

            case 2:
                if (ll == NULL)
                {
                    printf("List is empty.\n");
                    break;
                }
                printf("  1. Beginning\n  2. End\n  3. Specific Position\n  Choice: ");
                scanf("%d", &sub);
                if (sub == 1) ll = delete_begin(ll);
                else if (sub == 2) ll = delete_end(ll);
                else if (sub == 3)
                {
                    printf("Enter position: ");
                    scanf("%d", &pos);
                    ll = delete_pos(ll, pos);
                }
                break;

            case 3:
                printf("Enter element to search: ");
                scanf("%d", &d);
                pos = search(ll, d);
                if (pos == -1) printf("Element not found.\n");
                else printf("Element found at position %d.\n", pos);
                break;

            case 4:
                printf("Enter existing value: ");
                scanf("%d", &old_d);
                printf("Enter new value: ");
                scanf("%d", &d);
                update(ll, old_d, d);
                break;

            case 5:
                printf("Total nodes: %d\n", count(ll));
                break;

            case 6:
                display(ll);
                break;

            case 7:
                ll = reverse(ll);
                printf("List reversed.\n");
                display(ll);
                break;

            case 8:
                free_ll(ll);
                ll = NULL;
                printf("Memory freed. Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }
}

node* create_ll_node(int d)
{
    node* head = (node*) malloc(sizeof(node));
    if (head == NULL)
    {
        printf("Can't alloc. Exitting...\n");
        exit(1);
    }
    head->data = d;
    head->next = NULL;
    return head;
}

// ptr takes over, head moves to next, ptr frees the current
void free_ll(node* head)
{
    while (head != NULL)
    {
        node* ptr = head;
        head = head->next;
        free(ptr);
    }
    head = NULL;
}

node* insert_end(node* head, int d)
{
        node* ptr = create_ll_node(d);
        if (head == NULL) return ptr;
        node* tmp = head;
	while (tmp -> next != NULL)
		tmp = tmp -> next;
	tmp->next = ptr;
	return head;
}

node* insert_begin(node* head, int d)
{
    // Making the node
    node* ptr = create_ll_node(d);
    // Prepend logic
    ptr->next = head;
    head = ptr;
    return head;
}

node* insert_pos(node* head, int d, int pos)
{
	if (pos < 1)
	{
		printf("Invalid position.\n");
		return head;
	}
        if (pos == 1) insert_begin(head,d);
        node* temp = head;
        for (int i = 2; i < pos && temp != NULL; i++)
                temp = temp -> next; // goes to the second node at first
        if (temp == NULL)
        {
                printf("Position out of bounds.\n");
                return head;
        }
        node* ptr = create_ll_node(d);
        ptr -> next = temp -> next;
        temp -> next = ptr;
        return head;
}


node* delete_begin(node* head)
{
        if (head == NULL)
                return head;
        node* tmp = head;
        head = head -> next;
        free(tmp);
        return head;
}

node* delete_end(node* head)
{
        node* preptr = NULL;
        node* ptr = head;
        if (head == NULL) return NULL;
        if (head->next == NULL)
                return delete_begin(head);
        while (ptr->next != NULL)
        {
                preptr = ptr;
                ptr = ptr -> next;
        }
        free(ptr);
        if (preptr != NULL)
                preptr->next = NULL;
        return head;
}

node* delete_pos(node* head, int pos)
{
        if (head == NULL) return NULL;
        if (pos < 1)
        {
                printf("Invalid position.\n");
                return head;
        }
        if (pos == 1)
                return delete_begin(head);
        node* preptr = NULL;
        node* ptr = head;
        for (int i = 1; i < pos && ptr != NULL; i++)
        {
                preptr = ptr;
                ptr = ptr->next;
        }
        if (ptr == NULL)
        {
                printf("Position out of bounds.\n");
                return head;
        }
        preptr->next = ptr->next;
        free(ptr);
        return head;
}

int search(node* head, int abc)
{
        int i = 1;
        node* ptr = head;
        if (head == NULL)
                return -1;
        while (ptr != NULL)
        {
                if (ptr -> data == abc)
                        return i;
                i++;
                ptr = ptr -> next;
        }
        return -1;
}

void display(node* head)
{
    if (head == NULL)
    {
        printf("None.\n");
        printf("Please create the list before traversing.\n");
        return;
    }
    node* ptr = head;
    while (ptr != NULL)
    {
        if (ptr != head)
            printf(", ");
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void update(node* head, int prev, int now)
{
        node* ptr = head;
        if (head == NULL)
        {
                printf("Linked list is empty.\n");
                return;
        }
        while (ptr != NULL)
        {
                if (ptr -> data == prev)
                {
                        ptr -> data = now;
                        printf("Updated %d to %d.\n", prev, now);
                        return;
                }
                ptr = ptr -> next;
        }
        printf("No element found.\n");
        return;
}

int count(node* head)
{
        int i = 0;
        node* ptr = head;
        if (head == NULL)
                return 0;
        while (ptr != NULL)
        {
                i++;
                ptr = ptr -> next;
        }
        return i;
}


node* reverse (node* head)
{
        if (head == NULL || head -> next == NULL)
                return head;

        node* prev = NULL;
        node* current = head;
        node* next = NULL;

        while (current != NULL)
        {
                next = current->next;
                current->next = prev;

                prev = current;
                current = next;
        }
        return prev;
}
