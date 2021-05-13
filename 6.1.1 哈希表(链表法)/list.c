#include<stdio.h>
#include<stdlib.h>
#include"hash_table.h"

/*
*    HeadNode was NOT
*                    included in the ADT!
*    This is a special version for hash table
*/

bool Add_LISTNode(LIST** h, LIST* head, EleType val)
{
	LIST* pNew = (LIST*)malloc(sizeof(LIST));
	if (!pNew)
		exit(-1);
	pNew->data = val;
	pNew->next = NULL;

	if (head)
	{
		LIST* p = head;
		while (p->next)
			p = p->next;
		p->next = pNew;
	}
	else
		*h = pNew;

	return true;
}

bool Del_LISTNode(LIST** h, LIST* head, EleType val)
{
	LIST* Before_Node = NULL;
	LIST* p = head;
	if (head->data != val)
	{
		while (p && (p->data != val))
		{
			Before_Node = p;
			p = p->next;
		}

		if (!p)
		{
			printf("Error_Number_Doesn't_Exit\n");
			return;
		}
		Before_Node->next = p->next;
		free(p);
		return true;
	}
	else//É¾³ýÍ·½Úµã
	{
		*h = head->next;
		free(head);
		return true;
	}
}