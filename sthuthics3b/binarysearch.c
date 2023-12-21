
#include<stdio.h>
int i,j;
void print(int array[],int size)
{
	for(i=0;i<size;i++)
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
	printf("the sorted array is:\n");
	print(array,size);
}

int binarySearch(int array[],int size,int ele)
{
	int left=0,right=size-1;
	
	int mid;
	
	while(left<=right)
	{
		mid=(left+right)/2;
		if(array[mid]==ele)
		{
			return mid+1;	
		}
		else if(array[mid]<ele)
		{
			left=mid+1;
		}
		else
		{
			right=mid-1;
		}
	}
	
	return -1;
	
	
}
void main()
{
	 int n,ele;
	 printf("enter the size of array:");
	 scanf("%d",&n);
	 int arr[n];
	 printf("enter the elements of array:");
	 for(int i=0;i<n;i++)
	 {
	 	scanf("%d",&arr[i]);
	 }
	 selectionSort(arr,n);
	 printf("\nenter the number to be searched:");
	 scanf("%d",&ele);
	 int result=binarySearch(arr,n,ele);
	 if(result==-1)
	 {
	 	printf("\nelement not found");
	 }
	 else
	 {
	 	printf("\n%d is found at position %d.",ele,result); 
	 }
	 
	 
}
