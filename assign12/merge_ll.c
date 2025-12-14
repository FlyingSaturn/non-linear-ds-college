#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

node* create_ll_node(int d);
void free_ll(node* head);
node* insert_end(node* head, int d);
node* insert_special(node* head, node* ptr);
node* merge(node* head1, node* head2);
void display(node* head);

int main(void)
{
    node *ll1 = NULL;
    node *ll2 = NULL;
    node *merged_list = NULL;

    printf("Creating List 1...\n");
    ll1 = insert_end(ll1, 10);
    ll1 = insert_end(ll1, 30);
    ll1 = insert_end(ll1, 50);
    display(ll1);

    printf("Creating List 2...\n");
    ll2 = insert_end(ll2, 20);
    ll2 = insert_end(ll2, 40);
    ll2 = insert_end(ll2, 60);
    display(ll2);

    printf("Merging...\n");
    merged_list = merge(ll1, ll2);

    printf("Final Merged List: ");
    display(merged_list);

    free_ll(ll1);
    free_ll(ll2);
    free_ll(merged_list);

    return 0;
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

node* insert_special(node* head, node* ptr)
{
    if (ptr == NULL)
        ptr = create_ll_node(head->data);
    else
    {
        ptr->next = create_ll_node(head->data);
        ptr = ptr->next;
    }
    return ptr;
}

node* merge(node* head1, node* head2)
{
    node* copy = NULL;
    node* ptr = NULL;
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data >= head2->data)
        {
            ptr = insert_special(head2, ptr);
            head2 = head2->next;
        }
        else if (head1->data <= head2->data)
        {
            ptr = insert_special(head1, ptr);
            head1 = head1->next;
        }
        if (copy == NULL)
            copy = ptr;
    }
    while (head1 != NULL)
    {
        ptr = insert_special(head1, ptr);
        if (copy == NULL)
            copy = ptr;
        head1 = head1 -> next;
    }
    while (head2 != NULL)
    {
        ptr = insert_special(head2, ptr);
        if (copy == NULL)
            copy = ptr;
        head2 = head2 -> next;
    }
    return copy;
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

