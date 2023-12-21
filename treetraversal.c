//code is incompleteeee

/*tree traversal*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;
struct node* create_node(int value)
{
    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->left=NULL;
    new->right=NULL;
    return new;
}

struct node* insert(struct node *root,int data)
{
	if(root==NULL)
		return create_node(data);
	else
	{
		if(data < root->data)
			root->left= insert(root->left,data);
		else if(data > root->data)
			root->right= insert(root->right,data);
		return root;	
	}
}

struct node* inorder(struct node *root)
{
	if(root==NULL)
		return NULL;
	else
	{
		inorder(root->left);
		printf("%d\t",root->data);
		inorder(root->right);
	}
	
}

struct node* preorder(struct node *root)
{
	if(root==NULL)
		return NULL;
	else
	{
		
		printf("%d\t",root->data);
		preorder(root->left);
		preorder(root->right);
	}
	
}

struct node* postorder(struct node *root)
{
	if(root==NULL)
		return NULL;
	else
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t",root->data);
	}
	
}

int height(struct node *root)
{
	if(root==NULL)
	{
		return 0;
	}
	
}
void main()
{
	root=insert(root,30);
	insert(root,20);
	insert(root,40);
	insert(root,15);
	insert(root,25);
	insert(root,35);
	insert(root,50);
	insert(root,5);
	insert(root,18);
	insert(root,45);
	insert(root,60);
	printf("inorder traversal\n");
	inorder(root);
	printf("\npreorder traversal\n");
	preorder(root);
	printf("\npostorder traversal\n");
	postorder(root);
}
