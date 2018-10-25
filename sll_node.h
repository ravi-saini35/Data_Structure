struct node {
	int data;
	struct node* next;
	};
typedef struct node NODE;
NODE* getNode(int item)
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
//NODE *head=0;
NODE *pushFront(NODE *head,int item)

{
	NODE* newnode;
	newnode=getNode(item);
	newnode->next=head;
	head=newnode;

}
NODE* deleteFront(NODE *head)
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
	return head;
}
NODE *pushEnd(NODE *head,int item)
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
	return head;
}
NODE *deleteEnd(NODE *head)
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
	free(cur);}
	}
	return head;
}
NODE *insert_at_i_th_position(NODE *head,int item)
{
	NODE* cur,*newnode;
	int i,k=2;
	cur=head;
	newnode=getNode(item);
	printf("Enter the value of i");
	scanf("%d",&i);
	if(head==NULL)
	{
		if(i==1)
		{
			head=newnode;
			return head;
		}
		else
		{
			printf("invalid insertion!\n");
			return head;
		}
	}
	while(k!=i)
	{
		cur=cur->next;
		if(cur==0)
		{
			printf("not posible inter the value of i in a posible range\n");
			return head;
		}
		k++;
	}
	newnode->next=cur->next;
	cur->next=newnode;
	return head;
}
NODE *searchElement(NODE *head)
{
	int target,i=1;
	printf("enter the element which you want to search.\n" );
	scanf("%d",&target);
	NODE* cur;
	cur=head;
	if(cur==NULL)
	{
		printf("ohh! linkedlist is empty.\n");
		return head;
	}
	while(cur->data!=target)
	{
		cur=cur->next;
		if(cur==NULL)
		{
			printf("this element is not there in linkedlist\n" );
			return  head;
		}
		i++;
	}
	printf("target element is at position =%d\n",i);
	return head;
}
NODE *delete_at_i_position(NODE *head)
{
	int i,k=2;
	if(head==NULL)
	{
		printf("linkedlist is empty\n");
		return head;
	}
	NODE* cur,*cur2;
	cur=head;
	printf("enter the value of i\n");
	scanf("%d",&i);
	if(i=1)
	{
		 deleteFront(head);
		return head;
	}
	while(k!=i)
	{
		cur=cur->next;
		k++;
	}
	if(k!=i)
	{
		printf("Enter a valid number\n");
		return head;
	}

	cur2=cur->next;
	cur->next=cur->next->next;
	free(cur2);
	return head;
}
void displayList(NODE *head)
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
