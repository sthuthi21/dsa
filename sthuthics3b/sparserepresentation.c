/*represention of sparse matrix*/
#include<stdio.h>
typedef struct{
	int row;
	int column;
	int value;
}rep;
int i,j;
void readMatrix(int array[10][10],int r,int c)
{
	printf("enter the elements of the array");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			scanf("%d",&array[i][j]);
		}
		
	}
}
void displayMatrix(int array[10][10],int r,int c)
{
	printf("The Matrix is:\n");
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			printf("%d\t",array[i][j]);
		}
		printf("\n");
	}
}

int countElements(int array[10][10],int r,int c)
{
	int count=0;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(array[i][j]!=0)
				count++;
		}
		
	}
	return count;
	
}
void sparseRep(int array[10][10],rep a[],int r,int c,int count)
{
	a[0].row=r;
	a[0].column=c;
	a[0].value=count;
	int k=1;
	for(i=0;i<r;i++)
	{
		for(j=0;j<c;j++)
		{
			if(array[i][j]!=0)
			{
				a[k].row=i;
				a[k].column=j;
				a[k].value=array[i][j];
				k++;
			}	
		}
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
void main()
{
	int r,c,nonZero;
	int array[10][10];
	float sparcity;
	printf("enter the number of rows and columns of the matrix:");
	scanf("%d %d",&r,&c);
	readMatrix(array,r,c);
	displayMatrix(array,r,c);
	nonZero=countElements(array,r,c);
	rep a[nonZero+1];
	sparseRep(array,a,r,c,nonZero);
	displaySparse(a,nonZero);
	
	sparcity=(float)(r*c-nonZero)/(r*c);
	printf("%f",sparcity);
	
	
}














