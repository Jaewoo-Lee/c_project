#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode														 //����Ʈ�� ���� ����
{
	char data[10];															 //������ �κ�
	struct listnode* llink;													 //left ��ũ
	struct listnode* rlink;													 //right ��ũ

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
void llink_print(head*);													 //����Ʈ ���� ��� �Լ�
node* search(head*, char[]);												 //��� ã�� �Լ�
void insertc(head*, char[], char[]);							   			 //���ϴ� ���� ��� �߰� �Լ�


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
		add -> llink = NULL;
		add -> rlink = pre;													//add�� pre�� ��(NULL)�� ����Ű�� �Ѵ�.
		return;
	}																		
	if(L->head ->rlink == NULL)												//L�� ��尡 �ϳ����
	{
		pre = L->head->rlink;												//pre�� L�� ù ��尡 ����Ű�� �� = NULL
		L -> head -> rlink= add;												//L�� ù ��尡 add�� ����Ű�� �ϰ�
		add ->llink = L -> head;
		add -> rlink = pre;													//add�� NULL�� ����Ű�� �Ѵ�.
		return;
	}
	else																	//L�� ��尡 2�� �̻��̸�
	{
		pre = L->head->rlink;
		add->rlink = pre;											//add�� ����Ű�� ���� L�� �ι�° ���
		L ->head->rlink = add;												//L�� ù���� ���� add�� ����Ų��.
		add -> llink = L->head;
		pre -> llink = add;
	}
}

void insertend(head* L, char* x)											//����Ʈ�� �������� ��带 �߰��ϱ�
{
	node* p;																//p�� add ����
	node* add;
	
	p = L->head;																//p�� L�� head
	add = (node*)malloc(sizeof(node));										//add ũ�� �Ҵ�
	strcpy(add -> data, x);													//add�� ������ �Է�
	
	while (p->rlink != NULL)													//p�� ����Ʈ�� �� ��带 ����ų������
	{
		p = p->rlink;														//p�� ����
	}

	add -> rlink = NULL;														//add�� ����� ���������� �����ϰ�
	p -> rlink = add;												//L�� ������ ��尡 add�� ����Ű�� ����
	add -> llink = p;
}

void reverse(head* L)														//��� ���� ������ �Լ�
{
	node* p;																
	node* q;																
	node* r;																

	p = L -> head; 
	q = NULL;
	r = NULL;

	while (p != NULL)
	{												
		r = q;
		q = p;
		p = p -> rlink;
		q -> rlink = r;
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
		p = p -> rlink;
		if(p != NULL)
			printf(", ");
	}
	printf(")\n");
}

void llink_print(head* L)															//llink�� �̿��� ����Ʈ�� ����ϴ� �Լ�
{
	node* p = NULL;																	//reverse�Լ����� llink�� �ٲ����� �ʾұ� ������
	printf("L = (");
	p = L -> head;																	//p�� reverse �� L�� head�� ���¿��� ����� �����Ͽ�
	while(p != NULL)
	{																				//[�� �� �� ��]�� ������ �ö�� �� �ִ�.
		printf("%s", p -> data);
		p = p -> llink;
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
			 
			temp = temp -> rlink;
			
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
	
	pre->rlink = temp->rlink;
	pre->llink = temp;
	temp->rlink = pre;
	pre->rlink->llink=pre;
	
}


int main()
{
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

	printf("(6) ���±��� printf�� rlink�� ����߰�,\nllink�� �� ����ƴ��� llink�� ����غ���! \n");
	llink_print(L); 
	getchar();

	return 0;
}