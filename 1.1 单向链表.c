#include<stdio.h>
#include<stdlib.h>
#define bool int    //C89 ��δ����bool����
#define ture 1
#define false 0
#define scanf_s scanf //��VS�У�scanf��Ϊ����ȫ����ֹʹ�á�������ı��뻷��Ϊ Dev-C++����ʹ��VS����Ļ�Ӧ��������ȥ

 typedef struct List
{
	 int data;                           //������
	 struct List* Plist;                 //ָ����
}LIST,*PLIST;

 PLIST create_list(void);                           //��������
 void traverse_list(PLIST pHead);                   //��������
 bool insert_list(PLIST pHead, int pos,int temp);	//posΪ����ڵ��λ�ã���1��ʼ��tempΪ��Ҫ�������
 bool delete_list(PLIST pHead, int pos);            //ɾ����pos�ڵ㣬pos��1��ʼ
 int length_list(PLIST pHead);                      //ͳ������ĳ���
 void selectionsort_list(PLIST pHead, int len);     //���������ѡ������

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

 PLIST create_list(void)                //create_list()���ܣ�����һ����ѭ�������������������ͷ���ĵ�ַ����pHead
 {
	 int i, len, temp;                  //len��ű���������ĳ��ȣ�temp��ʱ����������������ֵ
	 printf("Please enter the length:");
	 scanf_s("%d", &len);

	 PLIST pHead = (PLIST)malloc(sizeof(LIST));   //Ϊ�׽ڵ�����ڴ�ռ䣬������һ���ṹ��ָ��pHeadָ����
	 
	 PLIST pointer = pHead;               //�ṹ��ָ��pointer��ָ��������β�ڵ� 
	 pHead->Plist = NULL;                 //Ϊ�˷�ֹlen=0����������ǽ�pHead��ָ������Ϊ��ָ��

	 for (i = 0; i < len; ++i)
	 {
		 printf("Please enter the %d number: \n",i+1);
		 scanf_s("%d", &temp);
		 
		 PLIST pNew = (PLIST)malloc(sizeof(LIST));   //Ϊ�½ڵ�����ڴ�ռ䣬������һ���ṹ��ָ��pNewָ����

		 pNew->data = temp;
		 pointer->Plist=pNew;        //ʹ�������β�ڵ�ָ���½ڵ�
		 pNew->Plist = NULL;         //Ϊ�˷�ֹ��ѭ�������Ľڵ�Ϊ���������β�ڵ㣬���ǽ��½ڵ��ָ������Ϊ��ָ��
		 pointer = pNew;             //�ṹ��ָ��pointerָ��������β�ڵ� 
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

 bool insert_list(PLIST pHead, int pos, int temp)           //pos��1��ʼ
 {
	 int len=0;           
	 PLIST p = pHead;     //����ṹ��ָ�룬��ָ���׽ڵ�
	 while ( p->Plist != NULL && len < pos-1 )     //lenͳ�������д��׽ڵ���POS�ĳ���
	 {
		 ++len;
		 p = p->Plist;   //��ѭ���У�p���ջ�ָ���pos�Ľڵ�
	 }
	 if ( len < 0 )   return false;
	 PLIST pNew = (PLIST)malloc(sizeof(LIST));   //Ϊ�½ڵ�����ڴ�ռ䣬������һ���ṹ��ָ��pNewָ����
	 if ( pNew == NULL )   return false;
	 
	 pNew->data = temp;               //���½ڵ�洢����
	 pNew->Plist = p->Plist;          //ʹ�¶���Ľڵ�ָ��pos����һ���ڵ�
	 p->Plist = pNew;                 //ʹ��pos�Ľڵ�ָ���¶���Ľڵ㣬pos��pos+1�ڵ�֮����������

	 return ture;
 }

 bool delete_list(PLIST pHead, int pos)
 {    
	 PLIST r, k;
	 
	 int len = 0;
	 PLIST p = pHead;     //����ṹ��ָ�룬��ָ���׽ڵ�
	 while (p->Plist != NULL && len < pos - 1)     //lenͳ�������д��׽ڵ���POS�ĳ���
	 {
		 ++len;
		 p = p->Plist;   //��ѭ���У�p���ջ�ָ���pos�Ľڵ�
	 }
	 if (len < 0)   return false;
     r = p;

	 len = 0;
	 p = pHead;
	 while (p->Plist != NULL && len < pos - 2)   //������ȡ��pos-1�ڵ�ĵ�ַ
	 {
		 len++;
		 p = p->Plist;   //��ѭ���У�p���ջ�ָ���pos-1�Ľڵ�
	 }
	 k = p;

	 k->Plist = k->Plist->Plist;  //ʹp-1���ڵ�ָ��p+1���ڵ�
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