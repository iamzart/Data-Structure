#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//�ֶ�����һ���������Ҵ�ӡ����
void test01()
{
	SLTNode* node1 = (SLTNode*)malloc(sizeof(SLTNode));//����sizeof�Ĳ����������ͣ���һ���ṹ��,��Ϊ����������½��,�½���ǽṹ������
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

	//��ӡ����,���ú���
	//��ʵ�Σ�����һ��ͷ���
	SLTNode* plist = node1;//�ṹ��ָ��
	SLTPrint(plist);

}
void test02()
{
	SLTNode* plist = NULL;//һ��������
	//β��
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
		printf("�ҵ���\n");
	else
		printf("δ�ҵ�\n");
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