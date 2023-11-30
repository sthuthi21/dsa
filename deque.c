/*implement a double ended queue using linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *front=NULL;
struct node *rear=NULL;
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

void enqueueFront()
{
	struct node *new=create_node();
	if(front==NULL)
	{
		front=new;
		rear=new;
	}
	else
	{
		front->prev=new;
		new->next=front;
		front=new;
	}
}

void enqueueRear()
{
	struct node *new=create_node();
	if(front==NULL)
	{
		front=new;
		rear=new;
	}
	else
	{
		rear->next=new;
		new->prev=rear;
		rear=new;
	}
}

void dequeueFront()
{
	if(front==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		struct node *ptr;
		ptr=front;
		printf("THE DELETED ELEMENT IS %d\n",ptr->data);
		if(front->next!=NULL)
		{
			front=front->next;
			front->prev=NULL;
		}
		else
		{
			front=NULL;
			rear=NULL;
		}
		free(ptr);
	}
}

void dequeueRear()
{
	if(rear==NULL)
	{
		printf("queue is empty\n");
	}
	else
	{
		struct node *ptr;
		ptr=rear;
		printf("THE DELETED ELEMENT IS %d\n",ptr->data);
		if(rear->prev!=NULL)
		{
			rear=rear->prev;
			rear->next=NULL;
		}
		else
		{
			front=NULL;
			rear=NULL;
		}
		free(ptr);
	}
}

void display()
{
	struct node *ptr;
	printf("DEQUE:\n");
	if(front==NULL)
	{
		printf("no deque exists\n");
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
	int op;
	printf("MENU:\n");
	printf("1.ENQUEUE FRONT\n2.ENQUEUE REAR\n3.DEQUEUE FRONT\n4.DEQUEUE REAR\n5.DISPLAY\n");
	do
	{
		printf("Enter your choice:\n");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				enqueueFront();
				break;
			case 2:
				enqueueRear();
				break;
			case 3:
				dequeueFront();
				break;
			case 4:
				dequeueRear();
				break;
			case 5:
				display();
				break;
			default:
				printf("EXITING THE PROGRAM\n");
			
		}
	}while(op<6);
	
}
