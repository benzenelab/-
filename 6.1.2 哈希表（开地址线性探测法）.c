#include<stdio.h>
#include<stdlib.h>
#define MAX_TIMES 10
#define MAX_HASH_SIZE 10
#define bool int
#define true 1
#define false 0

typedef int EleType;
typedef struct Hash_Node
{
	int valid;
	EleType data;
}Hash_Node;

typedef struct Hash_Table
{
	int m;
	Hash_Node* table;
}Hash_Table;

Hash_Table* Creat_Hash_Table(void);
bool Add_HashNode(Hash_Table*, EleType);
bool Del_HashNode(Hash_Table*, EleType);
bool Find_HashNode(Hash_Table*, EleType);

int main(void)
{
	

	return;
}

Hash_Table* Creat_Hash_Table(void)
{
	int i;
	Hash_Table* hash = (Hash_Table*)malloc(sizeof(Hash_Table));
	if (!hash)
		exit(-1);
	hash->m = MAX_HASH_SIZE;
	hash->table = (Hash_Node*)malloc(sizeof(Hash_Node) * MAX_HASH_SIZE);
	if (!hash->table)
		exit(-1);

	for (i = 0; i < MAX_HASH_SIZE; i++)
		hash->table[i].valid = false;
	return hash;
}

bool Add_HashNode(Hash_Table* hash, EleType val)
{
	int i = 1;
	while (i <= MAX_TIMES)
	{
		int target = (val + i) % MAX_HASH_SIZE;
		if (hash->table[target].valid == false)
		{
			hash->table[target].data = val;
			hash->table[target].valid = true;
			return true;
		}
		else
			++i;
	}
	printf("Error_ArrayOverFlow!\n");
	return false;
}

bool Del_HashNode(Hash_Table* hash, EleType val)//
{
	int i = 1;
	while (i <= MAX_TIMES)
	{
		int target = (val + i) % MAX_HASH_SIZE;
		if ((hash->table[target].valid == true) && (hash->table[target].data==val))
		{
			hash->table[target].valid = false;
			return true;
		}
		else
			++i;
	}
	printf("Error_Number_Doesn't_Exist!\n");
	return false;
}

bool Find_HashNode(Hash_Table* hash, EleType val)
{
	int i = 1;
	while (i <= MAX_TIMES)
	{
		int target = (val + i) % MAX_HASH_SIZE;
		if ((hash->table[target].valid == true) && (hash->table[target].data == val))
			return true;
		else
			++i;
	}
	return false;
}