/*implementation of circular list*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
	struct node *prev;
};
struct node *head=NULL;

struct node* create_node()
{
    int value;
    printf("ENTER THE DATA :");
    scanf("%d",&value);

    struct node *new = (struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    new->prev=NULL;
    return new;
}

void insertFront()
{
	struct node *new=create_node();
	if(head==NULL)
	{
		head=new;
		head->next=new;
		head->prev=new;
	}
	else
	{
		new->next=head;
		new->prev=head->prev;
		head->prev->next=new;
		head=new;          
	}
}
void insertLast()
{
	struct node *new=create_node();
	if(head==NULL)
	{
		head=new;
		head->next=new;
		head->prev=new;
	}
	else
	{
		new->prev=head->prev;
		head->prev->next=new;
		new->next=head;
		head->prev=new;
	}

}

void deleteFirst()
{
	if(head==NULL)
	{
		printf("No list exists.\n");
		return;
	}
	else
	{
		struct node *ptr=head;
		if(ptr->next==head)
		{
			head=NULL;
		}
		else
		{
			head->next->prev=head->prev;
			head->prev->next=head->next;
			head=head->next;
		}
		printf("the deleted element:%d",ptr->data);
		free(ptr);
	}
	
	
}

void deleteLast()
{
	if(head==NULL)
	{
		printf("no linked list exists:\n");
		return;
	}
	else
	{
		struct node *ptr=head->prev;
		if(head->prev==head)
		{
			head=NULL;
		}
		else
		{
			head->prev=head->prev->prev;
			head->prev->next=head;
		}
		printf("the deleted element:%d",ptr->data);
		free(ptr);
	}
	
}

void display()
{
	struct node *ptr;
	printf("CIRCULAR LIST:\n");
	if(head==NULL)
	{
		printf("no list exists\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!= head)
		{
			printf("%d\n" , ptr->data);
			ptr=ptr->next;
		}
		printf("%d\n" , ptr->data);
	}
}

void main()
{
    
    int op,item,position;
    printf("MENU");
	printf("WHAT OPERATIONS DO  YOU WANT TO DO?\n");
	printf("1.insertion at begin\n2.insert at end\n3.delete from front\n4.delete from end\n5.display");
    printf("press any other number to exit\n");
	do{
		printf("enter your option:");
		scanf("%d",&op);
		switch(op)
		{
			case 1:
				insertFront();
				break;
			case 2:
				insertLast();
				break;
			case 3:
				deleteFirst();
				break;
			case 4:
				deleteLast();
				break;
			case 5:
                display();
                break;
		}
	}while(op<6);
}

/*server
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <fcntl.h>
void rsendd(int ch, int c_sock) {
char buff2[60];
bzero(buff2, sizeof(buff2));
strcpy(buff2, "Retransmission message: ");
buff2[strlen(buff2)] = (ch) + '0';
buff2[strlen(buff2)] = '\0';
printf("Resending Message to client: %s \n", buff2);
write(c_sock, buff2, sizeof(buff2));
usleep(1000);
}
int main() {
int s_sock, c_sock;
s_sock = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in server, other;
memset(&server, 0, sizeof(server));
memset(&other, 0, sizeof(other));
server.sin_family = AF_INET;
server.sin_port = htons(7004);
server.sin_addr.s_addr = INADDR_ANY;
socklen_t add;
if (bind(s_sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
 printf("Binding failed\n");
 return 0;
}
printf("\nSelective repeat - Server\n\n");
listen(s_sock, 10);
add = sizeof(other);
c_sock = accept(s_sock, (struct sockaddr *)&other, &add);
time_t t1, t2;
char msg[50] = "Server message: ";
char buff[50];
int flag = 0;
fd_set set1, set2, set3;
struct timeval timeout1, timeout2, timeout3;
int rv1, rv2, rv3;
int tot = 0;
int ok[20];
memset(ok, 0, sizeof(ok));
while (tot < 9) {
 int toti = tot;
 for (int j = (0 + toti); j < (3 + toti); j++) {
 bzero(buff, sizeof(buff));
 char buff2[60];
 bzero(buff2, sizeof(buff2));
 strcpy(buff2, "Server message: ");
 buff2[strlen(buff2)] = (j) + '0';
 buff2[strlen(buff2)] = '\0';
 printf("Message sent to client: %s \n", buff2);
 write(c_sock, buff2, sizeof(buff2));
 usleep(1000);
 }for (int k = 0 + toti; k < (toti + 3); k++) {
 qq:
 FD_ZERO(&set1);
 FD_SET(c_sock, &set1);
 timeout1.tv_sec = 2;
 timeout1.tv_usec = 0;
 rv1 = select(c_sock + 1, &set1, NULL, NULL, &timeout1);
 if (rv1 == -1)
 perror("select error");
 else if (rv1 == 0) {
 printf("Timeout for message: %d \n", k);
 rsendd(k, c_sock);
 goto qq;
 }
 else {
 read(c_sock, buff, sizeof(buff));
 printf("Message from Client: %s\n", buff);
 if (buff[0] == 'n') {
 printf("Corrupted message acknowledgement (msg %d) \n", 
buff[strlen(buff) - 1] -
'0');
 rsendd((buff[strlen(buff) - 1] - '0'), c_sock);
 goto qq;
 }
 else
 tot++;
 }
 }
}
close(c_sock);
close(s_sock);
return 0;
}*/

/*client

#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
int isfaulty() {
 int d = rand() % 4;
 return (d > 2);
}
int main() {
 srand(time(0));
 int c_sock;
 c_sock = socket(AF_INET, SOCK_STREAM, 0);
 struct sockaddr_in client;
 memset(&client, 0, sizeof(client));
 client.sin_family = AF_INET;
 client.sin_port = htons(7004);
 client.sin_addr.s_addr = inet_addr("127.0.0.1");
 if (connect(c_sock, (struct sockaddr *)&client, sizeof(client)) == -1) {
 printf("Connection failed");
 return 0;
 }
 printf("\nClient - with individual acknowledgement scheme\n\n");
 char msg1[50] = "Acknowledgement of: ";
 char msg3[50] = "Negative Acknowledgement: ";
 char msg2[50];
 char buff[100];
 int count = -1, flag = 1;
 while (count < 8) {
 bzero(buff, sizeof(buff));
 bzero(msg2, sizeof(msg2));
 if (count == 7 && flag == 1) {
 printf("here\n");
 flag = 0;
 read(c_sock, buff, sizeof(buff));
continue;
 }
 int n = read(c_sock, buff, sizeof(buff));
 char i = buff[strlen(buff) - 1];
 printf("Message received from server: %s \n", buff);
 int isfault = isfaulty();
 printf("Corruption status: %d \n", isfault);
 printf("Acknowledgement sent for message.\n");
 if (isfault)
 strcpy(msg2, msg3);
 else
 {
 strcpy(msg2, msg1);
 count++;
 }
 msg2[strlen(msg2)] = i;
 write(c_sock, msg2, sizeof(msg2));
 }
 close(c_sock);
 return 0;
}*/