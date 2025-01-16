#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//打印链表
void SLTPrint(SLTNode* phead)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		printf("%d-->", pcur->data);
		pcur = pcur->next;
	}
	printf("NULL\n");
}

//申请结点
SLTNode* SLTBuyNode(SLTDataType x)
{
	//SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode*));// 这个你之前写的，空间分配错了
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//申请出一个空间,malloc返回申请的空间的地址，用指针类型接受，但申请的是一块结构体的大小
	//如果用指针那就是固定那么大，存不下更大的类型了
	//要考虑是否申请成功
	if (newnode==NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;

	newnode->next = NULL;
	return newnode;
}

//尾插
//如果链表为空，创建的新结点指向phead
//如果链表非空，创建一个新结点，把原链表的最后一个节点的next指向新结点就连起来了
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	//现根据第二个参数创建一个新结点
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;//这里改变了phead（形参），如果不传址的话，就一直是空链表，每次进来都执行这里然并卵
	}
	else
	{
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}//跳出循环时，ptail已在最后一个，是尾结点
		ptail->next = newnode;
	}
}

//头插
// //头插的话结点可以为空，断言就是因为不能让二级指针为空，因为后边还要解引用
//创建一个新结点，让他指向头结点的指针域，再让头结点指向这个新结点
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);//创建一个新结点
	newnode->next = *pphead;
	*pphead = newnode;
}
//尾删
// 删除不仅要断言二级指针，还有结点不能为空
//找到尾结点然后释放，置空
//分情况，只有一个节点只需把这个置空，因为这个时候prev是空指针，不能对它解引用如果不止一个就得
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* prev = NULL;//因为初始情况下不知道ptail是哪个结点
	SLTNode* ptail = *pphead;
	if ((*pphead)->next == NULL)//只有一个节点的情况
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		while (ptail->next)//如果他下一个不为空
		{
			prev = ptail;
			ptail = ptail->next;
			//prev一直在ptail前边
		}//跳出循环ptail是尾结点
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

//头删
//先把头结点的下一个存起来，然后释放头结点，头结点指向存的结点
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;//让第二个成为新的头结点
}

//查找
//遍历和找尾结点不一样
SLTNode* SLTFind(SLTNode* phead, SLTDataType x)
{
	SLTNode* pcur = phead;
	while (pcur)
	{
		if (pcur->data == x)
		{
			return pcur;
		}
		pcur = pcur->next;
	}
	return NULL;
}
//在指定位置之前插入数据
//找到指定位置的前一个，先让新结点指向指定位置，再让prev指向新结点，都能找到
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead&&pos);
	SLTNode* newnode = SLTBuyNode(x);//创造一个新结点
	SLTNode* prev = *pphead;
	if (pos==*pphead)
	{
		SLTPushFront(pphead, x);
	}
	while (prev->next != pos)//如果pos是头节点的话，这里会一直往后走，死循环
	{
		prev = prev->next;
	}//跳出循环时，prev已是指定位置的前一个
	newnode->next = pos;
	prev->next = newnode;
}

//在指定位置之后插入数据
// 不用传头结点，因为不用遍历了，和前边没关系了
//先找到那个位置，先创建新结点，第一让新结点指向指定位置的后继，再让指定位置指向新结点，这样就把新结点插进来了，不能颠倒顺序，如果用了指定位置的后继，那就不能用这个后继找到这个指定位置的后边了
void SLTInsertAfter(SLTNode* pos,SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//删除pos结点
//找到前驱和后继，把他俩连起来
//当传的是头结点的话，是没有前驱的，所以要单拎出来
void SLTErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pphead && *pphead);
	if (pos == *pphead)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* prev = *pphead;
		SLTNode* next = pos->next;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = next;
		free(pos);
		pos = NULL;
	}
}

//删除pos之后的结点
void SLTEraseAfter(SLTNode* pos)
{
	assert(pos && pos->next);
	SLTNode* next = pos->next->next;
	free(pos->next);
	pos->next = next;
	pos->next = NULL;
}
//void SLTEraseAfter(SLTNode* pos)
//{
//	assert(pos && pos->next);
//	//pos del del->next
//	SLTNode* del = pos->next;
//	pos->next = del->next;
//
//	free(del);
//	del = NULL;
//}
//销毁链表
//一个一个释放
//也不能从后往前开始遍历，因为找不到前边的结点，是单链表
void SLTDesTroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;//把pcur的下一个保存下来
		free(pcur);//然后置空
		pcur = NULL;
		pcur = next;//然后往后走
	}
}
//free的内容不能为空，其次得确保free的内容得是这块空间的起始位置，不能被更改比如malloc了再++就不行，
//还有就是现在你的程序仍然对这块空间有使用权
  