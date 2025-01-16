#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <malloc.h>

typedef int SLTDataType;
typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//���ָ��ָ����һ���ڵ�
}SLTNode;

//��ӡ����
void SLTPrint(SLTNode* phead);

//β��
void SLTPushBack(SLTNode** pphead, SLTDataType x);
//ͷ��
void SLTPushFront(SLTNode** pphead, SLTDataType x);
//βɾ
void SLTPopBack(SLTNode** pphead);
//ͷɾ
void SLTPopFront(SLTNode** pphead);
//����
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
//��ָ��λ��֮ǰ��������
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
//��ָ��λ��֮���������
void SLTInsertAfter(SLTNode** pphead, SLTDataType x);
//ɾ��pos���
void SLTErase(SLTNode**pphead, SLTNode* pos);
//ɾ��pos֮��Ľ��
void SLTEraseAfter(SLTNode* pos);
//��������
void SLTDesTroy(SLTNode** pphead);
