#include<stdio.h>
#include<stdlib.h>
#define bool int

typedef char EleType;
typedef struct Stack
{
	int rsp;
	int Stack_len;
	EleType* s;
}Stack;

Stack* create_Stack(int );
void push(Stack*,EleType);
void pop_A(Stack*,EleType*);
void pop_B(Stack*);
bool Is_Full(Stack*);
bool Is_Empty(Stack*);


int main(void)
{
	int i;
	Stack *pst=create_Stack(10);
	
	push(pst, 'A');
	push(pst, 'A');
	push(pst, 'A');

	char kl;
	pop_A(pst, &kl);


	for (i = 0; i < pst->rsp; i++)
		printf("%c\n", pst->s[i]);
	putchar(kl);

	return 0;
}

Stack* create_Stack(int len)
{
	Stack *pst=(Stack*)malloc(sizeof(Stack));
	if (!pst)
		return NULL;
	pst->rsp = 0;
	pst->Stack_len = len;
	pst->s = (EleType*)malloc(sizeof(EleType) * (len+1));
	if (!pst->s)
		return NULL;
	return pst;
}

void push(Stack *pst,EleType val)
{
	if (Is_Full(pst))
	{
		printf("Stack_Overflow!\n");
		return;
	}
	pst->s[(pst->rsp)++] = val;
	return;
}

void pop_A(Stack *pst, EleType *get)
{
	if (Is_Empty(pst))
	{
		printf("Empty_Stack!\n");
		return;
	}
	*get = pst->s[(pst->rsp)--];
	return;
}

void pop_B(Stack *pst)
{
	if (Is_Empty(pst))
	{
		printf("Empty_Stack!\n");
		return;
	}
	(pst->rsp)--;
	return;
}

bool Is_Full(Stack *pst)
{
	if (pst->rsp >= pst->Stack_len)
		return 1;
	else
		return 0;
}

bool Is_Empty(Stack *pst)
{
	if (pst->rsp == 0)
		return 1;
	else
		return 0;
}