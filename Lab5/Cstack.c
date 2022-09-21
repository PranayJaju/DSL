#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    char* stack;
    int top;
    int size;
}Stack;

int isFull(Stack *s)
{
    return s->top==s->size-1;
}

int isEmpty(Stack *s)
{
	return s->top==-1;
}

void push(Stack *s, char x)
{
	if(isFull(s))
	    printf("---Stack Overflow---\nElement cannot be added.\n");
	else
        s->stack[++(s->top)]=x;
}

char pop(Stack *s)
{
	if(isEmpty(s))
	    printf("---Stack Underflow---\nNo element to be popped.\n");
	else
	    return s->stack[(s->top)--];    
}

void display(Stack *s)
{
	if(isEmpty(s))
	    printf("Stack is empty.\n");
	else
	{
	    for(int i=s->top; i>=0; i--)
	    {
	    	printf("%c", s->stack[i]);
	    	printf("\n");
	    }
	}    
}

void main()
{
	int n;
	printf("Enter stack size.\n");
    scanf("%d", &n);
    Stack *s;
    s->size=n;
    s->top=-1;
    s->stack[s->size];
    int action;
    do
    {
        printf("Enter action:\n1.Push\n2.Pop\n3.Display\n4.Exit.\n");
        scanf("%d", &action);
        if(action==1)
        {
            char ele;
            printf("Enter element to be pushed:\n");
            scanf("\n%c", &ele);
            push(s, ele);
        }
        else if(action==2)
        {
            printf("Popped element: %c\n", pop(s));
        }
        else if(action==3)
        {
            printf("The stack is:\n");
            display(s);
        }
        else
        {
        	printf("The stack is:\n");
            display(s);
            printf("EXITING...\n");
        }
    }while(action!=4);
}