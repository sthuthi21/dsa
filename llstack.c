/*Stack implementation using linked list*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL;

void push(int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	if(new==NULL)
		printf("memory is insufficient.\n");
	else if(top==NULL)
	{
		new->data=item;
		new->next=NULL;
		top=new;
	}
	else
	{
		new->data=item;
		new->next=top;
		top=new;
	}
}

void pop()
{
	struct node *temp;
	if(top==NULL)
		printf("LIST IS EMPTY");
	else
	{
		temp=top;
		top=temp->next;
		printf("DELETED ELEMENT IS :%d",temp->data);
		free(temp);
	}
}

void peek()
{
	if(top==NULL)
		printf("LIST IS EMPTY");
	else
		printf("THE ELEMENT AT TOP IS:%d",top->data);
}

void display()
{
	struct node *ptr;
	printf("STACK:\n");
	if(top==NULL)
	{
		printf("no STACK exists\n");
	}
	else
	{
		ptr=top;
		while(ptr!= NULL)
		{
			printf("%d\n" , ptr->data);
			ptr=ptr->next;
		}
	}
}

void main()
{
	int op, item;
	printf("MENU");
	printf("\n1.PUSH\n2.POP\n3.PEEk\n4.DISPLAY\n");
	do{
		printf("\nenter your option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter the item you want to push:");
				scanf("%d",&item);
				push(item);
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
		}
	}while(op<5);
}
