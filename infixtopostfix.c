/* c program to implement conversion of infix expression to postfix*/
#include<stdio.h>
#include<stdbool.h>
char infix[50];
char stack[50];
int top=-1;

void push(char ele)
{
    stack[++top]=ele;
}
char pop()
{
    return stack[top--];
}
bool isOperator(char op)
{
    if(op=='+'|| op=='-'|| op=='*'|| op=='/'|| op=='^'|| op=='(')
        return true;
    else
        return false;
}

int precedence(char op)
{
    if(op=='+'||op=='-')
        return 1;
    else if(op=='*'||op=='/')
        return 2;
    else if(op=='^')
        return 3;
    else if(op=='(')
        return 0;
}

void postfixConversion()
{
    char ele;
    int i=0;
    while(infix[i]!='\0')
    {
        if(isOperator(infix[i]))
        {
            if(infix[i]=='(')
                push(infix[i]);
            else if(precedence(infix[i])>precedence(stack[top]))
                push(infix[i]);
            else 
            {
                while(precedence(stack[top])>=precedence(infix[i]))
                {
                    ele=pop();
                    printf("%c",ele);
                }
                push(infix[i]);
            }
        }
        else if (infix[i]==')')
        {
            while(stack[top]!='(')
            {
                ele=pop();
                printf("%c",ele);
            }
            pop();
        }
        else
        {
            printf("%c", infix[i]);
        }
        i++;
    }
    while(top!=-1)
    {
        printf("%c",pop());
    }
}

void main()
{
    printf("Enter your INFIX expression:\n");
    scanf("%[^\n]",infix);
    printf("POSTFIX expression:\n");
    postfixConversion();
}


