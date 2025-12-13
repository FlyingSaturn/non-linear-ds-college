#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
	int data;
	struct node* left;
	struct node* right;
} node;

node* head = NULL;

node* insertion(int d);
void preorder(node* root);
void inorder(node* root);
void postorder(node* root);
void free_tree(node* root);

int main(void)
{
	int array[] = {50, 30, 60, 40, 10, 80, 70, 90, 20};

	for (int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
	{
		head = insertion(array[i]);
	}
	printf("The preorder of the tree is: \n");
	preorder(head);
	printf("The inorder of the tree is: \n");
	inorder(head);
	printf("The postorder of the tree is: \n");
	postorder(head);
	free_tree(head);
	return 0;
}

node* insertion(int d)
{
	node* newnode = malloc(sizeof(node));
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->data = d;
	node* p = head;
	if (p == NULL)
		return newnode;
	while (true)
	{
		if (p -> left != NULL && d < p->data)
			p = p -> left;
		else if (p -> right != NULL && d > p->data)
			p = p -> right;
		else
			break;
	}
	if (d < p->data)
		p->left = newnode;
	else if (d > p->data)
		p->right = newnode;
	return head;
}

void preorder(node* root)
{	
	if (root == NULL)
		return;
	printf("%d\n", root->data);
	preorder(root->left);
	preorder(root->right);
}

void inorder(node* root)
{	
	if (root == NULL)
		return;
	inorder(root->left);
	printf("%d\n", root->data);
	inorder(root->right);
}

void postorder(node* root)
{	
	if (root == NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	printf("%d\n", root->data);
}
void free_tree(node* root)
{
	if (root == NULL)
		return;
	free_tree(root->left);
	free_tree(root->right);
	free(root);
}

