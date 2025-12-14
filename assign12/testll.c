#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
} node;

// --- Prototypes ---
node* create_ll_node(int d);
void free_ll(node* head);
node* insert_end(node* head, int d);
node* merge(node* head1, node* head2);     // Your COPY version
node* mergealt(node* head1, node* head2);  // Your IN-PLACE version
void display(node* head);

int main(void)
{
    node *ll1 = NULL, *ll2 = NULL;

    // 1. Create List 1: 1 -> 3 -> 5
    ll1 = insert_end(ll1, 1);
    ll1 = insert_end(ll1, 3);
    ll1 = insert_end(ll1, 5);
    printf("List 1: "); display(ll1);

    // 2. Create List 2: 2 -> 4 -> 6
    ll2 = insert_end(ll2, 2);
    ll2 = insert_end(ll2, 4);
    ll2 = insert_end(ll2, 6);
    printf("List 2: "); display(ll2);

    // 3. Test the "COPY" Merge (Keeps originals safe)
    printf("\n--- Testing Copy Merge ---\n");
    node* merged_copy = merge(ll1, ll2);
    printf("Merged Copy: "); display(merged_copy);

    printf("Originals are still safe:\n");
    printf("List 1: "); display(ll1);
    printf("List 2: "); display(ll2);

    // 4. Test the "IN-PLACE" Merge (Destroys originals)
    printf("\n--- Testing In-Place Merge ---\n");
    // Note: We use the return value as the new head
    node* merged_inplace = mergealt(ll1, ll2);

    printf("Merged In-Place: "); display(merged_inplace);

    // If you try to print ll1 or ll2 now, they will be empty or broken
    // because they were "consumed" by the zipper.

    // Cleanup
    free_ll(merged_copy);
    free_ll(merged_inplace);

    return 0;
}

// --- Your Functions ---

node* create_ll_node(int d)
{
    node* head = (node*) malloc(sizeof(node));
    if (head == NULL) { exit(1); }
    head->data = d;
    head->next = NULL;
    return head;
}

void free_ll(node* head)
{
    while (head != NULL)
    {
        node* ptr = head;
        head = head->next;
        free(ptr);
    }
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

// Fixed the logic slightly to handle equal numbers
node* mergealt(node* head1, node* head2)
{
    node dummy;
    node* tail = &dummy;

    while (head1 && head2)
    {
        if (head1->data <= head2->data) // Use <= to handle equality
        {
            tail->next = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2 = head2 ->next;
        }
        tail = tail->next;
    }
    tail->next = (head1 ? head1 : head2);
    return dummy.next;
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
        if (head1->data <= head2->data)
        {
            ptr = insert_special(head1, ptr);
            head1 = head1->next;
        }
        else
        {
            ptr = insert_special(head2, ptr);
            head2 = head2->next;
        }
        if (copy == NULL)
            copy = ptr;
    }
    while (head1 != NULL)
    {
        ptr = insert_special(head1, ptr);
        if (copy == NULL) copy = ptr;
        head1 = head1 -> next;
    }
    while (head2 != NULL)
    {
        ptr = insert_special(head2, ptr);
        if (copy == NULL) copy = ptr;
        head2 = head2 -> next;
    }
    return copy;
}

void display(node* head)
{
    if (head == NULL) { printf("None.\n"); return; }
    node* ptr = head;
    while (ptr != NULL)
    {
        if (ptr != head) printf(" -> ");
        printf("%d", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
