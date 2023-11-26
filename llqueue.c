#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *front=NULL;
struct node *rear=NULL;

void enqueue(int item)
{
	if(front==NULL)
	{
		struct node *new = (struct node*)malloc(sizeof(struct node));
		new->data=item;
		new->next=NULL;
		front=rear=new;
	}
	else
	{
		struct node *new = (struct node*)malloc(sizeof(struct node));
		new->data=item;
		new->next=NULL;
		rear->next=new;
		rear=new;
	}
}

void dequeue()
{
	if(front==NULL)
	{
		printf("queue is empty");	
	}
	else
	{
		int item=front->data;
		if(front->next==NULL)
		{
			front=NULL;
			rear=NULL;
			printf("deleted element: %d", item);
		}
		else
		{
			struct node *ptr;
			ptr=front;
			front=front->next;
			printf("deleted element:%d",ptr->data);
			free(ptr);
		}
	}
}
void display()
{
	struct node *ptr;
	printf("QUEUE:\n");
	if(front==NULL)
	{
		printf("no STACK exists\n");
	}
	else
	{
		ptr=front;
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
	printf("\n1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
	do{
		printf("\nenter your option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter the item you want to enqueue:");
				scanf("%d",&item);
				enqueue(item);
				break;
			case 2:
				dequeue();
				break;
			case 3:
				display();
				break;
		}
	}while(op<4);
}
