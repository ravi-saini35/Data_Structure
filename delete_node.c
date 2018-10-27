#include<stdio.h>
#include<stdlib.h>
#define q 30
struct node 
{
        int data;
        struct node *right;
        struct node *left;
};

typedef struct node NODE;

int r=-1,f=-1;

NODE *queue[q];


void enque( NODE *x)
{
	if(r==q)
	{

		return;
	}

	if(f==-1&&r==-1)
	{
		f=0;
	}

	r++;

	queue[r]=x;
}

NODE* deque()
{
	if(f==-1)
	{
		printf("the queue is empty");
		
		return NULL ;
	}
	return queue[f++];
}


NODE * getnode(int data)
{

	NODE* newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	newnode->right=NULL;
	newnode->left=NULL;
	newnode->data=data;
	return newnode;
}

NODE *insert(NODE* root,int data){

	if(root==NULL)
	{
		NODE* newnode;
		newnode=getnode(data);
		return newnode;
	}

	if(root->data==data)
	{
		printf("it's not a distinct data so can not  insert");
		return root;
	}

	else
	{

		if(root->data>data)
		{

			root->left=insert(root->left,data);
			return root;
		}

		else
		{
			root->right=insert(root->right,data);
			return root;
		}
	}
}

void inorder_display(NODE*root)
{
	if(root==NULL)
	{
		return;
	}

	inorder_display(root->left);

	printf("%d ",root->data);

	inorder_display(root->right);
}


void postorder_display(NODE*root)
{
	if(root==NULL)
	{
		return;
	}

	postorder_display(root->left);

	postorder_display(root->right);

	printf("%d ",root->data);
}


void preorder_display(NODE*root)
{
	if(root==NULL)
	{
		return;
	}

	printf("%d ",root->data);
	
	preorder_display(root->left);
	
	preorder_display(root->right);
}

void level_order_display(NODE *root)
{
		NODE *ptr;
		ptr=root;

		if(ptr==NULL)
		{
			return;
		}

		enque(ptr);
		
		while(1)
		{
			ptr=deque();
			
			if(ptr!=NULL)
			{
				printf("%d ",ptr->data);


				if(ptr->left!=NULL)
				{
					enque(ptr->left);
				}

				if(ptr->right!=NULL)
				{
					enque(ptr->right);
				}
			}

			else
			{
				r=-1,f=-1;
				break;
			}

		}
}


NODE *search_node(NODE *root,int data)
{	NODE *temp=root;
	NODE *temp2;

	while(1)
	{	
		if(temp==NULL)
		{
			return NULL;
		}

		if(temp->data==data)
		{
			return temp2;
		}

		if(temp->data>data)
		{	temp2=temp;
			
			temp=temp->left;
		}
		
	    /*   	if(temp->left->data==data||temp->right->data==data)
                {
                        return temp;
                }*/


		else
		{	temp2=temp;
			temp=temp->right;
		}
	}

}

NODE *delete_node(NODE *root)
{	
	int data;
	NODE *temp,*parent,*ntemp;
	if(root==NULL)
	{
		printf("no element in tree, first insert");
		return NULL;
	}


	printf("\nenter the data You wantr to delete\n");
	scanf("%d",&data);

	if(root->left==NULL&&root->right==NULL)
	{
		if(root->data!=data){
			printf("\ndata you want to delete is not present in the tree \ntry another one!\n");
			return root;
		}
	}



	if(root->data==data)
	{
		temp=root;

		if(root->left==NULL&&root->right==NULL)
		{
			free(temp);

			printf("\nnode is deleted successfully\n");

			return NULL;

		}


		if(root->left==NULL)
		{	
			root=root->right;

			free(temp);
	      
			printf("\nnode is deleted successfully\n");
	
			return root;
		
		}


		if(root->right==NULL)
		{
			root=root->left;
	
			free(temp);

			printf("\nnode is deleted successfully\n");

			return root;
		}


		ntemp=temp->left;
		root=root->left;

		while(ntemp->right!=NULL)
		{
			ntemp=ntemp->right;
		}

		ntemp->right=temp->right;
		
		free(temp);

		printf("\nnode is deleted successfully\n");

		return root;
	}
		
			


	temp=search_node(root,data);
	
	if(temp==NULL)
	{

		printf("\nthe element you want to delete is not present in the tree.\n try another one. \n thank you.\n");
			return root;
	}

	if(temp->left!=NULL){

		if(temp->left->data==data)
	
			{	
	
			parent=temp;
	
			temp=temp->left;

			if(temp->left==NULL&&temp->right==NULL)
			{
				parent->left=NULL;
			
				free(temp);

				return root;
			}


			if(temp->left==NULL)
			{
				parent->left=temp->right;
			
				free(temp);
	
				 printf("\nnode is deleted successfully\n");

				return root;
			}


			ntemp=temp->left;

			parent->left = ntemp;

			while(ntemp->right!=NULL)
			{
				ntemp=ntemp->right;
			}

			ntemp->right=temp->right;

			free(temp);

			printf("\nnode is deleted successfully\n");

			return root;

		}
	}

	if(temp->right!=NULL){

		if(temp->right->data==data)
		{
			parent=temp;

			temp=temp->right;

			 if(temp->left==NULL&&temp->right==NULL)
              		  {
                      		  parent->right=NULL;

                       		 free(temp);
			
                      		  return root;
           		     }



			if(temp->left==NULL)
			{
				parent->right=temp->right;
	
				free(temp);
	
				return root;
			}

	
			 ntemp=temp->left;

                	parent->right = ntemp;
	
        	        while(ntemp->right!=NULL)
               		 {
                       	
				 ntemp=ntemp->right;
               		 }

			if(temp->right==NULL)
			{
				free(temp);
				return root;
			
			}
		

        	        ntemp->right=temp->right;
                
			free(temp);

			printf("\nnode is deleted successfully\n");

			return root;
		
		}
	}

}

void main(){
	int data,ch;
	NODE*root=NULL;
	while(1){
		printf("\nchoices you have\n1.insert new data\n2.inorder display\n3.postorder\n4.preorder\n5.level order display\n6.delete node\n7.search data\n 8. exit\n");
		printf("\nenter the number of operation you want to perform\n");
		scanf("%d",&ch);

		if(ch==8){
			return;
		}
		switch(ch){
			case 1 :
				printf("\nenter the data you want to insert\n");

				scanf("%d",&data);

				root=insert(root,data);

				printf("it is perfectly inserted\n");

				break;


			case 2 :

				inorder_display(root);

				break;

			case 3 :
				postorder_display(root);

				break;


			case 4 :
				preorder_display(root);

				break;

			case 5 :
				level_order_display(root);

				break;


			case 6 :
				root=delete_node(root);
				break;

			case 7 :
				printf("enter the data you want to search ");
				scanf("%d",&data);
				search_node(root,data);
				break;

			default :
				printf("\nenter the valid option\n");
				
				break;
		}
	}
}
