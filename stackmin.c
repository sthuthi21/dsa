/*Program to find the minimum element in the stack in O(1) time using an auxilliary which keep track of minimum element*/
#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int auxstack[MAX_SIZE];
int top1=-1;
int top2=-1;
void push(int item)
{
    int temp;
    if(top1==MAX_SIZE-1)
    {
        printf("Stack Overflow");
    }
    else
    {
        if (top1==-1||item<=auxstack[top2])
        {
            stack[++top1]=item;
            auxstack[++top2]=item;
        }
        else
        {
            stack[++top1]=item;
        }
    }
}

void pop()
{
    int item;
    if(top1<0)
    {
        printf("stack Underflow");
    }
    else
    {
        if(stack[top1]==auxstack[top2])
        {
            item=stack[top1--];
            top2--;
        }
        else
        {
            item=stack[top1--];
        }
        
    }
    printf("popped element:%d",item);
}

void display()
{
    if(top1>=0)
    {
        printf("\nSTACK\n");
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
void peek()
{
    int topEle=stack[top1];
    printf("Element at top is:%d",topEle);
}
void getmin()
{
    int minEle=auxstack[top2];
    printf("\nmin element :%d\n",minEle) ;
}

void main()
{
    int op,flag=0,a,b;
    printf("****STACK OPERATIONS****\n");
    printf("what do u want to do?\n1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.MINIMUM ELEMENT\nPress any other number to exit.");
    do
    {
        printf("\n*********************\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                printf("enter the item you want to push:");
                scanf("%d",&a);
                push(a);
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                peek();
                break;
            case 5:
                getmin();
                break;
            default:
                printf("exiting...");
        }
    
    }while(op<=5);

}

