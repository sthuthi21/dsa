#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
    char c;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL;
char str[50];

void addToDLL(char ch)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->c=ch;
    new->next=NULL;
    new->prev=NULL;

    if(head==NULL)
    {
        head=new;
        return;
    }
    else
    {
       struct node *temp=head;
       while(temp->next!=NULL)
       {
            temp=temp->next;
       }
       temp->next=new;
       temp->next->prev=temp;
       return;
    }
    
}

int isPalindrome()
{
    struct node *left=head;
    struct node *right=head;
    if(left==NULL)
        return 1;
    else
    {
        while(right->next!=NULL)
            right=right->next;
        while(left!=right)
        {
            if(left->c!=right->c)
                return 0;
            if(left->next=right)
                break;
            left=left->next;
            right=right->prev;
        }
    }
    return 1;
}

void main()
{
    printf("enter your string:");
    scanf("%s",str);

    for(int i=0;i<strlen(str);i++)
    {
        addToDLL(str[i]);
    }

    int check=isPalindrome();
    if(check==0)
    {
        printf("%s is not a palindrome",str);
    }
    else
    {
        printf("%s is a palindrome",str);
    }
}