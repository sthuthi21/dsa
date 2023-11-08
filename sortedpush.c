/*implementing sorted push in stack so that the stack is always sorted.*/
#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int auxstack[MAX_SIZE];
int top1=-1;
int top2=-1;

void push(int item)
{
    if(top1==MAX_SIZE-1)
    {
        printf("Stack Overflow");

    }
    else
    {
        if(top1==-1)
        {
            stack[++top1]=item;
        }
        else
        {
            while(item>stack[top1]&&top1!=-1)
            {
                auxstack[++top2]=stack[top1--];
            }
            stack[++top1]=item;
            while(top2!=0)
            {
                stack[++top1]=auxstack[top2--];
            }
        }
    }
}
int pop()
{
    int item;
    if(top1<0)
    {
        printf("stack Underflow");
    }
    else
    {
        item=stack[top1];
        top1--;
    }
    return item;
}
void display()
{
    if(top1>=0)
    {
        printf("STACK\n");
        for(int i=top1;i>=0;i--)
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
    int op,flag=0,a,b;
    printf("****STACK OPERATIONS****\n");
    while(flag==0)
    {
        printf("*********************\n");
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
                printf("select valid option");
        }
        printf("\npress 1 to exit.\npress 0 to do another operation.");
        scanf("%d",&flag);
    }
    
}

