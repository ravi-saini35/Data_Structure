#include<stdio.h>
#define STACKSIZE 10
int top=-1,x;

void display(int stack[top+1])
{
	int i;
	for(i=top;i>=0;i--)
		printf("\n|____%d____|",stack[i]);
}


void push(int stack[STACKSIZE],int element)
{
	if(top>STACKSIZE-1)
	{
		printf("stack is overflow\n");
		x=0;
	}
	else
	{
		x=1;
		top++;
		stack[top]=element;
	}
}
void pop( int stack[STACKSIZE])
{	
	if(top>=0)
	{
		printf("\nthe poped element is %d\n",stack[top]);
        	top--;
        	printf("\nafter popping a element \n the stack is\n");
     		display(stack);
		
	}
	else
	printf("\nstack is underflow\n");
	
}

void main()
{ 
	int choice;
	do
	{
	int stack[STACKSIZE];
	printf("Enter your choice whatever you want to do\n");;
	printf("1. for push an element\n");
	printf("2. for pop an element\n");
	printf("3. for exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
		{
			int element;
			printf("Enter the element which to be pushed");
			scanf("%d",&element);
			push(stack,element);
			display(stack);
		}
		break;
		case 2:
		{
			pop(stack);
		}
		break;
		case 3:
			printf("thanks\n");
		break;
		default:
			printf(" Invalid number! \nTry again ");
		
	}
	}while(choice>=1 && choice<3); 
	
}
