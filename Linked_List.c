#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
	char data[10];
	struct list* link;
}list;

typedef struct
{
	list* head;	
}head;

head* mblank();
void insertf(head*, char*);
void inserta(head*, char*);
void insertc(head*, char*, char*);
void delete(head*, char*);
void print(head*);
void reverse(head*);

head* mblank()
{
	head* L;
	L = (head*)malloc(sizeof(head));

	L->head = NULL;

	return L;
}

void insertf(head* L, char* x)
{
	list* temp;
	list* add;
	add = (list*)malloc(sizeof(list));
	temp = L->head;

	strcpy(add->data, x);

	add->link = temp;
	L->head = add;

	return;
}

void inserta(head* L, char* x)
{
	list* temp;
	list* add;
	add = (list*)malloc(sizeof(list));
	temp = L->head;

	strcpy(add->data, x);

	while (temp->link != NULL)
		temp = temp->link;

	add->link = NULL;
	temp->link = add;

	return;
}

void insertc(head* L, char* x, char* y)
{
	list* temp;
	list* add;
	add = (list*)malloc(sizeof(list));
	temp = L->head;

	strcpy(add->data, x);

	while (strcmp(y, temp->data)!= 0)
		temp = temp->link;

	add->link = temp->link;
	temp->link = add;

	return;
}

void delete(head* L, char* x)
{
	list* temp1;
	list* temp2;

	temp1 = L->head;
	temp2 = temp1->link;

	while (strcmp(x, temp2->data))
	{
		temp1 = temp2;
		temp2 = temp2->link;
	}

	temp1->link = temp2->link;

	return;
}

void print(head* L)
{
	list* temp;
	temp = L->head;

	printf("L =(");

	while (temp != NULL)
	{
		printf("%s", temp->data);
		temp = temp->link;
		if (temp != NULL)
			printf(", ");
	}
	printf(")\n");
}

void reverse(head* L)
{
	list* p;
	list* q;
	list* r;

	p = L->head;
	q = NULL;
	r = NULL;

	while (p != NULL)
	{
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}

	L->head = q;

	return;
}

void main()
{
	head* L;
	char a[4], b[4], c[4];

	L = mblank();

	print(L);

	insertf(L, "¼ö");
	inserta(L, "±Ý");
	insertf(L, "¿ù");

	print(L);

	reverse(L);
	print(L);

	scanf("%s", &a);
	scanf("%s", &b);

	insertc(L, a, b);

	print(L);

	scanf("%s", &c);
	delete(L, c);
	print(L);

	return 0;
}