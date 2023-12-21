/*program to find the sum of two sparse matrices*/
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
int sparseSum(rep a[],rep b[],rep c[],int n1,int n2)
{
	i=1,j=1,k=1;
	while(i<=n1&&j<=n2)
	{
		if(a[i].row==b[j].row&&a[i].column==b[j].column)
		{
			c[k].row=a[i].row;
			c[k].column=a[i].column;
			c[k].value=a[i].value+b[j].value;
			i++,j++,k++;
		}
		else if((a[i].row==b[j].row&&a[i].column>b[j].column)||(a[i].row>b[j].row))
		{
			c[k].row=b[j].row;
			c[k].column=b[j].column;
			c[k].value=b[j].value;
			j++,k++;
		}
		else
		{
			c[k].row=a[i].row;
			c[k].column=a[i].column;
			c[k].value=a[i].value;
			i++,k++;
		}
	}
	while(i<=n1)
	{
		c[k].row=a[i].row;
		c[k].column=a[i].column;
		c[k].value=a[i].value;
		i++,k++;
	}
	while(j<=n2)
	{
		c[k].row=b[j].row;
		c[k].column=b[j].column;
		c[k].value=b[j].value;
		j++,k++;
	}
	return k;
}
void displaySparse(rep a[],int count)
{
	printf("\nrow\tcolumn\tvalue\n");
	for(i=0;i<=count;i++)
	{
		printf("%d\t%d\t%d\n",a[i].row,a[i].column,a[i].value);
	}
}
void main()
{
	rep a[10],b[10],c[20];
	int n1,n2;
	int rows,cols;
	printf("enter the number of row and columns in the matrix:");
	scanf("%d %d",&rows,&cols);
	printf("enter the number of non zero elements in matrix 1:");
	scanf("%d",&n1);
	printf("enter the number of non zero elements in matrix 2:");
	scanf("%d",&n2);
	printf("enter the elements of matrix 1 in row,column,value format:\n");
	inputSparse(a,n1,rows,cols);
	printf("enter the elements of matrix 2 in row,column,value format:\n");
	inputSparse(b,n2,rows,cols);
	int value=sparseSum(a,b,c,n1,n2);
	c[0].row=rows;
	c[0].column=cols;
	c[0].value=value-1;
	printf("MATRIX 1:\n");
	displaySparse(a,n1);
	printf("MATRIX 2:\n");
	displaySparse(b,n2);
	printf("SUM MATRIX:\n");
	displaySparse(c,value-1);
	
	
}














