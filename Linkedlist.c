#include<stdio.h>
#include<stdlib.h>
int i=0;
struct node
{
	int info;
	struct node *next;
};
struct node *head=NULL;
void insert_1st()
{
	struct node *newnode;
	int data;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter your data :");
	scanf("%d",&data);
	newnode->info=data;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		newnode->next=head;
		head=newnode;
	}
}
void insert_end()
{
   	struct node *newnode,*ptr;
	int data;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter your data :");
	scanf("%d",&data);
	newnode->info=data;
	newnode->next=NULL;
	if(head==NULL)
	{
		head=newnode;
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=newnode;
	}
}
void insert_speci()
{
	struct node *newnode,*ptr;
	int data;
	newnode=(struct node*)malloc(sizeof(struct node));
	printf("Enter your data :");
	scanf("%d",&data);
	newnode->info=data;
	int pos;
	printf("\nEnter the position in which in you want to insert :");
	scanf("%d",&pos);
	for(i=0;i<pos-1;i++)
	{
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("\nPosition not found");
		}
	}
	newnode->next=ptr->next;
	ptr->next=newnode;
}
void delete_1st()
{
	struct node *newnode,*ptr;
	ptr=head;
	if(ptr==NULL)
	{
		printf("List is empty!!");
	}
	else
	{
		ptr=head;
		head=head->next;
		printf("The deleted data is %d",ptr->info);
		free(ptr);
	}
}
void delete_end()
{
	struct node *newnode,*ptr,*temp;
	ptr=head;
	if(ptr==NULL)
	{
		printf("\nlist is empty!!");
	}
	else if(head->next=NULL)
	{
		ptr=head;
		head=NULL;
		printf("Deleted element is %d",ptr->info);
		free(ptr);
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			temp=ptr;
			ptr=ptr->next;
		}
		temp->next=NULL;
			printf("The deleted element is %d",ptr->info);
			free(ptr);
	}
}
void delete_speci()
{
		struct node *newnode,*ptr,*temp;
		int pos;
		ptr=head;
		printf("\nEnter the position you want to delete :");
		scanf("%d",&pos);
		if(ptr==NULL)
		{
			printf("\nThe list is empty!!");
		}	
		else if(pos==0)
		{
			ptr=head;
			head=head->next;
			printf("\nThe deleted element is :",ptr->info);
			free(ptr);
		}
		else
		{
			ptr=head;
			for(i=0;i<pos;i++)
			{
				temp=ptr;
				ptr=ptr->next;
				if(ptr==NULL)
				{
					printf("\nposition not found");
				}
			}
			temp->next=ptr->next;
			printf("The deleted element is %d",temp->info);
			free(ptr);
		}
}
void display()
{
		struct node *ptr;
		ptr=head;
		if(ptr==NULL)
		{
			printf("\nThe list is empty!!");
		}
		else
		{
			ptr=head;
			printf("The elements in list is:");
			while(ptr!=NULL)
			{
				printf("\n%d",ptr->info);
				ptr=ptr->next;
			}
		}
}
int main()
{
	int n;
	while(1)
	{
	printf("\n0.Exit\n1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n4.Delete at beginning\n5.Delete at end\n6.Delele at specified position\n7.Display all elements in the list\n");
	printf("Enter your choice :");
	scanf("%d",&n);
	switch(n)
	{
		case 0:
		    exit(0);
			return 0;
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
