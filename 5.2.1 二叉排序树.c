#include<stdio.h>
#include<stdlib.h>
#define bool int
#define true 1
#define false 0

typedef int EleType;
typedef struct BinarySort_Tree
{
	EleType data;
	struct BinarySort_Tree* Lch;  //Left child
	struct BinarySort_Tree* Rch;  //Right child
}BSTree;

bool AddNode_BSTree(EleType, BSTree*);    //二叉排序树加入节点
BSTree* Creat_BSTree(EleType* ,int);      //创建二叉排序树
bool Find_BSTree(EleType, BSTree*);       //搜寻节点是否存在
bool DelNode_BSTree(EleType, BSTree*);    //删除二叉排序树的某一节点
void Free_BSTree(BSTree*);                //释放堆空间
void traverse_BSTree(BSTree*);            //中序遍历

char    LorR;  //Leftchild or Rightchild
BSTree* Fno;  //Father node

int main(void)
{
   /*  2021/3/7 Sun.
    *    在图书馆写这该死的代码，设计和模拟递归算法运行时差点脑袋没烧坏qwq
	*    还好编译一遍过了。
	*    #####      #####
	*          ####
	*    ©3.0 BenzeneLab
	*/

	int i,len = 5;
	int as[100];
	for (i = 0; i < len; i++)
		scanf_s("%d", &as[i]);
	BSTree* T =Creat_BSTree(as, len);
	traverse_BSTree(T);
	return 0;
}

bool AddNode_BSTree(EleType val, BSTree* T)
{
	/*
	 *    要求根节点不为空！！！   
	 */
	if (!T)
	{
		BSTree* pNew = (BSTree*)malloc(sizeof(BSTree));
		if (!pNew)
			exit(-1);
		pNew->data = val;
		pNew->Lch = pNew->Rch = NULL;

		if (LorR == 'L')
			Fno->Lch = pNew;
		else
			Fno->Rch = pNew;

		return true;
	}//if
	else
	{
		EleType temp = T->data;
		if (val == temp)
		{
			printf("The Number has already exist!\n");
			return false;
		}
		else if (val > temp)
		{
			Fno = T;
			LorR = 'R';
			return AddNode_BSTree(val, T->Rch);
		}
		else if (val < temp)
		{
			Fno = T;
			LorR = 'L';
			return AddNode_BSTree(val, T->Lch);
		}
	}//else
}

BSTree* Creat_BSTree(EleType* str, int len)
{
	int i;
	BSTree* T = (BSTree*)malloc(sizeof(BSTree));
	if (!T)
		exit(-1);
	T->data = str[0];
	T->Lch = T->Rch = NULL;

	for (i = 1; i < len; i++)
	{
		AddNode_BSTree(str[i], T);
	}

	return T;
}

bool Find_BSTree(EleType val, BSTree* T)
{
	if (!T)
		return false;
	else
	{
		EleType temp = T->data;
		if (val == temp)
			return true;
		else if (val < temp)
			return Find_BSTree(val, T->Lch);
		else
			return Find_BSTree(val, T->Rch);
	}//else
}

bool DelNode_BSTree(EleType val, BSTree* T)
{
	if (!T)
	{
		printf("The number doesn't exist!\n");
		return false;
	}

	EleType temp = T->data;
	if (val == temp)
	{
		if (!(T->Lch) && !(T->Rch))//叶子节点直接删除
		{
			if (LorR == 'L')
				Fno->Lch = NULL;
			else
				Fno->Rch = NULL;
			free(T);
			return true;
		}//!(T->Lch) && !(T->Rch)
		else if (!(T->Lch) || !(T->Rch))//左右子树一方为空
		{
			if (!(T->Lch))//左子树为空
			{
				if (LorR == 'R')//父节点右
				{
					Fno->Rch = T->Rch;
					free(T);
					return true;
				}
				else//父节点左
				{
					Fno->Lch = T->Rch;
					free(T);
					return true;
				}
			}
			else//右子树为空
			{
				if (LorR == 'R')//父节点右
				{
					Fno->Rch = T->Lch;
					free(T);
					return true;
				}
				else//父节点左
				{
					Fno->Lch = T->Lch;
					free(T);
					return true;
				}
			}
		}//else if
		else
		{
			BSTree *tempcell = T->Lch;
			while (true)//寻找到后继左子树节点中最大的节点
			{
				if (!tempcell->Rch)
					break;
				tempcell = tempcell->Rch;
			}
			EleType ch= tempcell->data;//临时存放数据
			bool sta = DelNode_BSTree(tempcell->data, T);//删除tempcell所指向的节点
			T->data = ch;
			return sta;
		}
	}//if (val == T->data)
	else if(val < temp)
	{
		Fno = T;
		LorR = 'L';
		return DelNode_BSTree(val, T->Lch);
	}
	else
	{
		Fno = T;
		LorR = 'R';
		return DelNode_BSTree(val, T->Rch);
	}
}

void Free_BSTree(BSTree* T)
{
	if (!T)
		return;
	else
	{
		if (!(T->Lch) && !(T->Rch))
			free(T);
		else if (!(T->Lch))
			Free_BSTree(T->Rch);
		else if (!(T->Rch))
			Free_BSTree(T->Lch);
		else
		{
			Free_BSTree(T->Lch);
			BSTree* tempcell = T->Rch;
			free(T);
			Free_BSTree(tempcell);
		}
		return;
	}
}

void traverse_BSTree(BSTree* T)
{
	if (!T)
	   return;
	else
	{
		traverse_BSTree(T->Lch);
		printf("%d ", T->data);
		traverse_BSTree(T->Rch);
		return;
	}
}