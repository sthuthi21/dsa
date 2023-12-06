#include<stdio.h>
#include<stdlib.h>

struct node
{
    int value;
    struct node *next;
};

struct node *h=NULL;
struct node *p=NULL;
struct node *n=NULL;

void insert(struct node **head,int value)
{
    struct node *new=(struct node*)malloc(sizeof(struct node));
    new->value=value;
    new->next=NULL;
    if(*head==NULL)
    {
        *head=new;
    }
    else
    {
        struct node *ptr=*head;
        while(ptr->next!=NULL)
            ptr=ptr->next;
        ptr->next=new;
    }
}

void delete(struct node **head)
{
    struct node *ptr=*head;
    *head=ptr->next;
    free(ptr);
    return;
}

void split(struct node **list,struct node **pos,struct node **neg)
{
    struct node *ptr=*list;
    while(ptr!=NULL)
    {
        if(ptr->value<0)
        {
            insert(neg,ptr->value);
            delete(list);
        }
        else
        {
            insert(pos,ptr->value);
            delete(list);
        }
        ptr=*list;
    }
}


void display(struct node *head)
{
	struct node *ptr;
	printf("LINKEDLIST:\n");
	if(head==NULL)
	{
		printf("no linked list exists\n");
	}
	else
	{
		ptr=head;
		while(ptr!= NULL)
		{
			printf("%d\n" , ptr->value);
			ptr=ptr->next;
		}
	}
}


void main()
{
    insert(&h,23);
    insert(&h,25);
    insert(&h,-56);
    insert(&h,47);
    insert(&h,-47);
    insert(&h,-23);
    insert(&h,27);
    insert(&h,58);
    insert(&h,-46);
    insert(&h,-60);
    display(h);
    split(&h,&p,&n);
    display(p);
    display(n);
    display(h);


}
