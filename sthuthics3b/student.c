#include<stdio.h>
struct student
{
	char name[20];
	int mark_phy;	
	int mark_chem;	
	int mark_bio;	
	int mark_maths;	
	int mark_comp;	
	int totalmark;	
};
void main()
{
	int num;
	printf("enter the number of students:");
	scanf("%d",&num);
	for(i=0;i<num;i++)
	{
		printf("enter the name:");
		scanf("%[^\n]",student.name[i]);
		printf("enter marks for physics:");
		scanf("%d",&student.mark_phy[i]);
		printf("enter marks for chemistry:");
		scanf("%d",&student.mark_chem[i]);
		printf("enter marks for biology:");
		scanf("%d",&student.mark_bio[i]);
		printf("enter marks for maths:");
		scanf("%d",&student.mark_maths[i]);
		printf("enter marks for computer:");
		scanf("%d",&student.mark_comp[i]);
		student.totalmark[i]=student.mark_phy[i]+student.mark_chem[i]+student.mark_bio[i]+student.mark_maths[i]+student.mark_comp[i];
		printf("total mark:%d",student.totalmark[i]);
	}
}
