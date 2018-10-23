#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node* next;
	
}

typedef struct node NODE;

int getNode(int item)
{
	NODE* newnode;
	newnode=(NODE*)malloc(sizeof(NODE));

	if(newnode==NULL)
	{
		printf("no enough space in the system\n");
		
		return 0;
	}

	newnode->data=item;

	newnode->next=0;

	return newnode;
}

NODE *head=0;

void pushFront(int item)

{
	NODE* newnode;

	newnode=getNode(item);	

	newnode->next=head;

	head=newnode;
	
}

void deleteFront()
{
	
	if(head==NULL)

	{
		printf("linkedlist is empty\n");
	}

	else{
		NODE *cur;
		cur=head;
		head=head->next;
		free(cur);}
	}
}
void pushEnd(int item)
{
	NODE *newnode,*cur;
	newnode=getNode(item);

	if(head==NULL)
	{
		newnode->next=NULL;

		head=newnode;
	}

	else{

		cur=head;

		while(cur->next!=NULL)

		{
	
			cur=cur->next;
		}
		cur->next=newnode;
	}
}

void deleteEnd()
{
	if(head==NULL)
	{
		printf("linked list is empty\n");
	}

	else{	
	
		NODE *cur,*prev;

		cur=head;

		if(cur->next==NULL)

		{
	
			head=NULL;
	
			free(cur);

		}

		else{

			while(cur->next!=NULL)

			{
	
				prev=cur;
	
				cur=cur->next;

			}

			prev->next=NULL;

			free(cur);
		}
	}
}


void displayList()
{
	if(head==NULL)
	
		printf("linkedlist is empty\n");
	
	else
	{
		NODE *cur;
		
		cur=head;
		
		while(cur!=NULL)
		{
			printf("%d-->",cur->data);
			cur=cur->next;
		}

	}

}


int main()
{
	int choice;

	do{
		
		printf("\nenter your choice\n");
		printf("1. for pushFront\n 2.for deleteFront\n 3.for pushEnd\n 4.for for deleteEnd\n 5. display\n 6. exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: 
			
				int item;
			
				printf("Enter the element to push in front\n");
			
				scanf("%d",&item);
			
				pushFront(item);
			
				break;

			case 2:
			
				deleteFront();
				
				break;
		
			case 3:
			
				int item;
				
				printf("enter a element to push in end\n");
			
				scanf("%d",&item);
				
				pushEnd(item);
			
				break;
			
			case 4:
			
				deleteEnd();
				
				break;
			
			case 5:
			
				displayList();
			
				break;

			case 6:
			
				return 0;
			
		}
	}while(choice>=1&&choice<=6);

	return 0;
}
