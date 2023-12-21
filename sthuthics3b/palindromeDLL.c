/*to check whether a string is palindrome or not using doubly linked list*/

#include<stdio.h>
#include<stdlib.h>

struct node{
	char data;
	struct node *next=NULL;
	struct node *prev=NULL;
}
struct node *head=NULL;

