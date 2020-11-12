#include<stdio.h>
#include<stdlib.h>

typedef struct PLIST
{
	int val;
	struct PLIST* front;
	struct PLIST* next;
}LIST,*PLIST;

int   len;      //len统计链表的长度
PLIST f, r;     //f指向链表的起始节点，r指向链表的结束节点

void creat_circleLIST(void);          //创建循环链表，该链表无头节点
void L_travelse(void);                //从左至右遍历链表
void R_travelse(void);                //从右至左遍历链表
void addNode(int temp, int pos);      //在链表中加入一个节点，pos从1开始，插入节点的位置在第pos个节点之前
void deleteNode(int pos);             //在链表中删除第pos个节点，pos从1开始

int main(void)
{
	creat_circleLIST();
	//deleteNode(2);
	L_travelse();
	R_travelse();
	return 0;
}

void creat_circleLIST(void)//该链表无头节点
{
	int i;
	PLIST head = NULL;
	printf("Please enter the length of the list:\n");
	scanf_s("%d", &len);
	if (len <= 0) exit(-1);

	printf("Please enter the numbers:\n");
	for (i = 0; i < len; i++)
	{
		int temp;
		scanf_s("%d", &temp);
		if (i == 0)
		{
			head = (PLIST)malloc(sizeof(LIST));
			if (head == NULL) exit(-1);
			head->val = temp;
			head->front = head->next = NULL;
			r = f = head;
		}
		else
		{
			PLIST pNew = (PLIST)malloc(sizeof(LIST));
			if (pNew == NULL) exit(-1);
			pNew->front = r;
			pNew->next =  f;
			pNew->val = temp;
			r->next = pNew;
			f->front = pNew;
			r = pNew;
		}
	}
	return;
}

void L_travelse(void)//从左至右遍历链表
{
	PLIST current = f;
	while (current != r)
	{
		printf("%d ", current->val);
		current = current->next;
	}
	printf("%d \n", r->val);
	return;
}

void R_travelse(void)//从右至左遍历链表
{
	PLIST current = r;
	while (current != f)
	{
		printf("%d ", current->val);
		current = current->front;
	}
	printf("%d \n", f->val);
	return;
}

void addNode(int temp, int pos)//pos从1开始，在第pos个位置前插入一个节点
{
	if (pos == 1)//当插入的节点为第一个节点
	{
		PLIST pNew = (PLIST)malloc(sizeof(LIST));
		if (pNew == NULL) exit(-1);
		pNew->val = temp;
		pNew->front = r;
		pNew->next = f;
		r->next = pNew;
		f->front = pNew;
		f = pNew;
	}
	else if (pos == len)//当插入的节点为最后一个节点
	{
		PLIST pNew = (PLIST)malloc(sizeof(LIST));
		if (pNew == NULL) exit(-1);
		pNew->val = temp;
		pNew->front = r;
		pNew->next = f;
		r->next = pNew;
		f->front = pNew;
		r = pNew;
	}
	else
	{
		int i;
		PLIST  p_beforePos = f;
		PLIST  p_Pos = f;
		for (i = 1; i < pos; i++)
		{
			if (i < pos - 1)
				p_beforePos = p_beforePos->next;
			p_Pos = p_Pos->next;
		}
        /*
		*   Bug fixed on 11/11/2020
		*   pos处不能取等号，若取等号链表将会多访问节点一次。
		*   以后写for循环时不要想当然，要仔细考虑循环结束的表达式。
		*
		*    for (i = 1; i <= pos; i++) //在第pos个节点后插入一个节点的写法
		*  {
		*	 if (i <= pos - 1)
		*		p_beforePos = p_beforePos->next;
		*	 p_Pos = p_Pos->next;
		*   }
		*/

		PLIST pNew = (PLIST)malloc(sizeof(LIST));
		if (pNew == NULL) exit(-1);
		pNew->val = temp;
		pNew->front = p_beforePos;
		pNew->next = p_Pos;
		p_beforePos->next = pNew;
		p_Pos->front = pNew;
	}
	return;
}

void deleteNode(int pos)//在链表中删除第pos个节点，pos从1开始
{
	if (pos == 1)
	{
		PLIST tempcell = f;
		f->next->front = r;
		r->next = f->next;
		f = f->next;
		free(tempcell);
	}
	else if (pos == len)
	{
		PLIST tempcell = r;
		r->front->next = f;
		f->front = r->front;
		r = r->front;
		free(tempcell);
	}
	else
	{
		int i;
		PLIST  p_Pos = f;
		for (i = 1; i < pos; i++)
		{
			p_Pos = p_Pos->next;
		}

		PLIST tempcell = p_Pos;
		p_Pos->front->next = p_Pos->next;
		p_Pos->next->front = p_Pos->front;
		free(tempcell);
	}
	return;
}