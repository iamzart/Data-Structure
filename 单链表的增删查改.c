#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLDataType;

typedef struct SListNode
{
	SLDataType data;
	struct SListNode* next;
}SL;

//�����½��
SL* SLBuynode(SLDataType X)
{
	SL* newnode = (SL*)malloc(sizeof(SL));
	newnode->data = X;//Ҫ�����ǳ�ʼ������
	newnode->next = NULL;
	return newnode;
}
void SLPrint(SL* pphead)
{
	while (pphead)
	{
		printf("%d->", pphead->data);
		pphead = pphead->next;
	}
	printf("NULL");
}
//β��
void SLPushback(SL** pphead, SLDataType x)
{
	assert(pphead);
	SL* newnode = SLBuynode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SL* pcur = *pphead;
		while (pcur&&pcur->next)//Ѱ��β���
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}
//ͷ��
void SLPushfront(SL** pphead,SLDataType x)
{
	assert(pphead);
	SL* newnode = SLBuynode(x);
	newnode->next = *pphead;//�ŵ���ǰ��
	*pphead = newnode;//ͷ�ڵ����
}
//βɾ
void SLPopback(SL** pphead)
{
	assert(pphead && *pphead);
	SL* ptail = *pphead;
	while (ptail->next->next)
	{
		ptail = ptail->next;
	}
	ptail->next = NULL;
	free(ptail->next);
	ptail->next = NULL;
}
//ͷɾ



int main()
{
	SL* plist = NULL;//����һ��������
	SLPushback(&plist, 1);
	SLPushback(&plist, 2);
	SLPushback(&plist, 3);
	//SLPrint(plist);
	SLPushfront(&plist, 9);
	SLPushfront(&plist, 8);
	SLPrint(plist);
	SLPopback(&plist);
	SLPrint(plist);
	return 0;
}