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
    // else if(top1==-1)
    // {
    //     stack[++top1]=item;
    //     auxstack[++top2]=item;
    // }
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

int pop()
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

void display(int stack1[],int top)
{
    if(top>=0)
    {
        printf("\nSTACK\n");
        for(int i=top;i>=0;i--)
        {
            printf("%d\t",stack1[i]);
        }
    }
    else
    {
        printf("stack is empty");
    }
}
void getmin()
{
    int minEle=auxstack[top2];
    printf("\nmin element :%d\n",minEle) ;
}


void main()
{
    push(6);
    display(stack,top1);
    display(auxstack,top2);
    getmin();
    push(4);
    display(stack,top1);
    display(auxstack,top2);
    getmin();
    push(2);
    display(stack,top1);
    display(auxstack,top2);
    getmin();
    push(10);
    display(stack,top1);
    display(auxstack,top2);
    getmin();
    pop();
    display(stack,top1);
    display(auxstack,top2);
    getmin();
    pop();
    display(stack,top1);
    display(auxstack,top2);
    getmin();
    push(1);
    display(stack,top1);
    display(auxstack,top2);
    getmin();
    push(5);
    display(stack,top1);
    display(auxstack,top2);
    getmin();
}

