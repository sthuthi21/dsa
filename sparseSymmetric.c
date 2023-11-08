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
    s[0].row=r;
    s[0].column=c;
    s[0].value=n;

    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&s[i].row,&s[i].column,&s[i].value);
    }
}
void displaySparse(rep s[],int count)
{
    printf("row\tcolumn\tvalue\n");
    for(i=0;i<=count;i++)
    {
        printf("%d\t%d\t%d\n",s[i].row,s[i].column,s[i].value);
    }
}
void arrangeSparse(rep a[],int n)
{
    rep temp;
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            if((a[i].row>a[j].row && a[j].column==a[i].column)||a[i].column>a[j].column)
            {
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
    }
}
void transpose(rep a[],int n)
{
    rep temp;
    for(i=0;i<=n;i++)
    {
        temp.row=a[i].row;
        a[i].row=a[i].column;
        a[i].column=temp.row;
    }
}
void checkSymmetric(rep a[],rep b[],int n)
{
    int flag=1;
    for(i=0;i<=n;i++)
    {
        if(b[i].column!=a[i].column||b[i].row!=a[i].row||b[i].value!=a[i].value)
        {
            flag=0;
            printf("NOT SYMMETRIC");
            break;
        }
    }
    if(flag==1)
        printf("SYMMETRIC");
}
void main()
{
    int n , rows , columns;
    rep a[10],b[10];
    printf("enter number of rows and columns in matrix:");
    scanf("%d %d",&rows,&columns);
    printf("enter the number of nonzero elements:");
    scanf("%d",&n);
    printf("enter non zero elements of matrix in row,column,value format:\n");
    inputSparse(a,n,rows,columns);
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
    checkSymmetric(a,b,n);

}