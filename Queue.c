#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define size 5

typedef char element;

typedef struct
{
	int front;
	int rear;
	element queue[size];
}Queue;

Queue* create();
int empty(Queue*);
int full(Queue*);
void enQueue(Queue*, element);
element deQueue(Queue*);
void delete(Queue*);
element peek(Queue*);
void print(Queue*);

Queue* create(void)
{
	Queue* Q;
	Q = (Queue*)malloc(sizeof(Queue));

	Q->front = -1;
	Q->rear = -1;

	return Q;
}

int empty(Queue* Q)
{
	if (Q->front == Q->rear)
		return 1;
	else
		return 0;
}

int full(Queue* Q)
{
	if (Q->rear == size-1)
		return 1;
	else
		return 0;
}

void enQueue(Queue* Q, element x)
{
	if (full(Q) == 1)
		return 1;
	else
	{
		Q->rear++;
		Q->queue[Q->rear] = x;
		return 0;
	}
}

element deQueue(Queue* Q)
{
	if (empty(Q) == 1)
		return 1;
	else
	{
		Q->front++;
		return Q->queue[Q->front];
	}
}

void delete(Queue* Q)
{
	if (empty(Q) == 1)
		return 1;
	else
	{
		Q->front++;
		return 0;
	}
}

element peek(Queue* Q)
{
	if (empty(Q) == 1)
		return 1;
	else
		return Q->queue[Q->front];
}
void print(Queue* Q)
{
	int i;
	printf("Q = (");
	while (!empty(Q))
	{
		printf("%c", deQueue(Q));
		if (!empty(Q))
			printf(", ");
	}
	printf(")");
}

void main()
{
	char a;
	Queue* Q;

	Q = create();

	enQueue(Q, 'A');
	//print(Q);
	//getchar();
	enQueue(Q, 'B');
	//print(Q);
	//getchar();
	enQueue(Q, 'C');
	print(Q);
	getchar();

	printf("%c", peek(Q));
	getchar();

	delete(Q);
	print(Q);
	getchar();

	return 0;
}