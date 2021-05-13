#include<stdio.h>
#include<stdlib.h>
#include"AvlTree_header.h"

Queue* creat_Queue(void)
{
	Queue* pQue = (Queue*)malloc(sizeof(Queue));
	if (!pQue)
		return NULL;

	pQue->front = pQue->rear = 0;
	pQue->Qu = (EleType_Queue*)malloc(sizeof(EleType_Queue) * MAX_QUEUE_LEN);  /*Take Care of it!!!*/
	if (!pQue->Qu)
		exit(-1);

	return pQue;
}

void En_Queue(Queue* pQue, EleType_Queue element)
{
	if (Queue_Is_Full(pQue))
	{
		printf("Queue_Overflow!\n");
		return;
	}
	pQue->Qu[pQue->rear] = element;
	pQue->rear = (pQue->rear + 1) % MAX_QUEUE_LEN;
	return;
}

void De_Queue(Queue* pQue)
{
	if (Queue_Is_Empty(pQue))
	{
		printf("Empty_Queue!\n");
		return;
	}
	pQue->front = (pQue->front + 1) % MAX_QUEUE_LEN;
	return;
}

bool Queue_Is_Full(Queue* pQue)
{
	if ((pQue->rear + 1) % MAX_QUEUE_LEN == pQue->front)
		return true;
	else
		return false;
}

bool Queue_Is_Empty(Queue* pQue)
{
	if (pQue->front == pQue->rear)
		return true;
	else
		return false;
}