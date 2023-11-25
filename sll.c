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
void delete_begin()
{
    struct node *ptr=head;
    head=ptr->next;
    printf("deleted item is head ,%d",ptr->data);
    free(ptr);
    return;
}
void delete_item(int item)
{
    struct node *ptr=head;
    struct node *temp;
    if(ptr->data==item)
    {
        delete_begin();
    }
    else if(head==NULL)
        printf("linked list is empty.\n");
    else
    {
        while(ptr!=NULL)
        {
            if(ptr->data!=item)
            {
                temp=ptr;
                ptr=ptr->next;
            }
            else
            {
                temp->next=ptr->next;
                printf("deleted element is %d",ptr->data);
                free(ptr);
                return;
            }
        }
        if(ptr==NULL)
        {
            printf("item doesnt exist");
        }
    }
}

void delete_position(int pos)
{
    struct node *current;
	struct node *prev;
    int count;
    if(head==NULL)
        printf("linked list is empty\n");
    else
    {
        if (pos==1)
        {
            delete_begin();
        }
        else
        {
            current=head;
            prev=NULL;
            count=1;
            while(current!=NULL && count<pos)
            {
                prev=current;
                current=current->next;
                count=count+1;
            }
            if(current==NULL)
            {
                printf("position %d exceeds length of the list %d",pos,count);
            }
            else
            {
                prev->next=current->next;
                printf("the deleted element is %d at position %d or %d\n",current->data,pos,count);
                free(current);
            }
        }

    }
    
}

void delete_smallest()
{
	struct node *ptr;
    if(head==NULL)
        printf("linked list is empty\n");
    else
    {
        int smallest=head->data;
        ptr=head;
        while(ptr!=NULL)
        {
            if(ptr->data<smallest)
                smallest=ptr->data;
            ptr=ptr->next;
        }
        delete_item(smallest);

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
	printf("1.insertion at begin\n2.insert at end\n3.display\n4.insert after data\n5.insert before data\n6.insert at position\n7.delete data\n8.delete position\n9.delete smallest element\n");
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
            case 7:
                printf("enter the item you want to delete:");
                scanf("%d",&item);
                delete_item(item);
                break;
            case 8:
                printf("enter the position you want to delete:");
                scanf("%d",&position);
                delete_position(position);
                break;
            case 9:
                delete_smallest();
                break;	
        }
	}while(op<10);
}
