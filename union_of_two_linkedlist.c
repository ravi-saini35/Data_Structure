#include<stdio.h>
#include<stdlib.h>
#include"sll_node.h"
NODE *Union(NODE *head1,NODE *head2,NODE *head)
{
     NODE *temp,*temp1=head1,*temp2=head2;
     if(head1->data<head2->data)
     {
          temp=head1;
          temp1=temp1->next;
     }

     else if(head2->data<head1->data)
     {

          temp=head2;
          temp2=temp2->next;
     }
     else
     {
          temp=head1;
          temp1=temp1->next;
          temp2=temp2->next;
     }
     head=temp;
     while(temp1!=NULL&&temp2!=NULL)
     {
          if(temp1->data<temp2->data)
          {
               temp->next=temp1;
               temp=temp1;
               temp1=temp1->next;
          }
          else if(temp2->data<temp1->data)
          {
               temp->next=temp2;
               temp=temp2;
               temp2=temp2->next;
          }
          else
          {
               temp->next=temp1;
               temp=temp1;
               temp2=temp2->next;
               temp1=temp1->next;
          }
     }
     if(temp1==0)
     {
          temp->next=temp2;
     }
     else
     {
          temp->next=temp1;
     }

     return head;

}
void main()
{
  int choice;
  int x;
  NODE *head1=NULL,*head2=NULL,*head=NULL;
  do{
	printf("enter choice\n");
	printf("1. pushFront\n 2.pushEnd\n 3. display\n 4. union of two\n " );
	scanf("%d",&choice);
	switch (choice) {
		case 1:
		{
			int item;
			printf("entre a number\t");
			scanf("%d",&item);
               printf("where you want to push\n");
               printf("\t\t\t1. in 1'st linked list\n");
               printf("\t\t\t2. in 2'nd linked list\n" );
               scanf("%d",&x);
               if(x==1)
		             head1=pushFront(head1,item);
               if(x==2)
                       head2=pushFront(head2,item);
			break;
		}
		case 2:
		{
			int item;
			printf("entre a number\n");
			scanf("%d",&item);
               printf("where you want to push\n");
               printf("\t\t\t1. in 1'st linked list\n");
               printf("\t\t\t2. in 2'nd linked list\n" );
               int y;
               scanf("%d",&y);
               if(x==1)
		            head1= pushEnd(head1,item);
               if(x==2)
                      head2= pushEnd(head2,item);
			break;
		}
		case 3:
		{
               printf("which linkedlist you want to display:-\n");
               printf("\t\t\t1. in 1'st linked list\n");
               printf("\t\t\t2. in 2'nd linked list\n" );

               scanf("%d",&x);
               if(x==1)
		             displayList(head1);
               if(x==2)
                       displayList(head2);
			break;
		}
		case 4:
		{
               head=Union(head1,head2,head);
               displayList(head);
			break;
		}
          default :
          {
               printf("do it again\n" );
          }
	}
}while(/*choice>=1&&choice<=4*/1);
}
