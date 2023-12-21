#include<stdio.h>
int p1len,p2len;
int i; 
int a=0,b=0,c=0;
struct polynomial{
	int coeff;
	int expo;
}p1[10],p2[10],p3[10];

void read()
{
	printf("first polynomial\n");
	for(i=0;i<p1len;i++)
	{
		printf("enter the coefficient of the term %d in polynomial 1:",i+1);
		scanf("%d",&p1[i].coeff);
		printf("enter the exponent of the term %d in polynomial 1:",i+1);
		scanf("%d",&p1[i].expo);
	}
	printf("second polynomial\n");
	for(i=0;i<p2len;i++)
	{
		printf("enter the coefficient of the term %d in polynomial 2:",i+1);
		scanf("%d",&p2[i].coeff);
		printf("enter the exponent of the term %d in polynomial 2:",i+1);
		scanf("%d",&p2[i].expo);
	}
}
void add()
{
	while(a<=p1len||b<=p2len)
	{
		if(p1[a].expo==p2[b].expo)
		{
			p3[c].expo=p1[a].expo;
			p3[c].coeff=p1[a].coeff+p2[b].coeff;
			a++;
			b++;
			c++;
		}
		else if(p1[a].expo>p2[b].expo)
		{
			p3[c].expo=p1[a].expo;
			p3[c].coeff=p1[a].coeff;
			a++;
			c++;
		}
		else
		{
			p3[c].expo=p2[b].expo;
			p3[c].coeff=p2[b].coeff;
			b++;
			c++;
		}
	}
}
void display()
{
	printf("first polynomial:\n");
	for(i=0;i<p1len-1;i++)
	{
		printf("%d(x^%d)+",p1[i].coeff,p1[i].expo);
	}
	printf("%d(x^%d)",p1[p1len-1].coeff,p1[p1len-1].expo);
	printf("\nsecond polynomial:\n");
	for(i=0;i<p2len-1;i++)
	{
		printf("%d(x^%d)+",p2[i].coeff,p2[i].expo);
	}
	printf("%d(x^%d)",p2[p2len-1].coeff,p2[p2len-1].expo);
	printf("\nsum polynomial:\n");
	for(i=0;i<c-2;i++)
	{
		printf("%d(x^%d)+",p3[i].coeff,p3[i].expo);
	}
	printf("%d(x^%d)",p3[c-2].coeff,p3[c-2].expo);
	
}
void main()
{
	printf("enter no of terms in p1:");
	scanf("%d",&p1len);
	printf("enter no of terms in p2:");
	scanf("%d",&p2len);
	read();
	add();
	display();
	
}
