#ifndef _HASH_TABLE_H
#define _HASH_TABLE_H
#define  MAX_HASH_SIZE 10
#define bool int
#define true 1
#define false 0

typedef int EleType;
typedef struct LIST
{
	EleType data;
	struct LIST* next;
}LIST;

typedef struct Hash_Table
{
	LIST** table;
}Hash_Table;

/*funcation statements
		   in Hash Table*/
Hash_Table* Creat_Hash_Table(void);
void Add_HashNode(Hash_Table*, EleType);
void Del_HashNode(Hash_Table*, EleType);
bool Find_HashNode(Hash_Table*, EleType);

/*funcation statements
           in list*/
bool Add_LISTNode(LIST**, LIST*, EleType);
bool Del_LISTNode(LIST**, LIST*, EleType);
#endif
