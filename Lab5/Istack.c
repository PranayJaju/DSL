#include<stdio.h>
#include<stdlib.h>

int top=-1;

int isFull(int n)
{
	if(top==n-1)
	return 1;
	return 0;
}

int isEmpty()
{
	if(top==-1)
	return 1;
	return 0;
}

void push(int stack[], int n, int x)
{
	if(isFull(n))
	    printf("---Stack Overflow---\nElement cannot be added.\n");
	else
        stack[++top]=x;
}

int pop(int stack[])
{
	if(isEmpty())
	    printf("---Stack Underflow---\nNo element to be popped.\n");
	else
	    return stack[top--];    
}

void display(int stack[])
{
	if(isEmpty())
	    printf("Stack is empty.\n");
	else
	{
	    for(int i=top; i>=0; i--)
	    	printf("%d", stack[i]);
	}    
}

void main()
{
	int stack[15], decimal;
	printf("Enter decimal number.\n");
	scanf("%d", &decimal);
	int dec=decimal;
	while(dec>0)
	{
		int r=dec%2;
		dec/=2;
		push(stack, 15, r);
	}
	printf("Binary of %d is: ", decimal);
	display(stack);
	printf("\n");
}