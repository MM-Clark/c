#include <stdio.h>
#include <stdlib.h>
# define SIZE 100
void push();
void pop();
void print();
void peek();
int stack[SIZE];
int top = -1;
main()
{
	int ch;
	while(1)
	{
		printf("1.Push Operation\n");
		printf("2.Pop\n");
		printf("3.Peek\n");
		printf("4.Print\n");
		printf("5.Exit\n");
		printf("enter your choice of operations : ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:
				push();
				break;
			case 2: 
				pop();
				break;
			case 3: 
				peek();
				break;
			case 4:
				print();
				break;
			case 5:
				exit(0);
				break;
			default:
				printf("Bad input\n");
		}		
	}
}

void push()
{
	int insert; 
	if(top >= SIZE - 1)
		printf("Overflow \n");
	else
	{
		printf("Element to be pushed: \n");
		scanf("%d", &insert);
		top = top + 1;
		stack[top] = insert;
	}	
}

void pop()
{
	if(top < 0)
	{
		printf("Underflow \n");
		return;
	}
	else
	{
		printf("Element popped: %d\n",stack[top]);
	       	top = top - 1;	
	}	
}

void peek()
{
	if(top <0)
		printf("empty stack\n");
	else
		printf("Head element: %d\n",stack[top]);
}

void print()
{
	if(top <0)
		printf("Empty stack\n");
	else
	{
		printf("Stack: \n");
		for(int i=top;i>=0;--i)
			printf("%d ", stack[i]);
		printf("\n");
	}
}
