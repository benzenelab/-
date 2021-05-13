#include<stdio.h>
#include<stdlib.h>
#define MAX_TREE_WIDE 2 
#define MAX_QUEUE_LEN 100
#define bool int

typedef char EleType;
typedef struct Binary_Tree
{
	EleType data;
	struct Binary_Tree* child[MAX_TREE_WIDE];//child[0] left_child 
}BTree;                                      //child[1] right_child
typedef BTree* EleType_Queue;

typedef struct Queue
{
	int rear;
	int front;
	EleType_Queue* Qu;  //多级指针的引用
}Queue;


/*Statements
	   In Binary_Tree*/
BTree* Creat_BTree(void);                //建立二叉树
void Pre_Traversal_BTree(BTree*);        //二叉树的先序遍历
void Inorder_Traversal_BTree(BTree*);    //二叉树的中序遍历
void Post_Traversal_BTree(BTree*);       //二叉树的后序遍历
void Level_Traversal_BTree(BTree*);      //二叉树的层次遍历
BTree* Copy_BTree(BTree*);               //复制二叉树
int Get_BTree_NodeSum(BTree*);           //统计二叉树节点个数
int Get_BTree_LeafNodeSum(BTree*);       //统计二叉树叶子节点个数
int Get_BTree_Deepth(BTree*);            //统计二叉树深度

/*Statements 
       In Queue*/
Queue* creat_Queue(void);
void En_Queue(Queue*, EleType_Queue);
void De_Queue(Queue*);
bool Queue_Is_Full(Queue*);
bool Queue_Is_Empty(Queue*);

int main(void)
{
	

	return 0;
}

BTree* Creat_BTree(void)
{
	EleType ch;
	scanf_s("%c",&ch,1);
	if (ch == '#')
		return NULL;
	else
	{
		BTree* pNew = (BTree*)malloc(sizeof(BTree));
		if (!pNew)
			exit(-1);
		pNew->data = ch;
		pNew->child[0] = Creat_BTree();
		pNew->child[1] = Creat_BTree();
		return pNew;
	}
}

void Pre_Traversal_BTree(BTree* T)
{
	if (!T)
		return;
	printf("%c", T->data);
	Pre_Traversal_BTree(T->child[0]);
	Pre_Traversal_BTree(T->child[1]);
	return;
}

void Inorder_Traversal_BTree(BTree* T)
{
	if (!T)
		return;
	Pre_Traversal_BTree(T->child[0]);
	printf("%c", T->data);
	Pre_Traversal_BTree(T->child[1]);
	return;
}

void Post_Traversal_BTree(BTree* T)
{
	if (!T)
		return;
	Pre_Traversal_BTree(T->child[0]);
	Pre_Traversal_BTree(T->child[1]);
	printf("%c", T->data);
	return;
}

void Level_Traversal_BTree(BTree* T)
{
	Queue *pQue = creat_Queue();
	En_Queue(pQue, T);  //头节点入队
	while (! Queue_Is_Empty(pQue))  //循环至队列为空
	{
		EleType_Queue temp = pQue->Qu[pQue->front];
		printf("%c", temp->data);
		if (temp->child[0])
			En_Queue(pQue, temp->child[0]);
		if (temp->child[1])
			En_Queue(pQue, temp->child[1]);
		De_Queue(pQue);
	}
	printf("\n");
	free(pQue);
	return;
}

BTree* Copy_BTree(BTree* T)
{
	if (!T)
		return NULL;
	else
	{
		BTree* Copyed_T = (BTree*)malloc(sizeof(BTree));
		if (!Copyed_T)
			exit(-1);
		Copyed_T->data = T->data;
		Copyed_T->child[0] = Copy_BTree(T->child[0]);
		Copyed_T->child[1] = Copy_BTree(T->child[1]);
		return Copyed_T;
	}
}

int Get_BTree_NodeSum(BTree* T)
{
	if (!T)//空节点
		return 0;
	else if ((!T->child[0]) && (!T->child[1]))//叶子节点
		return 1;
	else
		return Get_BTree_NodeSum(T->child[0]) + Get_BTree_NodeSum(T->child[1]) + 1;

}

int Get_BTree_LeafNodeSum(BTree* T)
{
	if (!T)//空节点
		return 0;
	else if ((!T->child[0]) && (!T->child[1]))//叶子节点
		return 1;
	else
		return Get_BTree_LeafNodeSum(T->child[0]) + Get_BTree_LeafNodeSum(T->child[1]);

}

int Get_BTree_Deepth(BTree* T)
{
	if (!T)//空节点
		return 0;
	int leftchild_deepth = Get_BTree_Deepth(T->child[0]);
	int rightchild_deepth = Get_BTree_Deepth(T->child[1]);
	if (leftchild_deepth >= rightchild_deepth)
		return leftchild_deepth + 1;
	else
		return rightchild_deepth + 1;

}

/*Functions in Queue*/
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
		return 1;
	else
		return 0;
}

bool Queue_Is_Empty(Queue* pQue)
{
	if (pQue->front == pQue->rear)
		return 1;
	else
		return 0;
}

