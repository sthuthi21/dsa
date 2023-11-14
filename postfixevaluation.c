#include<stdio.h>
#include<math.h>
char postfix[100];
int stack[100];
int top=-1;

void push(int ele)
{
    stack[++top]=ele;
}
int pop()
{
    return stack[top--];
}

int postfixEvaluation(){
    int i=0;
    while(postfix[i]!='\0')
    {
        if(postfix[i]=='+'||postfix[i]=='-'||postfix[i]=='*'||postfix[i]=='/'||postfix[i]=='^')
        {
            char op=postfix[i];
            int y=pop();
            int x=pop();
            int result=0;

            switch(op)
            {
                case '+':
                    result=x+y;
                    break;
                case '-':
                    result=x-y;
                    break;
                case '*':
                    result=x*y;
                    break;
                case '/':
                    result=x/y;
                    break;
                case '^':
                    result=pow(x,y);
                    break;
            }
            push(result);
        }
        else{
            push((int)postfix[i]-48);
        }
        i++;
    }
    return (pop());
}

void main()
{
    printf("enter your postfix expression:\n");
    scanf("%[^\n]",postfix);
    printf("TOTAL:\n");
    printf("%d\n",postfixEvaluation());
}