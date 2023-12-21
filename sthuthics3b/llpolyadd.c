#include<stdio.h>
#include<stdlib.h>

struct node{
	int expo;
	int coeff;
	struct node *next;
};
struct node *p1=NULL;
struct node *p2=NULL;
struct node *result=NULL;

void read(struct node **poly,int coeff,int expo)
{
	struct node *new = (struct node*)malloc(sizeof(struct node));
	new->coeff=coeff;
	new->expo=expo;
	new->next=NULL;
	
	if(*poly==NULL)
	{
		*poly=new;
		return;
	}
	struct node *ptr=*poly;
	while(ptr->next !=NULL)
		ptr=ptr->next;
	ptr->next=new;
}
void add(struct node **poly1,struct node **poly2,struct node **sum)
{
	struct node *ptr1=*poly1;
	struct node *ptr2=*poly2;
	struct node *ptrR=*sum;
	while(ptr1!=NULL && ptr2!=NULL)
	{
		if(ptr1->expo==ptr2->expo)
		{
			ptrR->coeff=ptr1->coeff+ptr2->coeff;
			ptrR->expo=ptr1->expo;
			ptr1=ptr1->next;
			ptr2=ptr2->next;
		}
		else if(ptr1->expo>ptr2->expo)
		{
			ptrR->coeff=ptr1->coeff;
			ptrR->expo=ptr1->expo;
			ptr1=ptr1->next;
		}
		else
		{
			ptrR->coeff=ptr2->coeff;
			ptrR->expo=ptr2->expo;
			ptr2=ptr2->next;
		}
	}
	while(ptr1!=NULL)
	{
		ptrR->coeff=ptr1->coeff;
		ptrR->expo=ptr1->expo;
		ptr1=ptr1->next;
	}
	while(ptr2!=NULL)
	{
		ptrR->coeff=ptr2->coeff;
		ptrR->expo=ptr2->expo;
		ptr2=ptr2->next;
	}

}
void display(struct node **poly)
{
	if(*poly==NULL)
	{
		printf("polynomial doesnt exist");
		return;
	}
	struct node *ptr=*poly;
	while(ptr->next!=NULL)
	{
		printf("%d(x^%d)+",ptr->coeff,ptr->expo);
		ptr=ptr->next;
	}
	printf("%d(x^%d)\n",ptr->coeff,ptr->expo);
}

void main()
{
	int coefficient,exponent;
	int op;
	printf("MENU:\n");
	printf("1.INSERT INTO POLYNOMIAL 1\n2.INSERT INTO POLYNOMAL 2\n3.ADD THE POLYNOMIAL\n4.DISPLAY THE POLYNOMIAL\n5.exit");
	do{
		printf("Enter your option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				printf("Enter the coefficient:");
				scanf("%d",&coefficient);
				printf("Enter the exponent:");
				scanf("%d",&exponent);
				read(&p1,coefficient,exponent);
				break;
			case 2:
				printf("Enter the coefficient:");
				scanf("%d",&coefficient);
				printf("Enter the exponent:");
				scanf("%d",&exponent);
				read(&p2,coefficient,exponent);
				break;
			case 3:
				add(&p1,&p2,&result);
				break;
			case 4:
				printf("FIRST POLYNOMIAL:\n");
				display(&p1);
				printf("SECOND POLYNOMIAL:\n");
				display(&p2);
				printf("RESULT:\n");
				display(&result);
				break;
		}
	
	}while(op<5);
}







