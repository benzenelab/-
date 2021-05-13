#include<stdio.h>
#include<stdlib.h>
#define MAXLEN 4
#define bool int

typedef int EleType;
typedef struct Queue
{
	int rear;
	int front;
	EleType* Qu;
}Queue;

Queue* creat_Queue(void);
void En_Queue(Queue*,EleType);
void De_Queue(Queue*);
bool Is_Full(Queue*);
bool Is_Empty(Queue*);
void traversal_Queue(Queue*);

int main(void)
{
	Queue* pQue = creat_Queue();
	En_Queue(pQue, 1);
	De_Queue(pQue);
	En_Queue(pQue, 2);
	De_Queue(pQue);
	En_Queue(pQue, 3);
	
	//De_Queue(pQue);
	
	traversal_Queue(pQue);

	return 0;
}

Queue* creat_Queue(void)
{
	Queue* pQue = (Queue*)malloc(sizeof(Queue));
	if (!pQue)
		return NULL;
	
	pQue->front = pQue->rear = 0;
	pQue->Qu = (EleType*)malloc(sizeof(EleType) * MAXLEN);
	if (!pQue->Qu)
		exit(-1);

	return pQue;
}

void En_Queue(Queue* pQue, EleType element)
{
	if (Is_Full(pQue))
	{
		printf("Queue_Overflow!\n");
		return;
	}
	pQue->Qu[pQue->rear] = element;
	pQue->rear = (pQue->rear + 1) % MAXLEN;
	return;
}

void De_Queue(Queue* pQue)
{
	if (Is_Empty(pQue))
	{
		printf("Empty_Queue!\n");
		return;
	}
	pQue->front = (pQue->front + 1) % MAXLEN;
	return;
}

bool Is_Full(Queue* pQue)
{
	if ((pQue->rear + 1) % MAXLEN == pQue->front)
		return 1;
	else
		return 0;
}

bool Is_Empty(Queue* pQue)
{
	if (pQue->front == pQue->rear)
		return 1;
	else
		return 0;
}

void traversal_Queue(Queue* pQue)
{	
	int i = pQue->front;
	for (; i < pQue->rear; i = (i + 1) % MAXLEN)
		printf("%d\n", pQue->Qu[i]);
	return;
}
