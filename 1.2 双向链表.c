#include<stdio.h>
#include<stdlib.h>

typedef struct LIST
{
	int val;
	struct LIST* next;
	struct LIST* front;
}LIST,*PLIST;

PLIST creat_list(void);
void travelse(PLIST head);
void back_travelse(PLIST head);

int main(void)
{
	PLIST head = creat_list();
	travelse(head);
	back_travelse(head);
	return 0;
}

PLIST creat_list(void)
{
	int i,len;
	PLIST head=(PLIST)malloc(sizeof(LIST));
	PLIST p = head;
	if (head == NULL)
		exit(-1);
	head->front = head->next = NULL;

	printf("Please enter the length of the list.\n");
	scanf_s("%d", &len);
	if (len <= 0)   exit(-1);
	printf("Please enter the numbers. \n");
	for (i = 0; i < len; i++)
	{
		int temp;
		PLIST pNew = (PLIST)malloc(sizeof(LIST));
		if (pNew == NULL)
			exit(-1);

		scanf_s("%d", &temp);
		pNew->val = temp;
		pNew->front = p;
		pNew->next = NULL;
		p->next = pNew;
		p = pNew;
	}
	return head;
}

void travelse(PLIST head)
{
	PLIST current = head->next;
	while (current != NULL)
	{
		printf("%d ", current->val);
		current = current->next;
	}
	printf("\n");
	return;
}

void back_travelse(PLIST head)
{
	PLIST current = head->next;
	while (current->next != NULL)
		current = current->next;
	
	while (current->front != NULL)
	{
		printf("%d ", current->val);
		current = current->front;
	}
	return;
}