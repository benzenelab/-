#include<stdio.h>
#include<stdlib.h>
#include"AvlTree_header.h"

static char LorR;
static AvlTree* Fno;

int main(void)
{
	int i, len = 5;
	int as[100];
	for (i = 0; i < len; ++i)
		scanf_s("%d", &as[i]);
	AvlTree* T=Creat_AvlTree(len, as);
	Level_AvlTraversal(T);

	return 0;
}

AvlTree* AddNode_AvlTree(EleType val, AvlTree* T)
{
	if (!T)
	{
		AvlTree* pNew = (AvlTree*)malloc(sizeof(AvlTree));
		if (!pNew)
			exit(-1);
		pNew->data = val;
		pNew->hight = 0;
		pNew->Lch = pNew->Rch = NULL;
		return pNew;     
	}
	else if (val < T->data)
	{
		T->Lch=AddNode_AvlTree(val, T->Lch);
		if (Get_hight(T->Lch) - Get_hight(T->Rch) == 2)
		{
			if (val < T->Lch->data)
				T = Single_Rotation(T);
			else
				T = Double_Rotation(T);
		}
	}
	else if (val > T->data)
	{
		T->Rch = AddNode_AvlTree(val, T->Rch);
		if (Get_hight(T->Rch) - Get_hight(T->Lch) == 2)
		{
			if (val > T->Rch->data)
				T = Single_Rotation(T);
			else
				T = Double_Rotation(T);
		}
	}
	else
	{
		printf("some_number_error\n");
		exit(-1);
	}
	T->hight = Max_(Get_hight(T->Lch),Get_hight(T->Rch)) + 1;
	return T;
}

AvlTree* DelNode_AvlTree(EleType val, AvlTree* T)
{
	if (!T)
	{
		printf("The number doesn't exist!\n");
		return T;
	}
	else if (val == T->data)
	{
		if (!(T->Lch) && !(T->Rch))
		{
			free(T);
			T = Fno;//tansfer to the father node
			if (LorR == 'L')
			{
				T->Lch = NULL;
				if (Get_hight(T->Rch) + 1 == 2)
				{
					//*****
				}
			}
			else
			{
				T->Rch = NULL;
				if (Get_hight(T->Lch) + 1 == 2)
				{
					//*****
				}
			}
		}
		else if (!(T->Lch) || !(T->Rch))
		{

		}
		else
		{

		}
	}
	else if (val < T->data)
	{
		Fno = T;
		LorR = 'L';
		return DelNode_AvlTree(val, T->Lch);
	}
	else
	{
		Fno = T;
		LorR = 'R';
		return DelNode_AvlTree(val, T->Rch);
	}
}

AvlTree* Creat_AvlTree(int len, EleType* str)
{
	int i;
	AvlTree* T = (AvlTree*)malloc(sizeof(AvlTree));
	if (!T)
		exit(-1);
	T->data = str[0];
	T->hight = 0;
	T->Lch = T->Rch = NULL;

	for (i = 1; i < len; ++i)
		T = AddNode_AvlTree(str[i], T);

	return T;
}

int Get_hight(AvlTree* T)
{
	if (!T)
		return -1;
	else
		return T->hight;
}

int Max_(int a, int b)
{
	if (a > b)
		return a;
	else
		return b; 
}

AvlTree* Single_Rotation(AvlTree* T)
{
	if (T->Lch != NULL)
	{
		AvlTree* temp = T->Lch;
		T->Lch = temp->Rch;
		temp->Rch = T;

		T->hight = Max_(Get_hight(T->Lch), Get_hight(T->Rch)) + 1;
		temp->hight = Max_(Get_hight(temp->Lch), Get_hight(temp->Rch)) + 1;
		return temp;
	}
	else
	{
		AvlTree* temp = T->Rch;
		T->Rch = temp->Lch;
		temp->Lch = T;

		T->hight = Max_(Get_hight(T->Lch), Get_hight(T->Rch)) + 1;
		temp->hight = Max_(Get_hight(temp->Lch), Get_hight(temp->Rch)) + 1;
		return temp;
	}
}

AvlTree* Double_Rotation(AvlTree* T)//
{
	T = Single_Rotation(T);
	return Single_Rotation(T);
}

void Level_AvlTraversal(AvlTree* T)
{
	if (!T)
		return;

	Queue* pQue = creat_Queue();
	En_Queue(pQue, T);
	while (!Queue_Is_Empty(pQue))
	{
		AvlTree* fNode = pQue->Qu[pQue->front];
		if (fNode->Lch != NULL)
			En_Queue(pQue,fNode->Lch);
		if (fNode->Rch != NULL)
			En_Queue(pQue, fNode->Rch);
		printf("%d ", fNode->data);
		De_Queue(pQue);
	}
	printf("\n");
	free(pQue->Qu);
	free(pQue);
	return;
}

void AvlTraversal(AvlTree* T)
{
	if (!T)
		return;
	else
	{
		AvlTraversal(T->Lch);
		printf("%d ", T->data);
		AvlTraversal(T->Rch);
		return;
	}
}