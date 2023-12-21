/* program to perform array operations */
#include<stdio.h>
void insert(int arr[30],int r)
{
	int i,ele;
	
	
	printf("enter the element to be inserted:");
	scanf("%d",&ele);
	arr[r]=ele;
	
	for(i=0;i<r+1;i++)
	{
		printf("%d",arr[i]);
	}
}
void delete(int arr[30],int r)
{
	int i,pos;
	printf("enter the position of the element to be deleted");
	scanf("%d",&pos);
	for(i=pos;i<r;i++)
	{
		arr[i-1]=arr[i];	
	}
	
	for(i=0;i<r-1;i++)
	{
		printf("%d",arr[i]);
	}
	
}
void search(int arr[30],int r)
{
	int flag=0,i,ele;
	printf("enter the element to be searched");
	scanf("%d",&ele);
	for(i=0;i<r;i++)
	{
		if(arr[i]==ele)
		{
			printf("the element is present at position %d.",i+1);
			flag=1;
		}
		
	}
	if(flag==0)
	{
		printf("the element is not present");
	}
}
void sort(int arr[30],int r)
{
	int i,j,temp;
	for(i=0;i<r;i++)
	{
		for(j=0;j<r-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	for(i=0;i<r;i++)
	{
		printf("%d",arr[i]);
	}
}
void main()
{
	int n,array[30],i,op;
	printf("enter the number of elements in the array:");
	scanf("%d",&n);
	printf("enter the elements of the array");
	for(i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
	}
	printf("which operation do u want to perform in your array?");
	printf("1.Insertion\n2.Deletion\n3.Searching\n4.Sorting");
	scanf("%d" ,&op);
	int ele;
	switch(op)
	{
		case 1:
		insert(array,n);
		
		break;
		case 2:
		delete(array,n);
		break;
		case 3:
		search(array,n);
		break;
		case 4:
		sort(array,n);
		break;
		default:
		printf("not a valid operation . pls select the right number");
		
		
	}
}
