#include<stdio.h>
#include<math.h>
int n,x;
int i;
int result=0;
struct polynomial
{
	int coeff;
	int expo;
}p[20];

void main()
{
	
	printf("enter the number of terms in the polynomail:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("enter the coefficient of term %d:",i+1);
		scanf("%d",&p[i].coeff);
		printf("enter the exponent of term %d:",i+1);
		scanf("%d",&p[i].expo);
	}
	printf("enter the value of x:");
	scanf("%d",&x);
	for(i=0;i<n;i++)
	{
		result += (p[i].coeff * pow(x,p[i].expo));	
	}
	printf("value of polynomial is: %d\n",result);
}



