#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode														 //리스트의 구조 정의
{
	char data[10];															 //데이터 부분
	struct listnode* link;													 //링크 부분

} node;																		 //이 구조체를 node라고 명명

typedef struct																 //head 노드의 구조 정의
{
	node* head;									    						 //실제 데이터가 입력될 head부분
} head;																	     //이것을 head라고 명명

//사용할 함수 원형 선언
head* mblank(void)  ;														 //공백리스트 만들기
void mlist(head*);
void insert(head*, char*);													 //데이터 추가 함수
void insertend(head*, char*);												 //리스트 끝에 노드 추가
void reverse(head*);														 //데이터 역순 함수
void print(head*);				    										 //리스트 출력 함수

//함수 연산입력
head* mblank(void)															 //공백리스트 만들기
{
	head* L;																 //L을 선언하고
	L=(head*)malloc(sizeof(head));											 //L의 크기를 지정하고
	L->head = NULL;															 //L에 값을 집어넣기

	return L;																 //결과는 L 
}



void insert(head* L, char* x)												//데이터 삽입 함수
{
	node* add;																//add라는 새로운 리스트를 생성하고
	node* pre;																//pre 생성
	add = (node*)malloc(sizeof(node));										//add에 크기 지정
	strcpy(add -> data, x);													//add의 데이터 부분에 x를 넣어주고

	if (L->head == NULL)														//L이 공백 리스트라면
	{
		pre = L->head;														//pre에 L의 head값 입력
		L->head = add;														//L는 add를 가리키고
		add -> link = pre;													//add는 pre의 값(NULL)을 가리키게 한다.
		return;
	}																		
	if(L->head ->link == NULL)												//L에 노드가 하나라면
	{
		pre = L->head->link;													//pre는 L의 첫 노드가 가리키는 곳 = NULL
		L->head ->link= add;													//L의 첫 노드가 add를 가리키게 하고
		add -> link = pre;													//add는 NULL을 가리키게 한다.
		return;
	}
	else																	//L에 노드가 2개 이상이면
	{
		add->link = L -> head->link;											//add가 가리키는 곳은 L의 두번째 노드
		L ->head->link = add;												//L의 첫번쨰 노드는 add를 가리킨다.
	
	}
}

void insertend(head* L, char* x)											//리스트의 마지막에 노드를 추가하기
{
	node* p;																//p와 add 생성
	node* add;
	
	p = L->head;																//p는 L의 head
	add = (node*)malloc(sizeof(node));										//add 크기 할당
	strcpy(add -> data, x);													//add에 데이터 입력
	
	if (p->link->link != NULL)												//p가 리스트의 끝에서 두번째 노드를 가리킬때까지
	{
		p = p->link;															//p를 전진
	}

	add->link = NULL;														//add를 노드의 마지막으로 지정하고
	p->link->link = add;														//L의 마지막 노드가 add를 가리키게 지정
}

void reverse(head* L)														//노드 순서 뒤집기 함수
{
	node* p;																//솔직히 보고 읽으면서 이해는 되는데
	node* q;																//함수를 만들기는 너무 어려워서
	node* r;																//책에 있는 함수 활용

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

void print(head* L)															//리스트 출력하는 함수
{
	node* p=NULL;
	printf("L = (");
	p = L->head;
	while(p != NULL)
	{
		printf("%s", p->data);
		p = p -> link;
		if(p != NULL)
			printf(", ");
	}
	printf(")\n");
}

int main()
{
	head* L;
	L = mblank();
	printf("(1) 공백 리스트 생성하기! \n");
	print(L); 
	getchar();

	printf("(2) 리스트에 3개의 노드 추가하기! \n");
	insert(L, "월");														//<월>
	insert(L, "수");														//<월 수>
	insert(L, "금");														//<월 금 수>
	print(L); 
	printf("책에 있는 함수 안쓰고 제가 만든 함수인거 티낼려고 일부러 순서 틀리게 했습니다. 오류 아닙니다");
	getchar();

	printf("(3) 리스트 마지막에 노드 한개 추가하기! \n");
	insertend(L, "일");
	print(L); 
	getchar();

	printf("(4) 리스트 원소를 역순으로 변환하기! \n");
	reverse(L);
	print(L); 
	getchar();

	return 0;
}