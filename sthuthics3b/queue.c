/*program to implement queue using arrays*/
#include<stdio.h>
#define MAX_SIZE 5
int front=-1;
int rear=-1;
int queue[MAX_SIZE];
void enqueue(int item)
{
	if(rear==MAX_SIZE-1)
	{
		printf("Queue is full\n");
	}
	else
	{
		if(front==-1 && rear==-1)
		{
			front=0;
			queue[++rear]=item;
		}
		else
		{
			queue[++rear]=item;
		}
	}
}

void dequeue()
{
	int item;
	if(front==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		item=queue[front];
		if(front==rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=front+1;
		}
		printf("deleted item is %d\n",item);
	}
	
}

void display()
{
	if(front==-1)
	{
		printf("queue is empty");
	}
	else
	{
		printf("the queue is :\n");
		for(int i=front;i<=rear;i++)
		{
			printf("%d\t",queue[i]);
		}
	}
}

void main()
{
	int op;
	do{
		printf("which operation do u want to perform in your QUEUE?\n");
		printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n");
		scanf("%d" ,&op);
		int ele;
		switch(op)
		{
			case 1:
			printf("enter item:");
			scanf("%d",&ele);
			enqueue(ele);
			break;
			case 2:
			dequeue();
			break;
			case 3:
			display();
			break;
			default:
			printf("not a valid operation . pls select the right operation");
		}
	}while(op<=3);
	
	

}
















