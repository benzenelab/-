#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 10
#define bool int

typedef int EleType;
typedef struct LIST
{
	EleType data;
	struct LIST* next;
	struct LIST* front;
}LIST, * PLIST;

typedef struct Queue
{
	PLIST rear;
	PLIST front;
	PLIST Qu;
	PLIST Last_Node;
}Queue;

Queue* creat_Queue(void);
void En_Queue(Queue*, EleType);
void De_Queue(Queue*);
bool Is_Full(Queue*);
bool Is_Empty(Queue*);
void traversal_Queue(Queue*);

int main(void)
{
	Queue* pQue = creat_Queue();
	En_Queue(pQue, 1);
	En_Queue(pQue, 2);
	En_Queue(pQue, 3);
	De_Queue(pQue);
	traversal_Queue(pQue);

	return 0;
}

Queue* creat_Queue(void)
{
	Queue* pQue = (Queue*)malloc(sizeof(Queue));
	if (!pQue)
		return NULL;
	
	int len = MAXLEN + 1;
	PLIST p;
	PLIST head = (PLIST)malloc(sizeof(LIST));
	if (!head)
		return NULL;
	head->front = head->next = NULL;
	p = head;
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
	pQue->Last_Node = p;
	pQue->Last_Node->next = head->next;

	pQue->front = pQue->rear = head->next;
	pQue->Qu = head;
	return pQue;
}

void En_Queue(Queue* pQue, EleType element)
{
	if (Is_Full(pQue))
	{
		PLIST pNew = (PLIST)malloc(sizeof(LIST));
		if (!pNew)
			exit(-1);
		pNew->front = pQue->Last_Node;
		pNew->next = pQue->Qu->next;
		pQue->Last_Node->data = element;
		pQue->Last_Node->next = pNew;
		pQue->Last_Node = pNew;
		pQue->rear = pNew;
	}
	else
	{
		pQue->rear->data = element;
		pQue->rear = pQue->rear->next;
	}
	return;
}

void De_Queue(Queue* pQue)
{

	if (Is_Empty(pQue))
	{
		printf("Empty_Queue!\n");
		return;
	}
	else
	{
		pQue->front = pQue->front->next;
	}
	return;
}

bool Is_Full(Queue* pQue)
{
	if (pQue->rear == pQue->Last_Node)
		return 1;
	else
		return 0;
}

bool Is_Empty(Queue* pQue)
{
	if (pQue->rear == pQue->front)
		return 1;
	else
		return 0;
}

void traversal_Queue(Queue* pQue)
{
	PLIST p = pQue->front;
	while (p != pQue->rear)
	{
		printf("%d\n", p->data);
		p = p->next;
	}
	return;
}
