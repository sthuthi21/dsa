/*program to implement circular queue*/
#include<stdio.h>
#define MAXSIZE 5

int cqueue[MAXSIZE];
int rear=-1;
int front=-1;

void enCQ(int item)
{
	if(front==-1)
	{
		front=0;
		rear=0;
		cqueue[rear]=item;
	}
	else
	{
		if((rear+1)%MAXSIZE != front)
		{
			rear=(rear+1)%MAXSIZE;
			cqueue[rear]=item;
		}
		else
			printf("queue is full\n");
	}
}

void deCQ()
{
	int item;
	if(front==-1)
	{
		printf("queue is empty\n");
	}
	else
	{
		item=cqueue[front];
		if(front == rear)
		{
			front=-1;
			rear=-1;
		}
		else
		{
			front=(front+1)%MAXSIZE;
		}
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
		if(front==0 && rear==0)
		{
			printf("%d\t",cqueue[front]);
		}
		else
		{
			for(int i=front;i!=rear;i=(i+1)%MAXSIZE)
			{
				printf("%d\t",cqueue[i]);
			}
			printf("%d\t",cqueue[rear]);
		}
		
	}
}

void main()
{
	int op;
	do{
		printf("which operation do u want to perform in your QUEUE?\n");
		printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\nPRESS ANY OTHER NUMBER TO EXIT\n");
		scanf("%d" ,&op);
		int ele;
		switch(op)
		{
			case 1:
			printf("enter item:");
			scanf("%d",&ele);
			enCQ(ele);
			break;
			case 2:
			deCQ();
			break;
			case 3:
			display();
			break;
			default:
			printf("exiting the program.....");
		}
	}while(op<=3);
	
}
	


