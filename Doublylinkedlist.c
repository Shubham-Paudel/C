#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int info;
	struct node *next;
	struct node *prev;
};
struct node *newnode;
struct node *head=NULL;
struct node *ptr=NULL;
int i;
void create();
void insert_1st();
void insert_end();
void insert_speci();
void delete_1st();
void delete_end();
void delete_speci();
void display();
int main()
{
	int n;
	while(1)
	{
	printf("\n0.Exit\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Delete at beginning\n5.Delete at end\n6.Delete at specified position\n7.Display all elements in list");
	printf("\nEnter your choice :");
	scanf("%d",&n);
	switch(n)
	{
		case 0:
			exit(0);
			break;
		case 1:
			insert_1st();
			break;
		case 2:
			insert_end();
			break;
		case 3:
			insert_speci();
			break;
		case 4:
			delete_1st();
			break;
		case 5:
			delete_end();
			break;
		case 6:
			delete_speci();
			break;
		case 7:
			display();
			break;
		default:
			break;
	}
}
	return 0;
}
void create()
{
	int data;
	printf("\nEnter your data:");
	scanf("%d",&data);
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->prev=NULL;
	newnode->next=NULL;
	return;
}
void insert_1st()
{
	create();
	if(head==NULL)
	{
		head=newnode;
		return;
	}
	newnode->next=head;
	head->prev=newnode;
	head=newnode;
	return;
}
void insert_end()
{
	create();
		if(head==NULL)
	{
		head=newnode;
		return;
	}
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->next=newnode;
	newnode->prev=ptr;
	return;
}
void insert_speci()
{
	int pos;
	create();
	printf("Enter the position :");
	scanf("%d",&pos);
	getch();
	ptr=head;
	for(i=0;i<pos-1;i++)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("\nPosition not found!!");
			return;
		}
	}
	newnode->next=ptr->next;
	newnode->prev=ptr;
	ptr->next->prev=newnode;
	ptr->next=newnode;
	return;
}
void delete_1st()
{
	if(head==NULL)
	{
		printf("\nList is empty!!");
		exit(0);
	}
	ptr=head;
	head=head->next;
	head->prev=NULL;
	free(ptr);
	return;
}
void delete_end()
{
	if(head==NULL)
	{
		printf("\nList is empty!!");
		exit(0);
	}
	else if(head->next==NULL)
	{
		ptr=head;
		head=NULL;
		printf("Deleted element is %d",ptr->info);
		free(ptr);
	}
	ptr=head;
	while(ptr->next!=NULL)
	{
		ptr=ptr->next;
	}
	ptr->prev->next=NULL;
	printf("Deleted element is %d",ptr->info);
	free(ptr);
	return;
}
void delete_speci()
{
	int pos;
	if(head==NULL)
	{
		printf("\nList is empty!!");
		exit(0);
	}
	printf("\nEnter the position to be deleted :");
	scanf("%d",&pos);
	if(pos==0)
	{
		ptr=head;
		head=head->next;
		head->prev=NULL;
		printf("Deleted element is %d",ptr->info);
		free(ptr);
		exit(0);
	}
	ptr=head;
	for(i=0;i<pos;i++)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("\nPosition not found!!");
		}
	}
	printf("Deleted element is %d",ptr->info);
	ptr->prev->next=ptr->next;
	ptr->next->prev=ptr->prev;
	free(ptr);
	return;
}
void display()
{
	printf("\nElements in list are :");
	ptr=head;
	while(ptr!=NULL)
	{
		printf("\n%d",ptr->info);
		ptr=ptr->next;
	}
	return;
}
