#include<stdio.h>
#define max_queue_size 2
int rear=-1,front=-1;
int array[max_queue_size];
void enque(int item)
{
    if(rear==-1&&front==-1)
      {
        array[++rear]=item;
        front++;
      }
     else if(rear==max_queue_size-1)
      printf("queue is full\n" );
    else
      array[++rear]=item;
}
int deque()
{
  if(front==-1 || front>rear)
  {printf("queue is empty\n" );
    return -1;}
  else
    return (array[front++]);
}
void display()
{
  int i;
    if(front!=-1||rear>front)
  {
	  printf("now the queue is\n");

  {
  for(i=rear;i>=front;i--)
   	 printf("|__%d__|\n",array[i] );
   }
}
}

int main()
{
  int choice,item,n;
  do
  {
    printf("enter your choice\n" );
    printf("1. for enque\n 2. for deque\n 3. for exit\n" );
    scanf("%d",&choice);
    switch(choice)
    {
	    case 1:
	   {
	printf("enter an item to enque\n" );
        scanf("%d",&item );
        enque(item);
        display();
	   }
	   break;
	    case 2:
      {
        n=deque();
        printf("the poped element is %d\n",n );
        display();
      }
      break;
	    case 3:
	   {
        printf("thanks\n");
        return 0;
	   }
	   break;
      default:
        printf("enter a valid number\n try again !\n" );

    }
  }while(choice!=3);
  return 0;

}
