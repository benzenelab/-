#include<stdio.h>
#include<stdlib.h>
#include"hash_table.h"

int main(void)
{
	/*
	*     2021/3/15 MON.
	*     interesting!!!
	*     CC BY 3.0 BenezeneLab
	*/

	return 0;
}

Hash_Table* Creat_Hash_Table(void)
{
	int i;
	Hash_Table* hash = (Hash_Table*)malloc(sizeof(Hash_Table));
	if (!hash)
		exit(-1);
	hash->table = (LIST**)malloc(sizeof(LIST*)*MAX_HASH_SIZE);
	if (!hash->table)
		exit(-1);
	for (i = 0; i < MAX_HASH_SIZE; i++)
		hash->table[i] = NULL;
	return hash;
}

void Add_HashNode(Hash_Table *hash,EleType val)
{
	int target = val % MAX_HASH_SIZE;
	if (!hash->table[target])
	{
		LIST* pNew = (LIST*)malloc(sizeof(LIST));
		if (!pNew)
			exit(-1);
		pNew->data = val;
		pNew->next = NULL;
		hash->table[target] = pNew;
	}
	else
		Add_LISTNode(&hash->table[target], hash->table[target], val);
	return;
}

void Del_HashNode(Hash_Table *hash, EleType val)
{
	int target = val % MAX_HASH_SIZE;
	if (!hash->table[target])
	{
		printf("Error_Number_Doesn't_Exit\n");
		return;
	}
	else
		Del_LISTNode(&hash->table[target],hash->table[target], val);
}

bool Find_HashNode(Hash_Table* hash, EleType val)
{
	int target = val % MAX_HASH_SIZE;
	if (!hash->table[target])
		return false;
	else
	{
		LIST* p = hash->table[target];
		while (p)
		{
			if (p->data == val)
				return true;
			else
				p = p->next;
		}
		return false;
	}
}