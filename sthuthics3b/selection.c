/*program to implement selection sort*/
#include<stdio.h>
int i,j;
void print(int array[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d\t",array[i]);
	}
}
void selectionSort(int array[],int size)
{
	int min,temp;
	for(i=0;i<size-1;i++)
	{
		min=i;
		for(j=i+1;j<size;j++)
		{
			if(array[j]<array[min])
			{
				min=j;
			}
		}
		temp=array[i];
		array[i]=array[min];
		array[min]=temp;
	}
	print(array,size);
}

void main()
{
	int n;
	printf("enter size of array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter elements of array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	selectionSort(arr,n);
}
