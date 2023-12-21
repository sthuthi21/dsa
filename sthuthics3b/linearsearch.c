/*program to implement linear search*/
#include<stdio.h>
void linearSearch(int array[],int size,int ele)
{
	int flag=0;
	for(int i=0;i<size;i++)
	{
		if(array[i]==ele)
		{
			printf("%d is present at position %d.",ele,i+1);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("element not found");
	}
}
void main()
{
	int n,ele;
	printf("enter the size of the array:");
	scanf("%d",&n);
	int arr[n];
	printf("enter the elements of the array:");
	for(int i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("enter the element you want to search:");
	scanf("%d",&ele);
	
	linearSearch(arr,n,ele);
}
