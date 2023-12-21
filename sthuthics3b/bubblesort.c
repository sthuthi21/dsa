/*program to implement bubblesort*/
#include<stdio.h>
void print(int array[],int size)
{
	for(int i=0;i<size;i++)
	{
		printf("%d\t",array[i]);
	}
}
void bubbleSort(int array[],int size)
{
	int i,j,temp;
	for(i=0;i<size-1;i++)
	{
		for(j=0;j<size-i-1;j++)
		{
			if(array[j]>array[j+1])
			{
				temp=array[j];
				array[j]=array[j+1];
				array[j+1]=temp;
			}
		}
	}
}
void main()
{
	int n,i;
	printf("enter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of the array:");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	bubbleSort(arr,n);
	print(arr,n);
}
