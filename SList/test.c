#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//手动构造一个链表，并且打印链表
void test01()
{
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));//这里sizeof的不是数据类型，是一个结构体,因为他申请的是新结点,新结点是结构体类型
	SLTNode* node2 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node3 = (SLTNode*)malloc(sizeof(SLTNode));
	SLTNode* node4 = (SLTNode*)malloc(sizeof(SLTNode));

	node1->data = 1;
	node2->data = 2;
	node3->data = 3;
	node4->data = 4;
	
	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = NULL;

	//打印链表,调用函数
	//（实参）传入一个头结点
	SLTNode* plist = node1;//结构体指针
	SLTPrint(plist);

}
void test02()
{
	SLTNode* plist = NULL;//一个空链表
	//尾插
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	SLTPushFront(&plist, 9);
	SLTPushFront(&plist, 8);
	SLTPushFront(&plist, 7);
	SLTPrint(plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPrint(plist);
	SLTPopFront(&plist);
	SLTNode* ret = SLTFind(plist, 1);
	if (ret)
		printf("找到了\n");
	else
		printf("未找到\n");
	SLTInsert(&plist, ret, 100);
	SLTPrint(plist);
	SLTInsertAfter(ret, 100);
	SLTPrint(plist);

	SLTNode*tmp = ret->next;
	SLTErase(&plist, ret);
	ret = tmp;

	SLTEraseAfter(ret);
	SLTPrint(plist);
}
int main()
{
	//test01();
	test02();
	
	return 0;
}