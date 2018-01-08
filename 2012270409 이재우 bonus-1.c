#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char element;
char postfix[30];

typedef struct stack{
	element data;
	struct stack *link;
}stack;

stack* top;

void push(element item)
{
	stack* temp = (stack*)malloc(sizeof(stack));
	temp -> data = item;
	temp -> link = top;
	top = temp;
}

element pop()
{
	element item;
	stack* temp = top;

	if (top == NULL)
	{
		printf("\n Stack Is Empty!\n");
		return 0;
	}

	else
	{
		item = temp -> data;
		top = temp -> link;
		free(temp);
		return item;
	}
}

element peek()
{
	element item;
	if (top == NULL)
	{
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else 
	{
		item = top -> data;
		return item;
	}
}

void del()
{
	stack* temp;
	if (top == NULL)
	{
		printf("\n\n Stack is empty!");
	}
	else
	{
		temp = top;
		top = top -> link;
		free(temp);
	}
}

void printStack()
{
	stack* p = top;
	printf("\n STACK [ ");
	while (p)
	{
		printf("%d ", p -> data);
		p = p -> link;
	}
	printf("] ");
}

int test(char *exp)
{
	char symbol, open;
	int i, length = strlen(exp);
	top = NULL;

	for (i = 0; i < length; i++){
		symbol = exp[i];
		switch (symbol)
		{			
			case '(':
			case '[':
			case '{':
				push(symbol); break;
			case ')':
			case ']':
			case '}':
			if (top == NULL) 
				return 0;
			else
			{
				open = pop();
				if ((open == '(' && symbol != ')') || (open == '[' && symbol != ']') || (open == '{' && symbol != '}'))
					return 0;
				else break;
			}
		}
	}
	if (top == NULL) 
		return 1;
	else 
		return 0;
}

void i_to_p(char *exp)
{
	char symbol;
	int i, j = 0;
	int length = strlen(exp);
	top = NULL;
	for (i = 0; i < length; i++){
		symbol = exp[i];
		switch (symbol)
		{
			case '+':
			case '-':
			case '*':
			case '/':
			case '(':
			case ')':			
			if (top == NULL){
				push(symbol); break;
			}
			else if (symbol == '+' || symbol == '-'){	
				while ((top != NULL) && (top->data != '('))
					postfix[j++] = pop();
				push(symbol); break;
			}
			else if (symbol == '*' || symbol == '/'){	
				if ((top->data == '*') || (top->data == '/'))
				{
					while ((top != NULL) && (top->data != '('))
						postfix[j++] = pop();
					push(symbol); break;
				}
				else
					push(symbol); break;
			}
			else if (symbol == ')'){				
				while (top->data != '(') postfix[j++] = pop();
				pop(); break;
			}
			else if (symbol == '('){				
				push(symbol); break;
			}
		default:
			postfix[j++] = symbol;					
		}
	}

	while (top != NULL)		
	{
		postfix[j++] = pop();
	}
	postfix[j] = '\0';	
	return;
}

element evalPostfix(char *exp)
{
	int opr1, opr2, value, i = 0;
	int length = strlen(exp);
	char symbol;
	top = NULL;

	for (i = 0; i < length; i++){
		symbol = exp[i];
		if (symbol != '+' && symbol != '-' && symbol != '*' && symbol != '/'){
			value = symbol - '0';
			push(value);
		}
		else{
			opr2 = pop();
			opr1 = pop();
			switch (symbol){
			case '+': push(opr1 + opr2); break;
			case '-': push(opr1 - opr2); break;
			case '*': push(opr1 * opr2); break;
			case '/': push(opr1 / opr2); break;
			}
		}
	}
	return pop();
}
void main(void)
{
	int result;
	char* express = "(7+5)/(2*3)-9";  
	printf("\tÀÔ·ÂµÈ ¼ö½Ä = %s", express);
	
	if (test(express) == 1)		
		printf("\n-----------°ýÈ£ ¸ÅÄª OK!-----------\n");
	else
	{
		printf("\n-----------Error! °ýÈ£ ¸ÅÄª Fail!-----------\n\n");
		exit(1); 	
	}
	printf("\n\n    PostFix :  ");	
	i_to_p(express);
	printf("%s", postfix);

	result = evalPostfix(postfix);		
	printf("\n\n    ¿¬»ê°á°ú  =  %d", result);

	printf("\n\n");
	exit(0);
}