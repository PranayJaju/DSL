#include<stdio.h>
#include<stdlib.h>
#include"BTStack.h"

//typedef struct btNode
//{
//	int data;
//	struct btNode* left;
//	struct btNode* right;
//}btNode;

btNode* create()
{
	btNode* p;
	int x;
	printf("Enter data.(-1 for no data): ");
	scanf("%d", &x);
	if(x==-1) return NULL;
	p=(btNode*)malloc(sizeof(btNode));
	p->data=x;

	printf("Enter left child of %d:\n", x);
	p->left=create();
	printf("Enter right child of %d:\n", x);
	p->right=create();

	return p;
}

void Preorder(btNode* root)
{
	btNode* current;
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;
    push(s,root);

    while(!isEmpty(s))
    {
    	current=pop(s);
    	printf("%d  ", current->data);
    	if(current->right!=NULL) push(s, current->right);
    	if(current->left!=NULL) push(s, current->left);
    }
}

void Inorder(btNode* root)
{
	btNode* current=root;
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;

	while(!isEmpty(s) || current!=NULL)
	{
		if(current!=NULL)
		{
			push(s, current);
			current=current->left;
		}
		else
		{
			current=pop(s);
			printf("%d  ", current->data);
			current=current->right;
		}
	}
}

void Postorder(btNode* root)
{
	btNode* current=root;
	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->top=-1;	

	
}

int main()
{
	btNode* root=NULL;
	root=create();
	printf("Preorder traversal: ");
	Preorder(root);
	printf("\nInorder traversal: ");
	Inorder(root);
}