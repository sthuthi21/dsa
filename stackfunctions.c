#include<stdio.h>
#define MAX_SIZE 10

int stack[MAX_SIZE];
int top=-1;

void push(int stack[],int item)
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
int pop(int stack[])
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
void display(int stack[])
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