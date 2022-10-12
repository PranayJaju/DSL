#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"cSTACK.h"
int i, j;

int main()
{
	char prefix_exp[50];
	printf("Enter prefix expression.\n");
	fgets(prefix_exp, 50, stdin);
	prefix_exp[strlen(prefix_exp)-1]='\0';

	Stack* s=(Stack*)malloc(sizeof(Stack));
	s->stack=(char*)calloc(75, sizeof(char));
    s->top=-1;
    s->size=75;

    i=strlen(prefix_exp)-1;
    char ch, op1, op2; int res;
    while(i>=0)
    {
        ch=prefix_exp[i];
        if(ch!='+'||ch!='-'||ch!='*'||ch!='/'||ch!='^')
        	push(s, ch);
        else
        {
        	op1=pop(s);
        	op2=pop(s);
        	switch(ch)
        	{
        		case '+': res=op1+op2;
        		break;
        		case '-': res=op1-op2;
        		break;
        		case '*': res=op1*op2;
        		break;
        		case '/': res=op1/op2;
        		break;
        		case '^': res=op1^op2;
        		break;
        	}
        	push(s, (char)res);
        }
    }

    printf("Result: %c", s->stack[s->top]);
}