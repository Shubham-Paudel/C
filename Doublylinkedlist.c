#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
        int info;
        struct node *next;
        struct node *prev;
};
struct node *newnode;
struct node *head;
struct node *ptr=NULL;
int i=0;
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
void create()
{
    int data;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter your data :");
    scanf("%d",&data);
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
    else
    {
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    }
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
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->prev=ptr;
    }
    return;
}
void insert_speci()
{
    int pos;
    create();
    printf("\nEnter the position you want to insert :");
    scanf("%d",&pos);
    ptr=head;
    for ( i = 0; i<pos-1; i++)
    {
        ptr=ptr->next;
        if(ptr==NULL)
        {
            printf("\nPosition not found");
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
        printf("\nThe list is empty!!");
        return;
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
        printf("\nThe list is empty!!");
        return;
    }
    else if(head->next=NULL)
    {
        ptr=head;
        head=NULL;
        printf("\nDeleted element is %d",ptr->info);
        free(ptr);
    }
    else
    {
        ptr=head;
        while(ptr->next!=NULL)
        {
            ptr=ptr->next;
        }
        ptr->prev->next=NULL;
        printf("\nDeleted element is %d",ptr->info);
        free(ptr);
    }
    return;
}
void delete_speci()
{
    int pos;
    if(head==NULL)
    {
        printf("\nThe list is empty!!");
        return;
    }
    printf("\nEnter the position you want to delete :");
    scanf("%d",&pos);
    if(pos==0)
    {
        ptr=head;
        head=head->next;
        head->prev=NULL;
        printf("\nDeleted element is %d",ptr->info);
        free(ptr);
    }
    else
    {
        ptr=head;
        for(i=0;i<pos;i++)
        {
            ptr=ptr->next;
            if(ptr==NULL)
            {
                printf("\nPosition not found");
            }
            ptr->prev->next=ptr->next;
            ptr->next->prev=ptr->prev;
            free(ptr);
        }
    }
 return;
}
void display()
{
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
		return;
}
