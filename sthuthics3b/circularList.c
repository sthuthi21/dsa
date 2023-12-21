/*implementation of circular list*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;

struct node* create_node()
{
    int value;
    printf("ENTER THE DATA :");
    scanf("%d",&value);

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

void insertList()
{
	struct node *new=create_node();
	if(new==NULL)
	{
		printf("memory insufficient\n");
	}
	else
	{
		if(head==NULL)
		{
			head=new;
			head->next=new;
			head->prev=new;
		}
		else
		{
			struct node *ptr=head;
			while(ptr->next!=head)
				ptr=ptr->next;
			new->next=head;
			ptr->next=new;           
		}
	}
}

void display()
{
	struct node *ptr;
	printf("CIRCULAR LIST:\n");
	if(head==NULL)
	{
		printf("no list exists\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!= head)
		{
			printf("%d\n" , ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n" , ptr->data);
	}
}

void main()
{
	insertList();
	insertList();
	insertList();
	insertList();
	display();
}
