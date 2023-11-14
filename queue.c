/*program to implement queue using arrays*/
#include<stdio.h>
#define MAXSIZE 5
int queue[MAXSIZE];
int rear=-1;
int front=-1;

void enqueue(int item)
{
    if(rear==MAXSIZE-1)
    {
        printf("queue is full");
    }
    else
    {
        if(front==-1&&rear==-1)
        {
            front=0;;
            queue[++rear]=item;
        }
        else{
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
    else{
        item=queue[front];
        if(front==rear)
        {
            front=-1;
            rear=-1;
        }
        else{
            front=front+1;
        }
        printf("deleted item is %d\n",item);
    }
}

void display()
{
    if(front==-1)
    {
        printf("queue is empty\n");
    }
    else{
        printf("the queue is:\n"); 
        for(int i=front;i<=rear;i++)
        {
            printf("%d\t",queue[i]);
        }
        printf("\n");        
    }
}

void main()
{
    int op;
    do{
        printf("what do u want to do?\n");
        printf("1.enqueue\n2.dequeue\n3.display\npress any other to exit\n");
        scanf("%d",&op);
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
                printf("exiting....");
        }
    }while(op>=1 && op<=3);
}