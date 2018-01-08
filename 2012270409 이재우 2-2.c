#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode														 //����Ʈ�� ���� ����
{
	char data[10];															 //������ �κ�
	struct listnode* link;													 //��ũ �κ�

} node;																		 //�� ����ü�� node��� ���

typedef struct																 //head ����� ���� ����
{
	node* head;									    						 //���� �����Ͱ� �Էµ� head�κ�
} head;																	     //�̰��� head��� ���

//����� �Լ� ���� ����
head* mblank(void)  ;														 //���鸮��Ʈ �����
void mlist(head*);
void insert(head*, char*);													 //������ �߰� �Լ�
void insertend(head*, char*);												 //����Ʈ ���� ��� �߰�
void reverse(head*);														 //������ ���� �Լ�
void print(head*);				    										 //����Ʈ ��� �Լ�
node* search(head*, char[]);
void insertc(head*, char[], char[]);


//�Լ� �����Է�
head* mblank(void)															 //���鸮��Ʈ �����
{
	head* L;																 //L�� �����ϰ�
	L=(head*)malloc(sizeof(head));											 //L�� ũ�⸦ �����ϰ�
	L->head = NULL;															 //L�� ���� ����ֱ�

	return L;																 //����� L 
}



void insert(head* L, char* x)												//������ ���� �Լ�
{
	node* add;																//add��� ���ο� ����Ʈ�� �����ϰ�
	node* pre;																//pre ����
	add = (node*)malloc(sizeof(node));										//add�� ũ�� ����
	strcpy(add -> data, x);													//add�� ������ �κп� x�� �־��ְ�

	if (L->head == NULL)														//L�� ���� ����Ʈ���
	{
		pre = L->head;														//pre�� L�� head�� �Է�
		L->head = add;														//L�� add�� ����Ű��
		add -> link = pre;													//add�� pre�� ��(NULL)�� ����Ű�� �Ѵ�.
		return;
	}																		
	if(L->head ->link == NULL)												//L�� ��尡 �ϳ����
	{
		pre = L->head->link;													//pre�� L�� ù ��尡 ����Ű�� �� = NULL
		L->head ->link= add;													//L�� ù ��尡 add�� ����Ű�� �ϰ�
		add -> link = pre;													//add�� NULL�� ����Ű�� �Ѵ�.
		return;
	}
	else																	//L�� ��尡 2�� �̻��̸�
	{
		add->link = L -> head->link;											//add�� ����Ű�� ���� L�� �ι�° ���
		L ->head->link = add;												//L�� ù���� ���� add�� ����Ų��.
	
	}
}

void insertend(head* L, char* x)											//����Ʈ�� �������� ��带 �߰��ϱ�
{
	node* p;																//p�� add ����
	node* add;
	
	p = L->head;																//p�� L�� head
	add = (node*)malloc(sizeof(node));										//add ũ�� �Ҵ�
	strcpy(add -> data, x);													//add�� ������ �Է�
	
	if (p->link->link != NULL)												//p�� ����Ʈ�� ������ �ι�° ��带 ����ų������
	{
		p = p->link;															//p�� ����
	}

	add->link = NULL;														//add�� ����� ���������� �����ϰ�
	p->link->link = add;														//L�� ������ ��尡 add�� ����Ű�� ����
}

void reverse(head* L)														//��� ���� ������ �Լ�
{
	node* p;																//������ ���� �����鼭 ���ش� �Ǵµ�
	node* q;																//�Լ��� ������ �ʹ� �������
	node* r;																//å�� �ִ� �Լ� Ȱ��

	p = L -> head;
	q = NULL;
	r = NULL;

	while (p != NULL)
	{												
		r = q;
		q = p;
		p = p -> link;
		q -> link = r;
	}

	L->head = q;

}

void print(head* L)															//����Ʈ ����ϴ� �Լ�
{
	node* p = NULL;
	printf("L = (");
	p = L -> head;
	while(p != NULL)
	{
		printf("%s", p -> data);
		p = p -> link;
		if(p != NULL)
			printf(", ");
	}
	printf(")\n");
}

node* search(head* L, char y[4])					
{
	node* temp;										
	temp = L->head;
	if(temp != NULL)								
	{
		while (strcmp(temp->data, y) != 0)			
		{
			
			temp=temp->link;
			
		}
		return temp;
										

	}												
		
}													
void insertc(head* L, char x[4], char y[4])			
{
	node* pre;										
	node* temp;
	temp = search(L, y);							
	
													
	pre = (node*)malloc(sizeof(node));  
	strcpy_s(pre -> data, strlen(pre->data), x);
	
	pre->link = temp->link;
	temp->link = pre;
	
}




int main()
{
	char a[4],b[4];
	head* L;
	L = mblank();
	printf("(1) ���� ����Ʈ �����ϱ�! \n");
	print(L); 
	getchar();

	printf("(2) ����Ʈ�� 3���� ��� �߰��ϱ�! \n");
	insert(L, "��");														//<��>
	insert(L, "��");														//<�� ��>
	insert(L, "��");														//<�� �� ��>
	print(L); 
	printf("å�� �ִ� �Լ��� �ٸ� �Լ��� ����Ѱ��� ��Ÿ���� ����\n");
	printf("�Ϻη� ���� Ʋ���� ��������ϴ�. ���� �ƴմϴ�.\n");
	getchar();

	printf("(3) ����Ʈ �������� ��� �Ѱ� �߰��ϱ�! \n");
	insertend(L, "��");
	print(L); 
	getchar();

	
	printf("(4) ���ϴ� �ڸ��� ��� �߰��ϱ�! \n");
	
	printf("���� �� ��� ���� �����ʿ� �߰��ұ��?: ");
	print(L);
	scanf("\n%s",&b);
	
	printf("�߰��ϰ� ���� ������ �Է��ϼ���: ");
	scanf("%s",&a);
	
	insertc(L, a, b);
	print(L); 
	getchar();


	printf("(5) ����Ʈ ���Ҹ� �������� ��ȯ�ϱ�! \n");
	reverse(L);
	print(L); 
	getchar();

	return 0;
}