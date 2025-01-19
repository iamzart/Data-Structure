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
	printf("NULL\n");
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
//�Ȱ�ͷ��㱣����������ͷ���ָ���¸����ͷű���Ľ��
void SLPopfront(SL** pphead)
{
	assert(pphead && *pphead);
	SL* newphead = *pphead;
	*pphead = (*pphead)->next;
	free(newphead);
	newphead = NULL;
}
//����
SL* SLFind(SL* phead, SLDataType x)
{
	//��������
	SL* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
			return pcur;
		else
		pcur = pcur->next;
	}
	return NULL;
}
//��pos֮�����x
void SLInsertafter(SL* pos,SLDataType x)
{
	assert(pos);
	SL* newnode = SLBuynode(x);
	newnode->next = pos->next;
	pos->next = newnode;		
}
//��pos֮ǰ����x
//���������ص�������Ҫ��ͷ�������ҵ�pos��ǰ��
//Ҫ�Ե�ǰ�Ľ������ã�����Ҫ��ֻ��һ������������
void SLInsertbefore(SL** pphead, SL* pos,SLDataType x)
{
	assert(pphead && pos);
	SL* pcur = *pphead;
	//pos����ͷ���
	if (*pphead == pos)
	{
		SLPushfront(pphead, x);
	}
	else
	{
		SL* newnode = SLBuynode(x);
		while (pcur -> next!= pos)
		{

			pcur = pcur->next;
		}//��ʱpcur��pos��ǰ��
		newnode->next = pos;
		pcur->next = newnode;
	}
}
//ɾ��pos���
//�漰ǰ��ֻҪ��ǰ����ͷ���
void SLErase(SL** pphead, SL* pos)
{
	assert(pphead && *pphead && pos);
	SL* prev = *pphead;
	//ɾ��ͷ���
	if (prev == pos)
	{
		free(pos);
		pos = NULL;
	}
	else
	{
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;

	}
	
}

//ɾ��pos֮��Ľ��
void Eraseafter(SL* pos)
{
	assert(pos&&pos->next);
	{
		SL* del = pos->next;
		pos->next = pos->next->next;
		free(del);
		del = NULL;
	}

}
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
	SLPopfront(&plist);
	SLPrint(plist);
	SL* findresult1 = SLFind(plist, 8);
	SLPrint(findresult1);
	SL* findresult2 = SLFind(plist, 9);
	SLPrint(findresult2);
	SLInsertafter(findresult2,101);
	SLPrint(plist);
	SLInsertbefore(&plist, findresult2, 202);
	SLPrint(plist);
	SLErase(&plist, findresult2);
	SLPrint(plist);
	Eraseafter(findresult2);
	SLPrint(plist);


	return 0;
}