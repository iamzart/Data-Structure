#define _CRT_SECURE_NO_WARNINGS
#include"SList.h"

//��ӡ����
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

//������
SLTNode* SLTBuyNode(SLTDataType x)
{
	//SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode*));// �����֮ǰд�ģ��ռ�������
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));//�����һ���ռ�,malloc��������Ŀռ�ĵ�ַ����ָ�����ͽ��ܣ����������һ��ṹ��Ĵ�С
	//�����ָ���Ǿ��ǹ̶���ô�󣬴治�¸����������
	//Ҫ�����Ƿ�����ɹ�
	if (newnode==NULL)
	{
		perror("malloc fail!");
		exit(1);
	}
	newnode->data = x;

	newnode->next = NULL;
	return newnode;
}

//β��
//�������Ϊ�գ��������½��ָ��phead
//�������ǿգ�����һ���½�㣬��ԭ��������һ���ڵ��nextָ���½�����������
void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	//�ָ��ݵڶ�����������һ���½��
	SLTNode* newnode = SLTBuyNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;//����ı���phead���βΣ����������ַ�Ļ�����һֱ�ǿ�����ÿ�ν�����ִ������Ȼ����
	}
	else
	{
		SLTNode* ptail = *pphead;
		while (ptail->next)
		{
			ptail = ptail->next;
		}//����ѭ��ʱ��ptail�������һ������β���
		ptail->next = newnode;
	}
}

//ͷ��
// //ͷ��Ļ�������Ϊ�գ����Ծ�����Ϊ�����ö���ָ��Ϊ�գ���Ϊ��߻�Ҫ������
//����һ���½�㣬����ָ��ͷ����ָ��������ͷ���ָ������½��
void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	assert(pphead);
	SLTNode* newnode = SLTBuyNode(x);//����һ���½��
	newnode->next = *pphead;
	*pphead = newnode;
}
//βɾ
// ɾ������Ҫ���Զ���ָ�룬���н�㲻��Ϊ��
//�ҵ�β���Ȼ���ͷţ��ÿ�
//�������ֻ��һ���ڵ�ֻ�������ÿգ���Ϊ���ʱ��prev�ǿ�ָ�룬���ܶ��������������ֹһ���͵�
void SLTPopBack(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* prev = NULL;//��Ϊ��ʼ����²�֪��ptail���ĸ����
	SLTNode* ptail = *pphead;
	if ((*pphead)->next == NULL)//ֻ��һ���ڵ�����
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		while (ptail->next)//�������һ����Ϊ��
		{
			prev = ptail;
			ptail = ptail->next;
			//prevһֱ��ptailǰ��
		}//����ѭ��ptail��β���
		prev->next = NULL;
		free(ptail);
		ptail = NULL;
	}
}

//ͷɾ
//�Ȱ�ͷ������һ����������Ȼ���ͷ�ͷ��㣬ͷ���ָ���Ľ��
void SLTPopFront(SLTNode** pphead)
{
	assert(pphead && *pphead);
	SLTNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;//�õڶ�����Ϊ�µ�ͷ���
}

//����
//��������β��㲻һ��
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
//��ָ��λ��֮ǰ��������
//�ҵ�ָ��λ�õ�ǰһ���������½��ָ��ָ��λ�ã�����prevָ���½�㣬�����ҵ�
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pphead&&pos);
	SLTNode* newnode = SLTBuyNode(x);//����һ���½��
	SLTNode* prev = *pphead;
	if (pos==*pphead)
	{
		SLTPushFront(pphead, x);
	}
	while (prev->next != pos)//���pos��ͷ�ڵ�Ļ��������һֱ�����ߣ���ѭ��
	{
		prev = prev->next;
	}//����ѭ��ʱ��prev����ָ��λ�õ�ǰһ��
	newnode->next = pos;
	prev->next = newnode;
}

//��ָ��λ��֮���������
// ���ô�ͷ��㣬��Ϊ���ñ����ˣ���ǰ��û��ϵ��
//���ҵ��Ǹ�λ�ã��ȴ����½�㣬��һ���½��ָ��ָ��λ�õĺ�̣�����ָ��λ��ָ���½�㣬�����Ͱ��½�������ˣ����ܵߵ�˳���������ָ��λ�õĺ�̣��ǾͲ������������ҵ����ָ��λ�õĺ����
void SLTInsertAfter(SLTNode* pos,SLTDataType x)
{
	assert(pos);
	SLTNode* newnode = SLTBuyNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

//ɾ��pos���
//�ҵ�ǰ���ͺ�̣�������������
//��������ͷ���Ļ�����û��ǰ���ģ�����Ҫ�������
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

//ɾ��pos֮��Ľ��
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
//��������
//һ��һ���ͷ�
//Ҳ���ܴӺ���ǰ��ʼ��������Ϊ�Ҳ���ǰ�ߵĽ�㣬�ǵ�����
void SLTDesTroy(SLTNode** pphead)
{
	assert(pphead);
	SLTNode* pcur = *pphead;
	while (pcur)
	{
		SLTNode* next = pcur->next;//��pcur����һ����������
		free(pcur);//Ȼ���ÿ�
		pcur = NULL;
		pcur = next;//Ȼ��������
	}
}
//free�����ݲ���Ϊ�գ���ε�ȷ��free�����ݵ������ռ����ʼλ�ã����ܱ����ı���malloc����++�Ͳ��У�
//���о���������ĳ�����Ȼ�����ռ���ʹ��Ȩ
  