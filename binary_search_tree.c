#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node *left;
	struct node *right;
	};
typedef struct node NODE;
NODE* getnode()
{
	NODE *newnode;
	newnode=(NODE*)malloc(sizeof(NODE));
	if(newnode==NULL)
	{
		printf("there is no space for a new node\n");
		return 0;
	}
	newnode->left=NULL;
	newnode->right=NULL;
	printf("enter a key element to newnode\n");
	scanf("%d",&newnode->key);
	return newnode;
}
NODE *root=NULL;
//code for implimentation of tree without recursion.
/*
void insertnode()
{
	NODE* child,*cur_root;
	cur_root=root;
	child=getnode();

	if(root==NULL)
	{
		root=child;
	}
	else
	{
	while(cur_root!=NULL){
		if(child->key>cur_root->key)
		{	if( cur_root->right==NULL){
				cur_root->right=child;
				return;}
			else
				cur_root=cur_root->right;
		}
		else if(child->key<cur_root->key)
		{
			if(cur_root->left==NULL){
				root->left=child;
				return;}
			else
				 cur_root=cur_root->left;

		}
		else
		{
			printf("not possible!");
		}
		}

	}
	return;

}*/
// implimentation of binary search tree using recursion.
void insertnode(NODE *child, NODE *root)
{
	if(child->key>root->key)
	{
		if(root->right==NULL){
			root->right=child;
			return;}
		insertnode(child,root->right);
	}
	else if(child->key<root->key)
	{
		if(root->left==NULL)
		{
			root->left=child;
			return;
		}
		insertnode(child,root->left);
	}
	else
	{
		printf("not possible!\n");
		return;
	}
}
//tree methods of traversing a binary search tree.
void preorder(NODE* Root)
{
	if(Root==NULL)
	{
		return;
	}
	printf("%d ",Root->key);
	preorder(Root->left);
	preorder(Root->right);
}
void inorder(NODE *Root)
{
	if(Root==NULL)
		return;
	inorder(Root->left);
	printf("%d ",Root->key);
	inorder(Root->right);
}
void postorder(NODE *Root)
{
	if(Root==NULL)
		return;
	postorder(Root->left);
        postorder(Root->right);
	printf("%d  ",Root->key);
}
void main()
{
	int choice;
	do{
	printf("enter your choice\n ");
	printf("1. for insert a node\n 2. for preorder\n 3.inorder\n 4. postorder\n 5. exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
		case 1:
			{
				NODE* child,*cur_root;
			        cur_root=root;
        			child=getnode();

        			if(root==NULL)
        			{
                			root=child;
        			}
				else
				insertnode(child,root);
				break;
			}
		case 2:
			{
				preorder(root);
				break;
			}
		case 3:
			{
				inorder(root);
				break;
			}
		case 4:
			{
				postorder(root);
				break;
			}
	}
	}while(choice<=4&&choice>=1);
}
