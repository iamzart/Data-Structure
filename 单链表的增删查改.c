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

//申请新结点
SL* SLBuynode(SLDataType X)
{
	SL* newnode = (SL*)malloc(sizeof(SL));
	newnode->data = X;//要给他们初始化啊！
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
//尾插
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
		while (pcur&&pcur->next)//寻找尾结点
		{
			pcur = pcur->next;
		}
		pcur->next = newnode;
	}
}
//头插
void SLPushfront(SL** pphead,SLDataType x)
{
	assert(pphead);
	SL* newnode = SLBuynode(x);
	newnode->next = *pphead;//放到最前边
	*pphead = newnode;//头节点更新
}
//尾删
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
//头删



int main()
{
	SL* plist = NULL;//创建一个空链表
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