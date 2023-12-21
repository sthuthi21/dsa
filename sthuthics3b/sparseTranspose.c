/*find transpose of sparse matrix*/
#include<stdio.h>
int i,j,k;
typedef struct{
	int row;
	int column;
	int value;
}rep;
void inputSparse(rep s[],int n,int r,int c)
{
	s[0].row= r;
	s[0].column= c;
	s[0].value= n;
	
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d",&s[i].row,&s[i].column,&s[i].value);
	}
}
void displaySparse(rep a[],int count)
{
	printf("\nrow\tcolumn\tvalue\n");
	for(i=0;i<=count;i++)
	{
		printf("%d\t%d\t%d\n",a[i].row,a[i].column,a[i].value);
	}
}
void arrangeSparse(rep a[],int n)
{
	rep temp[1];
	for(i=1;i<=n;i++)
	{
		for(j=i+1;i<=n;i++)
		{
			if((a[i].row>a[j].row && a[j].column==a[i].column)||a[i].column>a[j].column)
			{
				temp[0]=a[i];
				a[i]=a[j];
				a[j]=temp[0];
			}
		}
	}
}
void transpose(rep a[],int n)
{
	rep temp[1];
	for(i=0;i<=n;i++)
	{
		temp[0].row=a[i].row;
		a[i].row=a[i].column;
		a[i].column=temp[0].row;
	}
}

void main()
{
	rep a[10],b[10];
	int n;
	int rows,cols;
	printf("enter the number of row and columns in the matrix:");
	scanf("%d %d",&rows,&cols);
	printf("enter the number of nonzero elements:");
	scanf("%d",&n);
	printf("enter the elements of matrix in row,column,value format:\n");
	inputSparse(a,n,rows,cols);
	for(i=0;i<=n;i++)
	{
		b[i]=a[i];
	}
	arrangeSparse(b,n);
	transpose(b,n);
	printf("MATRIX:\n");
	displaySparse(a,n);
	printf("TRANSPOSE:\n");
	displaySparse(b,n);
	
	
}












