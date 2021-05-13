#include<stdio.h>
#include<stdlib.h>
#define bool int

typedef char EleType;
typedef struct List
{
	EleType data;
	struct List* front;
	struct List* next;
}LIST,*PLIST;	

typedef struct Stack
{
	int Stack_len;
	PLIST rsp;
	PLIST s;
}Stack;


Stack* create_Stack(int);
void push(Stack*, EleType);
void pop_A(Stack*, EleType*);
void pop_B(Stack*);
bool Is_Empty(Stack*);
bool Is_Full(Stack*);
void traversal_Stack(Stack*);

int main(void)
{
	Stack* pst = create_Stack(10);
	push(pst, 'A');
	push(pst, 'A');
	push(pst, 'A');
	push(pst, 'A');
	pop_B(pst);

	traversal_Stack(pst);

	return 0;
}

Stack* create_Stack(int len)
{
	Stack* pst = (Stack*)malloc(sizeof(Stack));
	if (!pst)
		return 0;
	pst->Stack_len = len;
	
	PLIST p;
	PLIST head = (PLIST)malloc(sizeof(LIST));
	if (!head)
		return NULL;
	head->front = head->next = NULL;
	p = head;
	len += 1;
	while (len)
	{
		PLIST pNew = (PLIST)malloc(sizeof(LIST));
		if (!pNew)
			return NULL;
		pNew->front = p;
		pNew->next = NULL;
		p->next = pNew;
		p = pNew;
		len--;
	}

	pst->s = head;
	pst->rsp = head->next;

	return pst;
}

void push(Stack *pst, EleType val)
{
	if ( Is_Full(pst) )
	{
        PLIST pNew = (PLIST)malloc(sizeof(LIST));
		if (!pNew)
			exit(-1);
		pNew->front = pst->rsp;
		pNew->next = NULL;
		pst->rsp->data = val;
		pst->rsp->next = pNew;
		pst->rsp = pNew;
	}
	else
	{
		pst->rsp->data = val;
		pst->rsp = pst->rsp->next;
	}
	return;
}

void pop_A(Stack* pst, EleType* get)
{
	if (Is_Empty(pst))
	{
		printf("Empty_Stack!\n");
		return;
	}

	*get = pst->rsp->data;
	pst->rsp = pst->rsp->front;
	return;
}

void pop_B(Stack* pst)
{
	if (Is_Empty(pst))
	{
		printf("Empty_Stack!\n");
		return;
	}

	pst->rsp = pst->rsp->front;
	return;
}

bool Is_Empty(Stack *pst)
{
	if (pst->s->next == pst->rsp)
		return 1;
	else
		return 0;
}

bool Is_Full(Stack* pst)
{
	if (pst->rsp->next == NULL)
		return 1;
	else
		return 0;

}

void traversal_Stack(Stack *pst)
{
	PLIST p = pst->s->next;
	while (p != pst->rsp)
	{
		printf("%c\n", p->data);
		p = p->next;
	}
	return;
}