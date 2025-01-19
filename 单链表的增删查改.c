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
	printf("NULL\n");
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
//先把头结点保存下来，让头结点指向下个，释放保存的结点
void SLPopfront(SL** pphead)
{
	assert(pphead && *pphead);
	SL* newphead = *pphead;
	*pphead = (*pphead)->next;
	free(newphead);
	newphead = NULL;
}
//查找
SL* SLFind(SL* phead, SLDataType x)
{
	//遍历链表
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
//在pos之后插入x
void SLInsertafter(SL* pos,SLDataType x)
{
	assert(pos);
	SL* newnode = SLBuynode(x);
	newnode->next = pos->next;
	pos->next = newnode;		
}
//在pos之前插入x
//链表不能往回倒，所以要传头结点遍历找到pos的前驱
//要对当前的结点解引用，所以要把只有一个的情况拎出来
void SLInsertbefore(SL** pphead, SL* pos,SLDataType x)
{
	assert(pphead && pos);
	SL* pcur = *pphead;
	//pos九四头结点
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
		}//此时pcur是pos的前驱
		newnode->next = pos;
		pcur->next = newnode;
	}
}
//删除pos结点
//涉及前后，只要有前就用头结点
void SLErase(SL** pphead, SL* pos)
{
	assert(pphead && *pphead && pos);
	SL* prev = *pphead;
	//删除头结点
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

//删除pos之后的结点
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