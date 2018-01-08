#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct listnode														 //리스트의 구조 정의
{
	char data[10];															 //데이터 부분
	struct listnode* llink;													 //left 링크
	struct listnode* rlink;													 //right 링크

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
void llink_print(head*);													 //리스트 역순 출력 함수
node* search(head*, char[]);												 //노드 찾기 함수
void insertc(head*, char[], char[]);							   			 //원하는 곳에 노드 추가 함수


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
		add -> llink = NULL;
		add -> rlink = pre;													//add는 pre의 값(NULL)을 가리키게 한다.
		return;
	}																		
	if(L->head ->rlink == NULL)												//L에 노드가 하나라면
	{
		pre = L->head->rlink;												//pre는 L의 첫 노드가 가리키는 곳 = NULL
		L -> head -> rlink= add;												//L의 첫 노드가 add를 가리키게 하고
		add ->llink = L -> head;
		add -> rlink = pre;													//add는 NULL을 가리키게 한다.
		return;
	}
	else																	//L에 노드가 2개 이상이면
	{
		pre = L->head->rlink;
		add->rlink = pre;											//add가 가리키는 곳은 L의 두번째 노드
		L ->head->rlink = add;												//L의 첫번쨰 노드는 add를 가리킨다.
		add -> llink = L->head;
		pre -> llink = add;
	}
}

void insertend(head* L, char* x)											//리스트의 마지막에 노드를 추가하기
{
	node* p;																//p와 add 생성
	node* add;
	
	p = L->head;																//p는 L의 head
	add = (node*)malloc(sizeof(node));										//add 크기 할당
	strcpy(add -> data, x);													//add에 데이터 입력
	
	while (p->rlink != NULL)													//p가 리스트의 끝 노드를 가리킬때까지
	{
		p = p->rlink;														//p를 전진
	}

	add -> rlink = NULL;														//add를 노드의 마지막으로 지정하고
	p -> rlink = add;												//L의 마지막 노드가 add를 가리키게 지정
	add -> llink = p;
}

void reverse(head* L)														//노드 순서 뒤집기 함수
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

void print(head* L)															//리스트 출력하는 함수
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

void llink_print(head* L)															//llink를 이용해 리스트를 출력하는 함수
{
	node* p = NULL;																	//reverse함수에서 llink는 바꿔주지 않았기 때문에
	printf("L = (");
	p = L -> head;																	//p가 reverse 된 L의 head인 상태에서 출력을 시작하여
	while(p != NULL)
	{																				//[일 수 금 월]의 순서로 올라올 수 있다.
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
	printf("(1) 공백 리스트 생성하기! \n");
	print(L); 
	getchar();

	printf("(2) 리스트에 3개의 노드 추가하기! \n");
	insert(L, "월");														//<월>
	insert(L, "수");														//<월 수>
	insert(L, "금");														//<월 금 수>
	print(L); 
	printf("책에 있는 함수와 다른 함수를 사용한것을 나타내기 위해\n");
	printf("일부러 순서 틀리게 만들었습니다. 오류 아닙니다.\n");
	getchar();

	printf("(3) 리스트 마지막에 노드 한개 추가하기! \n");
	insertend(L, "일");
	print(L); 
	getchar();


	printf("(4) 원하는 자리에 노드 추가하기! \n");
	
	printf("다음 중 어느 요일 오른쪽에 추가할까요?: ");
	print(L);
	scanf("\n%s",&b);
	
	printf("추가하고 싶은 요일을 입력하세요: ");
	scanf("%s",&a);
	
	insertc(L, a, b);
	print(L); 
	getchar();

	printf("(5) 리스트 원소를 역순으로 변환하기! \n");
	reverse(L);
	print(L); 
	getchar();

	printf("(6) 여태까지 printf는 rlink로 출력했고,\nllink가 잘 연결됐는지 llink로 출력해보기! \n");
	llink_print(L); 
	getchar();

	return 0;
}