#include<stdio.h>
#include<stdlib.h>
#define bool int    //C89 中未定义bool类型
#define ture 1
#define false 0
#define scanf_s scanf //在VS中，scanf因为不安全而禁止使用。本程序的编译环境为 Dev-C++，若使用VS编译的话应将本行舍去

 typedef struct List
{
	 int data;                           //数据域
	 struct List* Plist;                 //指针域
}LIST,*PLIST;

 PLIST create_list(void);                           //创建链表
 void traverse_list(PLIST pHead);                   //遍历链表
 bool insert_list(PLIST pHead, int pos,int temp);	//pos为插入节点的位置，从1开始。temp为需要插入的数
 bool delete_list(PLIST pHead, int pos);            //删除第pos节点，pos从1开始
 int length_list(PLIST pHead);                      //统计链表的长度
 void selectionsort_list(PLIST pHead, int len);     //对链表进行选择排序

 int main(void)
 {
	 PLIST pHead = NULL;
	 
	 pHead=create_list();
	 //insert_list(pHead, 2, 999);
	 // delete_list(pHead, 3);
	 selectionsort_list(pHead, length_list(pHead));
	 traverse_list(pHead);
	 // printf("\n%d \n",length_list(pHead) );

	 return 0;
 }

 PLIST create_list(void)                //create_list()功能：创建一个非循环单链表，并将该链表的头结点的地址付给pHead
 {
	 int i, len, temp;                  //len存放被创建链表的长度，temp临时存放链表中数据域的值
	 printf("Please enter the length:");
	 scanf_s("%d", &len);

	 PLIST pHead = (PLIST)malloc(sizeof(LIST));   //为首节点分配内存空间，并定义一个结构体指针pHead指向它
	 
	 PLIST pointer = pHead;               //结构体指针pointer恒指向该链表的尾节点 
	 pHead->Plist = NULL;                 //为了防止len=0的情况，我们将pHead的指针域定义为空指针

	 for (i = 0; i < len; ++i)
	 {
		 printf("Please enter the %d number: \n",i+1);
		 scanf_s("%d", &temp);
		 
		 PLIST pNew = (PLIST)malloc(sizeof(LIST));   //为新节点分配内存空间，并定义一个结构体指针pNew指向它

		 pNew->data = temp;
		 pointer->Plist=pNew;        //使该链表的尾节点指向新节点
		 pNew->Plist = NULL;         //为了防止该循环创建的节点为整个链表的尾节点，我们将新节点的指针域定义为空指针
		 pointer = pNew;             //结构体指针pointer指向该链表的尾节点 
	 }

	 return pHead;
 }
 
 void traverse_list(PLIST pHead)
 {
	 PLIST p = pHead->Plist;
	 while (p != NULL)
	 {
		 printf("%d ", p->data);
		 p = p->Plist;
	 }
	 return;
}

 bool insert_list(PLIST pHead, int pos, int temp)           //pos从1开始
 {
	 int len=0;           
	 PLIST p = pHead;     //定义结构体指针，其指向首节点
	 while ( p->Plist != NULL && len < pos-1 )     //len统计链表中从首节点至POS的长度
	 {
		 ++len;
		 p = p->Plist;   //在循环中，p最终会指向第pos的节点
	 }
	 if ( len < 0 )   return false;
	 PLIST pNew = (PLIST)malloc(sizeof(LIST));   //为新节点分配内存空间，并定义一个结构体指针pNew指向它
	 if ( pNew == NULL )   return false;
	 
	 pNew->data = temp;               //让新节点存储数据
	 pNew->Plist = p->Plist;          //使新定义的节点指向pos的下一个节点
	 p->Plist = pNew;                 //使第pos的节点指向新定义的节点，pos至pos+1节点之间的连接清除

	 return ture;
 }

 bool delete_list(PLIST pHead, int pos)
 {    
	 PLIST r, k;
	 
	 int len = 0;
	 PLIST p = pHead;     //定义结构体指针，其指向首节点
	 while (p->Plist != NULL && len < pos - 1)     //len统计链表中从首节点至POS的长度
	 {
		 ++len;
		 p = p->Plist;   //在循环中，p最终会指向第pos的节点
	 }
	 if (len < 0)   return false;
     r = p;

	 len = 0;
	 p = pHead;
	 while (p->Plist != NULL && len < pos - 2)   //遍历以取得pos-1节点的地址
	 {
		 len++;
		 p = p->Plist;   //在循环中，p最终会指向第pos-1的节点
	 }
	 k = p;

	 k->Plist = k->Plist->Plist;  //使p-1个节点指向p+1个节点
	 free(r);

	 return ture;
 }
 
 int length_list(PLIST pHead)
 {
	 int len = 0;
	 PLIST p = pHead;
	 while (p->Plist != NULL)   
	 {
		 ++len;
		 p = p->Plist;   
	 }
	 return len;
 }

 void selectionsort_list(PLIST pHead, int len)
 {
	 int i, j, temp;
	 PLIST k,r;
	 for(i=0,k=pHead->Plist;i<len;++i,k=k->Plist)
		 for(j=i+1,r=k->Plist;j<len;++j,r=r->Plist)
			 if (k->data > r->data)
			 {
				 temp = k->data;
				 k->data = r->data;
				 r->data = temp;
			 }

	 return;
 }