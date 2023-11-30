#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

struct node *top=NULL;
struct node *front=NULL;

void push(struct node *node)
{
	node->next=top;
	top=node;
}

void displayStack()
{
	struct node *ptr;
	printf("REVERSED QUEUE:\n");
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

void enqueue(int item)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->data=item;
	new->next=NULL;
	if(front==NULL)
	{
		
		front=new;
	}
	else
	{
		struct node *temp=front;
		while(temp->next!=NULL)
			temp=temp->next;
		temp->next=new;
	}
}

/*void dequeue()
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
			front==NULL;
			rear==NULL;
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
}*/
void displayQueue()
{
	struct node *ptr;
	printf("QUEUE:\n");
	if(front==NULL)
	{
		printf("no queue exists\n");
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
void reverseQueue()
{
 	struct node *temp;
 	while(front!=NULL)
 	{
 		temp=front;
 		front=front->next;
 		push(temp);
 	}
}

void main()
{
	int op, item;
	printf("MENU");
	printf("\n1.ENQUEUE\n2.DISPLAY QUEUE\n3.DISPLAY REVERSED QUEUE");
	do{
		printf("\nenter your option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("enter item:");
				scanf("%d",&item);
				enqueue(item);
				break;
			case 2:
				displayQueue();
				break;
			case 3:
				reverseQueue();
				displayStack();
				break;
			default:
				printf("EXITING THE PROGRAM...");
		}
	}while(op<5);

}






