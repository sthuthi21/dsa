/*c program to reverse and sort a singly linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};
struct node *head=NULL;
struct node* create_node()
{
    int value;
    printf("ENTER THE DATA :");
    scanf("%d",&value);

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    return new;
}

//insert
void sortedInsert(){
	int searchFlag = 0;
	if (head == NULL){
		struct node *new = create_node();
    	new -> next = head;
    	head = new;
    }
	else{
		struct node *new = create_node();
		
		struct node *ptr = head;
		struct node *prev = head;
		
		while (ptr != NULL){
			if (ptr -> data > new -> data){
				searchFlag = 1;
				break;
			}
			prev = ptr;
			ptr = ptr -> next;
		}
		if (searchFlag == 1){
            if (ptr == head){
                new -> next = ptr;
                head = new;
            }
			else if (ptr != NULL){
                prev -> next = new;
				new -> next = ptr;
			}
			else{
				prev -> next = new;
			}
		}
        else
            prev -> next = new;	
	}
}

//reverse

void reverse()
{
    struct node *prev=NULL;
    struct node *next=head;
    struct node *ptr=head;
    if(head==NULL)
    {
        printf("list doesnt exist.");
    }
    else
    
    while(next!=NULL)
    {
        next=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=next;
    }
    head=prev;
}

void display()
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
			printf("%d\n" , ptr->data);
			ptr=ptr->next;
		}
	}
}

void main()
{
    int op;
    printf("1. insert element\n2.reverse\n3.display");
    do{
        printf("enter your choice:\n");
        scanf("%d",&op);
        switch(op)
        {
            case 1:
                sortedInsert();
                break;
            case 2:
                reverse();
                break;
            case 3:
                display();
                break;
        }
    }while(op<4);
}
