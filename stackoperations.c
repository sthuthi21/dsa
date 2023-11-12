#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top=-1;

void push(int item)
{
    if(top==MAX_SIZE-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        top++;
        stack[top]=item;
    }
}
int pop()
{
    int item;
    if(top<0)
    {
        printf("stack Underflow");
    }
    else
    {
        item=stack[top];
        top--;
    }
    return item;
}
void display()
{
    if(top>=0)
    {
        printf("STACK\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\t",stack[i]);
        }
    }
    else
    {
        printf("stack is empty");
    }
}
void main()
{
    int op,a,b;
    printf("****STACK OPERATIONS****\n");
    do
    {
        printf("*********************\n1");
        printf("what do u want to do?\n1.PUSH\n2.POP\n3.DISPLAY\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("enter the item you want to push:");
                scanf("%d",&a);
                push(a);
                break;
            case 2:
                b=pop();
                printf("deleted element is:%d",b);
                break;
            case 3:
                display();
                break;
            default:
                printf("exiting....");
        }
        
    }while(op<=3);
    
}


