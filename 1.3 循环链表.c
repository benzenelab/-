#include<stdio.h>
#include<stdlib.h>

typedef struct PLIST
{
	int val;
	struct PLIST* front;
	struct PLIST* next;
}LIST,*PLIST;

int   len;      //lenͳ������ĳ���
PLIST f, r;     //fָ���������ʼ�ڵ㣬rָ������Ľ����ڵ�

void creat_circleLIST(void);          //����ѭ��������������ͷ�ڵ�
void L_travelse(void);                //�������ұ�������
void R_travelse(void);                //���������������
void addNode(int temp, int pos);      //�������м���һ���ڵ㣬pos��1��ʼ������ڵ��λ���ڵ�pos���ڵ�֮ǰ
void deleteNode(int pos);             //��������ɾ����pos���ڵ㣬pos��1��ʼ

int main(void)
{
	creat_circleLIST();
	//deleteNode(2);
	L_travelse();
	R_travelse();
	return 0;
}

void creat_circleLIST(void)//��������ͷ�ڵ�
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

void L_travelse(void)//�������ұ�������
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

void R_travelse(void)//���������������
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

void addNode(int temp, int pos)//pos��1��ʼ���ڵ�pos��λ��ǰ����һ���ڵ�
{
	if (pos == 1)//������Ľڵ�Ϊ��һ���ڵ�
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
	else if (pos == len)//������Ľڵ�Ϊ���һ���ڵ�
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
		*   pos������ȡ�Ⱥţ���ȡ�Ⱥ����������ʽڵ�һ�Ρ�
		*   �Ժ�дforѭ��ʱ��Ҫ�뵱Ȼ��Ҫ��ϸ����ѭ�������ı��ʽ��
		*
		*    for (i = 1; i <= pos; i++) //�ڵ�pos���ڵ�����һ���ڵ��д��
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

void deleteNode(int pos)//��������ɾ����pos���ڵ㣬pos��1��ʼ
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