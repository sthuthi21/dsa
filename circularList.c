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

void insertFront()
{
	struct node *new=create_node();
	if(head==NULL)
	{
		head=new;
		head->next=new;
		head->prev=new;
	}
	else
	{
		new->next=head;
		new->prev=head->prev;
		head->prev->next=new;
		head=new;          
	}
}
void insertLast()
{
	struct node *new=create_node();
	if(head==NULL)
	{
		head=new;
		head->next=new;
		head->prev=new;
	}
	else
	{
		new->prev=head->prev;
		head->prev->next=new;
		new->next=head;
		head->prev=new;
	}

}

void deleteFirst()
{
	if(head==NULL)
	{
		printf("No list exists.\n");
		return;
	}
	else
	{
		struct node *ptr=head;
		if(ptr->next==head)
		{
			head=NULL;
		}
		else
		{
			head->next->prev=head->prev;
			head->prev->next=head->next;
			head=head->next;
		}
		printf("the deleted element:%d",ptr->data);
		free(ptr);
	}
	
	
}

void deleteLast()
{
	if(head==NULL)
	{
		printf("no linked list exists:\n");
		return;
	}
	else
	{
		struct node *ptr=head->prev;
		if(head->prev==head)
		{
			head=NULL;
		}
		else
		{
			head->prev=head->prev->prev;
			head->prev->next=head;
		}
		printf("the deleted element:%d",ptr->data);
		free(ptr);
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
    
    int op,item,position;
    printf("MENU");
	printf("WHAT OPERATIONS DO  YOU WANT TO DO?\n");
	printf("1.insertion at begin\n2.insert at end\n3.delete from front\n4.delete from end\n5.display");
    printf("press any other number to exit\n");
	do{
		printf("enter your option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				insertFront();
				break;
			case 2:
				insertLast();
				break;
			case 3:
				deleteFirst();
				break;
			case 4:
				deleteLast();
				break;
			case 5:
                display();
                break;
		}
	}while(op<6);
}
