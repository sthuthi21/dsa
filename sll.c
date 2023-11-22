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

//INSERTION

void insert_begin()
{
    struct node *new=create_node();
    new->next=head;
    head=new;
}

void insert_end()
{
    struct node *new = create_node();
    struct node *ptr;

    if (new == NULL)
    {
        printf("MEMORY INSUFFICIENT");
    }
    else
    {
        if (head == NULL)
        {
            head = new;
        }
        else
        {
            ptr = head;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new;
        }
    }
}

void insert_afterdata(int item)
{
    if(head==NULL)
    {
        insert_begin();

    }
    else{
    struct node *ptr;
    ptr=head;
    while(ptr->next!=NULL && ptr->data!=item)
        ptr=ptr->next;
    if(ptr->next==NULL)
    {
        printf("item not available\n");
        return;
    }
    struct node *new=create_node();
    new->next=ptr->next;
    ptr->next=new;
    }
}

void insert_beforedata(int item)
{
    if(head==NULL)
    {
        printf("no linked list present");
    }
    else{
        if(head->data==item)
        {
            insert_begin();
        }
        else
        {
            struct node *prev=NULL;
            struct node *current=head;
            while(current->next!=NULL && current->data!=item)
            {
                prev=current;
                current=current->next;
            }
            if(current->next==NULL)
            {
                printf("item not available\n");
                return;
            }
            else
            {
                struct node *new=create_node();
                new->next=current;
                prev->next=new;
            }
        }
    }
}
void insert_inposition(int position)
{
	struct node *current;
	struct node *prev;
	if(position==1)
	{
		insert_begin();
	}
	else
	{
		current=head;
		prev=NULL;
		int count=1;
		while(count<position && current!=NULL)
		{
			prev=current;
			current=current->next;
			count=count+1;
		}			
        if(count<position)
			printf("position exceeds the length of the list.\n");
		else
		{
			struct node *new=create_node();
			new->next=current;
			prev->next=new;
		}
	}
	

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
    
    int op,item,position;
    printf("MENU");
	printf("WHAT OPERATIONS DO  YOU WANT TO DO?\n");
	printf("1.insertion at begin\n2.insert at end\n3.display\n4.insert after data\n5.insert before data\n6.insert at position\n");
	do{
		printf("enter your option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				insert_begin();
				break;
			case 2:
				insert_end();
				break;
            case 3:
                display();
                break;
            case 4:
				printf("enter item after which you want to enter:");
				scanf("%d",&item);
				insert_afterdata(item);
				break;
			case 5:
				printf("enter item before which you want to enter:");
				scanf("%d",&item);
				insert_beforedata(item);
				break;
			case 6:
                printf("enter position:");
				scanf("%d",&position);
				insert_inposition(position);
				break;
	// 	// 	case 6:
	// 	// 		printf("enter the element you want to enter:");
	// 	// 		scanf("%d",&data);
	// 	// 		insert_front(head,data);
	// 	// 		break;
				
		}
	}while(op<7);
}