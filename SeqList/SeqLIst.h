#pragma once
#include<stdio.h>
#include<stdlib.h>
/*˳���Ľṹ*/
typedef int SLDataType;
//�����������Ϊ���ڱ�ʾ�������͵�ʱ�������һ������ʱ��Ҫ��char�ͺܷ���
 typedef struct SeqList
{
	SLDataType* arr;//��������
	int size;//������Ч����
	int capacity;//����
}SL;//���ṹ��ȡ�ı���������
//�ó�ʼ��������ֻ������
void SLInit(SL *ps);
//����
void SLDestroy(SL* ps);
//β��
void SLPushBack(SL* PS, SLDataType x);
//ͷ��
void SLPushFront(SL* ps, SLDataType x);
//βɾ
void SLPopBack(SL* ps);
//ͷɾ
void SLPopFront(SL* ps);
//����
int SLFind(SL* ps, SLDataType x);
//ָ��λ��֮ǰ��������
void SLInsert(SL* ps, int pos, SLDataType x);
//ָ��λ��ɾ������
void SLErase(SL* ps, int pos);