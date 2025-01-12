#define _CRT_SECURE_NO_WARNINGS
#include"SeqList.h";
#include<assert.h>
#include<stdlib.h>//realloc����ͷ�ļ�����

//��ʼ��
void SLInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}
//����
//����һ���µ�capacity����Ϊԭ����Ϊ0��һֱ��������0
//��λ���ֽ�
//�������ʧ�ܻ᷵�ؿ�ָ�룬��ʱ��ԭ����Ҳ��ʧ�ˣ�����Ӧ����һ������������realloc����ֵ
//ʲôʱ����Ҫ���ݣ���size = capacityʱ�����ǿռ�ռ����
void SLCapacityCheck(SL* ps)
{
	if (ps->size == ps->capacity)
	{
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;//�ж���˫�ƺ�
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));//ps�������ṹ��ָ�룬���Ҫ�����鿪�ٹ�
		if (tmp == NULL)
		{
			perror("realloc fail!");
			exit(1);
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

//β��
//��Ч����+1
void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	SLCapacityCheck(ps);
	ps->arr[ps->size++] = x;
}
//ͷ��
//�ú�ߵ�Ԫ�ض�����ƶ�һλ������Ԫ�ذ�ͷλ���ڳ���
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	SLCapacityCheck(ps);
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[0] = x;
	++ps->size;
}
//βɾ
//ֱ������Ч����--�����õ�����ɶӰ�죬��ΪҲ�ᱻ���ǵ�
void SLPopBack(SL* ps)
{
	assert(ps && ps->size);//��ȷ���������ﻹ��Ԫ��ѽ
	ps->size--;
}
//ͷɾ
//ֱ����ǰ�ƣ��ѵ�һ��Ԫ�ظ��ǣ���Ч����--
void SLPopFront(SL*ps)
{
	assert(ps && ps->size);
	for (int i = 0; i <ps->size-1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//��������Ԫ��
//�ҵ������±꣬�Ҳ�������-1
int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] = x)
			return i;
	}
	//����ֵ����ﻹû���أ�����δ�ҵ�
	return -1;
}
//������λ��֮ǰ��������
//�����λ�ü��Ժ��Ԫ�ض�����ƶ�������Ԫ�طŵ��±�Ϊ���λ����
void SLInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	SLCapacityCheck(ps);//�ڲ���ǰ��Ҫ����ڴ湻����
	for (int i = ps->size; i > pos; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	ps->arr[pos] = x;
	ps->size++;
}

//ָ��λ��ɾ��Ԫ��
//�����λ�ÿ�ʼ����������һ����ǰ����
void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(ps->size);
	assert(pos >= 0 && pos < ps->size);
	for (int i = pos; i < ps->size - 1; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	ps->size--;
}
//����
void SLDestroy(SL* ps)
{
	if (ps->arr)//���ǿ�ָ��Ļ�
	{
		free(ps->arr);
		ps->arr = NULL;
		ps->capacity = ps->size = 0;
	}
}